__int64 __fastcall cam_isp_classify_vote_info(
        __int64 a1,
        __int64 a2,
        unsigned int *a3,
        int a4,
        unsigned int a5,
        _BYTE *a6,
        _BYTE *a7,
        char a8)
{
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x13
  unsigned __int64 v10; // x9
  _QWORD *v11; // x10
  unsigned int *v12; // x13
  __int64 v13; // x14
  __int64 v14; // x16
  __int64 v15; // x17
  unsigned __int64 v16; // x13
  unsigned __int64 v17; // x9
  _QWORD *v18; // x10
  unsigned int *v19; // x13
  __int64 v20; // x14
  __int64 v21; // x16
  __int64 v22; // x17
  unsigned __int64 v23; // x13
  unsigned __int64 v24; // x9
  _QWORD *v25; // x10
  unsigned int *v26; // x13
  __int64 v27; // x14
  __int64 v28; // x16
  __int64 v29; // x17
  unsigned __int64 v30; // x13
  unsigned __int64 v31; // x9
  _QWORD *v32; // x10
  unsigned int *v33; // x13
  __int64 v34; // x14
  __int64 v35; // x16
  __int64 v36; // x17
  unsigned __int64 v37; // x13
  unsigned __int64 v38; // x9
  _QWORD *v39; // x10
  unsigned int *v40; // x13
  __int64 v41; // x14
  __int64 v42; // x16
  __int64 v43; // x17
  unsigned __int64 v44; // x13
  unsigned __int64 v45; // x9
  _QWORD *v46; // x10
  unsigned int *v47; // x13
  __int64 v48; // x14
  __int64 v49; // x16
  __int64 v50; // x17
  int v52; // w9
  int v53; // w10
  unsigned __int64 v54; // x25
  _DWORD *v55; // x28
  __int64 v56; // x21
  const char *v57; // x23
  const char *v58; // x24
  const char *v59; // x0
  const char *v60; // [xsp+30h] [xbp-10h]
  unsigned int *v61; // [xsp+38h] [xbp-8h]

  if ( a4 != 2 )
  {
    if ( (a8 & 1) == 0 && *(_DWORD *)(a1 + 20) )
      goto LABEL_18;
    if ( a5 || (*a6 & 1) != 0 )
    {
      if ( (*a7 & 1) != 0 )
      {
LABEL_18:
        v8 = 0;
        goto LABEL_56;
      }
      v23 = *(unsigned int *)(a2 + 4);
      if ( (_DWORD)v23 )
      {
        v24 = 0;
        v8 = 0;
        v25 = (_QWORD *)(a2 + 8);
        do
        {
          if ( v24 == 40 )
            goto LABEL_34;
          if ( *(_DWORD *)v25 == 5 )
          {
            if ( v8 > 0xF )
              goto LABEL_34;
            v26 = &a3[10 * v8++ + 2];
            *(_QWORD *)v26 = *v25;
            v27 = v25[4];
            v28 = v25[1];
            v29 = v25[2];
            *((_QWORD *)v26 + 3) = v25[3];
            *((_QWORD *)v26 + 4) = v27;
            *((_QWORD *)v26 + 1) = v28;
            *((_QWORD *)v26 + 2) = v29;
            v23 = *(unsigned int *)(a2 + 4);
          }
          ++v24;
          v25 += 5;
        }
        while ( v24 < v23 );
      }
      else
      {
        v8 = 0;
      }
      a6 = a7;
    }
    else
    {
      v37 = *(unsigned int *)(a2 + 4);
      if ( (_DWORD)v37 )
      {
        v38 = 0;
        v8 = 0;
        v39 = (_QWORD *)(a2 + 8);
        do
        {
          if ( v38 == 40 )
            goto LABEL_34;
          if ( *(_DWORD *)v39 == 4 )
          {
            if ( v8 > 0xF )
              goto LABEL_34;
            v40 = &a3[10 * v8++ + 2];
            *(_QWORD *)v40 = *v39;
            v41 = v39[4];
            v42 = v39[1];
            v43 = v39[2];
            *((_QWORD *)v40 + 3) = v39[3];
            *((_QWORD *)v40 + 4) = v41;
            *((_QWORD *)v40 + 1) = v42;
            *((_QWORD *)v40 + 2) = v43;
            v37 = *(unsigned int *)(a2 + 4);
          }
          ++v38;
          v39 += 5;
        }
        while ( v38 < v37 );
      }
      else
      {
        v8 = 0;
      }
    }
    *a3 = v8;
    *a6 = 1;
LABEL_56:
    if ( (unsigned int)(*(_DWORD *)(a1 + 20) - 1) <= 4 )
    {
      v44 = *(unsigned int *)(a2 + 4);
      if ( (_DWORD)v44 )
      {
        v45 = 0;
        v46 = (_QWORD *)(a2 + 8);
        do
        {
          if ( v45 == 40 )
            goto LABEL_34;
          if ( *(_DWORD *)v46 == 6 && *((_DWORD *)v46 + 2) - 96 == *(_DWORD *)(a1 + 20) )
          {
            if ( v8 > 0xF )
              goto LABEL_34;
            v47 = &a3[10 * v8++ + 2];
            *(_QWORD *)v47 = *v46;
            v48 = v46[4];
            v49 = v46[1];
            v50 = v46[2];
            *((_QWORD *)v47 + 3) = v46[3];
            *((_QWORD *)v47 + 4) = v48;
            *((_QWORD *)v47 + 1) = v49;
            *((_QWORD *)v47 + 2) = v50;
            v44 = *(unsigned int *)(a2 + 4);
          }
          ++v45;
          v46 += 5;
        }
        while ( v45 < v44 );
      }
LABEL_74:
      *a3 = v8;
      if ( !v8 )
        return 0;
      goto LABEL_75;
    }
LABEL_70:
    v8 = *a3;
    if ( !*a3 )
      return 0;
LABEL_75:
    v52 = debug_mdl;
    v53 = debug_priority;
    v54 = 0;
    v55 = a3 + 5;
    do
    {
      v56 = v52 & 0x2000008;
      if ( (v52 & 0x2000008) != 0 && !v53 )
      {
        if ( v54 > 0xE )
          goto LABEL_34;
        v61 = a3;
        v60 = cam_isp_util_usage_data_to_string(*(v55 - 3));
        v57 = cam_cpas_axi_util_path_type_to_string(*(v55 - 1));
        v58 = cam_cpas_axi_util_trans_type_to_string(*(v55 - 2));
        v59 = cam_cpas_axi_util_drv_vote_lvl_to_string(*v55);
        a1 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               v56,
               4,
               "cam_isp_classify_vote_info",
               7385,
               "CLASSIFY_VOTE [%s] [%s] [%s] [%s] [%llu] [%llu] [%llu]",
               v60,
               v57,
               v58,
               v59,
               *(_QWORD *)(v55 + 1),
               *(_QWORD *)(v55 + 3),
               *(_QWORD *)(v55 + 5));
        a3 = v61;
        v52 = debug_mdl;
        v53 = debug_priority;
        v8 = *v61;
      }
      ++v54;
      v55 += 10;
    }
    while ( v54 < v8 );
    return 0;
  }
  LODWORD(v8) = *(_DWORD *)(a1 + 20);
  if ( (unsigned int)v8 > 9 || ((1 << v8) & 0x305) == 0 )
    goto LABEL_35;
  if ( !a5 )
  {
    if ( (*a6 & 1) == 0 )
    {
      v16 = *(unsigned int *)(a2 + 4);
      if ( (_DWORD)v16 )
      {
        v17 = 0;
        v8 = 0;
        v18 = (_QWORD *)(a2 + 8);
        do
        {
          if ( v17 == 40 )
            goto LABEL_34;
          if ( *(_DWORD *)v18 == 1 )
          {
            if ( v8 > 0xF )
              goto LABEL_34;
            v19 = &a3[10 * v8++ + 2];
            *(_QWORD *)v19 = *v18;
            v20 = v18[4];
            v21 = v18[1];
            v22 = v18[2];
            *((_QWORD *)v19 + 3) = v18[3];
            *((_QWORD *)v19 + 4) = v20;
            *((_QWORD *)v19 + 1) = v21;
            *((_QWORD *)v19 + 2) = v22;
            v16 = *(unsigned int *)(a2 + 4);
          }
          ++v17;
          v18 += 5;
        }
        while ( v17 < v16 );
      }
      else
      {
        LODWORD(v8) = 0;
      }
      goto LABEL_69;
    }
    return 0;
  }
  if ( (*a7 & 1) != 0 )
    return 0;
  v9 = *(unsigned int *)(a2 + 4);
  if ( !(_DWORD)v9 )
  {
    LODWORD(v8) = 0;
    a6 = a7;
LABEL_69:
    *a3 = v8;
    *a6 = 1;
    goto LABEL_70;
  }
  v10 = 0;
  v8 = 0;
  v11 = (_QWORD *)(a2 + 8);
  while ( v10 != 40 )
  {
    if ( *(_DWORD *)v11 == 2 )
    {
      if ( v8 > 0xF )
        break;
      v12 = &a3[10 * v8++ + 2];
      *(_QWORD *)v12 = *v11;
      v13 = v11[4];
      v14 = v11[1];
      v15 = v11[2];
      *((_QWORD *)v12 + 3) = v11[3];
      *((_QWORD *)v12 + 4) = v13;
      *((_QWORD *)v12 + 1) = v14;
      *((_QWORD *)v12 + 2) = v15;
      v9 = *(unsigned int *)(a2 + 4);
    }
    ++v10;
    v11 += 5;
    if ( v10 >= v9 )
    {
      a6 = a7;
      goto LABEL_69;
    }
  }
