__int64 __fastcall swr_device_wakeup_vote(__int64 a1)
{
  __int64 v1; // x19
  void (__fastcall *v2)(_QWORD); // x8
  unsigned int v3; // w20

  v1 = *(_QWORD *)(a1 + 32);
  if ( v1 )
  {
    mutex_lock(v1 + 936);
    v2 = *(void (__fastcall **)(_QWORD))(v1 + 8488);
    if ( v2 )
    {
      if ( *((_DWORD *)v2 - 1) != 476918287 )
        __break(0x8228u);
      v2(v1);
      v3 = 0;
    }
    else
    {
      v3 = -22;
    }
    mutex_unlock(v1 + 936);
  }
  else
  {
    printk(&unk_9A20, "swr_device_wakeup_vote");
    return (unsigned int)-22;
  }
  return v3;
}
