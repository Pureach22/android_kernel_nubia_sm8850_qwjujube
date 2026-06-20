__int64 __fastcall gsireg_parse_dummy(unsigned int a1)
{
  __int64 v2; // x20
  const char *v3; // x4
  long double v4; // q0
  __int64 v5; // x8
  __int64 result; // x0

  v2 = *(_QWORD *)(gsi_ctx + 8);
  if ( a1 >= 0x96 )
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d requested name of invalid reg=%d\n", "gsihal_reg_name_str", 186, a1);
    v3 = "Invalid Register";
  }
  else
  {
    v3 = gsireg_name_to_str[a1];
  }
  v4 = dev_err(v2, "%s:%d No parse function for %s\n", "gsireg_parse_dummy", 205, v3);
  v5 = gsi_ctx;
  if ( gsi_ctx )
  {
    if ( *(_QWORD *)(gsi_ctx + 28648) )
    {
      if ( a1 < 0x96 )
        goto LABEL_11;
      v4 = dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d requested name of invalid reg=%d\n", "gsihal_reg_name_str", 186, a1);
      v5 = gsi_ctx;
    }
    else if ( a1 < 0x96 )
    {
      goto LABEL_11;
    }
    if ( *(_QWORD *)(v5 + 28656) )
      v4 = dev_err(*(_QWORD *)(v5 + 8), "%s:%d requested name of invalid reg=%d\n", "gsihal_reg_name_str", 186, a1);
  }
LABEL_11:
  result = _warn_printk("invalid register operation", v4);
  __break(0x800u);
  return result;
}
