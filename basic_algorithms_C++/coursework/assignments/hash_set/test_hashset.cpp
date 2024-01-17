#include"set.h"
#include"hash_set.h"
#include "key_value.h"

int main(int argc, char const *argv[])
{
    Set<KeyValue>* set{new HashSet<KeyValue>( 
        [] (const KeyValue& kv) { return static_cast<size_t>(kv.key); }
        , LINEAR
    )};

    set->add(KeyValue(1,2.0));
    set->remove(KeyValue(1,2.0));
    set->empty();
    set->contains(KeyValue(1,2.0));

    return 0;
}