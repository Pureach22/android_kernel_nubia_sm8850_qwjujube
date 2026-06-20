__int64 __fastcall hdd_set_roam_reason_vsie_status(
        unsigned __int8 *a1,
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
  __int64 *v10; // x8
  int v11; // w20
  const char *v13; // x2
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  v10 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  if ( !v10 )
  {
    v13 = "%s: hdd_ctx failure";
    goto LABEL_5;
  }
  v11 = *(unsigned __int8 *)(a2 + 4);
  if ( (unsigned int)wlan_mlme_set_roam_reason_vsie_status(*v10, *(_BYTE *)(a2 + 4) != 0) )
  {
    v13 = "%s: set roam reason vsie failed";
LABEL_5:
    qdf_trace_msg(0x33u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_set_roam_reason_vsie_status");
    return 4294967274LL;
  }
  v15 = sme_cli_set_command(a1[8], 157, v11 != 0, 1);
  if ( v15 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set beacon report error vsie",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "hdd_set_roam_reason_vsie_status");
    v15 = 16;
  }
  return qdf_status_to_os_return(v15);
}
