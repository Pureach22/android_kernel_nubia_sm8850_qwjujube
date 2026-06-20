__int64 __fastcall msm_vidc_buffer_region_ext(__int64 a1, unsigned int a2)
{
  if ( !*(_QWORD *)(a1 + 21824) )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 320) + 6448LL) & 8) == 0 )
    {
      if ( a2 <= 0xF )
      {
        if ( ((1 << a2) & 0x2F18) != 0 )
          return 2;
        if ( ((1 << a2) & 0xD000) != 0 )
          return 8;
        if ( a2 == 7 )
          return 4;
      }
      if ( a2 == 2 )
      {
        if ( *(_DWORD *)(a1 + 308) == 1 )
          return 4;
        else
          return 8;
      }
      else
      {
        if ( a2 != 1 )
          goto LABEL_31;
        if ( *(_DWORD *)(a1 + 308) == 1 )
          return 8;
        else
          return 4;
      }
    }
    return 2;
  }
  if ( (int)a2 > 6 )
  {
    if ( a2 <= 0xF )
    {
      if ( ((1 << a2) & 0x2F00) != 0 )
        return 16;
      if ( ((1 << a2) & 0xD000) != 0 )
        return 64;
      if ( a2 == 7 )
        return 32;
    }
    goto LABEL_31;
  }
  if ( a2 - 3 < 2 )
    return 2;
  if ( a2 != 1 )
  {
    if ( a2 == 2 )
    {
      if ( *(_DWORD *)(a1 + 308) == 1 )
        return 32;
      else
        return 64;
    }
LABEL_31:
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_9780D, "err ", a1 + 340, "msm_vidc_buffer_region_ext", a2);
    }
    return 2;
  }
  if ( *(_DWORD *)(a1 + 308) == 1 )
    return 64;
  else
    return 32;
}
