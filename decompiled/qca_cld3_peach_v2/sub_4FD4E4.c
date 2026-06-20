double __fastcall sub_4FD4E4(__int64 a1)
{
  unsigned __int64 *v1; // x16

  __ldaxp(v1);
  return osif_vdev_sync_wait_for_ops(a1);
}
