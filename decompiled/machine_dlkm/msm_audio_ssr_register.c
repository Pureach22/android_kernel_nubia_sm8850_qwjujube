__int64 __fastcall msm_audio_ssr_register(__int64 a1)
{
  __int64 v2; // x20
  unsigned int v3; // w22
  __int64 result; // x0
  __int64 v5; // [xsp+0h] [xbp-60h] BYREF
  __int64 v6; // [xsp+8h] [xbp-58h] BYREF
  __int64 v7; // [xsp+10h] [xbp-50h]
  __int64 v8; // [xsp+18h] [xbp-48h]
  __int64 v9; // [xsp+20h] [xbp-40h]
  __int64 v10; // [xsp+28h] [xbp-38h]
  __int64 v11; // [xsp+30h] [xbp-30h]
  __int64 v12; // [xsp+38h] [xbp-28h]
  __int64 v13; // [xsp+40h] [xbp-20h]
  __int64 v14; // [xsp+48h] [xbp-18h]
  __int64 v15; // [xsp+50h] [xbp-10h]
  __int64 v16; // [xsp+58h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 744);
  v5 = 0;
  v6 = 0;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  v8 = 0;
  v9 = 0;
  v7 = 0;
  if ( !(unsigned int)_of_parse_phandle_with_args(v2, "qcom,msm_audio_ssr_devs", 0, 0, 0, &v6) && v6 )
  {
    v3 = 1;
    do
    {
      snd_event_mstr_add_client(&v5, msm_audio_ssr_compare);
      v14 = 0;
      v15 = 0;
      v12 = 0;
      v13 = 0;
      v10 = 0;
      v11 = 0;
      v8 = 0;
      v9 = 0;
      v6 = 0;
      v7 = 0;
      if ( (unsigned int)_of_parse_phandle_with_args(v2, "qcom,msm_audio_ssr_devs", 0, 0, v3, &v6) )
        break;
      ++v3;
    }
    while ( v6 );
  }
  result = snd_event_master_register(a1, canoe_ssr_ops, v5, 0);
  if ( !(_DWORD)result )
  {
    snd_event_notify(a1, 1);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
