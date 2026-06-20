__int64 __fastcall sme_qos_request_reassoc(
        __int64 a1,
        unsigned int a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w21
  __int64 v14; // x5
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  unsigned int v24; // w22
  __int64 v25; // x23
  unsigned int operation_chan_freq_vdev_id; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 result; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x19
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x8
  int v54; // w9
  __int64 v55; // x19
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x8
  int v65; // w9
  __int64 v66; // x19
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x8
  int v76; // w9
  __int64 v77; // x19
  __int64 v78; // x8
  int v79; // w9
  __int64 v80; // [xsp+0h] [xbp-10h] BYREF
  __int64 v81; // [xsp+8h] [xbp-8h]

  v11 = (unsigned __int8)a2;
  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *a3;
  WORD2(v80) = 0;
  LODWORD(v80) = 0;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Invoked on session %d with UAPSD mask 0x%X",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "sme_qos_request_reassoc",
    (unsigned __int8)a2,
    v14,
    v80,
    v81);
  if ( v11 <= 5
    && (v23 = *(_QWORD *)(a1 + 17296)) != 0
    && (v24 = (unsigned __int8)a2, (*(_BYTE *)(v23 + 96LL * (unsigned __int8)a2 + 1) & 1) != 0) )
  {
    v25 = qword_91F2D8;
    wlan_mlme_get_bssid_vdev_id(*(_QWORD *)(a1 + 21632), a2, &v80);
    operation_chan_freq_vdev_id = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), a2);
    result = wlan_cm_roam_invoke(
               *(_QWORD *)(a1 + 21632),
               a2,
               (unsigned __int8 *)&v80,
               operation_chan_freq_vdev_id,
               1u,
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               v33,
               v34);
    if ( !(_DWORD)result )
    {
      v44 = v25 + 3040LL * (unsigned __int8)a2;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: AC[%d] is in state [%d]",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "sme_qos_request_reassoc",
        0,
        *(unsigned int *)(v44 + 8));
      if ( *(_DWORD *)(v44 + 8) != 5 )
      {
        v53 = qword_91F2D8 + 3040LL * v24;
        v54 = *(_DWORD *)(v53 + 8);
        *(_DWORD *)(v53 + 8) = 5;
        *(_DWORD *)(v53 + 12) = v54;
      }
      v55 = v25 + 3040LL * v24;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: AC[%d] is in state [%d]",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "sme_qos_request_reassoc",
        1,
        *(unsigned int *)(v55 + 736));
      if ( *(_DWORD *)(v55 + 736) != 5 )
      {
        v64 = qword_91F2D8 + 3040LL * v24;
        v65 = *(_DWORD *)(v64 + 736);
        *(_DWORD *)(v64 + 736) = 5;
        *(_DWORD *)(v64 + 740) = v65;
      }
      v66 = v25 + 3040LL * v24;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: AC[%d] is in state [%d]",
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        "sme_qos_request_reassoc",
        2,
        *(unsigned int *)(v66 + 1464));
      if ( *(_DWORD *)(v66 + 1464) != 5 )
      {
        v75 = qword_91F2D8 + 3040LL * v24;
        v76 = *(_DWORD *)(v75 + 1464);
        *(_DWORD *)(v75 + 1464) = 5;
        *(_DWORD *)(v75 + 1468) = v76;
      }
      v77 = v25 + 3040LL * v24;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: AC[%d] is in state [%d]",
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        "sme_qos_request_reassoc",
        3,
        *(unsigned int *)(v77 + 2192));
      result = 0;
      if ( *(_DWORD *)(v77 + 2192) != 5 )
      {
        v78 = qword_91F2D8 + 3040LL * v24;
        v79 = *(_DWORD *)(v78 + 2192);
        *(_DWORD *)(v78 + 2192) = 5;
        *(_DWORD *)(v78 + 2196) = v79;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Invalid session for sessionId: %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "sme_qos_request_reassoc",
      v11);
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
