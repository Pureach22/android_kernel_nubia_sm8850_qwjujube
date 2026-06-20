__int64 __fastcall cam_vfe_top_apply_bw_start_stop(__int64 a1)
{
  int v2; // w0
  unsigned int v3; // w20
  __int64 v4; // x22
  __int64 v5; // x21
  unsigned int v6; // w8
  const char *v7; // x8
  __int64 v9; // [xsp+10h] [xbp-20h] BYREF
  __int64 v10; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v11[2]; // [xsp+20h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  v9 = 0;
  v10 = 0;
  v2 = cam_vfe_top_calc_axi_bw_vote(a1, 1, &v9, v11, &v10, 0);
  if ( v2 )
  {
    v3 = v2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_apply_bw_start_stop",
      774,
      "VFE:%d Failed in calculating bw vote rc=%d",
      *(_DWORD *)(a1 + 1068),
      v2);
  }
  else if ( *(_DWORD *)(a1 + 10372) == 1 )
  {
    v3 = 0;
  }
  else
  {
    v4 = v10;
    v5 = v11[0];
    v3 = cam_vfe_top_set_axi_bw_vote(a1, v9, v11[0], v10, 1, 0);
    if ( v3 )
    {
      v6 = *(_DWORD *)(a1 + 10372) - 1;
      if ( v6 > 2 )
        v7 = "Invalid State";
      else
        v7 = off_44EBB0[v6];
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_apply_bw_start_stop",
        787,
        "VFE:%d Failed in voting final bw camnoc:%llu mnoc:%llu bw_state:%s",
        *(_DWORD *)(a1 + 1068),
        v5,
        v4,
        v7);
    }
  }
  *(_DWORD *)(a1 + 10372) = 0;
  _ReadStatusReg(SP_EL0);
  return v3;
}