LABEL_34:
  while ( 1 )
  {
    __break(0x5512u);
LABEL_35:
    if ( (unsigned int)(v8 - 3) > 4 )
      break;
    v30 = *(unsigned int *)(a2 + 4);
    if ( !(_DWORD)v30 )
    {
      v8 = 0;
      goto LABEL_74;
    }
    v31 = 0;
    v8 = 0;
    v32 = (_QWORD *)(a2 + 8);
    while ( v31 != 40 )
    {
      if ( *(_DWORD *)v32 == 3 && *((_DWORD *)v32 + 2) - 1 == *(_DWORD *)(a1 + 20) )
      {
        if ( v8 > 0xF )
          goto LABEL_34;
        v33 = &a3[10 * v8++ + 2];
        *(_QWORD *)v33 = *v32;
        v34 = v32[4];
        v35 = v32[1];
        v36 = v32[2];
        *((_QWORD *)v33 + 3) = v32[3];
        *((_QWORD *)v33 + 4) = v34;
        *((_QWORD *)v33 + 1) = v35;
        *((_QWORD *)v33 + 2) = v36;
        v30 = *(unsigned int *)(a2 + 4);
      }
      ++v31;
      v32 += 5;
      if ( v31 >= v30 )
        goto LABEL_74;
    }
  }
  if ( !*(_QWORD *)(a1 + 8LL * a5 + 32) )
    goto LABEL_70;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_isp_classify_vote_info",
    7311,
    "Invalid res_id %u, split_idx: %u",
    v8,
    a5);
  return 4294967274LL;
}
