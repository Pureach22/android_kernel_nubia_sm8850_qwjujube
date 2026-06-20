__int64 __fastcall cam_csiphy_common_status_reg_dump(__int64 a1, char a2)
{
  __int64 *v2; // x8
  char *v3; // x23
  __int64 v5; // x25
  __int64 v6; // x22
  __int64 v7; // x24
  unsigned __int64 v8; // x26
  __int64 v9; // x19
  unsigned int v10; // w19
  int v11; // w8
  __int64 v12; // x27
  int v13; // w21
  char *v14; // x28
  __int64 v15; // x22
  char *v16; // x23
  __int64 v17; // x19
  unsigned int v18; // w24
  __int64 v20; // [xsp+8h] [xbp-8h]

  if ( a1 )
  {
    v2 = *(__int64 **)(a1 + 112);
    v3 = *(char **)(a1 + 1200);
    v5 = *v2;
    v6 = *(unsigned int *)(*v2 + 4);
    v7 = *(unsigned int *)(*v2 + 8);
    if ( (a2 & 1) != 0 )
    {
      if ( v3 )
      {
        v8 = *(unsigned int *)(v5 + 32);
        if ( !(_DWORD)v8 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x8000,
            1,
            "cam_csiphy_common_status_reg_dump",
            107,
            "Common status read buffer is NULL: %s, reg reads: %d",
            "N",
            0);
          return (unsigned int)-22;
        }
        v9 = a1;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x8000,
          3,
          "cam_csiphy_common_status_reg_dump",
          113,
          "PHY base addr=%pK offset=0x%x size=%d",
          v3,
          v6,
          *(_DWORD *)(v5 + 32));
        a1 = v9;
        goto LABEL_9;
      }
    }
    else if ( v3 )
    {
      v8 = 11;
LABEL_9:
      v11 = 0;
      v12 = 0;
      v13 = 0;
      v14 = &v3[v6];
      v15 = a1;
      v16 = &v3[v7];
      v20 = a1 + 4672;
      while ( 1 )
      {
        v17 = v11;
        v18 = cam_io_r(&v14[v11]);
        if ( (unsigned int)v13 < *(_DWORD *)(v5 + 28) )
        {
          cam_io_w_mb(v18, &v16[v17]);
          if ( (a2 & 1) == 0 )
          {
LABEL_13:
            if ( v13 <= 10 )
              goto LABEL_17;
            goto LABEL_10;
          }
        }
        else if ( (a2 & 1) == 0 )
        {
          goto LABEL_13;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x8000,
          3,
          "cam_csiphy_common_status_reg_dump",
          123,
          "CSIPHY%d_COMMON_STATUS%u = 0x%x",
          *(_DWORD *)(v15 + 932),
          v13,
          v18);
        if ( v13 <= 10 )
LABEL_17:
          *(_DWORD *)(v20 + 4 * v12) = v18;
LABEL_10:
        ++v13;
        v11 = v17 + 4;
        v12 = v13;
        if ( v8 <= v13 )
          return 0;
      }
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_common_status_reg_dump",
      101,
      "phy base is NULL  %s",
      "N");
    return (unsigned int)-22;
  }
  v10 = -22;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x8000,
    1,
    "cam_csiphy_common_status_reg_dump",
    88,
    "invalid input %d",
    -22);
  return v10;
}
