__int64 __fastcall icnss_ims_process_wfc_call_ind_cb(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 *a4)
{
  __int64 result; // x0
  const char *v7; // x19

  if ( !a3 )
  {
    v7 = "%sicnss2_qmi: IMS->CNSS: WFC_CALL_IND: Spurious indication\n";
    printk("%sicnss2_qmi: IMS->CNSS: WFC_CALL_IND: Spurious indication\n", byte_130B32);
    return ipc_log_string(icnss_ipc_log_context, v7, &unk_12DBF3);
  }
  if ( !a4 )
  {
    v7 = "%sicnss2_qmi: IMS->CNSS: WFC_CALL_IND: Invalid indication\n";
    printk("%sicnss2_qmi: IMS->CNSS: WFC_CALL_IND: Invalid indication\n", byte_130B32);
    return ipc_log_string(icnss_ipc_log_context, v7, &unk_12DBF3);
  }
  ipc_log_string(
    icnss_ipc_log_context,
    "icnss2_qmi: IMS->CNSS: WFC_CALL_IND: %x, %x %x, %x %x, %x %llx, %x %x, %x %x\n",
    *a4,
    a4[1],
    a4[2],
    a4[3],
    a4[4],
    a4[5],
    *((_QWORD *)a4 + 1),
    a4[16],
    *((unsigned __int16 *)a4 + 9),
    a4[20],
    *((_DWORD *)a4 + 6));
  result = kmemdup_noprof(a4, 32, 3264);
  if ( result )
    return icnss_driver_event_post(a1 - 1232, 0xEu, 0, result);
  return result;
}
