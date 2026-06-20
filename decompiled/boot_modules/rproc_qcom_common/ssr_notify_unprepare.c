__int64 __fastcall ssr_notify_unprepare(__int64 a1)
{
  __int64 result; // x0
  _QWORD v3[3]; // [xsp+8h] [xbp-18h] BYREF

  v3[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = **(_QWORD **)(a1 + 96);
  v3[1] = 0;
  *(_DWORD *)(a1 + 48) = 3;
  mod_timer(a1 + 56, jiffies + 2500LL);
  srcu_notifier_call_chain(*(_QWORD *)(a1 + 96) + 8LL, *(unsigned int *)(a1 + 48), v3);
  result = timer_delete_sync(a1 + 56);
  _ReadStatusReg(SP_EL0);
  return result;
}
