__int64 __fastcall lim_update_stads_ext_cap(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _QWORD *v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x0
  __int64 cmpt_obj; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7

  if ( *(_BYTE *)(a3 + 2318) )
  {
    v14 = (_QWORD *)(a3 + 2320);
    lim_set_stads_rtt_cap(a4, a3 + 2320, a1);
    v23 = *(_QWORD *)(a2 + 16);
    if ( v23 )
    {
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v23, v15, v16, v17, v18, v19, v20, v21, v22);
      if ( cmpt_obj )
        *(_BYTE *)(*(_QWORD *)(cmpt_obj + 520) + 23960LL) = *(_BYTE *)(a4 + 640);
      else
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: vdev component object is NULL",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "lim_update_stads_ext_cap");
    }
    mlme_set_tdls_prohibited(*(_QWORD *)(a2 + 16), (*v14 & 0x4000000000LL) != 0, v15, v16, v17, v18, v19, v20, v21, v22);
    mlme_set_tdls_chan_switch_prohibited(
      *(_QWORD *)(a2 + 16),
      (*v14 & 0x8000000000LL) != 0,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: ExtCap: tdls_prohibited: %d tdls_chan_swit_prohibited: %d",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "lim_update_stads_ext_cap",
      (*v14 >> 38) & 1LL,
      (*v14 >> 39) & 1LL);
    return lim_set_peer_twt_cap(a2, v14);
  }
  else
  {
    *(_BYTE *)(a4 + 640) = 0;
    mlme_set_tdls_prohibited(*(_QWORD *)(a2 + 16), 0, a5, a6, a7, a8, a9, a10, a11, a12);
    mlme_set_tdls_chan_switch_prohibited(*(_QWORD *)(a2 + 16), 0, v25, v26, v27, v28, v29, v30, v31, v32);
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: ExtCap not present",
             v33,
             v34,
             v35,
             v36,
             v37,
             v38,
             v39,
             v40,
             "lim_update_stads_ext_cap");
  }
}
