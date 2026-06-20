void sub_2B8E0()
{
  unsigned __int16 v0; // w22
  atomic_ushort *v1; // x29

  atomic_fetch_add_explicit(v1, v0, memory_order_relaxed);
  JUMPOUT(0x2B8E4);
}
