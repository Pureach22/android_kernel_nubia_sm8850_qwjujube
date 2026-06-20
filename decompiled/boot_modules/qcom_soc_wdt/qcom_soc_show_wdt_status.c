__int64 __fastcall qcom_soc_show_wdt_status(_QWORD *a1)
{
  dev_err(
    a1[1],
    "Wdog - STS: 0x%x, CTL: 0x%x, BARK TIME: 0x%x, BITE TIME: 0x%x\n",
    *(_DWORD *)(*a1 + 12LL),
    *(_DWORD *)(*a1 + 8LL),
    *(_DWORD *)(*a1 + 16LL),
    *(_DWORD *)(*a1 + 20LL));
  return 0;
}
