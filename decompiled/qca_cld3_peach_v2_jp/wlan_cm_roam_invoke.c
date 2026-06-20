__int64 __fastcall wlan_cm_roam_invoke(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        unsigned int a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x23
  unsigned __int8 v16; // w22
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x20
  __int64 v28; // x8
  __int64 v29; // x0
  unsigned int v30; // w1
  unsigned int v31; // w25
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  int v40; // w0
  __int64 v41; // x7
  int v42; // w8
  int v43; // w9
  int v44; // w10
  __int64 result; // x0
  __int64 v46; // x25
  unsigned int *v47; // x8
  unsigned int v48; // w1
  unsigned int v49; // w23
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned int v66; // w19
  unsigned int *v67; // x8
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // [xsp+18h] [xbp-28h] BYREF
  __int64 v77; // [xsp+20h] [xbp-20h]
  __int64 v78; // [xsp+28h] [xbp-18h]
  __int64 v79; // [xsp+30h] [xbp-10h]
  __int64 v80; // [xsp+38h] [xbp-8h]

  v80 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a1 + 80);
  if ( !v13 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: Invalid psoc", a6, a7, a8, a9, a10, a11, a12, a13, "wlan_cm_roam_invoke");
    result = 16;
    goto LABEL_18;
  }
  v16 = a2;
  v18 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)(a1 + 80),
          a2,
          2);
  if ( !v18 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: vdev object is NULL", v19, v20, v21, v22, v23, v24, v25, v26, "wlan_cm_roam_invoke");
    result = 29;
    goto LABEL_18;
  }
  v27 = v18;
  if ( !a4 )
    goto LABEL_8;
  v28 = *(_QWORD *)(v18 + 152);
  if ( v28 && (v29 = *(_QWORD *)(v28 + 80)) != 0 )
  {
    v30 = *(unsigned __int8 *)(v27 + 104);
    v78 = 0;
    v79 = 0;
    v76 = 0;
    v77 = 0;
    wlan_cm_roam_cfg_get_value(v29, v30, 0x1Bu, &v76);
    v31 = v76;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: [ROAM BAND] band mask:%d",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "wlan_cm_get_roam_band_value",
      (unsigned int)v76);
    v40 = wlan_reg_freq_to_band(a4);
    if ( v40 != 3 && ((v31 >> v40) & 1) != 0 )
    {
LABEL_8:
      if ( a3 )
      {
        v41 = *a3;
        v42 = a3[1];
        v43 = a3[2];
        v44 = a3[5];
      }
      else
      {
        v43 = 0;
        v41 = 0;
        v42 = 0;
        v44 = 0;
      }
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev: %d source: %d freq: %d bssid: %02x:%02x:%02x:**:**:%02x",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "wlan_cm_roam_invoke",
        v16,
        a5,
        a4,
        v41,
        v42,
        v43,
        v44);
      v66 = cm_start_roam_invoke(v13, v27, a3, a4, a5);
      wlan_objmgr_vdev_release_ref(v27, 2u, v67, v68, v69, v70, v71, v72, v73, v74, v75);
      result = v66;
      goto LABEL_18;
    }
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: Invalid PSOC", v19, v20, v21, v22, v23, v24, v25, v26, "is_freq_allowed_for_roam");
  }
  v46 = jiffies;
  v47 = (unsigned int *)(wlan_cm_roam_invoke___last_ticks - jiffies);
  if ( wlan_cm_roam_invoke___last_ticks - jiffies + 125 < 0 )
  {
    v48 = *(unsigned __int8 *)(v27 + 104);
    v78 = 0;
    v79 = 0;
    v76 = 0;
    v77 = 0;
    wlan_cm_roam_cfg_get_value(v13, v48, 0x1Bu, &v76);
    v49 = v76;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: [ROAM BAND] band mask:%d",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "wlan_cm_get_roam_band_value",
      (unsigned int)v76);
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev:%d, source:%d, allowed_bands:0x%x, freq:%d NOT allowed to roam",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      "wlan_cm_roam_invoke",
      v16,
      a5,
      v49,
      a4);
    wlan_cm_roam_invoke___last_ticks = v46;
  }
  wlan_objmgr_vdev_release_ref(v27, 2u, v47, v19, v20, v21, v22, v23, v24, v25, v26);
  result = 16;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
