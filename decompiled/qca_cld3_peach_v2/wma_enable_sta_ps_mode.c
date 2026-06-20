__int64 __fastcall wma_enable_sta_ps_mode(
        int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v10; // w19
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x22
  __int64 *v21; // x21
  __int64 v22; // x0
  __int64 v23; // x4
  int v24; // w8
  __int64 *v25; // x20
  __int64 v26; // x20
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v35; // x2
  const char *v36; // x3
  unsigned int v37; // w8
  int v38; // w23
  unsigned int v39; // w20
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 *v48; // x21
  __int64 v49; // x20
  unsigned int v50; // w21
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x5
  __int64 v68; // [xsp+0h] [xbp-20h] BYREF
  _BYTE v69[12]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v70; // [xsp+18h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = a1[2];
  result = (__int64)_cds_get_context(54, (__int64)"wma_enable_sta_ps_mode", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v20 = *(_QWORD *)(result + 520) + 488LL * v10;
    if ( !v20 || !*(_QWORD *)v20 )
    {
      v35 = "%s: vdev is NULL for vdev_%d";
      goto LABEL_16;
    }
    v21 = (__int64 *)result;
    v22 = *(_QWORD *)v20;
    *(_QWORD *)v69 = 0;
    result = wlan_pmo_get_ps_params(v22, v69);
    if ( !(_DWORD)result )
    {
      v23 = *(unsigned int *)v69;
      if ( *(_DWORD *)v69 >= 3u )
      {
        v35 = "%s: Invalid opm_mode:%d";
        v36 = "wma_wlan_pmo_get_ps_params";
        goto LABEL_17;
      }
      v24 = *a1;
      v68 = *(_QWORD *)v69;
      if ( v24 == 1 )
      {
        v37 = *((unsigned __int8 *)a1 + 4);
        v38 = *(_DWORD *)v69;
        v39 = v37 & 0x80
            | (v37 >> 4) & 2
            | ((v37 & 2) != 0)
            | (4 * (v37 & 1)) & 0xEF
            | (v37 >> 1) & 8
            | (unsigned __int8)(16 * ((v37 & 4) != 0))
            | (v37 >> 1) & 0x20
            | (8 * (_BYTE)v37) & 0x40;
        if ( *(_DWORD *)(v20 + 212) == v39 )
        {
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: Already Uapsd Enabled vdevId %d Mask %d",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            "wma_enable_sta_ps_mode",
            v10,
            v37 & 0x80
          | (v37 >> 4) & 2
          | ((v37 & 2) != 0)
          | (4 * (v37 & 1)) & 0xEF
          | (v37 >> 1) & 8
          | (unsigned __int8)(16 * ((v37 & 4) != 0))
          | (v37 >> 1) & 0x20
          | (8 * (_BYTE)v37) & 0x40,
            v68);
        }
        else
        {
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: Enable Uapsd vdevId %d Mask %d",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            "wma_enable_sta_ps_mode",
            v10,
            v37 & 0x80
          | (v37 >> 4) & 2
          | ((v37 & 2) != 0)
          | (4 * (v37 & 1)) & 0xEF
          | (v37 >> 1) & 8
          | (unsigned __int8)(16 * ((v37 & 4) != 0))
          | (v37 >> 1) & 0x20
          | (8 * (_BYTE)v37) & 0x40,
            v68);
          if ( (unsigned int)wma_unified_set_sta_ps_param(*v21, v10, 4u, v39, v40, v41, v42, v43, v44, v45, v46, v47) )
          {
            v35 = "%s: Enable Uapsd Failed vdevId %d";
            goto LABEL_16;
          }
          *(_DWORD *)(v20 + 212) = v39;
        }
        if ( v38 && *(_DWORD *)(v20 + 212) )
        {
          LODWORD(v68) = 0;
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: Qpower is disabled",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            "wma_enable_sta_ps_mode",
            v68);
        }
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: Enable Forced Sleep vdevId %d",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "wma_enable_sta_ps_mode",
          v10);
        v25 = v21;
        result = wma_set_force_sleep(v21, v10, 1, &v68, 1);
        if ( (_DWORD)result )
        {
          v35 = "%s: Enable Forced Sleep Failed vdevId %d";
          goto LABEL_16;
        }
      }
      else
      {
        v25 = v21;
        if ( !v24 )
        {
          if ( *(_DWORD *)v69 && *(_DWORD *)(v20 + 212) )
          {
            LODWORD(v68) = 0;
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: Advanced power save is disabled",
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              "wma_enable_sta_ps_mode",
              v68);
          }
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: Enable Sta Mode Ps vdevId %d",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            "wma_enable_sta_ps_mode",
            v10,
            v68);
          v26 = *v21;
          if ( !_cds_get_context(54, (__int64)"wma_unified_set_sta_ps_param", v27, v28, v29, v30, v31, v32, v33, v34)
            || (wma_is_vdev_valid(v10, v12, v13, v14, v15, v16, v17, v18, v19) & 1) == 0
            || (qdf_trace_msg(
                  0x36u,
                  8u,
                  "%s: Set Sta Ps param vdevId %d Param %d val %d",
                  v12,
                  v13,
                  v14,
                  v15,
                  v16,
                  v17,
                  v18,
                  v19,
                  "wma_unified_set_sta_ps_param",
                  v10,
                  4,
                  0),
                *(_DWORD *)v69 = v10,
                *(_QWORD *)&v69[4] = 4,
                (unsigned int)wmi_unified_sta_ps_cmd_send(v26)) )
          {
            v35 = "%s: Set Uapsd param 0 Failed vdevId %d";
LABEL_16:
            v36 = "wma_enable_sta_ps_mode";
            v23 = v10;
LABEL_17:
            result = qdf_trace_msg(0x36u, 2u, v35, v12, v13, v14, v15, v16, v17, v18, v19, v36, v23);
            goto LABEL_18;
          }
          v25 = v21;
          result = wma_set_force_sleep(v21, v10, 0, &v68, 1);
          if ( (_DWORD)result )
          {
            v35 = "%s: Enable Sta Ps Failed vdevId %d";
            goto LABEL_16;
          }
        }
      }
      if ( *((_BYTE *)v25 + 3951) )
      {
        v48 = v25;
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: Set ITO count to %d for vdevId %d",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "wma_enable_sta_ps_mode");
        v49 = *v25;
        v50 = *((unsigned __int8 *)v48 + 3951);
        if ( _cds_get_context(54, (__int64)"wma_unified_set_sta_ps_param", v51, v52, v53, v54, v55, v56, v57, v58) )
        {
          if ( (wma_is_vdev_valid(v10, v59, v60, v61, v62, v63, v64, v65, v66) & 1) != 0 )
          {
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: Set Sta Ps param vdevId %d Param %d val %d",
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              "wma_unified_set_sta_ps_param",
              v10,
              10,
              v50);
            *(_DWORD *)v69 = v10;
            *(_DWORD *)&v69[4] = 10;
            *(_DWORD *)&v69[8] = v50;
            result = wmi_unified_sta_ps_cmd_send(v49);
            v67 = (unsigned int)result;
            if ( !(_DWORD)result )
              goto LABEL_36;
          }
          else
          {
            v67 = 4;
          }
        }
        else
        {
          v67 = 16;
        }
        result = qdf_trace_msg(
                   0x36u,
                   2u,
                   "%s: Set ITO count failed vdevId %d Error %d",
                   v59,
                   v60,
                   v61,
                   v62,
                   v63,
                   v64,
                   v65,
                   v66,
                   "wma_enable_sta_ps_mode",
                   v10,
                   v67,
                   v68);
        goto LABEL_18;
      }
LABEL_36:
      *(_BYTE *)(v20 + 280) = 1;
    }
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
