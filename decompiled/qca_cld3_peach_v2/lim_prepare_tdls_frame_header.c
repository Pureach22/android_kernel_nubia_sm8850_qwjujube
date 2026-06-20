__int64 __fastcall lim_prepare_tdls_frame_header(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned __int8 *a3,
        char a4,
        char a5,
        char a6,
        __int64 a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  __int64 v15; // x8
  const void *v17; // x22
  __int16 v21; // w8
  unsigned __int8 *v22; // x1
  unsigned __int8 *v23; // x25
  unsigned __int8 *v24; // x23
  unsigned __int16 *v25; // x0
  int v26; // w8
  unsigned __int8 v27; // w8
  __int16 v28; // w8
  int v29; // w9
  const char *v30; // x21
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int16 v39; // w8
  __int64 v40; // x20
  unsigned __int8 *v41; // x19
  __int16 v43; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v44; // [xsp+58h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a5 )
    v17 = a3 + 13;
  else
    v17 = a3 + 7;
  v44 = v15;
  v21 = *(_WORD *)a2;
  if ( a5 )
    v22 = a3 + 7;
  else
    v22 = a3 + 13;
  if ( a4 )
    v23 = v22;
  else
    v23 = a3 + 1;
  if ( a4 )
    v24 = a3 + 1;
  else
    v24 = v22;
  v43 = 0;
  *(_WORD *)a2 = v21 & 0xFFF0 | 8;
  v25 = (unsigned __int16 *)dph_lookup_hash_entry(a8, a9, a10, a11, a12, a13, a14, a15, a1, v22, &v43, a7 + 360);
  if ( v25 )
    v26 = (*v25 >> 1) & 1;
  else
    LOBYTE(v26) = 0;
  if ( (*(_BYTE *)(a7 + 7024) & 1) == 0 || (*(_WORD *)(a7 + 176) & 0x200) == 0 )
  {
    if ( (*(_BYTE *)(a7 + 7024) & 2) != 0 && !a4 && (*(_BYTE *)(a7 + 178) & 2) != 0 )
      goto LABEL_21;
LABEL_23:
    if ( ((a4 == 1) & (unsigned __int8)v26) != 0 )
      v27 = 0;
    else
      v27 = 0x80;
    goto LABEL_26;
  }
  if ( a4 )
    goto LABEL_23;
LABEL_21:
  v27 = 0;
LABEL_26:
  v28 = v27 | ((a4 == 0) << 8) | *(_WORD *)a2 & 0xEE0F;
  *(_WORD *)a2 = v28;
  v29 = *(_DWORD *)(a7 + 424);
  if ( a4 )
    v30 = "DIRECT";
  else
    v30 = "AP";
  *(_WORD *)a2 = v28 & 0xAF8F | ((v29 != 0) << 14);
  qdf_mem_copy(a2 + 4, v23, 6u);
  qdf_mem_copy(a2 + 10, v17, 6u);
  qdf_mem_copy(a2 + 16, v24, 6u);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Preparing TDLS frame header to %s A1:%02x:%02x:%02x:**:**:%02x, A2:%02x:%02x:%02x:**:**:%02x, A3:%02x:%02x:%02x:**:**:%02x",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "lim_prepare_tdls_frame_header",
    v30,
    a2[4],
    a2[5],
    a2[6],
    a2[9],
    a2[10],
    a2[11],
    a2[12],
    a2[15],
    a2[16],
    a2[17],
    a2[18],
    a2[21]);
  if ( (*(_WORD *)a2 & 0xF0) == 0x80 )
  {
    v39 = *((_WORD *)a2 + 12) & 0xFFF0 | a6 & 0xF;
    v40 = 26;
    *((_WORD *)a2 + 12) = v39;
  }
  else
  {
    v40 = 24;
  }
  v41 = &a2[v40];
  qdf_mem_copy(v41, &eth_890d_header, 8u);
  v41[8] = 2;
  _ReadStatusReg(SP_EL0);
  return (unsigned int)(v40 + 9);
}
