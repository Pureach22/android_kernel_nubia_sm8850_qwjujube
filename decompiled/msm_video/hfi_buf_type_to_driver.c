__int64 __fastcall hfi_buf_type_to_driver(int a1, int a2, int a3)
{
  if ( a2 > 7 )
  {
    if ( a2 <= 10 )
    {
      if ( a2 == 8 )
        return 11;
      if ( a2 == 9 )
        return 8;
      return 9;
    }
    switch ( a2 )
    {
      case 11:
        return 10;
      case 12:
        return 13;
      case 13:
        return 14;
    }
  }
  else
  {
    if ( a2 > 4 )
    {
      if ( a2 == 5 )
        return 15;
      if ( a2 == 6 )
        return 12;
      return 7;
    }
    switch ( a2 )
    {
      case 1:
        if ( a1 == 2 )
          return 1;
        else
          return 2;
      case 2:
        if ( a1 == 2 )
          return 2;
        else
          return 1;
      case 3:
        if ( a1 == 2 )
        {
          if ( a3 == 1 )
            return 3;
          else
            return 4;
        }
        else if ( a3 == 1 )
        {
          return 4;
        }
        else
        {
          return 3;
        }
    }
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_94430, "err ", 0xFFFFFFFFLL, "codec", (unsigned int)a2);
  return 0;
}
