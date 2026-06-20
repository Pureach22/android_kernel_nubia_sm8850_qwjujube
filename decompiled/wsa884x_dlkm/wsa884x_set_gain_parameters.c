__int64 __fastcall wsa884x_set_gain_parameters(__int64 a1)
{
  __int64 v2; // x20
  int v3; // w8
  __int64 *v5; // x8
  __int64 v6; // x9
  unsigned int v7; // w8
  __int64 *v8; // x9
  __int64 v9; // x10
  unsigned __int64 v10; // x8
  __int64 v11; // x9
  int v12; // w21
  __int64 v13; // x0
  __int64 v14; // x2
  __int64 v15; // x3
  unsigned __int64 v16; // x8

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  v3 = *(_DWORD *)(v2 + 228);
  if ( v3 <= 2 )
  {
    if ( !v3 )
    {
      v5 = (__int64 *)(v2 + 260);
      *(_DWORD *)(v2 + 120) = 0;
      v6 = 0x900000006LL;
      goto LABEL_18;
    }
    if ( v3 != 1 )
      goto LABEL_16;
    goto LABEL_12;
  }
  if ( v3 != 3 && v3 != 6 )
  {
    if ( v3 != 4 )
    {
LABEL_16:
      *(_DWORD *)(v2 + 120) = 0;
      v5 = (__int64 *)(v2 + 260);
      v6 = 0x70000000ELL;
      goto LABEL_18;
    }
LABEL_12:
    v7 = *(unsigned __int8 *)(v2 + 236);
    if ( v7 > 1 )
    {
      if ( v7 == 2 )
      {
        v8 = (__int64 *)(v2 + 260);
        v9 = 0x500000010LL;
        goto LABEL_24;
      }
      if ( v7 == 3 )
      {
        v8 = (__int64 *)(v2 + 260);
        v9 = 0x400000011LL;
        goto LABEL_24;
      }
LABEL_22:
      v7 = 4;
      v8 = (__int64 *)(v2 + 260);
      v9 = 0x300000012LL;
      goto LABEL_24;
    }
    if ( *(_BYTE *)(v2 + 236) )
    {
      if ( v7 == 1 )
      {
        v8 = (__int64 *)(v2 + 260);
        v9 = 0x60000000FLL;
LABEL_24:
        *(_DWORD *)(v2 + 120) = v7;
        *v8 = v9;
        goto LABEL_25;
      }
      goto LABEL_22;
    }
    goto LABEL_16;
  }
  *(_DWORD *)(v2 + 120) = 0;
  v5 = (__int64 *)(v2 + 260);
  v6 = 0x800000009LL;
LABEL_18:
  *v5 = v6;
LABEL_25:
  v10 = *(unsigned __int8 *)(v2 + 236);
  if ( v10 >= 0x13 || (v11 = *(unsigned int *)(v2 + 232), (unsigned int)v11 > 3) )
  {
LABEL_33:
    __break(0x5512u);
    goto LABEL_34;
  }
  if ( (v11 | (4 * v10)) <= 0x4B )
  {
    v12 = vsense_gain_data[v10];
    snd_soc_component_update_bits(a1, 12321, 224, 32 * (unsigned int)isense_gain_data[4 * v10 + v11]);
    snd_soc_component_update_bits(a1, 12320, 224, (unsigned int)(32 * v12));
    snd_soc_component_update_bits(a1, 13497, 31, *(unsigned int *)(v2 + 260));
    if ( *(_BYTE *)(v2 + 32) == 1 )
    {
      snd_soc_component_update_bits(a1, 13488, 7, *(unsigned int *)(v2 + 120));
      v13 = a1;
      v14 = 1;
      v15 = 0;
      return snd_soc_component_update_bits(v13, 13489, v14, v15);
    }
    v16 = *(unsigned __int8 *)(v2 + 224);
    if ( v16 <= 0x12 )
    {
      *(_DWORD *)(v2 + 264) = pa_aux_no_comp[v16];
      snd_soc_component_update_bits(a1, 13489, 1, 1);
      v13 = a1;
      v14 = 62;
      v15 = 2 * (unsigned int)*(unsigned __int8 *)(v2 + 224);
      return snd_soc_component_update_bits(v13, 13489, v14, v15);
    }
    goto LABEL_33;
  }
LABEL_34:
  __break(1u);
  return wsa884x_set_pbr_parameters();
}
