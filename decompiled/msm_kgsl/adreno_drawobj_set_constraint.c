__int64 __fastcall adreno_drawobj_set_constraint(__int64 result, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v4; // x22
  int v5; // w9
  int v6; // w8
  int v7; // w9
  int v8; // w9
  unsigned int v9; // w10
  unsigned int v10; // w8
  unsigned int v11; // w9
  unsigned int v12; // w19
  __int64 v13; // x20
  int v14; // w8
  int updated; // w0
  int v16; // w19
  __int64 v17; // x19
  __int64 v18; // x0
  _DWORD v19[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v20; // [xsp+18h] [xbp-8h]

  v2 = result + 12288;
  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 8);
  v4 = *(_QWORD *)(a2 + 24);
  if ( *(_BYTE *)(result + 14232) == 1
    && *(_DWORD *)(v3 + 208)
    && ((*(_BYTE *)(v3 + 201) & 8) != 0 || (v4 & 0x800) != 0) )
  {
    v17 = result;
    kgsl_pwrctrl_set_constraint();
    result = v17;
    v5 = *(_DWORD *)(v3 + 232);
    if ( !v5 )
      goto LABEL_26;
  }
  else
  {
    v5 = *(_DWORD *)(v3 + 232);
    if ( !v5 )
      goto LABEL_26;
  }
  if ( (*(_BYTE *)(v3 + 201) & 8) == 0 && (v4 & 0x800) == 0 )
    goto LABEL_26;
  v6 = *(_DWORD *)(result + 13100);
  if ( !v6 )
  {
    if ( (adreno_drawobj_set_constraint___print_once & 1) == 0 )
    {
      v18 = *(_QWORD *)result;
      adreno_drawobj_set_constraint___print_once = 1;
      result = dev_err(v18, "l3 voting not available\n");
    }
    goto LABEL_26;
  }
  if ( v5 != 3
    || (v7 = *(unsigned __int8 *)(v2 + 1128), v19[1] = 0, v7 != 1)
    || ((v8 = *(_DWORD *)(v3 + 236), v9 = *(_DWORD *)(result + 13104), v10 = v6 - 1, v8 + 1 > v9)
      ? (v11 = v8 + 1)
      : (v11 = *(_DWORD *)(result + 13104)),
        v11 >= v10 ? (v12 = v10) : (v12 = v11),
        v9 == v12) )
  {
LABEL_26:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( v12 < 3 )
  {
    v13 = result;
    v14 = *(_DWORD *)(result + 4LL * v12 + 13088);
    v19[2] = 2;
    v19[0] = v14;
    updated = qcom_dcvs_update_votes("kgsl-l3", v19, 1, 0);
    if ( updated )
    {
      v16 = updated;
      result = __ratelimit(&adreno_drawobj_set_constraint__rs, "adreno_drawobj_set_constraint");
      if ( (_DWORD)result )
        result = dev_err(*(_QWORD *)v13, "Could not set l3_vote: %d\n", v16);
    }
    else
    {
      result = trace_kgsl_constraint(v13, v12);
      *(_DWORD *)(v13 + 13104) = v12;
    }
    goto LABEL_26;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))trace_kgsl_constraint)();
}
