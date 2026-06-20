_QWORD *__fastcall rmnet_shs_create_phy_msg_resp(_QWORD *result, char a2, char a3)
{
  _QWORD *v3; // x21
  __int64 v6; // x8
  __int64 v7; // x10
  __int64 v8; // [xsp+8h] [xbp-18h] BYREF
  __int64 v9; // [xsp+10h] [xbp-10h]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    *result = 0;
    result[1] = 0;
    v3 = result;
    result[2] = 0;
    result[3] = 0;
    result[4] = 0;
    result[5] = 0;
    result[6] = 0;
    result[7] = 0;
    result[8] = 0;
    result[9] = 0;
    result[10] = 0;
    result[11] = 0;
    result[12] = 0;
    result[13] = 0;
    result[14] = 0;
    v8 = 0;
    v9 = 0;
    result = (_QWORD *)ktime_get_real_ts64(&v8);
    v6 = v8;
    v7 = v9;
    *(_BYTE *)v3 = a2;
    *((_BYTE *)v3 + 1) = a3;
    *((_WORD *)v3 + 49) = 2;
    *((_BYTE *)v3 + 114) = 1;
    *((_WORD *)v3 + 56) = 1;
    v3[13] = v7 + 1000000000 * v6;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
