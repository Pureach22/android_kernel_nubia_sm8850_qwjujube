__int64 __fastcall qcom_pdm_get_domain_list(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  __int64 v9; // x22
  __int64 *v10; // x26
  __int64 *v11; // x26
  __int64 *v12; // x27
  __int64 *v13; // t1
  __int64 v14; // x24
  unsigned int v15; // w8
  unsigned int v16; // w24
  size_t v17; // x0
  unsigned __int64 v18; // x2
  unsigned __int64 StatusReg; // x19
  __int64 v20; // x24
  __int64 v21; // [xsp+8h] [xbp-8h]

  result = _kmalloc_cache_noprof(sized_strscpy, 3520, 2452);
  v9 = result;
  if ( !result )
    return result;
  do
  {
    v21 = a3;
    if ( *(_BYTE *)(a4 + 65) )
      a3 = *(unsigned int *)(a4 + 68);
    else
      a3 = 0;
    *(_DWORD *)v9 = 0;
    *(_BYTE *)(v9 + 8) = 1;
    *(_WORD *)(v9 + 10) = 1;
    *(_BYTE *)(v9 + 4) = 1;
    *(_WORD *)(v9 + 6) = 0;
    mutex_lock(&qcom_pdm_mutex);
    v10 = (__int64 *)(a1 + 304);
    do
    {
      v10 = (__int64 *)*v10;
      if ( v10 == (__int64 *)(a1 + 304) )
        goto LABEL_22;
    }
    while ( strcmp((const char *)v10[4], (const char *)a4) );
    if ( !v10
      || (*(_DWORD *)(v9 + 16) = 0,
          *(_BYTE *)(v9 + 12) = 1,
          v13 = (__int64 *)v10[2],
          v11 = v10 + 2,
          v12 = v13,
          v13 == v11) )
    {
LABEL_22:
      if ( (unsigned int)qmi_send_response(a1, a2, v21, 33, 2389, &servreg_get_domain_list_resp_ei, v9) )
        printk(&unk_82B8);
      mutex_unlock(&qcom_pdm_mutex);
      return kfree(v9);
    }
    while ( 1 )
    {
      v15 = *(unsigned __int16 *)(v9 + 6);
      *(_WORD *)(v9 + 6) = v15 + 1;
      if ( v15 > 0x1F || (unsigned int)a3 > v15 )
        goto LABEL_12;
      v16 = *(_DWORD *)(v9 + 16);
      *(_DWORD *)(v9 + 16) = v16 + 1;
      if ( v16 >= 0x20 )
        goto LABEL_27;
      a4 = v12[2];
      v17 = strnlen((const char *)a4, 0x41u);
      if ( v17 == -1 )
        break;
      if ( v17 == 65 )
        v18 = 65;
      else
        v18 = v17 + 1;
      if ( v18 >= 0x42 )
      {
        _fortify_panic(7, 65, v18);
        goto LABEL_22;
      }
      v14 = v9 + 20 + 76LL * v16;
      sized_strscpy(v14, a4);
      *(_DWORD *)(v14 + 72) = *((_DWORD *)v12 + 6);
LABEL_12:
      v12 = (__int64 *)*v12;
      if ( v12 == v11 )
        goto LABEL_22;
    }
    _fortify_panic(2, -1, 0);
LABEL_27:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v20 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &qcom_pdm_get_domain_list__alloc_tag;
    result = _kmalloc_cache_noprof(sized_strscpy, 3520, 2452);
    v9 = result;
    *(_QWORD *)(StatusReg + 80) = v20;
  }
  while ( result );
  return result;
}
