void __fastcall sme_scan_event_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        _QWORD *a11)
{
  __int64 v13; // x26
  __int64 i; // x21
  __int64 v15; // x8
  _DWORD *v16; // x8
  __int64 v17; // x0
  __int64 v18; // x2

  if ( a11 )
  {
    if ( a11[1818] && !*(_DWORD *)(a10 + 4) )
    {
      v13 = 0;
      for ( i = 0; i != 6; ++i )
      {
        v15 = a11[2153];
        if ( v15 && *(_BYTE *)(v15 + v13 + 1) == 1 )
        {
          if ( v15 + v13 )
          {
            if ( *(_BYTE *)(v15 + v13 + 51) == 1 )
            {
              qdf_trace_msg(
                0x34u,
                8u,
                "%s: Send pause ind for vdev_id : %d",
                a1,
                a2,
                a3,
                a4,
                a5,
                a6,
                a7,
                a8,
                "sme_scan_event_handler",
                (unsigned int)i);
              v16 = (_DWORD *)a11[1818];
              v17 = a11[1595];
              v18 = *(unsigned int *)(a10 + 4);
              if ( *(v16 - 1) != -549181079 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64, _QWORD, __int64, _QWORD))v16)(v17, (unsigned int)i, v18, 0);
            }
          }
          else
          {
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: vdev_id %d not found",
              a1,
              a2,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              "sme_is_beacon_report_started",
              (unsigned int)i);
          }
        }
        v13 += 96;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: Invalid mac context", a1, a2, a3, a4, a5, a6, a7, a8, "sme_scan_event_handler");
  }
}
