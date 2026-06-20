__int64 __fastcall sde_crtc_calc_vpadding_param(_DWORD *a1, unsigned int a2, int a3, int *a4, _DWORD *a5, _DWORD *a6)
{
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x8
  unsigned int v10; // w9
  unsigned int v13; // w13
  int v14; // w6
  int v15; // w7
  int v16; // w10
  void *v17; // x0
  int v20; // w4
  void *v22; // x0

  if ( !*(_QWORD *)a1 || (v6 = **(_QWORD **)a1) == 0 || (v7 = *(_QWORD *)(v6 + 56)) == 0 )
  {
    v17 = &unk_25E167;
LABEL_19:
    printk(v17, "_sde_crtc_get_kms");
    goto LABEL_20;
  }
  v8 = *(_QWORD *)(v7 + 8);
  if ( !v8 )
  {
    v17 = &unk_234896;
    goto LABEL_19;
  }
  v9 = *(_QWORD *)(v8 + 152);
  if ( !v9 )
  {
LABEL_20:
    v22 = &unk_2655E0;
    goto LABEL_21;
  }
  if ( *(_BYTE *)(v9 + 22016) != 1 )
    return 0;
  v10 = a1[1728];
  if ( v10 )
  {
    v13 = a1[1729] + v10;
    v14 = a2 % v10 + a2 / v10 * v13;
    *a4 = v14;
    v15 = (a2 + a3 - 1) % v10 + (a2 + a3 - 1) / v10 * v13;
    *a5 = v10 - a2 % v10;
    *a6 = v15 - v14 + 1;
    if ( *(_QWORD *)a1 )
      v16 = *(_DWORD *)(*(_QWORD *)a1 + 112LL);
    else
      v16 = -1;
    sde_evtlog_log(sde_dbg_base_evtlog, "sde_crtc_calc_vpadding_param", 9889, -1, v16, a2 % v10, v14, v15, *a4);
    if ( (_drm_debug & 4) != 0 )
    {
      if ( *(_QWORD *)a1 )
        v20 = *(_DWORD *)(*(_QWORD *)a1 + 112LL);
      else
        v20 = -1;
      _drm_dev_dbg(0, 0, 0, "crtc:%d padding_y:%d padding_start:%d padding_height:%d\n", v20, *a4, *a5, *a6);
    }
    return 0;
  }
  v22 = &unk_234B12;
LABEL_21:
  printk(v22, "sde_crtc_calc_vpadding_param");
  return 4294967274LL;
}
