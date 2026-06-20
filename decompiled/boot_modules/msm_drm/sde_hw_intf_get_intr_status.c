__int64 __fastcall sde_hw_intf_get_intr_status(__int64 a1)
{
  if ( a1 )
    return sde_reg_read(a1, 452);
  else
    return 4294967274LL;
}
