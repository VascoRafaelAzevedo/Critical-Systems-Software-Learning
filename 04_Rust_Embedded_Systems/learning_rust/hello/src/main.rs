fn gcd(mut a: u64, mut b: u64) -> u64 {
    assert!(a != 0 && b != 0);
    while b != 0 {
        if a > b {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    a
}

fn main() {
    let result = gcd(18, 10);
    println!("GCD is: {}", result);
}
