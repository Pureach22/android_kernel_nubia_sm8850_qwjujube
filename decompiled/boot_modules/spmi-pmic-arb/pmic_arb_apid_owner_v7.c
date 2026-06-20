__int64 __fastcall pmic_arb_apid_owner_v7(__int64 a1, unsigned __int16 a2)
{
  return *(_QWORD *)(a1 + 24) + 4 * (a2 - *(unsigned __int16 *)(a1 + 52));
}
