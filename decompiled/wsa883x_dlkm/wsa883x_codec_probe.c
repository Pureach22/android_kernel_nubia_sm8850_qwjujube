__int64 __fastcall wsa883x_codec_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x21
  __int64 i; // x22
  __int64 v5; // x8
  const char *v6; // x20
  size_t v7; // x0
  unsigned __int64 v8; // x2
  __int64 result; // x0
  __int64 v10; // x0
  int v11; // w16
  _QWORD v12[6]; // [xsp+0h] [xbp-30h] BYREF

  v12[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( !v1 || !*(_QWORD *)(a1 + 16) )
  {
    result = 4294967274LL;
    goto LABEL_15;
  }
  snd_soc_component_init_regmap(a1, *(_QWORD *)v1);
  *(_QWORD *)(v1 + 24) = a1;
  *(_DWORD *)(v1 + 192) = snd_soc_component_read(a1, 13696) & 0xF;
  *(_DWORD *)(v1 + 196) = (unsigned __int8)snd_soc_component_read(a1, 13313);
  *(_DWORD *)(v1 + 96) = 2;
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( v3 )
  {
    for ( i = 0; i != 200; i += 4 )
      snd_soc_component_update_bits(a1, *(unsigned __int16 *)&reg_init[i], reg_init[i + 2], reg_init[i + 3]);
    if ( (*(_DWORD *)(v3 + 192) | 2) == 2 )
    {
      snd_soc_component_update_bits(a1, 13420, 7, 3);
      *(_DWORD *)(v3 + 96) = 3;
    }
  }
  v5 = *(_QWORD *)(v1 + 384);
  *(_DWORD *)(v1 + 88) = 0;
  memset(v12, 0, 40);
  v6 = *(const char **)(v5 + 152);
  v7 = strnlen(v6, 0x28u);
  if ( v7 == -1 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v7 == 40 )
      v8 = 40;
    else
      v8 = v7 + 1;
    if ( v8 < 0x29 )
    {
      sized_strscpy(v12, v6);
      snd_soc_dapm_ignore_suspend(a1 + 208, v12);
      memset((char *)v12 + 3, 0, 32);
      v12[4] = 0;
      strcpy((char *)v12, "IN");
      snd_soc_dapm_ignore_suspend(a1 + 208, v12);
      memset((char *)&v12[1] + 5, 0, 24);
      HIDWORD(v12[4]) = 0;
      strcpy((char *)v12, "SWR DAC_Port");
      snd_soc_dapm_ignore_suspend(a1 + 208, v12);
      memset((char *)v12 + 5, 0, 32);
      HIDWORD(v12[4]) = 0;
      strcpy((char *)v12, "SPKR");
      snd_soc_dapm_ignore_suspend(a1 + 208, v12);
      snd_soc_dapm_sync(a1 + 208);
      result = 0;
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v10 = _fortify_panic(7);
  if ( (v11 & 0x80000) != 0 )
    JUMPOUT(0x2C58);
  return wsa883x_codec_remove(v10);
}
