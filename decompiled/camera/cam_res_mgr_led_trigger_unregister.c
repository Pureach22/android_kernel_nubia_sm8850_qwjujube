__int64 __fastcall cam_res_mgr_led_trigger_unregister(__int64 a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x19
  _QWORD *v4; // x8
  _QWORD *v5; // x9

  if ( !cam_res )
    return led_trigger_unregister_simple();
  mutex_lock(cam_res + 536);
  v2 = a1;
  v3 = (_QWORD *)(cam_res + 472);
  while ( 1 )
  {
    v3 = (_QWORD *)*v3;
    if ( v3 == (_QWORD *)(cam_res + 472) )
      break;
    if ( v3[3] == v2 )
    {
      led_trigger_unregister_simple();
      v4 = (_QWORD *)v3[1];
      if ( (_QWORD *)*v4 == v3 && (v5 = (_QWORD *)*v3, *(_QWORD **)(*v3 + 8LL) == v3) )
      {
        v5[1] = v4;
        *v4 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
      }
      *v3 = v3;
      v3[1] = v3;
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v3, 0);
      else
        kvfree(v3);
      return mutex_unlock(cam_res + 536);
    }
  }
  return mutex_unlock(cam_res + 536);
}
