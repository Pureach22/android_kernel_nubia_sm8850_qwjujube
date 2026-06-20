__int64 __fastcall adreno_sysfs_store_bool(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x21
  __int64 result; // x0
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  __int64 v9; // x1
  _BYTE v10[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v10[0] = 0;
  LODWORD(result) = kstrtobool(a3, v10);
  if ( (_DWORD)result )
  {
    result = (int)result;
  }
  else
  {
    v8 = *(__int64 (__fastcall **)(__int64, __int64))(a2 + 40);
    v9 = v10[0];
    if ( *((_DWORD *)v8 - 1) != 1628810607 )
      __break(0x8228u);
    LODWORD(result) = v8(v6, v9);
    if ( (_DWORD)result )
      result = (int)result;
    else
      result = a4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
