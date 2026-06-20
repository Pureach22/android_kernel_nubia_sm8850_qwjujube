__int64 __fastcall icnss_wlfw_process_twt_cfg_ind(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 *a4)
{
  __int64 result; // x0
  const char *v7; // x19

  if ( !a3 )
  {
    v7 = "%sicnss2_qmi: FW->CNSS: TWT_CFG_IND: Spurious indication\n";
    printk("%sicnss2_qmi: FW->CNSS: TWT_CFG_IND: Spurious indication\n", byte_130B32);
    return ipc_log_string(icnss_ipc_log_context, v7, &unk_12DBF3);
  }
  if ( !a4 )
  {
    v7 = "%sicnss2_qmi: FW->CNSS: TWT_CFG_IND: Invalid indication\n";
    printk("%sicnss2_qmi: FW->CNSS: TWT_CFG_IND: Invalid indication\n", byte_130B32);
    return ipc_log_string(icnss_ipc_log_context, v7, &unk_12DBF3);
  }
  ipc_log_string(
    icnss_ipc_log_context,
    "icnss2_qmi: FW->CNSS: TWT_CFG_IND: %x %llx, %x %x, %x %x, %x %x, %x %x, %x %x\n",
    *a4,
    *((_QWORD *)a4 + 1),
    a4[16],
    *((unsigned __int16 *)a4 + 9),
    a4[20],
    *((unsigned __int16 *)a4 + 11),
    a4[24],
    *((unsigned __int16 *)a4 + 13),
    a4[28],
    *((unsigned __int16 *)a4 + 15),
    a4[32],
    a4[33]);
  result = kmemdup_noprof(a4, 40, 3264);
  if ( result )
    return icnss_driver_event_post(a1 - 624, 0xFu, 0, result);
  return result;
}
