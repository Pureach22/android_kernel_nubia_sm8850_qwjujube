__int64 __fastcall sub_E5C4(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  return mem_buf_dma_buf_export(a1, a2, a3, a4 & 0xFFFFFFFFFFFF0000LL | 0xE2EB);
}
