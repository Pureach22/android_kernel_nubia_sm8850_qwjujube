__int64 __fastcall reg_get_opclass_for_cur_hwmode(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        int a4,
        char a5,
        unsigned int a6,
        char a7,
        unsigned int a8)
{
  char *v11; // x28
  unsigned __int64 v12; // x19
  unsigned __int16 bw_value; // w0
  unsigned __int8 v14; // w26
  unsigned __int64 v15; // x21
  __int64 v16; // x25
  unsigned __int8 *v17; // x3
  unsigned int v18; // w8
  unsigned int v19; // w9
  __int64 v20; // x1
  int v21; // w23
  char *v22; // x27
  char max_tx_power; // [xsp+Ch] [xbp-34h]
  __int64 v26; // [xsp+10h] [xbp-30h]
  unsigned __int16 v28; // [xsp+20h] [xbp-20h]
  _BYTE v31[4]; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+38h] [xbp-8h]

  v11 = &global_op_class;
  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a5 & 1) != 0 )
  {
    v12 = 2496;
  }
  else if ( (_UNKNOWN *)channel_map == &channel_map_us )
  {
    v11 = &us_op_class;
    v12 = 1920;
  }
  else if ( (_UNKNOWN *)channel_map == &channel_map_eu )
  {
    v11 = &euro_op_class;
    v12 = 1632;
  }
  else if ( (_UNKNOWN *)channel_map == &channel_map_china )
  {
    v11 = &china_op_class;
    v12 = 1344;
  }
  else
  {
    if ( (_UNKNOWN *)channel_map == &channel_map_jp )
      v12 = 1440;
    else
      v12 = 2496;
    if ( (_UNKNOWN *)channel_map == &channel_map_jp )
      v11 = &japan_op_class;
  }
  max_tx_power = reg_get_max_tx_power(a1);
  bw_value = reg_get_bw_value(a6);
  v14 = 0;
  v28 = bw_value;
  if ( *v11 && (_BYTE)a4 )
  {
    v14 = 0;
    v15 = 0;
    v26 = a2;
    while ( 1 )
    {
      v16 = a2 + 156LL * v14;
      v31[0] = 0;
      qdf_mem_set((void *)(v16 + 13), 0x46u, 0);
      *(_BYTE *)(v16 + 11) = 0;
      qdf_mem_set((void *)(v16 + 83), 0x46u, 0);
      *(_BYTE *)(v16 + 12) = 0;
      if ( v12 < v15 + 2 )
LABEL_45:
        __break(1u);
      v17 = (unsigned __int8 *)&v11[v15];
      v18 = *(unsigned __int16 *)&v11[v15 + 2];
      if ( v18 <= 0x27 )
      {
        v19 = 20;
        if ( v18 == 20 || v18 == 25 )
          goto LABEL_28;
      }
      else
      {
        if ( v18 == 160 || v18 == 80 )
        {
          v19 = *(unsigned __int16 *)&v11[v15 + 2];
LABEL_28:
          if ( v19 > v28 )
            goto LABEL_32;
          goto LABEL_29;
        }
        v19 = *(unsigned __int16 *)&v11[v15 + 2];
        if ( v18 == 40 )
          goto LABEL_28;
      }
LABEL_29:
      if ( v12 < v15 + 8 )
        goto LABEL_45;
      if ( *(_WORD *)&v11[v15 + 8] != 8 || (a7 & 1) != 0 )
      {
        v20 = a2;
        v21 = a4;
        v22 = &v11[v15];
        reg_get_channels_from_opclassmap(a1, v20, v14, v17, v31, 1, a8);
        if ( v31[0] == 1 )
        {
          if ( v12 <= v15 )
            goto LABEL_45;
          *(_BYTE *)v16 = *v22;
          if ( v12 < v15 + 2 )
            goto LABEL_45;
          *(_WORD *)(v16 + 2) = *((_WORD *)v22 + 1);
          if ( v12 < v15 + 12 )
            goto LABEL_45;
          *(_DWORD *)(v16 + 4) = *(_DWORD *)&v11[v15 + 12];
          *(_BYTE *)(v16 + 10) = max_tx_power;
          if ( v12 < v15 + 8 )
            goto LABEL_45;
          a4 = v21;
          ++v14;
          *(_WORD *)(v16 + 8) = *(_WORD *)&v11[v15 + 8];
        }
        else
        {
          a4 = v21;
        }
        a2 = v26;
        goto LABEL_41;
      }
LABEL_32:
      reg_get_channels_from_opclassmap(a1, a2, v14, v17, v31, 2, a8);
LABEL_41:
      if ( v12 <= v15 + 96 )
        goto LABEL_45;
      if ( v11[v15 + 96] )
      {
        v15 += 96LL;
        if ( v14 < (unsigned int)(unsigned __int8)a4 )
          continue;
      }
      break;
    }
  }
  *a3 = v14;
  _ReadStatusReg(SP_EL0);
  return 0;
}
