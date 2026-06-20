__int64 __fastcall wma_print_he_op(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w8

  v9 = *(_DWORD *)(a1 + 1);
  return qdf_trace_msg(
           0x36u,
           8u,
           "%s: bss_color %0x def_pe_dur %0x twt_req %0x txop_rts_thre %0x vht_oper %0x part_bss_color %0x, MBSSID AP %0x"
           " BSS color dis %0x",
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           "wma_print_he_op",
           *(_BYTE *)(a1 + 5) & 0x3F,
           v9 & 7,
           (v9 >> 3) & 1,
           (v9 >> 8) & 0x3FF,
           (v9 >> 18) & 1,
           (*(unsigned __int8 *)(a1 + 5) >> 6) & 1,
           (v9 >> 19) & 1,
           *(unsigned __int8 *)(a1 + 5) >> 7);
}
