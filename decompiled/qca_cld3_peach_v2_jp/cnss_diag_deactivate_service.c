__int64 cnss_diag_deactivate_service()
{
  deregister_cld_cmd_cb(27);
  return 0;
}
