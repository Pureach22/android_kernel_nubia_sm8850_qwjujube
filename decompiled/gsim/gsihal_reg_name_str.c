const char *__fastcall gsihal_reg_name_str(unsigned int a1)
{
  if ( a1 < 0x96 )
    return gsireg_name_to_str[a1];
  dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d requested name of invalid reg=%d\n", "gsihal_reg_name_str", 186, a1);
  return "Invalid Register";
}
