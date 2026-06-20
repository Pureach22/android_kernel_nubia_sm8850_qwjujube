__int64 __fastcall ipa_wigig_get_pipe_smmu_info(_QWORD *a1, unsigned int a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a2 >= 5 )
  {
    printk(&unk_3DFD03, "ipa_wigig_get_pipe_smmu_info");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_wigig %s:%d exceeded pipe num %d > %d\n",
        "ipa_wigig_get_pipe_smmu_info",
        840,
        a2,
        5);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_wigig %s:%d exceeded pipe num %d > %d\n",
        "ipa_wigig_get_pipe_smmu_info",
        840,
        a2,
        5);
    }
    return 4294967274LL;
  }
  else
  {
    *a1 = ipa_wigig_ctx + 96LL * a2 + 128;
    return 0;
  }
}
