__int64 __fastcall icnss_aop_interface_init(__int64 a1)
{
  __int64 v2; // x9
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x0
  __int64 result; // x0
  unsigned int v6; // w19

  if ( (unsigned int)of_property_read_string(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 760LL), "qcom,vreg_ol_cpr", a1 + 288)
    && !*(_QWORD *)(a1 + 5768) )
  {
    ipc_log_string(icnss_ipc_log_context, "Vreg for OL CPR and pdc_init table not configured\n");
    return 4294967274LL;
  }
  else
  {
    v2 = *(_QWORD *)(a1 + 8);
    *(_BYTE *)(a1 + 5696) = 1;
    *(_QWORD *)(a1 + 5704) = 1000;
    *(_QWORD *)(a1 + 5688) = v2 + 16;
    *(_BYTE *)(a1 + 5712) = 0;
    *(_QWORD *)(a1 + 5744) = 0;
    *(_QWORD *)(a1 + 5752) = 0;
    *(_BYTE *)(a1 + 5760) = 0;
    v3 = mbox_request_channel(a1 + 5688, 0);
    if ( v3 < 0xFFFFFFFFFFFFF001LL )
    {
      *(_QWORD *)(a1 + 5744) = v3;
      ipc_log_string(icnss_ipc_log_context, "Mbox channel initialized\n");
    }
    else
    {
      ipc_log_string(icnss_ipc_log_context, "Failed to get mbox channel with err %d\n", v3);
      v4 = qmp_get(*(_QWORD *)(a1 + 8) + 16LL);
      *(_QWORD *)(a1 + 5752) = v4;
      if ( v4 >= 0xFFFFFFFFFFFFF001LL )
      {
        printk("%sFailed to get qmp\n", byte_130B32);
        ipc_log_string(icnss_ipc_log_context, "%sFailed to get qmp\n", (const char *)&unk_12DBF3);
        return *(unsigned int *)(a1 + 5752);
      }
      *(_BYTE *)(a1 + 5760) = 1;
      ipc_log_string(icnss_ipc_log_context, "QMP initialized\n");
    }
    result = icnss_aop_pdc_reconfig(a1);
    if ( (_DWORD)result )
    {
      v6 = result;
      printk("%sFailed to reconfig WLAN PDC, err = %d\n", byte_130B32, result);
      ipc_log_string(icnss_ipc_log_context, "%sFailed to reconfig WLAN PDC, err = %d\n", (const char *)&unk_12DBF3, v6);
      return v6;
    }
  }
  return result;
}
