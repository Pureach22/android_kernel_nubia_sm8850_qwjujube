__int64 __fastcall cm_disconnect_continue_after_rso_stop(__int64 a1, unsigned int *a2)
{
  __int64 cm_ctx_fl; // x0
  __int64 *v4; // x19
  __int64 req_by_cm_id_fl; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int16 v23; // w9
  __int64 v24; // x21
  int v25; // t1
  bool v26; // zf
  __int16 v27; // w9
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 result; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w21
  unsigned int v46; // w20
  unsigned int v47; // [xsp+20h] [xbp-40h] BYREF
  __int16 v48; // [xsp+24h] [xbp-3Ch]
  _QWORD v49[6]; // [xsp+30h] [xbp-30h] BYREF

  v49[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48 = 0;
  v47 = 0;
  cm_ctx_fl = cm_get_cm_ctx_fl(a1, "cm_disconnect_continue_after_rso_stop", 463);
  if ( cm_ctx_fl
    && (v4 = (__int64 *)cm_ctx_fl,
        (req_by_cm_id_fl = cm_get_req_by_cm_id_fl(cm_ctx_fl, *a2, "cm_disconnect_continue_after_rso_stop", 468)) != 0) )
  {
    v14 = req_by_cm_id_fl;
    wlan_vdev_get_bss_peer_mac(*v4, &v47, v6, v7, v8, v9, v10, v11, v12, v13);
    v23 = v48;
    a2[4] = v47;
    *((_WORD *)a2 + 10) = v23;
    v25 = *(_DWORD *)(v14 + 40);
    v24 = v14 + 40;
    if ( !(v25 | *(unsigned __int16 *)(v24 + 4))
      || (*(_DWORD *)v24 == -1 ? (v26 = *(__int16 *)(v24 + 4) == -1) : (v26 = 0), v26) )
    {
      v27 = v48;
      *(_DWORD *)v24 = v47;
      *(_WORD *)(v24 + 4) = v27;
    }
    cm_update_scan_mlme_on_disconnect(*v4, (unsigned int *)(v24 - 16), v15, v16, v17, v18, v19, v20, v21, v22);
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev %d cm_id 0x%x: disconnect %02x:%02x:%02x:**:**:%02x source %d reason %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "cm_disconnect_continue_after_rso_stop",
      *((unsigned __int8 *)a2 + 4),
      *a2,
      *((unsigned __int8 *)a2 + 16),
      *((unsigned __int8 *)a2 + 17),
      *((unsigned __int8 *)a2 + 18),
      *((unsigned __int8 *)a2 + 21),
      a2[2],
      a2[3]);
    result = mlme_cm_disconnect_req(*v4, a2);
    if ( (_DWORD)result )
    {
      v45 = result;
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d cm_id 0x%x: disconnect req fail",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "cm_disconnect_continue_after_rso_stop",
        *((unsigned __int8 *)a2 + 4),
        *a2);
      v46 = *a2;
      memset(v49, 0, 40);
      qdf_mem_set(v49, 0x28u, 0);
      if ( !(unsigned int)cm_fill_disconnect_resp_from_cm_id(v4, v46, v49) )
        cm_disconnect_complete(v4, (unsigned int *)v49);
      result = v45;
    }
  }
  else
  {
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
