__int64 __fastcall sme_update_he_cap_nss(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  const char *v11; // x2
  __int64 v12; // x9
  int v14; // w8
  __int64 v15; // x10
  unsigned int v16; // w20
  unsigned int v17; // w21
  int v18; // w8
  unsigned int v19; // w9
  __int64 v20; // x8
  unsigned int v21; // w23
  _WORD *v22; // x21
  __int64 result; // x0
  __int16 v24; // w9
  __int64 v25; // x10
  __int64 v26; // x20
  __int16 v27; // [xsp+0h] [xbp-10h] BYREF
  __int16 v28; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)a3 - 3 > 0xFFFFFFFD )
  {
    if ( a2 > 5u || !(*(_QWORD *)(a1 + 17224) + 96LL * a2) )
    {
      v11 = "%s: No session for id %d";
      goto LABEL_13;
    }
    v12 = *(_QWORD *)(a1 + 8);
    v14 = *(unsigned __int16 *)(v12 + 1308);
    v15 = -1LL << (2 * a3);
    v16 = (v15 | *(unsigned __int16 *)(v12 + 1310)) & 0xFFFC | v14 & 3;
    v17 = (v15 | v14) & 0xFFFC | v14 & 3;
    if ( a3 != 1 )
    {
      v18 = 4 * (v14 & 3);
      v16 = v16 & 0xFFFFFFF3 | v18;
      v17 = v17 & 0xFFFFFFF3 | v18;
    }
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: new HE Nss MCS MAP: Rx 0x%0X, Tx: 0x%0X",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sme_update_he_cap_nss",
      v17,
      v16,
      __PAIR64__(v16, v17),
      v29);
    v19 = HIWORD(v17);
    v20 = a1;
    if ( HIWORD(v17) )
    {
      v21 = HIWORD(v16);
      if ( HIWORD(v16) )
      {
LABEL_9:
        if ( !v19 )
          goto LABEL_10;
        goto LABEL_17;
      }
    }
    else
    {
      *(_WORD *)(*(_QWORD *)(a1 + 8) + 1308LL) = v17;
      v21 = HIWORD(v16);
      if ( HIWORD(v16) )
        goto LABEL_9;
    }
    *(_WORD *)(*(_QWORD *)(a1 + 8) + 1310LL) = v16;
    if ( !v19 )
    {
LABEL_10:
      qdf_mem_copy((void *)(*(_QWORD *)(a1 + 8) + 1312LL), &v27, 2u);
      v20 = a1;
      v22 = (_WORD *)(a1 + 20480);
      if ( v21 )
        goto LABEL_19;
      goto LABEL_18;
    }
LABEL_17:
    v22 = (_WORD *)(a1 + 20480);
    if ( v21 )
    {
LABEL_19:
      v24 = v27;
      v25 = *(_QWORD *)(v20 + 8);
      v22[629] = v16;
      v22[628] = v24;
      v22[658] = v24;
      v22[659] = v16;
      v26 = v20;
      qdf_mem_copy((void *)(v20 + 21800), (const void *)(v25 + 1312), 2u);
      qdf_mem_copy((void *)(v26 + 21802), (const void *)(*(_QWORD *)(v26 + 8) + 1314LL), 2u);
      result = csr_update_session_he_cap(v26);
      goto LABEL_14;
    }
LABEL_18:
    qdf_mem_copy((void *)(*(_QWORD *)(v20 + 8) + 1314LL), &v28, 2u);
    LOWORD(v16) = v28;
    v20 = a1;
    goto LABEL_19;
  }
  v11 = "%s: invalid Nss value nss %d";
LABEL_13:
  result = qdf_trace_msg(0x34u, 2u, v11, a4, a5, a6, a7, a8, a9, a10, a11, "sme_update_he_cap_nss");
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
