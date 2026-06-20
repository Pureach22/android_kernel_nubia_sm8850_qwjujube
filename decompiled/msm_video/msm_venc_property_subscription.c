__int64 __fastcall msm_venc_property_subscription(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // x5
  __int64 result; // x0
  __int64 v8; // x20
  int v9; // [xsp+8h] [xbp-88h] BYREF
  __int64 v10; // [xsp+Ch] [xbp-84h]
  __int64 v11; // [xsp+14h] [xbp-7Ch]
  __int64 v12; // [xsp+1Ch] [xbp-74h]
  __int64 v13; // [xsp+24h] [xbp-6Ch]
  __int64 v14; // [xsp+2Ch] [xbp-64h]
  __int64 v15; // [xsp+34h] [xbp-5Ch]
  __int64 v16; // [xsp+3Ch] [xbp-54h]
  __int64 v17; // [xsp+44h] [xbp-4Ch]
  __int64 v18; // [xsp+4Ch] [xbp-44h]
  __int64 v19; // [xsp+54h] [xbp-3Ch]
  __int64 v20; // [xsp+5Ch] [xbp-34h]
  __int64 v21; // [xsp+64h] [xbp-2Ch]
  __int64 v22; // [xsp+6Ch] [xbp-24h]
  __int64 v23; // [xsp+74h] [xbp-1Ch]
  __int64 v24; // [xsp+7Ch] [xbp-14h]
  int v25; // [xsp+84h] [xbp-Ch]
  __int64 v26; // [xsp+88h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v24 = 0;
  v23 = 0;
  v22 = 0;
  v21 = 0;
  v20 = 0;
  v19 = 0;
  v18 = 0;
  v17 = 0;
  v16 = 0;
  v15 = 0;
  v14 = 0;
  v13 = 0;
  v12 = 0;
  v11 = 0;
  v10 = 0;
  if ( a1 && (msm_vidc_debug & 2) != 0 )
  {
    v8 = a1;
    printk(&unk_9602D, "high", a1 + 340, "msm_venc_property_subscription", a5);
    a1 = v8;
  }
  v9 = 2;
  if ( a2 )
  {
    LODWORD(v11) = 50332020;
    v6 = 16;
    v10 = 0x300016C03000162LL;
  }
  else
  {
    v6 = 8;
    LODWORD(v10) = 50332010;
  }
  result = msm_vidc_session_command(a1, 16777227, a2, 11, &v9, v6, "msm_venc_property_subscription");
  _ReadStatusReg(SP_EL0);
  return result;
}
