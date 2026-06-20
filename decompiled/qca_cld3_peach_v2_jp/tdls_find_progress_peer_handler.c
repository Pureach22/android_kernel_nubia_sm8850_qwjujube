void __fastcall tdls_find_progress_peer_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const void *v21; // x20
  __int64 v22; // x24
  __int64 v23; // x25
  bool v24; // zf
  int v25; // w26
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  _QWORD *v38; // x28
  _QWORD *v39[2]; // [xsp+0h] [xbp-10h] BYREF

  v39[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(a11 + 16) )
  {
    if ( a10 )
    {
      if ( (*(_DWORD *)(a10 + 16) | 2) == 2 )
      {
        comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a10, 0xAu);
        if ( comp_private_obj )
        {
          v21 = *(const void **)(a11 + 8);
          v22 = 0;
          v23 = comp_private_obj + 8;
          if ( v21 )
            v24 = *(_BYTE *)a11 == 0;
          else
            v24 = 1;
          v25 = !v24;
          while ( 1 )
          {
            v39[0] = nullptr;
            if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(v23 + 24 * v22), v39) )
            {
              while ( 1 )
              {
                v38 = v39[0];
                if ( (!v25 || (unsigned int)qdf_mem_cmp(v39[0] + 3, v21, 6u)) && *((_DWORD *)v38 + 9) == 3 )
                  break;
                if ( (unsigned int)qdf_list_peek_next((_QWORD *)(v23 + 24 * v22), v39[0], v39) )
                  goto LABEL_15;
              }
              if ( v38 == (_QWORD *)-24LL )
              {
                v28 = 0;
                v26 = 0;
                v27 = 0;
                v29 = 0;
              }
              else
              {
                v26 = *((unsigned __int8 *)v38 + 24);
                v27 = *((unsigned __int8 *)v38 + 25);
                v28 = *((unsigned __int8 *)v38 + 26);
                v29 = *((unsigned __int8 *)v38 + 29);
              }
              qdf_trace_msg(
                0,
                8u,
                "%s: %02x:%02x:%02x:**:**:%02x TDLS_LINK_CONNECTING",
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                "tdls_find_progress_peer_in_list",
                v26,
                v27,
                v28,
                v29);
              if ( v38 )
                break;
            }
LABEL_15:
            if ( ++v22 == 16 )
              goto LABEL_26;
          }
        }
        else
        {
          qdf_trace_msg(
            0,
            2u,
            "%s: invalid tdls vdev object",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "tdls_find_progress_peer");
LABEL_26:
          v38 = nullptr;
        }
        *(_QWORD *)(a11 + 16) = v38;
      }
    }
    else
    {
      qdf_trace_msg(0, 2u, "%s: invalid vdev", a1, a2, a3, a4, a5, a6, a7, a8, "tdls_find_progress_peer_handler");
    }
  }
  _ReadStatusReg(SP_EL0);
}
