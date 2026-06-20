__int64 __fastcall usb_cser_write_complete(__int64 *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x20
  __int64 v6; // x9
  _QWORD *v7; // x0
  __int64 v8; // x2
  _QWORD *v9; // x1

  v4 = *a1;
  if ( !*a1 )
    return printk(&unk_8F9B, "usb_cser_write_complete", a3, a4);
  v6 = raw_spin_lock_irqsave(v4 + 1068);
  v7 = (_QWORD *)(a2 + 64);
  v8 = v4 + 1152;
  v9 = *(_QWORD **)(v4 + 1160);
  *(_QWORD *)(v4 + 1576) += *(unsigned int *)(a2 + 88);
  if ( a2 + 64 == v4 + 1152 || v9 == v7 || *v9 != v8 )
  {
    _list_add_valid_or_report(v7, v9);
  }
  else
  {
    *(_QWORD *)(v4 + 1160) = v7;
    *(_QWORD *)(a2 + 64) = v8;
    *(_QWORD *)(a2 + 72) = v9;
    *v9 = v7;
  }
  return raw_spin_unlock_irqrestore(v4 + 1068, v6);
}
