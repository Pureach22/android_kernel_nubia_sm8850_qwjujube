__int64 __fastcall sde_connector_set_vrr_params(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  _BYTE *v8; // x24
  __int64 v9; // x19
  __int64 v10; // x21
  __int64 v11; // x22
  __int64 v12; // x8
  _QWORD *v13; // x20
  unsigned __int64 v14; // x20
  int v15; // w0
  int v16; // w6
  int v17; // w7
  int v18; // w0
  int v19; // w21
  int v20; // w27
  __int64 v21; // x8
  int v22; // w23
  int v23; // w26
  __int64 freq_pattern; // x0
  __int64 v25; // x22
  __int64 v26; // x25
  int v27; // w4
  _BOOL4 v28; // w22
  _BOOL4 v29; // w19
  char v30; // [xsp+0h] [xbp-40h]
  char v31; // [xsp+0h] [xbp-40h]
  unsigned __int8 *v32; // [xsp+30h] [xbp-10h]
  unsigned __int8 *v33; // [xsp+38h] [xbp-8h]

  if ( !result )
    return result;
  v8 = (_BYTE *)(result + 4096);
  v9 = result;
  if ( *(_BYTE *)(result + 4712) != 1 )
    return result;
  v10 = *(_QWORD *)(result + 2512);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 16)) == 0 )
    v11 = *(_QWORD *)(result + 2272);
  v12 = *(_QWORD *)(result + 2512);
  if ( *(_BYTE *)(result + 4714) != 1
    || (v13 = (_QWORD *)(v10 + 3232), v12 = *(_QWORD *)(result + 2512), v10 == -3232)
    || (v12 = *(_QWORD *)(result + 2512), (*(_BYTE *)(v10 + 3240) & 8) == 0) )
  {
LABEL_11:
    if ( v12 )
    {
      v14 = *(_QWORD *)(v12 + 1728);
      if ( v14 )
        goto LABEL_15;
    }
    goto LABEL_13;
  }
  result = drm_mode_vrefresh(*v13);
  if ( (_DWORD)result )
  {
    v12 = *(_QWORD *)(v9 + 2512);
    goto LABEL_11;
  }
  result = drm_mode_vrefresh(*v13);
  v14 = 1000000000 / (int)result;
  if ( 1000000000 / (int)result )
  {
LABEL_15:
    if ( v14 && !*(_DWORD *)(v9 + 4692) )
    {
      v18 = sde_dbg_base_evtlog;
      *(_DWORD *)(v9 + 4692) = 1;
      sde_evtlog_log(v18, "sde_connector_set_vrr_params", 1214, -1, 13107, 1, -1059143953, a8, v30);
LABEL_19:
      v19 = 1000 * (0x3B9ACA00 / v14);
      sde_evtlog_log(sde_dbg_base_evtlog, "sde_connector_set_vrr_params", 1223, -1, v19, -1059143953, a7, a8, v30);
      v20 = *(_DWORD *)(v9 + 4688);
      if ( v19 != v20 )
      {
        *(_DWORD *)(v9 + 4688) = v19;
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "frame_interval%d\n", v19);
      }
      v21 = *(_QWORD *)(v9 + 2512);
      if ( v21 )
        v22 = *(_DWORD *)(v21 + 1760);
      else
        v22 = 0;
      v23 = *(_DWORD *)(v9 + 4696);
      if ( v22 == v23 )
      {
        *((_WORD *)v8 + 310) = 0;
        v32 = v8 + 621;
        v33 = v8 + 620;
        if ( v19 == v20 && *(_QWORD *)(v9 + 4704) )
        {
LABEL_42:
          v27 = *(_DWORD *)(v9 + 64);
          v28 = v22 != v23;
          v29 = v19 != v20;
          result = sde_evtlog_log(
                     sde_dbg_base_evtlog,
                     "sde_connector_set_vrr_params",
                     1279,
                     -1,
                     v27,
                     v14,
                     SHIDWORD(v14),
                     v28,
                     v29);
          if ( (_drm_debug & 4) != 0 )
            return _drm_dev_dbg(
                     0,
                     0,
                     0,
                     "usecase_update:%d FI_updated:%d usecase:%d FI:%d pattern_updated %d %d\n",
                     v28,
                     v29,
                     v22,
                     v19,
                     *v33,
                     *v32);
          return result;
        }
      }
      else
      {
        *(_DWORD *)(v9 + 4696) = v22;
        v32 = v8 + 621;
        v33 = v8 + 620;
        *((_WORD *)v8 + 310) = 0;
      }
      freq_pattern = sde_encoder_get_freq_pattern(v11, *(_DWORD *)(v9 + 4688), v22);
      if ( !freq_pattern )
        return sde_evtlog_log(
                 sde_dbg_base_evtlog,
                 "sde_connector_set_vrr_params",
                 1243,
                 -1,
                 60333,
                 v14,
                 SHIDWORD(v14),
                 -1059143953,
                 v31);
      v25 = *(_QWORD *)(v9 + 4704);
      if ( v25 )
      {
        if ( *(_DWORD *)(freq_pattern + 12) != *(_DWORD *)(v25 + 12)
          || *(_DWORD *)(freq_pattern + 20) != *(_DWORD *)(v25 + 20) )
        {
          *(_QWORD *)(v9 + 4704) = freq_pattern;
          *v33 = 1;
          if ( *(unsigned __int8 *)(freq_pattern + 28) != *(unsigned __int8 *)(v25 + 28) )
            *v32 = 1;
          v26 = freq_pattern;
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "sde_connector_set_vrr_params",
            1262,
            -1,
            *(_DWORD *)(freq_pattern + 12),
            *(_DWORD *)(v25 + 12),
            *(_DWORD *)(freq_pattern + 20),
            *(_DWORD *)(v25 + 20),
            239);
          freq_pattern = v26;
        }
        if ( **(_DWORD **)freq_pattern != **(_DWORD **)v25 )
        {
          v8[584] = 1;
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "sde_connector_set_vrr_params",
            1272,
            -1,
            13107,
            **(_DWORD **)freq_pattern,
            **(_DWORD **)v25,
            -1059143953,
            v31);
        }
      }
      else
      {
        *(_QWORD *)(v9 + 4704) = freq_pattern;
        *v33 = 1;
        *v32 = 1;
      }
      goto LABEL_42;
    }
    if ( v14 )
      goto LABEL_19;
    goto LABEL_24;
  }
LABEL_13:
  result = drm_mode_vrefresh(*(_QWORD *)(v10 + 3232));
  if ( !(_DWORD)result )
  {
    v15 = drm_mode_vrefresh(*(_QWORD *)(v10 + 3232));
    v14 = 1000000000 / v15;
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "sde_connector_set_vrr_params",
               1209,
               -1,
               1000000000 / v15,
               -1059143953,
               v16,
               v17,
               v30);
    goto LABEL_15;
  }
LABEL_24:
  if ( (_drm_debug & 4) != 0 )
    return _drm_dev_dbg(0, 0, 0, "VRR not supported\n");
  return result;
}
