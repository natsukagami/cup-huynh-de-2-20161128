# “兄弟のカップ – II” の 解説

## Long và A: 
Bài yêu cầu nhập vào một xâu s và in ra kí tự đầu tiên của xâu s, vì xâu có thứ tự từ điển nhỏ nhất là tiền tố của xâu s là tiền tố ngắn nhất của s, hay là kí tự đầu tiên của xâu s.
#### Độ phức tập : O(1).
## Long và B : 
### Cách 1 : 
dp[i][j] là số cách để tạo ra dãy độ dài i và kí tự thứ i là j. Đáp án là tổng các dp[k][i] với i chạy từ 1 đến n.

dp[i][j]=tổng các dp[i-1][k] với k chạy từ 1 đến j.

Việc tính trên có thể mất O(n3), nhưng việc tính tổng có thể chuẩn bị và cập nhật trong lúc QHĐ, nên chỉ mất O(n2).
#### Độ phức tạp : O(n2).
### Giải thuật O(n*log2(n)): 
Số cách tạo ra dãy có độ dài k không giảm sử dụng các số từ 1 đến n giống như là số cách chia k số vào n nhóm. Đáp án là bài toán chia kẹo, C(n-1,k+n-1).
### Độ phức tạp : O(n*log2(n)).
*Lưu ý : mod là 100000007, không phải là 1000000007.*
## Long và C : 
Ta nhận xét rằng các thao tác trên không quan trọng thứ tự thực hiện, cho nên ta sẽ xét việc làm các hàng trước rồi mới làm các cột. Với cặp cột, ta sẽ kiểm tra nếu hai ô đầu cột khác nhau thì tất cả các ô tương ứng ở hai cột phải khác nhau và tương tự.
#### Độ phức tạp : O(n2).
## Long và D : 
Có rất nhiều cách giải bài này :
+ Sử dụng kĩ thuật tính toán với số lớn như anh Khánh đã dạy trong 5 phút. Cách cài tra BIGNUM trên https://kienthuc24h.com/ . Nộp thử trên http://vn.spoj.com/problems/BIGNUM/ .
+ Sử dụng log10 của một số. Ta đọc vào số lớn trên rồi tính số chữ số của nó, và nhân dần đến lúc nào log10 của tích bằng số chữ số của số lớn.
Ta có tính chất log10(a)+log10(b)=log10(a*b), vì vậy ta có thể tính được liên tục trong lúc for tính gia thừa. Tuy vậy với những trường hợp bé ta sẽ if để tránh sai.
+ Sử dụng mod là số nguyên tố lớn. Ta nhận xét rằng các giai thừa từ 1! đến 1000! thì số dư khi chia cho 100000007 hoặc 1000000007 sẽ cho ra nhưng số dư khác nhau, cho nên ta chỉ cần lưu lại số dư và tính đến khi nào số dư đúng bằng số dư của số lớn khi chia cho mod.

#### Độ phức tạp : Trường hợp tệ nhất là O(1000).
## Long và E : 
Ta nhận xét rằng sau khi sort lại thì ta lấy k số liên tục thì sẽ có tổng các giá trị tuyệt đối các hiệu là tối ưu nhất. Ta sẽ tính k số đầu tiên, rồi dịch chuyển đoạn k số trong dãy n số.
#### Độ phức tạp : O(n).
Chứng minh : Giả sử trong dãy n số a1,a2,a3,…,an-1,an+1 có một số an nằm giữa  an-1 và an+1 thì ta dễ thấy rằng nếu thay số an+1 bằng an thì ta sẽ có một kết quả tối ưu hơn vì tổng các hiệu sẽ giảm đi một lượng là (an+1-an)\*(n-1).
## Long và F : 
Với mỗi thằng bé ta sẽ tính dãy tăng dần độ ngoan liên tiếp dài nhất kết thúc ở nó, và dãy giảm dần độ ngoan dài nhất bắt đầu ở nó. Số kẹo min cần đưa cho mỗi thằng bé là max của hai giá trị.
#### Độ phức tạp : O(n).
## Long và G : 
dp[i][mask1][mask2] là số con mã lớn nhất đặt được tính đến dãy thứ i với hai hàng cuối có dạng mask1 và mask2. Ta sẽ còn phải kiểm tra xem mask có thỏa mãn không (là có bit nào bị cấm mà vẫn có con mã không), sau đó quy về dp[i-1][mask3][mask1] + số bit hoạt động của mask2. Tính mảng này mất O(n*82). Số con mã đặt được nhiều nhất là max của dp[n][0→7][0→7], đặt là ans.

