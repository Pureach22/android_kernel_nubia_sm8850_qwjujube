unsigned __int64 __fastcall pmic_arb_irq_status_v8(__int64 a1, unsigned __int16 a2)
{
  return *(_QWORD *)(*(_QWORD *)a1 + 8LL) + ((unsigned __int64)a2 << 9) + 260;
}
