__int64 __fastcall wsa884x_codec_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x21
  __int64 i; // x22
  unsigned int v5; // w8
  __int64 v6; // x3
  __int64 v7; // x8
  const char *v8; // x20
  size_t v9; // x0
  unsigned __int64 v10; // x2
  __int64 result; // x0
  __int64 v12; // x0
  int v13; // w16
  _QWORD v14[6]; // [xsp+0h] [xbp-30h] BYREF

  v14[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( !v1 || !*(_QWORD *)(a1 + 16) )
  {
    result = 4294967274LL;
    goto LABEL_19;
  }
  snd_soc_component_init_regmap(a1, *(_QWORD *)v1);
  *(_QWORD *)(v1 + 24) = a1;
  *(_DWORD *)(v1 + 216) = snd_soc_component_read(a1, 14464) & 0xF;
  *(_DWORD *)(v1 + 220) = (unsigned __int8)snd_soc_component_read(a1, 13313);
  *(_DWORD *)(v1 + 120) = 2;
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( v3 )
  {
    for ( i = 0; i != 140; i += 4 )
      snd_soc_component_update_bits(a1, *(unsigned __int16 *)&reg_init[i], reg_init[i + 2], reg_init[i + 3]);
    if ( *(_DWORD *)(v3 + 228) == 2 )
    {
      snd_soc_component_update_bits(a1, 13521, 240, 32);
      snd_soc_component_update_bits(a1, 13522, 31, 19);
      snd_soc_component_update_bits(a1, 12293, 15, 3);
      snd_soc_component_update_bits(a1, 12293, 240, 48);
      snd_soc_component_update_bits(a1, 12357, 255, 6);
      snd_soc_component_update_bits(a1, 12358, 255, 20);
      snd_soc_component_update_bits(a1, 12359, 255, 25);
      snd_soc_component_update_bits(a1, 12360, 255, 27);
      snd_soc_component_update_bits(a1, 12361, 255, 28);
      snd_soc_component_update_bits(a1, 12394, 2, 2);
    }
    snd_soc_component_update_bits(a1, 12293, 255, 119);
    snd_soc_component_update_bits(a1, 13363, 255, 192);
    snd_soc_component_update_bits(a1, 13408, 255, 29);
    snd_soc_component_update_bits(a1, 12294, 255, 64);
    v5 = *(_DWORD *)(v3 + 712) - 1;
    if ( v5 >= 3 )
      v6 = 8;
    else
      v6 = 48 - 16 * v5;
    snd_soc_component_update_bits(a1, 13362, 56, v6);
  }
  v7 = *(_QWORD *)(v1 + 696);
  *(_DWORD *)(v1 + 112) = 0;
  memset(v14, 0, 40);
  v8 = *(const char **)(v7 + 152);
  v9 = strnlen(v8, 0x28u);
  if ( v9 == -1 )
  {
    _fortify_panic(2);
  }
  else
  {
    if ( v9 == 40 )
      v10 = 40;
    else
      v10 = v9 + 1;
    if ( v10 < 0x29 )
    {
      sized_strscpy(v14, v8);
      snd_soc_dapm_ignore_suspend(a1 + 208, v14);
      memset((char *)v14 + 3, 0, 32);
      v14[4] = 0;
      strcpy((char *)v14, "IN");
      snd_soc_dapm_ignore_suspend(a1 + 208, v14);
      memset((char *)&v14[1] + 5, 0, 24);
      HIDWORD(v14[4]) = 0;
      strcpy((char *)v14, "SWR DAC_Port");
      snd_soc_dapm_ignore_suspend(a1 + 208, v14);
      memset((char *)v14 + 5, 0, 32);
      HIDWORD(v14[4]) = 0;
      strcpy((char *)v14, "SPKR");
      snd_soc_dapm_ignore_suspend(a1 + 208, v14);
      snd_soc_dapm_sync(a1 + 208);
      result = 0;
LABEL_19:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v12 = _fortify_panic(7);
  if ( (v13 & 0x80000) != 0 )
    JUMPOUT(0x5024);
  return wsa884x_codec_remove(v12);
}
