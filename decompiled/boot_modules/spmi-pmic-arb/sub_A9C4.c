void __usercall __noreturn sub_A9C4(unsigned int *a1@<X8>)
{
  unsigned int *v1; // x9
  unsigned int *v2; // x19
  unsigned int *v3; // x8

  atomic_load(v2);
  atomic_load(v1);
  v3 = (unsigned int *)atomic_load(a1);
  atomic_load(v3);
  JUMPOUT(0xA9D4);
}
