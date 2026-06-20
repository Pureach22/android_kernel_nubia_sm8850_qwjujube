__int64 __fastcall get_tp_chip_id(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  char *v4; // x19
  __int64 v6; // x2

  v3 = tpd_cdev;
  printk(&unk_3806D, "get_tp_chip_id", a3);
  *(_BYTE *)(v3 + 1094) = -1;
  printk(&unk_3C91E, "get_tp_chip_id", "Unknown_lcd");
  v4 = &tp_ic_vendor_info_l;
  if ( !strnstr("Unknown_lcd", off_3E8, 11) )
  {
    v4 = &byte_3F0;
    if ( !strnstr("Unknown_lcd", off_3F8, 11) )
    {
      v4 = &byte_400;
      if ( !strnstr("Unknown_lcd", off_408, 11) )
      {
        v4 = &byte_410;
        if ( !strnstr("Unknown_lcd", off_418, 11) )
        {
          v4 = &byte_420;
          if ( !strnstr("Unknown_lcd", off_428, 11) )
          {
            v4 = &byte_430;
            if ( !strnstr("Unknown_lcd", off_438, 11) )
            {
              v4 = &byte_440;
              if ( !strnstr("Unknown_lcd", off_448, 11) )
              {
                v4 = &byte_450;
                if ( !strnstr("Unknown_lcd", off_458, 11) )
                {
                  v4 = &byte_460;
                  if ( !strnstr("Unknown_lcd", off_468, 11) )
                  {
                    v4 = &byte_470;
                    if ( !strnstr("Unknown_lcd", off_478, 11) )
                    {
                      v4 = &byte_480;
                      if ( !strnstr("Unknown_lcd", off_488, 11) )
                        return 4294967291LL;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  v6 = (unsigned __int8)*v4;
  *(_BYTE *)(v3 + 1094) = v6;
  printk(&unk_3746B, "get_tp_chip_id", v6);
  return 0;
}
