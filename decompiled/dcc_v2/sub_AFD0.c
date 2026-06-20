void __usercall sub_AFD0(unsigned int *a1@<X8>)
{
  unsigned int *v1; // x11
  unsigned int *v2; // x8
  unsigned int *v3; // x8
  unsigned int *v4; // x8
  unsigned int *v5; // x8

  v2 = (unsigned int *)atomic_load(a1);
  v3 = (unsigned int *)atomic_load(v2);
  v4 = (unsigned int *)atomic_load(v3);
  v5 = (unsigned int *)atomic_load(v4);
  atomic_load(v5);
  atomic_load(v1);
  JUMPOUT(0x78A0);
}
