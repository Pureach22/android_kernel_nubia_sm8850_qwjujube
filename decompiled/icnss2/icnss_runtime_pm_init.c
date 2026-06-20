__int64 __fastcall icnss_runtime_pm_init(__int64 a1)
{
  _pm_runtime_resume(*(_QWORD *)(a1 + 8) + 16LL, 4);
  pm_runtime_forbid(*(_QWORD *)(a1 + 8) + 16LL);
  _pm_runtime_set_status(*(_QWORD *)(a1 + 8) + 16LL, 0);
  return pm_runtime_enable(*(_QWORD *)(a1 + 8) + 16LL);
}
