// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_533860(
        int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v11; // x20
  __int64 result; // x0

  if ( a1 )
    return extract_recv_bcn_stats_tlv();
  qdf_trace_msg(0x25u, 2u, (const char *)(a11 + 294), a2, a3, a4, a5, a6, a7, a8, a9, "wifi_pos_pdev_iterator");
  result = _qdf_mem_free(v11);
  _ReadStatusReg(SP_EL0);
  return result;
}
