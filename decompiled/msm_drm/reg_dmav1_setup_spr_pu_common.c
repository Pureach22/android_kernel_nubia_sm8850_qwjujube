__int64 __fastcall reg_dmav1_setup_spr_pu_common(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        long double a6)
{
  unsigned __int16 *v8; // x8
  __int64 v9; // x21
  int v10; // w8
  int v11; // w9
  int v12; // w11
  int v13; // w1
  __int64 (__fastcall *v14)(_QWORD, long double); // x8
  unsigned int v15; // w0
  unsigned int v16; // w20
  __int64 v17; // x8
  int v18; // w9
  __int64 (__fastcall *v19)(_QWORD); // x10
  int v21; // [xsp+4h] [xbp-4Ch] BYREF
  unsigned __int64 v22; // [xsp+8h] [xbp-48h] BYREF
  __int128 v23; // [xsp+10h] [xbp-40h]
  __int64 v24; // [xsp+20h] [xbp-30h]
  int *v25; // [xsp+28h] [xbp-28h]
  __int64 v26; // [xsp+30h] [xbp-20h]
  __int64 v27; // [xsp+38h] [xbp-18h]
  __int64 v28; // [xsp+40h] [xbp-10h]
  __int64 v29; // [xsp+48h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28 = 0;
  v25 = nullptr;
  v26 = 0;
  v24 = 0;
  v22 = 0;
  v23 = 0u;
  v21 = 0;
  if ( a3 )
  {
    v8 = *(unsigned __int16 **)a2;
    if ( **(_DWORD **)a2 >= 2u )
    {
      _drm_err("multiple pu regions not supported with spr\n");
LABEL_17:
      v16 = -22;
      goto LABEL_18;
    }
    v11 = v8[20];
    v12 = *(_DWORD *)(a2 + 96);
    v13 = v8[22] - v11;
    if ( v13 != v12 )
    {
      _drm_err("pu region not full width %d\n", v13);
      goto LABEL_17;
    }
    v9 = a1;
    v10 = v11 | (v8[21] << 16);
  }
  else
  {
    v9 = a1;
    *(double *)&a6 = _drm_dev_dbg(0, 0, 0, "invalid payload of pu rects\n");
    v10 = 0;
  }
  v21 = v10;
  LODWORD(v23) = 14;
  v22 = 0x8000000000000000LL;
  v14 = *(__int64 (__fastcall **)(_QWORD, long double))(a4 + 8);
  v27 = 0;
  v28 = 0;
  HIDWORD(v23) = 0;
  *(_QWORD *)((char *)&v23 + 4) = 0;
  v24 = a5;
  v25 = nullptr;
  v26 = 0;
  if ( *((_DWORD *)v14 - 1) != -1839634494 )
    __break(0x8228u);
  v15 = v14(&v22, a6);
  if ( v15 )
  {
    v16 = v15;
    _drm_err("spr write decode select failed ret %d\n", v15);
  }
  else
  {
    v17 = *(_QWORD *)(v9 + 72);
    v18 = *(_DWORD *)(v9 + 8);
    v19 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
    *(_QWORD *)((char *)&v23 + 4) = 0;
    LODWORD(v17) = v18 + *(_DWORD *)(*(_QWORD *)(v17 + 48) + 416LL);
    LODWORD(v22) = 1;
    HIDWORD(v23) = v17 + 32;
    v25 = &v21;
    v26 = 0x400000000LL;
    if ( *((_DWORD *)v19 - 1) != -1839634494 )
      __break(0x822Au);
    v16 = v19(&v22);
    if ( v16 )
      _drm_err("write pu config failed ret %d\n", v16);
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return v16;
}
