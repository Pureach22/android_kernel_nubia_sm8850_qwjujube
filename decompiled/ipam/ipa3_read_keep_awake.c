__int64 __fastcall ipa3_read_keep_awake(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w0
  int v8; // w23

  mutex_lock(ipa3_ctx + 30504);
  if ( *(_DWORD *)(ipa3_ctx + 30552) )
    v7 = scnprintf(&dbg_buff, 4096, "IPA APPS power state is ON\n");
  else
    v7 = scnprintf(&dbg_buff, 4096, "IPA APPS power state is OFF\n");
  v8 = v7;
  mutex_unlock(ipa3_ctx + 30504);
  return simple_read_from_buffer(a2, a3, a4, &dbg_buff, v8);
}
