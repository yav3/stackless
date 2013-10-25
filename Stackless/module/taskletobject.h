#define TASKLET_INSERT_HEAD(func) \
    int func (PyTaskletObject *task)

#define TASKLET_RUN_HEAD(func) \
    PyObject *func (PyTaskletObject *task)

#define TASKLET_REMOVE_HEAD(func) \
    int func (PyTaskletObject *task)

#define TASKLET_SETATOMIC_HEAD(func) \
    int func (PyTaskletObject *task, int flag)

#define TASKLET_SETIGNORENESTING_HEAD(func) \
    int func (PyTaskletObject *task, int flag)

#define TASKLET_CALL_HEAD(func) \
    int func (PyTaskletObject *task, PyObject *args, PyObject *kwds)

#define TASKLET_RAISE_EXCEPTION_HEAD(func) \
    PyObject *func (PyTaskletObject *self, PyObject *klass, PyObject *args)

#define TASKLET_THROW_HEAD(func) \
    PyObject *func (PyTaskletObject *self, int pending, PyObject *exc, PyObject *val, PyObject *tb)

#define TASKLET_KILL_HEAD(func) \
    PyObject *func (PyTaskletObject *task, int pending)


typedef struct _pytasklet_heaptype {
    PyFlexTypeObject type;
    /* the fast callbacks */
    TASKLET_INSERT_HEAD(                (*insert)            );
    TASKLET_RUN_HEAD(                   (*run)               );
    TASKLET_REMOVE_HEAD(                (*remove)            );
    TASKLET_SETATOMIC_HEAD(             (*set_atomic)        );
    TASKLET_SETIGNORENESTING_HEAD(      (*set_ignore_nesting));
    TASKLET_RAISE_EXCEPTION_HEAD(       (*raise_exception)   );
    TASKLET_KILL_HEAD(                  (*kill)              );
    TASKLET_THROW_HEAD(                 (*_throw)            );
} PyTasklet_HeapType;

int init_tasklettype(void);
