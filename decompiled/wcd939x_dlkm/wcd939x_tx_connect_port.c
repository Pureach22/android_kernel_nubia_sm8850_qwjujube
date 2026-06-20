__int64 __fastcall wcd939x_tx_connect_port(__int64 a1, __int64 a2, int a3, char a4)
{
  char v6; // w20
  __int64 v7; // x8
  __int64 v8; // x22
  __int64 result; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x5
  __int64 v15; // x6
  __int64 v16; // x7
  unsigned __int64 v17; // x8
  __int64 v18; // x0
  int v19; // [xsp+4h] [xbp-1Ch] BYREF
  _BYTE v20[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v21[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v22[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v23[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a2;
  v7 = *(_QWORD *)(a1 + 24);
  v23[0] = 0;
  v22[0] = 0;
  v8 = *(_QWORD *)(v7 + 152);
  v21[0] = 0;
  v20[0] = 0;
  v19 = 0;
  result = wcd939x_set_port_params(a1, a2, v23, v22, v21, &v19, v20, 0);
  if ( (_DWORD)result )
    goto LABEL_10;
  if ( a3 )
    v19 = a3;
  if ( (unsigned __int8)(v6 - 29) > 0xCu )
  {
LABEL_7:
    v18 = *(_QWORD *)(v8 + 48);
    if ( a4 )
      result = swr_connect_port(v18, v23, 1, v21, &v19, v22, v20);
    else
      result = swr_disconnect_port(v18, v23, 1, v21, v20);
LABEL_10:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v17 = *((unsigned __int8 *)*(&off_26840 + (unsigned __int8)(v6 - 29)) + 1);
  if ( v17 < 0xD )
  {
    v20[0] = *(_BYTE *)(v8 + v17 + 3217);
    goto LABEL_7;
  }
  __break(0x5512u);
  return wcd939x_set_port_params(result, v10, v11, v12, v13, v14, v15, v16);
}
