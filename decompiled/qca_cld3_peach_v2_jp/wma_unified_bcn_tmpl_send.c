__int64 __fastcall wma_unified_bcn_tmpl_send(
        __int64 *a1,
        unsigned __int8 a2,
        __int64 a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x0
  __int64 v25; // x4
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  __int128 v31; // q5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x8
  __int64 v35; // x9
  unsigned int v36; // w4
  __int64 result; // x0
  __int64 v38; // x8
  const char *v39; // x2
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w19
  __int64 v49; // [xsp+0h] [xbp-40h]

  _ReadStatusReg(SP_EL0);
  if ( (wma_is_vdev_valid(a2, a5, a6, a7, a8, a9, a10, a11, a12) & 1) == 0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev id:%d is not active ",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wma_unified_bcn_tmpl_send",
      a2,
      0,
      0,
      0,
      0,
      0,
      0);
    result = 4;
LABEL_18:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v24 = qdf_trace_msg(
          0x36u,
          8u,
          "vdev %d: bcn update reason %d",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          a2,
          *(unsigned int *)(a3 + 540),
          0,
          0,
          0,
          0,
          0,
          0);
  v34 = *(unsigned __int16 *)(a3 + 528);
  if ( !*(_WORD *)(a3 + 528) )
  {
    v38 = 7;
    if ( !a4 )
      v38 = 520;
    if ( *(_DWORD *)(a3 + v38) < 0x2DDu )
      goto LABEL_14;
    goto LABEL_13;
  }
  if ( (unsigned int)v34 < 0x201 )
  {
    v35 = 7;
    if ( !a4 )
      v35 = 520;
    v36 = *(_DWORD *)(a3 + v35);
    if ( v36 <= 0x2DC )
    {
      if ( v36 > (unsigned int)*(unsigned __int8 *)(a3 + v34 + 8) + 2 )
      {
LABEL_14:
        LOBYTE(v49) = a2;
        HIDWORD(v49) = *(_DWORD *)(a3 + 524) - a4;
        *(_QWORD *)(a3 + a4 + 31) = -*(_QWORD *)(a1[65] + 488LL * a2 + 192);
        mlme_get_bigtk_support(*(_QWORD *)(a1[65] + 488LL * a2), v26, v27, v28, v29, v30, *(double *)&v31, v32, v33);
        result = wmi_unified_beacon_tmpl_send_cmd(*a1);
        if ( (_DWORD)result )
        {
          v48 = result;
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Failed to send bcn tmpl: %d",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "wma_unified_bcn_tmpl_send",
            (unsigned int)result,
            v49);
          result = v48;
        }
        goto LABEL_18;
      }
      v39 = "%s: tmpl_len %d <= p2p_ie_len %d, Invalid";
      goto LABEL_17;
    }
LABEL_13:
    v39 = "%s: tmpl_len: %d > %d. Invalid tmpl len";
LABEL_17:
    qdf_trace_msg(0x36u, 2u, v39, v26, v27, v28, v29, v30, *(double *)&v31, v32, v33, "wma_unified_bcn_tmpl_send");
    result = 4294967274LL;
    goto LABEL_18;
  }
  __break(0x5512u);
  *(_OWORD *)(v25 + 24432) = v31;
  return wma_send_probe_rsp_tmpl(v24);
}
