__int64 __fastcall sde_dbg_reg_register_dump_range(
        __int64 a1,
        const char *a2,
        unsigned int a3,
        unsigned int a4,
        int a5)
{
  __int64 v6; // x25
  size_t v11; // x0
  __int64 result; // x0
  size_t v13; // x0
  unsigned __int64 v14; // x2
  __int64 v15; // x2
  __int64 *v16; // x1

  v6 = qword_2942A8;
  if ( (__int64 *)qword_2942A8 == &qword_2942A8 )
    return printk(&unk_26D253, "sde_dbg_reg_register_dump_range");
  while ( 1 )
  {
    v11 = strnlen((const char *)(v6 + 32), 0x50u);
    if ( v11 >= 0x51 )
    {
      _fortify_panic(2, 80, v11 + 1);
LABEL_27:
      v13 = _fortify_panic(4, 80, 81);
      goto LABEL_28;
    }
    if ( v11 )
    {
      if ( v11 == 80 )
        goto LABEL_27;
      if ( !strcmp((const char *)(v6 + 32), (const char *)a1) )
        break;
    }
    v6 = *(_QWORD *)v6;
    if ( (__int64 *)v6 == &qword_2942A8 )
      return printk(&unk_26D253, "sde_dbg_reg_register_dump_range");
  }
  if ( !v6 )
    return printk(&unk_26D253, "sde_dbg_reg_register_dump_range");
  if ( !a2 || !*a2 )
    return printk(&unk_243621, "sde_dbg_reg_register_dump_range");
  if ( a3 > a4 )
    return printk(&unk_2321A8, "sde_dbg_reg_register_dump_range");
  result = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 80);
  a1 = result;
  if ( !result )
    return result;
  v13 = strnlen(a2, 0x28u);
  if ( v13 == -1 )
  {
LABEL_28:
    _fortify_panic(2, -1, v13 + 1);
LABEL_29:
    _fortify_panic(7, 40, v14);
    return _list_add_valid_or_report(a1, v16);
  }
  if ( v13 == 40 )
    v14 = 40;
  else
    v14 = v13 + 1;
  if ( v14 >= 0x29 )
    goto LABEL_29;
  result = sized_strscpy(a1 + 24, a2);
  *(_DWORD *)(a1 + 64) = a3;
  *(_DWORD *)(a1 + 68) = a4;
  v15 = v6 + 16;
  *(_DWORD *)(a1 + 72) = a5;
  v16 = *(__int64 **)(v6 + 24);
  if ( a1 != v6 + 16 && v16 != (__int64 *)a1 && *v16 == v15 )
  {
    *(_QWORD *)(v6 + 24) = a1;
    *(_QWORD *)a1 = v15;
    *(_QWORD *)(a1 + 8) = v16;
    *v16 = a1;
    return result;
  }
  return _list_add_valid_or_report(a1, v16);
}
