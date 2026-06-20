__int64 __fastcall osif_twt_send_responder_enable_cmd(__int64 a1, unsigned __int8 a2)
{
  __int64 result; // x0
  __int64 v3; // [xsp+8h] [xbp-58h] BYREF
  int v4; // [xsp+10h] [xbp-50h]
  __int64 v5; // [xsp+14h] [xbp-4Ch]
  __int64 v6; // [xsp+1Ch] [xbp-44h]
  __int64 v7; // [xsp+24h] [xbp-3Ch]
  __int64 v8; // [xsp+2Ch] [xbp-34h]
  __int64 v9; // [xsp+34h] [xbp-2Ch]
  __int64 v10; // [xsp+3Ch] [xbp-24h]
  __int64 v11; // [xsp+44h] [xbp-1Ch]
  __int64 v12; // [xsp+4Ch] [xbp-14h]
  int v13; // [xsp+54h] [xbp-Ch]
  __int64 v14; // [xsp+58h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v11 = 0;
  v10 = 0;
  v9 = 0;
  v8 = 0;
  v7 = 0;
  v6 = 0;
  v5 = 0;
  v4 = 0;
  v3 = a2;
  v13 = 1;
  result = osif_twt_responder_enable(a1, (__int64)&v3);
  _ReadStatusReg(SP_EL0);
  return result;
}
