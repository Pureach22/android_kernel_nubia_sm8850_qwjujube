__int64 __fastcall wma_mgmt_tx_ack_comp_hdlr(
        __int64 result,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x19
  __int64 v12; // x8
  __int64 v13; // x8
  unsigned int v14; // w20
  _DWORD *v16; // x8
  __int64 v17; // x8
  __int64 v18; // x8
  _DWORD *v19; // x9
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  _DWORD *v29; // x8
  __int64 v30; // [xsp+8h] [xbp-48h] BYREF
  __int64 v31; // [xsp+10h] [xbp-40h]
  __int64 v32; // [xsp+18h] [xbp-38h]
  __int64 v33; // [xsp+20h] [xbp-30h]
  __int64 v34; // [xsp+28h] [xbp-28h]
  __int64 v35; // [xsp+30h] [xbp-20h]
  __int64 v36; // [xsp+38h] [xbp-18h]
  __int64 v37; // [xsp+40h] [xbp-10h]
  __int64 v38; // [xsp+48h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(result + 32);
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v12 = *(_QWORD *)(v11 + 80);
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  if ( !v12 )
    goto LABEL_23;
  v13 = *(_QWORD *)(v12 + 2136);
  v14 = *(unsigned __int16 *)(a2 + 58);
  if ( !v13 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: rx_ops is NULL",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_lmac_if_get_mgmt_txrx_rx_ops");
    goto LABEL_8;
  }
  v16 = *(_DWORD **)(v13 + 32);
  if ( !v16 )
  {
LABEL_8:
    result = 255;
    goto LABEL_9;
  }
  if ( *(v16 - 1) != -1949648479 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD))v16)(v11, v14);
LABEL_9:
  v17 = *(_QWORD *)(v11 + 80);
  BYTE2(v31) = result;
  if ( !v17 )
    goto LABEL_23;
  v18 = *(_QWORD *)(v17 + 2136);
  if ( v18 )
  {
    v19 = *(_DWORD **)v18;
    if ( *(_QWORD *)v18 )
    {
      if ( *(v19 - 1) != 20594172 )
        __break(0x8229u);
      result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64 *))v19)(v11, v14, a3, &v30);
      goto LABEL_23;
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x38u,
               2u,
               "%s: rx_ops is NULL",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "wlan_lmac_if_get_mgmt_txrx_rx_ops");
    v28 = *(_QWORD *)(v11 + 80);
    if ( !v28 )
      goto LABEL_23;
    v18 = *(_QWORD *)(v28 + 2136);
    if ( !v18 )
    {
      result = qdf_trace_msg(
                 0x38u,
                 2u,
                 "%s: rx_ops is NULL",
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 "wlan_lmac_if_get_mgmt_txrx_rx_ops");
      goto LABEL_23;
    }
  }
  v29 = *(_DWORD **)(v18 + 16);
  if ( v29 )
  {
    if ( *(v29 - 1) != 1475484239 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD))v29)(v11, v14);
    if ( result )
      result = _qdf_nbuf_free(result);
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
