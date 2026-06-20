__int64 sub_64097C()
{
  __asm { LDSMINALH       W20, W23, [X11] }
  return os_if_qmi_wfds_send_misc_req_msg();
}
