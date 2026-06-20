__int64 __fastcall get_hfi_colorformat(__int64 a1, int a2)
{
  if ( a2 <= 15 )
  {
    if ( a2 > 3 )
    {
      if ( a2 == 4 )
        return 7;
      if ( a2 == 8 )
        return 4;
    }
    else
    {
      if ( a2 == 1 )
        return 2;
      if ( a2 == 2 )
        return 1;
    }
  }
  else if ( a2 <= 63 )
  {
    if ( a2 == 16 )
      return 3;
    if ( a2 == 32 )
      return 6;
  }
  else
  {
    switch ( a2 )
    {
      case 64:
        return 5;
      case 128:
        return 11;
      case 256:
        return 10;
    }
  }
  if ( !a1 || (msm_vidc_debug & 1) == 0 )
    return 2;
  printk(&unk_8ED78, "err ", a1 + 340, "get_hfi_colorformat", (unsigned int)a2);
  return 2;
}
