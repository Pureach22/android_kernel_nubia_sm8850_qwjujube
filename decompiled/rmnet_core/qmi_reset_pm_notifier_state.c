__int64 __fastcall qmi_reset_pm_notifier_state(char a1)
{
  __int64 v1; // x1
  void *v2; // x0

  if ( a1 )
  {
    register_pm_notifier(&dfc_pm_notifier);
    v2 = &unk_2C981;
  }
  else
  {
    unregister_pm_notifier(&dfc_pm_notifier);
    v2 = &unk_2CD38;
  }
  return printk(v2, v1);
}
