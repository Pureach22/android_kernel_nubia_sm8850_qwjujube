__int64 __fastcall swrm_lock_sleep(__int64 a1)
{
  int v2; // w8
  int v3; // w20
  __int64 v4; // x21
  __int64 v5; // x20
  unsigned int v6; // w24
  bool v7; // cf
  __int64 v8; // x0
  __int64 v9; // x21
  unsigned int v10; // w19
  int v12; // w8
  _QWORD v13[6]; // [xsp+0h] [xbp-30h] BYREF

  v13[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(a1 + 8880);
  v2 = *(_DWORD *)(a1 + 15832);
  *(_DWORD *)(a1 + 15832) = v2 + 1;
  if ( !v2 )
  {
    cpu_latency_qos_update_request(a1 + 15752, 10);
    pm_stay_awake(*(_QWORD *)(a1 + 8512));
  }
  mutex_unlock(a1 + 8880);
  if ( !a1 )
    goto LABEL_20;
  mutex_lock(a1 + 8880);
  v3 = *(_DWORD *)(a1 + 15800);
  if ( !v3 )
  {
    *(_DWORD *)(a1 + 15800) = 1;
    mutex_unlock(a1 + 8880);
LABEL_20:
    v5 = a1 + 15808;
    v10 = 1;
    goto LABEL_21;
  }
  mutex_unlock(a1 + 8880);
  if ( v3 == 1 )
    goto LABEL_20;
  memset(v13, 0, 40);
  init_wait_entry(v13, 0);
  v4 = 175;
  v5 = a1 + 15808;
  while ( 1 )
  {
    prepare_to_wait_event(a1 + 15808, v13, 2);
    mutex_lock(a1 + 8880);
    v6 = *(_DWORD *)(a1 + 15800);
    if ( !v6 )
      *(_DWORD *)(a1 + 15800) = 1;
    mutex_unlock(a1 + 8880);
    v7 = v4 || v6 >= 2;
    v8 = v7 ? v4 : 1LL;
    if ( v6 < 2 || !v8 )
      break;
    v4 = schedule_timeout();
  }
  v9 = v8;
  finish_wait(a1 + 15808, v13);
  if ( v9 )
    goto LABEL_20;
  if ( (unsigned int)__ratelimit(&swrm_lock_sleep__rs, "swrm_lock_sleep") )
    dev_err(
      *(_QWORD *)(a1 + 8512),
      "%s: system didn't resume within %dms, s %d, w %d\n",
      "swrm_lock_sleep",
      700,
      *(_DWORD *)(a1 + 15800),
      *(_DWORD *)(a1 + 15832));
  mutex_lock(a1 + 8880);
  v12 = *(_DWORD *)(a1 + 15832) - 1;
  *(_DWORD *)(a1 + 15832) = v12;
  if ( !v12 )
  {
    if ( *(_DWORD *)(a1 + 15800) == 1 )
      *(_DWORD *)(a1 + 15800) = 0;
    cpu_latency_qos_update_request(a1 + 15752, 0xFFFFFFFFLL);
    pm_relax(*(_QWORD *)(a1 + 8512));
  }
  mutex_unlock(a1 + 8880);
  v10 = 0;
LABEL_21:
  _wake_up(v5, 3, 0, 0);
  _ReadStatusReg(SP_EL0);
  return v10;
}
