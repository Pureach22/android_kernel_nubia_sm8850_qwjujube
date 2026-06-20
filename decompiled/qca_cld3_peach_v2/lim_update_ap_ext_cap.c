__int64 __fastcall lim_update_ap_ext_cap(
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
  *(_BYTE *)(a1 + 10045) = (*(_WORD *)(a2 + 3324) & 0x2000) != 0;
  *(_BYTE *)(a1 + 10046) = (*(_WORD *)(a2 + 3324) & 0x4000) != 0;
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: Ext Cap peer TWT requestor: %d, responder: %d",
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "lim_set_sap_peer_twt_cap",
           (*(unsigned __int16 *)(a2 + 3324) >> 13) & 1,
           (*(unsigned __int16 *)(a2 + 3324) >> 14) & 1);
}
