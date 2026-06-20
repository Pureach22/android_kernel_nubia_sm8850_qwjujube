__int64 __fastcall update_vsync_source(__int64 result, __int64 a2)
{
  unsigned int v2; // w9
  unsigned int v3; // w20
  unsigned int v4; // w8
  unsigned int v5; // w19
  __int64 v6; // x21
  int v7; // w0

  if ( result )
  {
    if ( a2 )
    {
      v2 = *(_DWORD *)(a2 + 64) - 11;
      if ( v2 <= 4 )
      {
        if ( v2 > 3 )
        {
          v5 = 900;
          v3 = 896;
          v4 = 904;
        }
        else
        {
          v3 = dword_29D24C[v2];
          v4 = dword_29D2DC[v2];
          v5 = dword_29D25C[v2];
        }
        v6 = result;
        sde_reg_write(result, v4, 0x124F800u / (16 * *(_DWORD *)(a2 + 4)), "wd_load_value");
        sde_reg_write(v6, v3, 1u, "wd_ctl");
        v7 = sde_reg_read(v6, v5);
        result = sde_reg_write(v6, v5, v7 | 0x101u, "wd_ctl2");
        __dsb(0xEu);
      }
    }
  }
  return result;
}
