__int64 __fastcall ufp_notifier_cb(int a1)
{
  ((void (__fastcall *)(bool))change_tp_state)(a1 != 0);
  return 0;
}
