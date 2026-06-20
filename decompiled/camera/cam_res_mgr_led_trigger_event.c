__int64 __fastcall cam_res_mgr_led_trigger_event(__int64 a1)
{
  _QWORD *v2; // x10

  if ( !cam_res )
    return led_trigger_event(a1);
  mutex_lock(cam_res + 536);
  v2 = (_QWORD *)(cam_res + 472);
  while ( 1 )
  {
    v2 = (_QWORD *)*v2;
    if ( v2 == (_QWORD *)(cam_res + 472) )
      break;
    if ( v2[3] == a1 )
    {
      mutex_unlock(cam_res + 536);
      return led_trigger_event(a1);
    }
  }
  return mutex_unlock(cam_res + 536);
}
