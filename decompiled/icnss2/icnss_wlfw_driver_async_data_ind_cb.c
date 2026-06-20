__int64 __fastcall icnss_wlfw_driver_async_data_ind_cb(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  __int64 (*v8)(void); // x8

  ipc_log_string(icnss_ipc_log_long_context, "icnss2_qmi: Received QMI WLFW driver async data indication\n");
  if ( a3 )
  {
    ipc_log_string(
      icnss_ipc_log_long_context,
      "icnss2_qmi: Extract message with event length: %d, type: %d\n",
      *(_DWORD *)a4,
      *(unsigned __int16 *)(a4 + 6148));
    result = *(_QWORD *)(a1 + 4848);
    if ( result )
    {
      v8 = *(__int64 (**)(void))(a1 + 4856);
      if ( v8 )
      {
        if ( *((_DWORD *)v8 - 1) != -578656991 )
          __break(0x8228u);
        return v8();
      }
    }
  }
  else
  {
    printk("%sicnss2_qmi: Spurious indication\n", byte_130B32);
    return ipc_log_string(icnss_ipc_log_context, "%sicnss2_qmi: Spurious indication\n", (const char *)&unk_12DBF3);
  }
  return result;
}
