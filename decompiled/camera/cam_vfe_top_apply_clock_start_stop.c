__int64 __fastcall cam_vfe_top_apply_clock_start_stop(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  int v7; // w0
  unsigned int v8; // w20
  unsigned __int64 v9; // x21
  unsigned int v10; // w8
  const char *v11; // x8
  unsigned __int64 v13[2]; // [xsp+10h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0;
  v7 = cam_vfe_top_calc_hw_clk_rate(a1, 1, v13, 0, a5, a6);
  if ( v7 )
  {
    v8 = v7;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_apply_clock_start_stop",
      743,
      "VFE:%d Failed in calculating clock rate rc=%d",
      *(_DWORD *)(a1 + 1068),
      v7);
  }
  else if ( *(_DWORD *)(a1 + 10368) == 1 )
  {
    v8 = 0;
  }
  else
  {
    v9 = v13[0];
    v8 = cam_vfe_top_set_hw_clk_rate(a1, v13[0], 1, 0);
    if ( v8 )
    {
      v10 = *(_DWORD *)(a1 + 10368) - 1;
      if ( v10 > 2 )
        v11 = "Invalid State";
      else
        v11 = off_44EBB0[v10];
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_apply_clock_start_stop",
        754,
        "VFE:%d Failed in voting final clk:%lu clk_state:%s",
        *(_DWORD *)(a1 + 1068),
        v9,
        v11);
    }
  }
  *(_DWORD *)(a1 + 10368) = 0;
  *(_BYTE *)(a1 + 10480) = 0;
  _ReadStatusReg(SP_EL0);
  return v8;
}
