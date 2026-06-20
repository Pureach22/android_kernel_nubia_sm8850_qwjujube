__int64 __fastcall cam_sfe_top_bw_update(__int64 a1, _DWORD *a2, int **a3)
{
  int *v3; // x8
  __int64 v4; // x9
  int v5; // w7
  unsigned int v6; // w8
  unsigned int v7; // w6
  const char *v8; // x5
  __int64 v9; // x4
  __int64 v11; // x19

  v3 = *a3;
  if ( !*a3 )
    return 4294967274LL;
  v4 = *((_QWORD *)v3 + 2);
  if ( !v4 || !*(_QWORD *)(v4 + 112) )
    return 4294967274LL;
  v5 = *v3;
  v6 = v3[1];
  if ( v5 != 10 || v6 >= 6 )
  {
    v8 = "SFE:%d Invalid res_type:%d res id%d";
    v9 = 577;
    goto LABEL_10;
  }
  v7 = a2[5874];
  if ( v7 > 6 )
  {
    v8 = "Invalid number of ports %d, max %d";
    v9 = 583;
LABEL_10:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_top_bw_update",
      v9,
      v8);
    return 4294967274LL;
  }
  if ( v7 )
  {
    if ( a2[5647] == v6 )
    {
      v11 = 0;
LABEL_15:
      memcpy(&a2[152 * (unsigned int)v11 + 6046], a3 + 1, 0x260u);
      a2[v11 + 7896] = 1;
      return 0;
    }
    if ( v7 != 1 )
    {
      if ( a2[5685] == v6 )
      {
        v11 = 1;
        goto LABEL_15;
      }
      if ( v7 != 2 )
      {
        if ( a2[5723] == v6 )
        {
          v11 = 2;
          goto LABEL_15;
        }
        if ( v7 != 3 )
        {
          if ( a2[5761] == v6 )
          {
            v11 = 3;
            goto LABEL_15;
          }
          if ( v7 != 4 )
          {
            if ( a2[5799] == v6 )
            {
              v11 = 4;
              goto LABEL_15;
            }
            if ( v7 != 5 && a2[5837] == v6 )
            {
              v11 = 5;
              goto LABEL_15;
            }
          }
        }
      }
    }
  }
  return 0;
}
