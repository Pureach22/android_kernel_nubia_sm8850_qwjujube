__int64 __fastcall pmic_glink_ssr_notifier_cb(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x21
  _QWORD *v5; // x22
  __int64 v6; // x20
  _QWORD *v7; // x19
  _QWORD *i; // x23
  _QWORD *v9; // t1
  _DWORD *v10; // x8
  __int64 v11; // x0

  v2 = (_QWORD *)(a1 - 296);
  ipc_log_string(*(_QWORD *)(a1 - 296), "code: %lu\n", a2);
  if ( a2 == 2 )
  {
    v5 = (_QWORD *)(a1 - 320);
    *(_DWORD *)(a1 - 36) = 2;
    pm_stay_awake(*(_QWORD *)(a1 - 320));
    v6 = a1 - 264;
    mutex_lock(a1 - 264);
    v9 = *(_QWORD **)(a1 - 16);
    v7 = (_QWORD *)(a1 - 16);
    for ( i = v9; i != v7; i = (_QWORD *)*i )
    {
      v10 = (_DWORD *)i[2];
      v11 = *(i - 2);
      if ( *(v10 - 1) != 1214264421 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v10)(v11, 0);
    }
    mutex_unlock(v6);
    pm_relax(*v5);
    ipc_log_string(*v2, "state_cb done %d\n", 0);
  }
  return 0;
}
