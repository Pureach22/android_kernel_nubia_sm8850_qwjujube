__int64 __fastcall icnss_dms_init(__int64 a1)
{
  __int64 result; // x0
  const char *v3; // x20
  unsigned int v4; // w19

  LODWORD(result) = qmi_handle_init(a1 + 928, 256, qmi_dms_ops, 0);
  if ( (result & 0x80000000) != 0 )
  {
    v3 = "%sicnss2_qmi: Failed to initialize DMS handle, err: %d\n";
LABEL_6:
    v4 = result;
    printk(v3, byte_130B32, (unsigned int)result);
    ipc_log_string(icnss_ipc_log_context, v3, &unk_12DBF3, v4);
    return v4;
  }
  result = qmi_add_lookup(a1 + 928, 2, 1, 0);
  if ( (result & 0x80000000) != 0 )
  {
    v3 = "%sicnss2_qmi: Failed to add DMS lookup, err: %d\n";
    goto LABEL_6;
  }
  return result;
}
