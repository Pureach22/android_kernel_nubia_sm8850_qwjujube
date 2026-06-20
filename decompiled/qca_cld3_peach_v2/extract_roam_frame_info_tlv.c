__int64 __fastcall extract_roam_frame_info_tlv(
        __int64 a1,
        __int64 a2,
        _BYTE *a3,
        unsigned __int8 a4,
        unsigned __int8 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x9
  unsigned int v14; // w11
  unsigned int v16; // w21
  int v18; // w22
  _BYTE *v19; // x23
  __int64 i; // x24
  int v21; // w10
  int v22; // w9
  unsigned int v23; // w8
  int v24; // w10
  unsigned int v25; // w9
  unsigned int v26; // w9

  if ( !a2 || (v13 = *(_QWORD *)(a2 + 128)) == 0 || (v14 = *(_DWORD *)(a2 + 136)) == 0 || a5 + (unsigned int)a4 > v14 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Empty roam_frame_info param buf frame_idx:%d num_frames:%d",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "extract_roam_frame_info_tlv",
      a4,
      a5);
    return 0;
  }
  if ( a5 >= 0x36u )
    v16 = 54;
  else
    v16 = a5;
  *a3 = v16;
  if ( a5 )
  {
    v18 = 0;
    v19 = a3 + 24;
    for ( i = v13 + 36LL * a4 + 32; ; i += 36 )
    {
      *((_DWORD *)v19 - 2) = *(_DWORD *)(i - 28);
      *(_WORD *)(v19 - 15) = *(_DWORD *)(i - 8);
      *(v19 - 13) = *(_WORD *)(i - 6);
      *(v19 - 12) = *(_BYTE *)(i - 5);
      *(_WORD *)(v19 - 11) = *(_DWORD *)(i - 4);
      v21 = *(_DWORD *)(i - 24);
      v22 = v21 & 3;
      *(v19 - 4) = v21 & 3;
      v23 = *(_DWORD *)(i - 24);
      if ( (~v21 & 3) != 0 )
      {
        LOBYTE(v23) = 16 * ((unsigned __int8)v23 >> 2);
      }
      else
      {
        v23 = (v23 >> 2) & 0xF;
        v22 = 3;
        *(v19 - 4) = 3;
        if ( v23 >= 7 )
          LOBYTE(v23) = 0;
      }
      *(v19 - 3) = v23;
      v24 = (*(_DWORD *)(i - 24) >> 6) & 1;
      *(v19 - 2) = (*(_DWORD *)(i - 24) & 0x40) != 0;
      *((_WORD *)v19 + 2) = *(_WORD *)(i - 22);
      *((_WORD *)v19 + 4) = *(_DWORD *)(i - 20);
      if ( v22 == 3 || (unsigned __int8)v23 != 176 )
        break;
      v19[6] = (*(_DWORD *)(i - 24) >> 7) & 0xF;
      if ( !v24 )
        goto LABEL_25;
      *((_WORD *)v19 + 8) = *(_DWORD *)(i - 12);
      *((_DWORD *)v19 + 3) = -*(_DWORD *)(i - 16);
      *((_WORD *)v19 + 9) = *(_DWORD *)i;
      v19[20] = *(_BYTE *)(i + 2) & 0x1F;
LABEL_13:
      ++v18;
      v19 += 120;
      if ( v16 <= (unsigned __int8)v18 )
        return 0;
    }
    if ( !v24 && (unsigned __int8)v23 == 176 || ((unsigned __int8)v23 | 0x20) == 0x20 || v22 == 3 )
    {
LABEL_25:
      v25 = *(_DWORD *)(i - 20);
      *((_WORD *)v19 + 4) = 0;
      if ( v25 < 9 )
        v26 = v25 + 1;
      else
        v26 = 0;
      *(_DWORD *)v19 = v26;
    }
    *((_WORD *)v19 + 8) = *(_DWORD *)(i - 12);
    *((_DWORD *)v19 + 3) = -*(_DWORD *)(i - 16);
    *((_WORD *)v19 + 9) = *(_DWORD *)i;
    v19[20] = *(_BYTE *)(i + 2) & 0x1F;
    if ( ((unsigned __int8)v23 | 0x20) == 0x30 )
      wmi_unified_extract_roam_ml_info(a1);
    goto LABEL_13;
  }
  return 0;
}
