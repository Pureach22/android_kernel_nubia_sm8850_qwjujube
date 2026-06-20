__int64 __fastcall sde_hw_rc_get_param_rb(_DWORD *a1, unsigned __int16 *a2, _DWORD *a3, int *a4)
{
  int v4; // w8
  int v5; // w8
  unsigned int v6; // w19
  int v7; // w20
  unsigned int v8; // w9
  unsigned int v9; // w22
  int v10; // w27
  int v11; // w26
  int v12; // w28
  _BOOL4 v13; // w24
  unsigned int v14; // w25
  int v15; // w10
  int v17; // w10
  int v18; // w5
  int v19; // w10
  _DWORD *v20; // [xsp+20h] [xbp-20h]
  int *v21; // [xsp+28h] [xbp-18h]

  if ( !a2 || !a3 || !a4 )
  {
    _drm_err("invalid arguments\n");
    return 4294967274LL;
  }
  v4 = a1[4];
  if ( v4 == 2 )
  {
    v5 = a1[5];
    v21 = a4;
    v20 = a3;
  }
  else
  {
    if ( v4 != 4 )
    {
      _drm_err("invalid cfg_param_03:%u\n", v4);
      return 4294967274LL;
    }
    v21 = a4;
    v20 = a3;
    v5 = a1[6] + a1[5];
  }
  v6 = *a2;
  v7 = a2[1];
  v8 = a2[2] + v6;
  v9 = v8 - 1;
  v10 = a2[3] + v7;
  v12 = a1[2];
  v11 = a1[3];
  v13 = v8 != 0;
  v14 = v5 - 1;
  _drm_dev_dbg(0, 0, 0, "x1:%u y1:%u x2:%u y2:%u\n", *a2, a2[1], v8 - 1, (unsigned int)(v10 - 1));
  _drm_dev_dbg(0, 0, 0, "cfg_param_01:%u cfg_param_02:%u half_panel_x:%u", v12, v11, v14);
  if ( v10 - 1 <= v7 || (int)v9 <= (int)v6 || !v13 || !v10 || (v14 & 0x80000000) != 0 )
  {
    _drm_err("invalid coordinates\n");
    return 4294967274LL;
  }
  if ( v12 >= v7 )
  {
    *v20 |= 1u;
    if ( v14 < v6 || v9 > v14 )
    {
      v17 = *v21;
      if ( v14 >= v6 || v9 <= v14 )
        v15 = v17 | 3;
      else
        v15 = v17 | 2;
    }
    else
    {
      v15 = *v21 | 1;
    }
    *v21 = v15;
  }
  if ( v10 <= v11 )
  {
    v18 = *v21;
  }
  else
  {
    *v20 |= 2u;
    if ( v14 < v6 || v9 > v14 )
    {
      v19 = *v21;
      if ( v14 >= v6 || v9 <= v14 )
        v18 = v19 | 3;
      else
        v18 = v19 | 2;
    }
    else
    {
      v18 = *v21 | 1;
    }
    *v21 = v18;
  }
  _drm_dev_dbg(0, 0, 0, "param_r:0x%08X param_b:0x%08X\n", *v20, v18);
  sde_evtlog_log(sde_dbg_base_evtlog, "_sde_hw_rc_get_param_rb", 642, -1, *a2, a2[1], a2[2], a2[3], 239);
  sde_evtlog_log(sde_dbg_base_evtlog, "_sde_hw_rc_get_param_rb", 643, -1, v6, v7, v9, v10 - 1, v12);
  return 0;
}
