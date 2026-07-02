[+] UDP telemetry (tamamlandı)
[] TCP komut kanalı (bidirectional, reliable)
[] Binary protokol tasarımı (header + payload, framing)
[] Multithreading patterns (producer/consumer, thread pool)
[] Reconnection & fault tolerance
[] Integration testing (gerçek socket'larla test)
[] cc-core'u Qt'dan tamamen bağımsız hale getirme
Sorun A: cc-core Qt'ya bağımlı — UdpReceiver QObject'ten türüyor, cc-core Qt6::Core linkliyor. Oysa cc-core saf C++ olmalı.

Sorun B: QTableWidget yerine QAbstractTableModel + QTableView — gerçek Model/View.