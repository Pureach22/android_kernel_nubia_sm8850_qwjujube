__int64 __fastcall dp_bridge_hpd_cb(__int64 a1, char a2, char a3)
{
  __int64 v6; // x1

  mutex_lock(a1 + 208);
  v6 = system_wq;
  *(_BYTE *)(a1 + 200) = a2;
  *(_BYTE *)(a1 + 201) = a3;
  queue_delayed_work_on(32, v6, a1 + 88, 0);
  mutex_unlock(a1 + 208);
  return 0;
}
