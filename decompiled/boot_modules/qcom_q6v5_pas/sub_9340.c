void __usercall sub_9340(unsigned __int16 *a1@<X8>)
{
  unsigned __int16 *v1; // x9
  unsigned int *v2; // x19

  atomic_load(a1);
  atomic_load(v1);
  atomic_load(v2);
  JUMPOUT(0x9190);
}
