__int64 __fastcall msm_int_wsa_init(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x2
  __int64 v4; // x20
  const char *v5; // x21
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x9
  _QWORD *v9; // x21
  __int64 v10; // x0
  __int64 v11; // x2
  __int64 v12; // x20
  int *v13; // x1
  int *v14; // x5
  __int64 v15; // x0
  __int64 v16; // x2
  __int64 v17; // x20
  __int64 v18; // x0
  __int64 v19; // x20
  __int64 v20; // x0
  __int64 v21; // x20
  __int64 v22; // x10
  _QWORD *v23; // x21
  int v24; // w9
  __int64 v25; // x0
  __int64 v26; // x2
  __int64 v27; // x20
  int *v28; // x1
  int *v29; // x5
  __int64 v30; // x0
  __int64 v31; // x20
  __int64 v32; // x0
  __int64 v33; // x20
  __int64 v34; // x0
  __int64 v35; // x20
  __int64 result; // x0
  __int64 v37; // x1
  __int64 v38; // x2
  __int64 v39; // x0
  void *v40; // x0
  __int64 v41; // x0
  const char *v42; // x1
  int v43; // [xsp+8h] [xbp-58h] BYREF
  __int16 v44; // [xsp+Ch] [xbp-54h]
  int v45; // [xsp+10h] [xbp-50h] BYREF
  __int16 v46; // [xsp+14h] [xbp-4Ch]
  int v47; // [xsp+18h] [xbp-48h] BYREF
  __int16 v48; // [xsp+1Ch] [xbp-44h]
  int v49; // [xsp+20h] [xbp-40h] BYREF
  __int16 v50; // [xsp+24h] [xbp-3Ch]
  __int64 v51; // [xsp+28h] [xbp-38h] BYREF
  __int64 v52; // [xsp+30h] [xbp-30h]
  __int64 v53; // [xsp+38h] [xbp-28h]
  __int64 v54; // [xsp+40h] [xbp-20h] BYREF
  __int64 v55; // [xsp+48h] [xbp-18h]
  __int64 v56; // [xsp+50h] [xbp-10h]
  __int64 v57; // [xsp+58h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = snd_soc_rtdcom_lookup(a1, "lpass-cdc");
  if ( !v2 )
  {
    printk(&unk_12A17, "msm_int_wsa_init", v3);
    goto LABEL_29;
  }
  v4 = v2;
  v5 = **(const char ***)(a1 + 8);
  if ( !strstr(v5, "wsa883x") )
  {
    if ( !strstr(v5, "wsa884x") )
    {
      lpass_cdc_set_port_map(v4, 2, &sm_wsa8855_port_map);
      result = msm_common_dai_link_init((_QWORD *)a1, v37, v38);
      goto LABEL_30;
    }
    lpass_cdc_set_port_map(v4, 2, &sm_wsa_port_map);
    v22 = *(_QWORD *)(a1 + 8);
    v50 = 1284;
    v48 = 1284;
    v23 = *(_QWORD **)(v22 + 784);
    v46 = 3338;
    v49 = 50462976;
    v47 = 50462976;
    v45 = 117637633;
    v44 = 3339;
    v56 = 0x5DC000124F80LL;
    v43 = 117835012;
    v51 = 0xF00000001LL;
    v54 = 2576980380000000LL;
    v55 = 0xBB80000493E0LL;
    v24 = *((_DWORD *)v23 + 23);
    v52 = 0x100000003LL;
    v53 = 0x300000003LL;
    if ( v24 )
    {
      v25 = snd_soc_rtdcom_lookup(a1, "wsa-codec.1");
      if ( v25 )
      {
        v27 = v25;
        v28 = &v49;
        v29 = &v45;
      }
      else
      {
        printk(&unk_13005, "msm_int_wsa884x_init", v26);
        v41 = snd_soc_rtdcom_lookup(a1, "wsa-codec.2");
        if ( !v41 )
          goto LABEL_39;
        v27 = v41;
        v28 = &v47;
        v29 = &v43;
      }
      wsa884x_set_channel_map(v27, v28, 6, &v51, &v54, v29);
      wsa884x_codec_info_create_codec_entry(*v23, v27);
      if ( *((_DWORD *)v23 + 23) >= 2u )
      {
        v30 = snd_soc_rtdcom_lookup(a1, "wsa-codec.2");
        if ( v30 )
        {
          v31 = v30;
          wsa884x_set_channel_map(v30, &v47, 6, &v51, &v54, &v43);
          wsa884x_codec_info_create_codec_entry(*v23, v31);
          goto LABEL_22;
        }
LABEL_39:
        v40 = &unk_13F26;
LABEL_44:
        v42 = "msm_int_wsa884x_init";
        goto LABEL_45;
      }
    }
LABEL_22:
    if ( (v23[18] & 1) != 0 || *((_DWORD *)v23 + 23) < 3u )
      goto LABEL_28;
    v32 = snd_soc_rtdcom_lookup(a1, "wsa-codec.3");
    if ( v32 )
    {
      v33 = v32;
      wsa884x_set_channel_map(v32, &v49, 6, &v51, &v54, &v45);
      wsa884x_codec_info_create_codec_entry(*v23, v33);
      if ( *((_DWORD *)v23 + 23) < 4u )
        goto LABEL_28;
      v34 = snd_soc_rtdcom_lookup(a1, "wsa-codec.4");
      if ( v34 )
      {
        v35 = v34;
        wsa884x_set_channel_map(v34, &v47, 6, &v51, &v54, &v43);
        wsa884x_codec_info_create_codec_entry(*v23, v35);
        goto LABEL_28;
      }
      v40 = &unk_13575;
    }
    else
    {
      v40 = &unk_12CB3;
    }
    goto LABEL_44;
  }
  lpass_cdc_set_port_map(v4, 2, &sm_wsa_port_map);
  v49 = 50462976;
  v47 = 50462976;
  v45 = 167969281;
  v8 = *(_QWORD *)(a1 + 8);
  v43 = 184943876;
  v9 = *(_QWORD **)(v8 + 784);
  LODWORD(v8) = *((_DWORD *)v9 + 23);
  v54 = 2576980380000000LL;
  v55 = 5153960755500000LL;
  v51 = 0xF00000001LL;
  v52 = 0x300000003LL;
  if ( (_DWORD)v8 )
  {
    v10 = snd_soc_rtdcom_lookup(a1, "wsa-codec.1");
    if ( v10 )
    {
      v12 = v10;
      v13 = &v49;
      v14 = &v45;
    }
    else
    {
      printk(&unk_13005, "msm_int_wsa883x_init", v11);
      v39 = snd_soc_rtdcom_lookup(a1, "wsa-codec.2");
      if ( !v39 )
        goto LABEL_35;
      v12 = v39;
      v13 = &v47;
      v14 = &v43;
    }
    wsa883x_set_channel_map(v12, v13, 4, &v51, &v54, v14);
    wsa883x_codec_info_create_codec_entry(*v9, v12);
    if ( *((_DWORD *)v9 + 23) >= 2u )
    {
      v15 = snd_soc_rtdcom_lookup(a1, "wsa-codec.2");
      if ( v15 )
      {
        v17 = v15;
        wsa883x_set_channel_map(v15, &v47, 4, &v51, &v54, &v43);
        wsa883x_codec_info_create_codec_entry(*v9, v17);
        goto LABEL_9;
      }
LABEL_35:
      v40 = &unk_13F26;
LABEL_41:
      v42 = "msm_int_wsa883x_init";
LABEL_45:
      printk(v40, v42, v16);
      result = 4294967274LL;
      goto LABEL_30;
    }
  }
LABEL_9:
  if ( (v9[18] & 1) != 0 || *((_DWORD *)v9 + 23) < 3u )
    goto LABEL_28;
  v18 = snd_soc_rtdcom_lookup(a1, "wsa-codec.3");
  if ( !v18 )
  {
    v40 = &unk_12CB3;
    goto LABEL_41;
  }
  v19 = v18;
  wsa883x_set_channel_map(v18, &v49, 4, &v51, &v54, &v45);
  wsa883x_codec_info_create_codec_entry(*v9, v19);
  if ( *((_DWORD *)v9 + 23) >= 4u )
  {
    v20 = snd_soc_rtdcom_lookup(a1, "wsa-codec.4");
    if ( v20 )
    {
      v21 = v20;
      wsa883x_set_channel_map(v20, &v47, 4, &v51, &v54, &v43);
      wsa883x_codec_info_create_codec_entry(*v9, v21);
      goto LABEL_28;
    }
    v40 = &unk_13575;
    goto LABEL_41;
  }
LABEL_28:
  msm_common_dai_link_init((_QWORD *)a1, v6, v7);
LABEL_29:
  result = 0;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
