__int64 __fastcall mlme_vdev_self_peer_delete_resp_flush_cb(__int64 a1)
{
  sme_vdev_self_peer_delete_resp(*(_QWORD *)(a1 + 8));
  return 0;
}
