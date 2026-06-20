__int64 __fastcall gpio_keys_gpio_work_func(__int64 a1)
{
  unsigned int **v2; // x20

  v2 = (unsigned int **)(a1 - 80);
  mutex_lock(a1 + 128);
  gpio_keys_gpio_report_event(v2);
  if ( *(_DWORD *)(*(_QWORD *)(a1 - 80) + 28LL) )
    pm_relax(*(_QWORD *)(*(_QWORD *)(a1 - 72) + 656LL));
  return mutex_unlock(a1 + 128);
}
