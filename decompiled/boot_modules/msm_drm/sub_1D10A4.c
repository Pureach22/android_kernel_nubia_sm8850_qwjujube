__int64 sub_1D10A4()
{
  int v0; // w22

  if ( (v0 & 0x4000000) == 0 )
    JUMPOUT(0x1CA26C);
  return dsi_ctrl_get_io_resources();
}
