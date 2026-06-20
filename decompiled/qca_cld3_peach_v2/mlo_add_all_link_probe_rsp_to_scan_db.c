__int64 __fastcall mlo_add_all_link_probe_rsp_to_scan_db(__int64 a1, unsigned __int8 *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w8
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int bvmlie_persta_partner_info; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w19
  __int64 v32; // x0
  char *v33; // x23
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x21
  unsigned int *v44; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x24
  unsigned int v62; // w22
  unsigned __int64 v63; // x21
  unsigned int v64; // w0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 v89; // x0
  __int64 v90; // x0
  __int64 v91; // [xsp+8h] [xbp-F8h] BYREF
  __int64 v92; // [xsp+10h] [xbp-F0h]
  __int64 v93; // [xsp+18h] [xbp-E8h]
  __int64 v94; // [xsp+20h] [xbp-E0h] BYREF
  int v95[2]; // [xsp+28h] [xbp-D8h]
  unsigned __int64 v96; // [xsp+30h] [xbp-D0h] BYREF
  unsigned __int8 *v97; // [xsp+38h] [xbp-C8h] BYREF
  unsigned int v98; // [xsp+40h] [xbp-C0h] BYREF
  unsigned __int16 v99; // [xsp+44h] [xbp-BCh]
  __int64 v100; // [xsp+48h] [xbp-B8h] BYREF
  __int128 v101; // [xsp+50h] [xbp-B0h]
  __int64 v102; // [xsp+60h] [xbp-A0h]
  __int64 v103; // [xsp+68h] [xbp-98h]
  __int64 v104; // [xsp+70h] [xbp-90h]
  __int64 v105; // [xsp+78h] [xbp-88h]
  __int128 v106; // [xsp+80h] [xbp-80h]
  __int64 v107; // [xsp+90h] [xbp-70h]
  __int64 v108; // [xsp+98h] [xbp-68h]
  __int64 v109; // [xsp+A0h] [xbp-60h]
  __int64 v110; // [xsp+A8h] [xbp-58h]
  __int128 v111; // [xsp+B0h] [xbp-50h]
  __int64 v112; // [xsp+C0h] [xbp-40h]
  __int64 v113; // [xsp+C8h] [xbp-38h]
  __int64 v114; // [xsp+D0h] [xbp-30h]
  __int64 v115; // [xsp+D8h] [xbp-28h]
  __int64 v116; // [xsp+E0h] [xbp-20h]
  __int64 v117; // [xsp+E8h] [xbp-18h]
  __int64 v118; // [xsp+F0h] [xbp-10h]
  __int64 v119; // [xsp+F8h] [xbp-8h]

  v119 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v96 = 0;
  v97 = nullptr;
  v117 = 0;
  v118 = 0;
  v115 = 0;
  v116 = 0;
  v113 = 0;
  v114 = 0;
  v112 = 0;
  v110 = 0;
  v111 = 0u;
  v108 = 0;
  v109 = 0;
  v107 = 0;
  v105 = 0;
  v106 = 0u;
  v103 = 0;
  v104 = 0;
  v102 = 0;
  v100 = 0;
  v101 = 0u;
  v93 = 0;
  v94 = 0;
  v91 = 0;
  v92 = 0;
  v99 = 0;
  v98 = 0;
  wlan_cm_add_frame_to_scan_db(a1, a2);
  v12 = *((_DWORD *)a2 + 1);
  if ( v12 <= 0x23 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: No IEs in probe rsp",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "mlo_add_all_link_probe_rsp_to_scan_db");
    result = 16;
LABEL_22:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( (unsigned int)util_find_mlie((unsigned __int8 *)(*((_QWORD *)a2 + 1) + 36LL), v12 - 36, &v97, &v96) )
  {
    result = 0;
    goto LABEL_22;
  }
  bvmlie_persta_partner_info = util_get_bvmlie_persta_partner_info(
                                 v97,
                                 v96,
                                 &v100,
                                 0xFFu,
                                 v14,
                                 v15,
                                 v16,
                                 v17,
                                 v18,
                                 v19,
                                 v20,
                                 v21);
  if ( bvmlie_persta_partner_info )
  {
    v31 = bvmlie_persta_partner_info;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Per STA profile parsing failed",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "mlo_add_all_link_probe_rsp_to_scan_db");
LABEL_21:
    result = v31;
    goto LABEL_22;
  }
  v32 = _qdf_mem_malloc(0x900u, "mlo_add_all_link_probe_rsp_to_scan_db", 1700);
  *(_QWORD *)v95 = v32;
  if ( !v32 )
  {
    result = 2;
    goto LABEL_22;
  }
  v33 = (char *)v32;
  v34 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 77);
  if ( !v34 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev object is NULL",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "mlo_add_all_link_probe_rsp_to_scan_db");
    v31 = 29;
    goto LABEL_20;
  }
  v43 = v34;
  qdf_mem_copy(&v98, (const void *)(v34 + 74), 6u);
  wlan_objmgr_vdev_release_ref(v43, 0x4Du, v44, v45, v46, v47, v48, v49, v50, v51, v52);
  if ( !(_BYTE)v100 )
    goto LABEL_19;
  v61 = *((_QWORD *)a2 + 1);
  v62 = BYTE6(v101);
  v63 = (unsigned int)(*((_DWORD *)a2 + 1) - 24);
  v64 = util_gen_link_probe_rsp(
          (char *)(v61 + 24),
          v63,
          BYTE6(v101),
          v98 | ((unsigned __int64)v99 << 32),
          v33,
          0x900u,
          &v94,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60);
  if ( v64 )
  {
LABEL_11:
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: MLO: Link %d probe resp gen failed %d",
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      "mlo_add_all_link_probe_rsp_to_scan_db",
      v62,
      v64);
    v31 = 16;
LABEL_20:
    _qdf_mem_free(*(__int64 *)v95);
    goto LABEL_21;
  }
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: MLO: link probe rsp size:%u orig probe rsp :%u",
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    "mlo_add_all_link_probe_rsp_to_scan_db",
    (unsigned int)v94,
    (unsigned int)v63);
  LOBYTE(v91) = *a2;
  v92 = *(_QWORD *)v95;
  HIDWORD(v91) = v94;
  LODWORD(v93) = -80;
  wlan_cm_add_frame_to_scan_db(a1, (unsigned __int8 *)&v91);
  if ( (unsigned __int8)v100 < 2u )
    goto LABEL_19;
  v62 = BYTE6(v106);
  v64 = util_gen_link_probe_rsp(
          (char *)(v61 + 24),
          v63,
          BYTE6(v106),
          v98 | ((unsigned __int64)v99 << 32),
          *(char **)v95,
          0x900u,
          &v94,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80);
  if ( v64 )
    goto LABEL_11;
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: MLO: link probe rsp size:%u orig probe rsp :%u",
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    "mlo_add_all_link_probe_rsp_to_scan_db",
    (unsigned int)v94,
    (unsigned int)v63);
  LOBYTE(v91) = *a2;
  v92 = *(_QWORD *)v95;
  HIDWORD(v91) = v94;
  LODWORD(v93) = -80;
  wlan_cm_add_frame_to_scan_db(a1, (unsigned __int8 *)&v91);
  if ( (unsigned __int8)v100 < 3u )
    goto LABEL_19;
  v62 = BYTE6(v111);
  v64 = util_gen_link_probe_rsp(
          (char *)(v61 + 24),
          v63,
          BYTE6(v111),
          v98 | ((unsigned __int64)v99 << 32),
          *(char **)v95,
          0x900u,
          &v94,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          v88);
  if ( v64 )
    goto LABEL_11;
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: MLO: link probe rsp size:%u orig probe rsp :%u",
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    "mlo_add_all_link_probe_rsp_to_scan_db",
    (unsigned int)v94,
    (unsigned int)v63);
  LOBYTE(v91) = *a2;
  v92 = *(_QWORD *)v95;
  HIDWORD(v91) = v94;
  LODWORD(v93) = -80;
  v89 = wlan_cm_add_frame_to_scan_db(a1, (unsigned __int8 *)&v91);
  if ( (unsigned __int8)v100 <= 3u )
  {
LABEL_19:
    v31 = 0;
    goto LABEL_20;
  }
  __break(0x5512u);
  v90 = ((__int64 (__fastcall *)(__int64))unk_7AD5A8)(v89);
  return mlo_is_enable_roaming_on_connected_sta_allowed(v90);
}
