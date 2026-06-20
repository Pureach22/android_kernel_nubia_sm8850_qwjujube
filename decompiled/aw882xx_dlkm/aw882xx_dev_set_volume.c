__int64 __fastcall aw882xx_dev_set_volume(__int64 a1, int a2)
{
  int v3; // w8
  unsigned int v4; // w9
  unsigned int v5; // w10
  __int64 (__fastcall *v6)(_QWORD); // x8
  unsigned int v7; // w20
  void (__fastcall *v8)(__int64, __int64, int *); // x8
  __int64 v9; // x0
  __int64 v10; // x1
  void (__fastcall *v11)(__int64, __int64, __int64); // x11
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x2
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 608);
  v4 = *(_DWORD *)(a1 + 612);
  v16 = 0;
  v5 = v3 + a2;
  v6 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1184);
  if ( v5 >= v4 )
    v7 = v4;
  else
    v7 = v5;
  if ( v6 )
  {
    if ( *((_DWORD *)v6 - 1) != 2010610996 )
      __break(0x8228u);
    v7 = v6(v7);
  }
  v8 = *(void (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
  v9 = *(_QWORD *)(a1 + 120);
  v10 = *(unsigned int *)(a1 + 596);
  if ( *((_DWORD *)v8 - 1) != 1983062130 )
    __break(0x8228u);
  v8(v9, v10, &v16);
  v11 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 1152);
  v12 = *(_QWORD *)(a1 + 120);
  v13 = *(unsigned int *)(a1 + 596);
  v14 = *(_DWORD *)(a1 + 600) & v16 | (v7 << *(_DWORD *)(a1 + 604));
  if ( *((_DWORD *)v11 - 1) != -1860236611 )
    __break(0x822Bu);
  v11(v12, v13, v14);
  _ReadStatusReg(SP_EL0);
  return 0;
}
