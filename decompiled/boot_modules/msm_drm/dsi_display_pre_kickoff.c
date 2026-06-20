__int64 __fastcall dsi_display_pre_kickoff(__int64 a1, __int64 a2, unsigned int **a3)
{
  __int64 v3; // x8
  __int64 v4; // x22
  int v7; // w21
  unsigned int v8; // w8
  int updated; // w0
  int v10; // w4
  __int64 result; // x0
  unsigned int *v12; // x26
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x20
  char v16; // w21
  unsigned __int64 v17; // x9
  char v18; // w8
  __int64 v19; // x22
  __int64 v20; // x8
  __int64 v21; // x8
  unsigned __int16 *v22; // x0
  unsigned int v23; // w24
  unsigned int v24; // w25
  unsigned __int16 *v25; // x23
  unsigned __int64 v26; // x10
  unsigned __int16 *v27; // x14
  unsigned __int64 v28; // x11
  unsigned int v29; // w12
  unsigned __int16 v30; // w8
  unsigned __int64 v31; // x13
  unsigned __int16 v32; // w9
  unsigned int v33; // w7
  unsigned int v34; // w6
  unsigned int v35; // w23
  unsigned int v36; // w11
  unsigned int v37; // w12
  unsigned int v38; // w13
  unsigned int v39; // w15
  unsigned int v40; // w12
  unsigned int v41; // w13
  bool v42; // cf
  int v43; // w15
  int v44; // w4
  int v45; // w5
  int v46; // w14
  int v47; // w16
  int v48; // w17
  unsigned int v49; // w0
  const char *v50; // x2
  __int64 v51; // x9
  __int64 v52; // x8
  unsigned int v53; // w19
  _BYTE v54[4]; // [xsp+5Ch] [xbp-14h] BYREF
  _QWORD v55[2]; // [xsp+60h] [xbp-10h] BYREF

  v55[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 264);
  if ( *(_DWORD *)(v3 + 2236) == 1 )
    goto LABEL_26;
  v4 = *(_QWORD *)(v3 + 1424);
  if ( *(_BYTE *)(a2 + 1344) == 1 )
  {
    if ( *(_DWORD *)(a2 + 160) )
    {
      ((void (__fastcall *)(_QWORD, __int64, _QWORD))dsi_ctrl_setup_misr)(
        *(_QWORD *)(a2 + 168),
        1,
        *(unsigned int *)(a2 + 1348));
      if ( *(_DWORD *)(a2 + 160) >= 2u )
        ((void (__fastcall *)(_QWORD, _QWORD, _QWORD))dsi_ctrl_setup_misr)(
          *(_QWORD *)(a2 + 216),
          *(unsigned __int8 *)(a2 + 1344),
          *(unsigned int *)(a2 + 1348));
    }
  }
  if ( *(_DWORD *)(a2 + 864) )
  {
    mutex_lock(a2 + 72);
    mutex_lock(*(_QWORD *)(a2 + 264) + 1040LL);
    if ( *(_DWORD *)(a2 + 160) )
    {
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))dsi_ctrl_wait_for_cmd_mode_mdp_idle)(*(_QWORD *)(a2 + 168)) )
      {
LABEL_9:
        v7 = 1;
        goto LABEL_25;
      }
      v8 = *(_DWORD *)(a2 + 160);
      if ( v8 >= 2 )
      {
        if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))dsi_ctrl_wait_for_cmd_mode_mdp_idle)(*(_QWORD *)(a2 + 216)) )
          goto LABEL_9;
        v8 = *(_DWORD *)(a2 + 160);
      }
      if ( !*(_DWORD *)(*(_QWORD *)(v4 + 184) + 2368LL) )
      {
        v7 = 0;
LABEL_70:
        if ( v8 )
        {
          v51 = *(_QWORD *)(a2 + 168);
          if ( v51 && *(_BYTE *)(v51 + 2848) == 1 )
          {
            _flush_workqueue(*(_QWORD *)(a2 + 1624));
            cancel_work_sync(*(_QWORD *)(a2 + 168) + 2808LL);
            *(_BYTE *)(*(_QWORD *)(a2 + 168) + 2848LL) = 0;
            v8 = *(_DWORD *)(a2 + 160);
          }
          if ( v8 >= 2 )
          {
            v52 = *(_QWORD *)(a2 + 216);
            if ( v52 )
            {
              if ( *(_BYTE *)(v52 + 2848) == 1 )
              {
                _flush_workqueue(*(_QWORD *)(a2 + 1624));
                cancel_work_sync(*(_QWORD *)(a2 + 216) + 2808LL);
                *(_BYTE *)(*(_QWORD *)(a2 + 216) + 2848LL) = 0;
              }
            }
          }
        }
        goto LABEL_22;
      }
      if ( v8 )
      {
        v7 = dsi_phy_set_timing_params(
               *(_QWORD *)(a2 + 192),
               *(_QWORD *)(*(_QWORD *)(v4 + 184) + 2360LL),
               *(_DWORD *)(*(_QWORD *)(v4 + 184) + 2368LL),
               (*(_DWORD *)(v4 + 156) & 8) != 0);
        if ( v7 )
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to add DSI PHY timing params\n");
        v8 = *(_DWORD *)(a2 + 160);
        if ( v8 >= 2 )
        {
          v7 = dsi_phy_set_timing_params(
                 *(_QWORD *)(a2 + 240),
                 *(_QWORD *)(*(_QWORD *)(v4 + 184) + 2360LL),
                 *(_DWORD *)(*(_QWORD *)(v4 + 184) + 2368LL),
                 (*(_DWORD *)(v4 + 156) & 8) != 0);
          if ( v7 )
            drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to add DSI PHY timing params\n");
          v8 = *(_DWORD *)(a2 + 160);
        }
        goto LABEL_70;
      }
    }
    v7 = 0;
