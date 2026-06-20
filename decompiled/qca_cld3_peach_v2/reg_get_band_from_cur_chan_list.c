__int64 __fastcall reg_get_band_from_cur_chan_list(
        char a1,
        __int64 a2,
        __int64 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v16; // w24
  unsigned int v17; // w21
  __int64 v19; // x8
  __int64 v20; // x10
  unsigned int v21; // w11
  __int64 v22; // x11
  int v23; // w12
  __int64 v24; // x14
  __int64 v25; // x10
  __int64 v26; // x13
  __int64 v27; // t2
  __int64 i; // x25
  unsigned int v29; // w8
  __int64 v30; // x8
  __int64 v31; // x10
  __int64 v32; // x12
  __int64 v33; // x11
  __int64 v34; // x8
  __int64 v35; // x8
  __int64 v36; // x10
  unsigned int v37; // w11
  __int64 v38; // x10
  __int64 v39; // x11
  int v40; // w12
  __int64 v41; // x14
  __int64 v42; // x10
  __int64 v43; // x13
  __int64 v44; // t2

  if ( (a1 & 1) != 0 )
  {
    v19 = 0;
    v16 = 0;
    do
    {
      v20 = a3 + v19;
      if ( (*(_BYTE *)(a3 + v19 + 12) & 1) == 0 && *(_DWORD *)(v20 + 8) )
      {
        v21 = (unsigned __int16)v16++;
        v22 = a2 + 36LL * v21;
        *(_QWORD *)v22 = *(_QWORD *)v20;
        v23 = *(_DWORD *)(v20 + 32);
        v24 = *(_QWORD *)(v20 + 8);
        v27 = v20 + 16;
        v25 = *(_QWORD *)(v20 + 16);
        v26 = *(_QWORD *)(v27 + 8);
        *(_DWORD *)(v22 + 32) = v23;
        *(_QWORD *)(v22 + 8) = v24;
        *(_QWORD *)(v22 + 16) = v25;
        *(_QWORD *)(v22 + 24) = v26;
      }
      v19 += 36;
    }
    while ( v19 != 504 );
  }
  else
  {
    v16 = 0;
  }
  if ( (a1 & 2) != 0 )
  {
    for ( i = 0; i != 1008; i += 36 )
    {
      v34 = a3 + i;
      if ( (a4 & 1) != 0 )
      {
        if ( (reg_is_chan_disabled_and_not_nol(a3 + i + 504) & 1) != 0 )
          continue;
      }
      else if ( (*(_BYTE *)(v34 + 516) & 1) != 0 || !*(_DWORD *)(v34 + 512) )
      {
        continue;
      }
      v29 = (unsigned __int16)v16++;
      v30 = a2 + 36LL * v29;
      *(_QWORD *)v30 = *(_QWORD *)(a3 + i + 504);
      v32 = *(_QWORD *)(a3 + i + 520);
      v31 = *(_QWORD *)(a3 + i + 528);
      v33 = *(_QWORD *)(a3 + i + 512);
      *(_DWORD *)(v30 + 32) = *(_DWORD *)(a3 + i + 536);
      *(_QWORD *)(v30 + 16) = v32;
      *(_QWORD *)(v30 + 24) = v31;
      *(_QWORD *)(v30 + 8) = v33;
    }
  }
  if ( (a1 & 4) != 0 )
  {
    v35 = 0;
    v17 = v16;
    do
    {
      v36 = a3 + v35;
      if ( (*(_BYTE *)(a3 + v35 + 1524) & 1) == 0 && *(_DWORD *)(v36 + 1520) )
      {
        v37 = (unsigned __int16)v17;
        v38 = v36 + 1512;
        ++v17;
        v39 = a2 + 36LL * v37;
        *(_QWORD *)v39 = *(_QWORD *)v38;
        v40 = *(_DWORD *)(v38 + 32);
        v41 = *(_QWORD *)(v38 + 8);
        v44 = v38 + 16;
        v42 = *(_QWORD *)(v38 + 16);
        v43 = *(_QWORD *)(v44 + 8);
        *(_DWORD *)(v39 + 32) = v40;
        *(_QWORD *)(v39 + 8) = v41;
        *(_QWORD *)(v39 + 16) = v42;
        *(_QWORD *)(v39 + 24) = v43;
      }
      v35 += 36;
    }
    while ( v35 != 2160 );
  }
  else
  {
    v17 = v16;
  }
  if ( !(_WORD)v17 )
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: Failed to retrieve the channel list",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "reg_get_band_from_cur_chan_list");
  return v17;
}
