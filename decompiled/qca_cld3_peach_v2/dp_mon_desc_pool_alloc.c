__int64 __fastcall dp_mon_desc_pool_alloc(
        __int64 a1,
        unsigned int a2,
        int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v13; // x8

  *(_DWORD *)a4 = a3 - 1;
  v13 = dp_context_alloc_mem(a1, a2, 32LL * (unsigned int)(a3 - 1), a5, a6, a7, a8, a9, a10, a11, a12);
  *(_QWORD *)(a4 + 8) = v13;
  return 0;
}
