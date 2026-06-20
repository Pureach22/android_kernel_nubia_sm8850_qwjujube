__int64 nubia_dp_preference_exit()
{
  __int64 i; // x19
  __int64 result; // x0
  _QWORD *v2; // x9
  _QWORD *v3; // x8
  _QWORD *v4; // x21

  for ( i = 0; i != 16; i += 4 )
    sysfs_remove_file_ns(nubia_global_enhace_kobj, &(&disp_attrs)[i], 0);
  kobject_put(nubia_global_enhace_kobj);
  result = edid_ctl;
  if ( *(_QWORD *)(edid_ctl + 32) )
  {
    kfree(*(_QWORD *)(edid_ctl + 32));
    result = edid_ctl;
  }
  if ( *(_QWORD *)(result + 48) )
  {
    kfree(*(_QWORD *)(result + 48));
    result = edid_ctl;
  }
  v2 = *(_QWORD **)(result + 56);
  if ( v2 != (_QWORD *)(result + 56) )
  {
    do
    {
      v4 = (_QWORD *)*v2;
      v3 = (_QWORD *)v2[1];
      if ( (_QWORD *)*v3 == v2 && (_QWORD *)v4[1] == v2 )
      {
        v4[1] = v3;
        *v3 = v4;
      }
      else
      {
        _list_del_entry_valid_or_report(v2);
      }
      *v2 = 0xDEAD000000000100LL;
      v2[1] = 0xDEAD000000000122LL;
      kfree(v2 - 5);
      result = edid_ctl;
      v2 = v4;
    }
    while ( v4 != (_QWORD *)(edid_ctl + 56) );
  }
  if ( result )
    return kfree(result);
  return result;
}
