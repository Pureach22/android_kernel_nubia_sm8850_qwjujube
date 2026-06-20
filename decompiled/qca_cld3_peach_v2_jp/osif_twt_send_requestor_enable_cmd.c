__int64 __fastcall osif_twt_send_requestor_enable_cmd(__int64 a1, unsigned __int8 a2)
{
  unsigned int v3; // w0
  unsigned int v4; // w8
  bool v5; // zf
  __int64 result; // x0
  unsigned int v7; // w20
  __int64 v8; // [xsp+8h] [xbp-58h] BYREF
  int v9; // [xsp+10h] [xbp-50h]
  __int64 v10; // [xsp+14h] [xbp-4Ch]
  __int64 v11; // [xsp+1Ch] [xbp-44h]
  __int64 v12; // [xsp+24h] [xbp-3Ch]
  __int64 v13; // [xsp+2Ch] [xbp-34h]
  __int64 v14; // [xsp+34h] [xbp-2Ch]
  __int64 v15; // [xsp+3Ch] [xbp-24h]
  __int64 v16; // [xsp+44h] [xbp-1Ch]
  __int64 v17; // [xsp+4Ch] [xbp-14h]
  int v18; // [xsp+54h] [xbp-Ch]
  __int64 v19; // [xsp+58h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v16 = 0;
  v15 = 0;
  v14 = 0;
  v13 = 0;
  v12 = 0;
  v11 = 0;
  v10 = 0;
  v9 = 0;
  v8 = a2;
  v18 = 1;
  v3 = ucfg_twt_set_requestor_enable_cmd_in_progress(a1);
  if ( v3 )
  {
    v4 = v3;
    v5 = v3 == 6;
    result = 0;
    if ( !v5 )
      result = qdf_status_to_os_return(v4);
  }
  else
  {
    v7 = osif_twt_requestor_enable(a1, (__int64)&v8);
    ucfg_twt_reset_requestor_enable_cmd_in_progress(a1);
    result = v7;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
