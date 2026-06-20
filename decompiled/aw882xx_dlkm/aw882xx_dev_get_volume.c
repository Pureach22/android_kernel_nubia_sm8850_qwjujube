__int64 __fastcall aw882xx_dev_get_volume(__int64 a1, _DWORD *a2)
{
  void (__fastcall *v4)(__int64, __int64, int *); // x8
  __int64 v5; // x0
  __int64 v6; // x1
  unsigned int v7; // w9
  unsigned int v8; // w10
  __int64 (__fastcall *v9)(_QWORD); // x8
  __int64 v10; // x0
  int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(void (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
  v5 = *(_QWORD *)(a1 + 120);
  v6 = *(unsigned int *)(a1 + 596);
  v12 = 0;
  if ( *((_DWORD *)v4 - 1) != 1983062130 )
    __break(0x8228u);
  v4(v5, v6, &v12);
  v7 = (v12 & (unsigned int)~*(_DWORD *)(a1 + 600)) >> *(_DWORD *)(a1 + 604);
  v8 = *(_DWORD *)(a1 + 612);
  v9 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1176);
  if ( v7 >= v8 )
    v10 = v8;
  else
    v10 = v7;
  if ( v9 )
  {
    if ( *((_DWORD *)v9 - 1) != 2010610996 )
      __break(0x8228u);
    LODWORD(v10) = v9(v10);
  }
  *a2 = v10 - *(_DWORD *)(a1 + 608);
  _ReadStatusReg(SP_EL0);
  return 0;
}
