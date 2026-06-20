unsigned __int64 __fastcall pmic_arb_owner_acc_status_v3(__int64 a1, unsigned __int8 a2, unsigned __int16 a3)
{
  return *(_QWORD *)(a1 + 16) + ((unsigned __int64)a2 << 12) + 4LL * a3 + 0x200000;
}
