__int64 __fastcall sde_kms_timeline_status(__int64 a1)
{
  _QWORD *v1; // x20
  _QWORD *i; // x21
  __int64 result; // x0
  _QWORD v5[3]; // [xsp+8h] [xbp-18h] BYREF

  v5[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  v5[1] = 0;
  if ( a1 )
  {
    v1 = *(_QWORD **)(a1 + 864);
    for ( i = (_QWORD *)(a1 + 864); v1 != i; v1 = (_QWORD *)*v1 )
      sde_crtc_timeline_status((__int64)(v1 - 2));
    if ( (mutex_is_locked(a1 + 432) & 1) != 0 )
    {
      printk(&unk_27DA18, "sde_kms_timeline_status");
      drm_connector_list_iter_begin(a1, v5);
      while ( drm_connector_list_iter_next(v5) )
        sde_conn_timeline_status();
      result = drm_connector_list_iter_end(v5);
    }
    else
    {
      mutex_lock(a1 + 432);
      drm_connector_list_iter_begin(a1, v5);
      while ( drm_connector_list_iter_next(v5) )
        sde_conn_timeline_status();
      drm_connector_list_iter_end(v5);
      result = mutex_unlock(a1 + 432);
    }
  }
  else
  {
    result = printk(&unk_273E02, "sde_kms_timeline_status");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
