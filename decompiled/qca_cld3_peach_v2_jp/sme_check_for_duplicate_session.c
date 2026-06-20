__int64 __fastcall sme_check_for_duplicate_session(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  _QWORD *v13; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD *v23; // x24
  __int64 v25; // x8
  _DWORD *v26; // x8
  unsigned int v27; // w20

  context = _cds_get_context(71, (__int64)"sme_check_for_duplicate_session", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
    return 4;
  v13 = context;
  if ( (unsigned int)qdf_mutex_acquire(a1 + 12776) )
    return 4;
  if ( *a2 )
  {
    v23 = a2 + 1;
    do
    {
      if ( *v13 && (v25 = *(_QWORD *)(*v13 + 72LL)) != 0 )
      {
        v26 = *(_DWORD **)(v25 + 16);
        if ( v26 )
        {
          if ( *(v26 - 1) != 454466150 )
            __break(0x8228u);
          if ( (((__int64 (__fastcall *)(_QWORD *, _QWORD))v26)(v13, 0) & 1) != 0 )
          {
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: Peer exists with same MAC",
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              "sme_check_for_duplicate_session");
            v27 = 14;
            goto LABEL_16;
          }
        }
      }
      else
      {
        qdf_trace_msg(0x45u, 1u, "%s invalid instance", v14, v15, v16, v17, v18, v19, v20, v21, "cdp_find_peer_exist");
      }
    }
    while ( *v23++ );
  }
  v27 = 0;
LABEL_16:
  qdf_mutex_release(a1 + 12776);
  return v27;
}
