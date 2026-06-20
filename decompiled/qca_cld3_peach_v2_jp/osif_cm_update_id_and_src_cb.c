__int64 __fastcall osif_cm_update_id_and_src_cb(__int64 a1, int a2, int a3)
{
  __int64 v3; // x21

  v3 = *(_QWORD *)(a1 + 608);
  if ( v3 )
  {
    qdf_spinlock_acquire(v3 + 32);
    *(_DWORD *)(v3 + 24) = a2;
    *(_DWORD *)(v3 + 28) = a3;
    qdf_spinlock_release(v3 + 32);
    return 0;
  }
  else
  {
    qdf_trace_msg(72, 2, "%s: Invalid vdev osif priv", "osif_cm_update_id_and_src_cb");
    return 4;
  }
}
