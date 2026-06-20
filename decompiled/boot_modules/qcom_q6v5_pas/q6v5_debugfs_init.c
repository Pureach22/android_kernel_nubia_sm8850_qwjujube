__int64 __fastcall q6v5_debugfs_init(__int64 a1)
{
  __int64 v2; // x20
  size_t v3; // x0
  size_t v4; // x9
  unsigned __int64 v5; // x2
  _QWORD *v6; // x8
  __int64 result; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v9; // x22
  __int64 v10; // x0
  char s[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  s[0] = 0;
  if ( strlen(s) + 1 >= 2 )
  {
    _fortify_panic(4, 1);
    goto LABEL_13;
  }
  if ( debugfs_create_file("ssr_reasons", 420, *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1032LL), a1, &q6v5_debugfs_ops)
    && (v2 = _kmalloc_cache_noprof(qcom_scm_pas_metadata_release, 3264, 17), (*(_QWORD *)(a1 + 328) = v2) != 0) )
  {
    while ( 1 )
    {
      v3 = strlen(s);
      v4 = v3 == -1 ? 0LL : v3;
      v5 = v4 == 1 ? 1LL : v4 + 1;
      if ( v5 < 2 )
        break;
LABEL_13:
      _fortify_panic(7, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      v9 = *(_QWORD *)(StatusReg + 80);
      v10 = qcom_scm_pas_metadata_release;
      *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
      v2 = _kmalloc_cache_noprof(v10, 3264, 17);
      *(_QWORD *)(StatusReg + 80) = v9;
      *(_QWORD *)(a1 + 328) = v2;
      if ( !v2 )
        goto LABEL_14;
    }
    sized_strscpy(v2 + 16, s);
    v6 = *(_QWORD **)(a1 + 328);
    result = 0;
    *v6 = v6;
    v6[1] = v6;
  }
  else
  {
LABEL_14:
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
