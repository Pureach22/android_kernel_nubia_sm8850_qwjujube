__int64 sub_4B0914()
{
  __asm { LDSMINALH       W20, W23, [X11] }
  return csr_mlme_vdev_stop_bss();
}
