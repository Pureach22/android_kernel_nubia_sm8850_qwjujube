__int64 __fastcall sde_hw_pp_get_vsync_info(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  unsigned int v5; // w0

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 )
    {
      a2[2] = (unsigned __int16)sde_reg_read(a1, 0x10u);
      v5 = sde_reg_read(a1, 0x14u);
      a2[3] = HIWORD(v5);
      a2[4] = (unsigned __int16)v5;
      a2[5] = (unsigned __int16)sde_reg_read(a1, 0x2Cu);
      return 0;
    }
  }
  return result;
}
