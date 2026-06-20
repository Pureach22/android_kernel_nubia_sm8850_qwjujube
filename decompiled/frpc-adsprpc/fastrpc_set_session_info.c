__int64 __fastcall fastrpc_set_session_info(__int64 a1, __int64 a2)
{
  int v4; // w2
  __int64 v5; // x8
  unsigned int v6; // w2
  unsigned int v7; // w3
  __int64 result; // x0

  raw_spin_lock(a1 + 320);
  if ( *(_BYTE *)(a1 + 626) == 1 )
  {
    raw_spin_unlock(a1 + 320);
    dev_err(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL), "Set session info invoked multiple times\n");
    return 4294967243LL;
  }
  else
  {
    *(_BYTE *)(a1 + 626) = 1;
    raw_spin_unlock(a1 + 320);
    v4 = *(_DWORD *)(a2 + 8);
    v5 = *(_QWORD *)(a1 + 128);
    if ( (unsigned int)(v4 - 11) <= 0xFFFFFFF5 )
    {
      dev_err(*(_QWORD *)(v5 + 168), "Invalid PD type %d, range is %d - %d\n", v4, 1, 10);
      return 4294967243LL;
    }
    else
    {
      if ( *(_BYTE *)(v5 + 64132) == 1 )
      {
        *(_DWORD *)(a1 + 268) = v4;
        v4 = *(_DWORD *)(a2 + 8);
      }
      if ( v4 == 3 )
        *(_BYTE *)(a1 + 308) = 1;
      v6 = *(_DWORD *)(a2 + 4);
      v7 = *(_DWORD *)(v5 + 64128);
      if ( v6 >= v7 )
      {
        dev_err(*(_QWORD *)(v5 + 168), "Session ID %u cannot be beyond %u\n", v6, v7);
        return 4294967243LL;
      }
      else
      {
        result = 0;
        *(_DWORD *)(a1 + 284) = v6;
        *(_BYTE *)(a1 + 624) = 1;
      }
    }
  }
  return result;
}
