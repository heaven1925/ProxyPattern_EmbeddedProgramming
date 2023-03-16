# ProxyPattern_EmbeddedProgramming - @a.ertekin 
Object Oriented Programming Proxy Pattern Application Basic Adc Sensor Read 

< ENG > 
This code is designed to create an example of the proxy design pattern, which provides an interface to control access to a real object.

The code defines a structure to create a sensor object and uses a structure to create a sensor object. 
Then, a real sensor object and a proxy sensor object are created. While the real sensor object is used to read the real sensor values, the proxy sensor object controls access to the real sensor and only creates the real sensor object when access to the real sensor is necessary.

The code switches between real and proxy sensor objects using many different sensor read functions. 
These functions use HAL_ADC functions to read data from different channels of sensors. 
Each of these functions can be called on the real sensor object or the proxy sensor object.

As a result, the purpose of this code is to create an example of the proxy design pattern and provide an interface to control access to the real sensor object.


< TR > 
Bu kodun yapısı ve tasarımı, bir proxy tasarım kalıbı örneği oluşturmak için tasarlanmıştır. 
Bu tasarım kalıbı, gerçek bir nesneye erişimi kontrol etmek için bir ara yüz sağlar.

Kod, bir sensör nesnesi oluşturmak için bir yapı tanımlar ve bir sensör nesnesi oluşturmak için bir yapı kullanır. 
Ardından, bir gerçek sensör nesnesi ve bir proxy sensör nesnesi oluşturulur. 
Gerçek sensör nesnesi, gerçek sensör değerlerini okumak için kullanılırken, proxy sensör nesnesi gerçek sensöre erişimi kontrol eder ve sadece gerçek sensöre erişimin gerekli olduğu zaman gerçek sensör nesnesini oluşturur.

Kod, birçok farklı sensör okuma işlevi kullanarak gerçek ve proxy sensör nesneleri arasında geçiş yapar. 
Bu işlevler, sensörlerin farklı kanallarından verileri okumak için HAL_ADC fonksiyonlarını kullanır.
Bu fonksiyonların her biri, gerçek sensör nesnesi veya proxy sensör nesnesi üzerinde çağrılabilir.

Sonuç olarak, bu kodun amacı, bir proxy tasarım kalıbı örneği oluşturmak ve gerçek sensör nesnesine erişimi kontrol etmek için bir ara yüz sağlamaktır.
