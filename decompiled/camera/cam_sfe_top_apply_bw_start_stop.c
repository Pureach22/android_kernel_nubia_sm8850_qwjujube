__int64 __fastcall cam_sfe_top_apply_bw_start_stop(__int64 a1)
{
  int v2; // w0
  unsigned int v3; // w20
  unsigned __int64 v4; // x21
  unsigned int v5; // w8
  const char *v6; // x8
  unsigned int *v8; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int64 v9[2]; // [xsp+10h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = nullptr;
  v9[0] = 0;
  v2 = cam_sfe_top_calc_axi_bw_vote(a1, 1, &v8, v9, 0);
  if ( v2 )
  {
    v3 = v2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_top_apply_bw_start_stop",
      1130,
      "SFE:%d Failed in calculating bw vote rc=%d",
      *(_DWORD *)(*(_QWORD *)(a1 + 8) + 4LL),
      v2);
  }
  else if ( *(_DWORD *)(a1 + 31580) == 1 )
  {
    v3 = 0;
  }
  else
  {
    v4 = v9[0];
    v3 = cam_sfe_top_set_axi_bw_vote(a1, v8, v9[0], 1, 0);
    if ( v3 )
    {
      v5 = *(_DWORD *)(a1 + 31580) - 1;
      if ( v5 > 2 )
        v6 = "Invalid State";
      else
        v6 = off_44E3E8[v5];
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_top_apply_bw_start_stop",
        1142,
        "SFE:%d Failed in voting final bw:%llu bw_state:%s",
        *(_DWORD *)(*(_QWORD *)(a1 + 8) + 4LL),
        v4,
        v6);
    }
  }
  *(_DWORD *)(a1 + 31580) = 0;
  _ReadStatusReg(SP_EL0);
  return v3;
}
