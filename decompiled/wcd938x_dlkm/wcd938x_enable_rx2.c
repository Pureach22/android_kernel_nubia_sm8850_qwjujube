__int64 __fastcall wcd938x_enable_rx2(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x20
  __int64 v4; // x19
  __int64 v5; // x21
  __int64 v6; // x20
  __int64 v7; // x20
  int v9; // [xsp+4h] [xbp-1Ch] BYREF
  _BYTE v10[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v11[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v12[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v13[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 40);
  v4 = v3 - 208;
  v5 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
  if ( a3 == 8 )
  {
    v13[0] = 0;
    v11[0] = 0;
    v10[0] = 0;
    if ( !(unsigned int)wcd938x_set_port_params(v3 - 208, 15, v13, v12, v11, &v9, v10, 1) )
      swr_disconnect_port(*(_QWORD *)(v5 + 40), v13, 1, v11, v10);
    if ( *(_BYTE *)(v5 + 289) == 1 )
    {
      v7 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
      v13[0] = 0;
      v11[0] = 0;
      v10[0] = 0;
      if ( !(unsigned int)wcd938x_set_port_params(v4, 17, v13, v12, v11, &v9, v10, 1) )
        swr_disconnect_port(*(_QWORD *)(v7 + 40), v13, 1, v11, v10);
    }
    wcd938x_rx_clk_disable(v4);
    snd_soc_component_update_bits(v4, 13321, 2, 0);
  }
  else if ( a3 == 1 )
  {
    v13[0] = 0;
    v12[0] = 0;
    v11[0] = 0;
    v10[0] = 0;
    v9 = 0;
    if ( !(unsigned int)wcd938x_set_port_params(v3 - 208, 15, v13, v12, v11, &v9, v10, 1) )
      swr_connect_port(*(_QWORD *)(v5 + 40), v13, 1, v11, &v9, v12, v10);
    if ( *(_BYTE *)(v5 + 289) == 1 )
    {
      v6 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
      v13[0] = 0;
      v12[0] = 0;
      v11[0] = 0;
      v10[0] = 0;
      v9 = 0;
      if ( !(unsigned int)wcd938x_set_port_params(v4, 17, v13, v12, v11, &v9, v10, 1) )
        swr_connect_port(*(_QWORD *)(v6 + 40), v13, 1, v11, &v9, v12, v10);
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
