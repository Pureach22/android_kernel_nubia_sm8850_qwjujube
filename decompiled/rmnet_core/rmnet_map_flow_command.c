__int64 __fastcall rmnet_map_flow_command(__int64 a1, __int64 a2, char a3)
{
  int v3; // w8
  __int64 v5; // x8
  unsigned __int64 v6; // x9
  __int64 v7; // x10
  int v8; // w8
  __int64 result; // x0
  unsigned int v10; // w8
  int v11; // w23
  unsigned __int64 v12; // x20
  int v13; // w8
  unsigned int v14; // w8
  int v15; // w23
  unsigned __int64 v16; // x20
  int v17; // w8
  unsigned int v18; // w8
  int v19; // w22
  unsigned int v20; // w9
  __int64 v21; // x9
  int v22; // w8
  char v23; // w23
  unsigned int *v24; // x21
  __int64 v25; // x8
  __int64 v26; // x9
  __int64 v27; // x20
  _QWORD *i; // x24
  void (__fastcall *v29)(_QWORD); // x8
  unsigned int v30; // w8
  unsigned int v31; // w19
  unsigned int v32; // w9
  unsigned int v33; // w9
  __int64 v34; // x9
  int v35; // w8
  __int64 v36; // x9
  __int64 v37; // x10
  unsigned int v38; // w9
  __int64 v39; // x9
  int v40; // w8
  __int64 v41; // x8
  __int64 v42; // x9
  unsigned int v43; // w9
  unsigned int v44; // w8
  __int64 v45; // x8
  char v46; // w24
  unsigned int *v47; // x22
  __int64 v48; // x8
  __int64 v49; // x9
  unsigned int v50; // w9
  __int64 v51; // x8
  char v52; // w24
  unsigned int *v53; // x22
  __int64 v54; // x8
  __int64 v55; // x9
  __int64 v56; // x20
  char v57; // w21
  __int64 v58; // x0
  __int64 v59; // x8
  char v60; // w22
  __int64 v61; // x21
  __int64 v62; // x20
  char v63; // w21
  __int64 v64; // x0
  __int64 v65; // x8
  __int64 v66; // x20
  char v67; // w21
  __int64 v68; // x0
  __int64 v69; // x8
  char v70; // w22
  __int64 v71; // x21
  __int64 v72; // x9
  __int64 v73; // x21
  _QWORD *v74; // x25
  _QWORD *j; // x19
  void (__fastcall *v76)(unsigned int *, unsigned __int64); // x8
  int v77; // w9
  bool v78; // zf
  int v79; // w10
  int v80; // w11
  __int64 v81; // x9
  __int64 v82; // x10
  __int64 v83; // x8
  __int64 v84; // x8
  __int64 v85; // x11
  __int64 v86; // x9
  __int64 v87; // x10
  __int64 v88; // x8
  _QWORD *v89; // x25
  _QWORD *k; // x19
  void (__fastcall *v91)(unsigned int *, unsigned __int64); // x8
  unsigned int v92; // w9
  __int64 v93; // x10

  v3 = *(_DWORD *)(a1 + 116);
  if ( v3 && *(_DWORD *)(a1 + 112) == v3 )
  {
    v5 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
    v6 = 0;
    v7 = *(_QWORD *)(v5 + 88);
    if ( v7 && (v7 & 1) == 0 )
      v6 = (((v7 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL) + *(unsigned int *)(v5 + 100);
  }
  else
  {
    v6 = *(_QWORD *)(a1 + 224);
  }
  v8 = *(unsigned __int8 *)(v6 + 4);
  if ( *(_DWORD *)(a1 + 144) == 55834 && (unsigned int)(v8 - 7) <= 1 )
    goto LABEL_9;
  if ( v8 == 35 )
  {
    v18 = *(_DWORD *)(a1 + 112);
    if ( v18 < 0x1C )
      goto LABEL_9;
    v19 = *(_DWORD *)(a2 + 8);
    if ( (v19 & 0x20000000) != 0 )
    {
      v20 = v18 - *(_DWORD *)(a1 + 116);
      if ( v20 <= 0xB )
      {
        v62 = a1;
        v63 = a3;
        v64 = _pskb_pull_tail(a1, 12 - v20);
        a3 = v63;
        v65 = v64;
        a1 = v62;
        if ( !v65 )
          goto LABEL_28;
        v18 = *(_DWORD *)(v62 + 112);
      }
      v21 = *(_QWORD *)(a1 + 224);
      *(_DWORD *)(a1 + 112) = v18 - 12;
      *(_QWORD *)(a1 + 224) = v21 + 12;
    }
LABEL_28:
    v22 = *(_DWORD *)(a1 + 116);
    if ( v22 && *(_DWORD *)(a1 + 112) == v22 )
    {
      v23 = a3;
      v24 = nullptr;
      v25 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
      v26 = *(_QWORD *)(v25 + 88);
      if ( v26 && (v26 & 1) == 0 )
        v24 = (unsigned int *)((((v26 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                             + *(unsigned int *)(v25 + 100));
    }
    else
    {
      v24 = *(unsigned int **)(a1 + 224);
      v23 = a3;
    }
    v27 = a1;
    ++*(_QWORD *)(a2 + 2712);
    if ( (v19 & 0x20000000) != 0 )
    {
      for ( i = *(_QWORD **)(a2 + 2752); i != (_QWORD *)(a2 + 2752); i = (_QWORD *)*i )
      {
        *(_QWORD *)(a2 + 2720) = *v24;
        v29 = (void (__fastcall *)(_QWORD))*(i - 1);
        if ( *((_DWORD *)v29 - 1) != 362581883 )
          __break(0x8228u);
        v29(v24);
      }
    }
    a1 = v27;
    if ( (v23 & 1) == 0 )
      goto LABEL_10;
    v30 = *(_DWORD *)(v27 + 112);
    if ( (v19 & 4) != 0 )
      v31 = 24;
    else
      v31 = 16;
    v32 = v30 - *(_DWORD *)(v27 + 116);
    if ( v31 > v32 )
    {
      if ( v30 < v31 )
        return 0;
      result = _pskb_pull_tail(v27, v31 - v32);
      if ( !result )
        return result;
      v30 = *(_DWORD *)(v27 + 112);
      a1 = v27;
    }
LABEL_110:
    v93 = *(_QWORD *)(a1 + 224);
    *(_DWORD *)(a1 + 112) = v30 - v31;
    *(_QWORD *)(a1 + 224) = v93 + v31;
    return 0;
  }
  if ( v8 == 8 )
  {
    v14 = *(_DWORD *)(a1 + 112);
    if ( v14 < 0x10 )
      goto LABEL_9;
    v15 = *(_DWORD *)(a2 + 8);
    if ( (v15 & 0x20000000) == 0 )
    {
      v16 = 0;
      v17 = *(_DWORD *)(a1 + 116);
      if ( !v17 )
        goto LABEL_89;
LABEL_65:
      if ( *(_DWORD *)(a1 + 112) == v17 )
      {
        v46 = a3;
        v47 = nullptr;
        v48 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
        v49 = *(_QWORD *)(v48 + 88);
        if ( v49 && (v49 & 1) == 0 )
          v47 = (unsigned int *)((((v49 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                               + *(unsigned int *)(v48 + 100));
        goto LABEL_90;
      }
LABEL_89:
      v47 = *(unsigned int **)(a1 + 224);
      v46 = a3;
LABEL_90:
      v72 = *(_QWORD *)(a2 + 2584);
      v73 = a1;
      *(_QWORD *)(a2 + 2576) = *v47;
      *(_QWORD *)(a2 + 2584) = v72 + 1;
      if ( (v15 & 0x20000000) != 0 )
      {
        v74 = *(_QWORD **)(a2 + 2480);
        for ( j = (_QWORD *)(a2 + 2480); v74 != j; v74 = (_QWORD *)*v74 )
        {
          v76 = (void (__fastcall *)(unsigned int *, unsigned __int64))*(v74 - 1);
          if ( *((_DWORD *)v76 - 1) != -686379878 )
            __break(0x8228u);
          v76(v47, v16);
        }
      }
      a1 = v73;
      if ( (v46 & 1) == 0 )
        goto LABEL_10;
      v30 = *(_DWORD *)(v73 + 112);
      v77 = *(_DWORD *)(v73 + 116);
      v78 = (v15 & 4) == 0;
      v79 = 12;
      v80 = 4;
      goto LABEL_106;
    }
    v33 = v14 - *(_DWORD *)(a1 + 116);
    if ( v33 <= 3 )
    {
      v56 = a1;
      v57 = a3;
      v58 = _pskb_pull_tail(a1, 4 - v33);
      a3 = v57;
      v59 = v58;
      a1 = v56;
      if ( !v59 )
        goto LABEL_50;
      v14 = *(_DWORD *)(v56 + 112);
    }
    v34 = *(_QWORD *)(a1 + 224);
    *(_DWORD *)(a1 + 112) = v14 - 4;
    *(_QWORD *)(a1 + 224) = v34 + 4;
LABEL_50:
    v35 = *(_DWORD *)(a1 + 116);
    if ( v35 && *(_DWORD *)(a1 + 112) == v35 )
    {
      v16 = 0;
      v36 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
      v37 = *(_QWORD *)(v36 + 88);
      if ( v37 && (v37 & 1) == 0 )
      {
        v35 = *(_DWORD *)(a1 + 116);
        v16 = (((v37 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
            + *(unsigned int *)(v36 + 100);
      }
    }
    else
    {
      v16 = *(_QWORD *)(a1 + 224);
    }
    v43 = *(_DWORD *)(a1 + 112);
    v44 = v43 - v35;
    if ( v44 <= 7 )
    {
      v60 = a3;
      v61 = a1;
      if ( v43 < 8 || !_pskb_pull_tail(a1, 8 - v44) )
      {
        a1 = v61;
        a3 = v60;
        v17 = *(_DWORD *)(v61 + 116);
        if ( !v17 )
          goto LABEL_89;
        goto LABEL_65;
      }
      v43 = *(_DWORD *)(v61 + 112);
      a1 = v61;
      a3 = v60;
    }
    v45 = *(_QWORD *)(a1 + 224);
    *(_DWORD *)(a1 + 112) = v43 - 8;
    *(_QWORD *)(a1 + 224) = v45 + 8;
    v17 = *(_DWORD *)(a1 + 116);
    if ( !v17 )
      goto LABEL_89;
    goto LABEL_65;
  }
  if ( v8 != 7 )
    return 1;
  v10 = *(_DWORD *)(a1 + 112);
  if ( v10 < 0x1C )
  {
LABEL_9:
    if ( (a3 & 1) != 0 )
      return 0;
LABEL_10:
    consume_skb(a1);
    return 0;
  }
  v11 = *(_DWORD *)(a2 + 8);
  if ( (v11 & 0x20000000) == 0 )
  {
    v12 = 0;
    v13 = *(_DWORD *)(a1 + 116);
    if ( !v13 )
      goto LABEL_98;
    goto LABEL_72;
  }
  v38 = v10 - *(_DWORD *)(a1 + 116);
  if ( v38 <= 3 )
  {
    v66 = a1;
    v67 = a3;
    v68 = _pskb_pull_tail(a1, 4 - v38);
    a3 = v67;
    v69 = v68;
    a1 = v66;
    if ( !v69 )
      goto LABEL_57;
    v10 = *(_DWORD *)(v66 + 112);
  }
  v39 = *(_QWORD *)(a1 + 224);
  *(_DWORD *)(a1 + 112) = v10 - 4;
  *(_QWORD *)(a1 + 224) = v39 + 4;
LABEL_57:
  v40 = *(_DWORD *)(a1 + 116);
  if ( v40 && *(_DWORD *)(a1 + 112) == v40 )
  {
    v12 = 0;
    v41 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
    v42 = *(_QWORD *)(v41 + 88);
    if ( v42 && (v42 & 1) == 0 )
      v12 = (((v42 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
          + *(unsigned int *)(v41 + 100);
  }
  else
  {
    v12 = *(_QWORD *)(a1 + 224);
  }
  *(_QWORD *)(a2 + 2504) = *(_WORD *)(v12 + 2) & 0x7FFF;
  *(_QWORD *)(a2 + 2496) = ((unsigned __int64)*(unsigned __int8 *)(v12 + 1) >> 2) & 0x1F;
  *(_QWORD *)(a2 + 2512) = *(unsigned int *)(v12 + 4);
  v50 = *(_DWORD *)(a1 + 112);
  v13 = *(_DWORD *)(a1 + 116);
  if ( v50 - v13 > 7 )
    goto LABEL_71;
  v70 = a3;
  v71 = a1;
  if ( v50 >= 8 )
  {
    if ( !_pskb_pull_tail(a1, 8 - (v50 - v13)) )
    {
      a1 = v71;
      a3 = v70;
      v13 = *(_DWORD *)(v71 + 116);
      if ( !v13 )
        goto LABEL_98;
      goto LABEL_72;
    }
    v50 = *(_DWORD *)(v71 + 112);
    a1 = v71;
    a3 = v70;
LABEL_71:
    v51 = *(_QWORD *)(a1 + 224);
    *(_DWORD *)(a1 + 112) = v50 - 8;
    *(_QWORD *)(a1 + 224) = v51 + 8;
    v13 = *(_DWORD *)(a1 + 116);
    if ( !v13 )
      goto LABEL_98;
    goto LABEL_72;
  }
  if ( !v13 )
    goto LABEL_98;
LABEL_72:
  if ( *(_DWORD *)(a1 + 112) == v13 )
  {
    v52 = a3;
    v53 = nullptr;
    v54 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
    v55 = *(_QWORD *)(v54 + 88);
    if ( v55 && (v55 & 1) == 0 )
      v53 = (unsigned int *)((((v55 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                           + *(unsigned int *)(v54 + 100));
    goto LABEL_99;
  }
LABEL_98:
  v53 = *(unsigned int **)(a1 + 224);
  v52 = a3;
LABEL_99:
  v81 = *(_QWORD *)(a2 + 2560);
  v73 = a1;
  v82 = *(_QWORD *)(a2 + 2568);
  *(_QWORD *)(a2 + 2520) = *v53;
  v83 = v53[1];
  *(_QWORD *)(a2 + 2528) = v83;
  v84 = v81 + v83;
  v85 = v53[2];
  *(_QWORD *)(a2 + 2536) = v85;
  v86 = v82 + v85;
  v87 = v53[3];
  *(_QWORD *)(a2 + 2560) = v84;
  v88 = *(_QWORD *)(a2 + 2552);
  *(_QWORD *)(a2 + 2568) = v86;
  *(_QWORD *)(a2 + 2544) = v87;
  *(_QWORD *)(a2 + 2552) = v88 + 1;
  if ( (v11 & 0x20000000) != 0 )
  {
    v89 = *(_QWORD **)(a2 + 2480);
    for ( k = (_QWORD *)(a2 + 2480); v89 != k; v89 = (_QWORD *)*v89 )
    {
      v91 = (void (__fastcall *)(unsigned int *, unsigned __int64))*(v89 - 2);
      if ( *((_DWORD *)v91 - 1) != 639187566 )
        __break(0x8228u);
      v91(v53, v12);
    }
  }
  a1 = v73;
  if ( (v52 & 1) == 0 )
    goto LABEL_10;
  v30 = *(_DWORD *)(v73 + 112);
  v77 = *(_DWORD *)(v73 + 116);
  v78 = (v11 & 4) == 0;
  v79 = 24;
  v80 = 16;
LABEL_106:
  if ( v78 )
    v31 = v80;
  else
    v31 = v79;
  v92 = v30 - v77;
  if ( v31 <= v92 )
    goto LABEL_110;
  if ( v30 < v31 )
    return 0;
  result = _pskb_pull_tail(v73, v31 - v92);
  if ( result )
  {
    v30 = *(_DWORD *)(v73 + 112);
    a1 = v73;
    goto LABEL_110;
  }
  return result;
}
