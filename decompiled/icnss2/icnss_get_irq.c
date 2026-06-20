__int64 __fastcall icnss_get_irq(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 v4; // x0

  if ( !penv )
    return 4294967277LL;
  result = 4294967277LL;
  if ( a1 && *(_QWORD *)(penv + 8) )
  {
    if ( a2 <= 11 )
    {
      if ( (unsigned int)a2 >= 0xC )
      {
        __break(0x5512u);
        v4 = MEMORY[0x4F269B0](4294967277LL);
        return icnss_get_audio_shared_iommu_group_cap(v4);
      }
      else
      {
        return *(unsigned int *)(penv + 4LL * (unsigned int)a2 + 348);
      }
    }
    else
    {
      return 4294967274LL;
    }
  }
  return result;
}
