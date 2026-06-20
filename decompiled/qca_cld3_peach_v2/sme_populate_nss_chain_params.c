__int64 __fastcall sme_populate_nss_chain_params(
        __int64 a1,
        __int64 a2,
        int a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v15; // x24
  unsigned int v16; // w26
  __int64 v17; // x25
  char v18; // w8
  __int64 result; // x0
  bool v20; // w10
  _DWORD *v21; // x11
  unsigned int v22; // w12
  unsigned int v23; // w12
  bool v24; // zf
  unsigned int v25; // w10
  __int64 v26; // x13
  unsigned int v27; // w12
  unsigned int v28; // w11
  unsigned int v29; // w11
  unsigned int v30; // w11
  unsigned int v31; // w11
  unsigned int v32; // w11
  char v33; // w12
  __int64 v34; // x22
  char v35; // w27
  char v36; // w20
  __int64 v37; // x8
  unsigned __int8 v38; // w28
  __int64 v39; // x8
  __int64 v40; // [xsp+0h] [xbp-30h]
  __int64 v41; // [xsp+8h] [xbp-28h]
  __int64 v42; // [xsp+10h] [xbp-20h]
  __int64 v43; // [xsp+18h] [xbp-18h]
  int v44; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v45; // [xsp+28h] [xbp-8h]

  v42 = a2 + 24;
  v43 = a2 + 8;
  v41 = a2 + 44;
  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = a4;
  v17 = a2 + 16;
  v40 = a2 + 46;
  v18 = 1;
  do
  {
    v34 = *(_QWORD *)(a1 + 8);
    v35 = v18;
    v44 = 0;
    if ( a3 > 6 )
    {
      if ( a3 <= 10 )
      {
        if ( a3 == 7 )
        {
          v36 = 18;
          goto LABEL_47;
        }
        if ( a3 == 8 )
        {
          v36 = 21;
          goto LABEL_47;
        }
      }
      else
      {
        v36 = 24;
        if ( a3 == 11 )
        {
          v37 = v34;
          goto LABEL_53;
        }
        if ( a3 == 15 )
        {
          v36 = 12;
LABEL_47:
          if ( *(_BYTE *)(v34 + 2871) )
            v38 = 2;
          else
            v38 = 1;
          goto LABEL_50;
        }
        v37 = v34;
        if ( a3 == 16 )
          goto LABEL_53;
      }
    }
    else if ( a3 <= 1 )
    {
      v36 = a3;
      if ( !a3 )
        goto LABEL_47;
      if ( a3 == 1 )
      {
        v36 = 3;
        goto LABEL_47;
      }
    }
    else
    {
      switch ( a3 )
      {
        case 2:
          v36 = 9;
          goto LABEL_47;
        case 3:
          v36 = 6;
          goto LABEL_47;
        case 5:
          v36 = 15;
          goto LABEL_47;
      }
    }
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Device mode %d invalid",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "sme_get_nss_chain_shift",
      (unsigned int)a3,
      v40);
    v37 = *(_QWORD *)(a1 + 8);
    v36 = 0;
LABEL_53:
    if ( *(_BYTE *)(v37 + 2871) )
      v38 = 2;
    else
      v38 = 1;
    if ( a3 == 11 && ((unsigned __int8)v35 & *(_BYTE *)(v37 + 1072) & 1) != 0 )
      v38 = 1;
LABEL_50:
    result = ucfg_coex_psoc_get_btc_chain_mode(*(_QWORD *)(a1 + 21624), &v44);
    if ( (_DWORD)result )
    {
      result = qdf_trace_msg(
                 0x34u,
                 2u,
                 "%s: Failed to get BT coex chain mode",
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 "sme_fill_nss_chain_params");
      v20 = 0;
    }
    else
    {
      v20 = (unsigned int)(v44 - 1) < 2;
    }
    v18 = 0;
    v21 = (_DWORD *)(v34 + 4 * v15);
    v22 = (v21[863] >> v36) & 7;
    if ( v22 >= v16 )
      v22 = v16;
    *(_DWORD *)(v43 + 4 * v15) = v22;
    v23 = (v21[861] >> v36) & 7;
    if ( v23 >= v16 )
      v23 = v16;
    *(_DWORD *)(a2 + 4 * v15) = v23;
    v24 = (v35 & 1 & v20) == 0;
    v25 = v38;
    v26 = v34 + v15;
    if ( !v24 )
      v25 = 1;
    v27 = (v21[867] >> v36) & 7;
    if ( v27 >= v25 )
      v27 = v25;
    *(_DWORD *)(v42 + 4 * v15) = v27;
    v28 = (v21[865] >> v36) & 7;
    if ( v28 < v25 )
      v25 = v28;
    *(_DWORD *)(v17 + 4 * v15) = v25;
    v29 = (*(_DWORD *)(v34 + 3484) >> v36) & 7;
    if ( v29 >= v16 )
      v29 = v16;
    *(_DWORD *)(a2 + 40) = v29;
    v30 = (*(_DWORD *)(v34 + 3476) >> v36) & 7;
    if ( v30 >= v16 )
      v30 = v16;
    *(_DWORD *)(a2 + 32) = v30;
    v31 = (*(_DWORD *)(v34 + 3480) >> v36) & 7;
    if ( v31 >= v16 )
      v31 = v16;
    *(_DWORD *)(a2 + 36) = v31;
    *(_BYTE *)(v41 + v15) = *(_BYTE *)(v26 + 3488);
    if ( v27 >= v16 )
      v32 = v16;
    else
      v32 = v27;
    v33 = *(_BYTE *)(v26 + 3490);
    *(_DWORD *)(v42 + 4 * v15) = v32;
    if ( v25 >= v16 )
      v25 = v16;
    *(_DWORD *)(v17 + 4 * v15) = v25;
    *(_BYTE *)(v40 + v15) = v33;
    v15 = 1;
  }
  while ( (v35 & 1) != 0 );
  v39 = *(_QWORD *)(a1 + 8);
  *(_BYTE *)(a2 + 50) = *(_BYTE *)(v39 + 3494);
  *(_DWORD *)(a2 + 52) = *(_DWORD *)(v39 + 3496);
  _ReadStatusReg(SP_EL0);
  return result;
}
