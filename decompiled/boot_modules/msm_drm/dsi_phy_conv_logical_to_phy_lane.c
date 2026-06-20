__int64 __fastcall dsi_phy_conv_logical_to_phy_lane(__int64 a1, unsigned int a2)
{
  if ( a2 > 4 )
    return 4294967274LL;
  if ( a2 == 4 )
  {
    __break(0x5512u);
    JUMPOUT(0x1B9CFC);
  }
  if ( (unsigned __int8)(*(_BYTE *)(a1 + a2 + 4) - 1) >= 8u )
    return 4;
  else
    return dword_29D340[(unsigned __int8)(*(_BYTE *)(a1 + a2 + 4) - 1)];
}
