__int64 __fastcall cam_sfe_bus_config_rdi_wm(unsigned int *a1)
{
  int v1; // w6
  unsigned int v2; // w8
  unsigned int v3; // w9
  __int64 v4; // x6
  __int64 v5; // x4
  unsigned int v6; // w9
  unsigned int v7; // w8
  unsigned int v8; // w8
  unsigned int v9; // w9
  unsigned int v10; // w8
  unsigned int v11; // w8
  unsigned int v12; // w8
  unsigned int v13; // w8
  unsigned int *v14; // x19
  unsigned int *v15; // x19
  unsigned int *v16; // x19

  v1 = a1[16];
  a1[17] = 0;
  if ( v1 > 13 )
  {
    if ( v1 < 18 )
    {
      v2 = a1[18];
      if ( v2 == 1 )
        goto LABEL_54;
      if ( v2 )
      {
        v4 = *a1;
        v5 = 643;
        goto LABEL_35;
      }
      goto LABEL_12;
    }
    switch ( v1 )
    {
      case 18:
        v2 = a1[18];
        if ( v2 == 1 )
          goto LABEL_54;
        if ( !v2 )
        {
          v3 = 4 * a1[13];
          goto LABEL_13;
        }
        v4 = *a1;
        v5 = 617;
        break;
      case 19:
        v2 = a1[18];
        if ( v2 == 1 )
          goto LABEL_54;
        if ( !v2 )
        {
          v3 = 8 * a1[13];
          goto LABEL_13;
        }
        v4 = *a1;
        v5 = 655;
        break;
      case 20:
        v2 = a1[18];
        if ( v2 == 1 )
          goto LABEL_54;
        if ( !v2 )
        {
          v6 = a1[13];
          a1[24] = 1;
          a1[13] = v6 & 0xFFFFFFF;
          return v2;
        }
        v4 = *a1;
        v5 = 605;
        break;
      default:
        goto LABEL_55;
    }
LABEL_35:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x40000000,
      2,
      "cam_sfe_bus_config_rdi_wm",
      v5,
      "No index mode support for SFE WM: %u",
      v4);
    return 0;
  }
  if ( v1 > 4 )
  {
    if ( v1 <= 6 )
    {
      if ( v1 == 5 )
      {
        v10 = a1[18];
        if ( v10 == 1 )
        {
          *(_QWORD *)(a1 + 13) = 0xFFFF;
          a1[15] = 0xFFFF;
          a1[24] = 65537;
        }
        else if ( v10 )
        {
          v15 = a1;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x40000000,
            2,
            "cam_sfe_bus_config_rdi_wm",
            564,
            "No index mode support for SFE WM: %u",
            *a1);
          a1 = v15;
        }
        else
        {
          v11 = (7 * a1[13]) >> 1;
          a1[24] = 1;
          a1[13] = (v11 + 15) >> 4;
        }
        if ( *((_BYTE *)a1 + 123) == 1 )
        {
          v2 = a1[18];
          a1[17] = 14;
          if ( !v2 )
            goto LABEL_76;
        }
        return 0;
      }
      v2 = a1[18];
      if ( v2 == 1 )
        goto LABEL_54;
      if ( v2 )
      {
        v4 = *a1;
        v5 = 581;
        goto LABEL_35;
      }
LABEL_12:
      v3 = 2 * a1[13];
      goto LABEL_13;
    }
    if ( v1 == 7 )
    {
      v2 = a1[18];
      if ( v2 == 1 )
        goto LABEL_54;
      if ( !v2 )
      {
        v3 = (5 * a1[13]) >> 1;
        goto LABEL_13;
      }
      v4 = *a1;
      v5 = 593;
    }
    else
    {
      if ( v1 != 12 )
        goto LABEL_55;
      v2 = a1[18];
      if ( v2 == 1 )
        goto LABEL_54;
      if ( !v2 )
      {
        v9 = a1[13];
        a1[24] = 1;
        a1[15] = 2 * v9;
        return v2;
      }
      v4 = *a1;
      v5 = 628;
    }
    goto LABEL_35;
  }
  if ( v1 > 2 )
  {
    if ( v1 == 3 )
    {
      v12 = a1[18];
      if ( v12 == 1 )
      {
        *(_QWORD *)(a1 + 13) = 0xFFFF;
        a1[15] = 0xFFFF;
        a1[24] = 65537;
      }
      else if ( v12 )
      {
        v16 = a1;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          2,
          "cam_sfe_bus_config_rdi_wm",
          504,
          "No index mode support for SFE WM: %u",
          *a1);
        a1 = v16;
      }
      else
      {
        v13 = a1[13];
        a1[24] = 1;
        a1[13] = (((5 * v13) >> 2) + 15) >> 4;
      }
      if ( *((_BYTE *)a1 + 123) == 1 )
      {
        v2 = a1[18];
        a1[17] = 12;
        if ( !v2 )
          goto LABEL_76;
      }
    }
    else
    {
      v7 = a1[18];
      if ( v7 == 1 )
      {
        *(_QWORD *)(a1 + 13) = 0xFFFF;
        a1[15] = 0xFFFF;
        a1[24] = 65537;
      }
      else if ( v7 )
      {
        v14 = a1;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          2,
          "cam_sfe_bus_config_rdi_wm",
          546,
          "No index mode support for SFE WM: %u",
          *a1);
        a1 = v14;
      }
      else
      {
        v8 = a1[13];
        a1[24] = 1;
        a1[13] = (((3 * v8) >> 1) + 15) >> 4;
      }
      if ( *((_BYTE *)a1 + 123) == 1 )
      {
        v2 = a1[18];
        a1[17] = 13;
        if ( !v2 )
        {
LABEL_76:
          a1[13] = (a1[26] + 7) & 0xFFFFFFF8;
          return v2;
        }
      }
    }
    return 0;
  }
  if ( v1 == 1 )
  {
    v2 = a1[18];
    if ( v2 == 1 )
      goto LABEL_54;
    if ( !v2 )
    {
      v3 = (3 * a1[13]) >> 2;
      goto LABEL_13;
    }
    v4 = *a1;
    v5 = 522;
    goto LABEL_35;
  }
  if ( v1 != 2 )
  {
LABEL_55:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_config_rdi_wm",
      660,
      "Unsupported RDI format %d",
      v1);
    return (unsigned int)-22;
  }
  v2 = a1[18];
  if ( v2 == 1 )
  {
LABEL_54:
    v2 = 0;
    *(_QWORD *)(a1 + 13) = 0xFFFF;
    a1[15] = 0xFFFF;
    a1[24] = 65537;
    return v2;
  }
  if ( v2 )
  {
    v4 = *a1;
    v5 = 534;
    goto LABEL_35;
  }
  v3 = a1[13];
LABEL_13:
  a1[24] = 1;
  a1[13] = (v3 + 15) >> 4;
  return v2;
}
