__int64 __fastcall lpass_cdc_soc_codec_probe(__int64 a1)
{
  __int64 *v2; // x20
  unsigned int v3; // w8
  char v4; // w21
  char v5; // w22
  char v6; // w0
  bool v7; // w10
  _BOOL4 v8; // w8
  _BOOL4 v9; // w9
  __int64 (__fastcall *v10)(_QWORD); // x8
  int v11; // w9
  int v12; // w10
  int v13; // w8
  unsigned int v14; // w0
  __int64 (__fastcall *v15)(_QWORD); // x8
  unsigned int v16; // w0
  __int64 (__fastcall *v17)(_QWORD); // x8
  unsigned int v18; // w0
  __int64 (__fastcall *v19)(_QWORD); // x8
  unsigned int v20; // w0
  __int64 (__fastcall *v21)(_QWORD); // x8
  unsigned int v22; // w0
  __int64 v23; // x0
  int v24; // w0
  __int64 v26; // x8
  unsigned int v27; // w19
  unsigned int v28; // w20
  int v29; // w3

  v2 = *(__int64 **)(*(_QWORD *)(a1 + 24) + 152LL);
  snd_soc_component_init_regmap();
  if ( *((_DWORD *)v2 + 212) )
    goto LABEL_7;
  v3 = *((unsigned __int16 *)v2 + 401);
  if ( v3 != 1 && v3 != 2 )
  {
    if ( v3 < 3 )
      goto LABEL_7;
    v3 = 3;
  }
  *((_DWORD *)v2 + 212) = v3;
LABEL_7:
  v4 = snd_soc_component_read(a1, 12480);
  v5 = snd_soc_component_read(a1, 12484);
  v6 = snd_soc_component_read(a1, 12488);
  v7 = v4 == 1;
  v8 = v4 == 2;
  v9 = v5 == 14 && v4 == 2;
  if ( v5 != 15 )
  {
    v8 = 0;
    v7 = 0;
  }
  if ( v8 || v7 || v9 )
  {
    if ( v9 )
      v11 = 5;
    else
      v11 = 4;
    if ( (v6 & 0xFE) == 0x60 )
      v12 = 7;
    else
      v12 = 6;
    if ( v8 )
      v13 = v12;
    else
      v13 = v11;
    *((_DWORD *)v2 + 212) = v13;
    v10 = (__int64 (__fastcall *)(_QWORD))v2[29];
    if ( !v10 )
      goto LABEL_30;
  }
  else
  {
    v10 = (__int64 (__fastcall *)(_QWORD))v2[29];
    if ( !v10 )
      goto LABEL_30;
  }
  if ( *((_DWORD *)v10 - 1) != -725583242 )
    __break(0x8228u);
  v14 = v10(a1);
  if ( (v14 & 0x80000000) != 0 )
  {
    v28 = v14;
    v29 = 0;
LABEL_54:
    dev_err(*(_QWORD *)(a1 + 24), "%s: init for macro %d failed\n", "lpass_cdc_soc_codec_probe", v29);
    return v28;
  }
LABEL_30:
  v15 = (__int64 (__fastcall *)(_QWORD))v2[43];
  if ( v15 )
  {
    if ( *((_DWORD *)v15 - 1) != -725583242 )
      __break(0x8228u);
    v16 = v15(a1);
    if ( (v16 & 0x80000000) != 0 )
    {
      v28 = v16;
      v29 = 1;
      goto LABEL_54;
    }
  }
  v17 = (__int64 (__fastcall *)(_QWORD))v2[57];
  if ( v17 )
  {
    if ( *((_DWORD *)v17 - 1) != -725583242 )
      __break(0x8228u);
    v18 = v17(a1);
    if ( (v18 & 0x80000000) != 0 )
    {
      v28 = v18;
      v29 = 2;
      goto LABEL_54;
    }
  }
  v19 = (__int64 (__fastcall *)(_QWORD))v2[71];
  if ( v19 )
  {
    if ( *((_DWORD *)v19 - 1) != -725583242 )
      __break(0x8228u);
    v20 = v19(a1);
    if ( (v20 & 0x80000000) != 0 )
    {
      v28 = v20;
      v29 = 3;
      goto LABEL_54;
    }
  }
  v21 = (__int64 (__fastcall *)(_QWORD))v2[85];
  if ( v21 )
  {
    if ( *((_DWORD *)v21 - 1) != -725583242 )
      __break(0x8228u);
    v22 = v21(a1);
    if ( (v22 & 0x80000000) != 0 )
    {
      v28 = v22;
      v29 = 4;
      goto LABEL_54;
    }
  }
  v23 = *v2;
  v2[1] = a1;
  v24 = snd_event_client_register(v23, lpass_cdc_ssr_ops, v2);
  if ( v24 )
  {
    v26 = *(_QWORD *)(a1 + 24);
    v27 = v24;
    dev_err(v26, "%s: Registration with SND event FWK failed ret = %d\n", "lpass_cdc_soc_codec_probe", v24);
    return v27;
  }
  else
  {
    snd_event_notify(*v2, 1);
    return 0;
  }
}
