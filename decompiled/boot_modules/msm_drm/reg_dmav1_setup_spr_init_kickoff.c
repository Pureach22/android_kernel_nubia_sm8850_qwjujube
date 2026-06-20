__int64 __fastcall reg_dmav1_setup_spr_init_kickoff(
        unsigned int a1,
        int a2,
        int a3,
        __int64 a4,
        __int64 a5,
        char *a6,
        __int64 a7)
{
  __int64 v7; // d14
  char v13; // w8
  int v14; // w8
  unsigned int v15; // w9
  int v16; // w8
  int v17; // w8
  int v18; // w8
  __int64 v19; // x25
  __int64 (__fastcall *v20)(_QWORD); // x8
  unsigned int v21; // w0
  unsigned int v22; // w24
  __int64 (__fastcall *v23)(_QWORD); // x8
  unsigned int v24; // w0
  __int64 v25; // x15
  __int64 v26; // d3
  __int64 v28; // x10
  __int64 v29; // x9
  unsigned int v30; // w8
  unsigned int v31; // w8
  unsigned int v32; // w11
  __int64 v33; // x8
  _DWORD *v34; // x8
  __int64 v35; // [xsp+0h] [xbp-60h] BYREF
  __int64 v36; // [xsp+8h] [xbp-58h]
  __int64 v37; // [xsp+10h] [xbp-50h]
  __int64 v38; // [xsp+18h] [xbp-48h]
  __int64 v39; // [xsp+20h] [xbp-40h]
  __int64 v40; // [xsp+28h] [xbp-38h]
  __int64 v41; // [xsp+30h] [xbp-30h]
  unsigned __int64 v42; // [xsp+38h] [xbp-28h]
  unsigned __int64 v43; // [xsp+40h] [xbp-20h]
  unsigned __int64 v44; // [xsp+48h] [xbp-18h]
  _QWORD v45[2]; // [xsp+50h] [xbp-10h] BYREF

  v45[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *a6;
  v45[0] = 0;
  if ( (v13 & 1) != 0 )
  {
    v16 = (2 * (*((_WORD *)a6 + 5) & 1)) & 0xFB
        | (unsigned __int8)(4 * (*((_WORD *)a6 + 6) & 1))
        | ((*((_WORD *)a6 + 7) & 1) << 24);
  }
  else
  {
    v14 = *((unsigned __int16 *)a6 + 11);
    v15 = *((_WORD *)a6 + 4) & 1
        | (2 * (*((_WORD *)a6 + 5) & 1)) & 0xF3
        | (4 * (*((_WORD *)a6 + 6) & 1)) & 0xF7
        | (unsigned __int8)(8 * (*((_WORD *)a6 + 8) & 1))
        | ((*((_WORD *)a6 + 7) & 1) << 24)
        | ((*((_WORD *)a6 + 9) & 0xF) << 16) & 0xFF8FFFFF
        | ((*((_WORD *)a6 + 10) & 7) << 20)
        | (16 * (v14 & 3))
        | ((*((_WORD *)a6 + 12) & 3) << 6)
        | ((*((_WORD *)a6 + 16) & 3) << 8)
        | ((*((_WORD *)a6 + 17) & 3) << 10)
        | ((*((_WORD *)a6 + 18) & 3) << 12)
        | ((*((_WORD *)a6 + 19) & 1) << 14);
    LODWORD(v45[0]) = v15;
    if ( a2 != 2 )
      goto LABEL_6;
    v16 = (v14 << 13) & 0x8000 | ((*((_WORD *)a6 + 146) != 0) << 26) | v15;
  }
  LODWORD(v45[0]) = v16;
LABEL_6:
  v17 = *(_DWORD *)(a5 + 28);
  if ( v17 == 2 )
  {
    v18 = 1;
  }
  else
  {
    if ( v17 != 4 )
      goto LABEL_11;
    v18 = 3;
  }
  HIDWORD(v45[0]) = v18;
LABEL_11:
  v19 = *(_QWORD *)(a5 + 16);
  *(_DWORD *)(a7 + 20) = a3 + 4;
  *(_DWORD *)a7 = 5;
  *(_QWORD *)(a7 + 12) = 0;
  *(_QWORD *)(a7 + 32) = v45;
  *(_QWORD *)(a7 + 40) = 0x402000000LL;
  v20 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  if ( *((_DWORD *)v20 - 1) != -1839634494 )
    __break(0x8228u);
  v21 = v20(a7);
  if ( v21 )
  {
    v22 = v21;
    _drm_err("write spr config pt1 failed ret %d\n", v21);
LABEL_19:
    _ReadStatusReg(SP_EL0);
    return v22;
  }
  *(_QWORD *)(a7 + 12) = 0;
  *(_DWORD *)a7 = 2;
  *(_DWORD *)(a7 + 20) = a3 + 8;
  *(_QWORD *)(a7 + 32) = (char *)v45 + 4;
  *(_QWORD *)(a7 + 40) = 0x400000000LL;
  v23 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
  if ( *((_DWORD *)v23 - 1) != -1839634494 )
    __break(0x8228u);
  v24 = v23(a7);
  if ( v24 )
  {
    v22 = v24;
    _drm_err("write spr config failed ret %d\n", v24);
    goto LABEL_19;
  }
  v28 = *(_QWORD *)(a5 + 152);
  v39 = 0;
  v40 = 12;
  v29 = *(_QWORD *)(a7 + 24);
  v41 = v28;
  v30 = *(_DWORD *)(a5 + 160);
  LODWORD(v28) = *(_DWORD *)(a5 + 164);
  v38 = 0;
  v42 = __PAIR64__(v28, v30);
  LODWORD(v28) = *(_DWORD *)(a5 + 168);
  v32 = *(_DWORD *)(a5 + 172);
  v31 = *(_DWORD *)(a5 + 176);
  v37 = v29;
  v44 = __PAIR64__(v31, v32);
  v43 = __PAIR64__(*(_DWORD *)(a5 + 28), v28);
  v33 = *(unsigned int *)(v19 + 28);
  v35 = *(_QWORD *)(a5 + 16);
  v36 = 1;
  if ( (unsigned int)v33 <= 2 )
  {
    v34 = *(_DWORD **)(a4 + 8 * v33 + 16);
    if ( v34 )
    {
      if ( *(v34 - 1) != 1772228465 )
        __break(0x8228u);
      v22 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v34)(&v35, a1);
      if ( v22 )
        _drm_err("failed to kick off ret %d\n", v22);
    }
    else
    {
      v22 = 0;
    }
    goto LABEL_19;
  }
  __break(0x5512u);
  *(_QWORD *)(v25 - 24) = v7;
  *(_QWORD *)(v25 - 16) = v26;
  return reg_dmav1_setup_spr_init_cfgv1();
}
