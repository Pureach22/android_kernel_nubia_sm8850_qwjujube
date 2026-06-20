__int64 sub_44F14C()
{
  __asm { LDSMINALH       W20, W23, [X11] }
  return csr_send_csa_restart_req();
}
