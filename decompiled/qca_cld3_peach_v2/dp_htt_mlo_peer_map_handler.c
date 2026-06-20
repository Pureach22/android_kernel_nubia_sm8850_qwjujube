__int64 __fastcall dp_htt_mlo_peer_map_handler(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int *v12; // x8
  unsigned int v13; // w9
  unsigned int v14; // w22
  unsigned int v15; // w21
  unsigned __int64 v16; // x10
  __int64 v17; // x9
  unsigned int v18; // w10
  char *v19; // x9
  unsigned int *v20; // x8
  unsigned __int64 v21; // x11
  __int64 v22; // x10
  int v23; // w9
  char *v24; // x9
  unsigned int *v25; // x8
  unsigned __int64 v26; // x11
  __int64 v27; // x10
  int v28; // w9
  char *v29; // x8
  int v30; // w9
  int v31; // w8
  unsigned int v32; // w21
  __int64 result; // x0
  unsigned int v34; // w21
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // [xsp+8h] [xbp-28h] BYREF
  __int16 v44; // [xsp+14h] [xbp-1Ch] BYREF
  char v45; // [xsp+16h] [xbp-1Ah]
  char v46; // [xsp+17h] [xbp-19h]
  char v47; // [xsp+18h] [xbp-18h]
  char v48; // [xsp+19h] [xbp-17h]
  __int16 v49; // [xsp+1Ah] [xbp-16h]
  char v50; // [xsp+1Ch] [xbp-14h]
  char v51; // [xsp+1Dh] [xbp-13h]
  char v52; // [xsp+1Eh] [xbp-12h]
  char v53; // [xsp+1Fh] [xbp-11h]
  __int16 v54; // [xsp+20h] [xbp-10h]
  char v55; // [xsp+22h] [xbp-Eh]
  char v56; // [xsp+23h] [xbp-Dh]
  char v57; // [xsp+24h] [xbp-Ch]
  char v58; // [xsp+25h] [xbp-Bh]
  __int64 v59; // [xsp+28h] [xbp-8h]

  v12 = a2 + 8;
  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = a2[2];
  v13 = a2[3];
  v15 = *a2;
  v43 = 0;
  v44 = v13;
  v49 = v13;
  v45 = BYTE2(v13) & 1;
  v46 = (v13 >> 17) & 7;
  v47 = (v13 >> 20) & 0xF;
  v48 = v13 >> 28;
  v50 = BYTE2(v13) & 1;
  v51 = v46;
  v52 = v47;
  v53 = v48;
  v54 = v13;
  v55 = BYTE2(v13) & 1;
  v56 = v46;
  v57 = v47;
  v58 = v48;
  if ( a2 == (unsigned int *)-32LL )
    goto LABEL_18;
  v16 = *v12;
  LOWORD(v43) = -1;
  v17 = (v16 >> 12) & 0xFFF;
  if ( !(_DWORD)v17 )
    goto LABEL_17;
  if ( (v16 & 0xFFF) == 0 )
  {
    v18 = a2[9];
    LOBYTE(v43) = HIBYTE(v18) & 7;
    BYTE1(v43) = BYTE2(v18);
  }
  v19 = (char *)v12 + v17;
  v20 = (unsigned int *)(v19 + 4);
  if ( v19 != (char *)-4LL )
  {
    v21 = *v20;
    WORD1(v43) = -1;
    v22 = (v21 >> 12) & 0xFFF;
    if ( !(_DWORD)v22 )
      goto LABEL_17;
    if ( (v21 & 0xFFF) == 0 )
    {
      v23 = *((_DWORD *)v19 + 2);
      BYTE2(v43) = HIBYTE(v23) & 7;
      BYTE3(v43) = BYTE2(v23);
    }
    v24 = (char *)v20 + v22;
    v25 = (unsigned int *)((char *)v20 + v22 + 4);
    if ( v25 )
    {
      v26 = *v25;
      WORD2(v43) = -1;
      v27 = (v26 >> 12) & 0xFFF;
      if ( !(_DWORD)v27 )
        goto LABEL_17;
      if ( (v26 & 0xFFF) == 0 )
      {
        v28 = *((_DWORD *)v24 + 2);
        BYTE4(v43) = HIBYTE(v28) & 7;
        BYTE5(v43) = BYTE2(v28);
      }
      v29 = (char *)v25 + v27;
      if ( v29 != (char *)-4LL )
      {
        v30 = *((_DWORD *)v29 + 1);
        HIWORD(v43) = -1;
        if ( (v30 & 0xFFF000) != 0 )
        {
          if ( (v30 & 0xFFF) == 0 )
          {
            v31 = *((_DWORD *)v29 + 2);
            BYTE6(v43) = HIBYTE(v31) & 7;
            HIBYTE(v43) = BYTE2(v31);
          }
          goto LABEL_18;
        }
LABEL_17:
        qdf_trace_msg(0x45u, 2u, "%s: TLV Length is 0", a3, a4, a5, a6, a7, a8, a9, a10, "dp_htt_mlo_peer_map_handler");
      }
    }
  }
LABEL_18:
  v32 = v15 >> 8;
  result = dp_rx_mlo_peer_map_handler(*(_QWORD *)(a1 + 8), v32, a2 + 1, &v44, &v43);
  if ( (v14 & 0x1000000) != 0 )
  {
    v34 = dp_gen_ml_peer_id(*(_QWORD *)(a1 + 8), v32);
    qdf_trace_msg(
      0x80u,
      5u,
      "%s: HTT_T2H_MSG_TYPE_MLO_RX_PEER_MAP for peer id %d classify_idx valid %d classify_info_idx %d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "dp_htt_mlo_peer_map_handler",
      (unsigned __int16)v34,
      1,
      BYTE2(v14));
    result = dp_peer_set_tx_classify_idx(*(_QWORD *)(a1 + 8), v34, 255, HIWORD(v14));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
