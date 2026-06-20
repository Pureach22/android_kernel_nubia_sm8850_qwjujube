__int64 __fastcall hdd_reset_btm_abridge_flag(
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
  __int64 *v10; // x20
  char v11; // w19

  if ( !a2 )
    return 4294967274LL;
  v10 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  v11 = *(_BYTE *)(a2 + 4) == 0;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Reset BTM abridge flag: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_reset_btm_abridge_flag");
  wlan_mlme_set_btm_abridge_flag(*v10, v11);
  return 0;
}
