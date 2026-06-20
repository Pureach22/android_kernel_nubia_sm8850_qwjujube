__int64 __fastcall icnss_thermal_cdev_unregister(__int64 result)
{
  __int64 v1; // x9
  _QWORD *v2; // x19
  _QWORD **v3; // x20
  _QWORD *v4; // x8
  __int64 v5; // x9

  v1 = *(_QWORD *)(result + 152);
  v2 = *(_QWORD **)(v1 + 5528);
  v3 = (_QWORD **)(v1 + 5528);
  if ( v2 != (_QWORD *)(v1 + 5528) )
  {
    do
    {
      thermal_cooling_device_unregister(v2[6]);
      v4 = (_QWORD *)v2[1];
      if ( (_QWORD *)*v4 == v2 && (v5 = *v2, *(_QWORD **)(*v2 + 8LL) == v2) )
      {
        *(_QWORD *)(v5 + 8) = v4;
        *v4 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report(v2);
      }
      *v2 = 0xDEAD000000000100LL;
      v2[1] = 0xDEAD000000000122LL;
      result = kfree(v2);
      v2 = *v3;
    }
    while ( *v3 != v3 );
  }
  return result;
}
