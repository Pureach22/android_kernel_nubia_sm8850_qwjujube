__int64 __fastcall lim_generate_fils_pmkr1_name(__int64 a1, __int64 a2)
{
  char *v2; // x22
  __int64 v5; // x0
  void *v6; // x21
  char v7; // w10
  const char *v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  char *v27; // x21
  size_t v28; // x1
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  int v37; // w9
  unsigned __int8 v38; // w8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x8
  int v48; // [xsp+Ch] [xbp-D4h] BYREF
  _QWORD v49[9]; // [xsp+10h] [xbp-D0h] BYREF
  __int64 v50; // [xsp+58h] [xbp-88h]
  __int64 v51; // [xsp+60h] [xbp-80h]
  __int64 v52; // [xsp+68h] [xbp-78h]
  __int64 v53; // [xsp+70h] [xbp-70h]
  __int64 v54; // [xsp+78h] [xbp-68h]
  __int64 v55; // [xsp+80h] [xbp-60h]
  __int64 v56; // [xsp+88h] [xbp-58h]
  __int64 v57; // [xsp+90h] [xbp-50h]
  __int64 v58; // [xsp+98h] [xbp-48h]
  __int16 v59; // [xsp+A0h] [xbp-40h]
  _QWORD v60[2]; // [xsp+A8h] [xbp-38h] BYREF
  _QWORD v61[5]; // [xsp+B8h] [xbp-28h] BYREF

  v61[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(char **)(a2 + 9976);
  v59 = 0;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v50 = 0;
  memset(v49, 0, sizeof(v49));
  if ( !v2 )
    goto LABEL_10;
  v48 = 0;
  v5 = _qdf_mem_malloc(0x30u, "lim_generate_fils_pmkr1_name", 1605);
  if ( !v5 )
  {
    result = 2;
    goto LABEL_25;
  }
  v6 = (void *)v5;
  v61[2] = v2 + 436;
  v61[3] = a2 + 30;
  v7 = v2[17];
  v61[0] = "FT-R1N";
  v61[1] = v2 + 621;
  v60[0] = 0x1000000006LL;
  v60[1] = 0x600000006LL;
  if ( ((v7 - 19) & 0xFD) != 0 )
    v8 = "sha256";
  else
    v8 = "sha384";
  if ( (qdf_get_hash((__int64)v8, 4u, (__int64)v61, (unsigned int *)v60) & 0x80000000) != 0 )
  {
    qdf_mem_set(v6, 0x30u, 0);
    _qdf_mem_free((__int64)v6);
    result = 16;
    goto LABEL_25;
  }
  qdf_mem_copy(v2 + 637, v6, 0x10u);
  qdf_mem_set(v6, 0x30u, 0);
  _qdf_mem_free((__int64)v6);
  if ( !v2[351] )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: FT-FILS: RSN IE not present",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "lim_generate_fils_pmkr1_name");
    result = 16;
    goto LABEL_25;
  }
  v17 = dot11f_unpack_ie_rsn(a1, v2 + 96, v2[351] - 2, v49);
  if ( v17 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: unpack RSN IE failed, ret: %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "lim_generate_fils_pmkr1_name",
      v17);
LABEL_10:
    result = 16;
    goto LABEL_25;
  }
  v27 = &v2[(unsigned __int8)v2[351] + 94];
  if ( v2[352] == 1 )
  {
    v27 -= 4;
    v2[95] -= 4;
    qdf_mem_copy(&v48, v27, 4u);
  }
  if ( WORD1(v50) || v2[352] == 1 )
  {
    v28 = (16LL * WORD1(v50)) | 2;
    v27 -= v28;
    v2[95] -= (16 * BYTE2(v50)) | 2;
    qdf_mem_set(v27, v28, 0);
  }
  *v27 = 1;
  qdf_mem_copy(v27 + 2, v2 + 637, 0x10u);
  v37 = (unsigned __int8)v2[352];
  v38 = v2[95] + 18;
  v2[95] = v38;
  if ( v37 == 1 )
  {
    qdf_mem_copy(v27 + 18, &v48, 4u);
    v38 = v2[95] + 4;
    v2[95] = v38;
  }
  v2[351] = v38 + 2;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: FT-FILS: Final RSN length:%d",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "lim_generate_fils_pmkr1_name",
    v38);
  ((void (__fastcall *)(__int64, __int64, char *, _QWORD))qdf_trace_hex_dump)(53, 8, v2 + 94, (unsigned __int8)v2[351]);
  v47 = *(_QWORD *)(a2 + 112);
  if ( v47 )
  {
    qdf_mem_set((void *)(v47 + 2), 0x101u, 0);
    **(_WORD **)(a2 + 112) = (unsigned __int8)v2[95] + 2;
    qdf_mem_copy((void *)(*(_QWORD *)(a2 + 112) + 2LL), v2 + 94, **(unsigned __int16 **)(a2 + 112));
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: FT-FILS: Join req is NULL",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "lim_generate_fils_pmkr1_name");
  }
  result = 0;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
