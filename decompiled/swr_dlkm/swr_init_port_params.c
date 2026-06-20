__int64 __fastcall swr_init_port_params(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x19
  _DWORD *v7; // x8
  __int64 v8; // x1
  unsigned int v9; // w20

  v3 = *(_QWORD *)(a1 + 32);
  if ( v3 )
  {
    mutex_lock(v3 + 936);
    v7 = *(_DWORD **)(v3 + 8464);
    v8 = *(unsigned __int8 *)(a1 + 64);
    if ( *(v7 - 1) != -1610954608 )
      __break(0x8228u);
    v9 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))v7)(v3, v8, a2, a3);
    mutex_unlock(v3 + 936);
  }
  else
  {
    printk(&unk_9A20, "swr_init_port_params");
    return (unsigned int)-22;
  }
  return v9;
}
