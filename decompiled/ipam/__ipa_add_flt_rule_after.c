__int64 __fastcall _ipa_add_flt_rule_after(__int64 a1, const void *a2, const void *a3, unsigned int a4, __int64 **a5)
{
  __int64 *v6; // x8
  __int64 *v10; // x1
  __int64 *v11; // x20
  __int64 v12; // x2
  __int64 result; // x0
  __int64 **v14; // x8
  __int64 *v15; // x9
  unsigned int v16; // w21
  unsigned int v17; // w21
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v22[2]; // [xsp+10h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a5;
  v21 = 0;
  if ( !v6 )
    goto LABEL_25;
  if ( !a2 || !a3 )
  {
    if ( (unsigned int)__ratelimit(&_ipa_add_flt_rule_after__rs, "__ipa_add_flt_rule_after") )
      printk(&unk_3C9B71, "__ipa_add_flt_rule_after");
    v18 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        ipc_log_string(v19, "ipa %s:%d bad parms rule=%pK rule_hdl=%pK\n", "__ipa_add_flt_rule_after", 1087, a2, a3);
        v18 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v18 + 34160);
      if ( v20 )
        ipc_log_string(v20, "ipa %s:%d bad parms rule=%pK rule_hdl=%pK\n", "__ipa_add_flt_rule_after", 1087, a2, a3);
    }
    goto LABEL_25;
  }
  if ( (unsigned int)_ipa_validate_flt_rule(a2, &v21, a4)
    || (v22[0] = 0, (unsigned int)_ipa_create_flt_entry(v22, a2, v21, a1, 1)) )
  {
LABEL_25:
    v11 = nullptr;
    result = 0xFFFFFFFFLL;
    goto LABEL_26;
  }
  v10 = *a5;
  v11 = (__int64 *)v22[0];
  v12 = **a5;
  if ( *(__int64 **)(v12 + 8) != *a5 || (__int64 *)v22[0] == v10 || v12 == v22[0] )
  {
    _list_add_valid_or_report(v22[0], v10);
  }
  else
  {
    *(_QWORD *)(v12 + 8) = v22[0];
    *v11 = v12;
    v11[1] = (__int64)v10;
    *v10 = (__int64)v11;
  }
  result = _ipa_finish_flt_rule_add(a1, v11, a3);
  if ( (_DWORD)result )
  {
    v14 = *(__int64 ***)((char *)&unk_8 + (_QWORD)v11);
    if ( *v14 == v11 && (v15 = (__int64 *)*v11, *(__int64 **)(*v11 + 8) == v11) )
    {
      v15[1] = (__int64)v14;
      *v14 = v15;
    }
    else
    {
      _list_del_entry_valid_or_report(v11);
    }
    v16 = *(unsigned __int16 *)((char *)&word_1A2 + (_QWORD)v11);
    *v11 = 0xDEAD000000000100LL;
    v11[1] = 0xDEAD000000000122LL;
    if ( (unsigned int)((__int64 (*)(void))ipahal_get_rule_id_hi_bit)() > v16 )
    {
      v17 = *(unsigned __int16 *)((char *)&word_1A2 + (_QWORD)v11);
      if ( (unsigned int)((__int64 (*)(void))ipahal_get_low_rule_id)() <= v17 )
        idr_remove(
          *(_QWORD *)(*(_QWORD *)((char *)&unk_188 + (_QWORD)v11) + 136LL),
          *(unsigned __int16 *)((char *)&word_1A2 + (_QWORD)v11));
    }
    kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29376), v11);
    goto LABEL_25;
  }
LABEL_26:
  *a5 = v11;
  _ReadStatusReg(SP_EL0);
  return result;
}
