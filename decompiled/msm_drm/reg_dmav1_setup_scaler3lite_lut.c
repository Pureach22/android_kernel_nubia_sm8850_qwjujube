unsigned __int64 __fastcall reg_dmav1_setup_scaler3lite_lut(
        unsigned __int64 result,
        __int64 a2,
        int a3,
        unsigned int a4)
{
  unsigned __int64 v4; // x19
  unsigned int v7; // w8
  __int64 v8; // x8
  char v9; // w9
  unsigned int v10; // w10
  __int64 v11; // x21
  unsigned __int64 v12; // x22
  __int64 (__fastcall *v13)(_QWORD); // x8
  int v14; // w1
  unsigned __int64 v15; // x21
  __int64 (__fastcall *v16)(_QWORD); // x8
  __int64 (__fastcall *v17)(_QWORD); // x9
  int v18; // [xsp+8h] [xbp-18h]
  int v19; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(a2 + 224) )
    goto LABEL_28;
  v4 = result;
  result = sde_reg_dma_get_ops(a4);
  if ( !result || result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_28;
  v18 = *(_DWORD *)(a2 + 168);
  if ( (v18 & 0x10) != 0 && (v7 = *(_DWORD *)(a2 + 184), v7 <= 9) && *(_QWORD *)(a2 + 232) == 1320 )
  {
    v8 = *(_QWORD *)(a2 + 224) + 132LL * v7;
    v9 = 0;
    if ( (v18 & 0x20) == 0 )
      goto LABEL_14;
  }
  else
  {
    v8 = 0;
    v9 = 1;
    if ( (v18 & 0x20) == 0 )
      goto LABEL_14;
  }
  v10 = *(_DWORD *)(a2 + 188);
  if ( v10 <= 9 && *(_QWORD *)(a2 + 232) == 1320 )
  {
    v11 = *(_QWORD *)(a2 + 224) + 132LL * v10;
    if ( !v8 )
      goto LABEL_19;
    goto LABEL_16;
  }
LABEL_14:
  if ( (v9 & 1) != 0 )
    goto LABEL_23;
  v11 = 0;
  if ( v8 )
  {
LABEL_16:
    *(_QWORD *)(v4 + 12) = 0;
    *(_DWORD *)v4 = 2;
    v12 = result;
    *(_DWORD *)(v4 + 20) = a3 + 256;
    *(_QWORD *)(v4 + 32) = v8;
    *(_QWORD *)(v4 + 40) = 0x8400000000LL;
    v13 = *(__int64 (__fastcall **)(_QWORD))(result + 8);
    if ( *((_DWORD *)v13 - 1) != -1839634494 )
      __break(0x8228u);
    v14 = v13(v4);
    result = v12;
    if ( v14 )
      goto LABEL_27;
  }
LABEL_19:
  if ( v11 )
  {
    *(_QWORD *)(v4 + 12) = 0;
    *(_DWORD *)v4 = 2;
    *(_DWORD *)(v4 + 20) = a3 + 768;
    *(_QWORD *)(v4 + 32) = v11;
    *(_QWORD *)(v4 + 40) = 0x8400000000LL;
    v15 = result;
    v16 = *(__int64 (__fastcall **)(_QWORD))(result + 8);
    if ( *((_DWORD *)v16 - 1) != -1839634494 )
      __break(0x8228u);
    v14 = v16(v4);
    result = v15;
    if ( v14 )
      goto LABEL_27;
  }
LABEL_23:
  if ( (v18 & 1) != 0 )
  {
    *(_DWORD *)(v4 + 20) = a3 + 76;
    *(_DWORD *)v4 = 1;
    *(_QWORD *)(v4 + 12) = 0;
    *(_QWORD *)(v4 + 32) = &v19;
    *(_QWORD *)(v4 + 40) = 0x400000000LL;
    v17 = *(__int64 (__fastcall **)(_QWORD))(result + 8);
    v19 = 1;
    if ( *((_DWORD *)v17 - 1) != -1839634494 )
      __break(0x8229u);
    result = v17(v4);
    v14 = result;
    if ( (_DWORD)result )
LABEL_27:
      result = _drm_err("lut write failed ret %d\n", v14);
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
