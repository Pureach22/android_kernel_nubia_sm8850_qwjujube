__int64 __fastcall rmnet_offload_state_notifier(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 v3; // x20
  char v6; // w10
  __int64 v7; // x0
  __int64 port; // x0
  __int64 v9; // x19
  __int64 v10; // x2

  v3 = *a3;
  if ( *a3 && !strncmp((const char *)(v3 + 296), "rmnet_data", 0xAu) )
  {
    if ( a2 == 6 )
    {
      if ( rmnet_offload )
      {
        v6 = *(_BYTE *)(rmnet_offload + 5304) - 1;
        *(_BYTE *)(rmnet_offload + 5304) = v6;
        if ( !v6 )
        {
          v7 = printk(&unk_8895, "rmnet_offload_state_notifier", v3 + 296);
          rmnet_offload_state_free(v7);
        }
      }
    }
    else if ( a2 == 5 )
    {
      if ( rmnet_offload )
      {
        ++*(_BYTE *)(rmnet_offload + 5304);
      }
      else
      {
        port = rmnet_get_port(*(_QWORD *)(v3 + 2696));
        if ( port )
        {
          v9 = port;
          printk(&unk_878C, "rmnet_offload_state_notifier", v3 + 296);
          if ( (unsigned int)rmnet_offload_state_init(v9) == 2 )
            printk(&unk_876D, "rmnet_offload_state_notifier", v10);
        }
        else
        {
          printk(&unk_88DE, "rmnet_offload_state_notifier", v3 + 296);
        }
      }
    }
  }
  return 0;
}
