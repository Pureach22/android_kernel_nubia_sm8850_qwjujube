__int64 sub_7361F0()
{
  __int64 v0; // x9
  __int64 v1; // x13
  __int64 v2; // x27

  *(_QWORD *)(v2 + 208) = v1;
  *(_QWORD *)(v2 + 216) = v0;
  return send_set_ric_req_cmd_tlv();
}
