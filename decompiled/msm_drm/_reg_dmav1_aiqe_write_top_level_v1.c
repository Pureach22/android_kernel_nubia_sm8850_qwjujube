__int64 __fastcall reg_dmav1_aiqe_write_top_level_v1(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v7; // x9
  int v8; // w10
  int v9; // w22
  int v10; // w9
  int v11; // w10
  __int16 v12; // w8
  int v13; // w8
  __int64 (__fastcall *v14)(_QWORD); // x9
  unsigned int v15; // w0
  unsigned int v16; // w21
  __int64 (__fastcall *v17)(_QWORD); // x8
  unsigned int v18; // w0
  __int64 (__fastcall *v19)(_QWORD); // x8
  __int64 v21; // [xsp+8h] [xbp-28h] BYREF
  __int64 v22; // [xsp+10h] [xbp-20h]
  _DWORD v23[2]; // [xsp+18h] [xbp-18h] BYREF
  int v24; // [xsp+20h] [xbp-10h] BYREF
  int v25; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+28h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a2 + 72);
  v8 = *(_DWORD *)(a2 + 8);
  v21 = 0;
  v22 = 0;
  v9 = *(_DWORD *)(*(_QWORD *)(v7 + 48) + 604LL) + v8;
  aiqe_get_common_values(a3, a5, &v21);
  v11 = v21;
  v10 = HIDWORD(v21);
  *(_DWORD *)(a1 + 20) = v9;
  *(_DWORD *)a1 = 2;
  v23[0] = v10;
  v23[1] = v11;
  v12 = v22;
  LOWORD(v10) = WORD2(v22);
  *(_QWORD *)(a1 + 12) = 0;
  v13 = v12 & 0xFFF | ((v10 & 0xFFF) << 16);
  *(_QWORD *)(a1 + 32) = v23;
  *(_QWORD *)(a1 + 40) = 0x800000000LL;
  v14 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
  v24 = v13;
  v25 = 0;
  if ( *((_DWORD *)v14 - 1) != -1839634494 )
    __break(0x8229u);
  v15 = v14(a1);
  if ( v15 )
  {
    v16 = v15;
    _drm_err("write top part 1 failed ret %d\n", v15);
  }
  else
  {
    *(_DWORD *)(a1 + 20) = v9 + 20;
    *(_DWORD *)a1 = 1;
    *(_QWORD *)(a1 + 12) = 0;
    *(_QWORD *)(a1 + 32) = &v24;
    *(_QWORD *)(a1 + 40) = 0x400000000LL;
    v17 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
    if ( *((_DWORD *)v17 - 1) != -1839634494 )
      __break(0x8228u);
    v18 = v17(a1);
    if ( v18 )
    {
      v16 = v18;
      _drm_err("write top part 2 failed ret %d\n", v18);
    }
    else
    {
      *(_DWORD *)a1 = 1;
      *(_DWORD *)(a1 + 20) = v9 + 1004;
      *(_QWORD *)(a1 + 12) = 0;
      *(_QWORD *)(a1 + 32) = &v25;
      *(_QWORD *)(a1 + 40) = 0x400000000LL;
      v19 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
      if ( *((_DWORD *)v19 - 1) != -1839634494 )
        __break(0x8228u);
      v16 = v19(a1);
      if ( v16 )
        _drm_err("write top part 3 failed ret %d\n", v16);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v16;
}
