bool __fastcall rmnet_is_real_dev_registered(__int64 a1)
{
  return *(_QWORD *)(a1 + 264) == (_QWORD)rmnet_rx_handler;
}
