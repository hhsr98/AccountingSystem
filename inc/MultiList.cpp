#include "MultiList.h"
using namespace std;
MultiList::MultiList(string name):List_name(name),num_entry(0){

}

void MultiList::add_entry(PayingEntry* payingentry) {//�����µĸ�����Ŀ�������ַ�����vec_entry��
	num_entry++;
	vec_entry.push_back(payingentry);
} 


void MultiList::set_topay() {//���ô�Ŷ����˵����漰�������˵�Ӧ������map
	vector<PayingEntry*>::iterator iter;
	person_topay=(*(vec_entry[0])).get_person_topay();
	person_topaycopy=person_topay;//����PayingEntry�еľ�̬����
	num_person=(*(vec_entry[0])).get_total_person_num();//����PayingEntry�еľ�̬����
	for(iter=vec_entry.begin();iter!=vec_entry.end();iter++) {//������Ÿ�����Ŀ��vector
		map<string,double>::iterator iter1;
		map<string,double>temp=((*iter)->get_person_rate_list());//��ȡ�ñʸ�����Ŀ�е����������Ӧ�ı���
		double sum=((*iter)->get_total_num());//��ȡ�ñʸ�����Ŀ�е��ܽ��
		for(iter1=temp.begin();iter1!=temp.end();iter1++) {
			person_topay[iter1->first]+=iter1->second*sum;//��ĳ����ÿ��payingEntry�ø��Ľ����Ӵ���person_topay��
		}
	}
}

double MultiList::get_topay(string name) {//���ÿ������Ҫ֧������
	return person_topaycopy[name];
}

void MultiList::show_topay() {//������ת�˵ķ���
	map<string,double>::iterator iter,iter_swap;
	vector<string>temp;
	for(iter=person_topay.begin();iter!=person_topay.end();iter++) {//����map
		if(iter->second!=0)
		{
			temp.push_back(iter->first);
			 iter_swap=iter;
			 iter_swap++;
			while((iter_swap)->second==0)
			{
				iter_swap++;
			}
				temp.push_back(iter_swap->first);
				iter_swap->second+=iter->second;
				how_to_pay.insert ( std::pair<vector<string>,double>(temp,iter->second) );
				iter->second=0;
				vector <string>().swap(temp);
				iter_swap=iter;
				 iter_swap++;
				if((iter_swap->second<0.0000001&&iter_swap->second>-0.0000001))
					break;
		}
	}
}

const map<vector<string>,double> MultiList::get_how_to_pay()const {
	return how_to_pay;
}

const vector<PayingEntry*>MultiList::get_vec_entry()const {
	return vec_entry;
}

const map<string,double>MultiList::getperson_topaycopy()const {
	return person_topaycopy;
}

const std::string MultiList::get_name()const {
	return List_name;
}

const int MultiList::get_num() const {
	return num_entry;
}