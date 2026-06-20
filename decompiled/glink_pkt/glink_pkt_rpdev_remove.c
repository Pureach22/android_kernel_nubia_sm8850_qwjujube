__int64 __fastcall glink_pkt_rpdev_remove(__int64 a1)
{
  __int64 v1; // x22

  v1 = *(_QWORD *)(a1 + 136);
  mutex_lock(v1 - 232);
  glink_pkt_clear_queues(v1 - 1280);
  *(_QWORD *)(v1 - 144) = 0;
  mutex_unlock(v1 - 232);
  *(_QWORD *)(a1 + 152) = 0;
  *(_DWORD *)(v1 - 184) = 0;
  return _wake_up(v1 - 80, 1, 1, 0);
}
