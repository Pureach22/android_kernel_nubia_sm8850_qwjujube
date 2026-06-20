__int64 __fastcall do_devfreq_suspend(__int64 a1)
{
  devfreq_suspend_device(*(_QWORD *)(a1 - 488));
  return devfreq_suspend_device(*(_QWORD *)(a1 + 1048));
}
