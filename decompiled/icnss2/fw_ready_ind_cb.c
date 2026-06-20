__int64 __fastcall fw_ready_ind_cb(__int64 a1, __int64 a2, __int64 a3)
{
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Received FW Ready Indication\n");
  if ( a3 )
    return icnss_driver_event_post(a1 - 624, 2u, 0, 0);
  else
    return printk(byte_12E112);
}
