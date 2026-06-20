__int64 __fastcall icnss_wlfw_respond_get_info_ind_cb(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  __int64 (*v6)(void); // x8

  if ( a3 )
  {
    ipc_log_string(
      icnss_ipc_log_long_context,
      "icnss2_qmi: Extract message with event length: %d, type: %d, is last: %d, seq no: %d\n",
      *(_DWORD *)a4,
      *(unsigned __int8 *)(a4 + 6149),
      *(unsigned __int8 *)(a4 + 6151),
      *(_DWORD *)(a4 + 6156));
    result = *(_QWORD *)(a1 + 4832);
    if ( result )
    {
      v6 = *(__int64 (**)(void))(a1 + 4840);
      if ( v6 )
      {
        if ( *((_DWORD *)v6 - 1) != 1142088401 )
          __break(0x8228u);
        return v6();
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
