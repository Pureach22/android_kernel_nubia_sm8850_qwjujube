__int64 __fastcall adreno_prop_device_info(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v5; // w9
  __int64 v6; // x9
  __int64 v7; // x8
  __int64 v8; // x10
  __int64 (__fastcall *v9)(__int64, __int64, __int64, __int64); // x9
  unsigned int v10; // w0
  __int64 result; // x0
  _DWORD v12[2]; // [xsp+0h] [xbp-30h] BYREF
  _BYTE v13[12]; // [xsp+8h] [xbp-28h]
  __int64 v14; // [xsp+14h] [xbp-1Ch]
  int v15; // [xsp+1Ch] [xbp-14h]
  __int64 v16; // [xsp+20h] [xbp-10h]
  __int64 v17; // [xsp+28h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a1 + 14248);
  v12[0] = *(_DWORD *)(a1 + 16) + 1;
  v12[1] = v5;
  v6 = *(_QWORD *)(a1 + 104);
  v7 = *(_QWORD *)(a1 + 14264);
  *(_QWORD *)&v13[4] = 0;
  v14 = 0;
  v8 = *(_QWORD *)(v7 + 40);
  v15 = 0;
  *(_QWORD *)v13 = ((unsigned int)v6 >> 1) & 1;
  v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v8 + 320);
  if ( v9 )
  {
    if ( *((_DWORD *)v9 - 1) != 556668243 )
      __break(0x8229u);
    v10 = v9(a1, a2, a3, a4);
  }
  else
  {
    v10 = *(_DWORD *)(v7 + 64);
  }
  v16 = v10;
  result = copy_prop(a2, v12, 40);
  _ReadStatusReg(SP_EL0);
  return result;
}
