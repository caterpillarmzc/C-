//string类对象的常见构造
void TestString(){
	string s1;//构造空的string类对象
	string s2("hello world");//用c格式字符串构造string类对象s2
	string s3(s2);//拷贝构造s3
}


void TestString1(){
	//string类对象支持直接用cin和cout进行输入和输出
	string s("hello world!!");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s << endl;

	//将s中的字符串清空,注意清空知识将size清零,不改变底层空间的大小
	s.clear();
	cout << s.size() << endl;

	//将s中有效字符个数增加到10个,多出位置用'a'补充
	s.resize(10, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//将s中有效字符个数缩小到5个
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

}

void TestString2(){
	string s;
	//测试reserve是否会改变string中的有效元素个数
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//测试reserve参数小于string的底层空间大小,是否会将空间缩小
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

//利用reserve提高插入数据的效率,避免增容带来的开销
void TestPushBackReserve(){
	string s;
	s.reserve(100);
	size_t sz = s.capacity();

	cout << "making s growK\n";
	for (int i = 0; i < 100;++i){
		s.push_back('c');
		if (sz!=s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
}