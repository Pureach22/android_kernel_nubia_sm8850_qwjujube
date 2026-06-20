__int64 __fastcall reg_dmav1_setup_spr_pu_config(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x8
  int v7; // w22
  __int64 v8; // x8
  int v9; // w23
  __int64 (__fastcall *v10)(_QWORD); // x8
  unsigned int v11; // w0
  unsigned int v12; // w21
  __int64 (__fastcall *v13)(_QWORD); // x10
  int v15; // [xsp+4h] [xbp-4Ch] BYREF
  unsigned __int64 v16; // [xsp+8h] [xbp-48h] BYREF
  int v17; // [xsp+10h] [xbp-40h]
  __int64 v18; // [xsp+14h] [xbp-3Ch]
  int v19; // [xsp+1Ch] [xbp-34h]
  __int64 v20; // [xsp+20h] [xbp-30h]
  int *v21; // [xsp+28h] [xbp-28h]
  __int64 v22; // [xsp+30h] [xbp-20h]
  __int64 v23; // [xsp+38h] [xbp-18h]
  __int64 v24; // [xsp+40h] [xbp-10h]
  __int64 v25; // [xsp+48h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 14;
  v6 = *(_QWORD *)(a1 + 72);
  v7 = *(_DWORD *)(a1 + 8);
  v15 = 0;
  v8 = *(_QWORD *)(v6 + 48);
  v16 = 0x8000000000000000LL;
  v19 = 0;
  v9 = *(_DWORD *)(v8 + 416);
  v10 = *(__int64 (__fastcall **)(_QWORD))(a3 + 8);
  v18 = 0;
  v23 = 0;
  v24 = 0;
  v20 = a4;
  v21 = nullptr;
  v22 = 0;
  if ( *((_DWORD *)v10 - 1) != -1839634494 )
    __break(0x8228u);
  v11 = v10(&v16);
  if ( v11 )
  {
    v12 = v11;
    _drm_err("spr pu write decode select failed ret %d\n", v11);
  }
  else
  {
    if ( a2 && *(unsigned __int16 *)(a2 + 46) != *(unsigned __int16 *)(a2 + 10) )
      v15 = 0x20000000;
    v13 = *(__int64 (__fastcall **)(_QWORD))(a3 + 8);
    LODWORD(v16) = 5;
    v19 = v7 + v9 + 4;
    v18 = 0;
    v21 = &v15;
    v22 = 0x4DFFFFFFFLL;
    if ( *((_DWORD *)v13 - 1) != -1839634494 )
      __break(0x822Au);
    v12 = v13(&v16);
    if ( v12 )
      _drm_err("write pu config failed ret %d\n", v12);
  }
  _ReadStatusReg(SP_EL0);
  return v12;
}
