__int64 __fastcall sde_hw_sspp_setup_sys_cache_v1(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v5; // w0
  int v6; // w8
  unsigned int v7; // w2
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  result = sspp_subblk_offset(a1, 1, &v8);
  if ( a2 && !(_DWORD)result )
  {
    v5 = sde_reg_read(a1, v8 + 36);
    v6 = *(_DWORD *)(a2 + 20);
    v7 = v5;
    if ( (v6 & 1) != 0 )
    {
      v7 = v5 & 0xFFFF7FFF | ((*(_BYTE *)(a2 + 4) & 1) << 15);
      if ( (v6 & 2) == 0 )
      {
LABEL_5:
        if ( (v6 & 4) == 0 )
          goto LABEL_6;
        goto LABEL_13;
      }
    }
    else if ( (v6 & 2) == 0 )
    {
      goto LABEL_5;
    }
    v7 = v7 & 0xFFFFE0FF | ((*(_DWORD *)(a2 + 8) & 0x1F) << 8);
    if ( (v6 & 4) == 0 )
    {
LABEL_6:
      if ( (v6 & 8) == 0 )
        goto LABEL_7;
      goto LABEL_14;
    }
LABEL_13:
    v7 = v7 & 0xFFF3FFFF | ((*(_DWORD *)a2 & 3) << 18);
    if ( (v6 & 8) == 0 )
    {
LABEL_7:
      if ( (v6 & 0x10) == 0 )
      {
LABEL_9:
        result = sde_reg_write(a1, v8 + 36, v7, "SSPP_CMN_SYS_CACHE_MODE + idx");
        goto LABEL_10;
      }
LABEL_8:
      v7 = v7 & 0xFFFFFFEF | (16 * (*(_BYTE *)(a2 + 12) & 1));
      goto LABEL_9;
    }
LABEL_14:
    v7 = v7 & 0xFFFFFFF0 | *(_DWORD *)(a2 + 16) & 0xF;
    if ( (v6 & 0x10) == 0 )
      goto LABEL_9;
    goto LABEL_8;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
