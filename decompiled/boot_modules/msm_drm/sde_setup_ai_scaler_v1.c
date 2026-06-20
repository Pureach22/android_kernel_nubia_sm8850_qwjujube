__int64 __fastcall sde_setup_ai_scaler_v1(__int64 a1, _QWORD *a2)
{
  int v4; // w4
  int v5; // w23
  __int64 v6; // x25
  int v7; // w1
  int v8; // w1
  unsigned int v9; // w2
  __int64 v11; // x21
  __int64 v12; // x27
  unsigned int v13; // w23

  if ( !a1 || !a2 )
  {
    _drm_err("invalid parameters ctx %pK cfg %pK\n", (const void *)a1, a2);
    return 4294967274LL;
  }
  v4 = *(_DWORD *)(a1 + 64);
  v5 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 716LL);
  if ( !v5 )
  {
    _drm_dev_dbg(0, 0, 1, "AI Scaler not supported on DSPP idx %d", v4);
    return 4294967274LL;
  }
  if ( v4 == *(_DWORD *)(a2[6] + 64LL) )
  {
    v6 = *a2;
    if ( *a2 )
    {
      v7 = *((_DWORD *)a2 + 2);
      if ( v7 != 1968 )
      {
        _drm_err("invalid size of payload len %d exp %zd\n", v7, 0x7B0u);
        return 4294967274LL;
      }
      sde_reg_write(a1, v5 + 4, *(_DWORD *)(v6 + 8), "ai_scaler_base + 0x4");
      v8 = *((_DWORD *)a2 + 7);
      if ( v8 == 1 )
      {
        v9 = 0;
      }
      else
      {
        if ( v8 != 2 )
        {
          _drm_err("invalid number of mixers %d\n", v8);
          return 4294967274LL;
        }
        v9 = 1;
      }
      sde_reg_write(a1, v5 + 8, v9, "ai_scaler_base + 0x8");
      sde_reg_write(
        a1,
        v5 + 12,
        *(_DWORD *)(v6 + 12) & 0xFFF | ((*(_DWORD *)(v6 + 16) & 0xFFF) << 16),
        "ai_scaler_base + 0xC");
      sde_reg_write(
        a1,
        v5 + 16,
        *(_DWORD *)(v6 + 20) & 0xFFF | ((*(_DWORD *)(v6 + 24) & 0xFFF) << 16),
        "ai_scaler_base + 0x10");
      if ( (*(_BYTE *)(v6 + 10) & 4) != 0 )
      {
        v11 = 0;
        v12 = v6 + 28;
        v13 = v5 + 60;
        do
        {
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "param[%d] = 0x%X\n", v11, *(_DWORD *)(v12 + 4 * v11));
          sde_reg_write(a1, v13, *(_DWORD *)(v12 + 4 * v11++), "ai_scaler_base + offset");
          v13 += 4;
        }
        while ( v11 != 485 );
      }
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_setup_ai_scaler_v1",
        773,
        -1,
        *(_DWORD *)(a1 + 64),
        *(_DWORD *)(a1 + 1496),
        *(_DWORD *)(a1 + 28),
        1,
        239);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "Enable AI Scaler: src_w:0x%X src_h:0x%X dst_w:0x%X dst_h:0x%X\n",
          *(_DWORD *)(v6 + 12),
          *(_DWORD *)(v6 + 16),
          *(_DWORD *)(v6 + 20),
          *(_DWORD *)(v6 + 24));
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_setup_ai_scaler_v1",
        778,
        -1,
        *((_DWORD *)a2 + 7),
        *(_DWORD *)(v6 + 8),
        *(_DWORD *)(v6 + 12),
        *(_DWORD *)(v6 + 16),
        *(_DWORD *)(v6 + 20));
    }
    else
    {
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_setup_ai_scaler_v1",
        722,
        -1,
        v4,
        *(_DWORD *)(a1 + 1496),
        *(_DWORD *)(a1 + 28),
        0,
        239);
      _drm_dev_dbg(0, 0, 1, "Disable AI SCALER feature\n");
      sde_reg_write(a1, v5 + 4, 0, "ai_scaler_base + 0x4");
    }
  }
  else
  {
    _drm_dev_dbg(0, 0, 1, "AI Scaler need not be programmed on %d", v4);
  }
  return 0;
}
