__int64 __fastcall scm_get_wq_ctx(_DWORD *a1, _DWORD *a2, _DWORD *a3, char a4)
{
  __int64 v7; // x0
  __int64 result; // x0
  int v9; // w9
  int v10; // w10
  __int64 v11; // [xsp+18h] [xbp-38h] BYREF
  __int64 v12; // [xsp+20h] [xbp-30h]
  __int64 v13; // [xsp+28h] [xbp-28h]
  __int64 v14; // [xsp+30h] [xbp-20h]
  __int64 v15; // [xsp+38h] [xbp-18h] BYREF
  __int64 v16; // [xsp+40h] [xbp-10h]
  __int64 v17; // [xsp+48h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v15 = 1;
  v16 = 0;
  if ( hab_calling_convention == 1 )
    goto LABEL_9;
  v7 = (a4 & 1) != 0 ? 3254789123LL : 1107305475LL;
  _arm_smccc_smc(v7, 0, 0, 0, 0, 0, 0, 0, &v11, &v15);
  while ( 1 )
  {
    result = v11;
    if ( v11 != 1 )
      break;
    _arm_smccc_smc(1, 0, 0, 0, 0, 0, v16, 0, &v11, &v15);
  }
  if ( !(_DWORD)v11 )
  {
LABEL_9:
    v9 = v13;
    result = 0;
    v10 = v14;
    *a1 = v12;
    *a2 = v9;
    *a3 = v10;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
