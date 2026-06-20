__int64 __fastcall dsi_ctrl_pixel_format_to_bpp(unsigned int a1)
{
  if ( a1 > 7 )
    return 24;
  else
    return (unsigned int)bits_per_pixel[a1];
}
