__int64 sub_45642C()
{
  __asm { LDSMINALH       W20, W23, [X11] }
  return csr_mlme_vdev_disconnect_all_p2p_client_event();
}
