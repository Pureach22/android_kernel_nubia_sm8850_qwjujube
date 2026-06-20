__int64 __fastcall cal_done_ind_cb(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  unsigned __int64 v12; // x10

  result = ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Received QMI WLFW calibration done indication\n");
  if ( a3 )
  {
    *(_BYTE *)(a1 - 280) = 1;
    _X8 = (unsigned __int64 *)(a1 + 1208);
    __asm { PRFM            #0x11, [X8] }
    do
      v12 = __ldxr(_X8);
    while ( __stxr(v12 & 0xFFFFFFFFFFDFFFFFLL, _X8) );
  }
  else
  {
    printk("%sicnss2_qmi: Spurious indication\n", byte_130B32);
    return ipc_log_string(icnss_ipc_log_context, "%sicnss2_qmi: Spurious indication\n", (const char *)&unk_12DBF3);
  }
  return result;
}
