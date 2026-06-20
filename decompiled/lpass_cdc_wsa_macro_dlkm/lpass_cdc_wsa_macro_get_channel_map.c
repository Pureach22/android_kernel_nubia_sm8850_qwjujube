__int64 __fastcall lpass_cdc_wsa_macro_get_channel_map(__int64 a1, _DWORD *a2, int *a3, _DWORD *a4, unsigned int *a5)
{
  __int64 v5; // x23
  __int64 device_ptr; // x0
  _QWORD *v12; // x8
  __int64 v13; // x9
  char v14; // w8
  __int64 result; // x0
  _BOOL4 v16; // w10
  unsigned __int64 v17; // x9
  _BOOL4 v18; // w8
  int v19; // w8
  __int64 v20; // x9
  __int64 v21; // x11
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x12
  unsigned int v24; // w9
  unsigned __int64 v25; // x11
  __int64 v26; // x9
  __int64 v27; // x19
  __int64 v28; // x8
  unsigned __int64 v29; // x9
  int v30; // w11
  bool v31; // zf

  v5 = *(_QWORD *)(a1 + 96);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v5 + 24), 2);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(v5 + 24), "%s: null device for macro!\n", "lpass_cdc_wsa_macro_get_channel_map");
    return 4294967274LL;
  }
  v12 = *(_QWORD **)(device_ptr + 152);
  if ( !v12 || !v12[45] )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs_122, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(v5 + 24), "%s: priv is null for macro!\n", "lpass_cdc_wsa_macro_get_channel_map");
    return 4294967274LL;
  }
  v13 = *(unsigned int *)(a1 + 8);
  if ( (int)v13 > 4 )
  {
    switch ( (_DWORD)v13 )
    {
      case 5:
        *a3 = v12[52];
        v26 = *(unsigned int *)(a1 + 8);
        if ( (unsigned int)v26 <= 7 )
        {
          *a2 = v12[v26 + 55];
          return 0;
        }
        break;
      case 6:
        *a5 = 1;
        *a4 = 1;
        return 0;
      case 7:
        *a5 = v12[54];
        v20 = *(unsigned int *)(a1 + 8);
        if ( (unsigned int)v20 <= 7 )
        {
          *a4 = v12[v20 + 55];
          return 0;
        }
        break;
      default:
LABEL_32:
        v27 = device_ptr;
        result = __ratelimit(&lpass_cdc_wsa_macro_get_channel_map__rs, "lpass_cdc_wsa_macro_get_channel_map");
        if ( (_DWORD)result )
        {
          dev_err(v27, "%s: Invalid AIF\n", "lpass_cdc_wsa_macro_get_channel_map");
          return 0;
        }
        return result;
    }
    __break(0x5512u);
    return lpass_cdc_wsa_macro_mute_stream();
  }
  if ( (unsigned int)(v13 - 1) >= 2 )
  {
    if ( (_DWORD)v13 == 3 )
    {
      v28 = v12[50];
      v17 = v28 & 3;
      if ( (v28 & 3) != 0 )
      {
        v29 = __clz(__rbit64(v17));
        v30 = 1 << v29;
        v31 = (v28 & 2) != 0 && v29 == 0;
        if ( v31 )
          LODWORD(v17) = 2;
        else
          LODWORD(v17) = 1;
        if ( v31 )
          v19 = 3;
        else
          v19 = v30;
      }
      else
      {
        v19 = 0;
      }
      result = 0;
      goto LABEL_51;
    }
    if ( (_DWORD)v13 == 4 )
    {
      v14 = snd_soc_component_read(v5, 8464);
      result = 0;
      v16 = (v14 & 0x18) != 0;
      if ( (v14 & 0x18) != 0 )
        LODWORD(v17) = 2;
      else
        LODWORD(v17) = 1;
      v31 = (v14 & 3) == 0;
      v18 = (v14 & 3) != 0;
      if ( v31 )
        LODWORD(v17) = v16;
      v19 = v18 | (2 * v16);
LABEL_51:
      *a3 = v19;
      *a2 = v17;
      return result;
    }
    goto LABEL_32;
  }
  v21 = v12[v13 + 47];
  v22 = v21 & 0x1FF;
  if ( (v21 & 0x1FF) != 0 )
  {
    v23 = __clz(__rbit64(v22));
    LODWORD(v22) = 1;
    v24 = (unsigned __int16)(1 << v23);
    if ( v23 < 8 )
    {
      v25 = (unsigned __int16)(-2LL << v23) & (unsigned __int16)v21 & 0x1FE;
      LODWORD(v22) = 1;
      if ( v25 )
      {
        LODWORD(v22) = 2;
        v24 = (unsigned __int16)((1 << v23) | (1 << __clz(__rbit64(v25))));
      }
    }
  }
  else
  {
    v24 = 0;
  }
  result = 0;
  if ( (v24 & 0xC) != 0 )
    v24 >>= 2;
  *a5 = v24;
  *a4 = v22;
  return result;
}
