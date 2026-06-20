void __fastcall android_rvh_flush_task(__int64 a1, char *a2)
{
  _BYTE *v3; // x20
  __int64 v4; // x0

  if ( (walt_disabled & 1) == 0 )
  {
    if ( a2 == (char *)&init_task )
      v3 = &vendor_data_pad;
    else
      v3 = a2 + 5184;
    _sched_set_group_id(a2, 0);
    if ( (v3[191] & 4) != 0 )
      ((void (__fastcall *)(_BYTE *))remove_pipeline)(v3);
    v4 = ((__int64 (__fastcall *)(_BYTE *))remove_heavy)(v3);
    if ( (char *)pipeline_special_task == a2 )
      remove_special_task(v4);
  }
}
