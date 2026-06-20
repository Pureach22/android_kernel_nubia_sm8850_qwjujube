__int64 cnss_diag_activate_service()
{
  register_cld_cmd_cb(27, &cnss_diag_cmd_handler, 0);
  return 0;
}
