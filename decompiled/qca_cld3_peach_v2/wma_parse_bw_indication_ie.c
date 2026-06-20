__int64 __fastcall wma_parse_bw_indication_ie(
        unsigned __int8 *a1,
        unsigned __int8 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x4
  unsigned __int8 *v22; // x0
  unsigned __int8 v23; // w6
  __int64 v24; // x5
  unsigned __int8 v25; // w8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  char v34; // w9
  __int64 result; // x0
  char v36; // w10
  unsigned __int16 v37; // w8
  unsigned int v38; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v39[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v40[4]; // [xsp+10h] [xbp-10h] BYREF
  unsigned __int16 v41; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+18h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  v40[0] = 0;
  v39[0] = 0;
  v38 = 0;
  if ( !a1 || a2 <= 1u )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Invalid WMI_CSWRAP_IE len %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wma_parse_bw_indication_ie",
      a2);
    goto LABEL_17;
  }
  if ( (unsigned __int64)a1[1] + 2 > a2 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid ie len: %d, buffer len: %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wma_parse_bw_indication_ie");
LABEL_17:
    result = 4;
    goto LABEL_18;
  }
  ((void (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD))qdf_trace_hex_dump)(54, 8, a1, a2);
  v21 = a1[1];
  if ( *a1 != 196 || !a1[1] )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Invalid len: %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_parse_ch_switch_wrapper_ie",
      v21);
LABEL_16:
    qdf_trace_msg(0x36u, 2u, "%s: Invalid ie", v13, v14, v15, v16, v17, v18, v19, v20, "wma_parse_bw_indication_ie");
    goto LABEL_17;
  }
  v22 = a1 + 2;
  while ( 1 )
  {
    v23 = v22[1];
    v24 = *v22;
    v25 = v23 + 2;
    if ( (unsigned __int8)v21 < (unsigned int)(unsigned __int8)(v23 + 2) )
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: invalid sub element len :%d id:%d ie len:%d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wma_parse_ch_switch_wrapper_ie",
        (unsigned __int8)(v23 + 2),
        v24);
      goto LABEL_16;
    }
    if ( (_DWORD)v24 == 255 && v22[2] == 135 )
      break;
    LOBYTE(v21) = v21 - v25;
    v22 += v25;
    if ( !(_BYTE)v21 )
      goto LABEL_16;
  }
  if ( !v22 )
    goto LABEL_16;
  util_parse_bw_ind(v22, v40, v39, &v38, &v41);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: ch width: %d, ccfs0: %d, ccfs1: %d, puncture: %d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "wma_parse_bw_indication_ie",
    v38,
    v40[0],
    v39[0],
    v41);
  v34 = v40[0];
  result = 0;
  v36 = v39[0];
  *(_DWORD *)(a3 + 12) = v38;
  v37 = v41;
  *(_BYTE *)(a3 + 19) = v34;
  *(_BYTE *)(a3 + 20) = v36;
  *(_WORD *)(a3 + 16) = v37;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
