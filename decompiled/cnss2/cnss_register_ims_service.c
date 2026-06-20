__int64 __fastcall cnss_register_ims_service(__int64 a1)
{
  __int64 result; // x0

  result = qmi_handle_init(a1 + 7064, 0x2000, ims_qmi_ops, &qmi_ims_msg_handlers);
  if ( (result & 0x80000000) == 0 )
    return qmi_add_lookup(a1 + 7064, 77, 1, 0);
  return result;
}
