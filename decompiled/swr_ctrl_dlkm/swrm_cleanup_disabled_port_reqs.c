__int64 __fastcall swrm_cleanup_disabled_port_reqs(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x22
  int v5; // w8
  __int64 **v6; // x25
  __int64 **v7; // x26
  int v8; // w10
  int v9; // w8
  __int64 *v10; // x9
  __int64 **v11; // x8

  if ( result && (v1 = *(_QWORD *)(result + 152), v2 = result, v1) )
  {
    v3 = 0;
    v4 = v1 + 9152;
    do
    {
      v6 = (__int64 **)(v4 + 40 * v3);
      v7 = (__int64 **)*v6;
      while ( v7 != v6 )
      {
        v8 = *((unsigned __int8 *)v7 + 23);
        v9 = *((unsigned __int8 *)v7 + 24);
        v10 = (__int64 *)v7;
        v7 = (__int64 **)*v7;
        if ( v8 != v9 )
        {
          *((_BYTE *)v10 + 23) = v9;
          if ( !v9 )
          {
            v11 = (__int64 **)v10[1];
            if ( *v11 == v10 && v7[1] == v10 )
            {
              v7[1] = (__int64 *)v11;
              *v11 = (__int64 *)v7;
            }
            else
            {
              _list_del_entry_valid_or_report(v10);
            }
            *v10 = 0xDEAD000000000100LL;
            v10[1] = 0xDEAD000000000122LL;
            result = kfree(v10 - 1);
          }
        }
      }
      v5 = *((unsigned __int8 *)v6 + 18);
      *((_BYTE *)v6 + 17) = v5;
      if ( !v5 )
      {
        *((_BYTE *)v6 + 16) = 0;
        *(_WORD *)(v2 + 8504) &= ~(_WORD)v3;
      }
      ++v3;
    }
    while ( v3 != 13 );
  }
  else
  {
    result = __ratelimit(&swrm_cleanup_disabled_port_reqs__rs, "swrm_cleanup_disabled_port_reqs");
    if ( (_DWORD)result )
      return printk(&unk_10D41, "swrm_cleanup_disabled_port_reqs");
  }
  return result;
}
