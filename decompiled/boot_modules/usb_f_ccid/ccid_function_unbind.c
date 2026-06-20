__int64 __fastcall ccid_function_unbind(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x20
  __int64 v4; // x21
  _QWORD *v5; // x20
  __int64 v6; // x21
  __int64 v7; // x0
  _QWORD *v8; // x10
  __int64 v9; // x9
  _QWORD *v10; // x8
  __int64 v11; // x11
  _QWORD *v12; // x20
  __int64 v13; // x21
  __int64 v14; // x0

  v2 = *(_QWORD **)(a2 + 264);
  if ( v2 )
  {
    v4 = *(_QWORD *)(a2 + 240);
    kfree(*v2);
    usb_ep_free_request(v4, v2);
  }
  if ( !*(_DWORD *)(a2 + 472) )
  {
    v5 = *(_QWORD **)(a2 + 528);
    if ( v5 )
    {
      v6 = *(_QWORD *)(a2 + 256);
      kfree(*v5);
      usb_ep_free_request(v6, v5);
    }
  }
  v7 = raw_spin_lock_irqsave(a2 + 228);
  v8 = *(_QWORD **)(a2 + 544);
  v9 = v7;
  if ( v8 == (_QWORD *)(a2 + 544) )
  {
LABEL_14:
    raw_spin_unlock_irqrestore(a2 + 228, v9);
  }
  else
  {
    while ( 1 )
    {
      v10 = (_QWORD *)v8[1];
      if ( (_QWORD *)*v10 == v8 && (v11 = *v8, *(_QWORD **)(*v8 + 8LL) == v8) )
      {
        *(_QWORD *)(v11 + 8) = v10;
        *v10 = v11;
      }
      else
      {
        _list_del_entry_valid_or_report(v8);
      }
      *v8 = 0xDEAD000000000100LL;
      v8[1] = 0xDEAD000000000122LL;
      v12 = v8 - 8;
      raw_spin_unlock_irqrestore(a2 + 228, v9);
      if ( !v12 )
        break;
      v13 = *(_QWORD *)(a2 + 248);
      kfree(*v12);
      usb_ep_free_request(v13, v12);
      v14 = raw_spin_lock_irqsave(a2 + 228);
      v8 = *(_QWORD **)(a2 + 544);
      v9 = v14;
      if ( v8 == (_QWORD *)(a2 + 544) )
        goto LABEL_14;
    }
  }
  return usb_free_all_descriptors(a2);
}
