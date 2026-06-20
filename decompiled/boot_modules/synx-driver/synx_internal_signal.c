__int64 __fastcall synx_internal_signal(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned __int64 client; // x0
  __int64 v6; // x4
  __int64 v7; // x5
  unsigned __int64 v8; // x19
  unsigned __int64 v9; // x0
  unsigned int v10; // w21
  unsigned __int64 v11; // x23
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x24
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x5
  unsigned int v18; // w0
  unsigned __int64 v20; // x21

  client = synx_get_client();
  if ( client && client < 0xFFFFFFFFFFFFF001LL )
  {
    if ( a3 >= 2 && (a3 > 0x40 || a3 == 2 || a3 == 4) )
    {
      v8 = client;
      v9 = synx_util_acquire_handle(client, a2);
      if ( v9 )
      {
        if ( v9 <= 0xFFFFFFFFFFFFF000LL )
        {
          v11 = *(_QWORD *)(v9 + 8);
          if ( v11 )
          {
            if ( v11 <= 0xFFFFFFFFFFFFF000LL )
            {
              v12 = *(_QWORD *)(v11 + 64);
              if ( v12 )
              {
                if ( v12 < 0xFFFFFFFFFFFFF001LL )
                {
                  v13 = v9;
                  mutex_lock(v11 + 72);
                  if ( ((a2 & 0x100000) != 0 || (*(_BYTE *)(v11 + 124) & 2) != 0)
                    && (v18 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))synx_global_update_status_core)(
                                *(unsigned int *)(v11 + 344),
                                a3,
                                0)) != 0 )
                  {
                    v10 = v18;
                    mutex_unlock(v11 + 72);
                    if ( (synx_debug & 1) != 0 )
                      printk(&unk_27CA3, &unk_29207, "synx_internal_signal", 936, *(_QWORD *)(v8 + 104), a2);
                  }
                  else
                  {
                    if ( *(_DWORD *)(v11 + 132) || *(_QWORD *)(v11 + 328) != v11 + 328 )
                      synx_signal_offload_job(v8, v11, a2, a3);
                    v10 = synx_native_signal_fence(v11, a3, v14, v15, v16, v17);
                    if ( v10 )
                    {
                      if ( (synx_debug & 1) != 0 )
                        printk(&unk_2524A, &unk_29207, "synx_internal_signal", 953, *(_QWORD *)(v8 + 104), a2);
                    }
                    else if ( (synx_debug & 0x10) != 0 )
                    {
                      printk(&unk_283DA, "verb", "synx_internal_signal", 956, *(_QWORD *)(v8 + 104), a2);
                    }
                    mutex_unlock(v11 + 72);
                  }
                  v9 = v13;
                  goto LABEL_27;
                }
              }
            }
          }
        }
      }
      if ( (synx_debug & 1) != 0 )
      {
        v20 = v9;
        printk(&unk_29EEC, &unk_29207, "synx_internal_signal", 921, *(_QWORD *)(v8 + 104), a2);
        v9 = v20;
      }
    }
    else
    {
      v8 = client;
      if ( (synx_debug & 1) != 0 )
        printk(&unk_2A57E, &unk_29207, "synx_internal_signal", 910, *(_QWORD *)(client + 104), a3);
      v9 = 0;
    }
    v10 = -22;
LABEL_27:
    synx_util_release_handle(v9);
    synx_put_client(v8);
    return v10;
  }
  if ( (synx_debug & 1) != 0 )
    printk(&unk_2B010, &unk_29207, "synx_internal_signal", 900, v6, v7);
  return (unsigned int)-22;
}
