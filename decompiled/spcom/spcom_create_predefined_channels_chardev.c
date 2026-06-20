__int64 spcom_create_predefined_channels_chardev()
{
  unsigned int channel_chardev; // w19
  __int64 v1; // x21
  __int64 v2; // x25
  __int64 v3; // x22
  __int64 v5; // x28
  __int64 v6; // x20
  int v7; // w0
  int v8; // w24

  if ( (spcom_create_predefined_channels_chardev_is_predefined_created & 1) != 0 )
  {
    return 0;
  }
  else
  {
    v1 = 0;
    v2 = 0;
    while ( 1 )
    {
      v3 = spcom_dev;
      if ( !*(_BYTE *)(spcom_dev + v1) )
      {
LABEL_7:
        channel_chardev = 0;
        spcom_create_predefined_channels_chardev_is_predefined_created = 1;
        return channel_chardev;
      }
      mutex_lock(spcom_dev + 58296);
      channel_chardev = spcom_create_channel_chardev(v3 + v1, 0);
      mutex_unlock(spcom_dev + 58296);
      if ( channel_chardev )
        break;
      ++v2;
      v1 += 32;
      if ( v2 == 32 )
        goto LABEL_7;
    }
    printk(&unk_12F8B, "spcom_create_predefined_channels_chardev", v3 + v1);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: fail to create chardev [%s], ret [%d]\n",
      "spcom_create_predefined_channels_chardev",
      (const char *)&unk_F80E,
      (const char *)(v3 + v1),
      channel_chardev);
    if ( v2 )
    {
      v5 = 0;
      do
      {
        v6 = spcom_dev;
        if ( !*(_BYTE *)(spcom_dev + v5) )
          break;
        v7 = spcom_destroy_channel_chardev(spcom_dev + v5);
        if ( v7 )
        {
          v8 = v7;
          printk(&unk_10797, "spcom_create_predefined_channels_chardev", v6 + v5);
          ipc_log_string(
            spcom_ipc_log_context,
            "%sspcom:%s: fail to destroy chardev [%s], ret [%d]\n",
            "spcom_create_predefined_channels_chardev",
            (const char *)&unk_F80E,
            (const char *)(v6 + v5),
            v8);
        }
        --v2;
        v5 += 32;
      }
      while ( v2 );
    }
  }
  return channel_chardev;
}
