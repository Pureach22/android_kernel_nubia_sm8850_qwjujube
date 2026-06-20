__int64 __fastcall hal_rx_proc_phyrx_other_receive_info_tlv_peach(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20

  v9 = jiffies;
  if ( hal_rx_proc_phyrx_other_receive_info_tlv_peach___last_ticks - jiffies + 125 < 0 )
  {
    result = qdf_trace_msg(
               0x46u,
               2u,
               "%s: unhandled TLV type: %d, TLV len:%d",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "hal_rx_proc_phyrx_other_receive_info_tlv_peach",
               (*(_DWORD *)(result + 8) >> 1) & 0x1FF,
               (*(_DWORD *)(result + 8) >> 10) & 0xFFF);
    hal_rx_proc_phyrx_other_receive_info_tlv_peach___last_ticks = v9;
  }
  return result;
}
