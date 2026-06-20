__int64 __fastcall ucfg_reg_set_config_vars(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 result; // x0
  _QWORD v14[6]; // [xsp+0h] [xbp-30h] BYREF

  v14[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = a2[2];
  v11 = a2[3];
  v14[4] = a2[4];
  v14[2] = v10;
  v14[3] = v11;
  v12 = a2[1];
  v14[0] = *a2;
  v14[1] = v12;
  result = reg_set_config_vars(a1, (__int64)v14, a3, a4, a5, a6, a7, a8, a9, a10);
  _ReadStatusReg(SP_EL0);
  return result;
}
