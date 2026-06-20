__int64 __fastcall ttlm_valid_n_copy_for_rx_req(
        __int64 a1,
        __int64 a2,
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
  __int64 v11; // x22
  __int64 v12; // x8
  __int64 v13; // x19
  __int64 v14; // x8
  unsigned __int8 *v15; // x8
  int v16; // w9
  int v17; // w11
  int v18; // w8
  __int64 v19; // x10
  __int16 v20; // w9
  __int16 v21; // w11
  __int16 v22; // w8
  __int16 v23; // w9
  unsigned __int64 v24; // x8
  __int64 v25; // x4
  __int64 result; // x0
  __int64 v27; // x20
  __int64 v28; // x21
  __int64 v29; // x23
  __int64 v30; // x9
  char v31; // w24
  __int64 v32; // x23
  __int16 *v33; // x10
  int v34; // w11
  __int16 v35; // w11
  int v36; // w12
  __int16 v37; // w15
  unsigned __int64 v38; // x14
  __int16 v39; // w16
  __int16 v40; // w17
  __int64 v41; // x5
  int v42; // w3
  __int16 v43; // w6
  __int16 v44; // w20
  __int16 v45; // w21
  __int16 v46; // w25
  int v47; // w30
  unsigned __int64 v48; // x15
  bool v49; // zf
  char v50; // w17
  bool v51; // nf
  bool v52; // zf
  unsigned __int64 v53; // x13
  char v54; // w16
  bool v55; // nf
  unsigned int v56; // w11
  bool v57; // w14
  bool v58; // nf
  char v59; // w12
  __int64 v60; // x21
  __int64 v61; // x25
  unsigned int v62; // w20
  __int64 v63; // x26
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned __int16 *v80; // x8
  char v81; // w0
  __int64 v82; // [xsp+10h] [xbp-20h] BYREF
  __int64 v83; // [xsp+18h] [xbp-18h]
  unsigned __int16 v84; // [xsp+20h] [xbp-10h]
  __int64 v85; // [xsp+28h] [xbp-8h]

  v85 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a2 + 784);
  if ( !v11 )
    goto LABEL_17;
  v12 = *(_QWORD *)(a1 + 216);
  v84 = 0;
  v82 = 0;
  v83 = 0;
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    qdf_trace_msg(0x99u, 2u, "%s: PSOC is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "t2lm_is_valid_t2lm_link_map");
    v25 = 3;
LABEL_16:
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: reject t2lm conf, dir %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "ttlm_valid_n_copy_for_rx_req",
      v25);
