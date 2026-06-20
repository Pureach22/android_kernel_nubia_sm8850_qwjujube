void __usercall __noreturn sub_75D0(unsigned int *a1@<X8>)
{
  unsigned int *v1; // x9
  unsigned int *v2; // x8
  unsigned int *v3; // x8
  unsigned int *v4; // x8
  unsigned int *v5; // x9

  v2 = (unsigned int *)atomic_load(a1);
  v3 = (unsigned int *)atomic_load(v2);
  atomic_load(v3);
  atomic_load(v3);
  atomic_load(v3);
  v4 = (unsigned int *)atomic_load(v3);
  v5 = (unsigned int *)atomic_load(v1);
  atomic_load(v4);
  atomic_load(v4);
  atomic_load(v5);
  JUMPOUT(0x75F8);
}
