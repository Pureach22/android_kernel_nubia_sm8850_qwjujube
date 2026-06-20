__int64 __fastcall hdd_config_ignore_assoc_disallowed(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w19
  __int64 v11; // x20

  v10 = *(unsigned __int8 *)(a2 + 4);
  v11 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: %u",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_config_ignore_assoc_disallowed",
    *(unsigned __int8 *)(a2 + 4));
  if ( v10 > 1 )
    return 4294967274LL;
  sme_set_check_assoc_disallowed(*(_QWORD *)(v11 + 16), v10 == 0);
  return 0;
}
