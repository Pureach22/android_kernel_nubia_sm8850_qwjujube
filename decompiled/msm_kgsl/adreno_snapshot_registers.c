__int64 __fastcall adreno_snapshot_registers(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 result; // x0
  __int64 v5; // [xsp+8h] [xbp-18h] BYREF
  int v6; // [xsp+10h] [xbp-10h]
  int v7; // [xsp+14h] [xbp-Ch]
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a3;
  v7 = 0;
  v6 = a4;
  result = kgsl_snapshot_add_section(a1, 513, a2, kgsl_snapshot_dump_registers, &v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
