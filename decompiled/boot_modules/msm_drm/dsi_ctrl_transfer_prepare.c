__int64 __fastcall dsi_ctrl_transfer_prepare(__int64 a1, char a2)
{
  __int64 v5; // x20
  unsigned int v6; // w0
  __int64 (__fastcall *v7)(__int64, __int64, __int64); // x8
  __int64 v8; // x0
  unsigned int v9; // w0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x5
  int v15; // w6
  int v16; // w7
  unsigned int v17; // w20
  unsigned int v18; // w9
  unsigned int v25; // w11
  const char *v26; // x3
  unsigned int v27; // w19
  int v28; // w7
  __int64 v29; // x8
  __int64 v30; // x9
  void (__fastcall *v31)(__int64, __int64, __int64); // x8
  __int64 v32; // x8
  void (__fastcall *v33)(__int64, __int64); // x8
  int v34; // w0
  void (__fastcall *v35)(__int64, __int64, __int64); // x8
  __int64 v36; // x0
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return 4294967274LL;
  if ( (a2 & 0x20) != 0 && *(_DWORD *)(a1 + 2784) )
    return 0;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dsi_ctrl_transfer_prepare",
    3633,
    -1,
    4369,
    *(_DWORD *)(a1 + 8),
    a2,
    -1059143953,
    vars0);
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 80) + 8LL);
  v6 = _pm_runtime_resume(v5, 4);
  if ( (v6 & 0x80000000) == 0 )
  {
    v7 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 + 1640);
    v8 = *(_QWORD *)(a1 + 1632);
    if ( *((_DWORD *)v7 - 1) != 1407241817 )
      __break(0x8228u);
    v9 = v7(v8, 0x100000003LL, 1);
    if ( v9 )
    {
      v17 = v9;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: failed to enable clocks\n",
        *(const char **)(a1 + 16));
LABEL_38:
      _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(a1 + 80) + 8LL), 4);
      return v17;
    }
    if ( *(_BYTE *)(a1 + 2848) == 1 )
      dsi_ctrl_flush_cmd_dma_queue(a1, v10, v11, v12, v13, v14, v15, v16);
    mutex_lock(a1 + 32);
    if ( (a2 & 1) == 0 )
    {
      v29 = *(unsigned int *)(a1 + 1608);
      if ( (unsigned int)v29 >= 3 )
        goto LABEL_41;
      v30 = a1 + 8 * v29;
      if ( *(_QWORD *)(v30 + 1272) && *(_QWORD *)(a1 + 912 + 8 * v29) )
      {
        v31 = *(void (__fastcall **)(__int64, __int64, __int64))(v30 + 1248);
        if ( *((_DWORD *)v31 - 1) != -640374085 )
          __break(0x8228u);
        v31(a1 + 96, 2, 1);
        v32 = *(unsigned int *)(a1 + 1608);
        if ( (unsigned int)v32 <= 2 )
        {
          v33 = *(void (__fastcall **)(__int64, __int64))(a1 + 912 + 8 * v32);
          if ( *((_DWORD *)v33 - 1) != 2055766805 )
            __break(0x8228u);
          v33(a1 + 96, 32);
          goto LABEL_34;
        }
LABEL_41:
        __break(0x5512u);
        JUMPOUT(0x1D3DC4);
      }
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", *(const char **)(a1 + 16));
    }
LABEL_34:
    v34 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))dsi_ctrl_set_cmd_engine_state)(a1, 1, 0);
    if ( !v34 )
    {
      mutex_unlock(a1 + 32);
      return 0;
    }
    v17 = v34;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: failed to enable command engine: %d\n",
      *(const char **)(a1 + 16),
      v34);
    mutex_unlock(a1 + 32);
    v35 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 1640);
    v36 = *(_QWORD *)(a1 + 1632);
    if ( *((_DWORD *)v35 - 1) != 1407241817 )
      __break(0x8228u);
    v35(v36, 3, 1);
    goto LABEL_38;
  }
  v18 = *(_DWORD *)(v5 + 480);
  do
  {
    if ( !v18 )
      break;
    _X13 = (unsigned int *)(v5 + 480);
    __asm { PRFM            #0x11, [X13] }
    while ( 1 )
    {
      v25 = __ldxr(_X13);
      if ( v25 != v18 )
        break;
      if ( !__stlxr(v18 - 1, _X13) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v25 == v18;
    v18 = v25;
  }
  while ( !_ZF );
  v26 = *(const char **)(a1 + 16);
  v27 = v6;
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: failed to enable power resource %d\n", v26, v6);
  sde_evtlog_log(sde_dbg_base_evtlog, "dsi_ctrl_transfer_prepare", 3639, -1, v27, 60333, -17, v28, vars0a);
  return v27;
}
