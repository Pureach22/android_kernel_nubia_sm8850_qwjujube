__int64 __fastcall sub_6CEED4(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int128 v5; // q13
  __int128 v6; // q16

  *(_OWORD *)(a5 + 768) = v6;
  *(_OWORD *)(a5 + 784) = v5;
  return send_link_reconfig_req_cmd_tlv();
}
