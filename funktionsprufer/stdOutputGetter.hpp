#ifndef STDOUTPUTGETTER_HPP
#define STDOUTPUTGETTER_HPP

class stdOutputGetter
{
public:
  stdOutputGetter(std::string filebufName);
  ~stdOutputGetter();
private:
    int oldId = 0;
};

#endif
