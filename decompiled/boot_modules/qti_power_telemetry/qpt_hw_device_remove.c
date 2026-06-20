__int64 __fastcall qpt_hw_device_remove(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 result; // x0
  _QWORD *v3; // x19
  _QWORD *v4; // x20
  _QWORD *v5; // t1
  _QWORD *v6; // x22
  _QWORD *v7; // x8
  _QWORD *v8; // x9

  v1 = *(_QWORD **)(a1 + 168);
  _pm_runtime_disable(*v1, 1);
  dev_pm_genpd_remove_notifier(*v1);
  result = qti_qpt_start_stop_telemetry(v1, 0);
  v5 = (_QWORD *)v1[23];
  v3 = v1 + 23;
  v4 = v5;
  if ( v5 != v3 )
  {
    do
    {
      result = v4[3];
      v6 = (_QWORD *)*v4;
      if ( result )
        result = qptm_channel_unregister();
      v7 = (_QWORD *)v4[1];
      if ( (_QWORD *)*v7 == v4 && (v8 = (_QWORD *)*v4, *(_QWORD **)(*v4 + 8LL) == v4) )
      {
        v8[1] = v7;
        *v7 = v8;
      }
      else
      {
        result = _list_del_entry_valid_or_report(v4);
      }
      *v4 = 0xDEAD000000000100LL;
      v4[1] = 0xDEAD000000000122LL;
      v4 = v6;
    }
    while ( v6 != v3 );
  }
  return result;
}
