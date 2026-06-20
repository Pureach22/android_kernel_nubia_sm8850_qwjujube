_BYTE *__fastcall wma_wow_pagefault_add_new_sym_from_event(__int64 a1, char **a2, __int64 a3)
{
  _BYTE *result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned __int8 v14; // w22
  unsigned __int64 v15; // x28
  void ***v16; // x9
  __int64 v17; // x27
  unsigned __int8 v18; // w9
  unsigned __int64 v19; // x19
  __int64 v20; // x23
  __int64 v21; // x8
  __int64 v22; // x10
  void **v23; // x8
  _QWORD *context; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  void (__fastcall *v33)(char *, __int64); // x8
  int v34; // w24
  char *v35; // x25
  unsigned int v36; // w8
  char *v37; // x26
  unsigned int v38; // w9
  void ***v39; // x10
  unsigned __int8 v40; // w17
  __int64 v41; // x11
  __int64 v42; // x15
  __int64 v43; // x12
  __int64 v44; // x10
  __int64 v45; // x9
  unsigned int v46; // w11
  __int64 v47; // x11
  char *v48; // x9
  _BYTE *v50; // [xsp+8h] [xbp-28h]
  void *v51; // [xsp+10h] [xbp-20h]
  __int64 v52; // [xsp+18h] [xbp-18h]
  unsigned int v53; // [xsp+20h] [xbp-10h]
  void ***v54; // [xsp+28h] [xbp-8h]

  v52 = a1 + 4376;
  result = (_BYTE *)wlan_pmo_get_min_pagefault_wakeups_for_action(*(_QWORD *)(a1 + 24));
  v14 = (unsigned __int8)result;
  v15 = 0;
  v16 = (void ***)(a1 + 4400);
  v17 = 1;
  while ( 2 )
  {
    if ( !*((_BYTE *)a2 + 9) )
      return result;
    v54 = v16;
    v18 = *((_BYTE *)a2 + 8);
    if ( !v18 )
      goto LABEL_2;
    v19 = 0;
    v20 = 4;
    v21 = v52 + 16 * v15;
    v22 = *(unsigned __int8 *)(v21 + 4);
    v23 = *(void ***)(v21 + 8);
    v53 = v22;
    v50 = *v23;
    v51 = v23[v22 - 1];
    while ( 1 )
    {
      v35 = *a2;
      v36 = (unsigned __int8)(*a2)[v20];
      if ( !(*a2)[v20] )
        goto LABEL_12;
      if ( v36 < v14 )
        break;
      v34 = *(_DWORD *)(a1 + 5184);
      v37 = *(char **)(a1 + 5176);
      if ( (unsigned int)(v34 - 385) <= 5 )
      {
        context = _cds_get_context(53, (__int64)"wma_wow_pagefault_action_cb", v6, v7, v8, v9, v10, v11, v12, v13);
        if ( context )
        {
          v33 = (void (__fastcall *)(char *, __int64))context[1823];
          if ( *((_DWORD *)v33 - 1) != -297509796 )
            __break(0x8228u);
          v33(v37, 390);
        }
        else
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: NULL mac ptr",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "wma_wow_pagefault_action_cb");
        }
      }
      else if ( v34 )
      {
        goto LABEL_11;
      }
      qdf_mem_set(v37, 0x186u, 0);
      v34 = 0;
LABEL_11:
      result = qdf_mem_copy(&v37[v34], v35, 6u);
      *(_DWORD *)(a1 + 5184) = v34 + 6;
      (*a2)[v20] = 0;
      v18 = *((_BYTE *)a2 + 8);
      --*((_BYTE *)a2 + 9);
LABEL_12:
      ++v19;
      v20 += 8;
      if ( v19 >= v18 )
        goto LABEL_2;
    }
    v38 = (unsigned __int8)v15;
    if ( !v53 )
    {
      v42 = a3;
      goto LABEL_32;
    }
    if ( v53 > v36 || (((unsigned __int64)v51 - a3) & 0x8000000000000000LL) == 0 )
    {
LABEL_2:
      ++v15;
      ++v17;
      v16 = v54 + 2;
      if ( v15 == 50 )
        return result;
      continue;
    }
    break;
  }
  if ( v15 > 0x30 )
  {
    v42 = a3;
    if ( (unsigned __int8)v15 <= 0x32u )
      goto LABEL_33;
  }
  else
  {
    v40 = v53;
    v39 = v54;
    v41 = v17;
    v42 = a3;
    result = v50;
    do
    {
      v43 = *((unsigned __int8 *)v39 - 4);
      if ( (unsigned int)v43 <= v40
        && (__int64)(*v39)[v43 - 1] - a3 < 0
        && ((_DWORD)v43 != v40 || (_BYTE *)**v39 - result < 0) )
      {
        v38 = (unsigned __int8)v41;
        v40 = *((_BYTE *)v39 - 4);
        result = **v39;
      }
      ++v41;
      v39 += 2;
    }
    while ( v41 != 50 );
LABEL_32:
    if ( v38 <= 0x32 )
    {
LABEL_33:
      v44 = 0;
      v45 = v52 + 16LL * v38;
      if ( v36 <= 1 )
        v46 = 1;
      else
        v46 = (unsigned __int8)(*a2)[v20];
      v47 = 8LL * v46;
      *(_DWORD *)v45 = *(_DWORD *)&v35[v20 - 4];
      *(_BYTE *)(v45 + 4) = v36;
      do
      {
        *(_QWORD *)(*(_QWORD *)(v45 + 8) + v44) = v42;
        v44 += 8;
      }
      while ( v47 != v44 );
      v48 = *a2;
      --*((_BYTE *)a2 + 9);
      v48[v20] = 0;
      goto LABEL_2;
    }
  }
  __break(0x5512u);
  return result;
}
