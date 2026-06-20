__int64 __fastcall _reg_dmav1_setup_demura_cfg0_param4_common(__int64 a1, _DWORD *a2, __int64 a3, __int64 a4, char a5)
{
  int v5; // w8
  unsigned int v7; // w10
  unsigned int v8; // w8
  int v10; // w21
  int v11; // w22
  long double v12; // q0
  __int64 (__fastcall *v13)(_QWORD, long double); // x8
  unsigned int v14; // w20
  _QWORD v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a2[3];
  v16[0] = 0;
  if ( v5 )
  {
    v7 = a2[1590] & ~(unsigned int)(-1LL << a5)
       | ((a2[1591] & ~(unsigned int)(-1LL << a5)) << 8)
       | ((a2[1592] & ~(unsigned int)(-1LL << a5)) << 16);
    v8 = a2[1593] & ~(unsigned int)(-1LL << a5);
    v10 = *(_DWORD *)(a1 + 8);
    v11 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 568LL);
    LODWORD(v16[0]) = a2[1586] & ~(unsigned int)(-1LL << a5)
                    | ((a2[1587] & ~(unsigned int)(-1LL << a5)) << 8)
                    | ((a2[1588] & ~(unsigned int)(-1LL << a5)) << 16)
                    | ((a2[1589] & ~(unsigned int)(-1LL << a5)) << 24);
    HIDWORD(v16[0]) = v7 | (v8 << 24);
    *(double *)&v12 = _drm_dev_dbg(0, 0, 1, "0x4c: value is gain[0] %x gain[1] %x\n", LODWORD(v16[0]), HIDWORD(v16[0]));
    *(_QWORD *)(a3 + 12) = 0;
    *(_DWORD *)a3 = 2;
    *(_DWORD *)(a3 + 20) = v11 + v10 + 76;
    *(_QWORD *)(a3 + 32) = v16;
    *(_QWORD *)(a3 + 40) = 0x800000000LL;
    v13 = *(__int64 (__fastcall **)(_QWORD, long double))(a4 + 8);
    if ( *((_DWORD *)v13 - 1) != -1839634494 )
      __break(0x8228u);
    v14 = v13(a3, v12);
    if ( v14 )
      _drm_err("0x4c: REG_BLK_WRITE_SINGLE %d len %zd buf idx %d\n", v14, 8u, *(_DWORD *)(*(_QWORD *)(a3 + 24) + 20LL));
  }
  else
  {
    _drm_dev_dbg(0, 0, 1, "dcfg->cfg0_en is disabled\n");
    v14 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v14;
}
