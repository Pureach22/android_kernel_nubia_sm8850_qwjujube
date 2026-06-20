unsigned __int64 dp_audio_codec_ready()
{
  unsigned __int64 data; // x0
  unsigned __int64 v2; // x19
  __int64 ipc_log_context; // x0

  data = dp_audio_get_data();
  if ( data >= 0xFFFFFFFFFFFFF001LL )
  {
    v2 = data;
    ipc_log_context = get_ipc_log_context(data);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_audio_codec_ready");
    return v2;
  }
  else
  {
    queue_delayed_work_on(32, *(_QWORD *)(data + 192), data + 200, 62);
    return 0;
  }
}
