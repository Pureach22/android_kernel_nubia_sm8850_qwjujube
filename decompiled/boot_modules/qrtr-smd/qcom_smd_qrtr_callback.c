__int64 __fastcall qcom_smd_qrtr_callback(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x21
  unsigned int v5; // w20

  v3 = *(_QWORD *)(a1 + 152);
  if ( v3 )
  {
    v5 = qrtr_endpoint_post(*(_QWORD *)(a1 + 152), a2, a3);
    if ( v5 == -22 )
    {
      dev_err(*(_QWORD *)(v3 + 32), "invalid ipcrouter packet\n");
      v5 = 0;
    }
    if ( (qcom_glink_is_wakeup(1) & 1) != 0 )
      qrtr_print_wakeup_reason(a2);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&qcom_smd_qrtr_callback__rs, "qcom_smd_qrtr_callback") )
      printk(&unk_648B, "qcom_smd_qrtr_callback");
    return (unsigned int)-11;
  }
  return v5;
}
