bool __fastcall msm_vidc_internal_buffer_count(__int64 a1, unsigned int a2)
{
  int v2; // w8
  unsigned int v5; // w8
  __int64 v7; // x0

  v2 = *(_DWORD *)(a1 + 308);
  if ( v2 == 2 )
  {
    if ( a2 == 11 || a2 == 13 )
      return 1;
    if ( (a2 & 0xFFFFFFF7) == 7 )
      return *(_DWORD *)(a1 + 312) != 32;
    if ( a2 - 9 > 1 )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        v7 = buf_name(a2);
        printk(&unk_86666, "err ", a1 + 340, "msm_vidc_internal_buffer_count", v7);
        return 0;
      }
    }
    else
    {
      v5 = *(_DWORD *)(a1 + 312);
      if ( v5 < 0x11 )
        return (0x10106u >> v5) & 1;
    }
    return 0;
  }
  if ( v2 != 1 )
    return 0;
  return *(_DWORD *)(a1 + 312) != 64 || (a2 & 0xFFFFFFFD) == 8;
}
