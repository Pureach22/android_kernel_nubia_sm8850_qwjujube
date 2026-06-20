__int64 __fastcall stm_heartbeat_unlink(__int64 a1)
{
  *(_DWORD *)(a1 + 112) = 0;
  return hrtimer_cancel(a1 + 48);
}
