__int64 sub_23970C()
{
  unsigned __int128 *v0; // x18

  __ldaxp(v0);
  return send_mws_coex_status_req_cmd_tlv();
}
