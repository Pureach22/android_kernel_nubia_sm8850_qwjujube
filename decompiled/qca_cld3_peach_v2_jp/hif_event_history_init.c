__int64 __fastcall hif_event_history_init(__int64 a1, unsigned __int8 a2)
{
  if ( a2 >= 0x12u )
  {
    __break(0x5512u);
    JUMPOUT(0x15D470);
  }
  *(_QWORD *)(a1 + 8LL * a2 + 2608) = (char *)&hif_event_desc_history + 16408 * a2;
  *((_DWORD *)&hif_event_desc_history + 4102 * a2) = -1;
  return qdf_trace_msg(61, 5, "%s: SRNG events history initialized for group: %d", "hif_event_history_init", a2);
}
