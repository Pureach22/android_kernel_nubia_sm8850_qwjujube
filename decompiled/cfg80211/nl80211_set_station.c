__int64 __fastcall nl80211_set_station(__int64 a1, _QWORD *a2)
{
  _BYTE *v2; // x19
  __int64 v3; // x20
  _QWORD *v4; // x8
  __int64 v5; // x9
  __int64 v6; // x9
  __int64 v7; // x9
  int v8; // w9
  __int64 v9; // x9
  int v10; // w9
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x10
  __int64 v14; // x21
  int v15; // w10
  _BYTE *v16; // x9
  __int64 v17; // x9
  __int16 v18; // w9
  _BYTE *v19; // x8
  unsigned int v21; // w22
  _QWORD *v22; // x8
  _QWORD *v23; // x0
  __int64 v24; // x9
  __int64 v25; // x9
  __int64 v26; // x9
  __int64 v27; // x9
  __int64 v28; // x9
  __int64 v29; // x9
  __int64 v30; // x9
  int v31; // w9
  __int64 v32; // x9
  _BYTE *v33; // x10
  __int64 v35; // x9
  __int64 v36; // x9
  __int64 v37; // x9
  __int64 v38; // x9
  _BYTE *v39; // x10
  _BYTE *v40; // x9
  unsigned __int8 v41; // w24
  int v42; // w10
  int v43; // w11
  int v44; // w10
  int v45; // w22
  _QWORD *v46; // x8
  __int16 v47; // w25
  int v48; // w0
  __int16 *v49; // x9
  __int16 v50; // w9
  _BYTE *v51; // x9
  _WORD *v52; // x2
  unsigned int v53; // w8
  unsigned int v54; // w8
  unsigned __int64 vlan; // x0
  __int64 v56; // x1
  __int64 v57; // x2
  unsigned int v58; // w8
  _QWORD v59[2]; // [xsp+0h] [xbp-100h] BYREF
  __int64 v60; // [xsp+10h] [xbp-F0h]
  __int64 v61; // [xsp+18h] [xbp-E8h]
  __int64 v62; // [xsp+20h] [xbp-E0h]
  __int64 v63; // [xsp+28h] [xbp-D8h]
  _BYTE *v64; // [xsp+30h] [xbp-D0h]
  __int64 v65; // [xsp+38h] [xbp-C8h]
  _WORD *v66; // [xsp+40h] [xbp-C0h]
  __int64 v67; // [xsp+48h] [xbp-B8h]
  _BYTE *v68; // [xsp+50h] [xbp-B0h]
  __int64 v69; // [xsp+58h] [xbp-A8h]
  __int64 v70; // [xsp+60h] [xbp-A0h]
  __int64 v71; // [xsp+68h] [xbp-98h]
  __int64 v72; // [xsp+70h] [xbp-90h]
  __int64 v73; // [xsp+78h] [xbp-88h]
  _BYTE *v74; // [xsp+80h] [xbp-80h]
  __int64 v75; // [xsp+88h] [xbp-78h]
  __int64 v76; // [xsp+90h] [xbp-70h]
  __int64 v77; // [xsp+98h] [xbp-68h]
  __int64 v78; // [xsp+A0h] [xbp-60h]
  _BYTE *v79; // [xsp+A8h] [xbp-58h]
  __int64 v80; // [xsp+B0h] [xbp-50h]
  __int64 v81; // [xsp+B8h] [xbp-48h]
  __int64 v82; // [xsp+C0h] [xbp-40h]
  _BYTE *v83; // [xsp+C8h] [xbp-38h]
  __int64 v84; // [xsp+D0h] [xbp-30h]
  __int64 v85; // [xsp+D8h] [xbp-28h]
  __int64 v86; // [xsp+E0h] [xbp-20h] BYREF
  __int64 v87; // [xsp+E8h] [xbp-18h]
  __int64 v88; // [xsp+F0h] [xbp-10h]
  __int64 v89; // [xsp+F8h] [xbp-8h]

  v89 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (_BYTE *)a2[6];
  v3 = a2[7];
  v84 = 0;
  v85 = 0;
  v82 = 0;
  v83 = nullptr;
  v80 = 0;
  v81 = 0;
  v78 = 0;
  v79 = nullptr;
  v76 = 0;
  v77 = 0;
  v74 = nullptr;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = nullptr;
  v69 = 0;
  v66 = nullptr;
  v67 = 0;
  v64 = nullptr;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  v60 = 0;
  v61 = 0;
  v59[0] = 0;
  v59[1] = 0;
  if ( !*(_QWORD *)(*(_QWORD *)v2 + 152LL) )
    goto LABEL_48;
  v4 = (_QWORD *)a2[4];
  v5 = v4[16];
  if ( v5 )
    LOWORD(v61) = *(_WORD *)(v5 + 4);
  v6 = v4[282];
  if ( v6 )
    WORD1(v61) = *(_WORD *)(v6 + 4);
  v7 = v4[18];
  if ( v7 )
    v8 = *(unsigned __int16 *)(v7 + 4);
  else
    v8 = -1;
  HIDWORD(v60) = v8;
  v9 = v4[228];
  if ( v9 )
    v10 = *(unsigned __int8 *)(v9 + 4);
  else
    v10 = -1;
  HIDWORD(v69) = v10;
  v11 = v4[6];
  if ( !v11 )
    goto LABEL_27;
  v12 = v4[313];
  if ( !v12 )
  {
    LODWORD(v72) = -1;
    if ( v4[314] )
      goto LABEL_27;
    goto LABEL_19;
  }
  LODWORD(v72) = *(unsigned __int8 *)(v12 + 4);
  v13 = v4[314];
  if ( !v13 )
  {
LABEL_19:
    v14 = v11 + 4;
    goto LABEL_20;
  }
  v14 = v13 + 4;
  v71 = v13 + 4;
  v73 = v11 + 4;
  v15 = *(_DWORD *)(v11 + 4);
  if ( (v15 & 1) != 0 || !(v15 | *(unsigned __int16 *)(v11 + 8)) )
    goto LABEL_27;
LABEL_20:
  v16 = (_BYTE *)v4[19];
  if ( v16 )
  {
    v74 = v16 + 4;
    LOBYTE(v75) = *v16 - 4;
  }
  v17 = v4[171];
  if ( v17 )
  {
    v18 = *(_WORD *)(v17 + 4);
    LODWORD(v60) = 2;
    LOWORD(v63) = v18;
  }
  v19 = (_BYTE *)v4[172];
  if ( v19 )
  {
    v64 = v19 + 4;
    LOBYTE(v65) = *v19 - 4;
  }
  if ( (unsigned int)parse_station_flags(a2, *(unsigned int *)(*(_QWORD *)(v3 + 992) + 8LL), v59) )
    goto LABEL_27;
  v22 = (_QWORD *)a2[4];
  v23 = a2;
  v24 = v22[25];
  if ( v24 )
    BYTE6(v61) = *(_BYTE *)(v24 + 4);
  v25 = v22[116];
  if ( v25 )
  {
    HIBYTE(v61) = *(_BYTE *)(v25 + 4);
    v26 = v22[237];
    if ( v26 )
      WORD2(v61) = *(_WORD *)(v26 + 4);
    LODWORD(v60) = v60 | 4;
  }
  v27 = v22[164];
  if ( v27 )
    HIDWORD(v62) = *(_DWORD *)(v27 + 4);
  v28 = v22[194];
  if ( v28 )
  {
    BYTE1(v78) = 1;
    LOBYTE(v78) = *(_BYTE *)(v28 + 4);
  }
  v29 = v22[293];
  if ( v29 )
    v82 = v29 + 4;
  v30 = v22[274];
  if ( v30 )
  {
    v31 = *(unsigned __int16 *)(v30 + 4);
    LOWORD(v70) = v31;
    if ( !v31 )
      goto LABEL_45;
  }
  else if ( !(_WORD)v70 )
  {
    goto LABEL_45;
  }
  if ( (v2[1108] & 2) == 0 )
  {
LABEL_48:
    v21 = -95;
    goto LABEL_49;
  }
LABEL_45:
  v32 = v22[275];
  if ( v32 )
  {
    v33 = (_BYTE *)a2[6];
    if ( !*(_QWORD *)(*(_QWORD *)v33 + 424LL) || (v33[1108] & 0x20) == 0 )
      goto LABEL_48;
    LODWORD(v81) = *(unsigned __int8 *)(v32 + 4);
    if ( (_DWORD)v81 == 1 )
    {
      v35 = v22[276];
      if ( !v35 )
        goto LABEL_27;
      WORD2(v80) = *(_WORD *)(v35 + 4);
    }
    LOBYTE(v32) = 1;
  }
  BYTE4(v81) = v32;
  v36 = v22[181];
  if ( v36 )
    LOWORD(v61) = *(_WORD *)(v36 + 4);
  v37 = v22[31];
  if ( v37 )
    v76 = v37 + 4;
  v38 = v22[157];
  if ( v38 )
    v77 = v38 + 4;
  v39 = (_BYTE *)v22[269];
  if ( v39 )
  {
    v79 = v39 + 4;
    LOBYTE(v80) = *v39 - 4;
    v40 = (_BYTE *)v22[310];
    if ( v40 )
    {
      v21 = -22;
      v83 = v40 + 4;
      v41 = *v40 - 4;
      LOBYTE(v84) = v41;
      if ( v39 == (_BYTE *)-4LL || v41 < 0xBu )
        goto LABEL_49;
      v42 = (unsigned __int8)v39[10];
      if ( (v42 & 2) != 0 )
      {
        v45 = 14;
      }
      else
      {
        v43 = (v42 << 29 >> 31) & 3;
        if ( (v42 & 8) != 0 )
          v43 += 3;
        if ( (v40[6] & 2) != 0 )
          v44 = v43 + 3;
        else
          v44 = v43;
        if ( v44 )
          v45 = v44 + 11;
        else
          v45 = 15;
      }
      if ( (unsigned __int8)v45 > (unsigned int)v41 )
        goto LABEL_27;
      if ( (v40[11] & 8) != 0 )
      {
        if ( (unsigned __int64)(unsigned __int8)v45 + 2 > v41 )
          goto LABEL_27;
        v47 = *(_WORD *)&v40[(unsigned __int8)v45 + 4];
        v48 = _sw_hweight16(v47 & 0x1F0);
        v46 = a2;
        v45 += (v48 * (6 * (v47 & 0xFu) + 6) + 16) >> 3;
      }
      else
      {
        v46 = a2;
      }
      if ( (unsigned __int8)v45 <= (unsigned int)v41 )
      {
        v23 = v46;
        v22 = (_QWORD *)v46[4];
        goto LABEL_81;
      }
LABEL_27:
      v21 = -22;
      goto LABEL_49;
    }
  }
LABEL_81:
  v49 = (__int16 *)v22[189];
  if ( v49 )
  {
    v66 = v49 + 2;
    v50 = *v49;
    LOBYTE(v67) = v50 - 4;
    if ( (v50 & 1) != 0 )
      goto LABEL_27;
  }
  v51 = (_BYTE *)v22[190];
  if ( v51 )
  {
    v68 = v51 + 4;
    LOBYTE(v69) = *v51 - 4;
  }
  v87 = 0;
  v88 = 0;
  v86 = 0;
  v52 = (_WORD *)v22[129];
  if ( v52 )
  {
    v21 = _nla_parse(&v86, 2, v52 + 2, (unsigned __int16)(*v52 - 4), &nl80211_sta_wme_policy, 0, v23[8]);
    if ( v21 )
      goto LABEL_49;
    if ( v87 )
    {
      v53 = *(unsigned __int8 *)(v87 + 4);
      LOBYTE(v62) = *(_BYTE *)(v87 + 4);
    }
    else
    {
      v53 = (unsigned __int8)v62;
    }
    v23 = a2;
    if ( v53 > 0xF )
      goto LABEL_27;
    if ( v88 )
    {
      v54 = *(unsigned __int8 *)(v88 + 4);
      BYTE1(v62) = *(_BYTE *)(v88 + 4);
    }
    else
    {
      v54 = BYTE1(v62);
    }
    if ( v54 > 3 )
      goto LABEL_27;
    LODWORD(v60) = v60 | 1;
  }
  vlan = get_vlan(v23, v2);
  v59[0] = vlan;
  if ( vlan < 0xFFFFFFFFFFFFF001LL )
  {
    v21 = -95;
    v58 = *(_DWORD *)(*(_QWORD *)(v3 + 992) + 8LL);
    if ( v58 <= 9 && ((1 << v58) & 0x39E) != 0 )
    {
      v21 = rdev_change_station(v2, v3, v14, v59);
      vlan = v59[0];
    }
    dev_put(vlan, v56, v57);
  }
  else
  {
    v21 = vlan;
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return v21;
}
