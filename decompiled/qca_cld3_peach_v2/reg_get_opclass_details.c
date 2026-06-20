__int64 __fastcall reg_get_opclass_details(
        __int64 a1,
        __int64 a2,
        _BYTE *a3,
        unsigned __int8 a4,
        char a5,
        unsigned int a6)
{
  char *v10; // x26
  unsigned __int64 v11; // x27
  unsigned int v12; // w24
  unsigned __int64 v13; // x19
  __int64 v14; // x25
  char max_tx_power; // [xsp+10h] [xbp-10h]
  _BYTE v18[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+18h] [xbp-8h]

  v10 = &global_op_class;
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a5 & 1) != 0 )
  {
    v11 = 2592;
  }
  else if ( (_UNKNOWN *)channel_map == &channel_map_us )
  {
    v10 = &us_op_class;
    v11 = 1920;
  }
  else if ( (_UNKNOWN *)channel_map == &channel_map_eu )
  {
    v10 = &euro_op_class;
    v11 = 1632;
  }
  else if ( (_UNKNOWN *)channel_map == &channel_map_china )
  {
    v10 = &china_op_class;
    v11 = 1344;
  }
  else
  {
    if ( (_UNKNOWN *)channel_map == &channel_map_jp )
      v11 = 1440;
    else
      v11 = 2592;
    if ( (_UNKNOWN *)channel_map == &channel_map_jp )
      v10 = &japan_op_class;
  }
  LOBYTE(v12) = 0;
  max_tx_power = reg_get_max_tx_power(a1);
  if ( *v10 && a4 )
  {
    v12 = 0;
    v13 = 0;
    do
    {
      v14 = a2 + 156LL * (unsigned __int8)v12;
      v18[0] = 0;
      qdf_mem_set((void *)(v14 + 13), 0x46u, 0);
      *(_BYTE *)(v14 + 11) = 0;
      qdf_mem_set((void *)(v14 + 83), 0x46u, 0);
      *(_BYTE *)(v14 + 12) = 0;
      reg_get_channels_from_opclassmap(a1, a2, v12, &v10[v13], v18, 3, a6);
      if ( v18[0] == 1 )
      {
        if ( v11 <= v13
          || (*(_BYTE *)v14 = v10[v13], v11 < v13 + 2)
          || (*(_WORD *)(v14 + 2) = *(_WORD *)&v10[v13 + 2], v11 < v13 + 12)
          || (*(_DWORD *)(v14 + 4) = *(_DWORD *)&v10[v13 + 12], *(_BYTE *)(v14 + 10) = max_tx_power, v11 < v13 + 8) )
        {
LABEL_28:
          __break(1u);
        }
        ++v12;
        *(_WORD *)(v14 + 8) = *(_WORD *)&v10[v13 + 8];
      }
      if ( v11 <= v13 + 96 )
        goto LABEL_28;
      if ( !v10[v13 + 96] )
        break;
      v13 += 96LL;
    }
    while ( (unsigned __int8)v12 < (unsigned int)a4 );
  }
  *a3 = v12;
  _ReadStatusReg(SP_EL0);
  return 0;
}
