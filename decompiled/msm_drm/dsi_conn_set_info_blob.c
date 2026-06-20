__int64 __fastcall dsi_conn_set_info_blob(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  __int64 v8; // x2
  int v10; // w4
  const char *v11; // x2
  long double v12; // q0
  __int64 v13; // x22
  int v14; // w4
  long double v15; // q0
  const char *v16; // x2
  __int64 v17; // x2
  const char *v18; // x2
  const char *v19; // x2
  int v20; // w4
  const char *v21; // x2
  long double v22; // q0
  int v23; // w4
  const char *v24; // x2
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x8
  unsigned int v28; // w0

  result = 4294967274LL;
  if ( a2 && a3 )
  {
    v8 = *(_QWORD *)(a3 + 40);
    *(_QWORD *)(a3 + 16) = a1;
    ((void (__fastcall *)(__int64, const char *, __int64))sde_kms_info_add_keystr)(a2, "display type", v8);
    v10 = *(_DWORD *)(a3 + 832);
    if ( v10 > 1 )
    {
      if ( v10 == 2 )
      {
        v11 = "split display";
      }
      else
      {
        if ( v10 != 3 )
          goto LABEL_10;
        v11 = "split ext bridge";
      }
    }
    else
    {
      if ( v10 )
      {
        if ( v10 == 1 )
        {
          v11 = "ext bridge";
          goto LABEL_14;
        }
LABEL_10:
        *(double *)&v12 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: invalid display type:%d\n", v10);
        v13 = *(_QWORD *)(a3 + 264);
        if ( v13 )
          goto LABEL_15;
        goto LABEL_11;
      }
      v11 = "single display";
    }
LABEL_14:
    ((void (__fastcall *)(__int64, const char *, const char *))sde_kms_info_add_keystr)(a2, "display config", v11);
    v13 = *(_QWORD *)(a3 + 264);
    if ( v13 )
    {
LABEL_15:
      ((void (__fastcall *)(__int64, const char *, _QWORD, long double))sde_kms_info_add_keystr)(
        a2,
        "panel name",
        *(_QWORD *)v13,
        v12);
      v14 = *(_DWORD *)(v13 + 1352);
      if ( v14 == 2 )
      {
        ((void (__fastcall *)(__int64, const char *, const char *))sde_kms_info_add_keystr)(a2, "panel mode", "command");
        sde_kms_info_add_keyint(a2, (__int64)"mdp_transfer_time_us", *(unsigned int *)(a4 + 796));
      }
      else if ( v14 == 1 )
      {
        ((void (__fastcall *)(__int64, const char *, const char *))sde_kms_info_add_keystr)(a2, "panel mode", "video");
      }
      else
      {
        *(double *)&v15 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: invalid panel type:%d\n", v14);
      }
      if ( *(_BYTE *)(v13 + 1976) )
        v16 = "true";
      else
        v16 = "false";
      ((void (__fastcall *)(__int64, const char *, const char *, long double))sde_kms_info_add_keystr)(
        a2,
        "qsync support",
        v16,
        v15);
      v17 = *(unsigned int *)(v13 + 1980);
      if ( (_DWORD)v17 )
        sde_kms_info_add_keyint(a2, (__int64)"qsync_fps", v17);
      if ( *(_BYTE *)(v13 + 1388) )
        v18 = "true";
      else
        v18 = "false";
      ((void (__fastcall *)(__int64, const char *, const char *))sde_kms_info_add_keystr)(a2, "dfps support", v18);
      if ( *(_BYTE *)(v13 + 1388) == 1 )
      {
        sde_kms_info_add_keyint(a2, (__int64)"min_fps", *(unsigned int *)(v13 + 1364));
        sde_kms_info_add_keyint(a2, (__int64)"max_fps", *(unsigned int *)(v13 + 1368));
      }
      if ( *(_BYTE *)(v13 + 1392) )
        v19 = "true";
      else
        v19 = "false";
      ((void (__fastcall *)(__int64, const char *, const char *))sde_kms_info_add_keystr)(a2, "dyn bitclk support", v19);
      v20 = *(_DWORD *)(v13 + 1412);
      if ( v20 > 1 )
      {
        if ( v20 == 2 )
        {
          v21 = "horz flip";
          goto LABEL_43;
        }
        if ( v20 == 3 )
        {
          v21 = "vert flip";
          goto LABEL_43;
        }
      }
      else
      {
        if ( !v20 )
        {
          v21 = "none";
          goto LABEL_43;
        }
        if ( v20 == 1 )
        {
          v21 = "horz & vert flip";
LABEL_43:
          ((void (__fastcall *)(__int64, const char *, const char *))sde_kms_info_add_keystr)(
            a2,
            "panel orientation",
            v21);
LABEL_44:
          v23 = *(_DWORD *)(v13 + 1472);
          if ( v23 == 2 )
          {
            v24 = "dcs";
          }
          else if ( v23 == 1 )
          {
            v24 = "wled";
          }
          else
          {
            if ( v23 )
            {
              _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: invalid panel backlight type:%d\n", v23);
              goto LABEL_52;
            }
            v24 = "pwm";
          }
          ((void (__fastcall *)(__int64, const char *, const char *, long double))sde_kms_info_add_keystr)(
            a2,
            "backlight type",
            v24,
            v22);
LABEL_52:
          sde_kms_info_add_keyint(a2, (__int64)"max os brightness", *(unsigned int *)(v13 + 1488));
          v25 = sde_kms_info_add_keyint(a2, (__int64)"max panel backlight", *(unsigned int *)(v13 + 1484));
          if ( *(_BYTE *)(v13 + 2188) == 1 )
          {
            v26 = *(unsigned int *)(v13 + 2192);
            if ( (unsigned int)v26 >= 5
              || (v25 = ((__int64 (__fastcall *)(__int64, const char *, _QWORD))sde_kms_info_add_keystr)(
                          a2,
                          "spr_pack_type",
                          *(&msm_spr_pack_type_str + v26)),
                  v27 = *(unsigned int *)(v13 + 2196),
                  (unsigned int)v27 > 8) )
            {
              __break(0x5512u);
              return dsi_conn_set_submode_blob_info(v25);
            }
            ((void (__fastcall *)(__int64, const char *, char *))sde_kms_info_add_keystr)(
              a2,
              "spr_pack_type_mode",
              msm_spr_pack_type_mode_str[v27]);
          }
          if ( a4 && *(_BYTE *)(a4 + 744) == 1 && !*(_DWORD *)(*(_QWORD *)(a3 + 264) + 2236LL) )
          {
            sde_kms_info_add_keyint(a2, (__int64)"partial_update_num_roi", *(unsigned int *)(a4 + 748));
            sde_kms_info_add_keyint(a2, (__int64)"partial_update_xstart", *(unsigned int *)(a4 + 752));
            sde_kms_info_add_keyint(a2, (__int64)"partial_update_walign", *(unsigned int *)(a4 + 756));
            sde_kms_info_add_keyint(a2, (__int64)"partial_update_wmin", *(unsigned int *)(a4 + 768));
            sde_kms_info_add_keyint(a2, (__int64)"partial_update_ystart", *(unsigned int *)(a4 + 760));
            sde_kms_info_add_keyint(a2, (__int64)"partial_update_halign", *(unsigned int *)(a4 + 764));
            sde_kms_info_add_keyint(a2, (__int64)"partial_update_hmin", *(unsigned int *)(a4 + 772));
            sde_kms_info_add_keyint(a2, (__int64)"partial_update_roimerge", *(unsigned __int8 *)(a4 + 745));
          }
          v28 = dsi_ctrl_pixel_format_to_bpp(*(_DWORD *)(a3 + 892));
          sde_kms_info_add_keyint(a2, (__int64)"bit_depth", v28);
          if ( *(_BYTE *)(*(_QWORD *)(a3 + 264) + 2212LL) == 1 )
          {
            ((void (__fastcall *)(__int64, const char *, const char *))sde_kms_info_add_keystr)(
              a2,
              "dpu_ctl_op_sync",
              "true");
            ((void (__fastcall *)(__int64, const char *, const char *))sde_kms_info_add_keystr)(
              a2,
              "has_disp_in_other_core",
              "true");
          }
          return 0;
        }
      }
      *(double *)&v22 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: invalid panel rotation:%d\n", v20);
      goto LABEL_44;
    }
LABEL_11:
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: invalid panel data\n", *(double *)&v12);
    return 0;
  }
  return result;
}
