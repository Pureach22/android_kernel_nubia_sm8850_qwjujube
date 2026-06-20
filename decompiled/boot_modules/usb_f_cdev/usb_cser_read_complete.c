__int64 __fastcall usb_cser_read_complete(__int64 *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21
  __int64 v7; // x9
  int v8; // w8
  __int64 v9; // x8
  _QWORD *v10; // x0
  __int64 v11; // x2
  _QWORD *v12; // x1
  __int64 result; // x0
  _QWORD *v14; // x0
  __int64 v15; // x2
  _QWORD *v16; // x1

  v4 = *a1;
  if ( !*a1 )
    return printk(&unk_8F9B, "usb_cser_read_complete", a3, a4);
  v7 = raw_spin_lock_irqsave(v4 + 1068);
  if ( (*(_BYTE *)(v4 + 1561) & 1) != 0 )
  {
    v8 = *(_DWORD *)(a2 + 84);
    if ( v8 == -104 || v8 == -32 )
    {
      raw_spin_unlock_irqrestore(v4 + 1068, v7);
      result = usb_ep_queue(a1, a2, 3264);
      if ( !(_DWORD)result )
        return result;
      v7 = raw_spin_lock_irqsave(v4 + 1068);
    }
    else if ( !v8 )
    {
      v9 = *(unsigned int *)(a2 + 88);
      if ( (_DWORD)v9 )
      {
        v10 = (_QWORD *)(a2 + 64);
        v11 = v4 + 1136;
        v12 = *(_QWORD **)(v4 + 1144);
        *(_QWORD *)(v4 + 1568) += v9;
        if ( a2 + 64 == v4 + 1136 || v12 == v10 || *v12 != v11 )
        {
          _list_add_valid_or_report(v10, v12);
        }
        else
        {
          *(_QWORD *)(v4 + 1144) = v10;
          *(_QWORD *)(a2 + 64) = v11;
          *(_QWORD *)(a2 + 72) = v12;
          *v12 = v10;
        }
        raw_spin_unlock_irqrestore(v4 + 1068, v7);
        return _wake_up(v4 + 1096, 3, 1, 0);
      }
    }
  }
  v14 = (_QWORD *)(a2 + 64);
  v15 = v4 + 1120;
  v16 = *(_QWORD **)(v4 + 1128);
  if ( a2 + 64 == v4 + 1120 || v16 == v14 || *v16 != v15 )
  {
    _list_add_valid_or_report(v14, v16);
  }
  else
  {
    *(_QWORD *)(v4 + 1128) = v14;
    *(_QWORD *)(a2 + 64) = v15;
    *(_QWORD *)(a2 + 72) = v16;
    *v16 = v14;
  }
  return raw_spin_unlock_irqrestore(v4 + 1068, v7);
}
