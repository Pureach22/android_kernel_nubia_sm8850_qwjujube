__int64 __fastcall cnss_wlfw_xo_trim_result_send_sync(__int64 a1, int a2)
{
  unsigned int v2; // w1

  if ( a2 )
    v2 = 2;
  else
    v2 = 1;
  return cnss_wlfw_misc_req_send_sync(a1, v2);
}
