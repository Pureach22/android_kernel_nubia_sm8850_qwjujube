__int64 __fastcall regulatory_hint_country_ie(__int64 result, __int64 a2, char *a3, unsigned __int8 a4)
{
  __int64 v5; // x19
  int v6; // w8
  char v7; // w22
  __int64 v8; // x21
  char v9; // w23
  int v10; // w20
  __int64 v11; // x0
  int v12; // w0
  __int64 v13; // x0

  if ( a4 >= 6u && (a4 & 1) == 0 )
  {
    v5 = result;
    result = _kmalloc_cache_noprof(timer_delete, 3520, 64);
    if ( result )
    {
      v6 = (unsigned __int8)a3[2];
      v7 = *a3;
      v8 = result;
      v9 = a3[1];
      if ( v6 == 73 )
        v10 = 1;
      else
        v10 = 2 * (v6 == 79);
      _rcu_read_lock(result);
      if ( last_request && (*((_DWORD *)last_request + 5) != 3 || *((_DWORD *)last_request + 4) == -1) )
      {
        v12 = ((__int64 (__fastcall *)(__int64))get_wiphy_idx)(v5);
        *(_BYTE *)(v8 + 28) = v7;
        *(_DWORD *)(v8 + 16) = v12;
        *(_DWORD *)(v8 + 20) = 3;
        *(_BYTE *)(v8 + 29) = v9;
        *(_DWORD *)(v8 + 40) = v10;
        queue_regulatory_request(v8);
        v11 = 0;
      }
      else
      {
        v11 = v8;
      }
      v13 = kfree(v11);
      return _rcu_read_unlock(v13);
    }
  }
  return result;
}
