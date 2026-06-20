__int64 __fastcall synx_bind(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  unsigned __int64 client; // x0
  __int64 v8; // x4
  __int64 v9; // x5
  unsigned __int64 v10; // x19
  unsigned __int64 v11; // x0
  unsigned __int64 v12; // x21
  unsigned __int64 v13; // x20
  unsigned __int64 bind_ops; // x0
  _DWORD **v15; // x27
  unsigned int v16; // w8
  unsigned int v17; // w25
  unsigned __int64 v19; // x20
  unsigned __int64 v20; // x26
  unsigned int v21; // w8
  unsigned __int64 v22; // x28
  _QWORD *v23; // x28
  int v24; // w8
  _DWORD *v25; // x8
  unsigned int v26; // w0
  int v27; // w8
  unsigned __int64 StatusReg; // x25
  __int64 v29; // x28
  __int64 (__fastcall *v30)(_QWORD, _QWORD, _QWORD); // x0

  client = synx_get_client();
  if ( client )
  {
    v10 = client;
    if ( client < 0xFFFFFFFFFFFFF001LL )
    {
      v11 = synx_util_acquire_handle(client, a2);
      if ( v11 && v11 <= 0xFFFFFFFFFFFFF000LL )
      {
        v12 = *(_QWORD *)(v11 + 8);
        if ( v12 && v12 <= 0xFFFFFFFFFFFFF000LL )
        {
          v13 = v11;
          bind_ops = synx_util_get_bind_ops((unsigned int)a4);
          if ( bind_ops && bind_ops < 0xFFFFFFFFFFFFF001LL )
          {
            v15 = (_DWORD **)bind_ops;
            mutex_lock(v12 + 72);
            if ( (*(_BYTE *)(v12 + 124) & 0x20) != 0 )
            {
              if ( (synx_debug & 1) != 0 )
                printk(&unk_280D1, &unk_29207, "synx_bind", 1947, *(_QWORD *)(v10 + 104), a2);
              v17 = -22;
            }
            else
            {
              v16 = *(_DWORD *)(v12 + 132);
              if ( v16 <= 7 )
              {
                if ( v16
                  && (a3 == *(_QWORD *)(v12 + 136) && *(_DWORD *)(v12 + 144) == (_DWORD)a4
                   || v16 != 1
                   && (a3 == *(_QWORD *)(v12 + 160) && *(_DWORD *)(v12 + 168) == (_DWORD)a4
                    || v16 != 2
                    && (a3 == *(_QWORD *)(v12 + 184) && *(_DWORD *)(v12 + 192) == (_DWORD)a4
                     || v16 != 3
                     && (a3 == *(_QWORD *)(v12 + 208) && *(_DWORD *)(v12 + 216) == (_DWORD)a4
                      || v16 != 4
                      && (a3 == *(_QWORD *)(v12 + 232) && *(_DWORD *)(v12 + 240) == (_DWORD)a4
                       || v16 != 5
                       && (a3 == *(_QWORD *)(v12 + 256) && *(_DWORD *)(v12 + 264) == (_DWORD)a4
                        || v16 != 6 && a3 == *(_QWORD *)(v12 + 280) && *(_DWORD *)(v12 + 288) == (_DWORD)a4)))))) )
                {
                  if ( (synx_debug & 1) != 0 )
                    printk(&unk_29162, &unk_29207, "synx_bind", 1968, *(_QWORD *)(v10 + 104), a3);
                  v17 = -114;
                }
                else
                {
                  v20 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 88);
                  v17 = -12;
                  if ( v20 )
                  {
                    while ( v20 <= 0xFFFFFFFFFFFFF000LL )
                    {
                      synx_util_get_object(v12);
                      *(_DWORD *)v20 = a2;
                      *(_QWORD *)(v20 + 16) = v12;
                      v21 = *(_DWORD *)(v12 + 132);
                      if ( v21 <= 8 )
                      {
                        v22 = v12 + 24LL * v21;
                        *(_QWORD *)(v22 + 136) = a3;
                        *(_QWORD *)(v22 + 144) = a4;
                        v23 = (_QWORD *)(v22 + 136);
                        if ( v21 != 8 )
                        {
                          v24 = *(_DWORD *)(v12 + 132);
                          v23[2] = v20;
                          *(_DWORD *)(v12 + 132) = v24 + 1;
                          mutex_unlock(v12 + 72);
                          v25 = *v15;
                          if ( *(*v15 - 1) != 2137877367 )
                            __break(0x8228u);
                          v26 = ((__int64 (__fastcall *)(_QWORD, unsigned __int64, _QWORD))v25)(
                                  synx_external_callback,
                                  v20,
                                  (unsigned int)a3);
                          if ( v26 )
                          {
                            v17 = v26;
                            if ( (synx_debug & 1) != 0 )
                              printk(&unk_28E64, &unk_29207, "synx_bind", 1999, *(_QWORD *)(v10 + 104), a3);
                            mutex_lock(v12 + 72);
                            v27 = *(_DWORD *)(v12 + 132);
                            *v23 = 0;
                            v23[1] = 0;
                            *(_DWORD *)(v12 + 132) = v27 - 1;
                            mutex_unlock(v12 + 72);
                            synx_util_put_object(v12);
                            kfree(v20);
                            v11 = v13;
                            goto LABEL_21;
                          }
                          synx_util_release_handle(v13);
                          if ( (synx_debug & 8) != 0 )
                            printk(&unk_25811, &unk_2A972, "synx_bind", 2013, *(_QWORD *)(v10 + 104), a3);
                          synx_put_client(v10);
                          return 0;
                        }
                      }
                      __break(0x5512u);
                      StatusReg = _ReadStatusReg(SP_EL0);
                      v29 = *(_QWORD *)(StatusReg + 80);
                      v30 = _kmalloc_cache_noprof;
                      *(_QWORD *)(StatusReg + 80) = &synx_bind__alloc_tag;
                      v20 = _kmalloc_cache_noprof(v30, 3520, 88);
                      *(_QWORD *)(StatusReg + 80) = v29;
                      v17 = -12;
                      if ( !v20 )
                        break;
                    }
                  }
                }
              }
              else
              {
                if ( (synx_debug & 1) != 0 )
                  printk(&unk_25FF3, &unk_29207, "synx_bind", 1955, *(_QWORD *)(v10 + 104), a2);
                v17 = -12;
              }
            }
            mutex_unlock(v12 + 72);
            v11 = v13;
          }
          else
          {
            if ( (synx_debug & 1) != 0 )
              printk(&unk_257D6, &unk_29207, "synx_bind", 1938, *(_QWORD *)(v10 + 104), (unsigned int)a4);
            v17 = -22;
            v11 = v13;
          }
          goto LABEL_21;
        }
      }
      else if ( !v11 )
      {
LABEL_20:
        v17 = 0;
LABEL_21:
        synx_util_release_handle(v11);
        synx_put_client(v10);
        return v17;
      }
      if ( (synx_debug & 1) != 0 )
      {
        v19 = v11;
        printk(&unk_29EEC, &unk_29207, "synx_bind", 1930, *(_QWORD *)(v10 + 104), a2);
        v11 = v19;
      }
      goto LABEL_20;
    }
  }
  if ( (synx_debug & 1) != 0 )
    printk(&unk_2B010, &unk_29207, "synx_bind", 1920, v8, v9);
  return (unsigned int)-22;
}
