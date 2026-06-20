__int64 __fastcall sde_hw_set_write_gather_en(__int64 result, unsigned int a2)
{
  char v2; // w19
  __int64 v3; // x20
  int v4; // w0

  if ( result )
  {
    v2 = a2;
    if ( a2 <= 0xF )
    {
      v3 = result;
      v4 = sde_reg_read(result, 0xACu);
      return sde_reg_write(v3, 0xACu, v4 | (unsigned int)(1LL << v2), "VBIF_WRITE_GATHER_EN");
    }
  }
  return result;
}
