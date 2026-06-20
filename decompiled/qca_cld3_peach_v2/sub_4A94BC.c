__int64 sub_4A94BC()
{
  __asm { LDSMINALH       W20, W23, [X11] }
  return csr_send_csa_restart_req();
}
