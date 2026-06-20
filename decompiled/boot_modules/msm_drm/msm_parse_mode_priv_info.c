__int64 __fastcall msm_parse_mode_priv_info(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  char v3; // w9
  char v4; // w9
  int v5; // w8
  int v6; // w8

  v2 = *(_QWORD *)(result + 16);
  *(_QWORD *)(a2 + 184) = v2;
  if ( v2 )
  {
    v3 = *(_BYTE *)(v2 + 3400);
    *(_QWORD *)(a2 + 80) = v2 + 2496;
    *(_BYTE *)(a2 + 72) = v3;
    v4 = *(_BYTE *)(v2 + 3401);
    *(_QWORD *)(a2 + 88) = v2 + 2712;
    *(_BYTE *)(a2 + 73) = v4;
    *(_QWORD *)(a2 + 96) = *(_QWORD *)(v2 + 3404);
    *(_QWORD *)(a2 + 48) = *(_QWORD *)(v2 + 2408);
  }
  v5 = *(_DWORD *)(result + 8);
  if ( (v5 & 0x20) != 0 )
  {
    *(_DWORD *)(a2 + 156) |= 1u;
    v5 = *(_DWORD *)(result + 8);
  }
  if ( (~v5 & 0x21) != 0 )
  {
    if ( (v5 & 2) == 0 )
      goto LABEL_7;
  }
  else
  {
    *(_DWORD *)(a2 + 156) |= 2u;
    if ( (*(_DWORD *)(result + 8) & 2) == 0 )
    {
LABEL_7:
      if ( !result )
        return result;
      goto LABEL_11;
    }
  }
  *(_DWORD *)(a2 + 156) |= 4u;
  if ( !result )
    return result;
LABEL_11:
  v6 = *(_DWORD *)(result + 8);
  if ( (v6 & 4) != 0 )
  {
    *(_DWORD *)(a2 + 156) |= 8u;
    v6 = *(_DWORD *)(result + 8);
    if ( (v6 & 8) == 0 )
    {
LABEL_13:
      if ( (v6 & 0x40) == 0 )
        goto LABEL_14;
      goto LABEL_20;
    }
  }
  else if ( (v6 & 8) == 0 )
  {
    goto LABEL_13;
  }
  *(_DWORD *)(a2 + 156) |= 0x10u;
  v6 = *(_DWORD *)(result + 8);
  if ( (v6 & 0x40) == 0 )
  {
LABEL_14:
    if ( (v6 & 0x80) == 0 )
      goto LABEL_15;
    goto LABEL_21;
  }
LABEL_20:
  *(_DWORD *)(a2 + 156) |= 0x80u;
  v6 = *(_DWORD *)(result + 8);
  if ( (v6 & 0x80) == 0 )
  {
LABEL_15:
    if ( (v6 & 0x10) == 0 )
      goto LABEL_16;
    goto LABEL_22;
  }
LABEL_21:
  *(_DWORD *)(a2 + 156) |= 0x100u;
  v6 = *(_DWORD *)(result + 8);
  if ( (v6 & 0x10) == 0 )
  {
LABEL_16:
    if ( (v6 & 0x100) != 0 )
      goto LABEL_23;
    return result;
  }
LABEL_22:
  *(_DWORD *)(a2 + 156) |= 0x20u;
  if ( (*(_DWORD *)(result + 8) & 0x100) != 0 )
LABEL_23:
    *(_DWORD *)(a2 + 156) |= 0x200u;
  return result;
}
