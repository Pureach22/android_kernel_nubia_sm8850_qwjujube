__int64 __fastcall swr_dmic_port_enable(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x8
  unsigned __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 result; // x0
  _BYTE v8[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v9[4]; // [xsp+10h] [xbp-10h] BYREF
  char v10[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 40);
  v4 = *(unsigned __int8 *)(a1 + 76);
  v10[0] = 1;
  v5 = *(_QWORD *)(v3 - 184);
  v9[0] = v4;
  v6 = *(_QWORD *)(v5 + 152);
  if ( v4 >= 2 )
    __break(0x5512u);
  v8[0] = *(_BYTE *)(v6 + v4 + 72);
  if ( a3 == 4 )
  {
    result = swr_disconnect_port(*(_QWORD *)(v6 + 8), v9, 1, v10, v8);
  }
  else if ( a3 == 2 )
  {
    result = swr_slvdev_datapath_control(*(_QWORD *)(v6 + 8), *(unsigned __int8 *)(*(_QWORD *)(v6 + 8) + 64LL), 1);
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
