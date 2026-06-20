__int64 ipa3_get_ipc_logbuf()
{
  if ( ipa3_ctx )
    return *(_QWORD *)(ipa3_ctx + 34152);
  else
    return 0;
}
