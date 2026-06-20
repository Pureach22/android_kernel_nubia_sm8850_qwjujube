unsigned __int16 *__fastcall sme_get_oper_chan_freq(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned __int16 *result; // x0
  __int64 v11; // x9

  if ( !a1 )
    goto LABEL_7;
  result = (unsigned __int16 *)_cds_get_context(52, (__int64)"sme_get_oper_chan_freq", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !result )
    return result;
  if ( *(unsigned __int8 *)(a1 + 104) <= 5uLL )
  {
    v11 = *((_QWORD *)result + 2153);
    if ( v11 )
    {
      if ( (*(_BYTE *)(v11 + 96LL * *(unsigned __int8 *)(a1 + 104) + 1) & 1) != 0 )
        return wlan_get_operation_chan_freq((unsigned __int16 *)a1);
    }
  }
LABEL_7:
  qdf_trace_msg(0x34u, 2u, "%s: Invalid vdev id is passed", a2, a3, a4, a5, a6, a7, a8, a9, "sme_get_oper_chan_freq");
  return nullptr;
}
