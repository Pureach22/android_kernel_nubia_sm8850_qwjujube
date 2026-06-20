__int64 __fastcall sde_hw_setup_cdm_output(__int64 result, _BYTE *a2)
{
  unsigned int v2; // w2

  if ( result && a2 )
  {
    if ( (*a2 & 1) != 0 )
    {
      v2 = 0x1000000;
    }
    else if ( a2[1] )
    {
      v2 = 0x80000;
    }
    else
    {
      v2 = 0;
    }
    return sde_reg_write(result, 0x410u, v2, "MDP_OUT_CTL_0");
  }
  return result;
}
