__int64 __fastcall sde_hw_pp_update_te(__int64 result, __int64 a2)
{
  __int64 v3; // x20
  int v4; // w0

  if ( result )
  {
    if ( a2 )
    {
      v3 = result;
      v4 = sde_reg_read(result, 0x18u);
      return sde_reg_write(v3, 0x18u, v4 & 0xFFFF0000 | *(_DWORD *)(a2 + 12), "PP_SYNC_THRESH");
    }
  }
  return result;
}
