__int64 __fastcall rmnet_mem_nl_cmd_config_get(__int64 a1, __int64 a2)
{
  rmnet_mem_genl_send_int_to_userspace_no_info(ipa_config, a2);
  return 0;
}
