void ipa3_q6_clnt_svc_exit()
{
  __int64 v0; // x8

  if ( ipa3_qmi_ctx )
  {
    v0 = ipa3_qmi_ctx + 28672;
    *(_WORD *)(ipa3_qmi_ctx + 28876) = 0;
    *(_QWORD *)(v0 + 208) = 0;
  }
}
