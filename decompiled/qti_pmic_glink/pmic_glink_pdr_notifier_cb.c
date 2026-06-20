__int64 __fastcall pmic_glink_pdr_notifier_cb(int a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  _QWORD *i; // x20
  _DWORD *v7; // x8
  __int64 v8; // x0

  result = ipc_log_string(*(_QWORD *)(a3 + 32), "PDR state: %x\n", a1);
  if ( a1 == 0x1FFFFFFF )
    return ipc_log_string(*(_QWORD *)(a3 + 32), "PD state up for %s\n", *(const char **)(a3 + 376));
  if ( a1 == 0xFFFFFFF )
  {
    ipc_log_string(*(_QWORD *)(a3 + 32), "PD state down for %s\n", *(const char **)(a3 + 376));
    pm_stay_awake(*(_QWORD *)(a3 + 8));
    mutex_lock(a3 + 64);
    for ( i = *(_QWORD **)(a3 + 312); i != (_QWORD *)(a3 + 312); i = (_QWORD *)*i )
    {
      v7 = (_DWORD *)i[2];
      v8 = *(i - 2);
      if ( *(v7 - 1) != 1214264421 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v7)(v8, 0);
    }
    mutex_unlock(a3 + 64);
    pm_relax(*(_QWORD *)(a3 + 8));
    result = ipc_log_string(*(_QWORD *)(a3 + 32), "state_cb done %d\n", 0);
    *(_DWORD *)(a3 + 392) = 0xFFFFFFF;
  }
  return result;
}
