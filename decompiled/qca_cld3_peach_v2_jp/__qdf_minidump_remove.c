__int64 __fastcall _qdf_minidump_remove(__int64 result, __int64 a2, const char *a3)
{
  __int64 v3; // x22
  __int64 v6; // x21
  __int64 v7; // x23
  __int64 *v8; // x24

  if ( qdf_va_md_initialized == 1 )
  {
    v3 = result;
    v6 = raw_spin_lock_irqsave(&qdf_va_md_list_lock);
    v7 = qdf_va_md_list;
    qword_76D270 = v6;
    if ( (__int64 *)qdf_va_md_list != &qdf_va_md_list )
    {
      while ( 1 )
      {
        v8 = *(__int64 **)v7;
        if ( *(_QWORD *)(v7 + 16) == v3 && *(_DWORD *)(v7 + 56) == a2 && !strcmp((const char *)(v7 + 24), a3) )
          break;
        v7 = (__int64)v8;
        if ( v8 == &qdf_va_md_list )
          return raw_spin_unlock_irqrestore(&qdf_va_md_list_lock, v6);
      }
      qdf_list_remove_node((__int64)&qdf_va_md_list, (_QWORD *)v7);
      _qdf_mem_free(v7);
      v6 = qword_76D270;
    }
    return raw_spin_unlock_irqrestore(&qdf_va_md_list_lock, v6);
  }
  return result;
}
