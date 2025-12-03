fn main() {
    let y: u32;
    {
        let x = 5;
        y = x;
    }
    println!("{y}"); // no problem, y is in scope and value was copied to it

    let z1 = 1;
    let z2 = z1;

    println!("{z1}"); // no problem, z1 still has value
    println!("{z2}");

    let string = String::from("hello");
    let string2 = string; // string was moved into string2, that's why now it does not work

    //println!("{string}"); cannot be done, compilation error because value of the string is moved
    println!("{string2}");

    let mut x = String::from("hello");

    x.push_str(", world!");

    println!("{x}");

    let stringg = String::from("ahoy");
    let stringg2 = stringg.clone();

    //both can be printed because we did a deep copy not shallow copy
    println!("{stringg}"); 
    println!("{stringg2 }");

}
