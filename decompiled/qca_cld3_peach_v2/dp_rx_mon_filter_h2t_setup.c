__int64 __fastcall dp_rx_mon_filter_h2t_setup(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x20
  __int64 v12; // x21
  int v13; // w10
  int v14; // w12
  unsigned __int16 v15; // w9
  unsigned __int16 v16; // w9
  int v17; // w10
  int v18; // w12
  unsigned __int16 v19; // w9
  unsigned __int16 v20; // w9
  int v21; // w10
  int v22; // w12
  unsigned __int16 v23; // w9
  __int64 v24; // x8
  int v25; // w11
  unsigned __int16 v26; // w9
  int v27; // w10
  int v28; // w12
  unsigned __int16 v29; // w9
  unsigned __int16 v30; // w9
  int v31; // w10
  int v32; // w12
  unsigned __int16 v33; // w9
  unsigned int *v34; // x10
  int v35; // w9
  unsigned int v36; // w11
  int v37; // w13
  int v38; // w12
  int v39; // w13
  int v40; // w12
  int v41; // w13
  int v42; // w12
  int v43; // w12
  int v44; // w12
  int v45; // w11
  int v46; // w12
  __int16 v47; // w11
  int v48; // w10

  v11 = 0;
  v12 = *(_QWORD *)(result + 96456);
  do
  {
    v24 = *(_QWORD *)(*(_QWORD *)(v12 + 39328) + 8 * v11);
    if ( *(_BYTE *)(v24 + 432) != 1 )
      goto LABEL_3;
    *(_BYTE *)a2 = 1;
    v25 = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(a2 + 4) |= *(_DWORD *)(v24 + 436);
    v26 = v25 | *(_DWORD *)(v24 + 440);
    *(_DWORD *)(a2 + 8) = (unsigned __int16)*(_DWORD *)(v24 + 440) | v25;
    *(_DWORD *)(a2 + 8) = (*(_DWORD *)(v24 + 440) | v25) & 0xFFFF0000 | v26;
    v27 = *(_DWORD *)(a2 + 12);
    v28 = *(_DWORD *)(a2 + 16);
    v29 = v27 | *(_DWORD *)(v24 + 444);
    *(_DWORD *)(a2 + 12) = (unsigned __int16)*(_DWORD *)(v24 + 444) | v27;
    *(_DWORD *)(a2 + 12) = (*(_DWORD *)(v24 + 444) | v27) & 0xFFFF0000 | v29;
    v30 = v28 | *(_DWORD *)(v24 + 448);
    *(_DWORD *)(a2 + 16) = (unsigned __int16)*(_DWORD *)(v24 + 448) | v28;
    *(_DWORD *)(a2 + 16) = (*(_DWORD *)(v24 + 448) | v28) & 0xFFFF0000 | v30;
    v31 = *(_DWORD *)(a2 + 20);
    v32 = *(_DWORD *)(a2 + 24);
    v33 = v31 | *(_DWORD *)(v24 + 452);
    *(_DWORD *)(a2 + 20) = (unsigned __int16)*(_DWORD *)(v24 + 452) | v31;
    *(_DWORD *)(a2 + 20) = (*(_DWORD *)(v24 + 452) | v31) & 0xFFFF0000 | v33;
    v34 = (unsigned int *)(v24 + 510);
    v35 = *(unsigned __int16 *)(v24 + 456) | v32;
    *(_DWORD *)(a2 + 24) = v35;
    v36 = *(_DWORD *)(v24 + 510);
    if ( (v36 & 7) != 0 && (v37 = *(_DWORD *)(a2 + 78), (v37 & 7) == 0) )
    {
      *(_DWORD *)(a2 + 78) = v37 | *(_DWORD *)(v24 + 510) & 7;
      v36 = *v34;
      v38 = (*v34 >> 3) & 7;
      if ( !v38 )
        goto LABEL_11;
    }
    else
    {
      v38 = (v36 >> 3) & 7;
      if ( !v38 )
        goto LABEL_11;
    }
    v39 = *(_DWORD *)(a2 + 78);
    if ( (v39 & 0x38) == 0 )
    {
      *(_DWORD *)(a2 + 78) = v39 | (8 * v38);
      v36 = *v34;
    }
LABEL_11:
    v40 = (v36 >> 6) & 7;
    if ( v40 && (v41 = *(_DWORD *)(a2 + 78), (v41 & 0x1C0) == 0) )
    {
      *(_DWORD *)(a2 + 78) = v41 | (v40 << 6);
      v36 = *v34;
      if ( (*v34 & 0x1000) == 0 )
        goto LABEL_17;
    }
    else if ( (v36 & 0x1000) == 0 )
    {
      goto LABEL_17;
    }
    v42 = *(_DWORD *)(a2 + 78);
    if ( (v42 & 0x1000) == 0 )
    {
      *(_DWORD *)(a2 + 78) = v42 | 0x1000;
      v36 = *v34;
    }
LABEL_17:
    if ( (v36 & 0x2000) != 0 )
    {
      v43 = *(_DWORD *)(a2 + 78);
      if ( (v43 & 0x2000) == 0 )
      {
        *(_DWORD *)(a2 + 78) = v43 | 0x2000;
        v36 = *v34;
      }
    }
    if ( (v36 & 0x4000) != 0 )
    {
      v44 = *(_DWORD *)(a2 + 78);
      if ( (v44 & 0x4000) == 0 )
      {
        *(_DWORD *)(a2 + 78) = v44 | 0x4000;
        v36 = *v34;
      }
    }
    v45 = (v36 >> 9) & 7;
    if ( v45 && (v46 = *(_DWORD *)(a2 + 78), (v46 & 0xE00) == 0) )
    {
      *(_DWORD *)(a2 + 78) = v46 | (v45 << 9);
      v47 = *(_WORD *)(v24 + 508);
      if ( v47 )
      {
LABEL_26:
        if ( !*(_WORD *)(a2 + 76) )
          *(_WORD *)(a2 + 76) = v47;
      }
    }
    else
    {
      v47 = *(_WORD *)(v24 + 508);
      if ( v47 )
        goto LABEL_26;
    }
    if ( (*(_BYTE *)(v24 + 512) & 1) != 0 )
    {
      v48 = *(_DWORD *)(a2 + 78);
      if ( (v48 & 0x10000) == 0 )
      {
        *(_DWORD *)(a2 + 78) = v48 | 0x10000;
        *(_WORD *)(a2 + 82) = *(_WORD *)(v24 + 514);
        *(_WORD *)(a2 + 84) = *(_WORD *)(v24 + 516);
        *(_WORD *)(a2 + 86) = *(_WORD *)(v24 + 518);
      }
    }
    v13 = *(_DWORD *)(a2 + 28);
    v14 = *(_DWORD *)(a2 + 32);
    *(_DWORD *)(a2 + 24) = v35 | (*(unsigned __int16 *)(v24 + 458) << 16);
    v15 = v13 | *(_DWORD *)(v24 + 460);
    *(_DWORD *)(a2 + 28) = (unsigned __int16)*(_DWORD *)(v24 + 460) | v13;
    *(_DWORD *)(a2 + 28) = (*(_DWORD *)(v24 + 460) | v13) & 0xFFFF0000 | v15;
    v16 = v14 | *(_DWORD *)(v24 + 464);
    *(_DWORD *)(a2 + 32) = (unsigned __int16)*(_DWORD *)(v24 + 464) | v14;
    *(_DWORD *)(a2 + 32) = (*(_DWORD *)(v24 + 464) | v14) & 0xFFFF0000 | v16;
    v17 = *(_DWORD *)(a2 + 36);
    v18 = *(_DWORD *)(a2 + 40);
    v19 = v17 | *(_DWORD *)(v24 + 468);
    *(_DWORD *)(a2 + 36) = (unsigned __int16)*(_DWORD *)(v24 + 468) | v17;
    *(_DWORD *)(a2 + 36) = (*(_DWORD *)(v24 + 468) | v17) & 0xFFFF0000 | v19;
    v20 = v18 | *(_DWORD *)(v24 + 472);
    *(_DWORD *)(a2 + 40) = (unsigned __int16)*(_DWORD *)(v24 + 472) | v18;
    *(_DWORD *)(a2 + 40) = (*(_DWORD *)(v24 + 472) | v18) & 0xFFFF0000 | v20;
    v21 = *(_DWORD *)(a2 + 44);
    v22 = *(_DWORD *)(a2 + 48);
    v23 = v21 | *(_DWORD *)(v24 + 476);
    *(_DWORD *)(a2 + 44) = (unsigned __int16)*(_DWORD *)(v24 + 476) | v21;
    *(_DWORD *)(a2 + 44) = (*(_DWORD *)(v24 + 476) | v21) & 0xFFFF0000 | v23;
    *(_DWORD *)(a2 + 48) = *(unsigned __int16 *)(v24 + 480) | v22;
    result = dp_mon_filter_show_rx_filter_be(v11, (unsigned __int8 *)(v24 + 432), a3, a4, a5, a6, a7, a8, a9, a10);
LABEL_3:
    ++v11;
  }
  while ( v11 != 4 );
  return result;
}
