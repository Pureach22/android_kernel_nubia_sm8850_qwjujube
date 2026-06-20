__int64 __fastcall msm_vidc_allow_property(__int64 result, int a2)
{
  if ( a2 == 50332055 )
    return *(_DWORD *)(result + 312) == 16;
  if ( a2 != 50332043 )
  {
    if ( a2 == 50332039 )
      return *(_DWORD *)(result + 312) == 16;
    return 1;
  }
  if ( (*(_BYTE *)(result + 5544) & 0x80) != 0 && (~*(_DWORD *)(result + 5528) & 9LL) == 0 )
    return 1;
  if ( result )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_85904, "high", result + 340, "msm_vidc_allow_property", "META_OUTPUT_TX_FENCE");
    return 0;
  }
  return result;
}
