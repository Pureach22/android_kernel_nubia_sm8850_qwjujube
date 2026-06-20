__int64 __fastcall rmnet_wlan_get_tuples(__int64 *a1, __int64 a2, unsigned int *a3)
{
  __int64 v6; // x0
  __int64 v7; // x20
  __int64 v8; // x0
  __int64 v9; // x21
  __int64 v10; // x22
  __int64 v11; // x23
  _WORD *v12; // x22
  __int64 i; // x23
  _QWORD *j; // x25
  __int64 v15; // x26
  __int64 v16; // x27
  _WORD *v17; // x26
  unsigned __int64 v18; // x8

  mutex_lock(&rmnet_wlan_tuple_mutex);
  v6 = _alloc_skb(
         (((((12 * rmnet_wlan_tuple_count + 7) & 0xFFFFFFFC) + 7) & 0xFFFFFFFC) + 19) & 0xFFFFFFFC,
         3264,
         0,
         0xFFFFFFFFLL);
  if ( !v6 )
    return 4294967284LL;
  v7 = v6;
  v8 = genlmsg_put(v6, a3[1], *a3, a2, 0, 14);
  if ( v8
    && (v9 = v8,
        v10 = *(_QWORD *)(v7 + 216),
        v11 = *(unsigned int *)(v7 + 208),
        (nla_put(v7, 32769, 0, 0) & 0x80000000) == 0)
    && (v12 = (_WORD *)(v10 + v11)) != nullptr )
  {
    for ( i = 0; i != 16; ++i )
    {
      for ( j = (_QWORD *)rmnet_wlan_tuple_hash[i]; j; j = (_QWORD *)*j )
      {
        v15 = *(_QWORD *)(v7 + 216);
        v16 = *(unsigned int *)(v7 + 208);
        if ( (nla_put(v7, 32769, 0, 0) & 0x80000000) == 0 )
        {
          v17 = (_WORD *)(v15 + v16);
          if ( v17 )
          {
            if ( (unsigned int)nla_put(v7, 1, 8, j + 4) )
            {
              v18 = *(_QWORD *)(v7 + 224);
              if ( v18 > (unsigned __int64)v17 )
              {
                __break(0x800u);
                v18 = *(_QWORD *)(v7 + 224);
              }
              skb_trim(v7, (unsigned int)((_DWORD)v17 - v18));
            }
            else
            {
              *v17 = *(_WORD *)(v7 + 216) + *(_DWORD *)(v7 + 208) - (_WORD)v17;
            }
          }
        }
      }
    }
    *v12 = *(_DWORD *)(v7 + 216) + *(_DWORD *)(v7 + 208) - (_WORD)v12;
    *(_DWORD *)(v9 - 20) = *(_DWORD *)(v7 + 216) + *(_DWORD *)(v7 + 208) - (v9 - 20);
    *a1 = v7;
    mutex_unlock(&rmnet_wlan_tuple_mutex);
    return 0;
  }
  else
  {
    kfree(v7);
    return 4294967274LL;
  }
}
