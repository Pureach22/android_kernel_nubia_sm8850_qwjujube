__int64 __fastcall wcd939x_enable_rx3(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x19
  __int64 v6; // x19
  int v8; // [xsp+4h] [xbp-1Ch] BYREF
  _BYTE v9[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v10[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v11[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v12[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 40);
  v4 = v3 - 208;
  if ( a3 == 8 )
  {
    v6 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
    v12[0] = 0;
    v10[0] = 0;
    v9[0] = 0;
    if ( !(unsigned int)wcd939x_set_port_params(v4, 19, v12, v11, v10, &v8, v9, 1) )
      swr_disconnect_port(*(_QWORD *)(v6 + 40), v12, 1, v10, v9);
    usleep_range_state(6000, 6010, 2);
  }
  else if ( a3 == 1 )
  {
    v5 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
    v12[0] = 0;
    v11[0] = 0;
    v10[0] = 0;
    v9[0] = 0;
    v8 = 0;
    if ( !(unsigned int)wcd939x_set_port_params(v4, 19, v12, v11, v10, &v8, v9, 1) )
      swr_connect_port(*(_QWORD *)(v5 + 40), v12, 1, v10, &v8, v11, v9);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
