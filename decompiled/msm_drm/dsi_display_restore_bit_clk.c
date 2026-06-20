__int64 __fastcall dsi_display_restore_bit_clk(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  int v4; // w11
  unsigned int *v5; // x12
  int *v6; // x13
  int v7; // w15
  int v8; // w14
  unsigned int v9; // w19
  int v10; // w10
  unsigned int v12; // w9
  char vars0; // [xsp+0h] [xbp+0h]

  if ( a1 && a2 && (v2 = *(_QWORD *)(a2 + 184)) != 0 )
  {
    v3 = *(_QWORD *)(a1 + 264);
    if ( *(_BYTE *)(v3 + 1392) == 1 )
    {
      v4 = *(_DWORD *)(v2 + 2424);
      if ( v4 )
      {
        v5 = *(unsigned int **)(v2 + 2432);
        v6 = *(int **)(v2 + 2448);
        v7 = 0;
        v8 = *(_DWORD *)(a1 + 852);
        v9 = *v5;
        v10 = *v6;
        do
        {
          if ( v8 == v5[v7] )
          {
            v10 = v6[v7];
            v9 = *(_DWORD *)(a1 + 852);
          }
          ++v7;
        }
        while ( v4 != v7 );
        if ( v8 && (*(_BYTE *)(a1 + 856) & 1) == 0 )
        {
          v12 = *(_DWORD *)(v3 + 1396) - 1;
          if ( v12 <= 3 )
            *(_DWORD *)(a2 + qword_29D3C0[v12]) = v10;
        }
      }
      else
      {
        v9 = *(_DWORD *)(a1 + 860);
      }
      *(_QWORD *)(a2 + 48) = v9;
      *(_QWORD *)(v2 + 2408) = v9;
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dsi_display_restore_bit_clk",
        7701,
        -1,
        v9,
        *(_DWORD *)(a1 + 860),
        *(_DWORD *)(a1 + 852),
        -1059143953,
        vars0);
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dsi-debug]: clk_rate_hz:%u, cached_clk_rate:%u, dyn_bit_clk:%u\n",
        v9,
        *(_DWORD *)(a1 + 860),
        *(_DWORD *)(a1 + 852));
    }
    return 0;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid arguments\n");
    return 4294967274LL;
  }
}
