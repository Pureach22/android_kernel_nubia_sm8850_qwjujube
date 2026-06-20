__int64 __fastcall dp_mon_desc_pool_free(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  return dp_context_free_mem(a1, a3, *(_QWORD *)(a2 + 8), a4, a5, a6, a7, a8, a9, a10, a11);
}
