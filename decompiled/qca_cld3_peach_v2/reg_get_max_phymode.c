__int64 __fastcall reg_get_max_phymode(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 pdev_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w8
  const char *v23; // x2

  pdev_obj = reg_get_pdev_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !pdev_obj )
  {
    v23 = "%s: pdev reg component is NULL";
    goto LABEL_30;
  }
  v22 = *(_DWORD *)(pdev_obj + 56720);
  if ( v22 )
  {
    v23 = "%s: Couldn't find a suitable phymode";
    while ( 1 )
    {
      while ( (int)a2 > 4 )
      {
        switch ( a2 )
        {
          case 5u:
            if ( (v22 & 0x10) == 0 )
              return a2;
            goto LABEL_5;
          case 6u:
            if ( (v22 & 0x20) == 0 )
              return a2;
            goto LABEL_5;
          case 7u:
            if ( (v22 & 0x40) == 0 )
              return a2;
            goto LABEL_5;
        }
LABEL_26:
        if ( (a2 & 0xFFFFFFFD) == 1 )
          goto LABEL_30;
        if ( a2 > 8 )
        {
          v23 = "%s: Unknown phymode";
          goto LABEL_30;
        }
LABEL_5:
        --a2;
      }
      if ( (int)a2 <= 2 )
      {
        if ( a2 == 2 )
        {
          if ( (v22 & 4) == 0 )
            return a2;
          goto LABEL_5;
        }
        if ( a2 == 1 )
        {
          if ( (v22 & 2) == 0 )
            return 1;
          goto LABEL_36;
        }
        goto LABEL_26;
      }
      if ( a2 != 4 )
      {
        if ( (v22 & 1) == 0 )
          return 3;
LABEL_36:
        v23 = "%s: Couldn't find a suitable phymode";
LABEL_30:
        qdf_trace_msg(0x51u, 2u, v23, v14, v15, v16, v17, v18, v19, v20, v21, "reg_get_max_phymode");
        return 0;
      }
      if ( (v22 & 8) == 0 )
        return a2;
      if ( *(_DWORD *)channel_map <= a3 )
      {
        a2 = 2;
        if ( *(_DWORD *)(channel_map + 156) >= a3 )
          continue;
      }
      a2 = 3;
    }
  }
  return a2;
}
