__int64 __fastcall policy_mgr_add_5g_to_pcl(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        unsigned int a4,
        unsigned int *a5,
        int a6,
        __int64 a7,
        unsigned __int8 a8,
        __int64 a9,
        unsigned __int8 a10)
{
  __int64 comp_private_obj; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x10
  unsigned int v27; // w7
  char v28; // w9
  char v29; // w11
  int v31; // w12
  bool v32; // zf
  unsigned __int8 v33; // w12
  __int64 v34; // x13
  __int64 v35; // x5
  unsigned __int8 v36; // w12
  const char *v37; // x2
  __int64 v38; // x4
  __int64 v39; // x14
  unsigned __int8 v40; // w15
  __int64 v41; // x17
  int v42; // w16
  __int64 v43; // x2
  unsigned __int64 v44; // x1
  int v45; // w11
  __int64 v46; // x14
  unsigned __int8 v47; // w13
  __int64 v48; // x16
  int v49; // w15
  __int64 v50; // x1
  unsigned __int64 v51; // x17
  int v52; // w9

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid Context",
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             "policy_mgr_add_5g_to_pcl");
  v26 = a9;
  v27 = *a5;
  if ( a6 )
  {
    if ( a6 == 1 )
    {
      v28 = -41;
      v29 = -21;
    }
    else
    {
      v28 = -61;
      v29 = -41;
    }
  }
  else
  {
    v28 = -21;
    v29 = -1;
  }
  v31 = *(_DWORD *)(comp_private_obj + 2236);
  v32 = v31 == 1;
  if ( v31 == 1 )
    v33 = a10;
  else
    v33 = a8;
  if ( v32 )
    v34 = a9;
  else
    v34 = a7;
  if ( v32 )
    v26 = a7;
  v35 = v33;
  if ( v32 )
    v36 = a8;
  else
    v36 = a10;
  if ( v27 + (unsigned int)v35 > a4 )
  {
    v37 = "%s: no enough weight len %d chlist1_len %d %d";
    v38 = a4;
    return qdf_trace_msg(0x4Fu, 2u, v37, v18, v19, v20, v21, v22, v23, v24, v25, "policy_mgr_add_5g_to_pcl", v38);
  }
  if ( (_DWORD)v35 )
  {
    v39 = 0;
    v40 = 0;
    while ( 1 )
    {
      v42 = *(_DWORD *)(v34 + 4 * v39);
      if ( v27 )
      {
        if ( *a2 == v42 )
          goto LABEL_25;
        v41 = v27;
        v43 = 1;
        do
        {
          v44 = v43;
          if ( v27 == v43 )
            break;
          v32 = a2[v43++] == v42;
        }
        while ( !v32 );
        if ( v44 < v27 )
          goto LABEL_25;
      }
      else
      {
        v41 = 0;
      }
      ++v27;
      ++v40;
      a2[v41] = v42;
      *(_BYTE *)(a3 + v41) = v29;
LABEL_25:
      if ( ++v39 == v35 )
      {
        v45 = v40;
        goto LABEL_36;
      }
    }
  }
  v45 = 0;
LABEL_36:
  if ( v27 + v36 > a4 )
  {
    v37 = "%s: no enough weight len chlist2_len %d %d %d";
    v38 = a4;
    return qdf_trace_msg(0x4Fu, 2u, v37, v18, v19, v20, v21, v22, v23, v24, v25, "policy_mgr_add_5g_to_pcl", v38);
  }
  if ( v36 )
  {
    v46 = 0;
    v47 = 0;
    while ( 1 )
    {
      v49 = *(_DWORD *)(v26 + 4 * v46);
      if ( v27 )
      {
        if ( *a2 == v49 )
          goto LABEL_43;
        v48 = v27;
        v50 = 1;
        do
        {
          v51 = v50;
          if ( v27 == v50 )
            break;
          v32 = a2[v50++] == v49;
        }
        while ( !v32 );
        if ( v51 < v27 )
          goto LABEL_43;
        if ( v27 > 0x65 )
        {
LABEL_52:
          v52 = v47;
          goto LABEL_54;
        }
      }
      else
      {
        v48 = 0;
      }
      ++v27;
      ++v47;
      a2[v48] = v49;
      *(_BYTE *)(a3 + v48) = v28;
LABEL_43:
      if ( ++v46 == v36 )
        goto LABEL_52;
    }
  }
  v52 = 0;
LABEL_54:
  *a5 = v27;
  return qdf_trace_msg(
           0x4Fu,
           8u,
           "%s: Add 5g chlist len %d 6g chlist len %d len %d index %d order %d",
           v18,
           v19,
           v20,
           v21,
           v22,
           v23,
           v24,
           v25,
           "policy_mgr_add_5g_to_pcl",
           a8,
           a10,
           (unsigned int)(v52 + v45),
           *(_DWORD *)(comp_private_obj + 2236));
}
