__int64 __fastcall qcom_soc_set_wdt_bite(int a1, __int64 a2)
{
  unsigned int v2; // w8

  v2 = 32765 * a1;
  *(_DWORD *)(*(_QWORD *)a2 + 20LL) = v2 / 0x3E8;
  __dsb(0xFu);
  return 0;
}
