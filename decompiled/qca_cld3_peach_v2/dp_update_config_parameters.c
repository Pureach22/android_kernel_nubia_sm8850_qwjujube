__int64 __fastcall dp_update_config_parameters(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w8
  unsigned int v13; // w8

  if ( a1 )
  {
    *(_BYTE *)(*(_QWORD *)(a1 + 40) + 529LL) = *(_BYTE *)a2 & 1;
    *(_BYTE *)(*(_QWORD *)(a1 + 40) + 530LL) = (*(_BYTE *)a2 & 2) != 0;
    *(_BYTE *)(*(_QWORD *)(a1 + 40) + 528LL) = (*(_BYTE *)a2 & 8) != 0;
    *(_BYTE *)(*(_QWORD *)(a1 + 40) + 546LL) = (*(_BYTE *)a2 & 0x10) != 0;
    *(_BYTE *)(*(_QWORD *)(a1 + 40) + 547LL) = (*(_BYTE *)a2 & 0x20) != 0;
    *(_BYTE *)(*(_QWORD *)(a1 + 40) + 548LL) = (*(_BYTE *)a2 & 0x40) != 0;
    *(_BYTE *)(*(_QWORD *)(a1 + 40) + 545LL) = *(_BYTE *)(a2 + 1) & 1;
    *(_BYTE *)(*(_QWORD *)(a1 + 40) + 540LL) = (*(_WORD *)a2 & 0x200) != 0;
    *(_BYTE *)(*(_QWORD *)(a1 + 40) + 532LL) = (*(_BYTE *)a2 & 4) != 0;
    v12 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(*(_QWORD *)(a1 + 40) + 672LL) = v12;
    *(_BYTE *)(*(_QWORD *)(a1 + 40) + 685LL) = v12 < 0x400;
    v13 = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(*(_QWORD *)(a1 + 40) + 676LL) = v13;
    *(_BYTE *)(*(_QWORD *)(a1 + 40) + 684LL) = v13 < 0x400;
    *(_DWORD *)(*(_QWORD *)(a1 + 40) + 680LL) = *(_DWORD *)(a2 + 12);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: tx_comp_loop_pkt_limit %u tx_comp_enable_eol_data_check %u rx_reap_loop_pkt_limit %u rx_enable_eol_data_check "
      "%u rx_hp_oos_update_limit %u",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_update_rx_soft_irq_limit_params",
      *(unsigned int *)(*(_QWORD *)(a1 + 40) + 672LL),
      *(unsigned __int8 *)(*(_QWORD *)(a1 + 40) + 685LL),
      *(unsigned int *)(*(_QWORD *)(a1 + 40) + 676LL),
      *(unsigned __int8 *)(*(_QWORD *)(a1 + 40) + 684LL),
      *(_DWORD *)(*(_QWORD *)(a1 + 40) + 680LL));
    *(_DWORD *)(*(_QWORD *)(a1 + 40) + 556LL) = *(unsigned __int8 *)(a2 + 2);
    *(_DWORD *)(*(_QWORD *)(a1 + 40) + 560LL) = *(unsigned __int8 *)(a2 + 3);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x89u,
      2u,
      "%s: %pK: Invalid handle",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_update_config_parameters",
      0);
    return 4;
  }
}
