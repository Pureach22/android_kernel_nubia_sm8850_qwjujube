__int64 __fastcall wcd939x_enable_rx1(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x21
  __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x8
  int v11; // [xsp+4h] [xbp-1Ch] BYREF
  _BYTE v12[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v13[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v14[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v15[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 40);
  v4 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
  if ( a3 == 8 )
  {
    if ( *(_BYTE *)(v4 + 280) )
    {
      v15[0] = 0;
      v13[0] = 0;
      v12[0] = 0;
      v7 = v3 - 208;
      v8 = 59;
    }
    else
    {
      v15[0] = 0;
      v13[0] = 0;
      v12[0] = 0;
      if ( !(unsigned int)wcd939x_set_port_params(v3 - 208, 14, v15, v14, v13, &v11, v12, 1) )
        swr_disconnect_port(*(_QWORD *)(v4 + 40), v15, 1, v13, v12);
      if ( *(_BYTE *)(v4 + 308) != 1 )
        goto LABEL_19;
      v4 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
      v7 = v3 - 208;
      v8 = 16;
      v15[0] = 0;
      v13[0] = 0;
      v12[0] = 0;
    }
    if ( !(unsigned int)wcd939x_set_port_params(v7, v8, v15, v14, v13, &v11, v12, 1) )
      swr_disconnect_port(*(_QWORD *)(v4 + 40), v15, 1, v13, v12);
    goto LABEL_19;
  }
  if ( a3 != 1 )
    goto LABEL_19;
  if ( *(_BYTE *)(v4 + 280) )
  {
    v5 = v3 - 208;
    v6 = 59;
    v15[0] = 0;
    v14[0] = 0;
    v13[0] = 0;
    v12[0] = 0;
    v11 = 0;
    goto LABEL_11;
  }
  v15[0] = 0;
  v14[0] = 0;
  v13[0] = 0;
  v12[0] = 0;
  v11 = 0;
  if ( !(unsigned int)wcd939x_set_port_params(v3 - 208, 14, v15, v14, v13, &v11, v12, 1) )
    swr_connect_port(*(_QWORD *)(v4 + 40), v15, 1, v13, &v11, v14, v12);
  if ( *(_BYTE *)(v4 + 308) == 1 )
  {
    v9 = *(_QWORD *)(v3 - 184);
    v15[0] = 0;
    v14[0] = 0;
    v4 = *(_QWORD *)(v9 + 152);
    v13[0] = 0;
    v12[0] = 0;
    v5 = v3 - 208;
    v11 = 0;
    v6 = 16;
LABEL_11:
    if ( !(unsigned int)wcd939x_set_port_params(v5, v6, v15, v14, v13, &v11, v12, 1) )
      swr_connect_port(*(_QWORD *)(v4 + 40), v15, 1, v13, &v11, v14, v12);
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return 0;
}
