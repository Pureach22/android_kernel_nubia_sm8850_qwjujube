__int64 __fastcall hw_fence_iterator_next(
        __int64 a1,
        unsigned __int64 *a2,
        unsigned __int64 *a3,
        unsigned int a4,
        unsigned int a5,
        char a6)
{
  __int64 v6; // x30
  unsigned __int64 v9; // x27
  __int64 v10; // x25
  unsigned int v15; // w19
  int v16; // w8
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  const char *v20; // x3

  v9 = *(unsigned int *)(a1 + 80);
  v10 = v6;
  global_atomic_store(a1, *a2 + 40, 0);
  v15 = a4 + 1;
  v16 = msm_hw_fence_debug_level & 0x10020;
  if ( a4 + 1 >= a5 || (a6 & 1) != 0 )
  {
    if ( v16 == 65568 )
    {
      if ( (a6 & 1) != 0 )
        v20 = "true";
      else
        v20 = "false";
      printk(&unk_29829, "_hw_fence_iterator_next", 1190, v20, a4);
    }
    if ( (a6 & 1) != 0 )
      return a4;
  }
  else
  {
    if ( v16 == 65568 )
      printk(&unk_29883, "_hw_fence_iterator_next", 1195, v15, a5);
    v17 = (*a3 + 1) % v9;
    *a3 = v17;
    v18 = *(_QWORD *)(a1 + 64) + (v17 << 7);
    *a2 = v18;
    if ( v18 )
    {
      global_atomic_store(a1, v18 + 40, 1);
    }
    else
    {
      printk(&unk_2A7E8, "_hw_fence_lookup_next", 1148, v10, *a3);
      return (unsigned int)v9;
    }
  }
  return v15;
}
