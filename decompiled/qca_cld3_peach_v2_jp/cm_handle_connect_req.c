__int64 __fastcall cm_handle_connect_req(
        __int64 a1,
        unsigned __int8 **a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v15; // x0
  __int64 v16; // x19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x4
  __int64 v26; // x5
  const char *v27; // x2
  __int64 ext_hdl; // x0
  __int64 v29; // x22
  __int64 v30; // x0
  unsigned __int8 *ext_ie_ptr_from_ext_id; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned __int8 *ie_ptr_from_eid; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // w0

  result = 16;
  if ( !a1 || !a2 )
    return result;
  v12 = *(_QWORD *)(a1 + 152);
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: psoc not found",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "cm_handle_connect_req",
      *(unsigned __int8 *)a2,
      *((unsigned int *)a2 + 1));
    return 4;
  }
  if ( !mlme_get_psoc_ext_obj_fl(v13) )
    return 4;
  v15 = _qdf_mem_malloc(0x68u, "cm_handle_connect_req", 1414);
  if ( !v15 )
    return 2;
  v16 = v15;
  if ( (unsigned int)cm_copy_join_params(v15, a2) )
  {
    v25 = *(unsigned __int8 *)a2;
    v26 = *((unsigned int *)a2 + 1);
    v27 = "%s: vdev %d cm_id 0x%x: Failed to copy join req";
LABEL_22:
    qdf_trace_msg(0x68u, 2u, v27, v17, v18, v19, v20, v21, v22, v23, v24, "cm_handle_connect_req", v25, v26);
    cm_free_join_req(v16);
    return 16;
  }
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, v17, v18, v19, v20, v21, v22, v23, v24);
  if ( ext_hdl )
  {
    v29 = ext_hdl;
    v30 = *(_QWORD *)(ext_hdl + 24064);
    *(_DWORD *)(v29 + 24072) = 0;
    if ( v30 )
    {
      _qdf_mem_free(v30);
      *(_QWORD *)(v29 + 24064) = 0;
    }
  }
  ext_ie_ptr_from_ext_id = wlan_get_ext_ie_ptr_from_ext_id(&unk_89A9F4, 1u, a2[4], *((_DWORD *)a2 + 6));
  if ( ext_ie_ptr_from_ext_id )
    cm_update_hlp_info(
      a1,
      ext_ie_ptr_from_ext_id,
      ext_ie_ptr_from_ext_id[1] + 2,
      0,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39);
  ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0xF2u, a2[4], *((_DWORD *)a2 + 6));
  if ( ie_ptr_from_eid )
    cm_update_hlp_info(a1, ie_ptr_from_eid, ie_ptr_from_eid[1] + 2, 0, v41, v42, v43, v44, v45, v46, v47, v48);
  v49 = cm_csr_handle_join_req(a1, a2, v16, 0);
  v25 = *(unsigned __int8 *)a2;
  v26 = *((unsigned int *)a2 + 1);
  if ( v49 )
  {
    v27 = "%s: vdev %d cm_id 0x%x: fail to fill params from legacy";
    goto LABEL_22;
  }
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev %d cm_id 0x%x: HT cap %x",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "cm_handle_connect_req",
    v25,
    v26,
    *((unsigned __int16 *)a2 + 5));
  wlan_rec_debug_log(
    (char *)&off_0 + 1,
    *(_BYTE *)a2,
    0x10u,
    0,
    (const void *)(*((_QWORD *)a2[7] + 3) + 1LL),
    0,
    *(_DWORD *)(*((_QWORD *)a2[7] + 3) + 1140LL),
    *(_DWORD *)(*((_QWORD *)a2[7] + 3) + 1064LL));
  cm_process_join_req(v16);
  result = 0;
  if ( !*(_DWORD *)(a1 + 16) )
  {
    wlan_register_txrx_packetdump();
    return 0;
  }
  return result;
}
