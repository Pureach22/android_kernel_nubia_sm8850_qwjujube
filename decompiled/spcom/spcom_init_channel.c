__int64 __fastcall spcom_init_channel(__int64 a1, char a2, char *string)
{
  size_t v6; // x0
  unsigned __int64 v7; // x2
  int v8; // w8
  __int64 v10; // x0

  if ( !string || !*string )
  {
    printk(&unk_FF3B, "spcom_init_channel", string);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: invalid parameters\n",
      "spcom_init_channel",
      (const char *)&unk_F80E);
    return 4294967274LL;
  }
  v6 = strnlen(string, 0x20u);
  if ( v6 == -1 )
  {
    _fortify_panic(2, -1, 0);
LABEL_15:
    v10 = _fortify_panic(7, 32, v7);
    return spcom_register_rpmsg_drv(v10);
  }
  if ( v6 == 32 )
    v7 = 32;
  else
    v7 = v6 + 1;
  if ( v7 >= 0x21 )
    goto LABEL_15;
  sized_strscpy(a1, string, v7);
  *(_DWORD *)(a1 + 168) = 0;
  _init_swait_queue_head(a1 + 176, "&x->wait", &init_completion___key);
  *(_DWORD *)(a1 + 200) = 0;
  _init_swait_queue_head(a1 + 208, "&x->wait", &init_completion___key);
  _mutex_init(a1 + 32, "&ch->lock", &spcom_init_channel___key);
  *(_QWORD *)(a1 + 296) = 0;
  *(_QWORD *)(a1 + 304) = 0;
  *(_DWORD *)(a1 + 80) = 305419896;
  *(_DWORD *)(a1 + 336) = 305419896;
  *(_QWORD *)(a1 + 309) = 0;
  *(_BYTE *)(a1 + 85) = 1;
  if ( (a2 & 1) != 0 )
    v8 = 5;
  else
    v8 = 1;
  *(_BYTE *)(a1 + 232) = 0;
  *(_QWORD *)(a1 + 152) = 0;
  *(_QWORD *)(a1 + 160) = 0;
  *(_QWORD *)(a1 + 320) = 0;
  *(_QWORD *)(a1 + 328) = 0;
  *(_BYTE *)(a1 + 233) = a2 & 1;
  *(_DWORD *)(a1 + 236) = v8;
  *(_DWORD *)(a1 + 240) = 0;
  *(_BYTE *)(a1 + 244) = 0;
  _mutex_init(a1 + 248, "&ch->shared_sync_lock", &spcom_init_channel___key_199);
  return 0;
}
