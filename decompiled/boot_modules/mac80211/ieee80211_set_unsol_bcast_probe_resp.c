__int64 __fastcall ieee80211_set_unsol_bcast_probe_resp(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v7; // x0
  unsigned __int64 v8; // x22
  __int64 i; // x0
  size_t v10; // x2
  size_t v11; // x1
  const void *v12; // x1
  unsigned __int64 v13; // x21
  __int64 result; // x0
  unsigned __int64 StatusReg; // x23
  __int64 v16; // x24

  if ( *(_BYTE *)a1 != 1 )
    return 0;
  *(_DWORD *)(a3 + 356) = *(_DWORD *)(a1 + 4);
  v7 = *(_QWORD *)(a2 + 560);
  if ( v7 )
    kvfree_call_rcu(v7, *(_QWORD *)(a2 + 560));
  if ( *(_QWORD *)(a1 + 16) && *(_QWORD *)(a1 + 8) )
  {
    v8 = *(_QWORD *)(a1 + 8) + 24LL;
    for ( i = _kmalloc_noprof(v8, 3520); i; *(_QWORD *)(StatusReg + 80) = v16 )
    {
      if ( v8 < 0x10 || (v8 & 0xFFFFFFFFFFFFFFFCLL) == 0x10 )
      {
        __break(1u);
      }
      else
      {
        v10 = *(_QWORD *)(a1 + 8);
        if ( v8 >= 0x14 )
          v11 = v8 - 20;
        else
          v11 = 0;
        *(_DWORD *)(i + 16) = v10;
        if ( v11 >= v10 )
        {
          v12 = *(const void **)(a1 + 16);
          v13 = i;
          memcpy((void *)(i + 20), v12, v10);
          atomic_store(v13, (unsigned __int64 *)(a2 + 560));
          goto LABEL_16;
        }
      }
      _fortify_panic(17);
      StatusReg = _ReadStatusReg(SP_EL0);
      v16 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &ieee80211_set_unsol_bcast_probe_resp__alloc_tag;
      v8 = *(_QWORD *)(a1 + 8) + 24LL;
      i = _kmalloc_noprof(v8, 3520);
    }
    return 4294967284LL;
  }
  else
  {
    *(_QWORD *)(a2 + 560) = 0;
LABEL_16:
    result = 0;
    *a4 |= 0x80000000uLL;
  }
  return result;
}
