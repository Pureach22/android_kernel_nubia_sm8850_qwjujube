__int64 __fastcall p2p_psoc_object_open(
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
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  int v20; // w10
  char v21; // w8
  char v22; // w8
  unsigned int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w20
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x1
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7

  if ( !a1 )
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: psoc context passed is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_psoc_object_open");
    return 4;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: p2p soc private object is NULL",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "p2p_psoc_object_open");
    return 16;
  }
  v19 = comp_private_obj;
  *(_DWORD *)(comp_private_obj + 264) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10472);
  *(_DWORD *)(v19 + 268) = *(_DWORD *)(cfg_psoc_get_values(a1) + 10476);
  *(_BYTE *)(v19 + 272) = *(_BYTE *)(v19 + 272) & 0xFE | *(_BYTE *)(cfg_psoc_get_values(a1) + 10480);
  *(_BYTE *)(v19 + 272) = *(_BYTE *)(v19 + 272) & 0xFD | (2 * *(_BYTE *)(cfg_psoc_get_values(a1) + 10468));
  *(_BYTE *)(v19 + 272) = *(_BYTE *)(v19 + 272) & 0xFB | (4 * *(_BYTE *)(cfg_psoc_get_values(a1) + 10481));
  *(_BYTE *)(v19 + 272) = *(_BYTE *)(v19 + 272) & 0xF7 | (8 * *(_BYTE *)(cfg_psoc_get_values(a1) + 10482));
  v20 = *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 10483);
  v21 = *(_BYTE *)(v19 + 272) & 0xEF | (16 * v20);
  *(_BYTE *)(v19 + 272) = v21;
  if ( v20 )
    v22 = v21 & 0xDF;
  else
    v22 = *(_BYTE *)(v19 + 272) & 0xDF | (32 * *(_BYTE *)(cfg_psoc_get_values(a1) + 10484));
  *(_BYTE *)(v19 + 272) = v22;
  *(_QWORD *)(v19 + 8) = v19 + 8;
  *(_QWORD *)(v19 + 16) = v19 + 8;
  *(_QWORD *)(v19 + 24) = 0x1400000000LL;
  *(_QWORD *)(v19 + 32) = v19 + 32;
  *(_QWORD *)(v19 + 40) = v19 + 32;
  *(_QWORD *)(v19 + 48) = 0x1400000000LL;
  *(_QWORD *)(v19 + 56) = v19 + 56;
  *(_QWORD *)(v19 + 64) = v19 + 56;
  *(_QWORD *)(v19 + 72) = 0x1400000000LL;
  v24 = qdf_event_create((_DWORD *)(v19 + 96));
  if ( v24 )
  {
    v33 = v24;
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: failed to create cleanup roc done event",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "p2p_psoc_object_open");
    if ( *(_DWORD *)(v19 + 72) )
LABEL_10:
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: list length not equal to zero",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "qdf_list_destroy");
  }
  else
  {
    v42 = qdf_event_create((_DWORD *)(v19 + 136));
    if ( !v42 )
    {
      _qdf_runtime_lock_init((__int64 *)(v19 + 176), "&p2p_soc_obj->roc_runtime_lock");
      *(_DWORD *)(v19 + 216) = -1;
      *(_DWORD *)(v19 + 292) = -1;
      qdf_idr_create(v19 + 224);
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: p2p psoc object open successful",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "p2p_psoc_object_open");
      return 0;
    }
    v33 = v42;
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: failed to create cleanup roc done event",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "p2p_psoc_object_open");
    qdf_event_destroy(v19 + 96, v51);
    if ( *(_DWORD *)(v19 + 72) )
      goto LABEL_10;
  }
  if ( *(_DWORD *)(v19 + 48) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: list length not equal to zero",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "qdf_list_destroy");
  if ( *(_DWORD *)(v19 + 24) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: list length not equal to zero",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "qdf_list_destroy");
  return v33;
}
