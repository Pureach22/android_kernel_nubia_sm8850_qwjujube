__int64 __fastcall hal_cmem_write_peach(__int64 a1, __int64 a2, __int64 a3)
{
  return hal_write32_mb_1(a1, a2, a3);
}
