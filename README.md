# Ardunio-En-az-sayida-banknot-para-ustu-verme
## Ardunio kodu kullanılarak Proteus üzerinde çizim yapılmıştır.

1. Projeyi çalıstırabilmek için öncelikle ardunio kodunu derlemeniz ve altta çıkan hex uzantılı dosya yolunu kopyalamanız gerekmektedir.


![Ekran görüntüsü 2021-05-09 032636](https://user-images.githubusercontent.com/56557278/117557207-462fc800-b079-11eb-98cf-11fb1a898f93.jpg)

2. Devreyi çalıştırabilmek için Proteus üzerindeki Ardunio devresine sağ tıklayıp Edit Properties'e basmanız gerekli.
(Proteusu yönetici olarak çalıştırmanız önerilir.)

![Ekran görüntüsü 2021-05-09 032509](https://user-images.githubusercontent.com/56557278/117557253-b3435d80-b079-11eb-8a51-0e2f3558605b.jpg)

3.Açılan ekranda Program File kısmına kopyaladığımız dosya yolunu yapıştırın.

![Ekran görüntüsü 2021-05-09 032717](https://user-images.githubusercontent.com/56557278/117557273-e1c13880-b079-11eb-9c0a-c827c647f0ec.jpg)

4. Sol altta bulunan Run butonuna basarak artık devreyi çalıstırabilirsiniz.
![Ekran görüntüsü 2021-05-09 032817](https://user-images.githubusercontent.com/56557278/117557416-4f219900-b07b-11eb-9943-8f4ad3787475.jpg)

5. Yüklemek istediğiniz para miktarını tuşlayın ve bitiş butonuna basınız. Ardından yapmak istediğiniz işlemleri seçiniz.
![Ekran görüntüsü 2021-05-09 032844](https://user-images.githubusercontent.com/56557278/117557440-94de6180-b07b-11eb-8447-0b810d7ee55a.jpg)

6. Seçilen işlem sonucunda kalan hizmet adedi ve yapılan işlemin ücreti lcd ekran üzerinde gösterilir.

![Ekran görüntüsü 2021-05-09 032905](https://user-images.githubusercontent.com/56557278/117557456-b4758a00-b07b-11eb-9cd0-4c2f53f5aa76.jpg)

7.Son kez bitiş butonuna basılır ve paraüstü miktarı lcd ekran üzerinde gösterilir.

![Ekran görüntüsü 2021-05-09 032940](https://user-images.githubusercontent.com/56557278/117557473-da029380-b07b-11eb-9425-0be0862638c2.jpg)


İşlem sonunda random bir sayı üretilir.Eğer üretilen rastgele sayı 2'ye eşit işe kırmızı led yanar ve paranızın sıkıştığı anlamına gelir.Paranız iade edilir.Eğer üretilen sayı 2 den farklı ise işlem başarılı bir şekilde gerçekleştirilmiş demektir.
