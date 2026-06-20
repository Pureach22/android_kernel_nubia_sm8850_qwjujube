__int64 __fastcall pmic_glink_init_work(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  _QWORD *i; // x23
  void (__fastcall *v4)(__int64, __int64); // x8
  __int64 v5; // x0

  v1 = *(_QWORD *)(result - 208);
  v2 = result;
  if ( *(_DWORD *)(result + 176) == 0xFFFFFFF || *(_DWORD *)(result + 76) == 2 )
  {
    pm_stay_awake(*(_QWORD *)(result - 208));
    mutex_lock(v2 - 152);
    for ( i = *(_QWORD **)(v2 + 96); i != (_QWORD *)(v2 + 96); i = (_QWORD *)*i )
    {
      v4 = (void (__fastcall *)(__int64, __int64))i[2];
      v5 = *(i - 2);
      if ( *((_DWORD *)v4 - 1) != 1214264421 )
        __break(0x8228u);
      v4(v5, 1);
    }
    mutex_unlock(v2 - 152);
    pm_relax(*(_QWORD *)(v2 - 208));
    result = ipc_log_string(*(_QWORD *)(v2 - 184), "state_cb done %d\n", 1);
    *(_DWORD *)(v2 + 176) = 0x1FFFFFFF;
    *(_DWORD *)(v2 + 76) = 1;
  }
  if ( (*(_BYTE *)(v2 + 80) & 1) == 0 )
  {
    result = of_platform_populate(*(_QWORD *)(v1 + 744), 0, 0, v1);
    if ( (result & 0x80000000) != 0 )
      return printk(&unk_76FE, "pmic_glink_init_work", (unsigned int)result);
    else
      *(_BYTE *)(v2 + 80) = 1;
  }
  return result;
}
