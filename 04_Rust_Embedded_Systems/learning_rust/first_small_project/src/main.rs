use std::io;
use std::process::exit;

fn clear_screen() {
    // \x1B = ESC, [2J clears screen, [1;1H moves cursor to top-left
    print!("\x1B[2J\x1B[1;1H");
}

fn main() {
    let choice;
    clear_screen();
    println!("Hello, this project is a todo list!");
    println!();
    println!("-----------------------------------");
    println!();
    println!("1 - Enter ToDo List");
    println!("0 - Exit");
    choice = get_choice(1);

    match choice {
        1 => {
            clear_screen();
            todo_app()
        }

        0 => exit(0),

        _ => {
            println!("ERROR");
            exit(1)
        }
    }
}

fn get_choice(options: u32) -> u32 {
    loop {
        println!("Insert your option:");

        let mut input = String::new();
        io::stdin()
            .read_line(&mut input)
            .expect("failed to read line");

        match input.trim().parse::<u32>() {
            Ok(n) => {
                if n > options {
                    println!("Not a valid option.Try again.");
                } else {
                    return n;
                }
            }
            Err(_) => {
                println!("Insert a number. Try again");
            }
        }
    }
}

fn todo_app() {
    let mut todo_items: Vec<String> = Vec::new();
    let mut n_elements: u32 = 0;
    let mut choice;

    loop {
        clear_screen();
        println!("------------------------------");
        println!("          TO DO LIST          ");
        println!("------------------------------");
        if n_elements == 0 {
            println!("There are no items on your to do list.");
            println!("1 - Add a new Item");
            println!("0 - Exit");
            choice = get_choice(1);
            if choice == 1 {
                add_item(&mut n_elements, &mut todo_items);
            } else {
                exit(0);
            }
        } else {
            print_list(n_elements, &todo_items, false);
            println!("------------------");
            println!("1 - Add a new Item");
            println!("2 - Remove an Item");
            println!("0 - Exit");
            choice = get_choice(2);
            match choice {
                0 => exit(0),
                1 => add_item(&mut n_elements, &mut todo_items),
                2 => remove_item(&mut n_elements, &mut todo_items),
                _ => exit(1),
            }
        }
    }
}

fn print_list(n_elements: u32, todo_items: &Vec<String>, delete: bool) {
    if delete {
        let mut printed = 0;
        for item in todo_items {
            println!("{} --> {item}", printed + 1);
            printed += 1;
            if printed == n_elements {
                break;
            }
        }
    } else {
        let mut printed = 0;
        for item in todo_items {
            println!("--> {item}",);
            printed += 1;
            if printed == n_elements {
                break;
            }
        }
    }
}

fn add_item(n_elements: &mut u32, todo_items: &mut Vec<String>) {
    let mut task = String::new();

    clear_screen();
    println!("Write the task you need to do:");
    println!();
    io::stdin()
        .read_line(&mut task)
        .expect("Failed to read task");
    todo_items.push(task.trim().to_string());
    *n_elements += 1;
}

fn remove_item(n_elements: &mut u32, todo_items: &mut Vec<String>) {
    clear_screen();
    println!("List of Removable Elements:");
    print_list(*n_elements, todo_items, true);
    println!("----------------------------------------------------------------------");
    println!("Please Insert the number corresponding to the item you want to delete:");
    let choice;
    choice = get_choice(*n_elements + 1);

    todo_items.remove((choice - 1) as usize);
    *n_elements -= 1;
}
