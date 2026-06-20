__int64 __fastcall osif_vdev_sync_wait_for_ops(__int64 a1)
{
  return dsc_vdev_wait_for_ops(*(_QWORD *)(a1 + 8));
}
