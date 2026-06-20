bool __fastcall wcd9378_mbhc_micb_en_status(__int64 a1, int a2)
{
  return a2 == 2 && *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 216) + 24LL) + 152LL) + 368LL);
}
