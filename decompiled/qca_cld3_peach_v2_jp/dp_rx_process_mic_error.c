__int64 __fastcall dp_rx_process_mic_error(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 (__fastcall *v9)(_QWORD); // x8
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x24
  unsigned __int8 *v20; // x23
  __int64 v21; // x25
  __int64 v22; // x22
  unsigned int (__fastcall *v23)(_QWORD); // x8
  __int64 (__fastcall *v24)(_QWORD); // x8
  __int64 v25; // x1
  __int64 v26; // x2
  __int64 v27; // x3
  __int64 v28; // x4
  __int64 v29; // x5
  char v30; // w8
  __int64 v31; // x0
  unsigned int v32; // w22
  __int64 (__fastcall *v33)(__int64, __int64, __int64, __int64, __int64, __int64); // x8
  unsigned int v34; // w24
  __int64 (__fastcall *v35)(_QWORD); // x9
  __int64 v36; // x0
  unsigned int v37; // w23
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x20
  __int64 v47; // x21
  __int64 v48; // x21
  __int64 v49; // x21
  __int64 (__fastcall *v50)(__int64, char *); // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x21
  __int64 v60; // x0
  __int64 (__fastcall *v61)(__int64, __int64 *); // x8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x21
  __int16 v71; // w8
  __int64 (__fastcall *v72)(__int64, __int64, __int64 *); // x8
  __int64 v73; // x0
  __int64 v74; // x1
  __int64 v75; // [xsp+0h] [xbp-30h] BYREF
  __int64 v76; // [xsp+8h] [xbp-28h]
  __int64 v77; // [xsp+10h] [xbp-20h] BYREF
  __int64 v78; // [xsp+18h] [xbp-18h] BYREF
  __int64 v79; // [xsp+20h] [xbp-10h]
  __int64 v80; // [xsp+28h] [xbp-8h]

  v80 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 1128);
  v78 = 0;
  v79 = 0;
  v76 = 0;
  v77 = 0;
  v8 = *(_QWORD *)(v7 + 74392);
  v75 = 0;
  v9 = *(__int64 (__fastcall **)(_QWORD))(v8 + 560);
  if ( *((_DWORD *)v9 - 1) != -1147376687 )
    __break(0x8228u);
  result = v9(a3);
  if ( (_BYTE)result )
  {
    if ( a4 )
    {
      v19 = *a4;
      if ( *a4 )
      {
        v20 = *(unsigned __int8 **)(v19 + 24);
        if ( v20 )
        {
          v21 = *(_QWORD *)(a1 + 1128);
          v22 = *(_QWORD *)(a2 + 224);
          v23 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(v21 + 74392) + 528LL);
          if ( *((_DWORD *)v23 - 1) != -1536295579 )
            __break(0x8228u);
          if ( v23(v22) )
          {
            v24 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v21 + 74392) + 1232LL);
            if ( *((_DWORD *)v24 - 1) != -1536295579 )
              __break(0x8228u);
            v30 = v24(v22);
            v31 = *(_QWORD *)(a2 + 224);
            if ( !v30 )
            {
              v32 = *(_BYTE *)(v31 + *(unsigned __int16 *)(a1 + 1138) + 22) & 0xF;
              if ( (*(_BYTE *)(v31 + *(unsigned __int16 *)(a1 + 1138) + 22) & 0xF) != 0 )
              {
                v33 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 392LL);
                if ( *((_DWORD *)v33 - 1) != 855462014 )
                  __break(0x8228u);
                v34 = v33(v31, v25, v26, v27, v28, v29);
                v35 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 856LL);
                v36 = *(_QWORD *)(a2 + 224);
                if ( *((_DWORD *)v35 - 1) != 646946022 )
                  __break(0x8229u);
                v37 = v35(v36);
                result = dp_rx_defrag_add_last_frag(a1, a4, v34, v37, a2);
                v46 = jiffies;
                if ( dp_rx_process_mic_error___last_ticks_36 - jiffies + 125 < 0 )
                {
                  result = qdf_trace_msg(
                             0x45u,
                             5u,
                             "%s: Frag pkt seq# %d frag# %d consumed status %d !",
                             v38,
                             v39,
                             v40,
                             v41,
                             v42,
                             v43,
                             v44,
                             v45,
                             "dp_rx_process_mic_error",
                             (unsigned __int16)v37,
                             v32,
                             (unsigned int)result,
                             v75,
                             v76,
                             v77,
                             v78,
                             v79,
                             v80);
                  dp_rx_process_mic_error___last_ticks_36 = v46;
                }
                goto LABEL_43;
              }
            }
          }
          else
          {
            v31 = *(_QWORD *)(a2 + 224);
          }
          v50 = *(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 632LL);
          if ( *((_DWORD *)v50 - 1) != 795953379 )
            __break(0x8228u);
          result = v50(v31, (char *)&v77 + 6);
          if ( (_DWORD)result )
          {
            v59 = jiffies;
            if ( dp_rx_process_mic_error___last_ticks_38 - jiffies + 125 < 0 )
            {
              result = qdf_trace_msg(
                         0x45u,
                         2u,
                         "%s: Failed to get da_mac_addr",
                         v51,
                         v52,
                         v53,
                         v54,
                         v55,
                         v56,
                         v57,
                         v58,
                         "dp_rx_process_mic_error",
                         v75,
                         v76,
                         v77,
                         v78,
                         v79,
                         v80);
              dp_rx_process_mic_error___last_ticks_38 = v59;
            }
          }
          else
          {
            v60 = *(_QWORD *)(a2 + 224);
            v61 = *(__int64 (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 640LL);
            if ( *((_DWORD *)v61 - 1) != 795953379 )
              __break(0x8228u);
            result = v61(v60, &v77);
            if ( (_DWORD)result )
            {
              v70 = jiffies;
              if ( dp_rx_process_mic_error___last_ticks_40 - jiffies + 125 < 0 )
              {
                result = qdf_trace_msg(
                           0x45u,
                           2u,
                           "%s: Failed to get ta_mac_addr",
                           v62,
                           v63,
                           v64,
                           v65,
                           v66,
                           v67,
                           v68,
                           v69,
                           "dp_rx_process_mic_error",
                           v75,
                           v76,
                           v77,
                           v78,
                           v79,
                           v80);
                dp_rx_process_mic_error___last_ticks_40 = v70;
              }
            }
            else
            {
              WORD1(v79) = *(_WORD *)((_BYTE *)&v77 + 5) & 0x100;
              result = (__int64)qdf_mem_set((char *)&v78 + 4, 6u, 0);
              v71 = *(unsigned __int8 *)(v19 + 59);
              v76 = 0;
              LOBYTE(v75) = 0;
              WORD2(v79) = v71;
              v72 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)(*((_QWORD *)v20 + 1) + 8LL)
                                                                          + 120LL);
              if ( v72 )
              {
                v73 = *(_QWORD *)(a1 + 16);
                v74 = *v20;
                if ( *((_DWORD *)v72 - 1) != 400924455 )
                  __break(0x8228u);
                result = v72(v73, v74, &v75);
              }
            }
          }
        }
        else
        {
          v49 = jiffies;
          if ( dp_rx_process_mic_error___last_ticks_34 - jiffies + 125 < 0 )
          {
            result = qdf_trace_msg(
                       0x45u,
                       5u,
                       "%s: PDEV not found",
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       "dp_rx_process_mic_error",
                       v75,
                       v76,
                       v77,
                       v78,
                       v79,
                       v80);
            dp_rx_process_mic_error___last_ticks_34 = v49;
          }
        }
      }
      else
      {
        v48 = jiffies;
        if ( dp_rx_process_mic_error___last_ticks_32 - jiffies + 125 < 0 )
        {
          result = qdf_trace_msg(
                     0x45u,
                     5u,
                     "%s: VDEV not found",
                     v11,
                     v12,
                     v13,
                     v14,
                     v15,
                     v16,
                     v17,
                     v18,
                     "dp_rx_process_mic_error",
                     v75,
                     v76,
                     v77,
                     v78,
                     v79,
                     v80);
          dp_rx_process_mic_error___last_ticks_32 = v48;
        }
      }
    }
    else
    {
      v47 = jiffies;
      if ( dp_rx_process_mic_error___last_ticks - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x45u,
                   5u,
                   "%s: txrx_peer not found",
                   v11,
                   v12,
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   "dp_rx_process_mic_error",
                   v75,
                   v76,
                   v77,
                   v78,
                   v79,
                   v80);
        dp_rx_process_mic_error___last_ticks = v47;
      }
    }
    if ( a2 )
      result = _qdf_nbuf_free(a2);
  }
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
