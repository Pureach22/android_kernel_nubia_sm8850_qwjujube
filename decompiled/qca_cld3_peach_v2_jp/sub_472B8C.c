__int64 __fastcall sub_472B8C(__int64 a1)
{
  __asm { LDSMINALH       W20, W23, [X11] }
  return wma_send_vdev_stop(a1);
}
