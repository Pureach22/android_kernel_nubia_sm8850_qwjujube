__int64 __fastcall wma_nan_pasn_peer_remove(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 a10,
        unsigned __int8 *a11,
        unsigned __int8 a12,
        char a13)
{
  __int64 *context; // x23
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v42; // w8
  __int64 result; // x0
  __int64 v44; // x4
  __int64 v45; // x5
  __int64 v46; // x6
  __int64 v47; // x7
  const char *v48; // x2
  unsigned int v49; // w0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x22
  __int64 v68; // x8
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  int v77; // [xsp+8h] [xbp-28h]
  _BYTE v78[4]; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v79; // [xsp+18h] [xbp-18h]
  int v80; // [xsp+20h] [xbp-10h]
  __int64 v81; // [xsp+28h] [xbp-8h]

  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(54, (__int64)"wma_nan_pasn_peer_remove", a1, a2, a3, a4, a5, a6, a7, a8);
  v80 = 0;
  v79 = 0;
  v78[0] = 0;
  if ( (cds_get_driver_state(v18, v19, v20, v21, v22, v23, v24, v25) & 8) != 0 )
  {
    result = 16;
    goto LABEL_21;
  }
  if ( !context )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: wma_handle is NULL",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wma_nan_pasn_peer_remove");
    goto LABEL_20;
  }
  if ( ((unsigned __int8)wma_objmgr_peer_exist((__int64)context, (__int64)a11, v78) & 1) == 0 )
  {
    if ( a11 )
    {
      v44 = *a11;
      v45 = a11[1];
      v46 = a11[2];
      v47 = a11[5];
    }
    else
    {
      v46 = 0;
      v44 = 0;
      v45 = 0;
      v47 = 0;
    }
    v42 = a10;
    v48 = "%s: peer doesn't exist peer_addr %02x:%02x:%02x:**:**:%02x vdevid %d";
    goto LABEL_19;
  }
  v42 = v78[0];
  if ( v78[0] != a10 )
  {
    if ( a11 )
    {
      v44 = *a11;
      v45 = a11[1];
      v46 = a11[2];
      v47 = a11[5];
    }
    else
    {
      v46 = 0;
      v44 = 0;
      v45 = 0;
      v47 = 0;
    }
    v48 = "%s: peer %02x:%02x:%02x:**:**:%02x is on vdev id %d but delete req on vdevid %d";
    v77 = a10;
LABEL_19:
    qdf_trace_msg(
      0x36u,
      2u,
      v48,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "wma_nan_pasn_peer_remove",
      v44,
      v45,
      v46,
      v47,
      v42,
      v77);
    goto LABEL_20;
  }
  if ( (a13 & 1) != 0 )
    goto LABEL_6;
  LOBYTE(v79) = a10;
  v49 = wmi_unified_peer_delete_send(*context);
  if ( v49 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Peer delete could not be sent to target %d",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "wma_nan_pasn_peer_remove",
      v49);
    result = 16;
    goto LABEL_21;
  }
  if ( (wmi_service_enabled(*context, 0x6Eu, v50, v51, v52, v53, v54, v55, v56, v57) & 1) == 0 )
  {
LABEL_6:
    wma_remove_objmgr_peer(
      (__int64)context,
      *(_QWORD *)(context[65] + 488LL * a10),
      a11,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41);
    result = 0;
    goto LABEL_21;
  }
  v58 = _qdf_mem_malloc(8u, "wma_nan_pasn_peer_remove", 132);
  if ( !v58 )
  {
LABEL_20:
    result = 4;
    goto LABEL_21;
  }
  v67 = v58;
  *(_BYTE *)v58 = a10;
  *(_DWORD *)(v58 + 4) = 0;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Wait for the peer delete. vdev_id %d",
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    "wma_nan_pasn_peer_remove",
    a10);
  v68 = wma_fill_hold_req(context, a10, 0x1023u, a12, nullptr, v67, 0x1F40u);
  result = 0;
  if ( !v68 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to allocate request vdev_id %d",
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      "wma_nan_pasn_peer_remove",
      a10);
    _qdf_mem_free(v67);
    result = 16;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
