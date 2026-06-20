void __usercall __noreturn sub_145D4(atomic_uint *a1@<X8>)
{
  atomic_uint *v1; // x11
  unsigned int *v2; // x19
  atomic_uint *v3; // x20
  atomic_uint *v4; // x22
  atomic_uint *v5; // x25
  atomic_uint *v6; // x26
  atomic_uint *v7; // x10
  unsigned int v8; // w8

  atomic_load(v2);
  v7 = (atomic_uint *)atomic_exchange((atomic_uint *volatile)atomic_exchange(v6, (unsigned int)a1), (unsigned int)a1);
  atomic_exchange(v1, (unsigned int)a1);
  atomic_exchange(v3, (unsigned int)a1);
  atomic_exchange(v4, (unsigned int)a1);
  atomic_exchange(v4, (unsigned int)a1);
  atomic_exchange(v4, (unsigned int)a1);
  atomic_exchange(v7, (unsigned int)v1);
  atomic_exchange(v7, (unsigned int)v1);
  atomic_exchange(v7, (unsigned int)v1);
  atomic_exchange(v7, (unsigned int)v1);
  atomic_exchange(v7, (unsigned int)v1);
  atomic_exchange(v7, (unsigned int)v1);
  atomic_exchange(v7, (unsigned int)v1);
  atomic_exchange(a1, (unsigned int)v7);
  atomic_exchange(v3, (unsigned int)a1);
  atomic_exchange(v3, (unsigned int)a1);
  atomic_exchange((atomic_uint *volatile)v2, (unsigned int)a1);
  atomic_exchange((atomic_uint *volatile)v2, (unsigned int)a1);
  atomic_exchange((atomic_uint *volatile)v2, (unsigned int)a1);
  atomic_exchange(v3, (unsigned int)a1);
  atomic_exchange(v3, (unsigned int)a1);
  atomic_exchange(v3, (unsigned int)a1);
  atomic_exchange(a1, atomic_exchange(v3, (unsigned int)a1));
  v8 = atomic_load(v2);
  atomic_exchange(v5, v8);
  atomic_exchange(v5, v8);
  atomic_exchange(v5, v8);
  atomic_exchange(v5, v8);
  atomic_exchange(v5, v8);
  atomic_exchange(v5, v8);
  atomic_exchange(v5, v8);
  atomic_exchange(v5, v8);
  atomic_exchange(v5, v8);
  atomic_exchange(v5, v8);
  atomic_exchange(v5, v8);
  atomic_exchange(v5, v8);
  atomic_exchange(v5, v8);
  JUMPOUT(0x148D4);
}
