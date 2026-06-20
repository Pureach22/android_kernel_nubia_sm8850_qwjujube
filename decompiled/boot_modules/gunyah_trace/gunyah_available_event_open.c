__int64 __fastcall gunyah_available_event_open(__int64 a1, __int64 a2)
{
  return single_open(a2, gunyah_available_event_show, *(_QWORD *)(a1 + 696));
}
