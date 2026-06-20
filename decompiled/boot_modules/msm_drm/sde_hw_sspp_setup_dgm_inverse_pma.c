__int64 __fastcall sde_hw_sspp_setup_dgm_inverse_pma(__int64 result, int a2, int a3)
{
  __int64 v3; // x9
  __int64 v5; // x21
  unsigned int v6; // w20
  unsigned int v7; // w8
  unsigned int v8; // w2

  if ( result )
  {
    v3 = 1216;
    v5 = result;
    if ( a2 == 2 )
      v3 = 1220;
    v6 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + v3);
    v7 = sde_reg_read(result, v6) & 0xFFFFFFFE;
    if ( a3 )
      v8 = v7 + 1;
    else
      v8 = v7;
    return sde_reg_write(v5, v6, v8, "offset");
  }
  return result;
}
