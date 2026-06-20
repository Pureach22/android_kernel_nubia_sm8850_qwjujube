__int64 __fastcall wcd939x_enable_clsh(__int64 a1, __int64 a2, char a3)
{
  __int64 v4; // x8
  __int64 v5; // x20
  unsigned int v6; // w9
  bool v7; // cc
  int v8; // w9
  __int64 v10; // x0
  __int64 result; // x0
  int v12; // [xsp+4h] [xbp-1Ch] BYREF
  _BYTE v13[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v14[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v15[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v16[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 40);
  v5 = *(_QWORD *)(*(_QWORD *)(v4 - 184) + 152LL);
  v6 = *(_DWORD *)(v5 + 284);
  v7 = v6 > 5;
  v8 = (1 << v6) & 0x36;
  if ( !v7 && v8 != 0 )
  {
    v16[0] = 0;
    v15[0] = 0;
    v14[0] = 0;
    v13[0] = 0;
    v12 = 0;
    if ( !(unsigned int)wcd939x_set_port_params(v4 - 208, 18, v16, v15, v14, &v12, v13, 1) )
    {
      v10 = *(_QWORD *)(v5 + 40);
      if ( (a3 & 3) == 0 )
      {
        swr_disconnect_port(v10, v16, 1, v14, v13);
        if ( (a3 & 0xC) != 0 )
          goto LABEL_9;
LABEL_11:
        result = 0;
        goto LABEL_12;
      }
      swr_connect_port(v10, v16, 1, v14, &v12, v15, v13);
    }
  }
  if ( (a3 & 0xC) == 0 )
    goto LABEL_11;
LABEL_9:
  result = swr_slvdev_datapath_control(*(_QWORD *)(v5 + 40), *(unsigned __int8 *)(*(_QWORD *)(v5 + 40) + 64LL), 0);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
