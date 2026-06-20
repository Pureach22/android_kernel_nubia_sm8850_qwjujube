__int64 __fastcall wcd9378_mbhc_zdet_ramp(__int64 a1, unsigned __int16 *a2, _DWORD *a3, _DWORD *a4, __int64 a5)
{
  int v10; // w9
  __int64 v11; // x8
  __int64 v12; // x21
  __int64 result; // x0
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a2;
  v11 = *(_QWORD *)(a1 + 24);
  v14 = 0;
  v12 = *(_QWORD *)(v11 + 152);
  snd_soc_component_update_bits(a1, 1075314979, 112, (unsigned int)(16 * v10));
  snd_soc_component_update_bits(a1, 1075314719, 252, a2[3]);
  snd_soc_component_update_bits(a1, 1075314720, 252, a2[4]);
  snd_soc_component_update_bits(a1, 1075314721, 252, a2[5]);
  snd_soc_component_update_bits(a1, 1075314979, 15, a2[1]);
  result = snd_soc_component_update_bits(a1, 1075314980, 15, a2[2]);
  if ( a3 )
  {
    regmap_update_bits_base(*(_QWORD *)(v12 + 48), 1075314710, 128, 128, 0, 0, 0);
    wcd9378_mbhc_get_result_params(v12, a5, a2[1], &v14);
    result = regmap_update_bits_base(*(_QWORD *)(v12 + 48), 1075314710, 128, 0, 0, 0, 0);
    *a3 = v14;
  }
  if ( a4 )
  {
    regmap_update_bits_base(*(_QWORD *)(v12 + 48), 1075314710, 64, 64, 0, 0, 0);
    wcd9378_mbhc_get_result_params(v12, a5, a2[1], &v14);
    result = regmap_update_bits_base(*(_QWORD *)(v12 + 48), 1075314710, 64, 0, 0, 0, 0);
    *a4 = v14;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
