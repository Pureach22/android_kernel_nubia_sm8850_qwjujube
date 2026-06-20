__int64 __fastcall ieee80211_regulatory_limit_wmm_params(__int64 result, unsigned __int16 *a2, unsigned int a3)
{
  __int64 v3; // x19
  unsigned __int64 lock; // x0
  __int64 v7; // x8
  int v8; // w8
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x8
  unsigned int v12; // w9
  unsigned __int16 *v13; // x8
  unsigned int v14; // w9
  unsigned int v15; // w9
  unsigned int v16; // w8

  if ( (*(_DWORD *)(result + 4720) & 0xFFFFFFFE) == 2 )
  {
    v3 = result;
    lock = _rcu_read_lock(result, a2);
    v7 = *(_QWORD *)(v3 + 5640);
    if ( v7 )
    {
      v8 = *(unsigned __int16 *)(*(_QWORD *)v7 + 4LL);
      if ( v8 )
      {
        lock = freq_reg_info(*(_QWORD *)(v3 + 16), (unsigned int)(1000 * v8));
        if ( lock )
        {
          if ( lock <= 0xFFFFFFFFFFFFF000LL && *(_BYTE *)(lock + 92) == 1 )
          {
            if ( a3 >= 5 )
            {
              __break(0x5512u);
              return ieee80211_set_wmm_default(lock, v9, v10);
            }
            v11 = 20;
            if ( *(_DWORD *)(v3 + 4720) == 3 )
              v11 = 52;
            v12 = a2[1];
            v13 = (unsigned __int16 *)(lock + v11 + 8LL * a3);
            if ( v12 <= *v13 )
              LOWORD(v12) = *v13;
            a2[1] = v12;
            v14 = a2[2];
            if ( v14 <= v13[1] )
              LOWORD(v14) = v13[1];
            a2[2] = v14;
            v15 = *((unsigned __int8 *)a2 + 6);
            if ( v15 <= *((unsigned __int8 *)v13 + 6) )
              LOBYTE(v15) = *((_BYTE *)v13 + 6);
            *((_BYTE *)a2 + 6) = v15;
            v16 = v13[2] >> 5;
            if ( *a2 < v16 )
              LOWORD(v16) = *a2;
            *a2 = v16;
          }
        }
      }
    }
    return _rcu_read_unlock(lock);
  }
  return result;
}
