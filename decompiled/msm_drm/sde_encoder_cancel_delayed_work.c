__int64 __fastcall sde_encoder_cancel_delayed_work(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    result = kthread_cancel_delayed_work_sync(result + 944);
    if ( (result & 1) != 0 && (_drm_debug & 4) != 0 )
      return _drm_dev_dbg(0, 0, 0, "enc%d sw_event:%d, work cancelled\n", *(_DWORD *)(v1 + 24), 0);
  }
  return result;
}
