__int64 __fastcall dsi_phy_reset_clk_en_sel(__int64 result)
{
  __int64 v1; // x8
  __int64 (__fastcall *v2)(_QWORD); // x8
  __int64 v3; // x0

  if ( result )
  {
    v1 = *(unsigned int *)(result + 776);
    if ( (unsigned int)v1 >= 3 )
    {
      __break(0x5512u);
      JUMPOUT(0x1B9004);
    }
    v2 = *(__int64 (__fastcall **)(_QWORD))(result + 8 * v1 + 408);
    if ( v2 )
    {
      v3 = result + 88;
      if ( *((_DWORD *)v2 - 1) != 2045579128 )
        __break(0x8228u);
      return v2(v3);
    }
  }
  return result;
}
