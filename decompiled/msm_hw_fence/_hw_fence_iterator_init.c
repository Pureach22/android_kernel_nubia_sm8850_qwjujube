__int64 __fastcall hw_fence_iterator_init(
        __int64 a1,
        unsigned __int64 *a2,
        unsigned __int64 *a3,
        __int64 a4,
        __int64 a5,
        unsigned int a6,
        unsigned int a7)
{
  __int64 v7; // x30
  unsigned __int64 v8; // x20
  unsigned int v9; // w21
  unsigned __int64 v11; // x7
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x8
  __int64 v15; // x21
  unsigned __int64 *v16; // x22
  unsigned __int64 *v17; // x23
  __int64 v18; // x24

  v8 = *(unsigned int *)(a1 + 80);
  v9 = a7;
  if ( a2 && a6 < a7 && (unsigned int)v8 >= a7 )
  {
    v11 = (int)((907 * a4 + 4969 * a5 * (2 * a4 - 1)) % v8);
    *a3 = v11;
    if ( (~msm_hw_fence_debug_level & 0x10020) == 0 )
    {
      v15 = a1;
      v16 = a2;
      v17 = a3;
      v18 = v7;
      printk(&unk_227F2, "_hw_fence_iterator_init", 1174, a4, a5);
      v11 = *v17;
      v7 = v18;
      a2 = v16;
      a3 = v17;
      a1 = v15;
    }
    v12 = (v11 + a6) % v8;
    *a3 = v12;
    v13 = *(_QWORD *)(a1 + 64) + (v12 << 7);
    *a2 = v13;
    if ( v13 )
    {
      global_atomic_store(a1, v13 + 40, 1);
      return a6;
    }
    else
    {
      printk(&unk_2A7E8, "_hw_fence_lookup_next", 1148, v7, *a3);
      return (unsigned int)v8;
    }
  }
  else
  {
    printk(&unk_212DA, "_hw_fence_iterator_init", 1167, v7, a1);
  }
  return v9;
}
