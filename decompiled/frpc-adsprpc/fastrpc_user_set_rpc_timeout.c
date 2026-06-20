__int64 __fastcall fastrpc_user_set_rpc_timeout(__int64 a1, _DWORD *a2)
{
  int v2; // w5
  int v6; // w4

  v2 = a2[1];
  if ( v2 )
  {
    v6 = 0;
  }
  else
  {
    v2 = a2[2];
    if ( v2 )
    {
      v6 = 1;
    }
    else
    {
      v2 = a2[3];
      if ( v2 )
      {
        v6 = 2;
      }
      else
      {
        v2 = a2[4];
        if ( v2 )
        {
          v6 = 3;
        }
        else
        {
          v2 = a2[5];
          if ( !v2 )
          {
            raw_spin_lock(a1 + 320);
            *(_DWORD *)(a1 + 632) = *a2;
            raw_spin_unlock(a1 + 320);
            return 0;
          }
          v6 = 4;
        }
      }
    }
  }
  dev_err(
    *(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL),
    "Error %d: %s: rsvd[%d] %u expected to be 0",
    -22,
    "fastrpc_user_set_rpc_timeout",
    v6,
    v2);
  return 4294967274LL;
}
