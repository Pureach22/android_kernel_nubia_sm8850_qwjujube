__int64 __fastcall sde_hw_sspp_setup_cdp(__int64 result, unsigned __int8 *a2, unsigned int a3)
{
  unsigned int v3; // w8
  unsigned int v4; // w9
  unsigned int v5; // w2

  if ( result && a2 )
  {
    if ( a3 >= 2 )
    {
      if ( a3 != 2 )
        return printk(&unk_27E748, "sde_hw_sspp_setup_cdp");
      v3 = 316;
    }
    else
    {
      v3 = 308;
    }
    v4 = *a2;
    if ( a2[1] )
      v4 |= 2u;
    if ( a2[2] )
      v4 |= 4u;
    if ( *((_DWORD *)a2 + 1) == 1 )
      v5 = v4 | 8;
    else
      v5 = v4;
    return sde_reg_write(result, v3, v5, "cdp_cntl_offset");
  }
  return result;
}
