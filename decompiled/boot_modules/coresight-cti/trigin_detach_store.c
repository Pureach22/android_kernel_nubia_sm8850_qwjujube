__int64 __fastcall trigin_detach_store(__int64 a1, int a2, char *s, int a4)
{
  int v6; // w0
  int v7; // w8
  __int64 result; // x0
  __int64 v9; // [xsp+0h] [xbp-10h] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  if ( sscanf(s, "%d %d", (char *)&v9 + 4, &v9) == 2 )
  {
    v6 = cti_channel_trig_op(a1, 1, 0, HIDWORD(v9), v9);
    if ( v6 )
      v7 = v6;
    else
      v7 = a4;
    result = v7;
  }
  else
  {
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
