__int64 sub_216B90()
{
  __asm { LDTRB           W24, [X29,#-0x34] }
  return wmi_unified_lteu_config_cmd_send();
}
