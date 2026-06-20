__int64 __fastcall lim_process_sme_cfg_action_frm_in_tb_ppdu(
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
  if ( a2 )
    return lim_send_action_frm_tb_ppdu_cfg(a1, *(unsigned __int8 *)(a2 + 2), *(unsigned __int8 *)(a2 + 3));
  else
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: Buffer is NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "lim_process_sme_cfg_action_frm_in_tb_ppdu");
}
