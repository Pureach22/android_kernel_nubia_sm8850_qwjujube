__int64 __fastcall hdd_monitor_mode_qdf_create_event(__int64 a1, char a2)
{
  if ( a2 != 6 )
    return 0;
  qdf_event_create((_DWORD *)(a1 + 1664));
  return qdf_event_create((_DWORD *)(a1 + 1704));
}
