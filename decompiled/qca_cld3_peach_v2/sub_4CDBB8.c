__int64 __fastcall sub_4CDBB8(__int64 a1)
{
  __asm { LDSMINALH       W20, W23, [X11] }
  return wma_send_vdev_stop(a1);
}
