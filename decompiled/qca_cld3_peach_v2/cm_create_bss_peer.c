__int64 __fastcall cm_create_bss_peer(
        __int64 *a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x8
  __int64 v12; // x21
  __int64 v13; // x8
  __int64 v15; // x0
  const char *v16; // x2
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x8
  __int64 v30; // x2
  char v31; // w8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x1
  __int64 v41; // x19
  char v42; // w8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  _BYTE v51[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v52; // [xsp+8h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51[0] = 0;
  if ( !a1 )
  {
    v16 = "%s: invalid cm_ctx";
    goto LABEL_9;
  }
  if ( !a2 || (v11 = *((_QWORD *)a2 + 127)) == 0 || !*(_QWORD *)(v11 + 24) )
  {
    v16 = "%s: invalid req";
LABEL_9:
    result = qdf_trace_msg(0x68u, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "cm_create_bss_peer");
    goto LABEL_10;
  }
  v12 = *a1;
  v13 = *(_QWORD *)(*a1 + 216);
  if ( v13 )
    v15 = *(_QWORD *)(v13 + 80);
  else
    v15 = 0;
  wlan_psoc_mlme_get_11be_capab(v15, v51);
  if ( v51[0] == 1
    && (wlan_vdev_mlme_is_mlo_vdev(v12, v18, v19, v20, v21, v22, v23, v24, v25) & 1) != 0
    && ((v26 = *(_QWORD *)(v12 + 216)) == 0 ? (v27 = 0) : (v27 = *(_QWORD *)(v26 + 80)),
        (wlan_cm_is_eht_allowed_for_current_security(v27, *(_QWORD *)(*((_QWORD *)a2 + 127) + 24LL), 1) & 1) != 0) )
  {
    cm_set_vdev_link_id(a1, a2);
    v28 = *((_QWORD *)a2 + 127);
    if ( v28 )
    {
      v29 = *(_QWORD *)(v28 + 24);
      if ( v29 )
        v30 = v29 + 1912;
      else
        v30 = 0;
    }
    else
    {
      v30 = 0;
    }
    v31 = *((_BYTE *)a2 + 816) ^ 1;
  }
  else
  {
    v30 = 0;
    v31 = 0;
  }
  result = mlme_cm_bss_peer_create_req(v12, *(_QWORD *)(*((_QWORD *)a2 + 127) + 24LL) + 1LL, v30, v31 & 1);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: peer create request failed %d",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "cm_create_bss_peer",
      *(unsigned __int8 *)(v12 + 168),
      *a2,
      (unsigned int)result);
    result = _qdf_mem_malloc(0x150u, "cm_create_bss_peer", 730);
    if ( result )
    {
      v40 = *a2;
      *(_DWORD *)(result + 52) = 16;
      v41 = result;
      *(_DWORD *)(result + 4) = v40;
      v42 = *(_BYTE *)(*a1 + 168);
      *(_DWORD *)(result + 56) = 4;
      *(_BYTE *)result = v42;
      cm_fill_bss_info_in_connect_rsp_by_cm_id(a1, v40, result);
      wlan_sm_dispatch(a1[9], 0xBu, 0x150u, v41, v43, v44, v45, v46, v47, v48, v49, v50);
      result = _qdf_mem_free(v41);
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
