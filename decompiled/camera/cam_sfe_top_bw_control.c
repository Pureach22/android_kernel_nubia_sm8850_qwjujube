__int64 __fastcall cam_sfe_top_bw_control(__int64 a1, _DWORD *a2, __int64 *a3)
{
  __int64 v3; // x20
  __int64 v4; // x21
  unsigned int v5; // w8
  unsigned int v6; // w6
  const char *v7; // x5
  __int64 v8; // x4
  __int64 v10; // x8
  __int64 v11; // x0

  v3 = *a3;
  if ( !*a3 )
    return 4294967274LL;
  v4 = *(_QWORD *)(*(_QWORD *)(v3 + 16) + 112LL);
  if ( !v4 )
    return 4294967274LL;
  v5 = *(_DWORD *)(v3 + 4);
  if ( *(_DWORD *)v3 != 10 || v5 >= 6 )
  {
    v7 = "SFE:%d Invalid res_type:%d res id%d";
    v8 = 623;
    goto LABEL_8;
  }
  v6 = a2[5874];
  if ( v6 > 6 )
  {
    v7 = "Invalid number of ports %d, max %d";
    v8 = 629;
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_top_bw_control",
      v8,
      v7);
    return 4294967274LL;
  }
  if ( v6 )
  {
    if ( a2[5647] == v5 )
    {
      v10 = 0;
LABEL_13:
      a2[v10 + 7896] = *((_DWORD *)a3 + 2);
      goto LABEL_15;
    }
    if ( v6 != 1 )
    {
      if ( a2[5685] == v5 )
      {
        v10 = 1;
        goto LABEL_13;
      }
      if ( v6 != 2 )
      {
        if ( a2[5723] == v5 )
        {
          v10 = 2;
          goto LABEL_13;
        }
        if ( v6 != 3 )
        {
          if ( a2[5761] == v5 )
          {
            v10 = 3;
            goto LABEL_13;
          }
          if ( v6 != 4 )
          {
            if ( a2[5799] == v5 )
            {
              v10 = 4;
              goto LABEL_13;
            }
            if ( v6 != 5 && a2[5837] == v5 )
            {
              v10 = 5;
              goto LABEL_13;
            }
          }
        }
      }
    }
  }
LABEL_15:
  if ( *(_DWORD *)(v4 + 92) == 1 )
    return cam_sfe_top_apply_bw_start_stop(a2);
  if ( (unsigned int)__ratelimit(&cam_sfe_top_bw_control__rs, "cam_sfe_top_bw_control") )
    v11 = 3;
  else
    v11 = 2;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    v11,
    0x40000000,
    1,
    "cam_sfe_top_bw_control",
    644,
    "SFE:%d Not ready to set BW yet :%d",
    *(_DWORD *)(*(_QWORD *)(v3 + 16) + 4LL),
    *(_DWORD *)(v4 + 92));
  return 0;
}
