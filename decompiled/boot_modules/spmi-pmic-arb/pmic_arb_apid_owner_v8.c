__int64 __fastcall pmic_arb_apid_owner_v8(__int64 a1, unsigned __int16 a2)
{
  return *(_QWORD *)(a1 + 32) + 4 * (a2 - *(unsigned __int16 *)(a1 + 52));
}
