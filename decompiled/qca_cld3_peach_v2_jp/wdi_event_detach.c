__int64 __fastcall wdi_event_detach(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 i; // x20
  __int64 v11; // x21
  _DWORD *v12; // x8
  const char *v14; // x2

  if ( !a1 )
  {
    v14 = "Invalid device in %s\nWDI detach failed";
LABEL_15:
    qdf_trace_msg(0x3Fu, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "wdi_event_detach");
    return 0xFFFFFFFFLL;
  }
  if ( !*(_QWORD *)(a1 + 56) )
  {
    v14 = "%s: wdi_event_list is NULL";
    goto LABEL_15;
  }
  for ( i = 0; i != 50; ++i )
  {
    v11 = *(_QWORD *)(*(_QWORD *)(a1 + 56) + 8 * i);
    while ( v11 )
    {
      v12 = *(_DWORD **)(v11 + 8);
      v11 = *(_QWORD *)(v11 + 16);
      if ( v12 )
      {
        if ( *(v12 - 1) != -73020817 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v12)(512, (unsigned int)i | 0x100);
      }
    }
  }
  _qdf_mem_free(*(_QWORD *)(a1 + 56));
  *(_QWORD *)(a1 + 56) = 0;
  return 0;
}
