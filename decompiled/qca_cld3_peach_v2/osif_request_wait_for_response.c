__int64 __fastcall osif_request_wait_for_response(__int64 a1)
{
  __int64 v1; // x0

  v1 = qdf_wait_for_event_completion(a1 + 48, *(unsigned int *)(a1 + 36));
  return qdf_status_to_os_return(v1);
}
