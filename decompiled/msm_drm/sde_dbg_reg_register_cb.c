__int64 __fastcall sde_dbg_reg_register_cb(const char *a1, __int64 a2, __int64 a3)
{
  __int64 *v6; // x21
  size_t v7; // x0
  unsigned __int64 v8; // x2
  __int64 v9; // x2
  unsigned __int64 StatusReg; // x23
  __int64 v12; // x24
  __int64 (__fastcall *v13)(_QWORD, _QWORD, _QWORD, _QWORD); // x0

  if ( !a1 || !*a1 )
  {
    printk(&unk_23C5E8, "sde_dbg_reg_register_cb");
    return 4294967274LL;
  }
  v6 = (__int64 *)_kmalloc_cache_noprof(drm_dp_dpcd_read, 3520, 200);
  if ( !v6 )
    return 4294967284LL;
  while ( 1 )
  {
    v7 = strnlen(a1, 0x50u);
    if ( v7 != -1 )
      break;
    _fortify_panic(2, -1, 0);
LABEL_16:
    _fortify_panic(7, 80, v8);
    StatusReg = _ReadStatusReg(SP_EL0);
    v12 = *(_QWORD *)(StatusReg + 80);
    v13 = drm_dp_dpcd_read;
    *(_QWORD *)(StatusReg + 80) = &sde_dbg_reg_register_cb__alloc_tag;
    v6 = (__int64 *)_kmalloc_cache_noprof(v13, 3520, 200);
    *(_QWORD *)(StatusReg + 80) = v12;
    if ( !v6 )
      return 4294967284LL;
  }
  if ( v7 == 80 )
    v8 = 80;
  else
    v8 = v7 + 1;
  if ( v8 >= 0x51 )
    goto LABEL_16;
  sized_strscpy(v6 + 4, a1);
  v6[14] = 0;
  v6[17] = 92;
  v6[18] = 0;
  v6[16] = 0;
  v6[21] = 0;
  v6[22] = a2;
  v6[23] = a3;
  v6[2] = (__int64)(v6 + 2);
  v6[3] = (__int64)(v6 + 2);
  v9 = qword_2942A8;
  if ( *(__int64 **)(qword_2942A8 + 8) != &qword_2942A8 || v6 == &qword_2942A8 || (__int64 *)qword_2942A8 == v6 )
  {
    _list_add_valid_or_report(v6, &qword_2942A8);
    return 0;
  }
  else
  {
    *(_QWORD *)(qword_2942A8 + 8) = v6;
    *v6 = v9;
    v6[1] = (__int64)&qword_2942A8;
    qword_2942A8 = (__int64)v6;
    return 0;
  }
}
