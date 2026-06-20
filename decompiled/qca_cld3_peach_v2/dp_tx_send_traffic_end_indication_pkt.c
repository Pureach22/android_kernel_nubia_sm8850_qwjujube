__int64 __fastcall dp_tx_send_traffic_end_indication_pkt(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int16 v12; // w8
  char v13; // w9
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x19
  __int64 v24; // [xsp+8h] [xbp-78h] BYREF
  __int64 v25; // [xsp+10h] [xbp-70h]
  __int64 v26; // [xsp+18h] [xbp-68h]
  __int64 v27; // [xsp+20h] [xbp-60h]
  __int64 v28; // [xsp+28h] [xbp-58h]
  __int64 v29; // [xsp+30h] [xbp-50h]
  __int64 v30; // [xsp+38h] [xbp-48h]
  __int64 v31; // [xsp+40h] [xbp-40h]
  __int64 v32; // [xsp+48h] [xbp-38h]
  int v33; // [xsp+50h] [xbp-30h]
  __int64 v34; // [xsp+54h] [xbp-2Ch]
  int v35; // [xsp+5Ch] [xbp-24h]
  __int64 v36; // [xsp+60h] [xbp-20h]
  __int64 v37; // [xsp+68h] [xbp-18h]
  __int64 v38; // [xsp+70h] [xbp-10h]
  __int64 v39; // [xsp+78h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_WORD *)(a3 + 4);
  v24 = 0;
  v25 = 0;
  v13 = *(_BYTE *)(a3 + 94);
  v30 = 0;
  v31 = 0;
  WORD2(v24) = v12;
  LOBYTE(v12) = *(_BYTE *)(a3 + 12);
  v37 = 0;
  v38 = 0;
  BYTE4(v25) = v12;
  BYTE5(v25) = 1;
  v31 = 0x80000000LL;
  v35 = 0;
  v36 = 0;
  v32 = 0;
  v33 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  BYTE6(v36) = v13;
  v34 = 8;
  result = (__int64)dp_tx_send_msdu_single(a1, a2, (__int64)&v24, a4, 0, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( result )
  {
    v23 = result;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Traffic end indication packet tx failed",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "dp_tx_send_traffic_end_indication_pkt");
    result = _qdf_nbuf_free(v23);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
