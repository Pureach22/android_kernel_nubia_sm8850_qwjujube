__int64 __fastcall icnss_register_fw_service(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x3

  result = qmi_handle_init(a1 + 624, 6182, wlfw_qmi_ops, &wlfw_msg_handlers);
  if ( (result & 0x80000000) == 0 )
  {
    v3 = *(_QWORD *)(a1 + 304);
    v4 = 3;
    if ( v3 != 25680 && v3 != 26448 && v3 != 30544 )
      v4 = 0;
    return qmi_add_lookup(a1 + 624, 69, 1, v4);
  }
  return result;
}
