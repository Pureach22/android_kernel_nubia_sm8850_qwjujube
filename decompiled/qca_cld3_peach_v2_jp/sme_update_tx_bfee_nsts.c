__int64 __fastcall sme_update_tx_bfee_nsts(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
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
  __int64 v14; // x9
  __int64 v15; // x22
  unsigned int v16; // w21
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w0
  __int64 result; // x0
  _QWORD v28[3]; // [xsp+8h] [xbp-48h] BYREF
  int v29; // [xsp+20h] [xbp-30h]
  _QWORD v30[3]; // [xsp+28h] [xbp-28h] BYREF
  int v31; // [xsp+40h] [xbp-10h]
  __int64 v32; // [xsp+48h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a1 + 8);
  if ( a3 )
    v15 = a3;
  else
    v15 = a4;
  *(_BYTE *)(a1 + 21636) = a3;
  *(_BYTE *)(v14 + 2624) = v15;
  if ( a3 )
  {
    v16 = a2;
    v30[1] = 0x300000000LL;
    v30[2] = 0x400000002LL;
    v31 = 0;
    v30[0] = 0x10000005BLL;
    v29 = 0;
    v28[1] = 0x300000001LL;
    v28[2] = 0x300000001LL;
    v28[0] = 0x10000005BLL;
    v17 = wma_form_unit_test_cmd_and_send(a2, 72, 7, v30);
    if ( v17 )
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: send_unit_test_cmd returned %d",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "sme_set_he_tx_bf_cbf_rates",
        v17);
    v26 = wma_form_unit_test_cmd_and_send(v16, 72, 7, v28);
    if ( v26 )
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: send_unit_test_cmd returned %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "sme_set_he_tx_bf_cbf_rates",
        v26);
  }
  else
  {
    v16 = a2;
  }
  if ( a2 > 5u || !(*(_QWORD *)(a1 + 17224) + 96LL * a2) )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: No session for id %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "sme_update_he_tx_bfee_nsts",
      v16);
    goto LABEL_15;
  }
  if ( (unsigned int)v15 > 7 )
  {
LABEL_15:
    result = 4294967274LL;
    goto LABEL_16;
  }
  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1297LL) = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1297LL) & 0xFFFFFFFFFFC7FFFFLL
                                            | (v15 << 19);
  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1297LL) = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1297LL) & 0xFFFFFFFFF8FFFFFFLL
                                            | (v15 << 24);
  csr_update_session_he_cap(a1);
  result = 0;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
