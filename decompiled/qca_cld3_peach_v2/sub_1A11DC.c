// attributes: thunk
__int64 sub_1A11DC()
{
  __int64 v0; // x0

  v0 = ((__int64 (*)(void))"us_req_cmd_tlv")();
  return target_if_register_legacy_service_ready_cb(v0);
}
