__int64 __fastcall hfi_buf_type_from_driver(int a1, int a2)
{
  if ( a2 > 9 )
  {
    if ( a2 <= 12 )
    {
      if ( a2 == 10 )
        return 11;
      if ( a2 == 11 )
        return 8;
      return 6;
    }
    switch ( a2 )
    {
      case 13:
        return 12;
      case 14:
        return 13;
      case 15:
        return 5;
    }
  }
  else
  {
    if ( a2 > 6 )
    {
      if ( a2 == 7 )
        return 7;
      if ( a2 == 8 )
        return 9;
      return 10;
    }
    if ( (unsigned int)(a2 - 3) < 2 )
      return 3;
    if ( a2 == 1 )
    {
      if ( a1 == 2 )
        return 1;
      else
        return 2;
    }
    if ( a2 == 2 )
    {
      if ( a1 == 2 )
        return 2;
      else
        return 1;
    }
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_94430, "err ", 0xFFFFFFFFLL, "codec", (unsigned int)a2);
  return 0;
}
