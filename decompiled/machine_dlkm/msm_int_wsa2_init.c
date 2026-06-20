__int64 __fastcall msm_int_wsa2_init(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x2
  __int64 v4; // x20
  __int64 v5; // x1
  __int64 v6; // x2
  _QWORD *v7; // x21
  bool v8; // zf
  __int64 v9; // x0
  __int64 v10; // x2
  __int64 v11; // x20
  __int64 v12; // x0
  __int64 v13; // x20
  _QWORD *v14; // x21
  __int64 v15; // x0
  __int64 v16; // x20
  __int64 v17; // x0
  __int64 v18; // x20
  __int64 result; // x0
  void *v20; // x0
  const char *v21; // x1
  int v22; // [xsp+8h] [xbp-58h] BYREF
  __int16 v23; // [xsp+Ch] [xbp-54h]
  int v24; // [xsp+10h] [xbp-50h] BYREF
  __int16 v25; // [xsp+14h] [xbp-4Ch]
  int v26; // [xsp+18h] [xbp-48h] BYREF
  __int16 v27; // [xsp+1Ch] [xbp-44h]
  int v28; // [xsp+20h] [xbp-40h] BYREF
  __int16 v29; // [xsp+24h] [xbp-3Ch]
  __int64 v30; // [xsp+28h] [xbp-38h] BYREF
  __int64 v31; // [xsp+30h] [xbp-30h]
  __int64 v32; // [xsp+38h] [xbp-28h]
  __int64 v33; // [xsp+40h] [xbp-20h] BYREF
  __int64 v34; // [xsp+48h] [xbp-18h]
  __int64 v35; // [xsp+50h] [xbp-10h]
  __int64 v36; // [xsp+58h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = snd_soc_rtdcom_lookup(a1, "lpass-cdc");
  if ( !v2 )
  {
    printk(&unk_12A17, "msm_int_wsa2_init", v3);
    goto LABEL_18;
  }
  lpass_cdc_set_port_map(v2, 2, &sm_wsa2_port_map);
  v4 = a1[1];
  if ( !strstr(*(const char **)v4, "wsa883x") )
  {
    v14 = *(_QWORD **)(v4 + 784);
    v29 = 1284;
    v27 = 1284;
    v25 = 3338;
    v28 = 50462976;
    v24 = 117637633;
    v23 = 3339;
    v26 = 50462976;
    v22 = 117835012;
    v35 = 0x5DC000124F80LL;
    v33 = 2576980380000000LL;
    v34 = 0xBB80000493E0LL;
    v8 = *((_BYTE *)v14 + 144) == 1;
    v31 = 0x100000003LL;
    v32 = 0x300000003LL;
    v30 = 0xF00000001LL;
    if ( !v8 )
      goto LABEL_18;
    if ( *((_DWORD *)v14 + 23) < 3u )
      goto LABEL_17;
    v15 = snd_soc_rtdcom_lookup(a1, "wsa-codec.3");
    if ( v15 )
    {
      v16 = v15;
      wsa884x_set_channel_map(v15, &v28, 6, &v30, &v33, &v24);
      wsa884x_codec_info_create_codec_entry(*v14, v16);
      if ( *((_DWORD *)v14 + 23) < 4u )
        goto LABEL_17;
      v17 = snd_soc_rtdcom_lookup(a1, "wsa-codec.4");
      if ( v17 )
      {
        v18 = v17;
        wsa884x_set_channel_map(v17, &v26, 6, &v30, &v33, &v22);
        wsa884x_codec_info_create_codec_entry(*v14, v18);
        goto LABEL_17;
      }
      v20 = &unk_13575;
    }
    else
    {
      v20 = &unk_12CB3;
    }
    v21 = "msm_int_wsa884x_2_init";
LABEL_27:
    printk(v20, v21, v10);
    result = 4294967274LL;
    goto LABEL_19;
  }
  v7 = *(_QWORD **)(v4 + 784);
  v24 = 167969281;
  v28 = 50462976;
  v26 = 50462976;
  v22 = 184943876;
  v8 = *((_BYTE *)v7 + 144) == 1;
  v33 = 2576980380000000LL;
  v34 = 5153960755500000LL;
  v30 = 0xF00000001LL;
  v31 = 0x300000003LL;
  if ( !v8 )
    goto LABEL_18;
  if ( *((_DWORD *)v7 + 23) < 3u )
    goto LABEL_17;
  v9 = snd_soc_rtdcom_lookup(a1, "wsa-codec.3");
  if ( !v9 )
  {
    v20 = &unk_12CB3;
LABEL_24:
    v21 = "msm_int_wsa883x_2_init";
    goto LABEL_27;
  }
  v11 = v9;
  wsa883x_set_channel_map(v9, &v28, 4, &v30, &v33, &v24);
  wsa883x_codec_info_create_codec_entry(*v7, v11);
  if ( *((_DWORD *)v7 + 23) >= 4u )
  {
    v12 = snd_soc_rtdcom_lookup(a1, "wsa-codec.4");
    if ( v12 )
    {
      v13 = v12;
      wsa883x_set_channel_map(v12, &v26, 4, &v30, &v33, &v22);
      wsa883x_codec_info_create_codec_entry(*v7, v13);
      goto LABEL_17;
    }
    v20 = &unk_13575;
    goto LABEL_24;
  }
LABEL_17:
  msm_common_dai_link_init(a1, v5, v6);
LABEL_18:
  result = 0;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
