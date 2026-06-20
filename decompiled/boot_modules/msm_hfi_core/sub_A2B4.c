__int64 __fastcall sub_A2B4(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, int a7)
{
  if ( (a7 & 0x1000000) == 0 )
    JUMPOUT(0xDC88);
  return smmu_mmap_for_fw();
}
