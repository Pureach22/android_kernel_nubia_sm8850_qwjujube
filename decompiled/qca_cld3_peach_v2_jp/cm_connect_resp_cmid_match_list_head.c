__int64 __fastcall cm_connect_resp_cmid_match_list_head(__int64 a1, __int64 a2)
{
  return cm_check_cmid_match_list_head(a1, a2 + 4) & 1;
}
