__int64 __fastcall dp_rx_fill_gro_info(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  __int64 (__fastcall *v10)(__int64, __int64 *); // x8
  char v11; // w9
  __int64 (__fastcall *v12)(_QWORD); // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w10
  bool v22; // zf
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  __int64 v103; // [xsp+0h] [xbp-20h] BYREF
  __int64 v104; // [xsp+8h] [xbp-18h]
  __int64 v105; // [xsp+10h] [xbp-10h]
  __int64 v106; // [xsp+18h] [xbp-8h]

  v106 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 40);
  v104 = 0;
  v105 = 0;
  v103 = 0;
  result = wlan_cfg_is_gro_enabled(v8);
  if ( (result & 1) != 0 )
  {
    v10 = *(__int64 (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1248LL);
    if ( *((_DWORD *)v10 - 1) != 617382751 )
      __break(0x8228u);
    result = v10(a2, &v103);
    if ( !(_DWORD)result )
    {
      v11 = v103;
      ++*a4;
      *(_QWORD *)(a3 + 72) = *(_QWORD *)(a3 + 72) & 0xFFFFFFFFFFFFFFFALL | v11 & 1 | (4LL * (BYTE2(v103) & 1));
      v12 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 848LL);
      if ( *((_DWORD *)v12 - 1) != 646946022 )
        __break(0x8228u);
      result = v12(a2);
      v21 = HIDWORD(v105);
      v22 = is_dp_verbose_debug_enabled == 1;
      *(_QWORD *)(a3 + 72) = *(_QWORD *)(a3 + 72) & 0xFFFC07F5LL
                           | ((unsigned __int64)(unsigned __int16)result << 32)
                           | ((unsigned __int64)(unsigned __int16)v104 << 48)
                           | (unsigned __int8)(2 * (BYTE1(v103) & 1)) & 0xF7
                           | (unsigned __int8)(8 * (BYTE3(v103) & 1))
                           | ((unsigned __int64)(BYTE4(v103) & 0x7F) << 11);
      *(_DWORD *)(a3 + 80) = v21;
      if ( v22 )
      {
        result = qdf_trace_msg(
                   0x45u,
                   8u,
                   "%s: ----------------------RX DESC LRO/GRO----------------------",
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   "dp_rx_print_offload_info");
        if ( (is_dp_verbose_debug_enabled & 1) != 0 )
        {
          result = qdf_trace_msg(
                     0x45u,
                     8u,
                     "%s: lro_eligible 0x%x",
                     v23,
                     v24,
                     v25,
                     v26,
                     v27,
                     v28,
                     v29,
                     v30,
                     "dp_rx_print_offload_info",
                     *(_DWORD *)(a3 + 72) & 1);
          if ( (is_dp_verbose_debug_enabled & 1) != 0 )
          {
            result = qdf_trace_msg(
                       0x45u,
                       8u,
                       "%s: pure_ack 0x%x",
                       v31,
                       v32,
                       v33,
                       v34,
                       v35,
                       v36,
                       v37,
                       v38,
                       "dp_rx_print_offload_info",
                       (*(_DWORD *)(a3 + 72) >> 2) & 1);
            if ( (is_dp_verbose_debug_enabled & 1) != 0 )
            {
              result = qdf_trace_msg(
                         0x45u,
                         8u,
                         "%s: chksum 0x%x",
                         v39,
                         v40,
                         v41,
                         v42,
                         v43,
                         v44,
                         v45,
                         v46,
                         "dp_rx_print_offload_info",
                         *(unsigned __int16 *)(a3 + 76));
              if ( (is_dp_verbose_debug_enabled & 1) != 0 )
              {
                result = qdf_trace_msg(
                           0x45u,
                           8u,
                           "%s: TCP seq num 0x%x",
                           v47,
                           v48,
                           v49,
                           v50,
                           v51,
                           v52,
                           v53,
                           v54,
                           "dp_rx_print_offload_info",
                           HIDWORD(v104));
                if ( (is_dp_verbose_debug_enabled & 1) != 0 )
                {
                  result = qdf_trace_msg(
                             0x45u,
                             8u,
                             "%s: TCP ack num 0x%x",
                             v55,
                             v56,
                             v57,
                             v58,
                             v59,
                             v60,
                             v61,
                             v62,
                             "dp_rx_print_offload_info",
                             (unsigned int)v105);
                  if ( (is_dp_verbose_debug_enabled & 1) != 0 )
                  {
                    result = qdf_trace_msg(
                               0x45u,
                               8u,
                               "%s: TCP window 0x%x",
                               v63,
                               v64,
                               v65,
                               v66,
                               v67,
                               v68,
                               v69,
                               v70,
                               "dp_rx_print_offload_info",
                               *(unsigned __int16 *)(a3 + 78));
                    if ( (is_dp_verbose_debug_enabled & 1) != 0 )
                    {
                      result = qdf_trace_msg(
                                 0x45u,
                                 8u,
                                 "%s: TCP protocol 0x%x",
                                 v71,
                                 v72,
                                 v73,
                                 v74,
                                 v75,
                                 v76,
                                 v77,
                                 v78,
                                 "dp_rx_print_offload_info",
                                 (*(_DWORD *)(a3 + 72) >> 1) & 1);
                      if ( (is_dp_verbose_debug_enabled & 1) != 0 )
                      {
                        result = qdf_trace_msg(
                                   0x45u,
                                   8u,
                                   "%s: TCP offset 0x%x",
                                   v79,
                                   v80,
                                   v81,
                                   v82,
                                   v83,
                                   v84,
                                   v85,
                                   v86,
                                   "dp_rx_print_offload_info",
                                   (*(_DWORD *)(a3 + 72) >> 11) & 0x7F);
                        if ( (is_dp_verbose_debug_enabled & 1) != 0 )
                        {
                          result = qdf_trace_msg(
                                     0x45u,
                                     8u,
                                     "%s: toeplitz 0x%x",
                                     v87,
                                     v88,
                                     v89,
                                     v90,
                                     v91,
                                     v92,
                                     v93,
                                     v94,
                                     "dp_rx_print_offload_info",
                                     *(unsigned int *)(a3 + 80));
                          if ( (is_dp_verbose_debug_enabled & 1) != 0 )
                            result = qdf_trace_msg(
                                       0x45u,
                                       8u,
                                       "%s: ---------------------------------------------------------",
                                       v95,
                                       v96,
                                       v97,
                                       v98,
                                       v99,
                                       v100,
                                       v101,
                                       v102,
                                       "dp_rx_print_offload_info");
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
  _ReadStatusReg(SP_EL0);
  return result;
}
