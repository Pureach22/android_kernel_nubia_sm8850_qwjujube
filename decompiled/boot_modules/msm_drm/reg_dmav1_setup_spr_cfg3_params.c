__int64 __fastcall reg_dmav1_setup_spr_cfg3_params(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int16 v4; // w8
  __int64 v5; // x9
  __int16 v6; // w10
  int v7; // w8
  int v8; // w10
  unsigned int v11; // w8
  int v12; // w11
  int v13; // w25
  __int64 (__fastcall *v15)(_QWORD); // x8
  unsigned int v16; // w0
  unsigned int v17; // w22
  int v18; // w10
  __int16 v19; // w12
  int v20; // w11
  __int16 v21; // w13
  int v22; // w9
  unsigned int v23; // w9
  int v24; // w12
  __int16 v25; // w13
  int v26; // w8
  unsigned int v27; // w12
  unsigned int v28; // w8
  __int16 v29; // w13
  int v30; // w10
  int v31; // w8
  int v32; // w9
  int v33; // w11
  unsigned int v34; // w9
  __int16 v35; // w13
  int v36; // w10
  int v37; // w11
  int v38; // w9
  int v39; // w8
  __int64 (__fastcall *v40)(_QWORD); // x10
  int v42; // [xsp+8h] [xbp-48h] BYREF
  int v43; // [xsp+Ch] [xbp-44h]
  unsigned __int64 v44; // [xsp+10h] [xbp-40h]
  unsigned __int64 v45; // [xsp+18h] [xbp-38h]
  unsigned __int64 v46; // [xsp+20h] [xbp-30h]
  unsigned __int64 v47; // [xsp+28h] [xbp-28h]
  __int64 v48; // [xsp+30h] [xbp-20h]
  __int64 v49; // [xsp+38h] [xbp-18h]
  __int64 v50; // [xsp+40h] [xbp-10h]
  __int64 v51; // [xsp+48h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_WORD *)(a2 + 14) )
  {
    v4 = *(_WORD *)(a2 + 48);
    v5 = *(_QWORD *)(a1 + 72);
    v6 = *(_WORD *)(a2 + 50);
    v49 = 0;
    v50 = 0;
    v7 = v4 & 0x3FF | ((v6 & 0x3FF) << 10);
    v8 = *(_DWORD *)(a1 + 8);
    LODWORD(v5) = *(_DWORD *)(*(_QWORD *)(v5 + 48) + 416LL);
    v11 = v7 & 0xC00FFFFF | ((*(_WORD *)(a2 + 52) & 0x3FF) << 20);
    v12 = *(_DWORD *)(a2 + 28);
    *(_DWORD *)a3 = 2;
    v13 = v5 + v8;
    *(_QWORD *)(a3 + 12) = 0;
    v47 = 0;
    v48 = 0;
    v42 = v11;
    v43 = v12 & 0x3FFFFFFF;
    *(_DWORD *)(a3 + 20) = v5 + v8 + 112;
    *(_QWORD *)(a3 + 32) = &v42;
    *(_QWORD *)(a3 + 40) = 0x800000000LL;
    v15 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
    v45 = 0;
    v46 = 0;
    v44 = 0;
    if ( *((_DWORD *)v15 - 1) != -1839634494 )
      __break(0x8228u);
    v16 = v15(a3);
    if ( v16 )
    {
      v17 = v16;
      _drm_err("write spr cfg13 failed ret %d\n", v16);
    }
    else
    {
      v18 = *(_WORD *)(a2 + 70) & 0xFFF | ((*(_WORD *)(a2 + 72) & 0xFFF) << 16);
      v19 = *(_WORD *)(a2 + 80);
      v20 = *(_WORD *)(a2 + 74) & 0xFFF | ((*(_WORD *)(a2 + 76) & 0xFFF) << 16);
      v21 = *(_WORD *)(a2 + 82);
      v22 = *(_WORD *)(a2 + 78) & 0xFFF;
      v42 = *(_WORD *)(a2 + 66) & 0xFFF | ((*(_WORD *)(a2 + 68) & 0xFFF) << 16);
      v43 = v18;
      v23 = v22 & 0xF000FFFF | ((v19 & 0xFFF) << 16);
      v24 = v21 & 0xFFF;
      v25 = *(_WORD *)(a2 + 88);
      v26 = *(_WORD *)(a2 + 86) & 0xFFF;
      v27 = v24 & 0xF000FFFF | ((*(_WORD *)(a2 + 84) & 0xFFF) << 16);
      LOWORD(v18) = *(_WORD *)(a2 + 94);
      v44 = __PAIR64__(v23, v20);
      v28 = v26 & 0xF000FFFF | ((v25 & 0xFFF) << 16);
      LOWORD(v23) = *(_WORD *)(a2 + 90);
      LOWORD(v20) = *(_WORD *)(a2 + 96);
      v29 = *(_WORD *)(a2 + 100);
      v45 = __PAIR64__(v28, v27);
      v30 = v18 & 0xFFF | ((v20 & 0xFFF) << 16);
      v31 = v23 & 0xFFF | ((*(_WORD *)(a2 + 92) & 0xFFF) << 16);
      LOWORD(v27) = *(_WORD *)(a2 + 104);
      v32 = *(_WORD *)(a2 + 102) & 0xFFF;
      v33 = *(_WORD *)(a2 + 98) & 0xFFF | ((v29 & 0xFFF) << 16);
      v46 = __PAIR64__(v30, v31);
      v34 = v32 & 0xF000FFFF | ((v27 & 0xFFF) << 16);
      LOWORD(v31) = *(_WORD *)(a2 + 106);
      LOWORD(v30) = *(_WORD *)(a2 + 110);
      LOWORD(v27) = *(_WORD *)(a2 + 114);
      v35 = *(_WORD *)(a2 + 116);
      v47 = __PAIR64__(v34, v33);
      v36 = v30 & 0xFFF | ((*(_WORD *)(a2 + 112) & 0xFFF) << 16);
      v37 = v27 & 0xFFF;
      LOWORD(v27) = *(_WORD *)(a2 + 120);
      v38 = *(_WORD *)(a2 + 118) & 0xFFF;
      LODWORD(v48) = v31 & 0xFFF | ((*(_WORD *)(a2 + 108) & 0xFFF) << 16);
      HIDWORD(v48) = v36;
      LOWORD(v31) = *(_WORD *)(a2 + 122);
      LOWORD(v36) = *(_WORD *)(a2 + 124);
      LODWORD(v49) = v37 & 0xF000FFFF | ((v35 & 0xFFF) << 16);
      HIDWORD(v49) = v38 & 0xF000FFFF | ((v27 & 0xFFF) << 16);
      LOWORD(v38) = *(_WORD *)(a2 + 126);
      LOWORD(v37) = *(_WORD *)(a2 + 128);
      v39 = v31 & 0xFFF | ((v36 & 0xFFF) << 16);
      *(_DWORD *)a3 = 2;
      *(_DWORD *)(a3 + 20) = v13 + 160;
      *(_QWORD *)(a3 + 12) = 0;
      *(_QWORD *)(a3 + 32) = &v42;
      *(_QWORD *)(a3 + 40) = 0x4000000000LL;
      v40 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
      LODWORD(v50) = v39;
      HIDWORD(v50) = v38 & 0xFFF | ((v37 & 0xFFF) << 16);
      if ( *((_DWORD *)v40 - 1) != -1839634494 )
        __break(0x822Au);
      v17 = v40(a3);
      if ( v17 )
        _drm_err("write spr cfg15 failed ret %d\n", v17);
    }
  }
  else
  {
    v17 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v17;
}
