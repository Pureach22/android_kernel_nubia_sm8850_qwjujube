__int64 __fastcall gunyah_set_event_open(__int64 a1, __int64 a2)
{
  __int64 v2; // x2

  v2 = *(_QWORD *)(a1 + 696);
  if ( (*(_BYTE *)(a2 + 12) & 2) != 0 && (*(_BYTE *)(a2 + 49) & 2) != 0 )
  {
    *(_QWORD *)(v2 + 24) = 0;
    v2 = *(_QWORD *)(a1 + 696);
  }
  return single_open(a2, gunyah_set_event_show, v2);
}
