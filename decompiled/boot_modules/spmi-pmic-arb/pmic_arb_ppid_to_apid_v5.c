__int64 __fastcall pmic_arb_ppid_to_apid_v5(__int64 a1, unsigned __int16 a2)
{
  if ( *(__int16 *)(*(_QWORD *)(a1 + 136) + 2LL * a2) < 0 )
    return *(_WORD *)(*(_QWORD *)(a1 + 136) + 2LL * a2) & 0x7FFF;
  else
    return 4294967277LL;
}
