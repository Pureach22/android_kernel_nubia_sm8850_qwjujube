__int64 __fastcall qmp_intr(__int64 a1, __int64 a2)
{
  ipc_log_string(ilc, "[%s]: \n", "qmp_intr");
  _wake_up(a2 + 96, 3, 0, 0);
  return 1;
}
