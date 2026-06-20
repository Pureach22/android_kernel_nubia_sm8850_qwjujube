__int64 __fastcall lpass_cdc_wsa2_macro_get_channel_map(__int64 a1, int *a2, int *a3, _DWORD *a4, int *a5)
{
  __int64 v5; // x23
  __int64 device_ptr; // x0
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x11
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x12
  unsigned int v17; // w9
  unsigned __int64 v18; // x11
  __int64 result; // x0
  __int64 v20; // x9
  unsigned __int64 v21; // x10
  unsigned __int64 v22; // x10
  int v23; // w12
  bool v24; // zf
  __int16 v25; // w9
  __int64 v26; // x9
  char v27; // w8
  _BOOL4 v28; // w10
  int v29; // w9
  _BOOL4 v30; // w8
  int v31; // w9
  unsigned __int16 v32; // w8

  v5 = *(_QWORD *)(a1 + 96);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v5 + 24), 4);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs, "lpass_cdc_wsa2_macro_get_data") )
      dev_err(*(_QWORD *)(v5 + 24), "%s: null device for macro!\n", "lpass_cdc_wsa2_macro_get_channel_map");
    return 4294967274LL;
  }
  v12 = *(_QWORD *)(device_ptr + 152);
  if ( !v12 || !*(_QWORD *)(v12 + 248) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs_120, "lpass_cdc_wsa2_macro_get_data") )
      dev_err(*(_QWORD *)(v5 + 24), "%s: priv is null for macro!\n", "lpass_cdc_wsa2_macro_get_channel_map");
    return 4294967274LL;
  }
  v13 = *(unsigned int *)(a1 + 8);
  if ( (int)v13 <= 3 )
  {
    switch ( (_DWORD)v13 )
    {
      case 1:
        goto LABEL_8;
      case 2:
        *a5 = 1;
        *a4 = 1;
        return 0;
      case 3:
LABEL_8:
        v14 = *(_QWORD *)(v12 + 8 * v13 + 264);
        v15 = v14 & 0x1FF;
        if ( (v14 & 0x1FF) != 0 )
        {
          v16 = __clz(__rbit64(v15));
          LODWORD(v15) = 1;
          v17 = (unsigned __int16)(1 << v16);
          if ( v16 < 8 )
          {
            v18 = (unsigned __int16)(-2LL << v16) & (unsigned __int16)v14 & 0x1FE;
            LODWORD(v15) = 1;
            if ( v18 )
            {
              LODWORD(v15) = 2;
              v17 = (unsigned __int16)((1 << v16) | (1 << __clz(__rbit64(v18))));
            }
          }
        }
        else
        {
          v17 = 0;
        }
        result = 0;
        if ( (v17 & 0x30) != 0 )
          v31 = v17 >> 4;
        else
          v31 = 4 * v17;
        *a5 = v31;
        *a4 = v15;
        return result;
    }
LABEL_50:
    dev_err(device_ptr, "%s: Invalid AIF\n", "lpass_cdc_wsa2_macro_get_channel_map");
    return 0;
  }
  if ( (_DWORD)v13 == 6 )
  {
    *a3 = *(_QWORD *)(v12 + 312);
    v26 = *(unsigned int *)(a1 + 8);
    if ( (unsigned int)v26 > 6 )
    {
      __break(0x5512u);
      return lpass_cdc_wsa2_macro_mute_stream();
    }
    else
    {
      *a2 = *(_QWORD *)(v12 + 8 * v26 + 320);
      return 0;
    }
  }
  if ( (_DWORD)v13 != 5 )
  {
    if ( (_DWORD)v13 == 4 )
    {
      v20 = *(_QWORD *)(v12 + 296);
      v21 = v20 & 3;
      if ( (v20 & 3) != 0 )
      {
        v22 = __clz(__rbit64(v21));
        v23 = 1 << v22;
        v24 = (v20 & 2) != 0 && v22 == 0;
        if ( v24 )
          LODWORD(v21) = 2;
        else
          LODWORD(v21) = 1;
        if ( v24 )
          v25 = 3;
        else
          v25 = v23;
      }
      else
      {
        v25 = 0;
      }
      result = 0;
      if ( *(_BYTE *)(v12 + 664) & 1 | (v25 == 0) )
        v32 = v25;
      else
        v32 = 4 * v25;
      *a3 = v32;
      *a2 = v21;
      return result;
    }
    goto LABEL_50;
  }
  v27 = snd_soc_component_read(v5, 16656);
  result = 0;
  v28 = (v27 & 0x18) != 0;
  if ( (v27 & 0x18) != 0 )
    v29 = 2;
  else
    v29 = 1;
  v24 = (v27 & 3) == 0;
  v30 = (v27 & 3) != 0;
  if ( v24 )
    v29 = v28;
  *a3 = v30 | (2 * v28);
  *a2 = v29;
  return result;
}
