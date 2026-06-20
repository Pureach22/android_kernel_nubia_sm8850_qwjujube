__int64 __fastcall cscfg_param_value_store(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x20
  unsigned int v5; // w21
  __int64 result; // x0
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 - 8);
  v5 = *(_DWORD *)(a1 - 16);
  v7[0] = 0;
  LODWORD(result) = kstrtoull(a2, 0, v7);
  if ( !(_DWORD)result )
    LODWORD(result) = cscfg_update_feat_param_val(v4, v5, v7[0]);
  _ReadStatusReg(SP_EL0);
  if ( (_DWORD)result )
    return (int)result;
  else
    return a3;
}
