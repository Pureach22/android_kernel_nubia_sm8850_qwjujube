__int64 __fastcall qcom_soc_enable_wdt(int a1, __int64 a2)
{
  *(_DWORD *)(*(_QWORD *)a2 + 8LL) = a1;
  __dsb(0xFu);
  return 0;
}
