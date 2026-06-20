void __fastcall qcom_geni_i3c_ibi_conf(__int64 a1)
{
  _BYTE *v1; // x20
  int v3; // w8
  unsigned int v4; // w0
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 v7; // x0

  v1 = (_BYTE *)(a1 + 20480);
  v3 = *(unsigned __int8 *)(a1 + 21654);
  *(_DWORD *)(a1 + 21440) = 0;
  *(_DWORD *)(a1 + 21360) = 0;
  if ( v3 == 1 )
    writel_relaxed(0x5FD74322u, (unsigned int *)(*(_QWORD *)(a1 + 21328) + 8LL));
  if ( v1[980] == 1 && (v1[981] & 1) == 0 && (unsigned int)geni_i3c_enable_naon_ibi_clks(a1, 1) )
  {
    ipc_log_string(*(_QWORD *)(a1 + 2528), "%s:  NAON clock failure\n", "qcom_geni_i3c_ibi_conf");
    v7 = *(_QWORD *)(a1 + 8);
    if ( v7 )
      dev_err(v7, "%s:  NAON clock failure\n", "qcom_geni_i3c_ibi_conf");
    else
      printk(&unk_13A7A, "qcom_geni_i3c_ibi_conf", v5, v6);
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
  }
  else
  {
    geni_i3c_enable_ibi_ctrl(a1, 1);
    if ( v1[1174] == 1 )
    {
      v4 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 21328) + 20LL));
      writel_relaxed(v4, (unsigned int *)(*(_QWORD *)(a1 + 21328) + 20LL));
    }
    writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(a1 + 21328) + 12LL));
    writel_relaxed(0xFFFFFFFF, (unsigned int *)(*(_QWORD *)(a1 + 21328) + 4104LL));
    v1[841] = 1;
  }
}
