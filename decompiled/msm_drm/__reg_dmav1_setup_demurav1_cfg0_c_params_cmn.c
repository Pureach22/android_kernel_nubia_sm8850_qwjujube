__int64 __fastcall _reg_dmav1_setup_demurav1_cfg0_c_params_cmn(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5,
        char a6,
        int a7)
{
  __int64 (*v13)(void); // x8
  unsigned int v14; // w0
  unsigned int v15; // w25
  unsigned int v16; // w8
  __int64 *v17; // x9
  __int64 v18; // x5
  __int64 (__fastcall *v19)(_QWORD); // x8
  unsigned int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)(a1 + 20) = a7 + 104;
  *(_DWORD *)a1 = 1;
  *(_QWORD *)(a1 + 12) = 0;
  *(_QWORD *)(a1 + 32) = &v21;
  *(_QWORD *)(a1 + 40) = 0x400000000LL;
  v13 = *(__int64 (**)(void))(a2 + 8);
  v21 = ((a6 & 3) << 28) | 0x80000000;
  if ( *((_DWORD *)v13 - 1) != -1839634494 )
    __break(0x8228u);
  v14 = v13();
  if ( v14 )
  {
    v15 = v14;
    _drm_err("0x68: REG_SINGLE_WRITE failed ret %d\n", v14);
  }
  else
  {
    v21 = 0;
    if ( a4 )
    {
      v16 = 0;
      do
      {
        v17 = (__int64 *)(a3 + 8LL * v16);
        v18 = *v17;
        *(_DWORD *)(a5 + 8LL * v16) = *v17;
        *(_DWORD *)(a5 + 4LL * ((2 * v16) | 1)) = *((_DWORD *)v17 + 1) & 0x3FF;
        _drm_dev_dbg(0, 0, 1, "0x6c: index %d value %x\n", 2 * v16, v18);
        _drm_dev_dbg(0, 0, 1, "0x6c: index %d value %x\n", (2 * v21) | 1, *(_DWORD *)(a5 + 4LL * ((2 * v21) | 1)));
        v16 = ++v21;
      }
      while ( v21 < a4 );
    }
    *(_QWORD *)(a1 + 32) = a5;
    *(_DWORD *)a1 = 3;
    *(_DWORD *)(a1 + 20) = a7 + 108;
    *(_QWORD *)(a1 + 12) = 0;
    *(_DWORD *)(a1 + 40) = 0;
    *(_DWORD *)(a1 + 44) = 8 * a4;
    v19 = *(__int64 (__fastcall **)(_QWORD))(a2 + 8);
    if ( *((_DWORD *)v19 - 1) != -1839634494 )
      __break(0x8228u);
    v15 = v19(a1);
    if ( v15 )
      _drm_err("0x6c: REG_BLK_WRITE_INC failed ret %d\n", v15);
  }
  _ReadStatusReg(SP_EL0);
  return v15;
}
