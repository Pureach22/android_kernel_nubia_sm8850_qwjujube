__int64 __fastcall hwmon_attr_show_string(__int64 a1, __int64 a2, char *a3)
{
  __int64 v4; // x8
  __int64 v5; // x3
  __int64 v6; // x2
  unsigned int v7; // w21
  _DWORD *v8; // x8
  __int64 result; // x0
  const char *v10[2]; // [xsp+10h] [xbp-10h] BYREF

  v10[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 32);
  v5 = *(unsigned int *)(a2 + 48);
  v10[0] = nullptr;
  v7 = *(_DWORD *)(a2 + 40);
  v6 = *(unsigned int *)(a2 + 44);
  v8 = *(_DWORD **)(v4 + 16);
  if ( *(v8 - 1) != -1284720852 )
    __break(0x8228u);
  LODWORD(result) = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, const char **))v8)(a1, v7, v6, v5, v10);
  if ( (result & 0x80000000) == 0 )
    LODWORD(result) = sprintf(a3, "%s\n", v10[0]);
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
