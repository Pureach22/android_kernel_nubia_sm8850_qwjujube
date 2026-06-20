__int64 __fastcall swr_dmic_codec_probe(__int64 a1)
{
  _QWORD *v1; // x19
  const char *v3; // x21
  size_t v4; // x0
  unsigned __int64 v5; // x2
  size_t v6; // x0
  unsigned __int64 v7; // x21
  const char *v8; // x21
  size_t v9; // x0
  size_t v10; // x22
  size_t v11; // x0
  const char *v12; // x1
  size_t v13; // x2
  __int64 v14; // x21
  const char *v15; // x21
  bool v16; // cf
  unsigned __int64 v17; // x8
  size_t v18; // x2
  char *v19; // x0
  unsigned __int64 v20; // x21
  const char *v21; // x21
  bool v22; // cf
  unsigned __int64 v23; // x8
  size_t v24; // x2
  char *v25; // x0
  unsigned __int64 v26; // x21
  const char *v27; // x21
  bool v28; // cf
  unsigned __int64 v29; // x8
  size_t v30; // x2
  char *v31; // x0
  unsigned __int64 v32; // x21
  const char *v33; // x21
  bool v34; // cf
  unsigned __int64 v35; // x8
  size_t v36; // x2
  char *v37; // x0
  unsigned __int64 v38; // x21
  const char *v39; // x21
  bool v40; // cf
  unsigned __int64 v41; // x8
  size_t v42; // x2
  char *v43; // x0
  unsigned __int64 v44; // x21
  const char *v45; // x21
  bool v46; // cf
  unsigned __int64 v47; // x8
  size_t v48; // x2
  char *v49; // x0
  unsigned __int64 v50; // x21
  __int64 result; // x0
  size_t v52; // x2
  __int64 v53; // [xsp+0h] [xbp-30h] BYREF
  __int64 v54; // [xsp+8h] [xbp-28h]
  __int64 v55; // [xsp+10h] [xbp-20h]
  __int64 v56; // [xsp+18h] [xbp-18h]
  __int64 v57; // [xsp+20h] [xbp-10h]
  __int64 v58; // [xsp+28h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD **)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( !v1 )
  {
    result = 4294967274LL;
    goto LABEL_116;
  }
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v1[2] = a1;
  v3 = *(const char **)(a1 + 16);
  v53 = 0;
  if ( !v3 )
  {
    dev_err(*(_QWORD *)(a1 + 24), "%s: component prefix is NULL\n", "swr_dmic_codec_probe");
    result = 4294966779LL;
    goto LABEL_116;
  }
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v53 = 0;
  v4 = strnlen(v3, 0x28u);
  if ( v4 == -1 )
    goto LABEL_118;
  if ( v4 == 40 )
    v5 = 40;
  else
    v5 = v4 + 1;
  if ( v5 >= 0x29 )
    goto LABEL_119;
  sized_strscpy(&v53, v3);
  v6 = strnlen((const char *)&v53, 0x28u);
  if ( v6 >= 0x29 )
    goto LABEL_120;
  if ( v6 != 40 )
  {
    if ( v6 == 39 )
      v7 = 39;
    else
      v7 = v6 + 1;
    memcpy((char *)&v53 + v6, " ", v6 != 39);
    if ( v7 > 0x27 )
      goto LABEL_122;
    *((_BYTE *)&v53 + v7) = 0;
  }
  v8 = *(const char **)(v1[4] + 104LL);
  v9 = strnlen((const char *)&v53, 0x28u);
  v10 = v9;
  if ( v9 >= 0x29 )
  {
    v52 = v9 + 1;
    goto LABEL_121;
  }
  if ( v9 != 40 )
  {
    v11 = strlen(v8);
    v12 = v8;
    if ( v11 + v10 >= 0x28 )
      v13 = 39 - v10;
    else
      v13 = v11;
    if ( v11 + v10 >= 0x28 )
      v14 = 39;
    else
      v14 = v11 + v10;
    memcpy((char *)&v53 + v10, v12, v13);
    *((_BYTE *)&v53 + v14) = 0;
  }
  snd_soc_dapm_ignore_suspend(a1 + 208, &v53);
  v15 = *(const char **)(a1 + 16);
  v53 = 0;
  v54 = 0;
  v55 = 0;
  v56 = 0;
  v57 = 0;
  v4 = strnlen(v15, 0x28u);
  if ( v4 == -1 )
    goto LABEL_118;
  if ( v4 == 40 )
    v5 = 40;
  else
    v5 = v4 + 1;
  if ( v5 >= 0x29 )
    goto LABEL_119;
  sized_strscpy(&v53, v15);
  v6 = strnlen((const char *)&v53, 0x28u);
  if ( v6 >= 0x29 )
    goto LABEL_120;
  if ( v6 != 40 )
  {
    v16 = v6 >= 0x1F;
    v17 = v6 + 9;
    if ( v6 >= 0x1F )
      v18 = 39 - v6;
    else
      v18 = 9;
    v19 = (char *)&v53 + v6;
    if ( v16 )
      v20 = 39;
    else
      v20 = v17;
    memcpy(v19, " SWR_DMIC", v18);
    if ( v20 > 0x27 )
      goto LABEL_122;
    *((_BYTE *)&v53 + v20) = 0;
  }
  snd_soc_dapm_ignore_suspend(a1 + 208, &v53);
  v21 = *(const char **)(a1 + 16);
  v53 = 0;
  v54 = 0;
  v55 = 0;
  v56 = 0;
  v57 = 0;
  v4 = strnlen(v21, 0x28u);
  if ( v4 == -1 )
    goto LABEL_118;
  if ( v4 == 40 )
    v5 = 40;
  else
    v5 = v4 + 1;
  if ( v5 >= 0x29 )
    goto LABEL_119;
  sized_strscpy(&v53, v21);
  v6 = strnlen((const char *)&v53, 0x28u);
  if ( v6 >= 0x29 )
    goto LABEL_120;
  if ( v6 != 40 )
  {
    v22 = v6 >= 0x1B;
    v23 = v6 + 13;
    if ( v6 >= 0x1B )
      v24 = 39 - v6;
    else
      v24 = 13;
    v25 = (char *)&v53 + v6;
    if ( v22 )
      v26 = 39;
    else
      v26 = v23;
    memcpy(v25, " SMIC_PORT_EN", v24);
    if ( v26 > 0x27 )
      goto LABEL_122;
    *((_BYTE *)&v53 + v26) = 0;
  }
  snd_soc_dapm_ignore_suspend(a1 + 208, &v53);
  v27 = *(const char **)(a1 + 16);
  v53 = 0;
  v54 = 0;
  v55 = 0;
  v56 = 0;
  v57 = 0;
  v4 = strnlen(v27, 0x28u);
  if ( v4 == -1 )
    goto LABEL_118;
  if ( v4 == 40 )
    v5 = 40;
  else
    v5 = v4 + 1;
  if ( v5 >= 0x29 )
    goto LABEL_119;
  sized_strscpy(&v53, v27);
  v6 = strnlen((const char *)&v53, 0x28u);
  if ( v6 >= 0x29 )
    goto LABEL_120;
  if ( v6 != 40 )
  {
    v28 = v6 >= 0x18;
    v29 = v6 + 16;
    if ( v6 >= 0x18 )
      v30 = 39 - v6;
    else
      v30 = 16;
    v31 = (char *)&v53 + v6;
    if ( v28 )
      v32 = 39;
    else
      v32 = v29;
    memcpy(v31, " SWR_DMIC_OUTPUT", v30);
    if ( v32 > 0x27 )
      goto LABEL_122;
    *((_BYTE *)&v53 + v32) = 0;
  }
  snd_soc_dapm_ignore_suspend(a1 + 208, &v53);
  v33 = *(const char **)(a1 + 16);
  v53 = 0;
  v54 = 0;
  v55 = 0;
  v56 = 0;
  v57 = 0;
  v4 = strnlen(v33, 0x28u);
  if ( v4 == -1 )
    goto LABEL_118;
  if ( v4 == 40 )
    v5 = 40;
  else
    v5 = v4 + 1;
  if ( v5 >= 0x29 )
    goto LABEL_119;
  sized_strscpy(&v53, v33);
  v6 = strnlen((const char *)&v53, 0x28u);
  if ( v6 >= 0x29 )
    goto LABEL_120;
  if ( v6 != 40 )
  {
    v34 = v6 >= 0x1C;
    v35 = v6 + 12;
    if ( v6 >= 0x1C )
      v36 = 39 - v6;
    else
      v36 = 12;
    v37 = (char *)&v53 + v6;
    if ( v34 )
      v38 = 39;
    else
      v38 = v35;
    memcpy(v37, " VA_SWR_DMIC", v36);
    if ( v38 > 0x27 )
      goto LABEL_122;
    *((_BYTE *)&v53 + v38) = 0;
  }
  snd_soc_dapm_ignore_suspend(a1 + 208, &v53);
  v39 = *(const char **)(a1 + 16);
  v53 = 0;
  v54 = 0;
  v55 = 0;
  v56 = 0;
  v57 = 0;
  v4 = strnlen(v39, 0x28u);
  if ( v4 == -1 )
    goto LABEL_118;
  if ( v4 == 40 )
    v5 = 40;
  else
    v5 = v4 + 1;
  if ( v5 >= 0x29 )
    goto LABEL_119;
  sized_strscpy(&v53, v39);
  v6 = strnlen((const char *)&v53, 0x28u);
  if ( v6 >= 0x29 )
  {
LABEL_120:
    v52 = v6 + 1;
LABEL_121:
    _fortify_panic(2, 40, v52);
    goto LABEL_122;
  }
  if ( v6 != 40 )
  {
    v40 = v6 >= 0x18;
    v41 = v6 + 16;
    if ( v6 >= 0x18 )
      v42 = 39 - v6;
    else
      v42 = 16;
    v43 = (char *)&v53 + v6;
    if ( v40 )
      v44 = 39;
    else
      v44 = v41;
    memcpy(v43, " SMIC_VA_PORT_EN", v42);
    if ( v44 > 0x27 )
      goto LABEL_122;
    *((_BYTE *)&v53 + v44) = 0;
  }
  snd_soc_dapm_ignore_suspend(a1 + 208, &v53);
  v45 = *(const char **)(a1 + 16);
  v53 = 0;
  v54 = 0;
  v55 = 0;
  v56 = 0;
  v57 = 0;
  v4 = strnlen(v45, 0x28u);
  if ( v4 == -1 )
  {
LABEL_118:
    _fortify_panic(2, -1, v4 + 1);
LABEL_119:
    v6 = _fortify_panic(7, 40, v5);
    goto LABEL_120;
  }
  if ( v4 == 40 )
    v5 = 40;
  else
    v5 = v4 + 1;
  if ( v5 >= 0x29 )
    goto LABEL_119;
  sized_strscpy(&v53, v45);
  v6 = strnlen((const char *)&v53, 0x28u);
  if ( v6 >= 0x29 )
    goto LABEL_120;
  if ( v6 != 40 )
  {
    v46 = v6 >= 0x15;
    v47 = v6 + 19;
    if ( v6 >= 0x15 )
      v48 = 39 - v6;
    else
      v48 = 19;
    v49 = (char *)&v53 + v6;
    if ( v46 )
      v50 = 39;
    else
      v50 = v47;
    memcpy(v49, " SWR_DMIC_VA_OUTPUT", v48);
    if ( v50 <= 0x27 )
    {
      *((_BYTE *)&v53 + v50) = 0;
      goto LABEL_114;
    }
LABEL_122:
    __break(1u);
  }
LABEL_114:
  snd_soc_dapm_ignore_suspend(a1 + 208, &v53);
  snd_soc_dapm_sync(a1 + 208);
  v1[22] = swr_dmic_event_notify;
  wcd939x_swr_dmic_register_notifier(v1[5], v1 + 22, 1);
  result = 0;
LABEL_116:
  _ReadStatusReg(SP_EL0);
  return result;
}
