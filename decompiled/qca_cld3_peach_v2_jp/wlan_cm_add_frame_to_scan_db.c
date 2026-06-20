__int64 __fastcall wlan_cm_add_frame_to_scan_db(__int64 a1, unsigned __int8 *a2)
{
  __int64 v3; // x1
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  __int64 v14; // x19
  __int64 cm_ctx_fl; // x0
  unsigned int v16; // w8
  const char *v17; // x2
  __int64 result; // x0
  __int64 v19; // x25
  unsigned __int16 v20; // w22
  __int64 v21; // x24
  unsigned __int8 *ie_ptr_from_eid; // x0
  unsigned __int8 *v23; // x23
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned __int8 *v32; // x26
  unsigned int v33; // w23
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 ext_hdl; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x27
  void *v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned __int8 *ext_ie_ptr_from_ext_id; // x0
  unsigned __int8 *v70; // x23
  unsigned int _6g_oper_channel; // w0
  unsigned int v72; // w23
  unsigned __int8 v73; // w22
  const char *v74; // x2
  unsigned __int8 *v75; // x0
  unsigned __int8 *v76; // x0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  int v85; // w0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  unsigned int *v94; // x8
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  unsigned int *v103; // x8
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  int v112; // [xsp+0h] [xbp-10h] BYREF
  __int16 v113; // [xsp+4h] [xbp-Ch]
  __int64 v114; // [xsp+8h] [xbp-8h]

  v114 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a2;
  v113 = 0;
  v112 = 0;
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v3, 77);
  if ( v4 )
  {
    v13 = *(_QWORD *)(v4 + 152);
    v14 = v4;
    if ( !v13 )
    {
      v17 = "%s: pdev object is NULL";
      goto LABEL_35;
    }
    cm_ctx_fl = cm_get_cm_ctx_fl(
                  v4,
                  (__int64)"wlan_cm_add_frame_to_scan_db",
                  0x1755u,
                  v5,
                  v6,
                  v7,
                  v8,
                  v9,
                  v10,
                  v11,
                  v12);
    if ( !cm_ctx_fl )
    {
      v17 = "%s: cm ctx is NULL";
      goto LABEL_35;
    }
    v16 = *((_DWORD *)a2 + 1);
    if ( v16 < 0x25 )
    {
      v17 = "%s: Invalid frame length";
LABEL_35:
      qdf_trace_msg(0x68u, 2u, v17, v5, v6, v7, v8, v9, v10, v11, v12, "wlan_cm_add_frame_to_scan_db");
      wlan_objmgr_vdev_release_ref(v14, 0x4Du, v103, v104, v105, v106, v107, v108, v109, v110, v111);
      result = 16;
      goto LABEL_36;
    }
    v19 = *((_QWORD *)a2 + 1);
    v20 = v16 - 36;
    v21 = cm_ctx_fl;
    ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0, (unsigned __int8 *)(v19 + 36), (unsigned __int16)v16 - 36);
    if ( a2[20] == 1 && ie_ptr_from_eid && !*ie_ptr_from_eid )
    {
      v23 = ie_ptr_from_eid;
      qdf_mem_copy(&v112, (const void *)(*((_QWORD *)a2 + 1) + 10LL), 6u);
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: SSID of the candidate is %.*s",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "wlan_cm_add_frame_to_scan_db",
        v23[1],
        v23 + 2);
      v32 = v23;
      v33 = v23[1];
      ext_hdl = wlan_vdev_mlme_get_ext_hdl(v14, v34, v35, v36, v37, v38, v39, v40, v41);
      if ( ext_hdl )
      {
        v51 = ext_hdl;
        v52 = (void *)(ext_hdl + 296);
        if ( v33 >= 0x20 )
          v33 = 32;
        qdf_mem_set(v52, 0x21u, 0);
        qdf_mem_copy((void *)(v51 + 297), v32 + 2, v33);
        *(_BYTE *)(v51 + 296) = v33;
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: Set roam offload ssid: %.*s",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "wlan_cm_set_roam_offload_ssid",
          v33,
          v51 + 297);
      }
      else
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev legacy private object is NULL",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "wlan_cm_set_roam_offload_ssid");
      }
      wlan_cm_set_roam_offload_bssid(v14, (unsigned __int16 *)&v112, v61, v62, v63, v64, v65, v66, v67, v68);
    }
    ext_ie_ptr_from_ext_id = wlan_get_ext_ie_ptr_from_ext_id("$", 1u, (unsigned __int8 *)(v19 + 36), v20);
    if ( ext_ie_ptr_from_ext_id
      && (v70 = ext_ie_ptr_from_ext_id, !(unsigned int)qdf_mem_cmp(ext_ie_ptr_from_ext_id + 2, "$", 1u))
      && v70[1] <= 0x10u
      && (_6g_oper_channel = (unsigned int)util_scan_get_6g_oper_channel(v70), (_BYTE)_6g_oper_channel) )
    {
      v72 = _6g_oper_channel;
      v73 = 4;
      v74 = "%s: Extracted primary channel from HE OP : %d";
    }
    else
    {
      v75 = wlan_get_ie_ptr_from_eid(0x3Du, (unsigned __int8 *)(v19 + 36), v20);
      if ( v75 && *v75 == 61 && v75[1] == 22 && (v72 = v75[2]) != 0 )
      {
        v73 = 3;
        v74 = "%s: Extracted primary channel from HT INFO : %d";
      }
      else
      {
        v76 = wlan_get_ie_ptr_from_eid(3u, (unsigned __int8 *)(v19 + 36), v20);
        if ( !v76 || *v76 != 3 || v76[1] != 1 || (v72 = v76[2]) == 0 )
        {
          v17 = "%s: Ignore beacon, Primary channel was not found in the candidate frame";
          goto LABEL_35;
        }
        v73 = 3;
        v74 = "%s: Extracted primary channel from DS : %d";
      }
    }
    qdf_trace_msg(
      0x68u,
      8u,
      v74,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_cm_add_frame_to_scan_db",
      (unsigned __int8)v72);
    v85 = wlan_reg_chan_band_to_freq(v13, v72, v73, v77, v78, v79, v80, v81, v82, v83, v84);
    cm_inform_bcn_probe(
      (__int64 *)v21,
      *((char **)a2 + 1),
      *((_DWORD *)a2 + 1),
      v85,
      *((_DWORD *)a2 + 4),
      *(unsigned int *)(v21 + 88),
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93);
    wlan_objmgr_vdev_release_ref(v14, 0x4Du, v94, v95, v96, v97, v98, v99, v100, v101, v102);
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev object is NULL",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_cm_add_frame_to_scan_db");
    result = 29;
  }
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
