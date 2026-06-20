__int64 qmi_tmd_cleanup()
{
  __int64 v0; // x21
  __int64 v1; // x22
  __int64 result; // x0
  __int64 v3; // x25
  _QWORD *v4; // x19
  __int64 v5; // x0
  _QWORD *v6; // x27
  _QWORD *v7; // x8
  __int64 v8; // x9

  if ( tmd_inst_cnt >= 1 )
  {
    v0 = 0;
    v1 = tmd_instances;
    do
    {
      v3 = v1 + 416 * v0;
      mutex_lock(v3 + 312);
      v4 = *(_QWORD **)(v3 + 368);
      if ( v4 != (_QWORD *)(v3 + 368) )
      {
        do
        {
          v5 = v4[2];
          v6 = (_QWORD *)*v4;
          *((_BYTE *)v4 - 8) = 0;
          if ( v5 )
            thermal_cooling_device_unregister();
          v7 = (_QWORD *)v4[1];
          if ( (_QWORD *)*v7 == v4 && (v8 = *v4, *(_QWORD **)(*v4 + 8LL) == v4) )
          {
            *(_QWORD *)(v8 + 8) = v7;
            *v7 = v8;
          }
          else
          {
            _list_del_entry_valid_or_report(v4);
          }
          *v4 = 0xDEAD000000000100LL;
          v4[1] = 0xDEAD000000000122LL;
          v4 = v6;
        }
        while ( v6 != (_QWORD *)(v3 + 368) );
      }
      qmi_handle_release(v3 + 8);
      result = mutex_unlock(v3 + 312);
      ++v0;
    }
    while ( v0 < tmd_inst_cnt );
  }
  return result;
}
