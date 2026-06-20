__int64 __fastcall umac_stop_complete_cb(__int64 a1, __int64 a2)
{
  return qdf_event_set(*(_QWORD *)(a1 + 8), a2);
}
