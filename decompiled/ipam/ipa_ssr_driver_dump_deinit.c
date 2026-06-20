__int64 ipa_ssr_driver_dump_deinit()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0

  kfree(dmesg_buf);
  kfree(qword_1FDBA8);
  kfree(qword_1FDBB0);
  kfree(qword_1FDBB8);
  kfree(qword_1FDBC0);
  kfree(qword_1FDBC8);
  kfree(qword_1FDBD0);
  kfree(qword_1FDBD8);
  kfree(ipc_buf);
  kfree(qword_1FDBE8);
  kfree(qword_1FDBF0);
  kfree(qword_1FDBF8);
  kfree(qword_1FDC00);
  kfree(qword_1FDC08);
  kfree(qword_1FDC10);
  kfree(qword_1FDC18);
  kfree(qword_1FDC20);
  kfree(qword_1FDC28);
  kfree(qword_1FDC30);
  kfree(qword_1FDC38);
  kfree(qword_1FDC40);
  kfree(qword_1FDC48);
  if ( num_of_regions_registered )
  {
    v0 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v1 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v1 )
      {
        ipc_log_string(v1, "ipa %s:%d deiniting with regions still registered", "ipa_ssr_driver_dump_deinit", 109);
        v0 = ipa3_ctx;
      }
      v2 = *(_QWORD *)(v0 + 34160);
      if ( v2 )
        ipc_log_string(v2, "ipa %s:%d deiniting with regions still registered", "ipa_ssr_driver_dump_deinit", 109);
    }
  }
  num_of_regions_registered = 0;
  return 0;
}
