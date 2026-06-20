__int64 __fastcall usb_cser_disconnect(__int64 a1)
{
  _QWORD *v1; // x22
  _QWORD *v3; // x20
  __int64 v4; // x0
  _QWORD *v5; // x8
  __int64 v6; // x21
  _QWORD **v7; // x24
  _QWORD *i; // x9
  _QWORD *v9; // x8
  __int64 v10; // x10
  _QWORD *v11; // x23
  _QWORD *v12; // x9
  _QWORD **j; // x24
  _QWORD *v14; // x8
  __int64 v15; // x10
  _QWORD *v16; // x23
  _QWORD *v17; // x9
  _QWORD **k; // x23
  _QWORD *v19; // x8
  __int64 v20; // x10
  _QWORD *v21; // x22
  __int64 v22; // x2
  __int64 v23; // x3
  __int64 v24; // x0

  v1 = *(_QWORD **)(a1 + 1432);
  v3 = *(_QWORD **)(a1 + 1424);
  usb_ep_disable(v1);
  *v1 = 0;
  usb_ep_disable(v3);
  *v3 = 0;
  v4 = raw_spin_lock_irqsave(a1 + 1068);
  v5 = *(_QWORD **)(a1 + 1168);
  v6 = v4;
  if ( v5 )
  {
    kfree(*v5);
    usb_ep_free_request(v1, *(_QWORD *)(a1 + 1168));
  }
  *(_QWORD *)(a1 + 1184) = 0;
  v7 = (_QWORD **)(a1 + 1136);
  *(_QWORD *)(a1 + 1176) = 0;
  for ( i = *(_QWORD **)(a1 + 1136); i != v7; i = *v7 )
  {
    v9 = (_QWORD *)i[1];
    if ( (_QWORD *)*v9 == i && (v10 = *i, *(_QWORD **)(*i + 8LL) == i) )
    {
      *(_QWORD *)(v10 + 8) = v9;
      *v9 = v10;
    }
    else
    {
      _list_del_entry_valid_or_report(i);
    }
    v11 = i - 8;
    *i = i;
    i[1] = i;
    if ( i != qword_40 )
    {
      kfree(*v11);
      usb_ep_free_request(v1, v11);
    }
  }
  v12 = *(_QWORD **)(a1 + 1120);
  for ( j = (_QWORD **)(a1 + 1120); v12 != j; v12 = *j )
  {
    v14 = (_QWORD *)v12[1];
    if ( (_QWORD *)*v14 == v12 && (v15 = *v12, *(_QWORD **)(*v12 + 8LL) == v12) )
    {
      *(_QWORD *)(v15 + 8) = v14;
      *v14 = v15;
    }
    else
    {
      _list_del_entry_valid_or_report(v12);
    }
    v16 = v12 - 8;
    *v12 = v12;
    v12[1] = v12;
    if ( v12 != qword_40 )
    {
      kfree(*v16);
      usb_ep_free_request(v1, v16);
    }
  }
  v17 = *(_QWORD **)(a1 + 1152);
  for ( k = (_QWORD **)(a1 + 1152); v17 != k; v17 = *k )
  {
    v19 = (_QWORD *)v17[1];
    if ( (_QWORD *)*v19 == v17 && (v20 = *v17, *(_QWORD **)(*v17 + 8LL) == v17) )
    {
      *(_QWORD *)(v20 + 8) = v19;
      *v19 = v20;
    }
    else
    {
      _list_del_entry_valid_or_report(v17);
    }
    v21 = v17 - 8;
    *v17 = v17;
    v17[1] = v17;
    if ( v17 != qword_40 )
    {
      kfree(*v21);
      usb_ep_free_request(v3, v21);
    }
  }
  raw_spin_unlock_irqrestore(a1 + 1068, v6);
  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 1544) )
    {
      *(_DWORD *)(a1 + 1544) = 0;
      *(_BYTE *)(a1 + 1548) = 1;
      _wake_up(a1 + 1096, 3, 1, 0);
    }
  }
  else
  {
    printk(&unk_8F9B, "usb_cser_notify_modem", v22, v23);
  }
  v24 = raw_spin_lock_irqsave(a1 + 1068);
  *(_BYTE *)(a1 + 1560) = 0;
  *(_QWORD *)(a1 + 1568) = 0;
  *(_QWORD *)(a1 + 1576) = 0;
  *(_QWORD *)(a1 + 1584) = 0;
  return raw_spin_unlock_irqrestore(a1 + 1068, v24);
}
