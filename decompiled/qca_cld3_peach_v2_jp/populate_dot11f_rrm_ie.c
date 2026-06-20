__int64 __fastcall populate_dot11f_rrm_ie(__int64 a1, __int64 a2)
{
  __int64 capabilities; // x0
  unsigned int v4; // w8
  unsigned int v5; // w8
  unsigned int v6; // w8
  unsigned int v7; // w8
  unsigned int v8; // w8
  unsigned int v9; // w8
  unsigned int v10; // w8
  unsigned int v11; // w8
  unsigned int v12; // w9
  unsigned int v13; // w9
  unsigned int v14; // w9
  unsigned int v15; // w9
  unsigned int v16; // w9
  unsigned int v17; // w9
  unsigned int v18; // w9
  unsigned int v19; // w9
  unsigned int v20; // w10
  unsigned int v21; // w10
  unsigned int v22; // w10
  unsigned int v23; // w10
  unsigned int v24; // w12
  unsigned int v25; // w12
  unsigned int v26; // w12
  unsigned int v27; // w12
  unsigned int v28; // w12
  unsigned int v29; // w11
  int v30; // w13
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  capabilities = rrm_get_capabilities(a1);
  v4 = *(_DWORD *)(a2 + 1) & 0xFFFFFFFE | *(_DWORD *)capabilities & 1;
  *(_DWORD *)(a2 + 1) = v4;
  v5 = v4 & 0xFFFFFFFD | (2 * ((*(_DWORD *)capabilities >> 1) & 1));
  *(_DWORD *)(a2 + 1) = v5;
  v6 = v5 & 0xFFFFFFFB | (4 * ((*(_DWORD *)capabilities >> 2) & 1));
  *(_DWORD *)(a2 + 1) = v6;
  v7 = v6 & 0xFFFFFFF7 | (8 * ((*(_DWORD *)capabilities >> 3) & 1));
  *(_DWORD *)(a2 + 1) = v7;
  v8 = v7 & 0xFFFFFFEF | (16 * ((*(_DWORD *)capabilities >> 4) & 1));
  *(_DWORD *)(a2 + 1) = v8;
  v9 = v8 & 0xFFFFFFDF | (32 * ((*(_DWORD *)capabilities >> 5) & 1));
  *(_DWORD *)(a2 + 1) = v9;
  v10 = v9 & 0xFFFFFFBF | (((*(_DWORD *)capabilities >> 6) & 1) << 6);
  *(_DWORD *)(a2 + 1) = v10;
  v11 = v10 & 0xFFFFFF7F | (((*(_DWORD *)capabilities >> 7) & 1) << 7);
  *(_DWORD *)(a2 + 1) = v11;
  v12 = v11 & 0xFFFFFEFF | (((*(_DWORD *)capabilities >> 8) & 1) << 8);
  *(_DWORD *)(a2 + 1) = v12;
  v13 = v12 & 0xFFFFFDFF | (((*(_DWORD *)capabilities >> 9) & 1) << 9);
  *(_DWORD *)(a2 + 1) = v13;
  v14 = v13 & 0xFFFFFBFF | (((*(_DWORD *)capabilities >> 10) & 1) << 10);
  *(_DWORD *)(a2 + 1) = v14;
  v15 = v14 & 0xFFFFF7FF | (((*(_DWORD *)capabilities >> 11) & 1) << 11);
  *(_DWORD *)(a2 + 1) = v15;
  v16 = v15 & 0xFFFFEFFF | (((*(_DWORD *)capabilities >> 12) & 1) << 12);
  *(_DWORD *)(a2 + 1) = v16;
  v17 = v16 & 0xFFFFDFFF | (((*(_DWORD *)capabilities >> 13) & 1) << 13);
  *(_DWORD *)(a2 + 1) = v17;
  v18 = v17 & 0xFFFFBFFF | (((*(_DWORD *)capabilities >> 14) & 1) << 14);
  *(_DWORD *)(a2 + 1) = v18;
  v19 = v18 & 0xFFFF7FFF | (((*(_DWORD *)capabilities >> 15) & 1) << 15);
  *(_DWORD *)(a2 + 1) = v19;
  v20 = v19 & 0xFFFEFFFF | ((HIWORD(*(_DWORD *)capabilities) & 1) << 16);
  *(_DWORD *)(a2 + 1) = v20;
  v21 = v20 & 0xFFFDFFFF | (((*(_DWORD *)capabilities >> 17) & 1) << 17);
  *(_DWORD *)(a2 + 1) = v21;
  v22 = v21 & 0xFFE3FFFF | (((*(_DWORD *)capabilities >> 18) & 7) << 18);
  *(_DWORD *)(a2 + 1) = v22;
  v23 = v22 & 0xFF1FFFFF | (((*(_DWORD *)capabilities >> 21) & 7) << 21);
  *(_DWORD *)(a2 + 1) = v23;
  v24 = v23 & 0xF8FFFFFF | ((HIBYTE(*(_DWORD *)capabilities) & 7) << 24);
  *(_DWORD *)(a2 + 1) = v24;
  v25 = v24 & 0xF7FFFFFF | (((*(_DWORD *)capabilities >> 27) & 1) << 27);
  *(_DWORD *)(a2 + 1) = v25;
  v26 = v25 & 0xEFFFFFFF | (((*(_DWORD *)capabilities >> 28) & 1) << 28);
  *(_DWORD *)(a2 + 1) = v26;
  v27 = v26 & 0xDFFFFFFF | (((*(_DWORD *)capabilities >> 29) & 1) << 29);
  *(_DWORD *)(a2 + 1) = v27;
  v28 = v27 & 0xBFFFFFFF | (((*(_DWORD *)capabilities >> 30) & 1) << 30);
  *(_DWORD *)(a2 + 1) = v28;
  v29 = *(_DWORD *)capabilities & 0x80000000 | v28 & 0x7FFFFFFF;
  LOBYTE(v28) = *(_BYTE *)(a2 + 5);
  *(_DWORD *)(a2 + 1) = v29;
  LOBYTE(v28) = v28 & 0xFE | *(_BYTE *)(capabilities + 4) & 1;
  *(_BYTE *)(a2 + 5) = v28;
  LOBYTE(v28) = v28 & 0xFD | *(_BYTE *)(capabilities + 4) & 2;
  *(_BYTE *)(a2 + 5) = v28;
  LOBYTE(v28) = v28 & 0xFB | *(_BYTE *)(capabilities + 4) & 4;
  *(_BYTE *)(a2 + 5) = v28;
  LOBYTE(v28) = v28 & 0xF7 | *(_BYTE *)(capabilities + 4) & 8;
  *(_BYTE *)(a2 + 5) = v28;
  v30 = *(_BYTE *)(capabilities + 4) & 0xF0 | v28 & 0xF;
  *(_BYTE *)(a2 + 5) = v30;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: RRM Enabled Cap IE: %02x %02x %02x %02x %02x",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "populate_dot11f_rrm_ie",
    (unsigned __int8)v11,
    BYTE1(v19),
    BYTE2(v23),
    HIBYTE(v29),
    v30);
  *(_BYTE *)a2 = 1;
  return 0;
}
