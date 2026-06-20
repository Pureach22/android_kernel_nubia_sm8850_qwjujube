__int64 __fastcall mhi_uci_poll(__int64 a1, void (**a2)(void))
{
  __int64 v2; // x22
  __int64 v3; // x19
  void (*v5)(void); // x8
  __int64 v6; // x21
  unsigned int v7; // w20

  v2 = *(_QWORD *)(a1 + 32);
  v3 = *(_QWORD *)(v2 + 32);
  if ( a2 )
  {
    v5 = *a2;
    if ( v2 != -208 && v5 )
    {
      v6 = a1;
      if ( *((_DWORD *)v5 - 1) != -442429149 )
        __break(0x8228u);
      v5();
      __dmb(0xBu);
      a1 = v6;
      v5 = *a2;
    }
    if ( v2 != -96 && v5 )
    {
      if ( *((_DWORD *)v5 - 1) != -442429149 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, void (**)(void)))v5)(a1, v2 + 96, a2);
      __dmb(0xBu);
    }
  }
  raw_spin_lock_bh(v2 + 232);
  if ( *(_BYTE *)(v2 + 340) != 1 )
  {
    v7 = 8;
    goto LABEL_24;
  }
  if ( *(_QWORD *)(v2 + 240) == v2 + 240 && !*(_QWORD *)(v2 + 256) )
  {
    v7 = 0;
    if ( !*(_DWORD *)(v2 + 344) )
      goto LABEL_24;
    goto LABEL_19;
  }
  if ( *(_QWORD *)(v2 + 352) && !*(_DWORD *)(v2 + 360) )
    ipc_log_string();
  v7 = 65;
  if ( *(_DWORD *)(v2 + 344) )
  {
LABEL_19:
    if ( *(_QWORD *)(v2 + 352) && !*(_DWORD *)(v2 + 360) )
      ipc_log_string();
    v7 |= 2u;
  }
LABEL_24:
  raw_spin_unlock_bh(v2 + 232);
  raw_spin_lock_bh(v2 + 120);
  if ( (*(_BYTE *)(v2 + 340) & 1) != 0 )
  {
    if ( (int)mhi_get_free_desc_count(v3, 1) >= 1 )
    {
      if ( *(_QWORD *)(v2 + 352) && !*(_DWORD *)(v2 + 360) )
        ipc_log_string();
      v7 |= 0x104u;
    }
  }
  else
  {
    v7 |= 8u;
  }
  raw_spin_unlock_bh(v2 + 120);
  if ( *(_QWORD *)(v2 + 352) && *(_DWORD *)(v2 + 360) <= 1u )
    ipc_log_string();
  return v7;
}
