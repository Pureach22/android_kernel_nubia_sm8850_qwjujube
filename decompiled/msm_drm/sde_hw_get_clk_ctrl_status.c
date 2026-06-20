__int64 __fastcall sde_hw_get_clk_ctrl_status(__int64 a1, unsigned int a2, _BYTE *a3)
{
  __int64 result; // x0
  __int64 v5; // x9
  unsigned int v6; // w1
  __int64 v7; // x9
  unsigned int v8; // t1
  int v9; // w19
  int v11; // w8

  result = 4294967274LL;
  if ( a1 && a2 - 20 >= 0xFFFFFFED )
  {
    v5 = *(_QWORD *)(a1 + 40) + 8LL * a2;
    v8 = *(_DWORD *)(v5 + 236);
    v7 = v5 + 236;
    v6 = v8;
    if ( v8 )
    {
      v9 = *(_DWORD *)(v7 + 4);
      v11 = sde_reg_read(a1, v6);
      *a3 = ((unsigned __int64)v11 >> v9) & 1;
      return 0;
    }
  }
  return result;
}
