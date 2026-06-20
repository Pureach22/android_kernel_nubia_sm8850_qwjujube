double __fastcall sub_4A040C(__int64 a1)
{
  unsigned __int64 *v1; // x16

  __ldaxp(v1);
  return osif_vdev_sync_wait_for_ops(a1);
}
