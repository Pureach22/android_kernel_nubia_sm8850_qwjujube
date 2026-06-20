__int64 __fastcall walt_attach_task(__int64 a1, __int64 a2)
{
  activate_task(a2, a1, 0);
  return wakeup_preempt(a2, a1, 0);
}
