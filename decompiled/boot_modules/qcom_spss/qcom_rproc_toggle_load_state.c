__int64 __fastcall qcom_rproc_toggle_load_state(__int64 a1, __int64 a2, char a3)
{
  const char *v4; // x4
  __int64 result; // x0
  char s[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v7; // [xsp+10h] [xbp-40h]
  __int64 v8; // [xsp+18h] [xbp-38h]
  __int64 v9; // [xsp+20h] [xbp-30h]
  __int64 v10; // [xsp+28h] [xbp-28h]
  __int64 v11; // [xsp+30h] [xbp-20h]
  __int64 v12; // [xsp+38h] [xbp-18h]
  __int64 v13; // [xsp+40h] [xbp-10h]
  __int64 v14; // [xsp+48h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a3 & 1) != 0 )
    v4 = "on";
  else
    v4 = "off";
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  v8 = 0;
  v9 = 0;
  *(_QWORD *)s = 0;
  v7 = 0;
  snprintf(s, 0x40u, "{class: image, res: load_state, name: %s, val: %s}", a2, v4);
  result = qmp_send(a1, s, 64);
  _ReadStatusReg(SP_EL0);
  return result;
}
