class BaseModule {
public:
    BaseModule(){}
    ~BaseModule(){}

    virtual int Init();
    virtual int Update();
    virtual int Render();
    virtual int Shutdown();
};