# 🔐 RSA Encryption/Decryption

## 📖 Project Description
This project is a **C program** designed to implement the **RSA encryption algorithm** from scratch, as part of an ASD2 (Algorithms and Data Structures 2) project.

It provides a console-based interface to manage messages, generate RSA keys, encrypt messages from a file, and then decrypt them to retrieve the original text.

The system is designed to manage:
- Adding new messages to a text file (`phrases.txt`)
- Generation of large prime numbers and RSA key pairs (public and private)
- Use of **Stacks** to store the keys and **Lists** to store the messages
- Encryption of messages, character by character
- Decryption of the encrypted data to verify the original message

---

## 👥 Authors
- **Khalil Naffeti**
- **Thouaiba Boumedyen**

---

## 🗂️ Project Structure & Key Features

### 1. Main Menu & Message Management
<img width="1238" height="705" alt="image" src="https://github.com/user-attachments/assets/645b86ff-4001-4570-80e5-28719d8ef65c" />

The program presents a menu with three options: 1. Add messages, 2. Encrypt/Decrypt, or 3. Quit.
- **Option 1 (`messages_ajouter`):** Allows the user to add multiple new messages one by one, which are saved to a `phrases.txt` file.
- **Option 2:** First, the program counts the total number of messages available in `phrases.txt`. It then asks the user how many of these messages they want to process.
- **Data Loading:** The selected messages are read from the file and loaded into a list (`LISTE L`) for processing.

### 2. RSA Key Generation
This is the core of the RSA algorithm, generating a unique key pair for each message.
- **Prime Generation (`generate_prem`):** The program first generates a list of prime numbers (up to 10000) to be used as a source.
- **Key Pair Creation:** For each message, the system:
    1.  Randomly selects two distinct primes, `p` and `q`, from the list.
    2.  Calculates the modulus `n = p * q`.
    3.  Calculates Euler's totient `phi_n = (p-1) * (q-1)`.
    4.  Finds a public exponent `e` (using `exposant`) that is coprime to `phi_n`.
    5.  Calculates the private exponent `d` using the modular inverse (`mod_inverse`), which is found using the extended Euclidean algorithm.

### 3. Key Management with Stacks
The system uses two stacks to manage the keys for each message: `pilepublic` and `pileprivee`.
- **`Empiler(pilepublic, ...)`:** The **public key (n, e)** is pushed onto the public stack.
- **`Empiler(pileprivee, ...)`:** The **private key (n, d)** is pushed onto the private stack.
- This LIFO (Last-In, First-Out) structure ensures the correct private key is used to decrypt its corresponding message.

### 4. Encryption Process (`chiffrement`)
<img width="1238" height="619" alt="image" src="https://github.com/user-attachments/assets/0c5c98fd-e2ef-4c04-85a8-9d1c3265490b" />

The encryption function iterates through each message in the list.
- **Get Key:** It pops a public key `(n, e)` from the `pilepublic` stack.
- **Encrypt:** It encrypts the message character by character.
- **Formula:** Each character's ASCII value `M` is transformed using the formula **`C = M^e mod n`**. This calculation is performed by the `Exponentiation_Modulaire` function.
- **Store:** The resulting encrypted numbers are stored in a `LISTECrypt` structure.

### 5. Decryption Process (`dechiffrement`)
<img width="1238" height="672" alt="image" src="https://github.com/user-attachments/assets/5551091e-459f-497d-92c5-f329c76591d5" />

The decryption function processes the list of encrypted numbers.
- **Get Key:** It pops the corresponding private key `(n, d)` from the `pileprivee` stack.
- **Decrypt:** It decrypts each number `C` in the message.
- **Formula:** The original ASCII value is recovered using the formula **`M = C^d mod n`**. This also uses the `Exponentiation_Modulaire` function.
- **Result:** The ASCII value `M` is converted back to a character (`Convertir_Char`), and the original message is reconstructed and displayed.

---

## 🚀 Installation & Usage
1.  **Clone the Repository:**
    ```bash
    git clone [https://github.com/YourUsername/YourRepoName.git](https://github.com/YourUsername/YourRepoName.git)
    ```
2.  **Compile the Project:**
    * You will need a C compiler (like **GCC**).
    * Navigate to the project directory and compile the source files (e.g., `main.c`). You may need to link the math library.
    ```bash
    gcc *.c -o rsa_project -lm
    ```
3.  **Run the Application:**
    * Execute the compiled program from your terminal.
    ```bash
    ./rsa_project
    ```
    *(On Windows, you might run `rsa_project.exe`)*

4.  **Follow the Menu:**
    * First, choose option `1` to add some messages.
    * Then, run the program again and choose option `2` to encrypt and decrypt the messages you just added.