Sau tính xong rồi, ta lại có hàm QHĐ thứ 2 : 

pd[i][mask1][mask2][cnt] là số cách đặt tính đến dãy thứ i với hai hàng cuối có dang mask1 và mask2, truy về pd[i-1][mask3][mask1][cnt-số bit hoạt động của mask2]. Đáp án là tổng của các pd[n][0→7][0→7][ans]. Vẫn có chú ý như hàm thứ nhất.
#### Độ phức tạp : O(n*82+n*82*ans).
## Long và H : 
dp[i][ch1][ch2] là đến hàng thứ i dùng 2 kí tự ch1 và ch2. (Lưu ý để ch1 và ch2 dưới dạng các số từ 0 đến 25) Ta tính bằng dp[i-1][ch3][ch4]. Chú ý kiểm tra ch1 khác ch2 và ch1 khác ch3 và ch2 khác ch4. Ta sẽ for cả hàng để cập nhật số ô phải sửa trong hàng. Có thể giảm độ phức tạp bằng việc chuẩn bị trước mảng change[i][ch1][ch2], là số ô cần thay đổi để  được hàng i chỉ toàn ch1 và ch2.
#### Độ phức tạp : O(n*262*(m+262)).
## Long và I : 
Ta sẽ thấy tối ưu nhất là đổi các block toàn 0 liên tiếp thành các số 1 liên tiếp, để tạo ra dãy toàn 1 dài nhất. Ta sẽ tìm các đoạn 0 liên tục có tổng <=k, và đổi trạng thái dãy trên để tạo ra đoạn liên tục số 1 dài nhất là các tổng các đoạn 1 bao quanh các đoạn 0, cộng thêm k. Lưu lại giá trị max của các đoạn trên khi chạy trên dãy.
#### Độ phức tạp : O(n).
## Long và J : 
dp[i][j] là số cách tạo dãy ngoặc có độ dài i, tổng là j. dp[i][j]=dp[i-1][j+1] và cộng thêm dp[i-1][j-1] nếu j>0. Khởi tạo dp[0][0]=0.

Trong xâu S, ta sẽ tính tổng bé nhất của tiền tố của xâu ngoặc S, gọi là l, và tổng của dãy ngoặc là s.
Số cách tạo ra dãy ngoặc là tổng các dp[i][j]*dp[m-n-i][j+s], với i chạy từ 0 đến (m-n), và j chạy từ max(l,0) đến i, vì chắc chắn tổng của dãy sẽ không vượt quá i.
#### Độ phức tạp : O(n2).
## Long và K : 
Ta for và lưu số lượng số có bit thứ i hoạt động vào mảng cnt[i]. 

Ta for với mỗi một số từ a[1] đến a[n], ta sẽ kiểm tra xem nó có là ANH, OR hay XOR của các số còn lại hay không như sau :
+ Nếu số số còn lại có bit thứ j hoạt động bằng n-1 và bit thứ j của a[i] hoạt động thì đúng, và ngược lại. Nếu đúng với tất cả các bit của a[i] thì ta có số bằng AND của tất cả các số.
+ Nếu số số còn lại có bit thứ j hoạt động lớn hơn hoặc bằng 1 và bit thứ j của a[i] hoạt động thì đúng, và ngược lại. Nếu đúng với tất cả các bit của a[i] thì ta có số bằng OR của tất cả các số.
+ Nếu số số còn lại có bit thứ j hoạt động là lẻ và bit thứ j của a[i] hoạt động thì đúng, và ngược lại. Nễu đúng với tất cả các bit của a[i] thì ta có số bằng XOR của tất cả các số.

#### Độ phức tạp : O(n*log2(109)), hay O(n*30).
# ~終わり,さよなら!!~