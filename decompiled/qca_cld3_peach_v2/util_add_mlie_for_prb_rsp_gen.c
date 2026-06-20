__int64 __fastcall util_add_mlie_for_prb_rsp_gen(
        unsigned __int8 *a1,
        unsigned __int64 a2,
        void **a3,
        _QWORD *a4,
        __int64 a5,
        unsigned __int8 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  unsigned __int64 v15; // x19
  unsigned int v16; // w20
  const void *v18; // x22
  char *v19; // x20
  __int64 v20; // x25
  __int64 v21; // x24
  unsigned __int8 v22; // w28
  void **v23; // x27
  char *v24; // x23
  _QWORD *v25; // x20
  __int64 v26; // x26
  unsigned __int8 v27; // w25
  unsigned __int64 v28; // x8
  unsigned __int64 v29; // x21
  const void *v30; // x24
  void **v31; // x27
  unsigned __int8 v32; // w26
  __int64 v33; // x0
  _BYTE *v34; // x23
  unsigned int v35; // w19
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned __int8 *v52; // [xsp+8h] [xbp-18h]
  _QWORD *v53; // [xsp+8h] [xbp-18h]
  int v54; // [xsp+10h] [xbp-10h] BYREF
  char v55; // [xsp+14h] [xbp-Ch]
  __int64 v56; // [xsp+18h] [xbp-8h]

  LODWORD(v15) = 0;
  v16 = 29;
  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v55 = 0;
  v54 = 0;
  if ( !a1 || !a2 )
    goto LABEL_8;
  if ( a2 < 5 || *a1 != 255 || a1[2] != 107 || (*(_WORD *)(a1 + 3) & 7) != 0 )
  {
    LODWORD(v15) = 0;
    v16 = 4;
LABEL_8:
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Failed to parse common info, mlie len %zu common info len %d",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "util_add_mlie_for_prb_rsp_gen",
      a2,
      (unsigned int)v15);
    goto LABEL_9;
  }
  if ( a2 < 0xC )
  {
    LODWORD(v15) = 0;
    v16 = 27;
    goto LABEL_8;
  }
  v16 = 0;
  v18 = a1 + 5;
  v15 = a1[5];
  if ( a2 < v15 || a2 - v15 <= 4 )
    goto LABEL_8;
  v19 = (char *)*a3;
  v20 = *a4;
  v21 = jiffies;
  v22 = v15 + 5;
  if ( util_add_mlie_for_prb_rsp_gen___last_ticks - jiffies + 125 < 0 )
  {
    v52 = a1;
    v23 = a3;
    v24 = (char *)*a3;
    v25 = a4;
    v26 = *a4;
    v27 = a6;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: mlie_len %d, common_info_len %d, link_id_offset %d",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "util_add_mlie_for_prb_rsp_gen",
      (unsigned __int8)(a1[5] + 5),
      a1[5],
      12);
    a1 = v52;
    a6 = v27;
    v20 = v26;
    a3 = v23;
    a4 = v25;
    v19 = v24;
    util_add_mlie_for_prb_rsp_gen___last_ticks = v21;
  }
  v28 = a5 - v20;
  v29 = (unsigned __int8)(v15 + 5);
  if ( v28 >= v29 )
  {
    v30 = a1;
    v31 = a3;
    v32 = a6;
    v53 = a4;
    v33 = _qdf_mem_malloc((unsigned __int8)(v15 + 5), "util_add_mlie_for_prb_rsp_gen", 1789);
    if ( v33 )
    {
      v34 = (_BYTE *)v33;
      qdf_mem_copy(&v54, v30, 5u);
      BYTE1(v54) = v15 + 3;
      qdf_mem_copy(v34, &v54, 5u);
      v35 = (unsigned __int8)(v15 + 5);
      qdf_mem_copy(v34 + 5, v18, (unsigned int)v22 - 5);
      if ( v32 == 255 || v35 <= 0xC )
      {
        _qdf_mem_free((__int64)v34);
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Failed to process link id, link_id %d",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "util_add_mlie_for_prb_rsp_gen",
          v32);
        v16 = 4;
      }
      else
      {
        v34[12] = v34[12] & 0xF0 | v32 & 0xF;
        qdf_mem_copy(v19, v34, v35);
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: Add mlie for link id %d",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "util_add_mlie_for_prb_rsp_gen",
          v32);
        ((void (__fastcall *)(__int64, __int64, _BYTE *, _QWORD))qdf_trace_hex_dump)(53, 8, v34, v35);
        *v31 = &v19[v29];
        *v53 = v20 + v29;
        _qdf_mem_free((__int64)v34);
        v16 = 0;
      }
    }
    else
    {
      v16 = 2;
    }
  }
  else
  {
    v16 = 2;
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Insufficient space in link specific frame for ML IE. Required: %u octets, available: %zu octets",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "util_add_mlie_for_prb_rsp_gen",
      (unsigned __int8)(v15 + 5),
      v28);
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v16;
}
