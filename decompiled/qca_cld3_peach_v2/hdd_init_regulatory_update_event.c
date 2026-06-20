__int64 __fastcall hdd_init_regulatory_update_event(__int64 a1)
{
  unsigned int v2; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  const char *v11; // x2
  unsigned int v12; // w19

  v2 = qdf_event_create((_DWORD *)(a1 + 6952));
  if ( v2 )
  {
    v11 = "%s: Failed to create regulatory update event";
  }
  else
  {
    v2 = qdf_mutex_create(a1 + 6992);
    if ( !v2 )
    {
      *(_BYTE *)(a1 + 6948) = 0;
      return qdf_status_to_os_return(v2);
    }
    v11 = "%s: Failed to create regulatory status mutex";
  }
  v12 = v2;
  qdf_trace_msg(0x33u, 2u, v11, v3, v4, v5, v6, v7, v8, v9, v10, "hdd_init_regulatory_update_event");
  v2 = v12;
  return qdf_status_to_os_return(v2);
}
