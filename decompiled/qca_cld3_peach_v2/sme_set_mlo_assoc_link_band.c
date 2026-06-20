__int64 __fastcall sme_set_mlo_assoc_link_band(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  if ( a2 <= 5u && *(_QWORD *)(a1 + 17296) + 96LL * a2 )
    return wlan_mlme_set_sta_mlo_conn_band_bmp(*(_QWORD *)(a1 + 21624), a3);
  else
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: No session for id %d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "sme_set_mlo_assoc_link_band");
}
