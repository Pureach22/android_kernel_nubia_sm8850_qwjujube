__int64 __fastcall lpass_cdc_wsa2_macro_enable_prim_interpolator(__int64 a1, unsigned __int16 a2, int a3)
{
  __int64 result; // x0
  __int64 v7; // x8
  unsigned int v8; // w20
  __int64 v9; // x9
  __int64 v10; // x8
  int v11; // w9
  int v12; // w10
  unsigned int v13; // w22
  int v14; // w8
  unsigned int v15; // w23
  __int64 v16; // x0
  __int64 v17; // x1
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x8
  unsigned int v22; // w10
  __int64 v23; // x1
  int v24; // w8
  unsigned int v25; // w20

  result = lpass_cdc_get_device_ptr(*(_QWORD *)(a1 + 24), 4);
  if ( result )
  {
    v7 = *(_QWORD *)(result + 152);
    if ( v7 && *(_QWORD *)(v7 + 248) )
    {
      v8 = 0;
      v9 = 0;
      if ( a2 > 0x447Fu )
      {
        if ( a2 == 17560 || a2 == 17536 )
        {
          v8 = 17536;
          v9 = 1;
        }
      }
      else if ( a2 == 17408 || a2 == 17432 )
      {
        v9 = 0;
        v8 = 17408;
      }
      if ( a3 == 8 )
      {
        v20 = v7 + 2 * v9;
        if ( --*(_WORD *)(v20 + 32) == 0 )
        {
          snd_soc_component_update_bits(a1, v8, 32, 0);
          snd_soc_component_update_bits(a1, v8 | 0x4C, 1, 0);
          snd_soc_component_update_bits(a1, v8, 64, 64);
          result = snd_soc_component_update_bits(a1, v8, 64, 0);
          v22 = v8 == 17408 ? 17412 : 0;
          v23 = v8 == 17536 ? 17540LL : v22;
          if ( (_DWORD)v23 )
          {
            if ( v8 == 17408 )
              v24 = 17456;
            else
              v24 = 0;
            if ( v8 == 17536 )
              v25 = 17584;
            else
              v25 = v24;
            snd_soc_component_update_bits(a1, v23, 4, 0);
            snd_soc_component_update_bits(a1, v25, 3, 0);
            v16 = a1;
            v17 = v25;
            v18 = 60;
            v19 = 0;
            return snd_soc_component_update_bits(v16, v17, v18, v19);
          }
        }
      }
      else if ( a3 == 1 )
      {
        v10 = v7 + 2 * v9;
        v11 = *(unsigned __int16 *)(v10 + 32);
        *(_WORD *)(v10 + 32) = v11 + 1;
        if ( !v11 )
        {
          snd_soc_component_update_bits(a1, v8 | 0x10, 3, 3);
          snd_soc_component_update_bits(a1, v8, 16, 16);
          if ( v8 == 17408 )
            v12 = 17412;
          else
            v12 = 0;
          if ( v8 == 17536 )
            v13 = 17540;
          else
            v13 = v12;
          if ( v13 )
          {
            if ( v8 == 17408 )
              v14 = 17456;
            else
              v14 = 0;
            if ( v8 == 17536 )
              v15 = 17584;
            else
              v15 = v14;
            snd_soc_component_update_bits(a1, v15, 60, 16);
            snd_soc_component_update_bits(a1, v15, 3, 1);
            snd_soc_component_update_bits(a1, v13, 4, 4);
          }
          result = snd_soc_component_update_bits(a1, v8 | 0x4C, 1, 1);
        }
        if ( v8 != a2 )
        {
          result = snd_soc_component_read(a1, v8);
          if ( (result & 0x10) != 0 )
          {
            v16 = a1;
            v17 = a2;
            v18 = 16;
            v19 = 16;
            return snd_soc_component_update_bits(v16, v17, v18, v19);
          }
        }
      }
    }
    else
    {
      result = __ratelimit(&lpass_cdc_wsa2_macro_get_data__rs_120, "lpass_cdc_wsa2_macro_get_data");
      if ( (_DWORD)result )
        return dev_err(
                 *(_QWORD *)(a1 + 24),
                 "%s: priv is null for macro!\n",
                 "lpass_cdc_wsa2_macro_enable_prim_interpolator");
    }
  }
  else
  {
    result = __ratelimit(&lpass_cdc_wsa2_macro_get_data__rs, "lpass_cdc_wsa2_macro_get_data");
    if ( (_DWORD)result )
      return dev_err(
               *(_QWORD *)(a1 + 24),
               "%s: null device for macro!\n",
               "lpass_cdc_wsa2_macro_enable_prim_interpolator");
  }
  return result;
}
