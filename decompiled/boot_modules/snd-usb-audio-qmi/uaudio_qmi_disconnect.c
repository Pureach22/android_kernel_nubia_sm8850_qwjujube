__int64 uaudio_qmi_disconnect()
{
  __int64 i; // x23
  __int64 result; // x0
  char *v2; // x26
  __int64 j; // x22
  __int64 v4; // x8
  __int64 v5; // x28
  unsigned __int64 v6; // x19
  __int64 v7; // x9
  unsigned int v8; // w2
  _QWORD *v9; // x9
  _QWORD *v10; // x10
  _QWORD *v11; // x8
  __int64 **v12; // x27
  __int64 v13; // x8
  unsigned __int64 v14; // x8
  __int64 v15; // x11
  unsigned __int64 v16; // x8
  __int64 v17; // x11
  __int64 v18; // x28

  for ( i = 0; i != 32; ++i )
  {
    v2 = (char *)&uadev[11 * i];
    if ( *((_DWORD *)v2 + 6) )
    {
      if ( *((int *)v2 + 16) >= 1 )
      {
        for ( j = 0; j < *((int *)v2 + 16); ++j )
        {
          v4 = *((_QWORD *)v2 + 9);
          if ( v4 )
          {
            v5 = v4 + 80 * j;
            if ( *(_BYTE *)(v5 + 76) == 1 )
            {
              v6 = *(unsigned __int8 *)(v5 + 73);
              if ( v6 >= 0x20 )
              {
                __break(0x5512u);
                return disable_audio_stream();
              }
              v7 = uadev[11 * *(unsigned __int8 *)(v5 + 73) + 10];
              if ( v7 )
              {
                v8 = *(unsigned __int8 *)(v5 + 74);
                if ( !*(_DWORD *)(v7 + 216) )
                {
                  if ( *(_DWORD *)(v7 + 344) <= v8 )
                  {
                    printk(&unk_B155, "find_substream");
                  }
                  else if ( *(unsigned __int8 *)(v5 + 75) >= 2u )
                  {
                    printk(&unk_B311, "find_substream");
                  }
                  else
                  {
                    v9 = (_QWORD *)(v7 + 280);
                    v10 = v9;
                    while ( 1 )
                    {
                      v10 = (_QWORD *)*v10;
                      if ( v10 == v9 )
                        break;
                      if ( *((_DWORD *)v10 - 106) == v8 )
                      {
                        v11 = &v10[26 * *(unsigned __int8 *)(v5 + 75)];
                        v12 = (__int64 **)(v11 - 52);
                        if ( v11 == qword_1A0 )
                          break;
                        v13 = *((_QWORD *)v2 + 10);
                        if ( !v13 || *(_DWORD *)(v13 + 216) )
                          break;
                        v14 = *(unsigned int *)(v5 + 56);
                        if ( (_DWORD)v14 )
                        {
                          v15 = 1128;
                          if ( (v14 & 0x80) == 0 )
                            v15 = 1256;
                          xhci_sideband_remove_endpoint(
                            uadev[11 * *(unsigned __int8 *)(v5 + 73) + 7],
                            *(_QWORD *)(uadev[11 * *(unsigned __int8 *)(v5 + 73)] + v15 + 8 * ((v14 >> 15) & 0xF)));
                        }
                        v16 = *(unsigned int *)(v5 + 60);
                        if ( (_DWORD)v16 )
                        {
                          v17 = 1128;
                          if ( (v16 & 0x80) == 0 )
                            v17 = 1256;
                          xhci_sideband_remove_endpoint(
                            uadev[11 * (unsigned int)v6 + 7],
                            *(_QWORD *)(uadev[11 * (unsigned int)v6] + v17 + 8 * ((v16 >> 15) & 0xF)));
                        }
                        v18 = **v12;
                        snd_usb_hw_free(v12);
                        snd_usb_autosuspend(v18);
                        goto LABEL_9;
                      }
                    }
                  }
                }
              }
              ipc_log_string(
                *(_QWORD *)(uaudio_svc + 24),
                "%s%s: no subs for c#%u, dev#%u dir%u\n",
                (const char *)&unk_B13E,
                "uaudio_qmi_disconnect",
                *(unsigned __int8 *)(v5 + 73),
                *(unsigned __int8 *)(v5 + 74),
                *(unsigned __int8 *)(v5 + 75));
              printk("%s%s: no subs for c#%u, dev#%u dir%u\n", &unk_B8A7);
            }
          }
LABEL_9:
          ;
        }
      }
      *((_DWORD *)v2 + 6) = 0;
      result = uaudio_dev_cleanup(&uadev[11 * i]);
    }
  }
  return result;
}
