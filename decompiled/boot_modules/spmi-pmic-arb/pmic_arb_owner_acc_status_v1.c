__int64 __fastcall pmic_arb_owner_acc_status_v1(__int64 a1, unsigned __int8 a2, unsigned __int16 a3)
{
  return *(_QWORD *)(a1 + 16) + 32LL * a2 + 4LL * a3;
}
