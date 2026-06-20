__int64 __fastcall wma_process_mgmt_tx_completion(
        _QWORD *a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  const char *v27; // x4
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x21
  __int64 v37; // x8
  __int64 v38; // x8
  _DWORD *v39; // x8
  __int64 v40; // x0
  __int64 v41; // x25
  const char *v42; // x2
  __int64 v43; // x8
  __int64 v44; // x8
  _DWORD *v45; // x8
  _QWORD *context; // x0
  _DWORD *v47; // x8
  __int64 v48; // x4
  __int64 v49; // x8
  __int64 v50; // x8
  _DWORD *v51; // x9
  __int64 v52; // x8
  _DWORD *v53; // x8
  __int64 v54; // x0
  __int64 v55; // [xsp+8h] [xbp-48h] BYREF
  __int64 v56; // [xsp+10h] [xbp-40h]
  __int64 v57; // [xsp+18h] [xbp-38h]
  __int64 v58; // [xsp+20h] [xbp-30h]
  __int64 v59; // [xsp+28h] [xbp-28h]
  __int64 v60; // [xsp+30h] [xbp-20h]
  __int64 v61; // [xsp+38h] [xbp-18h]
  __int64 v62; // [xsp+40h] [xbp-10h]
  __int64 v63; // [xsp+48h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  result = _wma_validate_handle(
             (__int64)a1,
             (__int64)"wma_process_mgmt_tx_completion",
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13);
  if ( (_DWORD)result )
    goto LABEL_51;
  if ( a3 > 4 )
    v27 = "unknown";
  else
    v27 = off_A183A0[a3];
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: status: %s wmi_desc_id: %d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "wma_process_mgmt_tx_completion",
    v27,
    a2);
  v36 = a1[4];
  if ( !v36 )
  {
    v42 = "%s: psoc ptr is NULL";
LABEL_50:
    result = qdf_trace_msg(0x36u, 2u, v42, v28, v29, v30, v31, v32, v33, v34, v35, "wma_process_mgmt_tx_completion");
    goto LABEL_51;
  }
  v37 = *(_QWORD *)(v36 + 80);
  if ( !v37 )
    goto LABEL_15;
  v38 = *(_QWORD *)(v37 + 2136);
  if ( !v38 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: rx_ops is NULL",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "wlan_lmac_if_get_mgmt_txrx_rx_ops");
    v41 = 0;
    goto LABEL_18;
  }
  v39 = *(_DWORD **)(v38 + 16);
  if ( !v39 )
  {
LABEL_15:
    v41 = 0;
    if ( a4 != 255 )
      goto LABEL_27;
    goto LABEL_19;
  }
  v40 = a1[4];
  if ( *(v39 - 1) != 1475484239 )
    __break(0x8228u);
  v41 = ((__int64 (__fastcall *)(__int64, _QWORD))v39)(v40, a2);
  if ( v41 )
  {
    _qdf_nbuf_unmap_single(a1[23], v41, 1);
    if ( a4 != 255 )
      goto LABEL_27;
    goto LABEL_19;
  }
LABEL_18:
  if ( a4 != 255 )
    goto LABEL_27;
LABEL_19:
  v43 = *(_QWORD *)(v36 + 80);
  if ( !v43 )
    goto LABEL_26;
  v44 = *(_QWORD *)(v43 + 2136);
  if ( !v44 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: rx_ops is NULL",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "wlan_lmac_if_get_mgmt_txrx_rx_ops");
    goto LABEL_26;
  }
  v45 = *(_DWORD **)(v44 + 32);
  if ( !v45 )
  {
LABEL_26:
    a4 = 255;
    goto LABEL_27;
  }
  if ( *(v45 - 1) != -1949648479 )
    __break(0x8228u);
  a4 = ((__int64 (__fastcall *)(__int64, _QWORD))v45)(v36, a2);
LABEL_27:
  BYTE2(v56) = a4;
  LOBYTE(v62) = a5;
  BYTE2(v62) = 0;
  context = _cds_get_context(71, (__int64)"wma_mgmt_pktdump_tx_handler", v28, v29, v30, v31, v32, v33, v34, v35);
  v47 = (_DWORD *)a1[473];
  if ( a3 > 3 )
  {
    v48 = 4;
    if ( !v47 )
      goto LABEL_34;
  }
  else
  {
    v48 = dword_A2FAE8[a3];
    if ( !v47 )
      goto LABEL_34;
  }
  if ( *(v47 - 1) != -915278510 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD *, _QWORD, _QWORD, __int64, __int64, _QWORD))v47)(context, 0, a4, v41, v48, 0);
LABEL_34:
  v49 = *(_QWORD *)(v36 + 80);
  if ( !v49 )
    goto LABEL_49;
  v50 = *(_QWORD *)(v49 + 2136);
  if ( !v50 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: rx_ops is NULL",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "wlan_lmac_if_get_mgmt_txrx_rx_ops",
      v48);
    v52 = *(_QWORD *)(v36 + 80);
    if ( v52 )
    {
      v50 = *(_QWORD *)(v52 + 2136);
      if ( v50 )
      {
LABEL_43:
        v53 = *(_DWORD **)(v50 + 16);
        if ( v53 )
        {
          if ( *(v53 - 1) != 1475484239 )
            __break(0x8228u);
          v54 = ((__int64 (__fastcall *)(__int64, _QWORD))v53)(v36, a2);
          if ( v54 )
            _qdf_nbuf_free(v54);
        }
        goto LABEL_49;
      }
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: rx_ops is NULL",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "wlan_lmac_if_get_mgmt_txrx_rx_ops");
    }
LABEL_49:
    v42 = "%s: Failed to process mgmt tx completion";
    goto LABEL_50;
  }
  v51 = *(_DWORD **)v50;
  if ( !*(_QWORD *)v50 )
    goto LABEL_43;
  if ( *(v51 - 1) != 20594172 )
    __break(0x8229u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64 *, __int64))v51)(v36, a2, a3, &v55, v48);
  if ( (_DWORD)result )
    goto LABEL_49;
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
