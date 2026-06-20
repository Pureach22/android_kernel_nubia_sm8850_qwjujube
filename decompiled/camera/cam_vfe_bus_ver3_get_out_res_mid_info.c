__int64 __fastcall cam_vfe_bus_ver3_get_out_res_mid_info(__int64 a1, int *a2)
{
  __int64 v2; // x20
  int v4; // w9
  __int64 v5; // x8
  int v6; // w11
  int v7; // w21
  unsigned __int64 *v8; // x13
  unsigned __int64 v9; // x11
  int v10; // w12
  unsigned __int64 v11; // x13
  int v12; // w7
  int v13; // w14
  __int64 result; // x0
  int v15; // w8

  v2 = a1 + 0x8000;
  v4 = *(_DWORD *)(a1 + 34732);
  if ( v4 )
  {
    v5 = *(_QWORD *)(a1 + 34760);
    v6 = 0;
    while ( 1 )
    {
      v7 = v6;
      v8 = *(unsigned __int64 **)(v5 + 152LL * v6 + 24);
      if ( v8 )
      {
        v9 = *v8;
        if ( !*v8 || ((v9 >> a2[2]) & 1) != 0 )
        {
          v10 = *((_DWORD *)v8 + 28);
          if ( v10 )
            break;
        }
      }
LABEL_3:
      v6 = v7 + 1;
      if ( v7 + 1 == v4 )
        goto LABEL_13;
    }
    v11 = v8[13];
    v12 = *a2;
    v13 = 0;
    while ( *(_DWORD *)(v11 + 4LL * v13) != v12 )
    {
      if ( v10 == ++v13 )
        goto LABEL_3;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_bus_ver3_get_out_res_mid_info",
      5380,
      "VFE:%u match mid :%d  PID:%d pid_mask 0x%lx, out resource:0x%x found",
      *(_DWORD *)(a1 + 8),
      v12,
      a2[2],
      v9,
      *(_DWORD *)(v5 + 152LL * v7 + 4));
    result = 0;
    v15 = *(_DWORD *)(*(_QWORD *)(v2 + 1992) + 152LL * v7 + 4);
  }
  else
  {
LABEL_13:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_get_out_res_mid_info",
      5372,
      "VFE:%u mid:%d does not match with any out resource",
      *(_DWORD *)(a1 + 8),
      *a2);
    v15 = 0;
    result = 4294967274LL;
  }
  a2[1] = v15;
  return result;
}
