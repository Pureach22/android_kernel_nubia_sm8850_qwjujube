__int64 __fastcall tpd_touch_report(
        __int64 a1,
        unsigned __int16 a2,
        unsigned __int16 a3,
        unsigned __int16 a4,
        unsigned __int8 a5,
        unsigned __int8 a6)
{
  __int64 v8; // x25
  unsigned int v12; // w21

  v8 = tpd_cdev;
  v12 = a6;
  mutex_lock(tpd_cdev + 2776);
  input_event(a1, 3, 47, a4);
  input_mt_report_slot_state(a1, 0, 1);
  input_event(a1, 1, 330, 1);
  input_event(a1, 3, 53, a2);
  input_event(a1, 3, 54, a3);
  if ( v12 )
    input_event(a1, 3, 58, v12);
  if ( a5 )
    input_event(a1, 3, 48, a5);
  return mutex_unlock(v8 + 2776);
}
