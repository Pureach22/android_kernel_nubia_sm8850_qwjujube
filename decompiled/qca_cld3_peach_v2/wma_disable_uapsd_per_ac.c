__int64 __fastcall wma_disable_uapsd_per_ac(
        __int64 *a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x24
  int v24; // w9
  __int64 v25; // x9
  const void *vdev_bssid; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x21
  unsigned int v36; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w21
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  const char *v54; // x2
  unsigned int v55; // w1
  __int64 v56; // x4
  __int64 v57; // x5
  __int64 v58; // x22
  unsigned int v59; // w23
  _DWORD v61[2]; // [xsp+Ch] [xbp-34h] BYREF
  __int64 v62; // [xsp+14h] [xbp-2Ch]
  int v63; // [xsp+1Ch] [xbp-24h]
  __int64 v64; // [xsp+20h] [xbp-20h] BYREF
  unsigned int v65; // [xsp+28h] [xbp-18h]
  int v66; // [xsp+2Ch] [xbp-14h]
  _DWORD *v67; // [xsp+30h] [xbp-10h]
  __int64 v68; // [xsp+38h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = a1[65];
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Disable Uapsd per ac vdevId %d ac %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wma_disable_uapsd_per_ac",
    a2,
    a3);
  if ( a3 >= 4 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid AC vdevId %d ac %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wma_disable_uapsd_per_ac",
      a2,
      a3);
    v45 = 16;
  }
  else
  {
    v23 = v14 + 488LL * a2;
    v24 = dword_B35988[a3];
    *(_DWORD *)(v23 + 212) &= dword_B358E8[a3];
    v61[0] = a3;
    v61[1] = v24;
    v25 = a1[65];
    v62 = 0;
    v63 = 0;
    vdev_bssid = (const void *)wma_get_vdev_bssid(*(_QWORD *)(v25 + 488LL * a2), v15, v16, v17, v18, v19, v20, v21, v22);
    if ( vdev_bssid )
    {
      v67 = v61;
      v35 = *a1;
      v65 = 0;
      v64 = a2;
      v66 = 1;
      qdf_mem_copy((char *)&v64 + 4, vdev_bssid, 6u);
      v36 = wmi_unified_set_sta_uapsd_auto_trig_cmd(v35);
      if ( v36 )
      {
        v45 = v36;
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Failed to send set uapsd param ret = %d",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "wma_set_sta_uapsd_auto_trig_cmd",
          v36);
        v54 = "%s: Fail to send auto trig cmd for vdevid %d ret = %d";
        v55 = 2;
        v56 = v45;
        v57 = a2;
LABEL_13:
        qdf_trace_msg(0x36u, v55, v54, v46, v47, v48, v49, v50, v51, v52, v53, "wma_disable_uapsd_per_ac", v56, v57);
        goto LABEL_14;
      }
      v58 = *a1;
      v59 = *(_DWORD *)(v23 + 212);
      if ( _cds_get_context(54, (__int64)"wma_unified_set_sta_ps_param", v37, v38, v39, v40, v41, v42, v43, v44) )
      {
        v45 = 4;
        if ( (wma_is_vdev_valid(a2, v46, v47, v48, v49, v50, v51, v52, v53) & 1) != 0 )
        {
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: Set Sta Ps param vdevId %d Param %d val %d",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "wma_unified_set_sta_ps_param",
            a2,
            4,
            v59);
          v64 = a2 | 0x400000000LL;
          v65 = v59;
          v45 = wmi_unified_sta_ps_cmd_send(v58);
          if ( !v45 )
          {
            v57 = *(unsigned int *)(v23 + 212);
            v54 = "%s: Disable Uapsd per ac vdevId %d val %d";
            v55 = 8;
            v56 = a2;
            goto LABEL_13;
          }
        }
      }
      else
      {
        v45 = 16;
      }
      v54 = "%s: Disable Uapsd per ac Failed vdevId %d ac %d";
      v55 = 2;
      v56 = a2;
      v57 = a3;
      goto LABEL_13;
    }
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to get bssid for vdev_%d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "wma_disable_uapsd_per_ac",
      a2);
    v45 = 16;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v45;
}
