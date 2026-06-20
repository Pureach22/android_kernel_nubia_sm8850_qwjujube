__int64 __fastcall a5xx_snapshot_registers(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  unsigned __int64 v4; // x8
  __int64 result; // x0
  __int64 v6; // [xsp+8h] [xbp-18h] BYREF
  int v7; // [xsp+10h] [xbp-10h]
  int v8; // [xsp+14h] [xbp-Ch]
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a4[1];
  v6 = *a4;
  v7 = v4 >> 1;
  v8 = 0;
  result = kgsl_snapshot_dump_registers(a1, a2, a3, &v6);
  _ReadStatusReg(SP_EL0);
  return result;
}
