__int64 __fastcall sde_hw_get_demura_sw_fuse_value(__int64 result)
{
  unsigned int v1; // w1

  if ( result )
  {
    v1 = *(_DWORD *)(result + 32);
    if ( v1 )
      return sde_reg_read(result, v1);
    else
      return 0;
  }
  return result;
}
