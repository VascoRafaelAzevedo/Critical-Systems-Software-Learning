#include <iostream>

// Default deleter
template<typename T>
struct DefaultDeleter {
    void operator()(T* ptr) const {
        std::cout << "DefaultDeleter: delete " << ptr << "\n";
        delete ptr;
    }
};

// Array deleter
template<typename T>
struct ArrayDeleter {
    void operator()(T* ptr) const {
        std::cout << "ArrayDeleter: delete[] " << ptr << "\n";
        delete[] ptr;
    }
};

template<typename T, typename Deleter = DefaultDeleter<T>>
class TSmartPtr {
private:
    T* ptr;
    Deleter deleter;  // Objeto que sabe como deletar

public:
    TSmartPtr(T* p = nullptr) : ptr(p), deleter() {
        if (ptr) std::cout << "Construtor: " << ptr << "\n";
    }
    
    ~TSmartPtr() {
        if (ptr) {
            deleter(ptr);  // Usa o deleter customizado!
        }
    }
    
    // Proibir cópia
    TSmartPtr(const TSmartPtr&) = delete;
    TSmartPtr& operator=(const TSmartPtr&) = delete;
    
    // Move semantics
    TSmartPtr(TSmartPtr&& other) noexcept 
        : ptr(other.ptr), deleter(std::move(other.deleter)) {
        other.ptr = nullptr;
    }
    
    TSmartPtr& operator=(TSmartPtr&& other) noexcept {
        if (this == &other) return *this;  // Self-assignment protection
        
        if (ptr) {
            deleter(ptr);
        }
        
        ptr = other.ptr;
        deleter = std::move(other.deleter);
        other.ptr = nullptr;
        
        return *this;
    }
    
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    T* get() const { return ptr; }
    
    // Para arrays: operator[]
    T& operator[](size_t index) const {
        return ptr[index];
    }
};

int main() {
    std::cout << "=== Teste 1: Single object ===\n";
    {
        TSmartPtr<int> sp(new int(42));
        std::cout << "Valor: " << *sp << "\n";
    }  // DefaultDeleter usado
    
    std::cout << "\n=== Teste 2: Array ===\n";
    {
        TSmartPtr<int, ArrayDeleter<int>> spArray(new int[5]{10, 20, 30, 40, 50});
        
        for (int i = 0; i < 5; i++) {
            std::cout << "spArray[" << i << "] = " << spArray[i] << "\n";
        }
    }  // ArrayDeleter usado
    
    std::cout << "\n=== Teste 3: Custom deleter (file handle simulation) ===\n";
    {
        struct FileDeleter {
            void operator()(int* ptr) const {
                std::cout << "FileDeleter: fechando 'arquivo' e delete\n";
                // Aqui farias fclose() ou similar
                delete ptr;
            }
        };
        
        TSmartPtr<int, FileDeleter> spFile(new int(999));
        std::cout << "File handle: " << *spFile << "\n";
    }  // FileDeleter usado
    
    std::cout << "\n=== Fim ===\n";
    return 0;
}