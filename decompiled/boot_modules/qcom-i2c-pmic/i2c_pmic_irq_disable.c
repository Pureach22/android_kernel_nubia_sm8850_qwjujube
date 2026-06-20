__int64 __fastcall i2c_pmic_irq_disable(__int64 result)
{
  *(_BYTE *)(*(_QWORD *)(result + 48) + 14LL) &= ~*(_BYTE *)(result + 8);
  return result;
}
