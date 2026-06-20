__int64 __fastcall ipa3_should_pipe_channel_be_stopped(__int64 a1)
{
  int v1; // w19
  _QWORD *ep_mapping; // x0
  __int64 v3; // x13
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0

  if ( *(_DWORD *)(ipa3_ctx + 32240) < 0xEu )
    return 0;
  v1 = a1;
  ep_mapping = (_QWORD *)ipa_get_ep_mapping(a1);
  if ( (_DWORD)ep_mapping == -1 )
  {
    printk(&unk_3AC96C, "ipa3_should_pipe_channel_be_stopped");
    v5 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(v6, "ipa %s:%d Invalid client.\n", "ipa3_should_pipe_channel_be_stopped", 7594);
        v5 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v5 + 34160);
      if ( v7 )
        ipc_log_string(v7, "ipa %s:%d Invalid client.\n", "ipa3_should_pipe_channel_be_stopped", 7594);
    }
    __break(0x800u);
    return 0;
  }
  else if ( (unsigned int)ep_mapping >= 0x25 )
  {
    __break(0x5512u);
    *ep_mapping = v3;
    return ipa_stop_gsi_channel((char *)ep_mapping + 217);
  }
  else
  {
    if ( (*(_BYTE *)(ipa3_ctx + 480LL * (unsigned int)ep_mapping + 573) & 1) != 0 )
      return 0;
    return ((v1 - 39) & 0xFFFFFFFD) == 0;
  }
}
