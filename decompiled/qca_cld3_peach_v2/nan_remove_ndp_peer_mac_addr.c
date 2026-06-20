__int64 __fastcall nan_remove_ndp_peer_mac_addr(
        __int64 a1,
        int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w19
  __int64 v22; // x8
  __int64 v28; // x21
  unsigned int v29; // w20
  void *v30; // x0
  int v33; // w9
  int v34; // w12

  if ( !a1 )
  {
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a3, a4, a5, a6, a7, a8, a9, a10, "nan_get_psoc_priv_obj");
    goto LABEL_6;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
LABEL_6:
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: NAN PSOC priv obj is null",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "nan_remove_ndp_peer_mac_addr");
    return 29;
  }
  v20 = *(unsigned __int8 *)(comp_private_obj + 382);
  if ( v20 >= 9 )
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: num peers %d more than max NDP peers",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "nan_remove_ndp_peer_mac_addr",
      *(unsigned __int8 *)(comp_private_obj + 382));
    return 16;
  }
  if ( !*(_BYTE *)(comp_private_obj + 382) )
  {
    qdf_trace_msg(
      0x53u,
      8u,
      "%s: last NDP peer removed",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "nan_remove_ndp_peer_mac_addr");
    return 0;
  }
  v22 = comp_private_obj + 334;
  if ( *a2 == *(_DWORD *)(comp_private_obj + 334)
    && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(comp_private_obj + 338) )
  {
    v28 = comp_private_obj;
    v29 = 0;
    v30 = (void *)(comp_private_obj + 334);
    goto LABEL_59;
  }
  if ( v20 != 1 )
  {
    if ( *a2 == *(_DWORD *)(comp_private_obj + 340)
      && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(comp_private_obj + 344) )
    {
      v28 = comp_private_obj;
      v30 = (void *)(comp_private_obj + 340);
      v29 = 1;
      goto LABEL_59;
    }
    if ( v20 != 2 )
    {
      if ( *a2 == *(_DWORD *)(comp_private_obj + 346)
        && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(comp_private_obj + 350) )
      {
        v28 = comp_private_obj;
        v29 = 2;
        v30 = (void *)(comp_private_obj + 346);
        goto LABEL_59;
      }
      if ( v20 != 3 )
      {
        if ( *a2 == *(_DWORD *)(comp_private_obj + 352)
          && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(comp_private_obj + 356) )
        {
          v28 = comp_private_obj;
          v30 = (void *)(comp_private_obj + 352);
          v29 = 3;
          goto LABEL_59;
        }
        if ( v20 != 4 )
        {
          if ( *a2 == *(_DWORD *)(comp_private_obj + 358)
            && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(comp_private_obj + 362) )
          {
            v28 = comp_private_obj;
            v29 = 4;
            v30 = (void *)(comp_private_obj + 358);
          }
          else
          {
            if ( v20 == 5 )
              goto LABEL_33;
            if ( *a2 == *(_DWORD *)(comp_private_obj + 364)
              && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(comp_private_obj + 368) )
            {
              v28 = comp_private_obj;
              v30 = (void *)(comp_private_obj + 364);
              v29 = 5;
            }
            else
            {
              v28 = comp_private_obj;
              if ( v20 == 6 )
              {
LABEL_50:
                v29 = v20;
                goto LABEL_60;
              }
              v30 = (void *)(comp_private_obj + 370);
              if ( *a2 == *(_DWORD *)(v22 + 36) && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(v22 + 40) )
              {
                v29 = 6;
              }
              else
              {
                if ( v20 == 7 )
                  goto LABEL_50;
                v33 = *a2;
                v34 = *((unsigned __int16 *)a2 + 2);
                v29 = v20;
                if ( v33 != *(_DWORD *)(v28 + 376) || v34 != *(unsigned __int16 *)(v28 + 380) )
                  goto LABEL_60;
                v30 = (void *)(v28 + 376);
                v29 = 7;
              }
            }
          }
LABEL_59:
          qdf_mem_copy(v30, (const void *)(v22 + 6LL * (v20 - 1)), 6u);
          goto LABEL_60;
        }
      }
    }
  }
LABEL_33:
  v28 = comp_private_obj;
  v29 = *(unsigned __int8 *)(comp_private_obj + 382);
LABEL_60:
  qdf_trace_msg(
    0x53u,
    8u,
    "%s: peer remove from migrated list at index %d with max peer %d",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "nan_remove_ndp_peer_mac_addr",
    v29,
    v20);
  --*(_BYTE *)(v28 + 382);
  return 0;
}
