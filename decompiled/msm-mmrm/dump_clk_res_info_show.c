__int64 __fastcall dump_clk_res_info_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x21
  int v5; // w0
  int v6; // w22
  bool v7; // cc
  _DWORD *v8; // x23
  __int64 v9; // x19
  unsigned int v10; // w24
  int v11; // w0

  v4 = drv_data;
  v5 = scnprintf(a3, 4096, "threshold: %d\n", *(_DWORD *)(drv_data + 88));
  v6 = 4096 - v5;
  if ( *(_DWORD *)(v4 + 80) )
    v7 = v6 < 2;
  else
    v7 = 1;
  if ( !v7 )
  {
    v8 = *(_DWORD **)(v4 + 72);
    v9 = a3 + v5;
    v10 = 1;
    do
    {
      v11 = scnprintf(v9, (unsigned int)v6, "%d\t%d\t% 8d\t%d\t%d\n", *v8, v8[1], v8[2], v8[3], v8[4]);
      v6 -= v11;
      if ( v10 >= *(_DWORD *)(v4 + 80) )
        break;
      v9 += v11;
      v8 += 5;
      ++v10;
    }
    while ( v6 > 1 );
  }
  return 4096LL - v6;
}
