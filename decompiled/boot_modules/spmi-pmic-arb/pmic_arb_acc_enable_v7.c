unsigned __int64 __fastcall pmic_arb_acc_enable_v7(__int64 a1, unsigned __int16 a2)
{
  return *(_QWORD *)(*(_QWORD *)a1 + 8LL) + ((unsigned __int64)a2 << 12) + 256;
}
