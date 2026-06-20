__int64 __fastcall sde_power_mmrm_reserve(__int64 result)
{
  int v1; // w23
  __int64 v2; // x19
  unsigned __int64 v3; // x20
  __int64 v4; // x22
  int v5; // w8
  __int64 v6; // x25
  __int64 v7; // x21
  __int64 v8; // x1
  unsigned __int64 v9; // x8
  __int64 v10; // x9
  unsigned __int64 v11; // x10
  unsigned __int64 v12; // x8

  if ( *(_BYTE *)(result + 377) == 1 )
  {
    v1 = *(_DWORD *)(result + 32);
    v2 = result;
    if ( v1 )
    {
      v3 = *(_QWORD *)(result + 456);
      v4 = *(_QWORD *)(result + 40);
      v5 = 0;
      while ( 1 )
      {
        v6 = v4 + 120LL * v5;
        v7 = v5;
        result = strcmp((const char *)(v6 + 8), (const char *)(v2 + 424));
        if ( !(_DWORD)result )
          break;
        v5 = v7 + 1;
        if ( v1 == (_DWORD)v7 + 1 )
          return result;
      }
      v9 = *(_QWORD *)(v6 + 56);
      v10 = 120 * v7;
      if ( v3 >= v9 )
        v11 = *(_QWORD *)(v6 + 56);
      else
        v11 = v3;
      if ( v9 )
        v12 = v11;
      else
        v12 = v3;
      _ReadStatusReg(SP_EL0);
      *(_QWORD *)(v4 + v10 + 48) = v12;
      *(_DWORD *)(*(_QWORD *)(v2 + 40) + v10 + 68) = 1;
      return msm_dss_single_clk_set_rate(*(_QWORD *)(v2 + 40) + 120LL * (int)v7, v8);
    }
  }
  return result;
}
