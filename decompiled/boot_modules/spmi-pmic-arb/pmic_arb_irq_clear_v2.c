unsigned __int64 __fastcall pmic_arb_irq_clear_v2(__int64 a1, unsigned __int16 a2)
{
  return *(_QWORD *)(a1 + 16) + ((unsigned __int64)a2 << 12) + 8;
}
