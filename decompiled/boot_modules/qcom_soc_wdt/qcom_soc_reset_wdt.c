__int64 __fastcall qcom_soc_reset_wdt(__int64 *a1)
{
  __int64 v1; // x9

  v1 = *a1;
  *(_DWORD *)(v1 + 4) = 1;
  __dsb(0xFu);
  return 0;
}
