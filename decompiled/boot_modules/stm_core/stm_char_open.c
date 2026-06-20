__int64 __fastcall stm_char_open(__int64 a1, __int64 a2)
{
  __int64 device; // x0
  __int64 v5; // x21
  __int64 v6; // x0
  __int64 v7; // x22
  __int64 result; // x0
  unsigned int v9; // w19
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_DWORD *)(a1 + 76) >> 20;
  device = class_find_device(&stm_class, 0, &v10, major_match);
  if ( !device )
  {
    result = 4294967277LL;
    goto LABEL_9;
  }
  v5 = device;
  v6 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 32);
  v7 = v6;
  if ( !v6 )
  {
    v9 = -12;
    goto LABEL_8;
  }
  *(_DWORD *)(v6 + 8) = 0;
  *(_QWORD *)v6 = v5;
  if ( (try_module_get(*(_QWORD *)(v5 + 912)) & 1) == 0 )
  {
    kfree(v7);
    v9 = -19;
LABEL_8:
    put_device(v5);
    result = v9;
    goto LABEL_9;
  }
  *(_QWORD *)(a2 + 32) = v7;
  result = nonseekable_open(a1, a2);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
