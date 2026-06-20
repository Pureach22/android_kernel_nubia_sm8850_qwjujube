__int64 __fastcall htc_recv_init(__int64 a1)
{
  return qdf_event_create(a1 + 3368);
}
