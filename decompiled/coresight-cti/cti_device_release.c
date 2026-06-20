__int64 __fastcall cti_device_release(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x8
  int v5; // w10
  _QWORD *v6; // x8
  _QWORD *v7; // x9
  char *v8; // x11
  _QWORD *v9; // x10
  __int64 result; // x0
  __int64 (__fastcall *v11)(_QWORD); // x8

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  v3 = mutex_lock(&ect_mutex);
  v4 = *(unsigned int *)(v2 + 40);
  if ( (_DWORD)v4 != -1 )
  {
    if ( (unsigned int)v4 >= 0x20 )
    {
      __break(0x5512u);
      return readl_relaxed(v3);
    }
    v5 = nr_cti_cpu;
    cti_cpu_drvdata[v4] = 0;
    nr_cti_cpu = v5 - 1;
    if ( v5 == 1 )
    {
      cpu_pm_unregister_notifier(&cti_cpu_pm_nb);
      _cpuhp_remove_state(138, 0);
    }
  }
  v6 = ect_net;
  while ( v6 != &ect_net )
  {
    v7 = v6;
    v8 = (char *)(v6 - 147);
    v6 = (_QWORD *)*v6;
    if ( v8 == (char *)v2 )
    {
      v9 = (_QWORD *)v7[1];
      if ( (_QWORD *)*v9 == v7 && (_QWORD *)v6[1] == v7 )
      {
        v6[1] = v9;
        *v9 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v7);
      }
      *v7 = 0xDEAD000000000100LL;
      v7[1] = 0xDEAD000000000122LL;
      break;
    }
  }
  result = mutex_unlock(&ect_mutex);
  v11 = *(__int64 (__fastcall **)(_QWORD))(v2 + 1192);
  if ( v11 )
  {
    if ( *((_DWORD *)v11 - 1) != 1820440776 )
      __break(0x8228u);
    return v11(a1);
  }
  return result;
}
