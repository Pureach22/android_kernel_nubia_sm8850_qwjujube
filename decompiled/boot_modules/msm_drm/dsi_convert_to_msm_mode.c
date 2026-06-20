__int64 __fastcall dsi_convert_to_msm_mode(__int64 result, __int64 a2)
{
  int v2; // w9
  int v3; // w8

  *(_DWORD *)(a2 + 8) = 0;
  *(_QWORD *)(a2 + 16) = *(_QWORD *)(result + 184);
  v2 = *(_DWORD *)(result + 156);
  if ( (v2 & 1) != 0 )
  {
    v3 = 32;
    *(_DWORD *)(a2 + 8) = 32;
    v2 = *(_DWORD *)(result + 156);
    if ( (v2 & 2) == 0 )
      goto LABEL_6;
    goto LABEL_5;
  }
  v3 = 0;
  if ( (v2 & 2) != 0 )
  {
LABEL_5:
    v3 |= 1u;
    *(_DWORD *)(a2 + 8) = v3;
    v2 = *(_DWORD *)(result + 156);
  }
LABEL_6:
  if ( (v2 & 4) != 0 )
  {
    v3 |= 2u;
    *(_DWORD *)(a2 + 8) = v3;
    v2 = *(_DWORD *)(result + 156);
    if ( (v2 & 8) == 0 )
    {
LABEL_8:
      if ( (v2 & 0x10) == 0 )
        goto LABEL_9;
      goto LABEL_16;
    }
  }
  else if ( (v2 & 8) == 0 )
  {
    goto LABEL_8;
  }
  v3 |= 4u;
  *(_DWORD *)(a2 + 8) = v3;
  v2 = *(_DWORD *)(result + 156);
  if ( (v2 & 0x10) == 0 )
  {
LABEL_9:
    if ( (v2 & 0x80) == 0 )
      goto LABEL_10;
    goto LABEL_17;
  }
LABEL_16:
  v3 |= 8u;
  *(_DWORD *)(a2 + 8) = v3;
  v2 = *(_DWORD *)(result + 156);
  if ( (v2 & 0x80) == 0 )
  {
LABEL_10:
    if ( (v2 & 0x100) == 0 )
      goto LABEL_11;
    goto LABEL_18;
  }
LABEL_17:
  v3 |= 0x40u;
  *(_DWORD *)(a2 + 8) = v3;
  v2 = *(_DWORD *)(result + 156);
  if ( (v2 & 0x100) == 0 )
  {
LABEL_11:
    if ( (v2 & 0x20) == 0 )
      goto LABEL_12;
    goto LABEL_19;
  }
LABEL_18:
  v3 |= 0x80u;
  *(_DWORD *)(a2 + 8) = v3;
  v2 = *(_DWORD *)(result + 156);
  if ( (v2 & 0x20) == 0 )
  {
LABEL_12:
    if ( (v2 & 0x200) == 0 )
      return result;
LABEL_20:
    *(_DWORD *)(a2 + 8) = v3 | 0x100;
    return result;
  }
LABEL_19:
  v3 |= 0x10u;
  *(_DWORD *)(a2 + 8) = v3;
  if ( (*(_DWORD *)(result + 156) & 0x200) != 0 )
    goto LABEL_20;
  return result;
}
