__int64 __fastcall extract_roam_frame_info_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        _BYTE *a11,
        unsigned __int8 a12,
        unsigned __int8 a13)
{
  __int64 v13; // x10
  unsigned int v14; // w11
  unsigned int v16; // w8
  int v17; // w9
  _BYTE *v18; // x11
  __int64 v19; // x10
  unsigned int v20; // w13
  unsigned int v21; // w13
  char v22; // w13
  int v23; // w15
  int v24; // w13
  unsigned int v25; // w14
  int v26; // w15

  if ( !a10
    || (v13 = *(_QWORD *)(a10 + 128)) == 0
    || (v14 = *(_DWORD *)(a10 + 136)) == 0
    || a13 + (unsigned int)a12 > v14 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Empty roam_frame_info param buf frame_idx:%d num_frames:%d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_roam_frame_info_tlv",
      a12,
      a13);
    return 0;
  }
  if ( a13 >= 0x36u )
    v16 = 54;
  else
    v16 = a13;
  *a11 = v16;
  if ( a13 )
  {
    v17 = 0;
    v18 = a11 + 20;
    v19 = v13 + 36LL * a12 + 16;
    while ( 1 )
    {
      *((_DWORD *)v18 - 2) = *(_DWORD *)(v19 - 12);
      *(_WORD *)(v18 - 15) = *(_DWORD *)(v19 + 8);
      *(v18 - 13) = *(_WORD *)(v19 + 10);
      *(v18 - 12) = *(_BYTE *)(v19 + 11);
      *(_WORD *)(v18 - 11) = *(_DWORD *)(v19 + 12);
      v23 = *(_DWORD *)(v19 - 8);
      v24 = v23 & 3;
      *(v18 - 4) = v23 & 3;
      v25 = *(_DWORD *)(v19 - 8);
      if ( (~v23 & 3) != 0 )
      {
        LOBYTE(v25) = 16 * ((unsigned __int8)v25 >> 2);
      }
      else
      {
        v25 = (v25 >> 2) & 0xF;
        v24 = 3;
        *(v18 - 4) = 3;
        if ( v25 >= 7 )
          LOBYTE(v25) = 0;
      }
      *(v18 - 3) = v25;
      v26 = (*(_DWORD *)(v19 - 8) >> 6) & 1;
      *(v18 - 2) = (*(_DWORD *)(v19 - 8) & 0x40) != 0;
      *((_WORD *)v18 + 2) = *(_WORD *)(v19 - 6);
      *((_WORD *)v18 + 4) = *(_DWORD *)(v19 - 4);
      if ( v24 == 3 || (unsigned __int8)v25 != 176 )
        break;
      v18[6] = (*(_DWORD *)(v19 - 8) >> 7) & 0xF;
      if ( !v26 )
        goto LABEL_12;
LABEL_16:
      ++v17;
      *((_WORD *)v18 + 8) = *(_DWORD *)(v19 + 4);
      *((_DWORD *)v18 + 3) = -*(_DWORD *)v19;
      *((_WORD *)v18 + 9) = *(_DWORD *)(v19 + 16);
      v22 = *(_BYTE *)(v19 + 18);
      v19 += 36;
      v18[20] = v22 & 0x1F;
      v18 += 40;
      if ( v16 <= (unsigned __int8)v17 )
        return 0;
    }
    if ( (v26 || (unsigned __int8)v25 != 176) && ((unsigned __int8)v25 | 0x20) != 0x20 && v24 != 3 )
      goto LABEL_16;
LABEL_12:
    v20 = *(_DWORD *)(v19 - 4);
    *((_WORD *)v18 + 4) = 0;
    if ( v20 < 9 )
      v21 = v20 + 1;
    else
      v21 = 0;
    *(_DWORD *)v18 = v21;
    goto LABEL_16;
  }
  return 0;
}
