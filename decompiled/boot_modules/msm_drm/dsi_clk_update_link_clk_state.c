__int64 __fastcall dsi_clk_update_link_clk_state(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4, char a5)
{
  _DWORD *v9; // x8
  __int64 v10; // x0
  __int64 result; // x0
  const char *v12; // x2
  unsigned int v13; // w20
  _DWORD *v14; // x8
  __int64 v15; // x0
  int v16; // w23
  __int64 v17; // x27
  int i; // w20
  __int64 v19; // x25
  __int64 v20; // x26
  _DWORD *v21; // x8
  int v22; // w0
  unsigned int v23; // w20
  __int64 v24; // x24
  __int64 v25; // x20
  _DWORD *v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  unsigned int v29; // w19
  _DWORD *v30; // x8
  __int64 v31; // x0
  unsigned int v32; // [xsp+4h] [xbp-Ch]
  __int64 v33; // [xsp+8h] [xbp-8h]

  if ( !a1 )
    return 4294967274LL;
  if ( (a5 & 1) == 0 )
  {
    v14 = *(_DWORD **)(a1 + 408);
    if ( v14 )
    {
      v15 = *(_QWORD *)(a1 + 448);
      if ( *(v14 - 1) != 1029685075 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v14)(v15, 2, a3, a4) )
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: pre link clk off cb failed\n");
    }
    v16 = *(_DWORD *)(a1 + 96);
    v17 = *(unsigned int *)(a1 + 100);
    v32 = a4;
    v33 = a2 + 48LL * (unsigned int)v17;
    if ( v16 )
    {
      for ( i = 0; i != v16; ++i )
      {
        if ( i != v17 )
        {
          v19 = a2 + 48LL * i;
          if ( v19 )
          {
            if ( (a3 & 1) != 0 )
            {
              v20 = *(_QWORD *)(v19 + 24);
              clk_disable(v20);
              clk_unprepare(v20);
              _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: LP Link clocks are disabled\n");
            }
            if ( (a3 & 2) != 0 )
              dsi_link_hs_clk_stop(a2 + 48LL * i);
          }
        }
      }
    }
    if ( (a3 & 1) != 0 )
    {
      v24 = *(_QWORD *)(v33 + 24);
      clk_disable(v24);
      clk_unprepare(v24);
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: LP Link clocks are disabled\n");
      if ( (a3 & 2) == 0 )
      {
LABEL_26:
        v21 = *(_DWORD **)(a1 + 416);
        if ( !v21 )
          return 0;
LABEL_34:
        v28 = *(_QWORD *)(a1 + 448);
        if ( *(v21 - 1) != 1029685075 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v21)(v28, 2, a3, v32);
        if ( (_DWORD)result )
        {
          v29 = result;
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: post link clk off cb failed\n");
          return v29;
        }
        return result;
      }
    }
    else if ( (a3 & 2) == 0 )
    {
      goto LABEL_26;
    }
    v25 = a2 - 48 * v17;
    dsi_link_hs_clk_stop(v33);
    v26 = *(_DWORD **)(v25 + 184);
    v27 = *(_QWORD *)(v25 + 232);
    if ( *(v26 - 1) != -1297827279 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v26)(v27, 0);
    v21 = *(_DWORD **)(a1 + 416);
    if ( !v21 )
      return 0;
    goto LABEL_34;
  }
  v9 = *(_DWORD **)(a1 + 432);
  if ( v9 )
  {
    v10 = *(_QWORD *)(a1 + 448);
    if ( *(v9 - 1) != 1029685075 )
      __break(0x8228u);
    LODWORD(result) = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v9)(v10, 2, a3, a4);
    if ( (_DWORD)result )
    {
      v12 = "*ERROR* [msm-dsi-error]: pre link clk on cb failed for type %d\n";
LABEL_8:
      v13 = result;
      drm_dev_printk(0, &unk_248D72, v12, a3);
      return v13;
    }
  }
  v22 = dsi_display_link_clk_enable(a2, a3, *(unsigned int *)(a1 + 96), *(unsigned int *)(a1 + 100));
  if ( v22 )
  {
    v23 = v22;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to start link clk type %d rc=%d\n", a3, v22);
    return v23;
  }
  v30 = *(_DWORD **)(a1 + 424);
  if ( !v30 )
    return 0;
  v31 = *(_QWORD *)(a1 + 448);
  if ( *(v30 - 1) != 1029685075 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v30)(v31, 2, a3, a4);
  if ( (_DWORD)result )
  {
    v12 = "*ERROR* [msm-dsi-error]: post link clk on cb failed for type %d\n";
    goto LABEL_8;
  }
  return result;
}
