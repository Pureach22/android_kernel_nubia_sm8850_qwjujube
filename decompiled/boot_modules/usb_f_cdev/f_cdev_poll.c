__int64 __fastcall f_cdev_poll(__int64 a1, void (**a2)(void), __int64 a3, __int64 a4)
{
  __int64 v4; // x20
  void (*v5)(void); // x8
  __int64 v6; // x1
  int v7; // w8
  unsigned int v8; // w19

  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 && *(_BYTE *)(v4 + 1560) == 1 )
  {
    if ( a2 )
    {
      v5 = *a2;
      if ( *a2 )
      {
        if ( *((_DWORD *)v5 - 1) != -442429149 )
          __break(0x8228u);
        v5();
        __dmb(0xBu);
      }
    }
    v6 = raw_spin_lock_irqsave(v4 + 1068);
    if ( *(_QWORD *)(v4 + 1136) == v4 + 1136 )
      v7 = 0;
    else
      v7 = 65;
    if ( *(_BYTE *)(v4 + 1548) )
      v8 = v7 | 2;
    else
      v8 = v7;
    raw_spin_unlock_irqrestore(v4 + 1068, v6);
  }
  else
  {
    printk(&unk_8DB8, "f_cdev_poll", a3, a4);
    return 8;
  }
  return v8;
}
