__int64 __fastcall msm_vidc_buffer_region(__int64 a1, unsigned int a2)
{
  if ( a2 > 0xF )
    goto LABEL_10;
  if ( ((1 << a2) & 0x2F98) != 0 )
    return 2;
  if ( ((1 << a2) & 0xD000) != 0 )
    return 8;
  if ( a2 == 2 )
  {
    if ( *(_DWORD *)(a1 + 308) == 1 )
      return 4;
    else
      return 8;
  }
  else
  {
LABEL_10:
    if ( a2 == 1 )
    {
      if ( *(_DWORD *)(a1 + 308) == 1 )
        return 8;
      else
        return 4;
    }
    else
    {
      if ( !a1 || (msm_vidc_debug & 1) == 0 )
        return 2;
      printk(&unk_9780D, "err ", a1 + 340, "msm_vidc_buffer_region", a2);
      return 2;
    }
  }
}
