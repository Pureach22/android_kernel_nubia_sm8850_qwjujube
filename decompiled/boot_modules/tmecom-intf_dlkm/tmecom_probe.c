__int64 __fastcall tmecom_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 v6; // x0
  const char *property; // x0
  __int64 result; // x0
  unsigned __int64 v9; // x0
  __int64 v10; // x0
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v12; // [xsp+10h] [xbp-20h]
  __int64 v13; // [xsp+18h] [xbp-18h]
  __int64 v14; // [xsp+20h] [xbp-10h]
  __int64 v15; // [xsp+28h] [xbp-8h]

  v1 = a1 + 16;
  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = devm_kmalloc(a1 + 16, 176, 3520);
  if ( !v3 )
    goto LABEL_9;
  v4 = v3;
  *(_QWORD *)(v3 + 8) = v1;
  v5 = v3 + 8;
  v6 = *(_QWORD *)(a1 + 760);
  *(_BYTE *)(v5 + 8) = 1;
  *(_QWORD *)(v5 + 16) = 500;
  v13 = 0;
  v14 = 0;
  *(_QWORD *)s = 0;
  v12 = 0;
  *(_BYTE *)(v5 + 24) = 0;
  *(_QWORD *)(v5 + 32) = tmecom_receive_message;
  property = (const char *)of_get_property(v6, "mbox-names", 0);
  if ( property )
  {
    snprintf(s, 0x20u, "%s_send_message", property);
    v9 = mbox_request_channel(v5, 0);
    *(_QWORD *)(v4 + 64) = v9;
    if ( v9 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_err(v1, "failed to get mbox channel\n");
      result = *(unsigned int *)(v4 + 64);
      goto LABEL_10;
    }
    _mutex_init(v4 + 72, "&tdev->lock", &tmecom_probe___key);
    if ( !*(_QWORD *)(v4 + 64) || (v10 = devm_kmalloc(v1, 1024, 3520), (*(_QWORD *)(v4 + 160) = v10) != 0) )
    {
      _init_waitqueue_head(v4 + 136, "&tdev->waitq", &tmecom_probe___key_19);
      *(_BYTE *)(v4 + 168) = 0;
      *(_QWORD *)v4 = v1;
      *(_QWORD *)(a1 + 168) = v4;
      tmedev = v4;
      dev_info(a1 + 16, "tmecom probe success\n");
      result = 0;
      goto LABEL_10;
    }
    dev_err(v1, "message buffer alloc faile\n");
LABEL_9:
    result = 4294967284LL;
    goto LABEL_10;
  }
  result = 4294967274LL;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
