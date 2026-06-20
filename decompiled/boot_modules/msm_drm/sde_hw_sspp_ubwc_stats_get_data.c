__int64 __fastcall sde_hw_sspp_ubwc_stats_get_data(__int64 result, unsigned int a2, __int64 a3)
{
  __int64 v4; // x21
  int v5; // w9
  unsigned int v6; // w20
  int v7; // w0
  int v8; // w0
  int v9; // w0

  if ( result )
  {
    v4 = result;
    if ( a2 >= 2 )
      v5 = 184;
    else
      v5 = 128;
    v6 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL) + v5;
    v7 = sde_reg_read(result, v6);
    *(_WORD *)(a3 + 4) = v7;
    *(_WORD *)(a3 + 10) = HIWORD(v7);
    *(_DWORD *)(a3 + 16) = sde_reg_read(v4, v6 + 4);
    v8 = sde_reg_read(v4, v6 + 8);
    *(_WORD *)(a3 + 6) = v8;
    *(_WORD *)(a3 + 12) = HIWORD(v8);
    *(_DWORD *)(a3 + 20) = sde_reg_read(v4, v6 + 12);
    v9 = sde_reg_read(v4, v6 + 16);
    *(_WORD *)(a3 + 8) = v9;
    *(_WORD *)(a3 + 14) = HIWORD(v9);
    result = sde_reg_read(v4, v6 + 20);
    *(_DWORD *)(a3 + 24) = result;
  }
  return result;
}
