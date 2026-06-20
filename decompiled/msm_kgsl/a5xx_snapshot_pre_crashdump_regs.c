__int64 __fastcall a5xx_snapshot_pre_crashdump_regs(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  _QWORD v4[3]; // [xsp+8h] [xbp-18h] BYREF

  v4[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = &a5xx_pre_crashdumper_registers;
  v4[1] = 3;
  result = kgsl_snapshot_dump_registers(a1, a2, a3, v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
