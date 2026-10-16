#include <iostream>
#include <string>
using namespace std;

// Function to check prime
int isPrime(long int n)
{
    if (n <= 1) return 0;
    for (long int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Euclidean algorithm for GCD
long int gcd(long int a, long int b)
{
    while (b != 0)
    {
        long int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Find e and d
void find_e_and_d(long int z, long int &e, long int &d)
{
    for (e = 2; e < z; e++)
    {
        if (gcd(e, z) == 1) break;
    }
    for (d = 2; d < z; d++)
    {
        if ((e * d) % z == 1) break;
    }
}

// Modular exponentiation
long long modPow(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Encrypt and decrypt each character
void encrypt_and_decrypt(string message, long int e, long int n, long int d)
{

    cout << "\nPlaintext (P)\t\t\tCiphertext (C)\t\t\tAfter decryption\n";
    cout << "Symbolic\tNumeric\tP^" << e << "\tP^" << e << " mod " << n
         << "\tC^" << d << "\tC^" << d << " mod " << n << "\tSymbolic\n";

    for (int i = 0; i < message.length(); i++)
    {
        char ch = message[i];
        if (ch < 'A' || ch > 'Z') continue;

        long int P = ch - 'A' + 1;
        long long Pe = (long long)P * P * P;
        long long C = modPow(P, e, n);
        long long Cd = modPow(C, d, n);
        char decryptedChar = (char)(Cd + 'A' - 1);

        cout << ch << "\t\t" << P << "\t"
             << Pe << "\t" << C << "\t\t"
             << C << "\t" << Cd << "\t\t"
             << decryptedChar << endl;
    }

    cout << "\nSender's computation\t\tReceiver's computation\n";
}

int main()
{
    long int p, q, n, z, e, d;
    string message;

    cout << "Enter The First Prime Number (p)\n";
    cin >> p;
    if (!isPrime(p))
    {
        cout << "Error: " << p << " is not prime\n";
        return 1;
    }

    cout << "Enter Another prime Number (q)\n";
    cin >> q;
    if (!isPrime(q))
    {
        cout << "Error: " << q << " is not prime\n";
        return 1;
    }

    n = p * q;
    z = (p - 1) * (q - 1);
    find_e_and_d(z, e, d);

    cout << "\nRSA Parameters\n";
    cout << "p = " << p << ", q = " << q << endl;
    cout << "n = " << n << endl;
    cout << "z = " << z << endl;
    cout << "e = " << e << ", d = " << d << endl;
    cout << "Public Key = (" << e << ", " << n << ")\n";
    cout << "Private Key = (" << d << ", " << n << ")\n";

    cout << "\nEnter Message\n";
    cin >> message;

    encrypt_and_decrypt(message, e, n, d);

    return 0;
}
