__int64 __fastcall lim_join_result_callback(__int64 a1, __int64 a2)
{
  unsigned int v2; // w20
  __int64 result; // x0

  v2 = a2;
  result = pe_find_session_by_vdev_id(a1, a2);
  if ( result )
  {
    lim_send_sme_join_reassoc_rsp(
      a1,
      0,
      *(unsigned int *)(result + 10060),
      *(unsigned __int16 *)(result + 10056),
      result,
      v2);
    return pe_delete_session(a1);
  }
  return result;
}
