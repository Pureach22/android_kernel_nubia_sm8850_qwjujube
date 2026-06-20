__int64 __fastcall usb_cser_start_rx(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  __int64 v6; // x23
  _QWORD *v7; // x21
  int v8; // w24
  _QWORD *v9; // x22
  _QWORD *v10; // x8
  __int64 v11; // x9
  _QWORD *v13; // x2

  if ( !a1 )
    return printk(&unk_8F9B, "usb_cser_start_rx", a3, a4);
  v5 = raw_spin_lock_irqsave(a1 + 1068);
  if ( *(_BYTE *)(a1 + 1560) == 1 && (*(_BYTE *)(a1 + 1561) & 1) != 0 )
  {
    v6 = *(_QWORD *)(a1 + 1432);
    v7 = (_QWORD *)(a1 + 1120);
    while ( 1 )
    {
      v9 = (_QWORD *)*v7;
      if ( (_QWORD *)*v7 == v7 )
        break;
      v10 = (_QWORD *)v9[1];
      if ( (_QWORD *)*v10 == v9 && (v11 = *v9, *(_QWORD **)(*v9 + 8LL) == v9) )
      {
        *(_QWORD *)(v11 + 8) = v10;
        *v10 = v11;
      }
      else
      {
        _list_del_entry_valid_or_report(*v7);
      }
      *v9 = v9;
      v9[1] = v9;
      *((_DWORD *)v9 - 14) = 2048;
      *(v9 - 2) = usb_cser_read_complete;
      raw_spin_unlock_irqrestore(a1 + 1068, v5);
      v8 = usb_ep_queue(v6, v9 - 8, 3264);
      v5 = raw_spin_lock_irqsave(a1 + 1068);
      if ( v8 )
      {
        printk(&unk_932B, "usb_cser_start_rx", *(unsigned int *)(a1 + 1048), a1);
        v13 = *(_QWORD **)(a1 + 1120);
        if ( (_QWORD *)v13[1] != v7 || v13 == v9 )
        {
          _list_add_valid_or_report(v9, a1 + 1120);
        }
        else
        {
          v13[1] = v9;
          *v9 = v13;
          v9[1] = v7;
          *v7 = v9;
        }
        return raw_spin_unlock_irqrestore(a1 + 1068, v5);
      }
    }
  }
  return raw_spin_unlock_irqrestore(a1 + 1068, v5);
}
