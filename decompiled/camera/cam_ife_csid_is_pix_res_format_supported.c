__int64 __fastcall cam_ife_csid_is_pix_res_format_supported(unsigned int a1)
{
  unsigned int v1; // w8

  if ( ((1LL << a1) & 0x440047E0000FELL) != 0 )
    v1 = 0;
  else
    v1 = -22;
  if ( a1 <= 0x32 )
    return v1;
  else
    return 4294967274LL;
}
