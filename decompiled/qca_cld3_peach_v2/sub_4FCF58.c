__int64 __fastcall sub_4FCF58(__int64 a1)
{
  unsigned __int64 *v1; // x16

  __ldaxp(v1);
  return osif_vdev_sync_destroy(a1);
}
