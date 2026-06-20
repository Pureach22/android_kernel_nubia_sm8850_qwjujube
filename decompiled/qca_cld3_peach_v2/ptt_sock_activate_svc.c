__int64 ptt_sock_activate_svc()
{
  register_cld_cmd_cb(17, ptt_cmd_handler, 0);
  return register_cld_cmd_cb(23, ptt_cmd_handler, 0);
}
