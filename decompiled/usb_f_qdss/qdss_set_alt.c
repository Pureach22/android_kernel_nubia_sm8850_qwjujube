__int64 __fastcall qdss_set_alt(__int64 a1, int a2, int a3)
{
  __int64 v6; // x20
  __int64 v7; // x0
  int v8; // w0
  __int64 v9; // x8
  unsigned int v10; // w9
  unsigned int v17; // w11
  unsigned int v18; // w0
  __int64 v19; // x2
  _QWORD *v20; // x21
  char v21; // w8
  unsigned int v22; // w0
  int v23; // w8
  const char *v24; // x1
  __int64 v25; // x0
  unsigned int v27; // w20
  void *v28; // x8
  __int64 v29; // x8
  __int64 v30; // x0

  v6 = **(_QWORD **)(*(_QWORD *)(a1 + 48) + 48LL);
  ipc_log_string(qdss_ipc_log, "%s: qdss pointer = %pK\n", "qdss_set_alt", (const void *)a1);
  *(_QWORD *)(a1 + 264) = v6;
  if ( a3 )
  {
    v27 = 0;
    goto LABEL_42;
  }
  if ( *(_DWORD *)(v6 + 72) <= 2u )
  {
    printk(&unk_835D, "qdss_set_alt");
    goto LABEL_41;
  }
  if ( *(unsigned __int8 *)(a1 + 275) == a2 && (*(_BYTE *)(a1 + 460) & 1) == 0 )
  {
    if ( v6 )
    {
      v7 = *(_QWORD *)(v6 + 200);
      if ( v7 )
      {
        v8 = _pm_runtime_resume(v7, 5);
        if ( v8 < 0 && v8 != -115 )
        {
          v9 = *(_QWORD *)(v6 + 200);
          v10 = *(_DWORD *)(v9 + 480);
          do
          {
            if ( !v10 )
              break;
            _X13 = (unsigned int *)(v9 + 480);
            __asm { PRFM            #0x11, [X13] }
            while ( 1 )
            {
              v17 = __ldxr(_X13);
              if ( v17 != v10 )
                break;
              if ( !__stlxr(v10 - 1, _X13) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v17 == v10;
            v10 = v17;
          }
          while ( !_ZF );
        }
      }
    }
    v20 = (_QWORD *)(a1 + 240);
    v22 = config_ep_by_speed(v6, a1, *(_QWORD *)(a1 + 240));
    if ( v22 )
    {
      v28 = &unk_8436;
    }
    else
    {
      v22 = usb_ep_enable(*v20);
      if ( !v22 )
      {
        v21 = 1;
        goto LABEL_28;
      }
      v28 = &unk_8154;
    }
    v27 = v22;
    printk(v28, "qdss_set_alt");
    v29 = *(_QWORD *)(a1 + 264);
    if ( v29 )
    {
      v30 = *(_QWORD *)(v29 + 200);
      if ( v30 )
        _pm_runtime_idle(v30, 5);
    }
LABEL_42:
    printk(&unk_8190, "qdss_set_alt");
    qdss_eps_disable(a1);
    return v27;
  }
  if ( *(unsigned __int8 *)(a1 + 274) == a2 && *(_BYTE *)(a1 + 280) == 1 )
  {
    if ( !(unsigned int)config_ep_by_speed(v6, a1, *(_QWORD *)(a1 + 232)) )
    {
      v18 = usb_ep_enable(*(_QWORD *)(a1 + 232));
      if ( v18 )
      {
LABEL_43:
        v27 = v18;
        goto LABEL_42;
      }
      **(_QWORD **)(a1 + 232) = a1;
      v20 = (_QWORD *)(a1 + 224);
      v19 = *(_QWORD *)(a1 + 224);
      *(_BYTE *)(a1 + 460) |= 2u;
      if ( !(unsigned int)config_ep_by_speed(v6, a1, v19) )
      {
        v18 = usb_ep_enable(*v20);
        if ( !v18 )
        {
          v21 = 4;
LABEL_28:
          *(_QWORD *)*v20 = a1;
          *(_BYTE *)(a1 + 460) |= v21;
          goto LABEL_29;
        }
        goto LABEL_43;
      }
    }
LABEL_41:
    v27 = -22;
    goto LABEL_42;
  }
LABEL_29:
  v23 = *(unsigned __int8 *)(a1 + 460);
  if ( *(_BYTE *)(a1 + 280) == 1 )
  {
    if ( (~v23 & 7) == 0 )
    {
      v24 = "%s: usb_connected INTF enabled\n";
LABEL_34:
      v25 = qdss_ipc_log;
      *(_DWORD *)(a1 + 276) = 1;
      ipc_log_string(v25, v24, "qdss_set_alt");
    }
  }
  else if ( (v23 & 1) != 0 )
  {
    v24 = "%s: usb_connected INTF disabled\n";
    goto LABEL_34;
  }
  if ( *(_DWORD *)(a1 + 276) )
    queue_work_on(32, *(_QWORD *)(a1 + 464), a1 + 392);
  return 0;
}
