__int64 __fastcall reg_get_6ghz_cli_pwr_type_per_ap_pwr_type(
        __int64 a1,
        unsigned int a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v13; // w8
  __int64 result; // x0
  unsigned int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  reg_get_cur_6g_client_type(a1, &v15, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( v15 == 1 )
  {
    if ( a2 < 3 )
    {
      v13 = a2 + 7;
      goto LABEL_7;
    }
LABEL_8:
    result = 16;
    goto LABEL_9;
  }
  if ( v15 || a2 >= 4 )
    goto LABEL_8;
  v13 = dword_A2FB78[a2];
LABEL_7:
  result = 0;
  *a3 = v13;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
