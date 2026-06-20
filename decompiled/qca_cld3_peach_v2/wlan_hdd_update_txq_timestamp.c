__int64 __fastcall wlan_hdd_update_txq_timestamp(__int64 result)
{
  __int64 v1; // x19
  unsigned __int64 v2; // x21
  __int64 v3; // x22
  unsigned __int64 StatusReg; // x23
  __int64 v5; // x27
  __int64 v6; // x26
  int v7; // w8

  if ( *(_DWORD *)(result + 1096) )
  {
    v1 = result;
    v2 = 0;
    v3 = 328;
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      v5 = *(_QWORD *)(v1 + 24);
      v6 = v5 + v3;
      result = raw_spin_trylock(v5 + v3 - 8);
      if ( (_DWORD)result )
      {
        v7 = *(_DWORD *)(StatusReg + 40);
        *(_DWORD *)(v6 - 4) = v7;
        if ( v7 != -1 )
          *(_QWORD *)(v5 + v3) = jiffies;
        *(_DWORD *)(v6 - 4) = -1;
        result = raw_spin_unlock(v5 + v3 - 8);
      }
      ++v2;
      v3 += 384;
    }
    while ( v2 < *(unsigned int *)(v1 + 1096) );
  }
  return result;
}
