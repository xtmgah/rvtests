#ifndef _VCFHEADER_H_
#define _VCFHEADER_H_

class VCFHeader{
  public:
    void push_back(const std::string& s){
        this->data.push_back(s);
    }
    void getPeopleName(std::vector<std::string>* p) const{
        if (!p) return;
        if (this->data.size() < 1) return;
        const std::string ln = this->data[this->data.size() - 1];
        
        std::vector<std::string> fd;
        stringTokenize(ln, "\t", &fd);
        if (fd.size() < 10) return;
        p->clear();
        for (int i = 9; i < fd.size() ; i++) {
            p->push_back(fd[i]);
        }
    };
    int size() const {return this->data.size();}
    std::string operator[] (int n) {return this->data[n];};
    const std::string operator[] (int n) const {return this->data[n];};
    std::string at(int n) { return this->data.at(n);};
    const std::string at(int n) const {return this->data.at(n);};
  private:
    std::vector<std::string> data;
};

#endif /* _VCFHEADER_H_ */
