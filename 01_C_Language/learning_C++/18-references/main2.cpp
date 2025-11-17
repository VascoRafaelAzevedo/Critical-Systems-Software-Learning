#include <iostream>


template <typename T>
class TSmartPtr
{
private:
    T *ptr;

public:
    TSmartPtr(T *p) : ptr(p)
    {
        std::cout << "Construtor: ptr=" << ptr << ", valor=" << *ptr << "\n";
    }

    ~TSmartPtr()
    {
        if (ptr)
        {
            std::cout << "Destrutor: delete ptr=" << ptr << ", valor=" << *ptr << "\n";
            delete ptr;
        }
        else
        {
            std::cout << "Destrutor: ptr=nullptr (não deleta)\n";
        }
    }

    TSmartPtr(const TSmartPtr &) = delete;
    TSmartPtr &operator=(const TSmartPtr &) = delete;

    TSmartPtr(TSmartPtr &&other) noexcept : ptr(other.ptr)
    {
        std::cout << "Move constructor: roubou ptr=" << ptr << "\n";
        other.ptr = nullptr;
    }

    TSmartPtr &operator=(TSmartPtr &&other) noexcept
    {
        std::cout << "Move assignment: this.ptr=" << ptr
                  << ", other.ptr=" << other.ptr << "\n";

        if (ptr)
        {
            std::cout << "  └─ Deletando valor antigo: " << *ptr << "\n";
            delete ptr; // DELETE #1
        }

        ptr = other.ptr;
        other.ptr = nullptr;

        std::cout << "  └─ Novo this.ptr=" << ptr << "\n";
        return *this;
    }

    T &operator*()
    {
        if (!ptr)
            throw std::runtime_error("Null poTer!");
        return *ptr;
    }
};

int main()
{
    std::cout << "=== Criando sp1 e sp2 ===\n";
    TSmartPtr<int> sp1(new int(10));
    TSmartPtr<int> sp2(new int(20));

    std::cout << "\n=== Antes do move ===\n";
    std::cout << "sp1=" << *sp1 << ", sp2=" << *sp2 << "\n";

    std::cout << "\n=== Move assignment ===\n";
    sp2 = std::move(sp1);

    std::cout << "\n=== Depois do move ===\n";
    std::cout << "sp2=" << *sp2 << "\n";

    std::cout << "\n=== Fim do main (destrutores) ===\n";

    std::cout << "\n=== Teste Self-Move ===\n";
    TSmartPtr<int> sp3(new int(30));
    std::cout << "Antes self-move: " << *sp3 << "\n";
    sp3 = std::move(sp3);                              // Move para si próprio!
    std::cout << "Depois self-move: " << *sp3 << "\n"; // Crash? Funciona?

    

    return 0;
}