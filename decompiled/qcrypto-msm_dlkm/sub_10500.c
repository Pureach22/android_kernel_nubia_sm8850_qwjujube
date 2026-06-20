void __noreturn sub_10500()
{
  atomic_uchar *v0; // x9
  unsigned __int8 v1; // w23
  atomic_ullong *v2; // x26
  unsigned __int8 v3; // w8

  v3 = atomic_exchange(v2, (unsigned __int64)v0);
  atomic_exchange(v0, v1);
  atomic_exchange(v0, v3);
  atomic_exchange(v0, v3);
  JUMPOUT(0x10550);
}
