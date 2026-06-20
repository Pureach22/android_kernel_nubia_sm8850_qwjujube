__int64 __fastcall _cam_print_log(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        char a9)
{
  _QWORD v9[12]; // [xsp+38h] [xbp-88h] BYREF
  char *v10; // [xsp+98h] [xbp-28h]
  _QWORD *v11; // [xsp+A0h] [xbp-20h]
  __int64 v12; // [xsp+A8h] [xbp-18h]
  __int64 v13; // [xsp+B0h] [xbp-10h]
  __int64 v14; // [xsp+B8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v9[6] = 0;
  v9[7] = 4294967248LL;
  v9[4] = &a9;
  v9[5] = v9;
  v13 = 4294967248LL;
  v10 = &a9;
  v11 = v9;
  v9[10] = 0;
  v9[11] = 4294967248LL;
  v9[8] = &a9;
  v9[9] = v9;
  if ( (result & 1) != 0 && debug_type != 1 )
  {
    v9[0] = v10;
    v9[1] = v11;
    v9[2] = v12;
    v9[3] = v13;
    result = vprintk(&L_str_20, v9);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