LABEL_22:
    updated = dsi_display_link_clk_force_update_ctrl(*(_QWORD *)(a2 + 1320));
    v10 = *(_DWORD *)(a2 + 860);
    if ( updated )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: Failed to configure dsi bit clock '%d'. rc = %d\n",
        v10,
        updated);
    }
    else
    {
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: dsi bit clk has been configured to %d\n", v10);
      *(_DWORD *)(a2 + 864) = 0;
    }
LABEL_25:
    mutex_unlock(*(_QWORD *)(a2 + 264) + 1040LL);
    mutex_unlock(a2 + 72);
    if ( v7 )
      goto LABEL_26;
  }
  result = 4294967274LL;
  if ( !a2 )
    goto LABEL_27;
  v12 = *a3;
  if ( !*a3 )
    goto LABEL_27;
  v13 = *(_QWORD *)(a2 + 264);
  if ( !v13 )
    goto LABEL_27;
  v14 = *(_QWORD *)(v13 + 1424);
  if ( !v14 || *(_BYTE *)(*(_QWORD *)(v14 + 184) + 3412LL) != 1 || !*(_DWORD *)(a2 + 160) )
  {
LABEL_26:
    result = 0;
    goto LABEL_27;
  }
  v15 = 0;
  v16 = 1;
  while ( 1 )
  {
    v19 = a2 + 168 + 48 * v15;
    v20 = *(_QWORD *)(a2 + 264);
    v55[0] = 0;
    v54[0] = 0;
    v21 = *(_QWORD *)(v20 + 1424);
    v22 = *(unsigned __int16 **)v19;
    if ( !v21 )
      goto LABEL_64;
    v23 = *v12;
    v24 = *(_DWORD *)(*(_QWORD *)(v21 + 184) + 3416LL);
    if ( *v12 <= v24 )
    {
      v26 = (unsigned __int64)(v22 + 1376);
      if ( v23 )
      {
        v34 = *((unsigned __int16 *)v12 + 2);
        v33 = *((unsigned __int16 *)v12 + 3);
        v32 = *((_WORD *)v12 + 4) - v34;
        v30 = *((_WORD *)v12 + 5) - v33;
        if ( v22 == (unsigned __int16 *)-2752LL )
        {
          LOWORD(v31) = 0;
          v29 = 0;
          LOWORD(v28) = 0;
          v35 = 0;
        }
        else
        {
          v36 = v22[1376];
          v37 = v22[1377];
          if ( v34 <= v36 )
            LODWORD(v26) = v22[1376];
          else
            LODWORD(v26) = *((unsigned __int16 *)v12 + 2);
          v38 = v22[1378] + v36;
          v39 = v22[1379] + v37;
          if ( v33 <= v37 )
            LODWORD(v28) = v22[1377];
          else
            LODWORD(v28) = *((unsigned __int16 *)v12 + 3);
          if ( v34 + v32 >= v38 )
            v40 = v38;
          else
            v40 = v34 + v32;
          if ( v33 + v30 >= v39 )
            v41 = v39;
          else
            v41 = v33 + v30;
          v42 = v40 >= (unsigned int)v26;
          v29 = v40 - v26;
          if ( v29 != 0 && v42 )
          {
            v42 = v41 >= (unsigned int)v28;
            LODWORD(v31) = v41 - v28;
            if ( (_DWORD)v31 != 0 && v42 )
            {
              v35 = 0;
              WORD2(v55[0]) = v29;
              v29 = (unsigned __int16)v29;
              v27 = v22;
              WORD1(v55[0]) = v28;
              HIWORD(v55[0]) = v31;
              goto LABEL_62;
            }
          }
          LOWORD(v31) = 0;
          v29 = 0;
          LOWORD(v28) = 0;
          LOWORD(v26) = 0;
          v35 = 0;
          v55[0] = 0;
        }
      }
      else
      {
        v26 = *(_QWORD *)v26;
        v30 = 0;
        v32 = 0;
        v33 = 0;
        v34 = 0;
        v35 = 0;
        v28 = v26 >> 16;
        v29 = WORD2(v26);
        v31 = HIWORD(v26);
        v55[0] = v26;
      }
      v27 = v22;
      goto LABEL_62;
    }
    v25 = *(unsigned __int16 **)v19;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: request for %d rois greater than max %d\n", v23, v24);
    LOWORD(v26) = v55[0];
    v27 = *(unsigned __int16 **)v19;
    v22 = v25;
    LOWORD(v28) = WORD1(v55[0]);
    v29 = WORD2(v55[0]);
    v30 = 0;
    LOWORD(v31) = HIWORD(v55[0]);
    v32 = 0;
    v33 = 0;
    v34 = 0;
    v35 = -22;
LABEL_62:
    v43 = v22[1376];
    v44 = *(_DWORD *)(v19 + 16);
    v45 = *((_DWORD *)v27 + 2);
    v46 = v22[1377];
    v47 = v22[1378];
    v48 = v22[1379];
    LOWORD(v55[0]) = v26 - v43;
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: ctrl%d:%d: req (%d,%d,%d,%d) bnd (%d,%d,%d,%d) out (%d,%d,%d,%d)\n",
      v44,
      v45,
      v34,
      v33,
      v32,
      v30,
      v43,
      v46,
      v47,
      v48,
      (unsigned __int16)(v26 - v43),
      (unsigned __int16)v28,
      v29,
      (unsigned __int16)v31);
    if ( v23 > v24 )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: dsi_display_calc_ctrl_roi failed rc %d\n", v35);
      result = v35;
      goto LABEL_27;
    }
    v22 = *(unsigned __int16 **)v19;
