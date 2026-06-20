__int64 __fastcall send_signal_to_subsystem(int a1, int a2)
{
  _QWORD *v2; // x8
  __int64 v3; // x1
  _QWORD *v4; // x2
  void *v6; // x0

  v2 = (_QWORD *)pwr_data;
  *(_DWORD *)(pwr_data + 292) = a2;
  if ( a1 != 1 )
  {
    if ( v2[27] )
    {
      v3 = v2[37];
      v4 = v2 + 44;
      return queue_work_on(32, v3, v4);
    }
    v6 = &unk_1378C;
    return printk(v6, "send_signal_to_subsystem");
  }
  if ( !v2[26] )
  {
    v6 = &unk_1231E;
    return printk(v6, "send_signal_to_subsystem");
  }
  v3 = v2[37];
  v4 = v2 + 40;
  return queue_work_on(32, v3, v4);
}
