__int64 __fastcall target_if_spectral_scan_enable_params(
        __int64 *a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x22
  __int64 result; // x0
  const char *v16; // x2
  const char *v17; // x2
  int *v20; // x25
  __int64 (*v21)(void); // x9
  int v22; // w0
  _DWORD *v23; // x8
  int v24; // w24
  int v25; // w0
  int v26; // w8
  int v27; // w8
  int v28; // w9
  int v29; // w11
  int v30; // w10
  unsigned int v31; // w10
  int v32; // w10
  char v33; // w9
  __int64 *v34; // x10
  char v35; // w11
  int v36; // w10
  unsigned int v37; // w10
  char v38; // w9
  int v39; // w10
  int v40; // w10
  unsigned int v41; // w8
  int v42; // w10
  _DWORD *v43; // x8
  unsigned int v44; // w22
  _DWORD *v45; // x9
  _DWORD *v46; // x8
  int v47; // w0
  _DWORD *v48; // x8
  int v49; // w21
  int v50; // w8
  unsigned int (__fastcall *v51)(_QWORD); // x8
  __int64 *v52; // x8
  __int64 v53; // x9
  __int64 *v54; // x10
  __int64 v55; // x11
  _DWORD *v56; // x8
  _DWORD *v57; // x8
  __int64 v58; // x8

  if ( !a1 )
  {
    v16 = "%s: Spectral LMAC object is NULL";
    goto LABEL_7;
  }
  v12 = *a1;
  if ( !*a1 )
  {
    v17 = "%s: pdev is null";
LABEL_10:
    qdf_trace_msg(0x56u, 2u, v17, a5, a6, a7, a8, a9, a10, a11, a12, "target_if_spectral_scan_enable_params");
    return 4;
  }
  if ( !*(_QWORD *)(v12 + 80) )
  {
    v17 = "%s: psoc is null";
    goto LABEL_10;
  }
  if ( a3 >= 2 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Invalid Spectral mode %u",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "target_if_spectral_scan_enable_params",
      a3);
    return 1;
  }
  v20 = (int *)((char *)a1 + 802);
  v21 = (__int64 (*)(void))a1[9];
  *((_BYTE *)a1 + 512) = a1[64] & 0xF7 | (8 * (*(_WORD *)(a2 + 12) != 0));
  if ( *((_DWORD *)v21 - 1) != 362784388 )
    __break(0x8229u);
  v22 = v21();
  v23 = (_DWORD *)a1[16];
  v24 = v22;
  if ( *(v23 - 1) != 362784388 )
    __break(0x8228u);
  v25 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v23)(a1, a3);
  if ( !*((_BYTE *)a1 + 187) )
  {
    if ( v24 )
    {
      a1[67] = 0x8000000080LL;
      *((_DWORD *)a1 + 136) = 138;
      v33 = *((_BYTE *)a1 + 512);
      *(__int64 *)((char *)a1 + 556) = 0x85FFFFFFFFLL;
      *(__int64 *)((char *)a1 + 564) = 0x4000000082LL;
      *((_BYTE *)a1 + 512) = v33 | 4;
      if ( v24 >= v25 )
      {
        *(_DWORD *)((char *)a1 + 814) = v24;
        *(_DWORD *)((char *)a1 + 818) = v25;
      }
      else
      {
        *(_DWORD *)((char *)a1 + 814) = v25;
        *(_DWORD *)((char *)a1 + 818) = v24;
      }
    }
    else
    {
      *(_DWORD *)((char *)a1 + 814) = 0;
      *(_DWORD *)((char *)a1 + 818) = v25;
      *(__int64 *)((char *)a1 + 564) = 0x1CFFFFFFFFLL;
      *(__int64 *)((char *)a1 + 556) = -4294967238LL;
      v38 = *((_BYTE *)a1 + 512);
      a1[67] = 0x3800000038LL;
      *((_DWORD *)a1 + 136) = 63;
      *((_BYTE *)a1 + 512) = v38 & 0xFB;
    }
    goto LABEL_53;
  }
  v26 = *((unsigned __int8 *)a1 + 1249);
  *(__int64 *)((char *)a1 + 548) = 0;
  if ( v26 == 1 && WORD2(a1[10 * a3 + 84]) == 2 )
  {
    v27 = 4;
    *((_DWORD *)a1 + 137) = 4;
  }
  else
  {
    v27 = 0;
  }
  if ( *((_BYTE *)a1 + 1250) == 1 && WORD2(a1[10 * a3 + 84]) == 2 )
  {
    v28 = 4;
    *((_DWORD *)a1 + 138) = 4;
  }
  else
  {
    v28 = 0;
  }
  v29 = *((_DWORD *)a1 + a3 + 296);
  switch ( v29 )
  {
    case 2:
      goto LABEL_35;
    case 1:
      v34 = &a1[10 * a3];
      v35 = *((_BYTE *)a1 + 512) | 4;
LABEL_36:
      v36 = *((unsigned __int16 *)v34 + 327);
      *((_BYTE *)a1 + 512) = v35;
      v37 = v36 - 5;
      if ( v37 > 4 )
        v32 = 0;
      else
        v32 = dword_A2CC98[(unsigned __int16)v37];
      *((_DWORD *)a1 + 134) = v32;
      *((_DWORD *)a1 + 135) = v32;
      *((_DWORD *)a1 + 136) = v32;
      if ( v24 >= v25 )
      {
        *(_DWORD *)((char *)a1 + 814) = v24;
        *(_DWORD *)((char *)a1 + 818) = v25;
      }
      else
      {
        *(_DWORD *)((char *)a1 + 814) = v25;
        *(_DWORD *)((char *)a1 + 818) = v24;
      }
      goto LABEL_47;
    case 0:
      v30 = HIWORD(a1[10 * a3 + 81]);
      *((_BYTE *)a1 + 512) &= ~4u;
      v31 = v30 - 5;
      if ( v31 > 4 )
        v32 = 0;
      else
        v32 = dword_A2CC98[(unsigned __int16)v31];
      *((_DWORD *)a1 + 134) = v32;
      *((_DWORD *)a1 + 135) = v32;
      *((_DWORD *)a1 + 136) = v32;
      *(_DWORD *)((char *)a1 + 814) = 0;
      *(_DWORD *)((char *)a1 + 818) = v25;
      goto LABEL_47;
  }
  if ( (unsigned int)(v29 - 3) < 2 )
  {
LABEL_35:
    v34 = &a1[10 * a3];
    v35 = a1[64] & 0xFB;
    goto LABEL_36;
  }
  v32 = *((_DWORD *)a1 + 134);
