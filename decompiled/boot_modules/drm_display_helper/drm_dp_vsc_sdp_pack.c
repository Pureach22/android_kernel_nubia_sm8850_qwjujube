__int64 __fastcall drm_dp_vsc_sdp_pack(__int64 a1, __int64 a2)
{
  int v2; // w8
  char v3; // w8
  int v4; // w8
  char v5; // w8
  char v6; // w9

  *(_DWORD *)(a2 + 32) = 0;
  *(_QWORD *)(a2 + 16) = 0;
  *(_QWORD *)(a2 + 24) = 0;
  *(_QWORD *)a2 = 0;
  *(_QWORD *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 1) = *(_BYTE *)a1;
  *(_BYTE *)(a2 + 2) = *(_BYTE *)(a1 + 1);
  *(_BYTE *)(a2 + 3) = *(_BYTE *)(a1 + 2);
  v2 = *(unsigned __int8 *)(a1 + 1);
  if ( v2 == 6 )
  {
    *(_BYTE *)(a2 + 4) = 1;
    *(_BYTE *)(a2 + 7) = 1;
    v2 = *(unsigned __int8 *)(a1 + 1);
  }
  if ( (v2 | 2) != 7 )
    return 36;
  v3 = 16 * *(_BYTE *)(a1 + 4);
  *(_BYTE *)(a2 + 20) = v3;
  *(_BYTE *)(a2 + 20) = v3 & 0xF0 | *(_BYTE *)(a1 + 8) & 0xF;
  v4 = *(_DWORD *)(a1 + 12);
  if ( v4 <= 9 )
  {
    if ( v4 == 6 )
    {
      v5 = 0x80;
      goto LABEL_15;
    }
    if ( v4 == 8 )
    {
      v5 = -127;
      v6 = 1;
      goto LABEL_14;
    }
  }
  else
  {
    switch ( v4 )
    {
      case 16:
        v5 = -124;
        v6 = 4;
        goto LABEL_14;
      case 12:
        v5 = -125;
        v6 = 3;
        goto LABEL_14;
      case 10:
        v5 = -126;
        v6 = 2;
LABEL_14:
        *(_BYTE *)(a2 + 21) = v6;
LABEL_15:
        if ( *(_DWORD *)(a1 + 16) == 1 )
          *(_BYTE *)(a2 + 21) = v5;
        *(_BYTE *)(a2 + 22) = *(_BYTE *)(a1 + 20) & 7;
        return 36;
    }
  }
  _warn_printk("Missing case %d\n", v4);
  __break(0x800u);
  return -22;
}
