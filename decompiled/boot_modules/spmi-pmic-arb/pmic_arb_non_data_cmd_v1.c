__int64 __fastcall pmic_arb_non_data_cmd_v1(__int64 a1, int a2, unsigned int a3)
{
  __int64 *v3; // x19
  __int64 v7; // x25
  _DWORD *v8; // x8
  unsigned int v9; // w22
  __int64 v10; // x24

  v3 = *(__int64 **)(a1 + 152);
  v7 = *v3;
  v8 = *(_DWORD **)(*(_QWORD *)(*v3 + 56) + 40LL);
  if ( *(v8 - 1) != 1307277261 )
    __break(0x8228u);
  v9 = ((__int64 (__fastcall *)(__int64 *, _QWORD, _QWORD, _QWORD))v8)(v3, a3, 0, 0);
  if ( (v9 & 0x80000000) == 0 )
  {
    v10 = raw_spin_lock_irqsave(v3 + 6);
    writel_relaxed((a2 << 27) | ((unsigned __int8)(a3 & 0xF) << 20), *(_QWORD *)(v7 + 8) + v9);
    v9 = pmic_arb_wait_for_done(a1, *(_QWORD *)(v7 + 8), a3, 0, 0);
    raw_spin_unlock_irqrestore(v3 + 6, v10);
  }
  return v9;
}
