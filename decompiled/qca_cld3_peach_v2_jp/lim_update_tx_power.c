__int64 __fastcall lim_update_tx_power(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 cmpt_obj; // x20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x8
  __int64 v52; // x2
  __int64 v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  int v62; // w8
  int v63; // w9
  __int64 v64; // x8
  unsigned __int8 v65; // w9
  int v66; // w8
  __int64 v67; // x0
  __int64 v68; // x1
  __int64 v69; // x2

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a3 + 16), a5, a6, a7, a8, a9, a10, a11, a12);
  v25 = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a2 + 16), v17, v18, v19, v20, v21, v22, v23, v24);
  result = 16;
  if ( cmpt_obj && v25 )
  {
    if ( (wlan_is_scc_tpc_power_supp_enabled(*(_QWORD *)(a3 + 16), v26, v27, v28, v29, v30, v31, v32, v33) & 1) != 0 )
      return 0;
    if ( (a4 & 1) != 0 )
    {
      wlan_set_tpc_update_required_for_sta(*(_QWORD *)(a2 + 16), 0, v35, v36, v37, v38, v39, v40, v41, v42);
      v51 = *(_QWORD *)(a3 + 112);
      *(_BYTE *)(a3 + 10070) = 0;
      if ( v51 )
        v52 = v51 + 4364;
      else
        v52 = 0;
      lim_set_tpc_power(a1, a3, v52, 0, v43, v44, v45, v46, v47, v48, v49, v50);
      return 0;
    }
    *(_BYTE *)(a3 + 10070) = 1;
    if ( *(unsigned __int8 *)(cmpt_obj + 532) == *(unsigned __int8 *)(v25 + 532) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: STA and SAP are in same power type",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "lim_update_tx_power");
      return 16;
    }
    v53 = qdf_trace_msg(
            0x35u,
            8u,
            "%s: STA is moved to %d from %d power type",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "lim_update_tx_power");
    *(_BYTE *)(cmpt_obj + 532) = *(_BYTE *)(v25 + 532);
    v62 = *(unsigned __int8 *)(v25 + 533);
    if ( *(_BYTE *)(v25 + 533) )
    {
      v63 = *(_DWORD *)(a2 + 284);
      if ( *(_DWORD *)(v25 + 636) == v63 )
      {
        v64 = 0;
LABEL_14:
        v65 = *(_BYTE *)(v25 + 636 + 8 * v64 + 4);
LABEL_17:
        v66 = *(unsigned __int8 *)(cmpt_obj + 533);
        if ( !*(_BYTE *)(cmpt_obj + 533) )
          goto LABEL_34;
        *(_WORD *)(cmpt_obj + 640) = v65;
        if ( v66 == 1 )
          goto LABEL_34;
        *(_WORD *)(cmpt_obj + 648) = v65;
        if ( v66 == 2 )
          goto LABEL_34;
        *(_WORD *)(cmpt_obj + 656) = v65;
        if ( v66 == 3 )
          goto LABEL_34;
        *(_WORD *)(cmpt_obj + 664) = v65;
        if ( v66 == 4 )
          goto LABEL_34;
        *(_WORD *)(cmpt_obj + 672) = v65;
        if ( v66 == 5 )
          goto LABEL_34;
        *(_WORD *)(cmpt_obj + 680) = v65;
        if ( v66 == 6 )
          goto LABEL_34;
        *(_WORD *)(cmpt_obj + 688) = v65;
        if ( v66 == 7 )
          goto LABEL_34;
        *(_WORD *)(cmpt_obj + 696) = v65;
        if ( v66 == 8 )
          goto LABEL_34;
        *(_WORD *)(cmpt_obj + 704) = v65;
        if ( v66 == 9
          || (*(_WORD *)(cmpt_obj + 712) = v65, v66 == 10)
          || (*(_WORD *)(cmpt_obj + 720) = v65, v66 == 11)
          || (*(_WORD *)(cmpt_obj + 728) = v65, v66 == 12)
          || (*(_WORD *)(cmpt_obj + 736) = v65, v66 == 13)
          || (*(_WORD *)(cmpt_obj + 744) = v65, v66 == 14)
          || (*(_WORD *)(cmpt_obj + 752) = v65, v66 == 15)
          || (*(_WORD *)(cmpt_obj + 760) = v65, v66 == 16) )
        {
LABEL_34:
          wlan_set_tpc_update_required_for_sta(*(_QWORD *)(a2 + 16), 1, v54, v55, v56, v57, v58, v59, v60, v61);
          return 0;
        }
LABEL_82:
        __break(0x5512u);
        v67 = MEMORY[0xFFFFFFFFFE485FE0](v53);
        return lim_is_power_change_required_for_sta(v67, v68, v69);
      }
      if ( v62 != 1 )
      {
        if ( *(_DWORD *)(v25 + 644) == v63 )
        {
          v64 = 1;
          goto LABEL_14;
        }
        if ( v62 != 2 )
        {
          if ( *(_DWORD *)(v25 + 652) == v63 )
          {
            v64 = 2;
            goto LABEL_14;
          }
          if ( v62 != 3 )
          {
            if ( *(_DWORD *)(v25 + 660) == v63 )
            {
              v64 = 3;
              goto LABEL_14;
            }
            if ( v62 != 4 )
            {
              if ( *(_DWORD *)(v25 + 668) == v63 )
              {
                v64 = 4;
                goto LABEL_14;
              }
              if ( v62 != 5 )
              {
                if ( *(_DWORD *)(v25 + 676) == v63 )
                {
                  v64 = 5;
                  goto LABEL_14;
                }
                if ( v62 != 6 )
                {
                  if ( *(_DWORD *)(v25 + 684) == v63 )
                  {
                    v64 = 6;
                    goto LABEL_14;
                  }
                  if ( v62 != 7 )
                  {
                    if ( *(_DWORD *)(v25 + 692) == v63 )
                    {
                      v64 = 7;
                      goto LABEL_14;
                    }
                    if ( v62 != 8 )
                    {
                      if ( *(_DWORD *)(v25 + 700) == v63 )
                      {
                        v64 = 8;
                        goto LABEL_14;
                      }
                      if ( v62 != 9 )
                      {
                        if ( *(_DWORD *)(v25 + 708) == v63 )
                        {
                          v64 = 9;
                          goto LABEL_14;
                        }
                        if ( v62 != 10 )
                        {
                          if ( *(_DWORD *)(v25 + 716) == v63 )
                          {
                            v64 = 10;
                            goto LABEL_14;
                          }
                          if ( v62 != 11 )
                          {
                            if ( *(_DWORD *)(v25 + 724) == v63 )
                            {
                              v64 = 11;
                              goto LABEL_14;
                            }
                            if ( v62 != 12 )
                            {
                              if ( *(_DWORD *)(v25 + 732) == v63 )
                              {
                                v64 = 12;
                                goto LABEL_14;
                              }
                              if ( v62 != 13 )
                              {
                                if ( *(_DWORD *)(v25 + 740) == v63 )
                                {
                                  v64 = 13;
                                  goto LABEL_14;
                                }
                                if ( v62 != 14 )
                                {
                                  if ( *(_DWORD *)(v25 + 748) == v63 )
                                  {
                                    v64 = 14;
                                    goto LABEL_14;
                                  }
                                  if ( v62 != 15 )
                                  {
                                    if ( *(_DWORD *)(v25 + 756) == v63 )
                                    {
                                      v64 = 15;
                                      goto LABEL_14;
                                    }
                                    if ( v62 != 16 )
                                      goto LABEL_82;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    v65 = 0;
    goto LABEL_17;
  }
  return result;
}
