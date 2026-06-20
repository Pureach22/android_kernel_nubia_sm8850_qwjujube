__int64 __fastcall gmu_core_rdpm_cx_freq_update(__int64 result, unsigned int a2)
{
  __int64 v2; // x9

  v2 = *(_QWORD *)(result + 8288);
  if ( v2 )
  {
    result = writel_relaxed_0(a2 / 0x3E8, (unsigned int *)(v2 + *(unsigned int *)(result + 8304)));
    __dsb(0xEu);
  }
  return result;
}
