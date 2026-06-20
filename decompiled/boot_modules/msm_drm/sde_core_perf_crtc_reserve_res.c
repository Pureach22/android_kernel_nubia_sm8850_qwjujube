__int64 __fastcall sde_core_perf_crtc_reserve_res(__int64 result, unsigned __int64 a2)
{
  __int64 v2; // x8
  _QWORD *v3; // x19
  __int64 v4; // x8
  __int64 v5; // x8
  unsigned __int64 v6; // x9
  __int64 v7; // x8
  __int64 v8; // x1
  unsigned __int64 v9; // x2
  __int64 v10; // x0
  void *v11; // x0
  void *v12; // x0

  if ( !result )
  {
    v12 = &unk_25E167;
    return printk(v12, "sde_core_perf_crtc_reserve_res");
  }
  if ( !*(_QWORD *)result || (v2 = *(_QWORD *)(*(_QWORD *)result + 56LL)) == 0 )
  {
    v11 = &unk_231B33;
LABEL_20:
    printk(v11, "_sde_crtc_get_kms");
    goto LABEL_21;
  }
  v3 = *(_QWORD **)(v2 + 8);
  if ( !v3 )
  {
    v11 = &unk_234896;
    goto LABEL_20;
  }
  v4 = v3[17];
  if ( !v4 )
  {
LABEL_21:
    v12 = &unk_234896;
    return printk(v12, "sde_core_perf_crtc_reserve_res");
  }
  v5 = *(_QWORD *)(v4 + 56);
  if ( *(_DWORD *)(v5 + 5912) != 1 )
  {
    v6 = v3[263];
    v7 = v5 + 16;
    if ( v6 <= a2 )
      v6 = a2;
    v8 = v3[249];
    if ( v6 >= v3[252] )
      v9 = v3[252];
    else
      v9 = v6;
    if ( v3[265] )
      v10 = v3[265];
    else
      v10 = v7;
    v3[263] = v9;
    result = ((__int64 (__fastcall *)(__int64, __int64))sde_power_clk_reserve_rate)(v10, v8);
    if ( (_drm_debug & 4) != 0 )
      return _drm_dev_dbg(0, 0, 0, "reserve clk:%llu\n", v3[263]);
  }
  return result;
}
