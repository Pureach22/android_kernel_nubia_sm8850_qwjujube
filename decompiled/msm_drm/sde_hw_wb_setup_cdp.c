__int64 __fastcall sde_hw_wb_setup_cdp(__int64 result, unsigned __int8 *a2)
{
  unsigned int v2; // w8
  unsigned int v3; // w2

  if ( result && a2 )
  {
    v2 = *a2;
    if ( a2[1] )
      v2 |= 2u;
    if ( *((_DWORD *)a2 + 1) == 1 )
      v3 = v2 | 8;
    else
      v3 = v2;
    return sde_reg_write(result, 0x2B4u, v3, "WB_CDP_CNTL");
  }
  return result;
}
