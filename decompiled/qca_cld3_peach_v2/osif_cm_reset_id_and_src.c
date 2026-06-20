__int64 __fastcall osif_cm_reset_id_and_src(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 680);
  if ( v1 )
  {
    qdf_spinlock_acquire(v1 + 32);
    *(_QWORD *)(v1 + 24) = -4294967275LL;
    qdf_spinlock_release(v1 + 32);
    return 0;
  }
  else
  {
    qdf_trace_msg(72, 2, "%s: Invalid vdev osif priv", "osif_cm_reset_id_and_src");
    return 4;
  }
}
