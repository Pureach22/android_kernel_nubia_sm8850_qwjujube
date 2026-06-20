__int64 __fastcall ce_send_entries_done_nolock_srng(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  unsigned int v3; // w19
  __int64 v4; // x8
  unsigned int v5; // w9
  unsigned int v6; // w10
  unsigned int v7; // w11
  unsigned int v8; // w12
  bool v9; // cf
  unsigned int v10; // w11
  __int64 v11; // x9

  v2 = *(_QWORD *)(a2 + 136);
  if ( (unsigned int)hal_srng_access_start_1(*(_QWORD *)(a1 + 2560)) )
  {
    return 0;
  }
  else
  {
    v4 = *(_QWORD *)(v2 + 80);
    v5 = *(_DWORD *)(v4 + 44);
    v6 = *(_DWORD *)(v4 + 36);
    v7 = (v5 + *(_DWORD *)(v4 + 124)) % v6;
    v8 = *(_DWORD *)(v4 + 136);
    v9 = v8 >= v7;
    v10 = v8 - v7;
    if ( v10 )
    {
      if ( v10 != 0 && v9 )
        v6 = 0;
      v3 = (v10 + v6) / v5;
    }
    else
    {
      v3 = 0;
    }
    v11 = *(_QWORD *)(v4 + 88);
    if ( (v11 & 1) != 0 )
    {
      *(_QWORD *)(v4 + 88) = v11 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v4 + 80);
    }
    else
    {
      raw_spin_unlock(v4 + 80);
    }
  }
  return v3;
}
