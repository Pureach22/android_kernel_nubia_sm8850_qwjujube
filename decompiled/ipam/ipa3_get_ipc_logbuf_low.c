__int64 ipa3_get_ipc_logbuf_low()
{
  if ( ipa3_ctx )
    return *(_QWORD *)(ipa3_ctx + 34160);
  else
    return 0;
}
