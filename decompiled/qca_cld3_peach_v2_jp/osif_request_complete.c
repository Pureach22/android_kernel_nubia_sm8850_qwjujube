__int64 __fastcall osif_request_complete(__int64 a1)
{
  return qdf_event_set(a1 + 48);
}
