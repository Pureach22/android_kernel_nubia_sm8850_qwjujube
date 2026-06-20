__int64 __fastcall aw_pid_2113_frcset_check(__int64 a1)
{
  void (__fastcall *v2)(__int64, __int64, int *); // x8
  __int64 v3; // x0
  void (__fastcall *v4)(__int64, __int64, int *); // x8
  __int64 v5; // x0
  unsigned __int16 v6; // w20
  int v7; // w3
  __int64 *v8; // x8
  __int64 v9; // x1
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(void (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
  v3 = *(_QWORD *)(a1 + 120);
  v11 = 0;
  if ( *((_DWORD *)v2 - 1) != 1983062130 )
    __break(0x8228u);
  v2(v3, 121, &v11);
  v4 = *(void (__fastcall **)(__int64, __int64, int *))(a1 + 1160);
  v5 = *(_QWORD *)(a1 + 120);
  v6 = v11;
  if ( *((_DWORD *)v4 - 1) != 1983062130 )
    __break(0x8228u);
  v4(v5, 125, &v11);
  if ( *(_DWORD *)(a1 + 20) == 1 )
    v7 = ((unsigned __int16)v11 | v6) & 0x7C00;
  else
    v7 = v6 & (unsigned __int16)v11 & 0x7C00;
  v8 = *(__int64 **)(a1 + 112);
  *(_DWORD *)(a1 + 12) = v7 == 0;
  v9 = v8[14];
  if ( !v9 )
    v9 = *v8;
  printk(&unk_28A28, v9, "aw_pid_2113_frcset_check");
  _ReadStatusReg(SP_EL0);
  return 0;
}
