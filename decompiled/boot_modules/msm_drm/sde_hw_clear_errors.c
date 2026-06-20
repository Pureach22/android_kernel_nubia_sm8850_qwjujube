__int64 __fastcall sde_hw_clear_errors(__int64 result, unsigned int *a2, _DWORD *a3)
{
  __int64 v5; // x19
  unsigned int v6; // w21
  int v7; // w0

  if ( result )
  {
    v5 = result;
    v6 = sde_reg_read(result, 0x190u);
    v7 = sde_reg_read(v5, 0x194u);
    if ( a2 )
      *a2 = v6;
    if ( a3 )
      *a3 = v7;
    return sde_reg_write(v5, 0x19Cu, v7 | v6, "VBIF_XIN_CLR_ERR");
  }
  return result;
}
