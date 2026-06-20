__int64 __fastcall wma_trigger_uapsd_params(
        __int64 *a1,
        unsigned int a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w9
  __int64 v39; // x10
  unsigned int v40; // w8
  __int64 v41; // x9
  const void *vdev_bssid; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x20
  __int64 result; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w20
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  unsigned int v70; // [xsp+0h] [xbp-40h]
  _DWORD v71[2]; // [xsp+Ch] [xbp-34h] BYREF
  __int64 v72; // [xsp+14h] [xbp-2Ch]
  unsigned int v73; // [xsp+1Ch] [xbp-24h]
  __int64 v74; // [xsp+20h] [xbp-20h] BYREF
  int v75; // [xsp+28h] [xbp-18h]
  int v76; // [xsp+2Ch] [xbp-14h]
  _DWORD *v77; // [xsp+30h] [xbp-10h]
  __int64 v78; // [xsp+38h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Trigger uapsd params vdev id %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wma_trigger_uapsd_params",
    a2);
  v70 = a3[3];
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: WMM AC %d User Priority %d SvcIntv %d DelIntv %d SusIntv %d",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "wma_trigger_uapsd_params",
    *a3,
    a3[1],
    a3[2],
    a3[4],
    v70);
  if ( (wmi_service_enabled(*a1, 0x1Cu, v22, v23, v24, v25, v26, v27, v28, v29) & 1) != 0
    && (wmi_service_enabled(*a1, 0x1Du, v30, v31, v32, v33, v34, v35, v36, v37) & 1) != 0 )
  {
    v38 = a3[1];
    v39 = *((_QWORD *)a3 + 1);
    v71[0] = *a3;
    v71[1] = v38;
    v40 = a3[4];
    v41 = a1[65];
    v72 = v39;
    v73 = v40;
    vdev_bssid = (const void *)wma_get_vdev_bssid(*(_QWORD *)(v41 + 488LL * a2), v30, v31, v32, v33, v34, v35, v36, v37);
    if ( vdev_bssid )
    {
      v77 = v71;
      v51 = *a1;
      v75 = 0;
      v74 = a2;
      v76 = 1;
      qdf_mem_copy((char *)&v74 + 4, vdev_bssid, 6u);
      result = wmi_unified_set_sta_uapsd_auto_trig_cmd(v51);
      if ( (_DWORD)result )
      {
        v61 = result;
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Failed to send set uapsd param ret = %d",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "wma_set_sta_uapsd_auto_trig_cmd",
          (unsigned int)result);
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Fail to send uapsd param cmd for vdevid %d ret = %d",
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          "wma_trigger_uapsd_params",
          v61,
          a2);
        result = v61;
      }
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to get bssid for vdev_%d",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "wma_trigger_uapsd_params",
        a2);
      result = 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Trigger uapsd is not supported vdev id %d",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wma_trigger_uapsd_params",
      a2);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
