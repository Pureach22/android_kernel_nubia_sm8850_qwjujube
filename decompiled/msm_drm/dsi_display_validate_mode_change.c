__int64 __fastcall dsi_display_validate_mode_change(__int64 a1, _DWORD *a2, _DWORD *a3)
{
  __int64 v3; // x19
  __int64 v4; // x8
  int v8; // w8
  bool v9; // zf
  __int64 v10; // x9
  _DWORD *v11; // x8
  _DWORD *v12; // x10
  __int64 result; // x0
  int v14; // w6
  int v15; // w11
  __int64 v16; // x19
  int v17; // w6
  size_t v18; // x0
  __int64 v19; // x8
  double v20; // d0
  int v21; // w8
  int v22; // w6
  unsigned int v23; // w19
  char v24; // [xsp+0h] [xbp-50h]
  _QWORD v25[3]; // [xsp+28h] [xbp-28h] BYREF
  __int64 v26; // [xsp+40h] [xbp-10h]
  __int64 v27; // [xsp+48h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  memset(v25, 0, sizeof(v25));
  if ( a1 && a3 && (v3 = *(_QWORD *)(a1 + 16)) != 0 )
  {
    v4 = *(_QWORD *)(a1 + 264);
    if ( v4 && *(_QWORD *)(v4 + 1424) )
    {
      if ( a2[6] == a3[6] && *a2 == *a3 )
      {
        mutex_lock(a1 + 72);
        v8 = *(_DWORD *)(v3 + 4520);
        if ( v8 == 2 )
        {
          v10 = a1;
          v12 = a2;
          v11 = a3;
          if ( *(_DWORD *)(a1 + 888) == 1 )
          {
            a3[39] |= 0x100u;
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "dsi_display_validate_mode_change",
              8410,
              -1,
              17476,
              *(_DWORD *)(v3 + 4520),
              *(_DWORD *)(a1 + 888),
              -1059143953,
              v24);
            _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Panel operating mode change to command detected\n");
            goto LABEL_38;
          }
        }
        else
        {
          v9 = v8 == 1;
          v10 = a1;
          v11 = a3;
          v12 = a2;
          if ( v9 && *(_DWORD *)(a1 + 888) == 2 )
          {
            a3[39] |= 0x80u;
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "dsi_display_validate_mode_change",
              8404,
              -1,
              13107,
              *(_DWORD *)(v3 + 4520),
              *(_DWORD *)(a1 + 888),
              -1059143953,
              v24);
            _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Panel operating mode change to video detected\n");
            goto LABEL_38;
          }
        }
        v14 = *((unsigned __int8 *)v11 + 72);
        if ( *((unsigned __int8 *)v12 + 72) == v14 )
        {
          v15 = v11[41];
          if ( v12[41] == v15 )
          {
            v16 = *(_QWORD *)(v10 + 264);
            if ( v12[3] != v11[3] || v12[9] != v11[9] )
            {
              dsi_panel_get_dfps_caps(v16, v25);
              if ( (v26 & 0x100000000LL) != 0 || *(_BYTE *)(v16 + 1400) == 1 )
              {
                _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Mode switch is seamless variable refresh\n");
                v17 = a3[11];
                v18 = sde_dbg_base_evtlog;
                a3[39] |= 0x10u;
                sde_evtlog_log(v18, "dsi_display_validate_mode_change", 8438, -1, 30583, a2[11], v17, a2[3], a3[3]);
              }
            }
            v19 = a1;
            if ( *(_BYTE *)(a1 + 856) == 1 )
            {
              if ( *(_BYTE *)(v16 + 1392) == 1 )
              {
                v20 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: dynamic clk change detected\n");
                v21 = a3[39];
                if ( (v21 & 0x10) != 0 && (*(_BYTE *)(v16 + 1400) & 1) == 0 )
                {
                  drm_dev_printk(
                    0,
                    &unk_248D72,
                    "*ERROR* [msm-dsi-error]: dfps and dyn clk not supported in same commit\n",
                    v20);
                  v23 = -524;
                  v19 = a1;
                  goto LABEL_40;
                }
                if ( *(_DWORD *)(a1 + 888) == 1 && *(_BYTE *)(v16 + 1400) )
                  v21 |= 0x10u;
                v22 = a3[38];
                a3[39] = v21 | 0x20;
                sde_evtlog_log(
                  sde_dbg_base_evtlog,
                  "dsi_display_validate_mode_change",
                  8467,
                  -1,
                  34952,
                  a2[38],
                  v22,
                  -1059143953,
                  v24);
                v19 = a1;
              }
              v23 = 0;
              *(_BYTE *)(v19 + 856) = 0;
LABEL_40:
              mutex_unlock(v19 + 72);
              result = v23;
              goto LABEL_17;
            }
LABEL_39:
            v23 = 0;
            goto LABEL_40;
          }
          v11[39] |= 0x200u;
          *(_DWORD *)(*(_QWORD *)(v10 + 264) + 1224LL) = v15;
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "dsi_display_validate_mode_change",
            8421,
            -1,
            26214,
            v12[41],
            v11[41],
            -1059143953,
            v24);
          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: BPP mode change detected\n");
        }
        else
        {
          v11[39] |= 8u;
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "dsi_display_validate_mode_change",
            8415,
            -1,
            21845,
            *((unsigned __int8 *)v12 + 72),
            v14,
            -1059143953,
            v24);
          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSC mode change detected\n");
        }
LABEL_38:
        v19 = a1;
        goto LABEL_39;
      }
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Avoid VRR and POMS when resolution is changed\n");
    }
    else
    {
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Current panel mode not set\n");
    }
    result = 0;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    result = 4294967274LL;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
