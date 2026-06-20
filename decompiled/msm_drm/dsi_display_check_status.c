__int64 __fastcall dsi_display_check_status(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // x24
  int v6; // w22
  __int64 v7; // x9
  int v8; // w21
  int v9; // w7
  unsigned int v11; // w20
  unsigned int v12; // w8
  long double v13; // q0
  char v14; // w23
  __int64 v15; // x8
  int v16; // w0
  unsigned int v17; // w9
  int v18; // w0
  char vars0; // [xsp+0h] [xbp+0h]

  if ( a2 )
  {
    v3 = *(_QWORD *)(a2 + 264);
    if ( v3 )
    {
      mutex_lock(v3 + 1040);
      if ( (*(_BYTE *)(v3 + 1973) & 1) != 0 )
      {
        if ( !*(_DWORD *)(v3 + 1968) )
        {
          v6 = *(_DWORD *)(v3 + 1724);
          if ( v6 != 4 )
          {
            v7 = *(_QWORD *)(a2 + 264);
            if ( !v7 || (*(_BYTE *)(v7 + 1974) & 1) == 0 && (*(_BYTE *)(v7 + 1016) & 1) == 0 )
            {
              if ( v6 == 5 )
              {
                v8 = -22;
LABEL_14:
                mutex_unlock(v3 + 1040);
                sde_evtlog_log(
                  sde_dbg_base_evtlog,
                  "dsi_display_check_status",
                  1238,
                  -1,
                  8738,
                  v8,
                  -1059143953,
                  v9,
                  vars0);
                return (unsigned int)v8;
              }
              sde_evtlog_log(
                sde_dbg_base_evtlog,
                "dsi_display_check_status",
                1189,
                -1,
                4369,
                v6,
                a3 & 1,
                -1059143953,
                vars0);
              if ( (*(_BYTE *)(a2 + 1641) & 1) != 0
                || ((a3 & 1) == 0 ? (v11 = 1) : (v11 = 5), *(_DWORD *)(v3 + 1352) == 1) )
              {
                v11 = 0;
              }
              v12 = *(_DWORD *)(a2 + 160);
              if ( v12 )
              {
                if ( a2 != -168 )
                {
                  *(_BYTE *)(*(_QWORD *)(a2 + 168) + 2801LL) = 1;
                  v12 = *(_DWORD *)(a2 + 160);
                }
                if ( v12 >= 2 && a2 != -216 )
                  *(_BYTE *)(*(_QWORD *)(a2 + 216) + 2801LL) = 1;
              }
              v8 = 1;
              dsi_display_clk_ctrl(*(_QWORD *)(a2 + 1320), 3, 1);
              dsi_display_toggle_error_interrupt_status(a2, 0);
              if ( v6 > 1 )
              {
                v14 = 0;
                v15 = a2;
                if ( v6 == 2 )
                  goto LABEL_39;
                if ( v6 == 3 )
                {
LABEL_41:
                  v17 = *(_DWORD *)(v15 + 160);
                  if ( v17 )
                  {
                    if ( v15 != -168 )
                    {
                      *(_BYTE *)(*(_QWORD *)(v15 + 168) + 2801LL) = 0;
                      v17 = *(_DWORD *)(v15 + 160);
                    }
                    if ( v17 >= 2 && v15 != -216 )
                      *(_BYTE *)(*(_QWORD *)(v15 + 216) + 2801LL) = 0;
                  }
                  if ( (a3 & 1) == 0 || (*(_BYTE *)(v3 + 1720) & 1) != 0 )
                    goto LABEL_51;
                  v18 = dsi_display_status_check_te(v15, v11, v13);
                  if ( v18 > 0 )
                  {
                    v8 = 1;
                    v15 = a2;
LABEL_51:
                    dsi_display_toggle_error_interrupt_status(v15, 1);
                    v15 = a2;
LABEL_54:
                    dsi_display_clk_ctrl(*(_QWORD *)(v15 + 1320), 3, 0);
                    goto LABEL_14;
                  }
                  v8 = v18;
                  v15 = a2;
LABEL_53:
                  *(_DWORD *)(v3 + 1968) = 1;
                  goto LABEL_54;
                }
              }
              else
              {
                if ( !v6 )
                {
                  v8 = dsi_display_status_reg_read(a2);
LABEL_36:
                  v15 = a2;
                  if ( v8 > 0 || (a3 & 1) == 0 )
                  {
LABEL_40:
                    if ( v8 < 1 )
                      goto LABEL_53;
                    goto LABEL_41;
                  }
                  v14 = 1;
LABEL_39:
                  v16 = dsi_display_status_check_te(v15, v11, v13);
                  v15 = a2;
                  v8 = v16;
                  a3 = v14;
                  goto LABEL_40;
                }
                if ( v6 == 1 )
                {
                  *(double *)&v13 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]:  ++\n");
                  v8 = 0;
                  goto LABEL_36;
                }
              }
              printk(&unk_275294, (unsigned int)v6);
              v15 = a2;
              *(_BYTE *)(v3 + 1720) = 0;
              goto LABEL_41;
            }
          }
        }
      }
      else
      {
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Panel not initialized\n");
      }
      v8 = 1;
      goto LABEL_14;
    }
  }
  return (unsigned int)-22;
}
