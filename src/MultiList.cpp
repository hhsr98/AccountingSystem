#include "../inc/MultiList.h"
MultiList::MultiList(string name):List_name(name),num_entry(0){

}

void MultiList::add_entry(Commodity* com,int num) {//����µĸ�����Ŀ�������ַ�����vec_entry��
	num_entry++;
	SmartPtr<PayingEntry>ptr=new PayingEntry(com,num);
	vec_entry.push_back(ptr);
} 


void MultiList::set_topay() {//���ô�Ŷ����˵����漰�������˵�Ӧ������map
	vector<SmartPtr<PayingEntry>>::iterator iter;
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
	for(iter=person_topay.begin();iter!=person_topay.end();iter++) {//����map
		if(iter->second>0)//������0��ʱ�������������ת�������һ���������������
		{
			iter_swap=iter++;
			while((iter_swap)->second==0)
				iter_swap++;
			cout<<iter->first<<"֧����"<<iter_swap->first<<iter->second<<endl;
			iter_swap->second+=iter->second;
			iter->second=0;
		}
		if(iter->second<0)//��С����ʱ����ǰ���һ��������������˳�ת����ȱ�Ľ����
		{
				iter_swap=iter--;
				while(iter_swap->second==0)
					iter_swap--;
				cout<<iter_swap->first<<"֧����"<<iter->first<<iter->second<<endl;
				iter_swap->second+=iter->second;
				iter->second=0;
		}

	}

}

