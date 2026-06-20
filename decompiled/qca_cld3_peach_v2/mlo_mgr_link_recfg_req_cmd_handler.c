__int64 __fastcall mlo_mgr_link_recfg_req_cmd_handler(__int64 a1, unsigned __int8 *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 v22; // x19
  unsigned __int8 v23; // w8
  unsigned __int8 v24; // w9
  unsigned __int8 v25; // w8
  unsigned __int8 v26; // w9
  unsigned __int8 v27; // w9
  void *v28; // x0
  __int64 v29; // x1
  unsigned __int8 v30; // w9
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int *v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 result; // x0
  unsigned int *v49; // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  _BYTE s[560]; // [xsp+8h] [xbp-238h] BYREF
  __int64 v59; // [xsp+238h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( !a2 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Invalid params",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "mlo_mgr_link_recfg_req_cmd_handler");
LABEL_16:
    result = 4;
    goto LABEL_17;
  }
  v12 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 90);
  if ( !v12 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Invalid link recfg VDEV %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "mlo_mgr_link_recfg_req_cmd_handler",
      *a2);
    goto LABEL_16;
  }
  v21 = *(_QWORD *)(v12 + 1360);
  v22 = v12;
  if ( !v21 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: mlo_ctx null",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "mlo_mgr_link_recfg_req_cmd_handler");
    wlan_objmgr_vdev_release_ref(v22, 0x5Au, v49, v50, v51, v52, v53, v54, v55, v56, v57);
    goto LABEL_16;
  }
  qdf_mem_set(s, 0x230u, 0);
  v23 = *a2;
  s[264] = 1;
  s[0] = v23;
  qdf_mem_copy(&s[552], a2 + 1, 6u);
  if ( !*((_DWORD *)a2 + 62) )
    goto LABEL_21;
  v24 = a2[8];
  s[128] = *((_DWORD *)a2 + 62);
  v25 = a2[15];
  s[9] = v24;
  s[8] = v25;
  qdf_mem_copy(&s[16], a2 + 9, 6u);
  if ( *((_DWORD *)a2 + 62) <= 1u )
    goto LABEL_21;
  v26 = a2[31];
  s[49] = a2[24];
  s[48] = v26;
  qdf_mem_copy(&s[56], a2 + 25, 6u);
  if ( *((_DWORD *)a2 + 62) < 3u
    || (v27 = a2[47], s[89] = a2[40], s[88] = v27, v28 = qdf_mem_copy(&s[96], a2 + 41, 6u), *((_DWORD *)a2 + 62) <= 3u) )
  {
LABEL_21:
    if ( !*((_DWORD *)a2 + 124) )
      goto LABEL_12;
    v30 = a2[256];
    s[256] = *((_DWORD *)a2 + 124);
    s[137] = v30;
    qdf_mem_copy(&s[144], a2 + 257, 6u);
    if ( *((_DWORD *)a2 + 124) < 2u
      || (s[177] = a2[272], qdf_mem_copy(&s[184], a2 + 273, 6u), *((_DWORD *)a2 + 124) < 3u)
      || (s[217] = a2[288], v28 = qdf_mem_copy(&s[224], a2 + 289, 6u), *((_DWORD *)a2 + 124) <= 3u) )
    {
LABEL_12:
      qdf_mutex_acquire(*(_QWORD *)(v21 + 3888) + 760LL);
      wlan_sm_dispatch(
        *(_QWORD *)(*(_QWORD *)(v21 + 3888) + 824LL),
        0,
        0x230u,
        (__int64)s,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38);
      qdf_mutex_release(*(_QWORD *)(v21 + 3888) + 760LL);
      wlan_objmgr_vdev_release_ref(v22, 0x5Au, v39, v40, v41, v42, v43, v44, v45, v46, v47);
      result = 0;
LABEL_17:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  __break(0x5512u);
  return mlo_link_recfg_find_link_status(v28, v29);
}
