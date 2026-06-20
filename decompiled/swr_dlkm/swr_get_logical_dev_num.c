__int64 __fastcall swr_get_logical_dev_num(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 (__fastcall *v6)(__int64, __int64, __int64); // x8
  unsigned int v7; // w20

  v3 = *(_QWORD *)(a1 + 32);
  if ( v3 )
  {
    mutex_lock(v3 + 936);
    v6 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v3 + 8456);
    if ( *((_DWORD *)v6 - 1) != -1743064948 )
      __break(0x8228u);
    v7 = v6(v3, a2, a3);
    mutex_unlock(v3 + 936);
  }
  else
  {
    printk(&unk_9A20, "swr_get_logical_dev_num");
    return (unsigned int)-22;
  }
  return v7;
}
