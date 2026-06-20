unsigned __int64 __fastcall nl80211_parse_beacon(__int64 a1, _QWORD *a2, _QWORD *a3, _QWORD *a4)
{
  __int64 v4; // x8
  __int64 v5; // x8
  bool v6; // zf
  _WORD **v7; // x8
  __int64 v8; // x9
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x8
  _WORD *v13; // x8
  __int64 v14; // x22
  _QWORD *v15; // x20
  _QWORD *v16; // x19
  _QWORD *v17; // x21
  unsigned __int64 result; // x0
  _WORD *v19; // x8
  __int64 v20; // x20
  _QWORD *v21; // x22
  _QWORD *v22; // x21
  _BYTE *v23; // x19
  _WORD *v24; // x10
  char v25; // w8
  unsigned __int64 v26; // x23
  _WORD *v27; // x22
  int v28; // w8
  _WORD *v29; // x24
  unsigned __int16 *v30; // x9
  unsigned int v31; // w10
  __int64 v32; // x10
  _WORD *v33; // x8
  _WORD *v34; // x8
  unsigned __int16 *v35; // x25
  _QWORD *v36; // x21
  _QWORD *v37; // x20
  unsigned __int64 v38; // x19
  int v39; // w10
  unsigned __int8 v40; // w11
  unsigned int v41; // w13
  unsigned __int64 v42; // x13
  bool v43; // cf
  unsigned __int64 v44; // x13
  unsigned __int64 v45; // x14
  unsigned __int64 v46; // x14
  __int64 v47; // x13
  unsigned __int64 v48; // x14
  _QWORD *v49; // x13
  __int64 v50; // x13
  int v51; // w8
  unsigned int v52; // w9
  unsigned __int16 *v53; // x10
  unsigned __int64 v54; // x12
  unsigned __int16 *v55; // x11
  __int64 v56; // x13
  __int64 v57; // x9
  unsigned __int64 v58; // x19
  int v59; // w8
  unsigned __int8 v60; // w9
  unsigned int v61; // w11
  unsigned __int64 v62; // x11
  unsigned __int64 v63; // x11
  unsigned __int64 v64; // x12
  unsigned __int64 v65; // x12
  __int64 v66; // x11
  unsigned __int64 v67; // x12
  _QWORD *v68; // x11
  __int64 v69; // x11
  unsigned __int64 v70; // x8
  unsigned __int64 StatusReg; // x26
  __int64 v72; // x27
  __int64 v73; // [xsp+8h] [xbp-28h] BYREF
  __int64 v74; // [xsp+10h] [xbp-20h]
  _WORD *v75; // [xsp+18h] [xbp-18h]
  _WORD *v76; // [xsp+20h] [xbp-10h]
  __int64 v77; // [xsp+28h] [xbp-8h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  a3[20] = 0;
  a3[21] = 0;
  a3[18] = 0;
  a3[19] = 0;
  a3[16] = 0;
  a3[17] = 0;
  a3[14] = 0;
  a3[15] = 0;
  a3[12] = 0;
  a3[13] = 0;
  a3[10] = 0;
  a3[11] = 0;
  a3[8] = 0;
  a3[9] = 0;
  a3[6] = 0;
  a3[7] = 0;
  a3[4] = 0;
  a3[5] = 0;
  a3[2] = 0;
  a3[3] = 0;
  *a3 = 0;
  a3[1] = 0;
  v4 = a2[313];
  if ( v4 )
    LODWORD(v4) = *(unsigned __int8 *)(v4 + 4);
  *(_DWORD *)a3 = v4;
  v5 = a2[14];
  if ( v5 )
  {
    a3[1] = v5 + 4;
    v6 = (unsigned __int16)(*(_WORD *)a2[14] - 4) == 0;
    a3[12] = (unsigned __int16)(*(_WORD *)a2[14] - 4);
    if ( v6 )
      goto LABEL_89;
    v7 = (_WORD **)(a2 + 15);
    v8 = a2[15];
    if ( !v8 )
    {
      v9 = a2[42];
      if ( !v9 )
        goto LABEL_8;
      goto LABEL_7;
    }
  }
  else
  {
    v7 = (_WORD **)(a2 + 15);
    v8 = a2[15];
    if ( !v8 )
      goto LABEL_89;
  }
  a3[2] = v8 + 4;
  a3[13] = (unsigned __int16)(**v7 - 4);
  v9 = a2[42];
  if ( v9 )
  {
LABEL_7:
    a3[3] = v9 + 4;
    a3[14] = (unsigned __int16)(*(_WORD *)a2[42] - 4);
  }
LABEL_8:
  v10 = a2[127];
  if ( v10 )
  {
    a3[4] = v10 + 4;
    a3[15] = (unsigned __int16)(*(_WORD *)a2[127] - 4);
  }
  v11 = a2[128];
  if ( v11 )
  {
    a3[5] = v11 + 4;
    a3[16] = (unsigned __int16)(*(_WORD *)a2[128] - 4);
  }
  v12 = a2[145];
  if ( v12 )
  {
    a3[6] = v12 + 4;
    a3[17] = (unsigned __int16)(*(_WORD *)a2[145] - 4);
  }
  v13 = (_WORD *)a2[270];
  if ( v13 )
  {
    v75 = nullptr;
    v76 = nullptr;
    v14 = a1;
    v15 = a2;
    v73 = 0;
    v74 = 0;
    v16 = a4;
    v17 = a3;
    result = _nla_parse(&v73, 3, v13 + 2, (unsigned __int16)(*v13 - 4), 0, 0, 0);
    if ( (_DWORD)result )
      goto LABEL_90;
    if ( !v74 || (*(_BYTE *)(v14 + 1108) & 1) == 0 )
    {
      result = 4294967201LL;
      goto LABEL_90;
    }
    v33 = v75;
    a1 = v14;
    a3 = v17;
    *((_BYTE *)v17 + 88) = 1;
    if ( v33 )
    {
      v17[7] = v33 + 2;
      v17[18] = (unsigned __int16)(*v33 - 4);
    }
    v34 = v76;
    a4 = v16;
    a2 = v15;
    if ( v76 )
    {
      v17[8] = v76 + 2;
      v17[19] = (unsigned __int16)(*v34 - 4);
    }
  }
  else
  {
    *((_BYTE *)a3 + 88) = -1;
  }
  v19 = (_WORD *)a2[283];
  if ( !v19 )
    goto LABEL_32;
  v75 = nullptr;
  v76 = nullptr;
  v73 = 0;
  v74 = 0;
  if ( ((__int16)v19[1] & 0x80000000) == 0 )
  {
    do_trace_netlink_extack("NLA_F_NESTED is missing");
    result = 4294967274LL;
    goto LABEL_90;
  }
  v20 = a1;
  v21 = a2;
  v22 = a4;
  v23 = a3;
  result = _nla_parse(&v73, 3, v19 + 2, (unsigned __int16)(*v19 - 4), &he_bss_color_policy, 31, 0);
  if ( (_DWORD)result )
    goto LABEL_90;
  if ( !v74 )
  {
LABEL_89:
    result = 4294967274LL;
    goto LABEL_90;
  }
  v24 = v76;
  a4 = v22;
  a2 = v21;
  a1 = v20;
  a3 = v23;
  v6 = v75 == nullptr;
  v23[160] = *(_BYTE *)(v74 + 4);
  v25 = v6;
  v23[163] = 1;
  v23[161] = v25;
  v23[162] = v24 != nullptr;
LABEL_32:
  v26 = a2[307];
  if ( !v26 )
    goto LABEL_72;
  if ( !*(_BYTE *)(a1 + 2480) )
  {
LABEL_45:
    result = -22;
    goto LABEL_90;
  }
  v27 = (_WORD *)(v26 + 4);
  v28 = (unsigned __int16)(*(_WORD *)v26 - 4);
  if ( (unsigned int)v28 < 4 )
  {
    LODWORD(v29) = 0;
  }
  else
  {
    LODWORD(v29) = 0;
    v30 = (unsigned __int16 *)(v26 + 4);
    do
    {
      v31 = *v30;
      if ( v31 < 4 || v28 < v31 )
        break;
      if ( (_DWORD)v29 == 255 )
        goto LABEL_45;
      LODWORD(v29) = (_DWORD)v29 + 1;
      v32 = (v31 + 3) & 0x1FFFC;
      v28 -= v32;
      v30 = (unsigned __int16 *)((char *)v30 + v32);
    }
    while ( v28 > 3 );
  }
  v35 = (unsigned __int16 *)a2;
  v36 = a4;
  v37 = a3;
  v38 = (16LL * (unsigned int)v29) | 8;
  result = _kmalloc_noprof(v38, 3520);
  if ( !result )
  {
LABEL_96:
    result = -12;
    goto LABEL_90;
  }
LABEL_48:
  *(_BYTE *)result = (_BYTE)v29;
  v39 = (unsigned __int16)(*(_WORD *)v26 - 4);
  if ( (unsigned int)v39 >= 4 )
  {
    v40 = 0;
    do
    {
      v41 = (unsigned __int16)*v27;
      if ( v41 < 4 || v39 < v41 )
        break;
      v42 = (16LL * v40) | 8;
      v43 = v38 >= v42;
      v44 = v38 - v42;
      if ( !v43
        || v44 < 8
        || (v45 = (16LL * v40) | 8, v43 = v38 >= v45, v46 = v38 - v45, !v43)
        || v46 < 8
        || (v47 = 16LL * v40, v48 = v47 + 16, v49 = (_QWORD *)(result + 8 + v47), *v49 = v27 + 2, v38 < v48) )
      {
LABEL_95:
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v38 = (16LL * (unsigned int)v29) | 8;
        v72 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &nl80211_parse_mbssid_elems__alloc_tag;
        result = _kmalloc_noprof(v38, 3520);
        *(_QWORD *)(StatusReg + 80) = v72;
        if ( result )
          goto LABEL_48;
        goto LABEL_96;
      }
      ++v40;
      v49[1] = (unsigned __int16)(*v27 - 4);
      v50 = ((unsigned __int16)*v27 + 3) & 0x1FFFC;
      v39 -= v50;
      v27 = (_WORD *)((char *)v27 + v50);
    }
    while ( v39 > 3 );
  }
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_90;
  v37[9] = result;
  v29 = *((_WORD **)v35 + 325);
  if ( !v29 )
  {
LABEL_72:
    result = 0;
    goto LABEL_90;
  }
  v27 = v29 + 2;
  v51 = (unsigned __int16)(*v29 - 4);
  if ( (unsigned int)v51 < 4 )
  {
    v26 = 0;
  }
  else
  {
    v26 = 0;
    v35 = v29 + 2;
    do
    {
      v52 = *v35;
      if ( v52 < 4 || v51 < v52 )
        break;
      v53 = v35 + 2;
      v54 = (unsigned __int16)(v52 - 4);
      v55 = (unsigned __int16 *)((char *)v35 + v54 + 4);
      if ( (unsigned __int16)(v52 - 4) >= 2u )
      {
        do
        {
          v56 = *((unsigned __int8 *)v53 + 1);
          if ( v54 < v56 + 2 )
            break;
          v53 = (unsigned __int16 *)((char *)v53 + v56 + 2);
          v54 = (char *)v55 - (char *)v53;
        }
        while ( (char *)v55 - (char *)v53 > 1 );
      }
      if ( v55 != v53 )
      {
        do_trace_netlink_extack("malformed information elements");
        result = -22;
        if ( v36 )
        {
          *v36 = "malformed information elements";
          v36[1] = v35;
          v36[2] = 0;
        }
        goto LABEL_90;
      }
      v26 = (unsigned int)(v26 + 1);
      v57 = (v52 + 3) & 0x1FFFC;
      v51 -= v57;
      v35 = (unsigned __int16 *)((char *)v35 + v57);
    }
    while ( v51 > 3 );
  }
  v58 = (16LL * (unsigned __int8)v26) | 8;
  result = _kmalloc_noprof(v58, 3520);
  if ( !result )
  {
    result = -12;
    goto LABEL_90;
  }
  *(_BYTE *)result = v26;
  v59 = (unsigned __int16)(*v29 - 4);
  if ( (unsigned int)v59 >= 4 )
  {
    v60 = 0;
    do
    {
      v61 = (unsigned __int16)*v27;
      if ( v61 < 4 || v59 < v61 )
        break;
      v62 = (16LL * v60) | 8;
      v43 = v58 >= v62;
      v63 = v58 - v62;
      if ( !v43 )
        goto LABEL_95;
      if ( v63 < 8 )
        goto LABEL_95;
      v64 = (16LL * v60) | 8;
      v43 = v58 >= v64;
      v65 = v58 - v64;
      if ( !v43 )
        goto LABEL_95;
      if ( v65 < 8 )
        goto LABEL_95;
      v66 = 16LL * v60;
      v67 = v66 + 16;
      v68 = (_QWORD *)(result + 8 + v66);
      *v68 = v27 + 2;
      if ( v58 < v67 )
        goto LABEL_95;
      ++v60;
      v68[1] = (unsigned __int16)(*v27 - 4);
      v69 = ((unsigned __int16)*v27 + 3) & 0x1FFFC;
      v59 -= v69;
      v27 = (_WORD *)((char *)v27 + v69);
    }
    while ( v59 > 3 );
  }
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    if ( *(unsigned __int8 *)v37[9] <= (unsigned int)(unsigned __int8)v26 )
    {
      v70 = result;
      result = 0;
      v37[10] = v70;
      goto LABEL_90;
    }
    goto LABEL_89;
  }
LABEL_90:
  _ReadStatusReg(SP_EL0);
  return result;
}
