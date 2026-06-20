__int64 __fastcall usb_cser_set_alt(__int64 a1)
{
  _QWORD *v1; // x2
  _QWORD *v3; // x21
  int v4; // w0
  __int64 v5; // x3
  __int64 v6; // x20
  _QWORD *v7; // x2
  __int64 v8; // x0
  unsigned int v9; // w0
  _QWORD *v10; // x2
  unsigned int v11; // w0
  _QWORD *v12; // x2
  __int64 v13; // x0
  __int64 v14; // x22
  __int64 v15; // x24
  _QWORD *v16; // x23
  int v17; // w25
  _QWORD *v18; // x0
  __int64 v19; // x2
  __int64 v20; // x3
  _QWORD *v21; // x8
  _QWORD *v22; // x1
  int v23; // w0
  __int64 v25; // x25
  _QWORD *v26; // x24
  int v27; // w26
  _QWORD *v28; // x0
  _QWORD *v29; // x8
  _QWORD *v30; // x1
  __int64 v31; // x1
  __int64 v32; // x2
  __int64 v33; // x3
  __int64 v34; // x8
  unsigned int v35; // w19
  void *v36; // x20
  __int64 v37; // x24
  _QWORD *v38; // x9
  _QWORD *v39; // x8
  __int64 v40; // x10
  _QWORD *v41; // x25

  v1 = *(_QWORD **)(a1 + 240);
  v3 = *(_QWORD **)(*(_QWORD *)(a1 + 48) + 48LL);
  if ( *v1 )
  {
    usb_ep_disable(*(_QWORD *)(a1 + 240));
    v1 = *(_QWORD **)(a1 + 240);
  }
  if ( !v1[3] )
  {
    v23 = config_ep_by_speed(*v3, a1);
    v1 = *(_QWORD **)(a1 + 240);
    if ( v23 )
    {
      v1[3] = 0;
      return 4294967274LL;
    }
  }
  v4 = usb_ep_enable(v1);
  if ( v4 )
  {
    v34 = *(_QWORD *)(a1 + 240);
    v35 = v4;
    dev_err(*v3 + 104LL, "can't enable %s, result %d\n", *(const char **)(v34 + 8), v4);
    return v35;
  }
  v6 = a1 - 1200;
  **(_QWORD **)(a1 + 240) = a1 - 1200;
  v7 = *(_QWORD **)(a1 + 224);
  if ( *v7 )
  {
    usb_cser_disconnect(a1 - 1200);
    v7 = *(_QWORD **)(a1 + 224);
  }
  if ( (!v7[3] || !*(_QWORD *)(*(_QWORD *)(a1 + 232) + 24LL))
    && ((unsigned int)config_ep_by_speed(*v3, a1) || (unsigned int)config_ep_by_speed(*v3, a1)) )
  {
    *(_QWORD *)(*(_QWORD *)(a1 + 224) + 24LL) = 0;
    *(_QWORD *)(*(_QWORD *)(a1 + 232) + 24LL) = 0;
    return 4294967274LL;
  }
  if ( a1 == 1200 )
  {
    printk(&unk_90C6, "usb_cser_connect", v7, v5);
  }
  else
  {
    v8 = *(_QWORD *)(a1 + 224);
    *(_QWORD *)(a1 + 336) = usb_cser_notify_modem;
    v9 = usb_ep_enable(v8);
    v10 = *(_QWORD **)(a1 + 224);
    if ( v9 )
    {
      printk(&unk_8EFA, "usb_cser_connect", v10, v9);
    }
    else
    {
      *v10 = v6;
      v11 = usb_ep_enable(*(_QWORD *)(a1 + 232));
      v12 = *(_QWORD **)(a1 + 232);
      if ( v11 )
      {
        printk(&unk_8D0C, "usb_cser_connect", v12, v11);
        **(_QWORD **)(a1 + 224) = 0;
        return 0;
      }
      *v12 = v6;
      v13 = raw_spin_lock_irqsave(a1 - 132);
      *(_WORD *)(a1 + 263) = 0;
      *(_BYTE *)(a1 + 360) = 1;
      raw_spin_unlock_irqrestore(a1 - 132, v13);
      v14 = raw_spin_lock_irqsave(a1 - 132);
      if ( *(_BYTE *)(a1 + 360) == 1 )
      {
        v15 = *(_QWORD *)(a1 + 232);
        v16 = (_QWORD *)(a1 - 80);
        v17 = 8;
        *(_QWORD *)(a1 - 24) = 0;
        *(_QWORD *)(a1 - 16) = 0;
        *(_QWORD *)(a1 - 32) = 0;
        while ( 1 )
        {
          v18 = (_QWORD *)usb_cser_alloc_req(v15, 2048, 2080);
          if ( !v18 )
            break;
          v18[6] = usb_cser_read_complete;
          v21 = v18 + 8;
          v22 = *(_QWORD **)(a1 - 72);
          if ( v18 + 8 == v16 || v22 == v21 || (_QWORD *)*v22 != v16 )
          {
            _list_add_valid_or_report(v18 + 8, v22);
            if ( !--v17 )
              goto LABEL_29;
          }
          else
          {
            *(_QWORD *)(a1 - 72) = v21;
            v18[8] = v16;
            v18[9] = v22;
            *v22 = v21;
            if ( !--v17 )
              goto LABEL_29;
          }
        }
        if ( (_QWORD *)*v16 == v16 )
        {
          v36 = &unk_9112;
          goto LABEL_45;
        }
LABEL_29:
        v25 = *(_QWORD *)(a1 + 224);
        v26 = (_QWORD *)(a1 - 48);
        v27 = 8;
        while ( 1 )
        {
          v28 = (_QWORD *)usb_cser_alloc_req(v25, 2048, 2080);
          if ( !v28 )
            break;
          v28[6] = usb_cser_write_complete;
          v29 = v28 + 8;
          v30 = *(_QWORD **)(a1 - 40);
          if ( v28 + 8 == v26 || v30 == v29 || (_QWORD *)*v30 != v26 )
          {
            _list_add_valid_or_report(v28 + 8, v30);
            if ( !--v27 )
              goto LABEL_39;
          }
          else
          {
            *(_QWORD *)(a1 - 40) = v29;
            v28[8] = v26;
            v28[9] = v30;
            *v30 = v29;
            if ( !--v27 )
              goto LABEL_39;
          }
        }
        if ( (_QWORD *)*v26 != v26 )
        {
LABEL_39:
          raw_spin_unlock_irqrestore(a1 - 132, v14);
          usb_cser_start_rx(a1 - 1200, v31, v32, v33);
          goto LABEL_47;
        }
        v37 = *(_QWORD *)(a1 + 232);
        v38 = *(_QWORD **)(a1 - 80);
        v36 = &unk_927C;
        while ( v38 != v16 )
        {
          v39 = (_QWORD *)v38[1];
          if ( (_QWORD *)*v39 == v38 && (v40 = *v38, *(_QWORD **)(*v38 + 8LL) == v38) )
          {
            *(_QWORD *)(v40 + 8) = v39;
            *v39 = v40;
          }
          else
          {
            _list_del_entry_valid_or_report(v38);
          }
          v41 = v38 - 8;
          *v38 = v38;
          v38[1] = v38;
          if ( v38 != qword_40 )
          {
            kfree(*v41);
            usb_ep_free_request(v37, v41);
          }
          v38 = (_QWORD *)*v16;
        }
LABEL_45:
        printk(v36, "usb_cser_start_io", v19, v20);
      }
      raw_spin_unlock_irqrestore(a1 - 132, v14);
LABEL_47:
      _wake_up(a1 - 128, 3, 1, 0);
    }
  }
  return 0;
}
