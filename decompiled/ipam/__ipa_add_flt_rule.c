__int64 __fastcall _ipa_add_flt_rule(__int64 *a1, unsigned int a2, __int64 a3, char a4, __int64 a5, char a6)
{
  __int64 *v11; // x19
  __int64 **v12; // x2
  __int64 ***v13; // x1
  __int64 v14; // x2
  __int64 result; // x0
  __int64 **v16; // x8
  __int64 *v17; // x9
  unsigned int v18; // w20
  unsigned int v19; // w20
  __int64 v20; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v21[2]; // [xsp+10h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  if ( (unsigned int)_ipa_validate_flt_rule(a3, &v20, a2)
    || (v21[0] = 0, (unsigned int)_ipa_create_flt_entry(v21, a3, v20, a1, a6 & 1)) )
  {
LABEL_25:
    result = 0xFFFFFFFFLL;
    goto LABEL_26;
  }
  if ( a4 )
  {
    v11 = (__int64 *)v21[0];
    v12 = (__int64 **)a1[1];
    if ( *((_BYTE *)a1 + 128) == 1 )
    {
      v13 = (__int64 ***)v12[1];
      if ( (__int64 **)v21[0] == v12 || v13 == (__int64 ***)v21[0] || *v13 != v12 )
      {
        _list_add_valid_or_report(v21[0], v13);
      }
      else
      {
        v12[1] = (__int64 *)v21[0];
        *v11 = (__int64)v12;
        v11[1] = (__int64)v13;
        *v13 = (__int64 **)v11;
      }
    }
    else if ( (__int64 *)v21[0] == a1 || v12 == (__int64 **)v21[0] || *v12 != a1 )
    {
      _list_add_valid_or_report(v21[0], a1[1]);
    }
    else
    {
      a1[1] = v21[0];
      *v11 = (__int64)a1;
      v11[1] = (__int64)v12;
      *v12 = v11;
    }
  }
  else
  {
    v14 = *a1;
    v11 = (__int64 *)v21[0];
    if ( *(__int64 **)(*a1 + 8) != a1 || (__int64 *)v21[0] == a1 || v14 == v21[0] )
    {
      _list_add_valid_or_report(v21[0], a1);
    }
    else
    {
      *(_QWORD *)(v14 + 8) = v21[0];
      *v11 = v14;
      v11[1] = (__int64)a1;
      *a1 = (__int64)v11;
    }
  }
  result = _ipa_finish_flt_rule_add(a1, v11, a5);
  if ( (_DWORD)result )
  {
    v16 = *(__int64 ***)((char *)&unk_8 + (_QWORD)v11);
    if ( *v16 == v11 && (v17 = (__int64 *)*v11, *(__int64 **)(*v11 + 8) == v11) )
    {
      v17[1] = (__int64)v16;
      *v16 = v17;
    }
    else
    {
      _list_del_entry_valid_or_report(v11);
    }
    v18 = *(unsigned __int16 *)((char *)&word_1A2 + (_QWORD)v11);
    *v11 = 0xDEAD000000000100LL;
    v11[1] = 0xDEAD000000000122LL;
    if ( (unsigned int)((__int64 (*)(void))ipahal_get_rule_id_hi_bit)() > v18 )
    {
      v19 = *(unsigned __int16 *)((char *)&word_1A2 + (_QWORD)v11);
      if ( (unsigned int)((__int64 (*)(void))ipahal_get_low_rule_id)() <= v19 )
        idr_remove(
          *(_QWORD *)(*(_QWORD *)((char *)&unk_188 + (_QWORD)v11) + 136LL),
          *(unsigned __int16 *)((char *)&word_1A2 + (_QWORD)v11));
    }
    kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29376), v11);
    goto LABEL_25;
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
