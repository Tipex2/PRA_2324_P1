#include <ostream>
#include "List.h"

template <typename T>
class ListArray : public List<T> {

	private:
		T*arr;
		int max;
		int n;
		static const int MINSIZE;

		void resize(int new_size){
			T* new_arr = new T[new_size];
			std::copy(arr, arr + n, new_arr);
			delete[] arr;
			arr = new_arr;
			max = new_size;
			};
	public:
		ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}

		~ListArray() { delete[] arr; }

		T operator[](int pos){
			if (pos < 0 || pos >=n) {
				throw std::out_of_range("Invalid position");
			}
			return arr[pos];
		}

		friend std::ostream& operator<<(std::ostream &out, const ListArray<T>& list){
			for (int i = 0; i < list.n; i++) {
				out << list.arr[i] << " ";
			}
			return out;
		}
};

