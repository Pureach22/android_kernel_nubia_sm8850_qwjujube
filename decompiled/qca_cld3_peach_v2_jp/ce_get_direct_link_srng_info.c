__int64 __fastcall ce_get_direct_link_srng_info(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 v14; // x24
  int v15; // w26
  _DWORD *v16; // x25
  __int64 v17; // x4
  __int64 v18; // x28
  __int64 v19; // x27
  __int64 v20; // x8
  __int64 v21; // x22
  __int64 v22; // x8
  __int64 v23; // x0
  int v24; // w10
  int v25; // w8
  __int64 v26; // x9
  _QWORD *v27; // x8
  __int64 v28; // x11
  __int64 v29; // x10
  _QWORD *v30; // x9
  _QWORD *v31; // x8
  __int64 v32; // x11
  __int64 v33; // x10
  _QWORD *v34; // x9
  __int64 v35; // x27
  char v36; // w8
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x22
  int v40; // w10
  int v41; // w8
  __int64 v42; // x9
  _QWORD *v43; // x8
  __int64 v44; // x11
  __int64 v45; // x10
  _QWORD *v46; // x9
  _QWORD *v47; // x8
  __int64 v48; // x11
  __int64 v49; // x10
  _QWORD *v50; // x9
  __int64 result; // x0
  __int64 v52; // [xsp+8h] [xbp-68h]
  __int64 v53; // [xsp+10h] [xbp-60h] BYREF
  __int64 v54; // [xsp+18h] [xbp-58h]
  __int64 v55; // [xsp+20h] [xbp-50h]
  __int64 v56; // [xsp+28h] [xbp-48h]
  __int64 v57; // [xsp+30h] [xbp-40h]
  __int64 v58; // [xsp+38h] [xbp-38h]
  __int64 v59; // [xsp+40h] [xbp-30h]
  __int64 v60; // [xsp+48h] [xbp-28h]
  __int64 v61; // [xsp+50h] [xbp-20h]
  __int64 v62; // [xsp+58h] [xbp-18h]
  __int64 v63; // [xsp+60h] [xbp-10h]
  __int64 v64; // [xsp+68h] [xbp-8h]

  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_DWORD *)(a1 + 30712) )
  {
LABEL_35:
    result = 0;
    goto LABEL_38;
  }
  v14 = 0;
  v15 = 0;
  v16 = (_DWORD *)(*(_QWORD *)(a1 + 30704) + 4LL);
  v52 = a1 + 480;
  while ( 1 )
  {
    if ( *(v16 - 1) != 1792 )
      goto LABEL_4;
    v17 = (unsigned int)v16[1];
    if ( (unsigned int)v17 >= 0xC )
      __break(0x5512u);
    v18 = *(_QWORD *)(v52 + 8 * v17);
    if ( !v18 )
      break;
    if ( (unsigned __int8)v15 > (unsigned int)a3 )
      goto LABEL_37;
    v19 = a2 + 48LL * (unsigned __int8)v15;
    *(_BYTE *)v19 = *(_DWORD *)(v18 + 8);
    *(_BYTE *)(v19 + 1) = *v16;
    v20 = *(_QWORD *)(v18 + 136);
    if ( v20 )
    {
      v21 = *(_QWORD *)(v20 + 80);
      v62 = 0;
      v63 = 0;
      v61 = 0;
    }
    else
    {
      v22 = *(_QWORD *)(v18 + 144);
      v61 = 0;
      v62 = 0;
      v21 = *(_QWORD *)(v22 + 80);
      v63 = 0;
    }
    v23 = *(_QWORD *)(a1 + 2560);
    v59 = 0;
    v60 = 0;
    v57 = 0;
    v58 = 0;
    v55 = 0;
    v56 = 0;
    v53 = 0;
    v54 = 0;
    hal_get_srng_params(v23, v21, (__int64)&v53);
    v24 = v55;
    *(_BYTE *)(v19 + 8) = BYTE4(v59);
    v25 = HIDWORD(v60);
    *(_BYTE *)(v19 + 9) = v60;
    v26 = v53;
    *(_DWORD *)(v19 + 12) = v24;
    *(_DWORD *)(v19 + 16) = v25;
    *(_QWORD *)(v19 + 24) = v26;
    v27 = *(_QWORD **)(a1 + 2560);
    if ( *(_DWORD *)(v21 + 116) )
    {
      v28 = 128;
      v29 = 9252;
      v30 = v27 + 9253;
    }
    else
    {
      v28 = 144;
      if ( (*(_DWORD *)(v21 + 76) & 0x80000000) != 0 )
      {
        v30 = v27 + 9255;
        v29 = 9254;
      }
      else
      {
        v29 = 2;
        v30 = (_QWORD *)(*v27 + 728LL);
      }
    }
    *(_QWORD *)(v19 + 32) = *v30 + *(_QWORD *)(v21 + v28) - v27[v29];
    v31 = *(_QWORD **)(a1 + 2560);
    if ( *(_DWORD *)(v21 + 116) )
    {
      if ( (*(_DWORD *)(v21 + 76) & 0x80000000) != 0 )
      {
        v34 = v31 + 9255;
        v32 = 144;
        v33 = 9254;
      }
      else
      {
        v32 = 144;
        v33 = 2;
        v34 = (_QWORD *)(*v31 + 728LL);
      }
    }
    else
    {
      v34 = v31 + 9253;
      v32 = 128;
      v33 = 9252;
    }
    *(_QWORD *)(v19 + 40) = *v34 + *(_QWORD *)(v21 + v32) - v31[v33];
    if ( *(_QWORD *)(v18 + 152) )
    {
      if ( (unsigned __int8)(v15 + 1) > (unsigned int)a3 )
        goto LABEL_37;
      v35 = a2 + 48LL * (unsigned __int8)(v15 + 1);
      *(_BYTE *)v35 = *(_DWORD *)(v18 + 8);
      v36 = *v16;
      v61 = 0;
      v62 = 0;
      v59 = 0;
      v60 = 0;
      *(_BYTE *)(v35 + 1) = v36;
      v37 = *(_QWORD *)(v18 + 152);
      v38 = *(_QWORD *)(a1 + 2560);
      v57 = 0;
      v58 = 0;
      v55 = 0;
      v56 = 0;
      v39 = *(_QWORD *)(v37 + 80);
      v63 = 0;
      v53 = 0;
      v54 = 0;
      hal_get_srng_params(v38, v39, (__int64)&v53);
      v40 = v55;
      *(_BYTE *)(v35 + 8) = BYTE4(v59);
      v41 = HIDWORD(v60);
      *(_BYTE *)(v35 + 9) = v60;
      v42 = v53;
      *(_DWORD *)(v35 + 12) = v40;
      *(_DWORD *)(v35 + 16) = v41;
      *(_QWORD *)(v35 + 24) = v42;
      v43 = *(_QWORD **)(a1 + 2560);
      if ( *(_DWORD *)(v39 + 116) )
      {
        v44 = 128;
        v45 = 9252;
        v46 = v43 + 9253;
      }
      else
      {
        v44 = 144;
        if ( (*(_DWORD *)(v39 + 76) & 0x80000000) != 0 )
        {
          v46 = v43 + 9255;
          v45 = 9254;
        }
        else
        {
          v45 = 2;
          v46 = (_QWORD *)(*v43 + 728LL);
        }
      }
      *(_QWORD *)(v35 + 32) = *v46 + *(_QWORD *)(v39 + v44) - v43[v45];
      v47 = *(_QWORD **)(a1 + 2560);
      if ( *(_DWORD *)(v39 + 116) )
      {
        if ( (*(_DWORD *)(v39 + 76) & 0x80000000) != 0 )
        {
          v50 = v47 + 9255;
          v48 = 144;
          v49 = 9254;
        }
        else
        {
          v48 = 144;
          v49 = 2;
          v50 = (_QWORD *)(*v47 + 728LL);
        }
      }
      else
      {
        v50 = v47 + 9253;
        v48 = 128;
        v49 = 9252;
      }
      v15 += 2;
      *(_QWORD *)(v35 + 40) = *v50 + *(_QWORD *)(v39 + v48) - v47[v49];
      *(_BYTE *)(v18 + 312) = 1;
    }
    else
    {
      ++v15;
    }
LABEL_4:
    ++v14;
    v16 += 3;
    if ( v14 >= *(unsigned int *)(a1 + 30712) )
      goto LABEL_35;
  }
  qdf_trace_msg(
    0x3Du,
    2u,
    "%s: Direct Link CE pipe %d not initialized",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "ce_get_direct_link_srng_info");
LABEL_37:
  result = 16;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
