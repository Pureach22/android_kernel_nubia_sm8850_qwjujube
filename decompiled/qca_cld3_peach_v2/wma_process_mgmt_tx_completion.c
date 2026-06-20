__int64 __fastcall wma_process_mgmt_tx_completion(
        _QWORD *a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        char a5,
        char a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x4
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x21
  __int64 v39; // x8
  __int64 v40; // x8
  _DWORD *v41; // x8
  __int64 v42; // x0
  __int64 v43; // x26
  const char *v44; // x2
  __int64 v45; // x8
  __int64 v46; // x8
  _DWORD *v47; // x8
  _QWORD *context; // x0
  _DWORD *v49; // x8
  __int64 v50; // x4
  __int64 v51; // x8
  __int64 v52; // x8
  _DWORD *v53; // x9
  __int64 v54; // x8
  _DWORD *v55; // x8
  __int64 v56; // x0
  __int64 v57; // [xsp+8h] [xbp-48h] BYREF
  __int64 v58; // [xsp+10h] [xbp-40h]
  __int64 v59; // [xsp+18h] [xbp-38h]
  __int64 v60; // [xsp+20h] [xbp-30h]
  __int64 v61; // [xsp+28h] [xbp-28h]
  __int64 v62; // [xsp+30h] [xbp-20h]
  __int64 v63; // [xsp+38h] [xbp-18h]
  __int64 v64; // [xsp+40h] [xbp-10h]
  __int64 v65; // [xsp+48h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  result = _wma_validate_handle(
             (__int64)a1,
             (__int64)"wma_process_mgmt_tx_completion",
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             a14);
  if ( (_DWORD)result )
    goto LABEL_51;
  if ( a3 > 4 )
    v29 = "unknown";
  else
    v29 = off_B0A518[a3];
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: status: %s wmi_desc_id: %d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "wma_process_mgmt_tx_completion",
    v29,
    a2);
  v38 = a1[4];
  if ( !v38 )
  {
    v44 = "%s: psoc ptr is NULL";
LABEL_50:
    result = qdf_trace_msg(0x36u, 2u, v44, v30, v31, v32, v33, v34, v35, v36, v37, "wma_process_mgmt_tx_completion");
    goto LABEL_51;
  }
  v39 = *(_QWORD *)(v38 + 80);
  if ( !v39 )
    goto LABEL_15;
  v40 = *(_QWORD *)(v39 + 2136);
  if ( !v40 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: rx_ops is NULL",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wlan_lmac_if_get_mgmt_txrx_rx_ops");
    v43 = 0;
    goto LABEL_18;
  }
  v41 = *(_DWORD **)(v40 + 16);
  if ( !v41 )
  {
LABEL_15:
    v43 = 0;
    if ( a4 != 255 )
      goto LABEL_27;
    goto LABEL_19;
  }
  v42 = a1[4];
  if ( *(v41 - 1) != 1475484239 )
    __break(0x8228u);
  v43 = ((__int64 (__fastcall *)(__int64, _QWORD))v41)(v42, a2);
  if ( v43 )
  {
    _qdf_nbuf_unmap_single(a1[23], v43, 1);
    if ( a4 != 255 )
      goto LABEL_27;
    goto LABEL_19;
  }
LABEL_18:
  if ( a4 != 255 )
    goto LABEL_27;
LABEL_19:
  v45 = *(_QWORD *)(v38 + 80);
  if ( !v45 )
    goto LABEL_26;
  v46 = *(_QWORD *)(v45 + 2136);
  if ( !v46 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: rx_ops is NULL",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wlan_lmac_if_get_mgmt_txrx_rx_ops");
    goto LABEL_26;
  }
  v47 = *(_DWORD **)(v46 + 32);
  if ( !v47 )
  {
LABEL_26:
    a4 = 255;
    goto LABEL_27;
  }
  if ( *(v47 - 1) != -1949648479 )
    __break(0x8228u);
  a4 = ((__int64 (__fastcall *)(__int64, _QWORD))v47)(v38, a2);
LABEL_27:
  BYTE2(v58) = a4;
  LOBYTE(v64) = a5;
  BYTE2(v64) = a6;
  context = _cds_get_context(71, (__int64)"wma_mgmt_pktdump_tx_handler", v30, v31, v32, v33, v34, v35, v36, v37);
  v49 = (_DWORD *)a1[473];
  if ( a3 > 3 )
  {
    v50 = 4;
    if ( !v49 )
      goto LABEL_34;
  }
  else
  {
    v50 = dword_B35978[a3];
    if ( !v49 )
      goto LABEL_34;
  }
  if ( *(v49 - 1) != -915278510 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD *, _QWORD, _QWORD, __int64, __int64, _QWORD))v49)(context, 0, a4, v43, v50, 0);
LABEL_34:
  v51 = *(_QWORD *)(v38 + 80);
  if ( !v51 )
    goto LABEL_49;
  v52 = *(_QWORD *)(v51 + 2136);
  if ( !v52 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: rx_ops is NULL",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wlan_lmac_if_get_mgmt_txrx_rx_ops",
      v50);
    v54 = *(_QWORD *)(v38 + 80);
    if ( v54 )
    {
      v52 = *(_QWORD *)(v54 + 2136);
      if ( v52 )
      {
LABEL_43:
        v55 = *(_DWORD **)(v52 + 16);
        if ( v55 )
        {
          if ( *(v55 - 1) != 1475484239 )
            __break(0x8228u);
          v56 = ((__int64 (__fastcall *)(__int64, _QWORD))v55)(v38, a2);
          if ( v56 )
            _qdf_nbuf_free(v56);
        }
        goto LABEL_49;
      }
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: rx_ops is NULL",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "wlan_lmac_if_get_mgmt_txrx_rx_ops");
    }
LABEL_49:
    v44 = "%s: Failed to process mgmt tx completion";
    goto LABEL_50;
  }
  v53 = *(_DWORD **)v52;
  if ( !*(_QWORD *)v52 )
    goto LABEL_43;
  if ( *(v53 - 1) != 20594172 )
    __break(0x8229u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64 *, __int64))v53)(v38, a2, a3, &v57, v50);
  if ( (_DWORD)result )
    goto LABEL_49;
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
