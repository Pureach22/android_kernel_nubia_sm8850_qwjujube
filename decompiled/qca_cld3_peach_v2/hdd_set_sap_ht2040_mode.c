__int64 __fastcall hdd_set_sap_ht2040_mode(
        __int64 *a1,
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
  __int64 v11; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  unsigned int v22; // w19
  const char *v23; // x2

  v11 = *a1;
  qdf_trace_msg(0x33u, 8u, "%s: change HT20/40 mode", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_set_sap_ht2040_mode");
  if ( *(_DWORD *)(v11 + 40) != 1 )
    return 0;
  v21 = *(_QWORD *)(*(_QWORD *)(v11 + 24) + 16LL);
  if ( !v21 )
  {
    v22 = 5;
    v23 = "%s: mac handle is null";
    goto LABEL_7;
  }
  if ( (unsigned int)sme_set_ht2040_mode(v21, *((unsigned __int8 *)a1 + 8), a2) != 16 )
    return 0;
  v22 = 16;
  v23 = "%s: Failed to change HT20/40 mode";
LABEL_7:
  qdf_trace_msg(0x33u, 2u, v23, v13, v14, v15, v16, v17, v18, v19, v20, "hdd_set_sap_ht2040_mode");
  return v22;
}
