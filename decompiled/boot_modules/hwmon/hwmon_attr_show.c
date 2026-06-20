__int64 __fastcall hwmon_attr_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v5; // x8
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  _DWORD *v9; // x8
  __int64 result; // x0
  _QWORD v11[2]; // [xsp+10h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a2 + 32);
  v6 = *(unsigned int *)(a2 + 40);
  v11[0] = 0;
  v7 = *(unsigned int *)(a2 + 44);
  v8 = *(unsigned int *)(a2 + 48);
  v9 = *(_DWORD **)(v5 + 8);
  if ( *(v9 - 1) != -2054292729 )
    __break(0x8228u);
  LODWORD(result) = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD *))v9)(a1, v6, v7, v8, v11);
  if ( (result & 0x80000000) == 0 )
    LODWORD(result) = sprintf(a3, "%ld\n", v11[0]);
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
