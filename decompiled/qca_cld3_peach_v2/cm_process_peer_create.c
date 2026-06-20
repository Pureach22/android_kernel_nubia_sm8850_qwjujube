__int64 __fastcall cm_process_peer_create(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned __int8 *v19; // x19
  _QWORD *v20; // x21
  _QWORD *peer_by_mac; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  double v31; // d0
  int v32; // w0
  int v33; // w21
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 result; // x0
  const char *v42; // x4
  unsigned __int8 *v43; // x3
  int v44; // w8
  unsigned int v45; // w20

  _ReadStatusReg(SP_EL0);
  context = _cds_get_context(53, (__int64)"cm_process_peer_create", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !a1 )
  {
    v42 = "msg";
LABEL_12:
    qdf_trace_msg(0x68u, 2u, "%s: %s is NULL", v11, v12, v13, v14, v15, v16, v17, v18, "cm_process_peer_create", v42);
    result = 4;
    goto LABEL_18;
  }
  v19 = *(unsigned __int8 **)(a1 + 8);
  if ( !v19 || !context )
  {
    if ( context )
      v42 = "bodyptr";
    else
      v42 = "mac";
    goto LABEL_12;
  }
  v20 = context;
  peer_by_mac = wlan_objmgr_get_peer_by_mac(context[2703], v19 + 1, 0x4Du);
  if ( peer_by_mac )
  {
    if ( *((_DWORD *)peer_by_mac + 17) == 12 )
    {
      v30 = (__int64)peer_by_mac;
      qdf_trace_msg(
        0x68u,
        4u,
        "%s: vdev:%d Ranging peer exists with same mac: %02x:%02x:%02x:**:**:%02x resume after deleting it",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "cm_process_peer_create",
        *v19,
        v19[1],
        v19[2],
        v19[3],
        v19[6]);
      v31 = wma_remove_existing_pasn_peer(v20[2703], v19);
      v33 = v32;
      wlan_objmgr_peer_release_ref(v30, 0x4Du, v31, v34, v35, v36, v37, v38, v39, v40);
      if ( !v33 )
      {
        result = 0;
        goto LABEL_18;
      }
    }
    else
    {
      wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 0x4Du, v22, v23, v24, v25, v26, v27, v28, v29);
    }
  }
  v43 = v19 + 7;
  v44 = *(_DWORD *)(v19 + 7) | *(unsigned __int16 *)(v19 + 11);
  if ( v44 )
    LOBYTE(v44) = v19[13];
  else
    v43 = nullptr;
  v45 = wma_add_bss_peer_sta(*v19, v19 + 1, 1, v43, v44 & 1);
  _qdf_mem_free((__int64)v19);
  result = v45;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
