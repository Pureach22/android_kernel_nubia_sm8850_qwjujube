__int64 __fastcall sde_hw_wb_setup_sys_cache(__int64 result, __int64 a2)
{
  int v2; // w8
  unsigned int v3; // w2

  if ( result && a2 )
  {
    v2 = *(_DWORD *)(a2 + 16);
    if ( (v2 & 1) != 0 )
    {
      if ( *(_BYTE *)a2 )
        v3 = 0x8000;
      else
        v3 = 0;
      if ( (v2 & 2) == 0 )
      {
LABEL_11:
        if ( (v2 & 8) != 0 )
        {
          v3 |= *(_DWORD *)(a2 + 12) & 0xF;
          if ( (v2 & 0x10) == 0 )
            return sde_reg_write(result, 0x94u, v3, "WB_SYS_CACHE_MODE");
        }
        else if ( (v2 & 0x10) == 0 )
        {
          return sde_reg_write(result, 0x94u, v3, "WB_SYS_CACHE_MODE");
        }
        v3 |= 16 * *(unsigned __int8 *)(a2 + 8);
        return sde_reg_write(result, 0x94u, v3, "WB_SYS_CACHE_MODE");
      }
    }
    else
    {
      v3 = 0;
      if ( (v2 & 2) == 0 )
        goto LABEL_11;
    }
    v3 |= (*(_DWORD *)(a2 + 4) & 0x1F) << 8;
    goto LABEL_11;
  }
  return result;
}