LABEL_17:
    result = 16;
    goto LABEL_18;
  }
  v14 = *(_QWORD *)(a1 + 1360);
  if ( v14 )
  {
    v15 = *(unsigned __int8 **)(v14 + 3880);
    v16 = v15[6];
    v17 = v15[54];
    v18 = v15[102];
    v19 = 1LL << v18;
    if ( v16 == 255 )
      v20 = 0;
    else
      v20 = 1LL << v16;
    if ( v17 == 255 )
      v21 = 0;
    else
      v21 = 1LL << v17;
    v49 = v18 == 255;
    v22 = v21 | v20;
    if ( v49 )
      v23 = 0;
    else
      v23 = v19;
    v24 = (unsigned __int16)(v22 | v23);
  }
  else
  {
    v27 = a1;
    v28 = a2;
    v29 = a3;
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: MLO dev context failed",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "t2lm_get_connected_link_id");
    a2 = v28;
    a1 = v27;
    a3 = v29;
    v24 = 0;
  }
  v30 = 0;
  v31 = 0;
  v32 = a3 + 8;
  v33 = (__int16 *)(a3 + 38);
  v25 = 3;
  do
  {
    v34 = *(_DWORD *)(v33 - 15);
    if ( v34 != 4 )
    {
      if ( v34 == 2 && (*(_BYTE *)(v33 - 13) & 1) != 0 )
      {
        v31 = 1;
        v25 = (unsigned int)v30;
      }
      else
      {
        v35 = *(v33 - 7);
        if ( (v35 & 1) != 0 && (v24 & 1) == 0 )
          goto LABEL_16;
        v25 = (v35 & 1) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v35 & 2) != 0 && (v24 & 2) == 0 )
          goto LABEL_16;
        v25 = (v35 & 2) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v35 & 4) != 0 && (v24 & 4) == 0 )
          goto LABEL_16;
        v25 = (v35 & 4) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v35 & 8) != 0 && (v24 & 8) == 0 )
          goto LABEL_16;
        v25 = (v35 & 8) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v35 & 0x10) != 0 && (v24 & 0x10) == 0 )
          goto LABEL_16;
        v25 = (v35 & 0x10) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v35 & 0x20) != 0 && (v24 & 0x20) == 0 )
          goto LABEL_16;
        v25 = (v35 & 0x20) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v35 & 0x40) != 0 && (v24 & 0x40) == 0 )
          goto LABEL_16;
        v25 = (v35 & 0x40) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v35 & 0x80) != 0 && (v24 & 0x80) == 0 )
          goto LABEL_16;
        v25 = (v35 & 0x80) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 7) & 0x100) != 0 && (v24 & 0x100) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 7) & 0x100) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 7) & 0x200) != 0 && (v24 & 0x200) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 7) & 0x200) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 7) & 0x400) != 0 && (v24 & 0x400) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 7) & 0x400) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 7) & 0x800) != 0 && (v24 & 0x800) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 7) & 0x800) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 7) & 0x1000) != 0 && (v24 & 0x1000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 7) & 0x1000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 7) & 0x2000) != 0 && (v24 & 0x2000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 7) & 0x2000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 7) & 0x4000) != 0 && (v24 & 0x4000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 7) & 0x4000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( *(v33 - 7) < 0 && v24 < 0x8000 )
          goto LABEL_16;
        v36 = v35;
        v37 = *(v33 - 6);
        v25 = v35 < 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v37 & 1) != 0 && (v24 & 1) == 0 )
          goto LABEL_16;
        v38 = v37 & 1;
        v25 = (v37 & 1) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v37 & 2) != 0 && (v24 & 2) == 0 )
          goto LABEL_16;
        v25 = (v37 & 2) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v37 & 4) != 0 && (v24 & 4) == 0 )
          goto LABEL_16;
        v25 = (v37 & 4) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v37 & 8) != 0 && (v24 & 8) == 0 )
          goto LABEL_16;
        v25 = (v37 & 8) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v37 & 0x10) != 0 && (v24 & 0x10) == 0 )
          goto LABEL_16;
        v25 = (v37 & 0x10) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v37 & 0x20) != 0 && (v24 & 0x20) == 0 )
          goto LABEL_16;
        v25 = (v37 & 0x20) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v37 & 0x40) != 0 && (v24 & 0x40) == 0 )
          goto LABEL_16;
        v25 = (v37 & 0x40) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v37 & 0x80) != 0 && (v24 & 0x80) == 0 )
          goto LABEL_16;
        v25 = (v37 & 0x80) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 6) & 0x100) != 0 && (v24 & 0x100) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 6) & 0x100) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 6) & 0x200) != 0 && (v24 & 0x200) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 6) & 0x200) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 6) & 0x400) != 0 && (v24 & 0x400) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 6) & 0x400) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 6) & 0x800) != 0 && (v24 & 0x800) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 6) & 0x800) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 6) & 0x1000) != 0 && (v24 & 0x1000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 6) & 0x1000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 6) & 0x2000) != 0 && (v24 & 0x2000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 6) & 0x2000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 6) & 0x4000) != 0 && (v24 & 0x4000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 6) & 0x4000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( *(v33 - 6) < 0 && v24 < 0x8000 )
          goto LABEL_16;
        v39 = *(v33 - 5);
        v25 = v37 < 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v39 & 1) != 0 && (v24 & 1) == 0 )
          goto LABEL_16;
        v25 = (v39 & 1) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v39 & 2) != 0 && (v24 & 2) == 0 )
          goto LABEL_16;
        v25 = (v39 & 2) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v39 & 4) != 0 && (v24 & 4) == 0 )
          goto LABEL_16;
        v25 = (v39 & 4) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v39 & 8) != 0 && (v24 & 8) == 0 )
          goto LABEL_16;
        v25 = (v39 & 8) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v39 & 0x10) != 0 && (v24 & 0x10) == 0 )
          goto LABEL_16;
        v25 = (v39 & 0x10) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v39 & 0x20) != 0 && (v24 & 0x20) == 0 )
          goto LABEL_16;
        v25 = (v39 & 0x20) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v39 & 0x40) != 0 && (v24 & 0x40) == 0 )
          goto LABEL_16;
        v25 = (v39 & 0x40) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v39 & 0x80) != 0 && (v24 & 0x80) == 0 )
          goto LABEL_16;
        v25 = (v39 & 0x80) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 5) & 0x100) != 0 && (v24 & 0x100) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 5) & 0x100) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 5) & 0x200) != 0 && (v24 & 0x200) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 5) & 0x200) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 5) & 0x400) != 0 && (v24 & 0x400) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 5) & 0x400) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 5) & 0x800) != 0 && (v24 & 0x800) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 5) & 0x800) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 5) & 0x1000) != 0 && (v24 & 0x1000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 5) & 0x1000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 5) & 0x2000) != 0 && (v24 & 0x2000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 5) & 0x2000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 5) & 0x4000) != 0 && (v24 & 0x4000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 5) & 0x4000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( *(v33 - 5) < 0 && v24 < 0x8000 )
          goto LABEL_16;
        v40 = *(v33 - 4);
        v25 = v39 < 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v40 & 1) != 0 && (v24 & 1) == 0 )
          goto LABEL_16;
        v25 = (v40 & 1) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v40 & 2) != 0 && (v24 & 2) == 0 )
          goto LABEL_16;
        v25 = (v40 & 2) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v40 & 4) != 0 && (v24 & 4) == 0 )
          goto LABEL_16;
        v25 = (v40 & 4) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v40 & 8) != 0 && (v24 & 8) == 0 )
          goto LABEL_16;
        v25 = (v40 & 8) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v40 & 0x10) != 0 && (v24 & 0x10) == 0 )
          goto LABEL_16;
        v25 = (v40 & 0x10) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v40 & 0x20) != 0 && (v24 & 0x20) == 0 )
          goto LABEL_16;
        v25 = (v40 & 0x20) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v40 & 0x40) != 0 && (v24 & 0x40) == 0 )
          goto LABEL_16;
        v25 = (v40 & 0x40) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v40 & 0x80) != 0 && (v24 & 0x80) == 0 )
          goto LABEL_16;
        v25 = (v40 & 0x80) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 4) & 0x100) != 0 && (v24 & 0x100) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 4) & 0x100) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 4) & 0x200) != 0 && (v24 & 0x200) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 4) & 0x200) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 4) & 0x400) != 0 && (v24 & 0x400) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 4) & 0x400) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 4) & 0x800) != 0 && (v24 & 0x800) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 4) & 0x800) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 4) & 0x1000) != 0 && (v24 & 0x1000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 4) & 0x1000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 4) & 0x2000) != 0 && (v24 & 0x2000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 4) & 0x2000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 4) & 0x4000) != 0 && (v24 & 0x4000) == 0 )
          goto LABEL_16;
        v41 = v40 & 0x4000;
        v25 = (*(v33 - 4) & 0x4000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( *(v33 - 4) < 0 && v24 < 0x8000 )
          goto LABEL_16;
        v42 = v40;
        v43 = *(v33 - 3);
        v25 = v40 < 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v43 & 1) != 0 && (v24 & 1) == 0 )
          goto LABEL_16;
        v25 = (v43 & 1) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v43 & 2) != 0 && (v24 & 2) == 0 )
          goto LABEL_16;
        v25 = (v43 & 2) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v43 & 4) != 0 && (v24 & 4) == 0 )
          goto LABEL_16;
        v25 = (v43 & 4) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v43 & 8) != 0 && (v24 & 8) == 0 )
          goto LABEL_16;
        v25 = (v43 & 8) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v43 & 0x10) != 0 && (v24 & 0x10) == 0 )
          goto LABEL_16;
        v25 = (v43 & 0x10) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v43 & 0x20) != 0 && (v24 & 0x20) == 0 )
          goto LABEL_16;
        v25 = (v43 & 0x20) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v43 & 0x40) != 0 && (v24 & 0x40) == 0 )
          goto LABEL_16;
        v25 = (v43 & 0x40) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v43 & 0x80) != 0 && (v24 & 0x80) == 0 )
          goto LABEL_16;
        v25 = (v43 & 0x80) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 3) & 0x100) != 0 && (v24 & 0x100) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 3) & 0x100) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 3) & 0x200) != 0 && (v24 & 0x200) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 3) & 0x200) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 3) & 0x400) != 0 && (v24 & 0x400) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 3) & 0x400) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 3) & 0x800) != 0 && (v24 & 0x800) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 3) & 0x800) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 3) & 0x1000) != 0 && (v24 & 0x1000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 3) & 0x1000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 3) & 0x2000) != 0 && (v24 & 0x2000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 3) & 0x2000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 3) & 0x4000) != 0 && (v24 & 0x4000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 3) & 0x4000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( *(v33 - 3) < 0 && v24 < 0x8000 )
          goto LABEL_16;
        v44 = *(v33 - 2);
        v25 = v43 < 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v44 & 1) != 0 && (v24 & 1) == 0 )
          goto LABEL_16;
        v25 = (v44 & 1) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v44 & 2) != 0 && (v24 & 2) == 0 )
          goto LABEL_16;
        v25 = (v44 & 2) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v44 & 4) != 0 && (v24 & 4) == 0 )
          goto LABEL_16;
        v25 = (v44 & 4) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v44 & 8) != 0 && (v24 & 8) == 0 )
          goto LABEL_16;
        v25 = (v44 & 8) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v44 & 0x10) != 0 && (v24 & 0x10) == 0 )
          goto LABEL_16;
        v25 = (v44 & 0x10) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v44 & 0x20) != 0 && (v24 & 0x20) == 0 )
          goto LABEL_16;
        v25 = (v44 & 0x20) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v44 & 0x40) != 0 && (v24 & 0x40) == 0 )
          goto LABEL_16;
        v25 = (v44 & 0x40) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v44 & 0x80) != 0 && (v24 & 0x80) == 0 )
          goto LABEL_16;
        v25 = (v44 & 0x80) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 2) & 0x100) != 0 && (v24 & 0x100) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 2) & 0x100) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 2) & 0x200) != 0 && (v24 & 0x200) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 2) & 0x200) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 2) & 0x400) != 0 && (v24 & 0x400) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 2) & 0x400) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 2) & 0x800) != 0 && (v24 & 0x800) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 2) & 0x800) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 2) & 0x1000) != 0 && (v24 & 0x1000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 2) & 0x1000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 2) & 0x2000) != 0 && (v24 & 0x2000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 2) & 0x2000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 2) & 0x4000) != 0 && (v24 & 0x4000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 2) & 0x4000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( *(v33 - 2) < 0 && v24 < 0x8000 )
          goto LABEL_16;
        v45 = *(v33 - 1);
        v25 = v44 < 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v45 & 1) != 0 && (v24 & 1) == 0 )
          goto LABEL_16;
        v25 = (v45 & 1) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v45 & 2) != 0 && (v24 & 2) == 0 )
          goto LABEL_16;
        v25 = (v45 & 2) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v45 & 4) != 0 && (v24 & 4) == 0 )
          goto LABEL_16;
        v25 = (v45 & 4) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v45 & 8) != 0 && (v24 & 8) == 0 )
          goto LABEL_16;
        v25 = (v45 & 8) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v45 & 0x10) != 0 && (v24 & 0x10) == 0 )
          goto LABEL_16;
        v25 = (v45 & 0x10) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v45 & 0x20) != 0 && (v24 & 0x20) == 0 )
          goto LABEL_16;
        v25 = (v45 & 0x20) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v45 & 0x40) != 0 && (v24 & 0x40) == 0 )
          goto LABEL_16;
        v25 = (v45 & 0x40) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v45 & 0x80) != 0 && (v24 & 0x80) == 0 )
          goto LABEL_16;
        v25 = (v45 & 0x80) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 1) & 0x100) != 0 && (v24 & 0x100) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 1) & 0x100) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 1) & 0x200) != 0 && (v24 & 0x200) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 1) & 0x200) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 1) & 0x400) != 0 && (v24 & 0x400) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 1) & 0x400) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 1) & 0x800) != 0 && (v24 & 0x800) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 1) & 0x800) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 1) & 0x1000) != 0 && (v24 & 0x1000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 1) & 0x1000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 1) & 0x2000) != 0 && (v24 & 0x2000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 1) & 0x2000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*(v33 - 1) & 0x4000) != 0 && (v24 & 0x4000) == 0 )
          goto LABEL_16;
        v25 = (*(v33 - 1) & 0x4000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( *(v33 - 1) < 0 && v24 < 0x8000 )
          goto LABEL_16;
        v46 = *v33;
        v25 = v45 < 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v46 & 1) != 0 && (v24 & 1) == 0 )
          goto LABEL_16;
        v25 = (v46 & 1) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v46 & 2) != 0 && (v24 & 2) == 0 )
          goto LABEL_16;
        v25 = (v46 & 2) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v46 & 4) != 0 && (v24 & 4) == 0 )
          goto LABEL_16;
        v25 = (v46 & 4) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v46 & 8) != 0 && (v24 & 8) == 0 )
          goto LABEL_16;
        v25 = (v46 & 8) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v46 & 0x10) != 0 && (v24 & 0x10) == 0 )
          goto LABEL_16;
        v25 = (v46 & 0x10) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v46 & 0x20) != 0 && (v24 & 0x20) == 0 )
          goto LABEL_16;
        v25 = (v46 & 0x20) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v46 & 0x40) != 0 && (v24 & 0x40) == 0 )
          goto LABEL_16;
        v25 = (v46 & 0x40) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (v46 & 0x80) != 0 && (v24 & 0x80) == 0 )
          goto LABEL_16;
        v25 = (v46 & 0x80) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*v33 & 0x100) != 0 && (v24 & 0x100) == 0 )
          goto LABEL_16;
        v25 = (*v33 & 0x100) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*v33 & 0x200) != 0 && (v24 & 0x200) == 0 )
          goto LABEL_16;
        v25 = (*v33 & 0x200) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*v33 & 0x400) != 0 && (v24 & 0x400) == 0 )
          goto LABEL_16;
        v25 = (*v33 & 0x400) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*v33 & 0x800) != 0 && (v24 & 0x800) == 0 )
          goto LABEL_16;
        v25 = (*v33 & 0x800) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*v33 & 0x1000) != 0 && (v24 & 0x1000) == 0 )
          goto LABEL_16;
        v25 = (*v33 & 0x1000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*v33 & 0x2000) != 0 && (v24 & 0x2000) == 0 )
          goto LABEL_16;
        v25 = (*v33 & 0x2000) != 0 ? (unsigned int)v30 : (unsigned int)v25;
        if ( (*v33 & 0x4000) != 0 && (v24 & 0x4000) == 0 )
          goto LABEL_16;
        v47 = (__int16)(v37 | v39);
        v48 = v37 & 0x7FFE | (unsigned __int64)(v39 & 0x7FFF) | v40 & 0x3FFF;
        v49 = v47 >= 0 && v48 == 0;
        v50 = !v49;
        if ( v41 | v43 & 1 )
          v51 = 1;
        else
          v51 = v42 < 0;
        if ( v51 )
          v50 = 1;
        v52 = ((v43 | v44) & 0x8000u) == 0 && (v43 & 0x7FFE | (unsigned __int64)(v44 & 0x7FFF) | v45 & 0x3FFF) == 0;
        v53 = v35 & 0x4000 | v38 | v35 & 0x3FFF;
        v54 = !v52;
        if ( v45 & 0x4000 | (unsigned __int64)(v46 & 1) )
          v55 = 1;
        else
          v55 = v45 < 0;
        if ( v55 )
          v54 = 1;
        if ( (*v33 & 0x4000) != 0 )
          v56 = v30;
        else
          v56 = v25;
        v57 = v46 < 0 || (v46 & 0x7FFE) != 0;
        if ( v46 < 0 )
          v25 = (unsigned int)v30;
        else
          v25 = v56;
        if ( v53 )
          v58 = 1;
        else
          v58 = v36 < 0;
        v59 = v57 | v54 | v50;
        if ( v58 )
          v59 = 1;
        v31 |= v59;
        if ( *v33 < 0 && v24 < 0x8000 )
        {
          v25 = v56;
          goto LABEL_16;
        }
      }
    }
    ++v30;
    v33 += 26;
  }
  while ( v30 != 3 );
  v60 = a2;
  v61 = a3;
  v62 = v25;
  v63 = a1;
  ml_nlink_get_curr_force_state(v13, a1, &v82);
  qdf_trace_msg(
    0x99u,
    8u,
    "%s: Current force state force_inactive_bitmap: %d force_active_bitmap: %d curr_dynamic_inactive_bitmap: %d curr_acti"
    "ve_bitmap: %d curr_inactive_bitmap: %d",
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    "t2lm_is_valid_t2lm_link_map",
    WORD1(v82),
    (unsigned __int16)v82,
    WORD2(v83),
    HIWORD(v83),
    v84);
  if ( (*(_BYTE *)(v61 + 116) & 1) == 0
    && *(_WORD *)(v61 + 128)
    && (*(unsigned __int16 *)(v61 + 128) & ~WORD1(v82)) == 0 )
  {
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: TTLM req: 0x%x failed due to force_inactive link: 0x%x",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "t2lm_is_valid_t2lm_link_map");
LABEL_709:
    v25 = v62;
    goto LABEL_16;
  }
  if ( ((unsigned __int8)v31 & (v62 < 3)) == 0 )
    goto LABEL_709;
  qdf_trace_msg(
    0x99u,
    8u,
    "%s: Link match found, accept t2lm conf dir:%d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "ttlm_valid_n_copy_for_rx_req",
    v62);
  if ( *(_DWORD *)(v32 + 52LL * v62) != 4 )
  {
    wlan_t2lm_clear_peer_negotiation(v60);
    qdf_mem_copy((void *)(v11 + 52LL * v62 + 220), (const void *)(v32 + 52LL * v62), 0x34u);
  }
  v80 = *(unsigned __int16 **)(v63 + 32);
  if ( v80 )
  {
    v81 = wlan_convert_freq_to_diag_band(*v80);
    wlan_connectivity_t2lm_req_resp_event(v63, *(_BYTE *)(v61 + 4), 0, 0, v81, 1, 45);
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: vdev: %d channel info not found",
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      "ttlm_valid_n_copy_for_rx_req",
      *(unsigned __int8 *)(v63 + 168));
    result = 29;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
