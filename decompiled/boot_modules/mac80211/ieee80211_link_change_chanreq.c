__int64 __fastcall ieee80211_link_change_chanreq(__int64 *a1, __int64 *a2, _QWORD *a3)
{
  __int64 v6; // x8
  __int64 v7; // x20
  __int64 v8; // x21
  __int64 v9; // x9
  _QWORD *v10; // x26
  _QWORD *v11; // x10
  __int64 v12; // x24
  bool v13; // zf
  __int64 *v14; // x0
  __int64 v15; // x21
  __int64 i; // x28
  __int64 v17; // x20
  __int64 v18; // x22
  __int64 v19; // x21
  __int64 v20; // x8
  __int64 *v21; // x24
  __int64 v22; // x9
  __int64 *v23; // x0
  __int64 v24; // x9
  __int64 v25; // x8
  __int64 v26; // x11
  __int64 *v27; // x9
  __int64 v28; // x10
  __int64 v29; // x11
  __int64 v30; // x8
  __int64 v31; // x9
  _QWORD *v32; // t2
  __int64 v33; // x8
  __int64 *v34; // x22
  __int64 v35; // x9
  __int64 *v36; // x0
  __int64 v37; // x9
  __int64 v38; // x8
  __int64 v39; // x11
  __int64 *v40; // x9
  __int64 v41; // x10
  __int64 v42; // x11
  __int64 v43; // x8
  __int64 v44; // x9
  _QWORD *v45; // t2
  __int64 result; // x0
  __int64 v47; // x8
  __int64 v48; // x10
  __int64 v49; // x11
  __int64 v50; // x8
  __int64 v51; // x10
  __int64 v52; // x11
  int v53; // w8
  __int64 *v54; // x20
  __int64 *v55; // x21
  __int64 *v56; // t1
  __int64 v57; // x8
  __int64 *v58; // x0
  __int64 v59; // x8
  __int64 v60; // x10
  __int64 v61; // x11
  __int64 *v62; // x8
  __int64 v63; // x9
  __int64 v64; // x10
  __int64 v65; // x8
  __int64 v66; // x11
  __int64 v67; // x11
  _QWORD *v68; // x9
  __int64 v69; // x13
  __int64 v70; // x14
  __int64 v71; // x10
  __int64 v72; // x8
  __int64 v73; // x11
  __int64 v74; // x13
  __int64 v75; // x14
  _QWORD *v76; // x9
  _QWORD *v77; // x10
  _QWORD *v78; // x11
  __int64 v79; // x12
  __int64 v80; // x14
  __int64 v81; // x15
  __int64 v82; // x12
  __int64 v83; // x14
  __int64 v84; // x15
  __int64 v85; // [xsp+8h] [xbp-68h]
  _QWORD *v86; // [xsp+10h] [xbp-60h]
  _QWORD *v87; // [xsp+18h] [xbp-58h]
  __int64 v88; // [xsp+20h] [xbp-50h]
  __int64 v89; // [xsp+28h] [xbp-48h] BYREF
  __int64 v90; // [xsp+30h] [xbp-40h]
  __int64 v91; // [xsp+38h] [xbp-38h]
  __int64 v92; // [xsp+40h] [xbp-30h]
  __int64 v93; // [xsp+48h] [xbp-28h] BYREF
  __int64 v94; // [xsp+50h] [xbp-20h]
  __int64 v95; // [xsp+58h] [xbp-18h]
  __int64 v96; // [xsp+60h] [xbp-10h]
  __int64 v97; // [xsp+68h] [xbp-8h]

  v97 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a1;
  v7 = a1[118];
  v95 = 0;
  v96 = 0;
  v93 = 0;
  v94 = 0;
  v8 = *(_QWORD *)(v6 + 1616);
  v91 = 0;
  v92 = 0;
  v89 = 0;
  v90 = 0;
  if ( (cfg80211_chandef_usable(*(_QWORD *)(v8 + 72), a2, 1) & 1) == 0 )
    goto LABEL_48;
  if ( !*((_DWORD *)a2 + 2) )
  {
    if ( *a2 == *(_QWORD *)(v7 + 136)
      && !*(_DWORD *)(v7 + 144)
      && *((_DWORD *)a2 + 3) == *(_DWORD *)(v7 + 148)
      && *((unsigned __int16 *)a2 + 14) == *(unsigned __int16 *)(v7 + 164)
      && *((_DWORD *)a2 + 4) == *(_DWORD *)(v7 + 152)
      && *((unsigned __int16 *)a2 + 15) == *(unsigned __int16 *)(v7 + 166) )
    {
      result = 0;
      goto LABEL_49;
    }
LABEL_48:
    result = 4294967274LL;
    goto LABEL_49;
  }
  if ( !*(_DWORD *)(v7 + 144) )
    goto LABEL_48;
  v9 = *(_QWORD *)(v7 + 832);
  if ( !v9 )
    goto LABEL_48;
  v10 = *(_QWORD **)(v8 + 4616);
  v85 = v8;
  v86 = a3;
  v11 = (_QWORD *)(v8 + 4616);
  v12 = v9 - 152;
  v13 = v10 == (_QWORD *)(v8 + 4616);
  v14 = a2;
  v15 = *(_QWORD *)(v7 + 832);
  v87 = v11;
  if ( !v13 )
  {
    v14 = a2;
    v88 = *(_QWORD *)(v7 + 832);
    do
    {
      if ( (v10[204] & 1) != 0 )
      {
        for ( i = 0; i != 15; ++i )
        {
          v17 = v10[i + 571];
          if ( v17 && (__int64 *)v17 != a1 )
          {
            v18 = *(_QWORD *)(v17 + 944);
            if ( *(_QWORD *)(v18 + 832) == v15 )
            {
              v19 = v12;
              v21 = v14 + 4;
              v20 = v14[4];
              if ( v20 )
              {
                v22 = *(_QWORD *)(v18 + 168);
                if ( v22 )
                {
                  if ( v20 != v22
                    || *((_DWORD *)v14 + 10) != *(_DWORD *)(v18 + 176)
                    || *((_DWORD *)v14 + 11) != *(_DWORD *)(v18 + 180)
                    || *((unsigned __int16 *)v14 + 30) != *(unsigned __int16 *)(v18 + 196)
                    || *((_DWORD *)v14 + 12) != *(_DWORD *)(v18 + 184)
                    || *((unsigned __int16 *)v14 + 31) != *(unsigned __int16 *)(v18 + 198) )
                  {
                    goto LABEL_48;
                  }
                }
              }
              v23 = (__int64 *)cfg80211_chandef_compatible(v14, v18 + 136);
              if ( !v23 )
                goto LABEL_48;
              v24 = v23[3];
              v13 = *v21 == 0;
              v25 = *v23;
              v26 = v23[1];
              v91 = v23[2];
              v92 = v24;
              if ( v13 )
                v27 = (__int64 *)(v18 + 168);
              else
                v27 = v21;
              v12 = v19;
              v15 = v88;
              v14 = &v89;
              v89 = v25;
              v90 = v26;
              v28 = *v27;
              v29 = v27[1];
              v32 = v27 + 2;
              v31 = v27[2];
              v30 = v32[1];
              v93 = v28;
              v94 = v29;
              v95 = v31;
              v96 = v30;
            }
            if ( *(_QWORD *)(v17 + 368) == v12 )
            {
              v34 = v14 + 4;
              v33 = v14[4];
              if ( v33 )
              {
                v35 = *(_QWORD *)(v17 + 408);
                if ( v35 )
                {
                  if ( v33 != v35
                    || *((_DWORD *)v14 + 10) != *(_DWORD *)(v17 + 416)
                    || *((_DWORD *)v14 + 11) != *(_DWORD *)(v17 + 420)
                    || *((unsigned __int16 *)v14 + 30) != *(unsigned __int16 *)(v17 + 436)
                    || *((_DWORD *)v14 + 12) != *(_DWORD *)(v17 + 424)
                    || *((unsigned __int16 *)v14 + 31) != *(unsigned __int16 *)(v17 + 438) )
                  {
                    goto LABEL_48;
                  }
                }
              }
              v36 = (__int64 *)cfg80211_chandef_compatible(v14, v17 + 376);
              if ( !v36 )
                goto LABEL_48;
              v37 = v36[3];
              v13 = *v34 == 0;
              v38 = *v36;
              v39 = v36[1];
              v91 = v36[2];
              v92 = v37;
              if ( v13 )
                v40 = (__int64 *)(v17 + 408);
              else
                v40 = v34;
              v14 = &v89;
              v89 = v38;
              v90 = v39;
              v41 = *v40;
              v42 = v40[1];
              v45 = v40 + 2;
              v44 = v40[2];
              v43 = v45[1];
              v93 = v41;
              v94 = v42;
              v95 = v44;
              v96 = v43;
            }
          }
        }
      }
      v10 = (_QWORD *)*v10;
    }
    while ( v10 != v87 );
  }
  v47 = v14[3];
  v48 = *v14;
  v49 = v14[1];
  v91 = v14[2];
  v92 = v47;
  v89 = v48;
  v90 = v49;
  v50 = v14[7];
  v51 = v14[4];
  v52 = v14[5];
  v95 = v14[6];
  v96 = v50;
  v93 = v51;
  v94 = v52;
  v53 = *(_DWORD *)(v15 - 88);
  switch ( v53 )
  {
    case 2:
      __break(0x800u);
      break;
    case 1:
LABEL_68:
      result = 4294967280LL;
      goto LABEL_49;
    case 0:
      v56 = *(__int64 **)(v15 - 104);
      v55 = (__int64 *)(v15 - 104);
      v54 = v56;
      if ( v56 != v55 )
      {
        while ( 1 )
        {
          v57 = v54[47];
          if ( v57 )
          {
            if ( v93
              && (v57 != v93
               || *((_DWORD *)v54 + 96) != (_DWORD)v94
               || *((_DWORD *)v54 + 97) != HIDWORD(v94)
               || *((unsigned __int16 *)v54 + 202) != WORD2(v96)
               || *((_DWORD *)v54 + 98) != (_DWORD)v95
               || *((unsigned __int16 *)v54 + 203) != HIWORD(v96)) )
            {
              goto LABEL_68;
            }
          }
          v58 = (__int64 *)cfg80211_chandef_compatible(v54 + 43, &v89);
          if ( !v58 )
            goto LABEL_68;
          v59 = v58[3];
          v60 = *v58;
          v61 = v58[1];
          v91 = v58[2];
          v92 = v59;
          v89 = v60;
          v90 = v61;
          if ( v54[47] )
            v62 = v54 + 47;
          else
            v62 = &v93;
          v64 = v62[2];
          v63 = v62[3];
          v66 = *v62;
          v65 = v62[1];
          v95 = v64;
          v96 = v63;
          v93 = v66;
          v94 = v65;
          v54 = (__int64 *)*v54;
          if ( v54 == v55 )
            goto LABEL_70;
        }
      }
      break;
  }
LABEL_70:
  v67 = a2[7];
  v68 = (_QWORD *)a1[118];
  v70 = a2[4];
  v69 = a2[5];
  v71 = *a1;
  v72 = *((unsigned int *)a1 + 2);
  v68[23] = a2[6];
  v68[24] = v67;
  v68[21] = v70;
  v68[22] = v69;
  v73 = a2[3];
  v74 = *a2;
  v75 = a2[1];
  v68[19] = a2[2];
  v68[20] = v73;
  v68[17] = v74;
  v68[18] = v75;
  if ( *(_DWORD *)(v71 + 4720) == 3 )
  {
    v76 = *(_QWORD **)(v71 + 2264);
    v77 = (_QWORD *)(v71 + 2264);
    if ( v76 != v77 )
    {
      if ( (unsigned int)v72 <= 0xE )
        goto LABEL_75;
      __break(0x5512u);
LABEL_74:
      __break(0x800u);
      while ( 1 )
      {
        v76 = (_QWORD *)*v76;
        if ( v76 == v77 )
          break;
LABEL_75:
        v78 = (_QWORD *)v76[v72 + 427];
        if ( !v78 )
          goto LABEL_74;
        v79 = a2[3];
        v80 = *a2;
        v81 = a2[1];
        v78[19] = a2[2];
        v78[20] = v79;
        v78[17] = v80;
        v78[18] = v81;
        v82 = a2[7];
        v83 = a2[4];
        v84 = a2[5];
        v78[23] = a2[6];
        v78[24] = v82;
        v78[21] = v83;
        v78[22] = v84;
      }
    }
  }
  ((void (__fastcall *)(__int64, __int64))ieee80211_recalc_chanctx_chantype)(v85, v12);
  result = 0;
  *v86 |= 0x200000uLL;
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
