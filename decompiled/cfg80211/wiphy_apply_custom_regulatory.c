unsigned __int64 __fastcall wiphy_apply_custom_regulatory(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 v5; // x1
  int v6; // w21
  __int64 v7; // x1
  __int64 v8; // x1
  __int64 v9; // x1
  __int64 v10; // x1
  __int64 v11; // x1
  unsigned __int64 result; // x0
  unsigned __int64 v13; // x20
  __int64 v14; // x0
  __int64 v15; // x0

  v2 = *(_DWORD *)(a1 + 104);
  if ( (v2 & 1) == 0 )
  {
    _warn_printk("wiphy should have REGULATORY_CUSTOM_REG\n");
    __break(0x800u);
    v2 = *(_DWORD *)(a1 + 104);
  }
  v5 = *(_QWORD *)(a1 + 328);
  *(_DWORD *)(a1 + 104) = v2 | 1;
  if ( v5 )
  {
    handle_band_custom(a1, v5, a2);
    v6 = 1;
    v7 = *(_QWORD *)(a1 + 336);
    if ( !v7 )
      goto LABEL_6;
    goto LABEL_5;
  }
  v6 = 0;
  v7 = *(_QWORD *)(a1 + 336);
  if ( v7 )
  {
LABEL_5:
    handle_band_custom(a1, v7, a2);
    ++v6;
  }
LABEL_6:
  v8 = *(_QWORD *)(a1 + 344);
  if ( v8 )
  {
    handle_band_custom(a1, v8, a2);
    ++v6;
  }
  v9 = *(_QWORD *)(a1 + 352);
  if ( v9 )
  {
    handle_band_custom(a1, v9, a2);
    ++v6;
  }
  v10 = *(_QWORD *)(a1 + 360);
  if ( v10 )
  {
    handle_band_custom(a1, v10, a2);
    v6 = 1;
  }
  v11 = *(_QWORD *)(a1 + 368);
  if ( v11 )
  {
    handle_band_custom(a1, v11, a2);
  }
  else if ( !v6 )
  {
    __break(0x800u);
  }
  result = reg_copy_regd(a2);
  if ( result <= 0xFFFFFFFFFFFFF000LL )
  {
    v13 = result;
    rtnl_lock(result);
    mutex_lock(a1);
    v14 = *(_QWORD *)(a1 + 384);
    atomic_store(v13, (unsigned __int64 *)(a1 + 384));
    if ( v14 )
      kvfree_call_rcu(v14, v14);
    v15 = mutex_unlock(a1);
    return rtnl_unlock(v15);
  }
  return result;
}
