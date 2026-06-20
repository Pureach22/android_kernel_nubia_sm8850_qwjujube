__int64 __fastcall dmic_swr_ctrl(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v4; // x19
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 result; // x0
  int v8; // w9
  _BYTE v9[4]; // [xsp+4h] [xbp-1Ch] BYREF
  _BYTE v10[4]; // [xsp+8h] [xbp-18h] BYREF
  int v11; // [xsp+Ch] [xbp-14h] BYREF
  char v12[4]; // [xsp+10h] [xbp-10h] BYREF
  char v13[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 40);
  v4 = *(unsigned __int8 *)(a1 + 76);
  v13[0] = 1;
  v12[0] = 1;
  v5 = *(_QWORD *)(v3 - 184);
  v9[0] = v4;
  v6 = *(_QWORD *)(v5 + 152);
  if ( (unsigned int)v4 < 2 )
  {
    if ( (_DWORD)v4 )
      v8 = 600000;
    else
      v8 = 2400000;
    v11 = v8;
    v10[0] = *(_BYTE *)(v6 + v4 + 72);
    if ( (_DWORD)a3 == 8 )
    {
      result = swr_slvdev_datapath_control(*(_QWORD *)(v6 + 8), *(unsigned __int8 *)(*(_QWORD *)(v6 + 8) + 64LL), 0);
    }
    else if ( (_DWORD)a3 == 1 )
    {
      result = swr_connect_port(*(_QWORD *)(v6 + 8), v9, a3, v12, &v11, v13, v10);
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&dmic_swr_ctrl__rs, "dmic_swr_ctrl") )
      dev_err(*(_QWORD *)(v3 - 184), "%s: invalid port id: %d\n", "dmic_swr_ctrl", v4);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