LABEL_47:
  if ( v32 )
    *((_DWORD *)a1 + 134) = v28 + v27 + v32;
  v39 = *((_DWORD *)a1 + 135);
  if ( v39 )
    *((_DWORD *)a1 + 135) = v28 + v27 + v39;
  v40 = *((_DWORD *)a1 + 136);
  if ( v40 )
    *((_DWORD *)a1 + 136) = v28 + v27 + v40;
LABEL_53:
  v41 = *((unsigned __int8 *)a1 + 512);
  v42 = *((_DWORD *)a1 + 142);
  *((_DWORD *)a1 + 145) = 0;
  *(__int64 *)((char *)a1 + 572) = 0;
  *((_DWORD *)a1 + 207) = 0;
  *v20 = (v41 >> 2) & 1;
  *(_DWORD *)((char *)a1 + 806) = v42;
  v43 = (_DWORD *)a1[5];
  if ( *(v43 - 1) != 362784388 )
    __break(0x8228u);
  if ( !((unsigned int (__fastcall *)(__int64 *, _QWORD))v43)(a1, a3) )
  {
    v51 = (unsigned int (__fastcall *)(_QWORD))a1[164];
    if ( *((_DWORD *)v51 - 1) != -2099273483 )
      __break(0x8228u);
    if ( v51(v12) )
    {
      v16 = "%s: Failed to reset transport specific buffer.";
    }
    else
    {
      v56 = (_DWORD *)a1[12];
      if ( *(v56 - 1) != 2051770554 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64 *, __int64, _QWORD))v56)(a1, a2, a3);
      *((_BYTE *)a1 + 14 * a3 + 1414) = 0;
      if ( !HIWORD(a1[10 * a3 + 80]) || !(unsigned int)target_if_spectral_finite_scan_init(a1, a3) )
      {
        v57 = (_DWORD *)a1[7];
        v44 = a3;
        if ( *(v57 - 1) != 1272303925 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64 *, _QWORD, __int64))v57)(a1, a3, a4);
        v58 = (__int64)a1 + 4 * a3;
        *(_DWORD *)(v58 + 1352) = 0;
        *(_DWORD *)(v58 + 1368) = 0;
        goto LABEL_57;
      }
      v16 = "%s: Failed to init finite scan";
    }
LABEL_7:
    qdf_trace_msg(0x56u, 2u, v16, a5, a6, a7, a8, a9, a10, a11, a12, "target_if_spectral_scan_enable_params");
    return 1;
  }
  v44 = a3;
LABEL_57:
  v45 = (_DWORD *)a1[13];
  if ( *(v45 - 1) != 2051770554 )
    __break(0x8229u);
  ((void (__fastcall *)(__int64 *, __int64 *, _QWORD))v45)(a1, &a1[10 * v44 + 80], a3);
  v46 = (_DWORD *)a1[16];
  if ( *(v46 - 1) != 362784388 )
    __break(0x8228u);
  v47 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v46)(a1, a3);
  v48 = (_DWORD *)a1[9];
  v49 = v47;
  if ( *(v48 - 1) != 362784388 )
    __break(0x8228u);
  v50 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v48)(a1, a3);
  result = 0;
  if ( v49 && v50 )
  {
    if ( (a1[64] & 4) != 0 )
    {
      result = 0;
      if ( v50 >= v49 )
      {
        v52 = (__int64 *)((char *)a1 + 516);
        v53 = 0x100000000LL;
        v54 = (__int64 *)((char *)a1 + 524);
        v55 = 1;
      }
      else
      {
        v52 = (__int64 *)((char *)a1 + 516);
        v53 = 1;
        v54 = (__int64 *)((char *)a1 + 524);
        v55 = 0x100000000LL;
      }
      *v52 = v53;
      *v54 = v55;
    }
    else
    {
      *(__int64 *)((char *)a1 + 516) = 0;
      *(__int64 *)((char *)a1 + 524) = 1;
      return 0;
    }
  }
  return result;
}
