__int64 __fastcall ieee80211_iter_keys_rcu(
        __int64 result,
        __int64 a2,
        __int64 (__fastcall *a3)(__int64, __int64, __int64, __int64 *, __int64),
        __int64 a4)
{
  __int64 v6; // x21
  __int64 *v7; // x23
  __int64 *i; // x24
  __int64 v10; // x8
  __int64 v11; // x2
  _QWORD *v12; // x22
  _QWORD *j; // x23
  __int64 **k; // x25
  __int64 v15; // x8
  __int64 v16; // x2

  v6 = result;
  if ( a2 )
  {
    v7 = (__int64 *)(a2 - 3208);
    for ( i = *(__int64 **)(a2 - 3208); i != v7; i = (__int64 *)*i )
    {
      v10 = *(i - 1);
      if ( (!v10 || (*(_BYTE *)(v10 + 203) & 1) == 0) && (i[2] & 1) != 0 )
      {
        if ( v10 )
          v11 = v10 + 2688;
        else
          v11 = 0;
        if ( *((_DWORD *)a3 - 1) != 1883079838 )
          __break(0x8234u);
        result = a3(v6, a2, v11, i + 64, a4);
      }
    }
  }
  else
  {
    v12 = *(_QWORD **)(result + 4616);
    for ( j = (_QWORD *)(result + 4616); v12 != j; v12 = (_QWORD *)*v12 )
    {
      for ( k = (__int64 **)v12[189]; k != v12 + 189; k = (__int64 **)*k )
      {
        v15 = (__int64)*(k - 1);
        if ( (!v15 || (*(_BYTE *)(v15 + 203) & 1) == 0) && ((_BYTE)k[2] & 1) != 0 )
        {
          if ( v15 )
            v16 = v15 + 2688;
          else
            v16 = 0;
          if ( *((_DWORD *)a3 - 1) != 1883079838 )
            __break(0x8234u);
          result = a3(v6, (__int64)(v12 + 590), v16, (__int64 *)k + 64, a4);
        }
      }
    }
  }
  return result;
}
