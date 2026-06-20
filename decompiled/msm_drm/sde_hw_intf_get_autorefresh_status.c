__int64 __fastcall sde_hw_intf_get_autorefresh_status(__int64 a1)
{
  return sde_reg_read(a1, 704);
}
