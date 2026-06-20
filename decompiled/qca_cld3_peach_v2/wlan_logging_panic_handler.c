__int64 wlan_logging_panic_handler()
{
  __int64 v0; // x9
  __int64 *v1; // x11
  _QWORD *v2; // x11
  __int64 v3; // x10
  __int64 v4; // x0
  __int64 *v5; // x1
  _QWORD *v6; // x10
  __int64 *v7; // x10
  __int64 **v8; // x12
  __int64 **v9; // x8
  __int64 v10; // x13
  __int64 **v11; // x1
  _QWORD *v12; // x8
  __int64 v13; // x12
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 *i; // x24
  __int64 **v18; // x8
  __int64 v19; // x9
  unsigned int v20; // w25
  __int64 v21; // x26
  __int64 v22; // x8
  unsigned int v23; // w0
  __int64 v24; // x28
  __int64 v25; // x2
  __int64 v26; // x3
  __int64 v27; // x0
  __int64 **v28; // x1
  __int64 v29; // x9
  _BYTE s[500]; // [xsp+Ch] [xbp-204h] BYREF
  __int64 v32; // [xsp+200h] [xbp-10h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = raw_spin_lock_irqsave((char *)&qword_826BF0 + 4);
  v1 = (__int64 *)off_826C08;
  if ( off_826C08 != (_UNKNOWN *)&off_826C08 )
  {
    v7 = &qword_826C18;
    v8 = (__int64 **)&off_826C08;
    do
    {
      v9 = (__int64 **)v1[1];
      if ( *v9 == v1 && (v10 = *v1, *(__int64 **)(*v1 + 8) == v1) )
      {
        *(_QWORD *)(v10 + 8) = v9;
        *v9 = (__int64 *)v10;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
      }
      *v1 = (__int64)v1;
      v1[1] = (__int64)v1;
      v11 = (__int64 **)v7[1];
      if ( v1 == v7 || v11 == (__int64 **)v1 || *v11 != v7 )
      {
        _list_add_valid_or_report(v1, v11);
      }
      else
      {
        v7[1] = (__int64)v1;
        *v1 = (__int64)v7;
        v1[1] = (__int64)v11;
        *v11 = v1;
      }
      v1 = *v8;
    }
    while ( *v8 != (__int64 *)v8 );
  }
  v2 = &unk_826000;
  if ( qword_826C70 )
  {
    v3 = *(unsigned int *)(qword_826C70 + 24);
    if ( (_DWORD)v3 )
    {
      *(_BYTE *)(qword_826C70 + v3 + 32) = 0;
      v4 = qword_826C70;
      v5 = (__int64 *)qword_826C20;
      if ( (__int64 *)qword_826C70 == &qword_826C18
        || qword_826C20 == qword_826C70
        || *(__int64 **)qword_826C20 != &qword_826C18 )
      {
        _list_add_valid_or_report(qword_826C70, qword_826C20);
      }
      else
      {
        qword_826C20 = qword_826C70;
        *(_QWORD *)qword_826C70 = &qword_826C18;
        *(_QWORD *)(v4 + 8) = v5;
        *v5 = v4;
      }
      v6 = (_QWORD *)qword_826BF8;
      if ( (__int64 *)qword_826BF8 == &qword_826BF8 )
      {
        v2[398] = 0;
      }
      else
      {
        v2[398] = qword_826BF8;
        v12 = (_QWORD *)v6[1];
        if ( (_QWORD *)*v12 == v6 && (v13 = *v6, *(_QWORD **)(*v6 + 8LL) == v6) )
        {
          *(_QWORD *)(v13 + 8) = v12;
          *v12 = v13;
        }
        else
        {
          _list_del_entry_valid_or_report(v6);
        }
        *v6 = v6;
        v6[1] = v6;
        *(_DWORD *)(v2[398] + 24LL) = 0;
      }
    }
  }
  raw_spin_unlock_irqrestore((char *)&qword_826BF0 + 4, v0);
  memset(s, 0, sizeof(s));
  printk(&unk_9BF0A8, v14, v15, v16);
  for ( i = (__int64 *)qword_826C18; (__int64 *)qword_826C18 != &qword_826C18; i = (__int64 *)qword_826C18 )
  {
    v18 = (__int64 **)i[1];
    if ( *v18 == i && (v19 = *i, *(__int64 **)(*i + 8) == i) )
    {
      *(_QWORD *)(v19 + 8) = v18;
      *v18 = (__int64 *)v19;
    }
    else
    {
      _list_del_entry_valid_or_report(i);
    }
    *i = (__int64)i;
    i[1] = (__int64)i;
    v20 = *((_DWORD *)i + 6);
    if ( v20 )
    {
      v21 = (__int64)(i + 4);
      do
      {
        v23 = qdf_str_copy_all_before_char(v21, v20, (__int64)s, 0x1F3u, 0xAu);
        if ( v23 > 0x1F3 )
          __break(0x5512u);
        v24 = v23;
        s[v23] = 0;
        if ( (unsigned int)__ratelimit(&panic_wifilog_ratelimit, "panic_wifilog_ratelimit_print") )
          printk(&unk_A3AED7, s, v25, v26);
        if ( *(_BYTE *)(v21 + v24) == 10 )
          v22 = (unsigned int)(v24 + 1);
        else
          v22 = (unsigned int)v24;
        v20 -= v22;
        v21 += v22;
      }
      while ( v20 );
    }
    v27 = raw_spin_lock_irqsave((char *)&qword_826BF0 + 4);
    v28 = (__int64 **)qword_826C00;
    v29 = v27;
    if ( i == &qword_826BF8 || (__int64 *)qword_826C00 == i || *(__int64 **)qword_826C00 != &qword_826BF8 )
    {
      _list_add_valid_or_report(i, qword_826C00);
    }
    else
    {
      qword_826C00 = (__int64)i;
      *i = (__int64)&qword_826BF8;
      i[1] = (__int64)v28;
      *v28 = i;
    }
    raw_spin_unlock_irqrestore((char *)&qword_826BF0 + 4, v29);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
