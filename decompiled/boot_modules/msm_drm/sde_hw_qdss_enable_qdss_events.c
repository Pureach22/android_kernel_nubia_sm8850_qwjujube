__int64 __fastcall sde_hw_qdss_enable_qdss_events(__int64 result, char a2)
{
  unsigned int v2; // w2

  if ( result )
  {
    if ( (a2 & 1) != 0 )
      v2 = 256;
    else
      v2 = 0;
    return sde_reg_write(result, 0, v2, "QDSS_CONFIG");
  }
  return result;
}
