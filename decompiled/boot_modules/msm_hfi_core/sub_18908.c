void __usercall sub_18908(unsigned int a1@<W8>)
{
  atomic_uint *v1; // x9

  atomic_exchange(v1, a1);
  JUMPOUT(0x15494);
}
