__int64 __fastcall zte_ir_open(__int64 a1, __int64 a2)
{
  __int64 v4; // x1
  _UNKNOWN **v5; // x10
  _UNKNOWN **v6; // x21
  unsigned int v7; // w19

  mutex_lock(&device_list_lock);
  v5 = &device_list;
  while ( 1 )
  {
    v5 = (_UNKNOWN **)*v5;
    if ( v5 == &device_list )
      break;
    v6 = v5 - 10011;
    if ( *((_DWORD *)v5 - 20022) == *(_DWORD *)(a1 + 76) )
    {
      printk(&unk_6FAA, v4);
      *(_QWORD *)(a2 + 32) = v6;
      nonseekable_open(a1, a2);
      v7 = 0;
      goto LABEL_6;
    }
  }
  printk(&unk_6E89, *(_DWORD *)(a1 + 76) & 0xFFFFF);
  v7 = -6;
LABEL_6:
  mutex_unlock(&device_list_lock);
  return v7;
}
