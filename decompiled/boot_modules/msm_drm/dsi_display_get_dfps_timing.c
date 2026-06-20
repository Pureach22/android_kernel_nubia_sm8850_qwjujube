__int64 __fastcall dsi_display_get_dfps_timing(__int64 a1, int *a2, unsigned int a3)
{
  __int64 v6; // x13
  unsigned int v7; // w8
  unsigned int v8; // w9
  __int64 v9; // x0
  __int64 v10; // x2
  int v11; // w6
  int v12; // w16
  int v13; // w7
  unsigned int v14; // w28
  unsigned int v15; // w10
  unsigned int v16; // w11
  _DWORD *v17; // x21
  unsigned int v18; // w19
  int v19; // w17
  unsigned int v20; // w15
  int *v21; // x24
  unsigned int v22; // w14
  __int64 v23; // x3
  char v24; // w1
  __int64 v25; // x12
  unsigned int v26; // w22
  unsigned int v27; // w23
  int v28; // w25
  int v29; // w11
  int v30; // w5
  int v31; // w27
  int *v32; // x8
  __int64 v33; // x8
  _DWORD *v34; // x26
  int v35; // w4
  int v36; // w4
  int v37; // w19
  int v38; // w25
  unsigned int v39; // w22
  unsigned int v40; // w28
  int v41; // w19
  int v42; // w4
  int v43; // w5
  unsigned int v44; // w22
  unsigned int v45; // w25
  int v46; // w28
  int v47; // w19
  int v48; // w4
  int v49; // w19
  unsigned int v50; // w22
  unsigned int v51; // w25
  int v52; // w26
  int v53; // w28
  __int64 v54; // x8
  int *v55; // x10
  __int64 result; // x0
  int v57; // w19
  char v58; // w21
  unsigned int v59; // w20
  int v60; // w19
  unsigned int v61; // w22
  int v62; // [xsp+1Ch] [xbp-64h]
  unsigned int v63; // [xsp+20h] [xbp-60h]
  unsigned int v64; // [xsp+20h] [xbp-60h]
  unsigned int v65; // [xsp+24h] [xbp-5Ch]
  unsigned int v66; // [xsp+24h] [xbp-5Ch]
  int v67; // [xsp+28h] [xbp-58h]
  int v68; // [xsp+28h] [xbp-58h]
  int v69; // [xsp+28h] [xbp-58h]
  int v70; // [xsp+2Ch] [xbp-54h]
  int v71; // [xsp+2Ch] [xbp-54h]
  int v72; // [xsp+30h] [xbp-50h]
  int v73; // [xsp+30h] [xbp-50h]
  char v74; // [xsp+34h] [xbp-4Ch]
  char v75; // [xsp+34h] [xbp-4Ch]
  __int64 v76; // [xsp+38h] [xbp-48h]
  __int64 v77; // [xsp+38h] [xbp-48h]
  char v78; // [xsp+44h] [xbp-3Ch]
  char v79; // [xsp+44h] [xbp-3Ch]
  __int64 v80; // [xsp+48h] [xbp-38h]
  __int64 v81; // [xsp+48h] [xbp-38h]
  int v82; // [xsp+50h] [xbp-30h]
  int v83; // [xsp+54h] [xbp-2Ch]
  _QWORD v84[3]; // [xsp+58h] [xbp-28h] BYREF
  __int64 v85; // [xsp+70h] [xbp-10h]
  __int64 v86; // [xsp+78h] [xbp-8h]

  v86 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v85 = 0;
  memset(v84, 0, sizeof(v84));
  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    goto LABEL_59;
  }
  if ( *(_DWORD *)(a1 + 836) < 2u )
  {
    dsi_panel_get_dfps_caps(*(_QWORD *)(a1 + 264), v84);
    if ( (v85 & 0x100000000LL) == 0 )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: dfps not supported by panel\n");
      goto LABEL_59;
    }
    v6 = *(_QWORD *)(a1 + 264);
    v7 = *a2;
    v8 = a2[1];
    v10 = *((_QWORD *)a2 + 10);
    v9 = *((_QWORD *)a2 + 11);
    v12 = a2[6];
    v11 = a2[7];
    v14 = a2[38];
    v13 = a2[39];
    v15 = a2[2];
    v17 = a2 + 3;
    v16 = a2[3];
    v18 = a2[4];
    v19 = a2[8];
    v21 = a2 + 9;
    v20 = a2[9];
    v22 = a2[11];
    v23 = *((unsigned __int8 *)a2 + 72);
    v24 = *((_BYTE *)a2 + 73);
    v25 = *((_QWORD *)a2 + 23);
    if ( *(_BYTE *)(v6 + 1280) != 1 || (v26 = *(_DWORD *)(v6 + 1284), v26 <= 1) )
    {
      if ( *(_BYTE *)(v25 + 3400) == 1 )
        *(_WORD *)(v25 + 2506) = v7;
      v26 = *(_DWORD *)(a1 + 160);
    }
    v27 = v16 / v26;
    v28 = v84[0];
    v29 = v15 / v26;
    v30 = v8 / v26;
    v31 = v7 / v26;
    if ( a3 )
    {
      if ( LODWORD(v84[0]) != 3 )
        goto LABEL_11;
      goto LABEL_37;
    }
    v33 = *(_QWORD *)(a1 + 264);
    if ( v33 )
    {
      v34 = *(_DWORD **)(v33 + 1424);
      if ( *v34 == v31 )
      {
        if ( v34[1] == v30 )
        {
          if ( v34[2] == v29 )
          {
            v35 = v34[3];
            v82 = v19;
            v83 = v12;
            if ( v35 == v27 )
              goto LABEL_23;
            v74 = v23;
            v80 = v9;
            v78 = v24;
            v76 = v10;
            v70 = v13;
            v72 = v8 / v26;
            v63 = v20;
            v65 = v22;
            v67 = v11;
            v62 = v15 / v26;
            _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: timing.h_front_porch differs %d %d\n", v35, v27);
            v11 = v67;
            v13 = v70;
            v30 = v72;
            LOBYTE(v23) = v74;
            v29 = v62;
            v20 = v63;
            v10 = v76;
            v24 = v78;
            v9 = v80;
            v22 = v65;
            if ( v28 == 3 )
            {
LABEL_23:
              if ( v34[4] == v18 / v26 )
              {
                if ( v34[6] == v83 )
                {
                  if ( v34[7] == v11 )
                  {
                    if ( v34[8] == v82 )
                    {
                      v36 = v34[9];
                      v73 = v30;
                      v81 = v9;
                      v79 = v24;
                      v77 = v10;
                      v75 = v23;
                      v71 = v13;
                      if ( v36 == v20 )
                        goto LABEL_29;
                      v64 = v20;
                      v66 = v22;
                      v37 = v29;
                      v68 = v11;
                      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: timing.v_front_porch differs %d %d\n", v36, v20);
                      v11 = v68;
                      v13 = v71;
                      v30 = v73;
                      LOBYTE(v23) = v75;
                      v20 = v64;
                      v22 = v66;
                      v10 = v77;
                      v24 = v79;
                      v29 = v37;
                      v9 = v81;
                      if ( v28 == 4 )
                      {
LABEL_29:
                        v38 = v14 / v26;
                        if ( v34[11] == v22 )
                        {
                          v39 = v22;
                          v40 = v20;
                          v69 = v11;
                          v41 = v29;
                          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: timing.refresh_rate identical %d %d\n", v22, v22);
                          v11 = v69;
                          v13 = v71;
                          v30 = v73;
                          LOBYTE(v23) = v75;
                          v10 = v77;
                          v24 = v79;
                          v29 = v41;
                          v9 = v81;
                          v20 = v40;
                          v22 = v39;
                        }
                        v42 = v34[38];
                        if ( v42 != v38 )
                        {
                          v43 = v38;
                          v44 = v22;
                          v45 = v20;
                          v46 = v11;
                          v47 = v29;
                          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: pixel_clk_khz differs %d %d\n", v42, v43);
                          v13 = v71;
                          v30 = v73;
                          LOBYTE(v23) = v75;
                          v10 = v77;
                          v29 = v47;
                          v24 = v79;
                          v9 = v81;
                          v11 = v46;
                          v20 = v45;
                          v22 = v44;
                        }
                        v48 = v34[39];
                        if ( v48 != v13 )
                        {
                          v49 = v30;
                          v50 = v22;
                          v51 = v20;
                          v52 = v11;
                          v53 = v29;
                          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: flags differs %d %d\n", v48, v13);
                          LOBYTE(v23) = v75;
                          v10 = v77;
                          v29 = v53;
                          v24 = v79;
                          v9 = v81;
                          v11 = v52;
                          v20 = v51;
                          v22 = v50;
                          v30 = v49;
                        }
                        v19 = v82;
                        v12 = v83;
                        v54 = *(_QWORD *)(*(_QWORD *)(a1 + 264) + 1424LL);
                        if ( v54 )
                        {
                          a3 = *(_DWORD *)(v54 + 44);
                          v28 = v84[0];
                          if ( LODWORD(v84[0]) != 3 )
                          {
LABEL_11:
                            if ( v28 != 4 )
                            {
                              drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Unsupported DFPS mode %d\n", v28);
                              result = 4294966772LL;
LABEL_60:
                              _ReadStatusReg(SP_EL0);
                              return result;
                            }
                            if ( (v23 & 1) != 0 && v10 )
                            {
                              v32 = (int *)(v10 + 160);
                            }
                            else
                            {
                              if ( (v24 & 1) == 0 || !v9 )
                                goto LABEL_47;
                              v32 = (int *)(v9 + 500);
                            }
                            v31 = *v32;
LABEL_47:
                            v57 = v22;
                            v58 = v20;
                            v59 = dsi_display_dfps_calc_front_porch(
                                    a3,
                                    v22,
                                    v29 + v27 + v30 + v31,
                                    v11 + v12 + v19 + v20,
                                    v20,
                                    v21);
                            sde_evtlog_log(
                              sde_dbg_base_evtlog,
                              "dsi_display_get_dfps_timing",
                              5491,
                              -1,
                              13107,
                              4,
                              a3,
                              v57,
                              v58);
                            result = v59;
                            goto LABEL_60;
                          }
LABEL_37:
                          if ( (v23 & 1) != 0 && v10 )
                          {
                            v55 = (int *)(v10 + 160);
                          }
                          else
                          {
                            if ( (v24 & 1) == 0 || !v9 )
                            {
LABEL_52:
                              v60 = v22;
                              v61 = dsi_display_dfps_calc_front_porch(
                                      a3,
                                      v22,
                                      v11 + v12 + v19 + v20,
                                      v29 + v27 + v30 + v31,
                                      v27,
                                      v17);
                              sde_evtlog_log(
                                sde_dbg_base_evtlog,
                                "dsi_display_get_dfps_timing",
                                5504,
                                -1,
                                17476,
                                3,
                                a3,
                                v60,
                                v27);
                              result = v61;
                              if ( !v61 )
                                *v17 *= *(_DWORD *)(a1 + 160);
                              goto LABEL_60;
                            }
                            v55 = (int *)(v9 + 500);
                          }
                          v31 = *v55;
                          goto LABEL_52;
                        }
                        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: cur_mode is not initialized\n");
LABEL_59:
                        result = 4294967274LL;
                        goto LABEL_60;
                      }
                    }
                    else
                    {
                      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: timing.v_sync_width differs %d %d\n");
                    }
                  }
                  else
                  {
                    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: timing.v_back_porch differs %d %d\n");
                  }
                }
                else
                {
                  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: timing.v_active differs %d %d\n");
                }
              }
              else
              {
                _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: timing.h_skew differs %d %d\n");
              }
            }
          }
          else
          {
            _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: timing.h_sync_width differs %d %d\n");
          }
        }
        else
        {
          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: timing.h_back_porch differs %d %d\n");
        }
      }
      else
      {
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: timing.h_active differs %d %d\n");
      }
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n", v23);
    }
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: seamless dynamic fps not supported for mode\n");
    goto LABEL_59;
  }
  __break(0x5512u);
  return dsi_display_get_modes(a1, a2);
}
