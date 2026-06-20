__int64 __fastcall sde_dbg_reg_register_base(const char *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 *v10; // x22
  size_t v11; // x0
  unsigned __int64 v12; // x2
  __int64 v13; // x2
  unsigned __int64 StatusReg; // x25
  __int64 v16; // x26
  __int64 (__fastcall *v17)(_QWORD, _QWORD, _QWORD, _QWORD); // x0

  if ( !a1 || !*a1 )
  {
    printk(&unk_23C5E8, "sde_dbg_reg_register_base");
    return 4294967274LL;
  }
  v10 = (__int64 *)_kmalloc_cache_noprof(drm_dp_dpcd_read, 3520, 200);
  if ( !v10 )
    return 4294967284LL;
  while ( 1 )
  {
    v11 = strnlen(a1, 0x50u);
    if ( v11 != -1 )
      break;
    _fortify_panic(2, -1, 0);
LABEL_16:
    _fortify_panic(7, 80, v12);
    StatusReg = _ReadStatusReg(SP_EL0);
    v16 = *(_QWORD *)(StatusReg + 80);
    v17 = drm_dp_dpcd_read;
    *(_QWORD *)(StatusReg + 80) = &sde_dbg_reg_register_base__alloc_tag;
    v10 = (__int64 *)_kmalloc_cache_noprof(v17, 3520, 200);
    *(_QWORD *)(StatusReg + 80) = v16;
    if ( !v10 )
      return 4294967284LL;
  }
  if ( v11 == 80 )
    v12 = 80;
  else
    v12 = v11 + 1;
  if ( v12 >= 0x51 )
    goto LABEL_16;
  sized_strscpy(v10 + 4, a1);
  v10[14] = a2;
  v10[15] = a4;
  v10[17] = 92;
  v10[18] = a3;
  v10[16] = 0;
  v10[21] = 0;
  v10[24] = a5;
  v10[2] = (__int64)(v10 + 2);
  v10[3] = (__int64)(v10 + 2);
  v13 = qword_2942A8;
  if ( *(__int64 **)(qword_2942A8 + 8) != &qword_2942A8 || v10 == &qword_2942A8 || (__int64 *)qword_2942A8 == v10 )
  {
    _list_add_valid_or_report(v10, &qword_2942A8);
    return 0;
  }
  else
  {
    *(_QWORD *)(qword_2942A8 + 8) = v10;
    *v10 = v13;
    v10[1] = (__int64)&qword_2942A8;
    qword_2942A8 = (__int64)v10;
    return 0;
  }
}
