__int64 __fastcall mem_buf_vmperm_alloc_staticvm(
        __int64 a1,
        void *a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6)
{
  return mem_buf_vmperm_alloc_flags(a1, 1, a2, a3, a4, a5, a6, 0xFFFFFFFF);
}
