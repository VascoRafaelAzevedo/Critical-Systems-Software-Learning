use std::{cmp::Ordering, io};

use rand::Rng;

fn main() {
    println!("GUESSING GAME");

    let mut rng = rand::rng();

    let number: u32 = rng.random_range(1..100);

    loop {
        println!("Insert a number:");
        let mut guess = String::new();

        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");
        let guess: u32 = guess.trim().parse().expect("INPUT A NUMBER");
        match guess.cmp(&number) {
            Ordering::Less => println!("LESSER"),
            Ordering::Equal => {
                println!("BINGO");
                break;
            }
            Ordering::Greater => println!("MAJOR"),
        }
    }

}
