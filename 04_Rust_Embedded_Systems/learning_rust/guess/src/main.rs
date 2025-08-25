use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    let secret = rand::rng().random_range(1..=100); //inclui sempre os numeros das pontas

    println!("welcome to the game of guessing");
    loop {
        println!("Please inpute your guess");

        let mut guess = String::new();

        io::stdin().read_line(&mut guess).expect("Failed");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        println!("hello, your guess is {guess}");

        match guess.cmp(&secret) {
            Ordering::Equal => {
                println!("Number Found, you won!!");
                break;
            }
            Ordering::Greater => {
                println!("big :(")
            }
            Ordering::Less => {
                println!("small :(")
            }
        }
    }
}
