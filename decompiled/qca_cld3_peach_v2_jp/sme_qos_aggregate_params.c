__int64 __fastcall sme_qos_aggregate_params(
        __int64 a1,
        unsigned int *a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w9
  unsigned int v23; // w8
  const char *v24; // x2
  __int64 result; // x0
  unsigned int v26; // w11
  unsigned int v27; // w8
  unsigned int v28; // w10
  int v29; // w9
  unsigned int v30; // w8
  unsigned int v31; // w10
  int v32; // w15
  unsigned int v33; // w13
  unsigned int v34; // w14
  unsigned int v35; // w12
  __int16 v36; // w16
  __int16 v37; // w9
  int v38; // w0
  unsigned int v39; // w17
  bool v40; // zf
  unsigned int v41; // w16
  unsigned int v42; // w11
  int v43; // w13
  __int16 v44; // w14
  bool v45; // cc
  __int16 v46; // w8
  bool v47; // cf
  int v48; // w9
  int v49; // w13
  int v50; // w17
  int v51; // w8
  int v52; // w11
  int v53; // w11
  __int16 v54; // w8
  unsigned int *v55; // x0
  __int64 v56; // [xsp+8h] [xbp-58h] BYREF
  __int64 v57; // [xsp+10h] [xbp-50h]
  __int64 v58; // [xsp+18h] [xbp-48h]
  __int64 v59; // [xsp+20h] [xbp-40h]
  __int64 v60; // [xsp+28h] [xbp-38h]
  __int64 v61; // [xsp+30h] [xbp-30h]
  unsigned __int64 v62; // [xsp+38h] [xbp-28h]
  __int64 v63; // [xsp+40h] [xbp-20h]
  __int64 v64; // [xsp+48h] [xbp-18h]
  int v65; // [xsp+50h] [xbp-10h]
  __int64 v66; // [xsp+58h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v65 = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v56 = 0;
  qdf_trace_msg(0x34u, 8u, "%s: invoked", a4, a5, a6, a7, a8, a9, a10, a11, "sme_qos_aggregate_params");
  if ( !a1 )
  {
    v24 = "%s: input is NULL, nothing to aggregate";
LABEL_11:
    qdf_trace_msg(0x34u, 2u, v24, v14, v15, v16, v17, v18, v19, v20, v21, "sme_qos_aggregate_params");
    result = 16;
    goto LABEL_62;
  }
  if ( !a2 )
  {
    v24 = "%s: Current is NULL, can't aggregate";
    goto LABEL_11;
  }
  qdf_mem_copy(&v56, a2, 0x4Cu);
  v22 = a2[7];
  v23 = *(_DWORD *)(a1 + 28);
  BYTE4(v57) = *(_BYTE *)(a1 + 12);
  if ( v22 )
  {
    if ( !v23 )
      goto LABEL_14;
    if ( v22 >= v23 )
      v22 = v23;
    if ( a2[4] != *(_DWORD *)(a1 + 16) )
      v23 = v22;
  }
  else if ( !v23 )
  {
    goto LABEL_14;
  }
  HIDWORD(v59) = v23;
LABEL_14:
  v26 = a2[8];
  v27 = *(_DWORD *)(a1 + 32);
  if ( v26 && v27 && (v28 = a2[4], v29 = *(_DWORD *)(a1 + 16), v28 != v29) )
  {
    if ( v26 < v27 )
      v27 = a2[8];
  }
  else
  {
    v28 = a2[4];
    v29 = *(_DWORD *)(a1 + 16);
  }
  LODWORD(v60) = v27;
  if ( v28 != v29 )
    LODWORD(v58) = v29;
  v30 = *((unsigned __int16 *)a2 + 13);
  v31 = a2[9];
  v32 = *(_DWORD *)(a1 + 40);
  v34 = a2[15];
  v33 = a2[16];
  v35 = *(_DWORD *)(a1 + 64);
  v36 = *(_WORD *)(a1 + 24);
  if ( v30 <= *(unsigned __int16 *)(a1 + 26) )
    LOWORD(v30) = *(_WORD *)(a1 + 26);
  v37 = *((_WORD *)a2 + 12);
  if ( v31 <= *(_DWORD *)(a1 + 36) )
    v31 = *(_DWORD *)(a1 + 36);
  v38 = v36;
  if ( v33 >= v35 )
    v39 = *(_DWORD *)(a1 + 64);
  else
    v39 = a2[16];
  v40 = v33 == 0;
  v41 = v36 & 0x7FFF;
  v43 = *(_DWORD *)(a1 + 56);
  v42 = *(_DWORD *)(a1 + 60);
  if ( !v40 )
    v35 = v39;
  WORD1(v59) = v30;
  HIDWORD(v60) = v31;
  LODWORD(v61) = v32;
  if ( v34 > v42 )
    v42 = v34;
  if ( (v37 & 0x7FFFu) <= v41 )
    v44 = v41;
  else
    v44 = v37 & 0x7FFF;
  HIDWORD(v63) = v42;
  LODWORD(v64) = v35;
  v45 = v38 <= 0 && v37 <= 0;
  HIDWORD(v64) = 6000000;
  if ( v45 )
    v46 = v44 | 0x8000;
  else
    v46 = v44;
  HIWORD(v65) = 0;
  v47 = __CFADD__((_DWORD)v63, v43);
  v48 = v63 + v43;
  LOWORD(v59) = v46;
  v49 = *(_DWORD *)(a1 + 48);
  v50 = *(_DWORD *)(a1 + 52);
  if ( v47 )
    v48 = -1;
  if ( __CFADD__((_DWORD)v62, v49) )
    v51 = -1;
  else
    v51 = v62 + v49;
  v52 = HIDWORD(v62) + v50;
  if ( __CFADD__(HIDWORD(v62), v50) )
    v52 = -1;
  HIDWORD(v61) = 0;
  v62 = __PAIR64__(v52, v51);
  LODWORD(v63) = v48;
  v53 = *(_DWORD *)(a1 + 4);
  if ( (((_WORD)v65 + *(_WORD *)(a1 + 72)) & 0xE000) != 0 )
    v54 = 0x2000;
  else
    v54 = v65 + *(_WORD *)(a1 + 72);
  LOWORD(v65) = v54;
  if ( v53 == 3 || a2[1] == 3 )
    HIDWORD(v56) = 3;
  if ( *(_BYTE *)a1 || *(_BYTE *)a2 )
    LOBYTE(v56) = 1;
  if ( a3 )
    v55 = a3;
  else
    v55 = a2;
  qdf_mem_copy(v55, &v56, 0x4Cu);
  result = 0;
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return result;
}
