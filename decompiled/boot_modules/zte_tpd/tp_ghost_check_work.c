__int64 tp_ghost_check_work()
{
  __int64 v0; // x19
  __int64 v1; // x1
  __int64 v2; // x2
  __int64 result; // x0
  __int64 v4; // x1
  __int64 v5; // x2
  int v6; // w8
  void (__fastcall *v7)(_QWORD); // x9
  __int64 v8; // x2

  v0 = tpd_cdev;
  if ( (tp_ghost_check() & 1) != 0 )
  {
    printk(&unk_3B632, v1, v2);
    v6 = *(_DWORD *)(v0 + 1192);
    if ( v6 > 2 )
    {
      printk(&unk_3698B, v4, v5);
    }
    else
    {
      v7 = *(void (__fastcall **)(_QWORD))(v0 + 3640);
      if ( v7 )
      {
        if ( *((_DWORD *)v7 - 1) != 1945898361 )
          __break(0x8229u);
        v7(v0);
        printk(&unk_38629, (unsigned int)(*(_DWORD *)(v0 + 1192) + 1), v8);
        v6 = *(_DWORD *)(v0 + 1192);
      }
      *(_DWORD *)(v0 + 1192) = v6 + 1;
    }
  }
  result = ghost_check_reset();
  *(_BYTE *)(v0 + 1160) = 0;
  return result;
}
