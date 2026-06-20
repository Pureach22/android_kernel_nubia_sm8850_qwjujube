void sub_210020()
{
  __int64 v0; // x20

  atomic_load_explicit((atomic_uint *volatile)(v0 + 153), memory_order_acquire);
  JUMPOUT(0x210024);
}