LABEL_64:
    v49 = dsi_ctrl_set_roi((__int64)v22, (unsigned __int16 *)v55, v54);
    if ( v49 )
    {
      v50 = "*ERROR* [msm-dsi-error]: dsi_ctrl_set_roi failed rc %d\n";
      goto LABEL_81;
    }
    if ( v54[0] == 1 )
      break;
LABEL_35:
    v17 = v15 + 1;
    result = 0;
    v15 = 1;
    v18 = v16 & (v17 < *(unsigned int *)(a2 + 160));
    v16 = 0;
    if ( (v18 & 1) == 0 )
      goto LABEL_27;
  }
  v49 = dsi_ctrl_timing_setup(*(_QWORD *)v19);
  if ( !v49 )
  {
    v49 = dsi_panel_send_roi_dcs(*(_QWORD *)(a2 + 264), (unsigned int)v15, v55);
    if ( v49 )
    {
      v50 = "*ERROR* [msm-dsi-error]: dsi_panel_set_roi failed rc %d\n";
      goto LABEL_81;
    }
    goto LABEL_35;
  }
  v50 = "*ERROR* [msm-dsi-error]: dsi_ctrl_setup failed rc %d\n";
LABEL_81:
  v53 = v49;
  drm_dev_printk(0, &unk_248D72, v50, v49);
  result = v53;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
