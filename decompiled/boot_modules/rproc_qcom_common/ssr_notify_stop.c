__int64 __fastcall ssr_notify_stop(__int64 a1, char a2)
{
  __int64 v4; // x1
  __int64 result; // x0
  __int64 v6; // [xsp+8h] [xbp-18h] BYREF
  char v7; // [xsp+10h] [xbp-10h]
  _BYTE v8[7]; // [xsp+11h] [xbp-Fh] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = **(_QWORD **)(a1 + 96);
  v7 = a2;
  memset(v8, 0, sizeof(v8));
  v6 = v4;
  *(_DWORD *)(a1 + 48) = 2;
  mod_timer(a1 + 56, jiffies + 2500LL);
  srcu_notifier_call_chain(*(_QWORD *)(a1 + 96) + 8LL, *(unsigned int *)(a1 + 48), &v6);
  result = timer_delete_sync(a1 + 56);
  _ReadStatusReg(SP_EL0);
  return result;
}
