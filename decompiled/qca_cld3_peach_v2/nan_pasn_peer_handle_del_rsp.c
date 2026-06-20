__int64 __fastcall nan_pasn_peer_handle_del_rsp(
        __int64 a1,
        unsigned __int8 *a2,
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
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 comp_private_obj; // x0
  _QWORD *v27; // x19
  char is_peer_migrated; // w22
  _QWORD *peer_by_mac; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x24
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w23
  const char *v49; // x2
  _DWORD *v50; // x8
  __int64 v51; // x0
  __int64 v52; // x20
  __int64 v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned __int8 v62; // w8
  unsigned int *v63; // x8
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  const char *v72; // x2
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 result; // x0
  __int64 (__fastcall *v82)(_QWORD); // x8
  __int64 v83; // x0
  _DWORD *v84; // x10
  unsigned __int64 v85; // x1
  unsigned int v86; // [xsp+10h] [xbp-10h] BYREF
  unsigned __int16 v87; // [xsp+14h] [xbp-Ch]
  __int64 v88; // [xsp+18h] [xbp-8h]

  v88 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v14 = *a2;
    v15 = a2[1];
    v16 = a2[2];
    v17 = a2[5];
  }
  else
  {
    v16 = 0;
    v14 = 0;
    v15 = 0;
    v17 = 0;
  }
  v87 = 0;
  v86 = 0;
  qdf_trace_msg(
    0x53u,
    8u,
    "%s: Received peer delete response for %02x:%02x:%02x:**:**:%02x and vdev id %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "nan_pasn_peer_handle_del_rsp",
    v14,
    v15,
    v16,
    v17,
    (unsigned __int8)a3);
  if ( !a1 )
  {
    v49 = "%s: psoc is NULL";
LABEL_27:
    result = qdf_trace_msg(0x53u, 2u, v49, v18, v19, v20, v21, v22, v23, v24, v25, "nan_pasn_peer_handle_del_rsp");
    goto LABEL_28;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
    v49 = "%s: psoc_nan_obj is NULL";
    goto LABEL_27;
  }
  v27 = (_QWORD *)comp_private_obj;
  if ( !*(_QWORD *)(comp_private_obj + 176) )
  {
    v49 = "%s: NAN PASN peer delete ops is NULL";
    goto LABEL_27;
  }
  qdf_mem_copy(&v86, a2, 6u);
  is_peer_migrated = nan_is_peer_migrated(a1, a3, (__int64)&v86);
  if ( (is_peer_migrated & 1) == 0 )
  {
    v48 = 0;
    goto LABEL_16;
  }
  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, &v86, 0x14u);
  if ( !peer_by_mac )
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: peer is null",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "nan_get_ndi_vdev_id_from_migrated_peer");
LABEL_26:
    v49 = "%s: vdev id is invalid";
    goto LABEL_27;
  }
  v38 = (__int64)peer_by_mac;
  v39 = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0xFu);
  if ( !v39 )
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: NAN peer priv obj is null",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "nan_get_ndi_vdev_id_from_migrated_peer");
    wlan_objmgr_peer_release_ref(v38, 0x14u, v73, v74, v75, v76, v77, v78, v79, v80);
    goto LABEL_26;
  }
  v48 = *(unsigned __int8 *)(v39 + 72);
  wlan_objmgr_peer_release_ref(v38, 0x14u, v40, v41, v42, v43, v44, v45, v46, v47);
  if ( v48 == 255 )
    goto LABEL_26;
LABEL_16:
  v50 = (_DWORD *)v27[22];
  if ( *(v50 - 1) != -232243948 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD, unsigned int *, __int64, __int64))v50)(a1, a3, &v86, 13, 1);
  v51 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_opmode_from_psoc)(a1, 16, 20);
  if ( !v51 )
  {
    v49 = "%s: Failed to get nan vdev";
    goto LABEL_27;
  }
  v52 = v51;
  v53 = wlan_objmgr_vdev_get_comp_private_obj(v51, 0xFu);
  if ( !v53 )
  {
    v72 = "%s: NAN vdev priv obj is null";
LABEL_30:
    qdf_trace_msg(0x53u, 2u, v72, v54, v55, v56, v57, v58, v59, v60, v61, "nan_update_pasn_peer_count");
    goto LABEL_31;
  }
  if ( !*(_BYTE *)(v53 + 105) )
  {
    v72 = "%s: No PASN peers present";
    goto LABEL_30;
  }
  v62 = *(_BYTE *)(v53 + 105) - 1;
  *(_BYTE *)(v53 + 105) = v62;
  qdf_trace_msg(
    0x53u,
    8u,
    "%s: Pasn peer count:%d",
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    "nan_update_pasn_peer_count",
    v62);
LABEL_31:
  result = wlan_objmgr_vdev_release_ref(v52, 0x14u, v63, v64, v65, v66, v67, v68, v69, v70, v71);
  v82 = (__int64 (__fastcall *)(_QWORD))v27[4];
  if ( v82 )
  {
    v83 = v27[39];
    if ( *((_DWORD *)v82 - 1) != 251140989 )
      __break(0x8228u);
    result = v82(v83);
  }
  if ( (is_peer_migrated & 1) != 0 )
  {
    v84 = (_DWORD *)v27[13];
    v85 = v86 | ((unsigned __int64)v87 << 32);
    if ( *(v84 - 1) != 1150619683 )
      __break(0x822Au);
    result = ((__int64 (__fastcall *)(_QWORD, unsigned __int64))v84)(v48, v85);
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
