__int64 __fastcall qcom_icc_debug_register(__int64 a1)
{
  __int64 v2; // x20
  __int64 *v3; // x1

  v2 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 24);
  if ( !v2 )
    return 4294967284LL;
  *(_QWORD *)(v2 + 16) = a1;
  mutex_lock(&debug_lock);
  v3 = (__int64 *)off_68;
  if ( off_68 == (_UNKNOWN **)v2 || *off_68 != (_UNKNOWN *)&icc_providers )
  {
    _list_add_valid_or_report(v2);
  }
  else
  {
    off_68 = (_UNKNOWN **)v2;
    *(_QWORD *)v2 = &icc_providers;
    *(_QWORD *)(v2 + 8) = v3;
    *v3 = v2;
  }
  mutex_unlock(&debug_lock);
  return 0;
}
