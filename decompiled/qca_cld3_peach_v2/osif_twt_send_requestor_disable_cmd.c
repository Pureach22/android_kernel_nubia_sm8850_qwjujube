__int64 __fastcall osif_twt_send_requestor_disable_cmd(__int64 a1, unsigned __int8 a2, int a3)
{
  __int64 result; // x0
  int v4; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-18h]
  int v6; // [xsp+10h] [xbp-10h]
  int v7; // [xsp+14h] [xbp-Ch]
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a2;
  v5 = 1;
  v6 = 0;
  v7 = a3;
  result = osif_twt_requestor_disable(a1, (__int64)&v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
