__int64 __fastcall sde_hw_rc_program_enable_bits(__int64 a1, __int64 *a2, int a3, int a4, int a5, int a6, __int64 a7)
{
  __int64 v11; // x8
  __int64 *v12; // x20
  char *v13; // x10
  int v14; // w22
  unsigned int v15; // w28
  __int64 v16; // x24
  unsigned int v17; // w11
  unsigned int v18; // w10
  __int64 v19; // x25
  __int64 v20; // x23
  __int64 v21; // x8
  __int64 v22; // x9
  _BOOL4 v23; // w12
  _BOOL4 v24; // w13
  bool v25; // zf
  int v26; // w15
  int v27; // w16
  bool v28; // w14
  int v29; // w7
  unsigned int v30; // w12
  size_t v31; // x0
  int v32; // w2
  int v33; // w4
  int v34; // w5
  unsigned int v35; // w21
  _BOOL4 v36; // w27
  __int64 v37; // x8
  unsigned int v38; // w23
  __int64 v39; // x8
  unsigned int v40; // w22
  __int64 v41; // x8
  unsigned int v42; // w21
  int v44; // [xsp+38h] [xbp-8h]

  if ( !a7 )
  {
    printk(&unk_26FEB0, "_sde_hw_rc_program_enable_bits");
    return 4294967274LL;
  }
  v11 = 0;
  v12 = a2 + 2560;
  while ( 1 )
  {
    if ( *(_DWORD *)((char *)&config_table_0 + v11 + 12) == a6 && *(_DWORD *)((char *)&config_table_0 + v11) == a3 )
    {
      v13 = (char *)&config_table_0 + v11;
      if ( *(_DWORD *)((char *)&config_table_0 + v11 + 4) == a4 )
        break;
    }
    v11 += 20;
    if ( v11 == 480 )
    {
      _drm_err("configuration not supported");
      printk(&unk_269FC7, "_sde_hw_rc_program_enable_bits");
      return 4294967274LL;
    }
  }
  v14 = *((_DWORD *)v13 + 2);
  v15 = *((_DWORD *)v13 + 4);
  _drm_dev_dbg(0, 0, 0, "found param_c:0x%08X, merge_mode_en:%d\n", v14, v15);
  v16 = *a2;
  v17 = a5 & 0xFFFFFFFE;
  v18 = a5 & 0xFFFFFFFD;
  v19 = *((unsigned int *)v12 + 343);
  v20 = *((unsigned int *)v12 + 342);
  v21 = *a2 & 0x1E0;
  v22 = *a2 & 0x1E;
  v23 = v21 != 480;
  v24 = (a5 & 0xFFFFFFFE) == 2;
  v25 = (a5 & 0xFFFFFFFD) != 1 || v22 == 30;
  v26 = !v25;
  if ( v25 )
    v27 = 16;
  else
    v27 = 17;
  v28 = v24 && v23;
  if ( !v24 || !v23 )
    v27 = v26;
  if ( v26 )
  {
    v29 = *(unsigned __int16 *)(a7 + 2);
    v30 = *(unsigned __int16 *)(a7 + 6);
    if ( *(_WORD *)(a7 + 2) || *((_DWORD *)a2 + 2) > v30 )
    {
      v31 = sde_dbg_base_evtlog;
      v32 = 78;
      v33 = 4369;
      v34 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 536LL);
LABEL_38:
      sde_evtlog_log(v31, "_sde_hw_rc_program_enable_bits", v32, -1, v33, v34, 1, v29, v30);
      return 4294967274LL;
    }
  }
  v35 = *(unsigned __int16 *)(a7 + 2);
  if ( v28 )
  {
    v30 = *(unsigned __int16 *)(a7 + 6);
    if ( v30 + v35 != (_DWORD)v20 || *((_DWORD *)a2 + 3) < v35 )
    {
      v31 = sde_dbg_base_evtlog;
      v32 = 86;
      v33 = 8738;
      v29 = *(unsigned __int16 *)(a7 + 2);
      v34 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 536LL);
      goto LABEL_38;
    }
  }
  v44 = v27;
  if ( (_drm_debug & 4) != 0 )
  {
    v36 = v22 != 30;
    _drm_dev_dbg(
      0,
      0,
      0,
      "idx:%d w:%llu h:%lld flags:%llx, R1:%d, R2:%d, PU R1:%d, PU R2:%d, Y_START:%d\n",
      *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 536LL),
      v19,
      v20,
      v16,
      v36,
      v21 != 480,
      v18 == 1,
      v17 == 2,
      v35);
  }
  else
  {
    LOBYTE(v36) = v22 != 30;
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "_sde_hw_rc_program_enable_bits",
    96,
    -1,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 536LL),
    v19,
    v20,
    v16,
    v36);
  v37 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL);
  v38 = *(_DWORD *)(v37 + 524) + 4;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "rc:%u, address:0x%08X, value:0x%08X\n",
      *(_DWORD *)(v37 + 536),
      *(_DWORD *)(a1 + 8) + v38,
      v44 | v14);
  sde_reg_write(a1, v38, v44 | v14, "address");
  v39 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL);
  v40 = *(_DWORD *)(v39 + 524) + 52;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "rc:%u, address:0x%08X, value:0x%08X\n",
      *(_DWORD *)(v39 + 536),
      *(_DWORD *)(a1 + 8) + v40,
      v35);
  sde_reg_write(a1, v40, v35, "address");
  v41 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL);
  v42 = *(_DWORD *)(v41 + 524) + 36;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "rc:%u, address:0x%08X, value:0x%08X\n",
      *(_DWORD *)(v41 + 536),
      *(_DWORD *)(a1 + 8) + v42,
      v15);
  sde_reg_write(a1, v42, v15, "address");
  return 0;
}
