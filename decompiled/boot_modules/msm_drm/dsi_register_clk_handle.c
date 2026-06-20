__int64 __fastcall dsi_register_clk_handle(__int64 a1, const char *a2)
{
  __int64 v4; // x20
  size_t v5; // x0
  unsigned __int64 v6; // x2
  _QWORD *v7; // x0
  _QWORD *v8; // x1
  _QWORD *v9; // x2
  unsigned __int64 StatusReg; // x22
  __int64 v11; // x23
  __int64 (__fastcall *v12)(_QWORD, _QWORD, _QWORD); // x0

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: bad params\n");
    return -22;
  }
  mutex_lock(a1 + 32);
  v4 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 88);
  if ( !v4 )
  {
LABEL_17:
    v4 = -12;
    goto LABEL_18;
  }
  while ( 1 )
  {
    v5 = strnlen(a2, 0x20u);
    if ( v5 != -1 )
      break;
    _fortify_panic(2, -1, 0);
LABEL_16:
    _fortify_panic(7, 32, v6);
    StatusReg = _ReadStatusReg(SP_EL0);
    v11 = *(_QWORD *)(StatusReg + 80);
    v12 = _kmalloc_cache_noprof;
    *(_QWORD *)(StatusReg + 80) = &dsi_register_clk_handle__alloc_tag;
    v4 = _kmalloc_cache_noprof(v12, 3520, 88);
    *(_QWORD *)(StatusReg + 80) = v11;
    if ( !v4 )
      goto LABEL_17;
  }
  if ( v5 == 32 )
    v6 = 32;
  else
    v6 = v5 + 1;
  if ( v6 >= 0x21 )
    goto LABEL_16;
  sized_strscpy(v4, a2);
  *(_QWORD *)(v4 + 80) = a1;
  v7 = (_QWORD *)(v4 + 64);
  v8 = (_QWORD *)(a1 + 80);
  v9 = *(_QWORD **)(a1 + 80);
  if ( v9[1] != a1 + 80 || v7 == v8 || v9 == v7 )
  {
    _list_add_valid_or_report(v7, v8);
  }
  else
  {
    v9[1] = v7;
    *(_QWORD *)(v4 + 64) = v9;
    *(_QWORD *)(v4 + 72) = v8;
    *v8 = v7;
  }
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s]: Added new client (%s)\n", (const char *)a1, (const char *)v4);
LABEL_18:
  mutex_unlock(a1 + 32);
  return v4;
}
