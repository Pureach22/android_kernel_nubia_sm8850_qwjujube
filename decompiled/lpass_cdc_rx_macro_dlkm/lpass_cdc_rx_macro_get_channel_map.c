__int64 __fastcall lpass_cdc_rx_macro_get_channel_map(__int64 a1, int *a2, int *a3, _DWORD *a4, _DWORD *a5)
{
  __int64 v10; // x24
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x10
  unsigned __int64 v14; // x9
  unsigned __int64 v15; // x11
  unsigned __int64 v16; // x10
  __int64 v17; // x9
  __int64 result; // x0
  char v19; // w0
  int v20; // w8
  int v21; // w9
  _BOOL4 v22; // w19
  _BOOL4 v23; // w20
  char v24; // w8
  bool v25; // zf
  int v26; // w8
  int v27; // w9
  __int64 v28; // [xsp+8h] [xbp-18h] BYREF
  __int64 v29[2]; // [xsp+10h] [xbp-10h] BYREF

  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 96);
  v28 = 0;
  v29[0] = 0;
  if ( (lpass_cdc_rx_macro_get_data(v10, v29, &v28, (__int64)"lpass_cdc_rx_macro_get_channel_map") & 1) == 0 )
  {
    result = 4294967274LL;
    goto LABEL_15;
  }
  v11 = *(unsigned int *)(a1 + 8);
  if ( (int)v11 > 4 )
  {
    if ( (_DWORD)v11 == 5 )
    {
      v19 = snd_soc_component_read(v10, 4504);
      if ( (v19 & 0xF0) != 0 )
        v20 = 3;
      else
        v20 = 2;
      if ( (v19 & 0xF0) != 0 )
        v21 = 2;
      else
        v21 = 1;
      if ( (v19 & 0xF) != 0 )
        v22 = v20;
      else
        v22 = (v19 & 0xF0) != 0;
      if ( (v19 & 0xF) != 0 )
        v23 = v21;
      else
        v23 = (v19 & 0xF0) != 0;
      v24 = snd_soc_component_read(v10, 4508);
      result = 0;
      v25 = (v24 & 0xF) == 0;
      if ( (v24 & 0xF) != 0 )
        v26 = v22 | 4;
      else
        v26 = v22;
      if ( v25 )
        v27 = v23;
      else
        v27 = v23 + 1;
      *a3 = v26;
      *a2 = v27;
      goto LABEL_15;
    }
    if ( (_DWORD)v11 == 6 || (_DWORD)v11 == 7 )
    {
      result = 0;
      *a5 = 1;
      *a4 = 1;
      goto LABEL_15;
    }
LABEL_39:
    result = __ratelimit(&lpass_cdc_rx_macro_get_channel_map__rs, "lpass_cdc_rx_macro_get_channel_map");
    if ( (_DWORD)result )
    {
      dev_err(v29[0], "%s: Invalid AIF\n", "lpass_cdc_rx_macro_get_channel_map");
      result = 0;
    }
    goto LABEL_15;
  }
  if ( (unsigned int)(v11 - 1) >= 4 )
    goto LABEL_39;
  v12 = v28;
  v13 = *(_QWORD *)(v28 + 8 * v11 + 312);
  v14 = v13 & 0x3F;
  if ( (v13 & 0x3F) != 0 )
  {
    v15 = __clz(__rbit64(v14));
    LODWORD(v14) = 1 << v15;
    if ( v15 < 5 )
    {
      v16 = (unsigned __int8)(-2LL << v15) & (unsigned __int8)v13 & 0x3E;
      if ( v16 )
        LODWORD(v14) = (1 << __clz(__rbit64(v16))) | v14;
    }
  }
  if ( (v14 & 0xC) != 0 )
    LODWORD(v14) = (unsigned int)v14 >> 2;
  if ( (v14 & 0x30) != 0 )
    LODWORD(v14) = 1;
  *a5 = v14;
  v17 = *(unsigned int *)(a1 + 8);
  if ( (unsigned int)v17 <= 7 )
  {
    result = 0;
    *a4 = *(_QWORD *)(v12 + 8 * v17 + 376);
LABEL_15:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return lpass_cdc_rx_macro_hw_params();
}
