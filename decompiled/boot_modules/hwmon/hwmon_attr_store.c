__int64 __fastcall hwmon_attr_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w0
  __int64 v8; // x3
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 (__fastcall *v11)(__int64, __int64, __int64, __int64, __int64); // x8
  __int64 v12; // x4
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  v7 = kstrtoll(a3, 10, v14);
  if ( v7 < 0 )
    goto LABEL_5;
  v8 = *(unsigned int *)(a2 + 48);
  v9 = *(unsigned int *)(a2 + 40);
  v10 = *(unsigned int *)(a2 + 44);
  v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(*(_QWORD *)(a2 + 32) + 24LL);
  v12 = v14[0];
  if ( *((_DWORD *)v11 - 1) != -1027269393 )
    __break(0x8228u);
  v7 = v11(a1, v9, v10, v8, v12);
  if ( v7 < 0 )
LABEL_5:
    a4 = v7;
  _ReadStatusReg(SP_EL0);
  return a4;
}
