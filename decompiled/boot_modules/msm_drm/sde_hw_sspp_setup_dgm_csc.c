__int64 __fastcall sde_hw_sspp_setup_dgm_csc(__int64 result, int a2, _DWORD *a3)
{
  __int64 v3; // x8
  __int64 v4; // x8
  unsigned int v5; // w19
  __int64 v6; // x20

  if ( result )
  {
    v3 = *(_QWORD *)(result + 56);
    if ( v3 )
    {
      v4 = *(_QWORD *)(v3 + 48);
      if ( v4 )
      {
        v5 = *(_DWORD *)(v4 + 36LL * (a2 == 2) + 480);
        if ( a3 )
        {
          v6 = result;
          sde_hw_csc_matrix_coeff_setup(result, v5 + 4, a3, 0);
          result = v6;
          LODWORD(a3) = 1;
        }
        return sde_reg_write(result, v5, (unsigned int)a3, "offset");
      }
    }
  }
  return result;
}
