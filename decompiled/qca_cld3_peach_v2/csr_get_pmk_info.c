__int64 __fastcall csr_get_pmk_info(
        __int64 a1,
        char a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  if ( a1 )
    return wlan_cm_get_psk_pmk(*(_QWORD *)(a1 + 21632), a2, (void *)(a3 + 22), (_BYTE *)(a3 + 86));
  else
    return qdf_trace_msg(0x34u, 2u, "%s: Mac_ctx is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "csr_get_pmk_info");
}
