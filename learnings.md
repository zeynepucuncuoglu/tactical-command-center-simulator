*  & farkı:
 int* x = &p //p nin adresini tut demek, bu boş olabilir null ptr olabilir
 burda p nin değerine erişmek isterse ama
 *x şeklinde kullanıyoruz. 

 int& x = p //p yi kopyalamıyor p nin referansı adresi DEĞİL!!
***
 QObject:  qt de signal slot kullanabilmek için o sınfın qobjectten türemesi lazım.
***
 std::function
 ### Callback Notu

**Callback**, bir sınıfa veya fonksiyona sonradan çalıştırması için verdiğimiz fonksiyondur.

Örnek:

```cpp
UdpReceiver receiver(
    9000,
    targetManager,
    callback
);
```

Burada `UdpReceiver`'a şunu söylemiş oluyoruz:

> "Yeni bir Target geldiğinde bu fonksiyonu çağır."

---

Bizim örneğimizde callback:

```cpp
[&](const Target& target)
{
    QMetaObject::invokeMethod(
        &window,
        [&window, target]()
        {
            window.onTargetReceived(target);
        },
        Qt::QueuedConnection
    );
}
```

Akış:

```text
UDP paketi gelir
↓
UdpReceiver Target oluşturur
↓
m_callback(target)
↓
Callback çalışır
↓
invokeMethod ile iş GUI thread kuyruğuna eklenir
↓
window.onTargetReceived(target)
↓
Tablo güncellenir
```

### Neden callback kullanıyoruz?

`UdpReceiver` UI'ı, veritabanını veya log sistemini bilmek zorunda kalmaz.

Sadece:

```cpp
std::function<void(const Target&)> m_callback;
```

tutar ve zamanı gelince çağırır.

Bu sayede sınıflar birbirine sıkı bağlı olmaz (**loose coupling**).

### Lambda neden kullanıldı?

Çünkü callback'in dışarıdaki `window` nesnesine erişmesi gerekiyor:

```cpp
[&window](const Target& target)
{
    ...
}
```

Lambda, dışarıdaki değişkenleri **capture** ederek callback içinde kullanabilmemizi sağlar. Bu yüzden modern C++'ta callback'ler çoğunlukla lambda ile verilir.
****

listen(sockfd, backlog) — "bu socket'e bağlantı kabul et" der, backlog ise kaç bağlantının kuyrukta bekleyebileceğini belirtir.

accept() — kuyruktaki bir bağlantıyı alır ve yeni bir socket döndürür. Orijinal server socket hâlâ dinlemeye devam eder, yeni socket sadece o client ile konuşur.
****