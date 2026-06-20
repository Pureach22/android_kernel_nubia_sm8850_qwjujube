__int64 __fastcall sde_hw_sspp_setup_sys_cache(__int64 result, __int64 a2)
{
  __int64 v3; // x21
  int v4; // w20
  unsigned int v5; // w0
  int v6; // w8
  unsigned int v7; // w2
  __int64 v8; // x0

  if ( result && a2 )
  {
    v3 = result;
    v4 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL);
    v5 = sde_reg_read(result, v4 + 444);
    v6 = *(_DWORD *)(a2 + 20);
    v7 = v5;
    if ( (v6 & 1) != 0 )
      v7 = v5 & 0xFFFF7FFF | ((*(_BYTE *)(a2 + 4) & 1) << 15);
    if ( (v6 & 2) != 0 )
    {
      v8 = v3;
      if ( **(_DWORD **)(v3 + 32) >> 30 == 3 )
      {
        v7 = v7 & 0xFFFFC0FF | ((*(_DWORD *)(a2 + 8) & 0x3F) << 8);
        if ( (v6 & 4) == 0 )
        {
LABEL_13:
          if ( (v6 & 8) != 0 )
          {
            v7 = v7 & 0xFFFFFFF0 | *(_DWORD *)(a2 + 16) & 0xF;
            if ( (v6 & 0x10) == 0 )
              return sde_reg_write(v8, v4 + 444, v7, "SSPP_SYS_CACHE_MODE + idx");
          }
          else if ( (v6 & 0x10) == 0 )
          {
            return sde_reg_write(v8, v4 + 444, v7, "SSPP_SYS_CACHE_MODE + idx");
          }
          v7 = v7 & 0xFFFFFFEF | (16 * (*(_BYTE *)(a2 + 12) & 1));
          return sde_reg_write(v8, v4 + 444, v7, "SSPP_SYS_CACHE_MODE + idx");
        }
      }
      else
      {
        v7 = v7 & 0xFFFFE0FF | ((*(_DWORD *)(a2 + 8) & 0x1F) << 8);
        if ( (v6 & 4) == 0 )
          goto LABEL_13;
      }
    }
    else
    {
      v8 = v3;
      if ( (v6 & 4) == 0 )
        goto LABEL_13;
    }
    v7 = v7 & 0xFFF3FFFF | ((*(_DWORD *)a2 & 3) << 18);
    goto LABEL_13;
  }
  return result;
}
