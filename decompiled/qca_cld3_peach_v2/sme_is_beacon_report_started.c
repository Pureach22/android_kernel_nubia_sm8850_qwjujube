__int64 __fastcall sme_is_beacon_report_started(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x9
  __int64 v11; // x8
  char v12; // w8
  const char *v13; // x2

  if ( a2 > 5 || (v10 = *(_QWORD *)(a1 + 17296), (v11 = v10 + 96LL * a2) == 0) )
  {
    v13 = "%s: vdev_id %d not found";
LABEL_9:
    qdf_trace_msg(0x34u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "sme_is_beacon_report_started", a2);
    v12 = 0;
    return v12 & 1;
  }
  if ( !a1 || !v10 || (*(_BYTE *)(v10 + 96LL * a2 + 1) & 1) == 0 )
  {
    v13 = "%s: CSR session not valid: %d";
    goto LABEL_9;
  }
  v12 = *(_BYTE *)(v11 + 51);
  return v12 & 1;
}
