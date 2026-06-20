__int64 __fastcall _ipa_add_rt_rule_after(__int64 a1, __int64 a2, __int64 a3, __int64 **a4)
{
  __int64 *v5; // x8
  __int64 result; // x0
  __int64 *v10; // x1
  __int64 *v11; // x21
  __int64 v12; // x2
  int v13; // w0
  __int64 v14; // [xsp+0h] [xbp-20h] BYREF
  __int64 v15; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v16[2]; // [xsp+10h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a4;
  v14 = 0;
  v15 = 0;
  if ( !v5 )
    goto LABEL_5;
  if ( (unsigned int)_ipa_rt_validate_hndls(a2, &v15, &v14)
    || (v16[0] = 0, (unsigned int)_ipa_create_rt_entry(v16, a2, a1, v15, v14, 0, 1)) )
  {
    v5 = nullptr;
LABEL_5:
    result = 0xFFFFFFFFLL;
    goto LABEL_6;
  }
  v10 = *a4;
  v11 = (__int64 *)v16[0];
  v12 = **a4;
  if ( *(__int64 **)(v12 + 8) != *a4 || (__int64 *)v16[0] == v10 || v16[0] == v12 )
  {
    _list_add_valid_or_report(v16[0], v10);
  }
  else
  {
    *(_QWORD *)(v12 + 8) = v16[0];
    *v11 = v12;
    v11[1] = (__int64)v10;
    *v10 = (__int64)v11;
  }
  v13 = _ipa_finish_rt_rule_add(v11, a3, a1);
  if ( v13 )
    v5 = nullptr;
  else
    v5 = v11;
  if ( v13 )
    result = 0xFFFFFFFFLL;
  else
    result = 0;
LABEL_6:
  *a4 = v5;
  _ReadStatusReg(SP_EL0);
  return result;
}
