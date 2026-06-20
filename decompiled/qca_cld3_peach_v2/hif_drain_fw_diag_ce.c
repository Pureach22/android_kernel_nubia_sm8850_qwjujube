__int64 __fastcall hif_drain_fw_diag_ce(__int64 a1)
{
  int fw_diag_ce_id; // w8
  __int64 result; // x0
  __int64 v4; // x20
  unsigned int v5; // w20
  __int64 v6; // x8
  __int64 v7; // x21
  int v8; // w22
  __int64 v9; // x8
  __int64 v10; // x8
  _BYTE v11[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  fw_diag_ce_id = hif_get_fw_diag_ce_id(a1, v11);
  result = 0;
  if ( fw_diag_ce_id )
    goto LABEL_14;
  if ( v11[0] >= 0xDuLL )
    goto LABEL_15;
  v4 = a1 + 56LL * v11[0];
  qdf_trace_msg(61, 5, "%s: before drain CE", "hif_drain_fw_diag_ce");
  result = hif_print_ce(a1, 2);
  if ( (*(_QWORD *)(v4 + 26456) & 1) != 0 || (*(_QWORD *)(v4 + 26456) & 2) != 0 )
  {
    result = 4294967280LL;
LABEL_14:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v5 = v11[0];
  if ( v11[0] < 0xCu )
  {
    v6 = a1 + 8LL * v11[0];
    v7 = *(_QWORD *)(v6 + 480);
    hif_record_ce_desc_event(a1, v11[0], 21, 0, 0, -1, v6);
    v8 = 33;
    do
    {
      ce_per_engine_service(a1, v5);
      if ( !ce_check_rx_pending(v7) )
      {
        ce_check_rx_pending(v7);
        goto LABEL_13;
      }
      hif_record_ce_desc_event(a1, v5, 19, 0, 0, -1, v9);
      --v8;
    }
    while ( v8 );
    if ( ce_check_rx_pending(v7) )
    {
      qdf_trace_msg(61, 5, "%s: Max drain count reached, abort suspend", "ce_poll_reap_by_id");
      result = 4294967285LL;
      goto LABEL_14;
    }
LABEL_13:
    hif_record_ce_desc_event(a1, v5, 22, 0, 0, -1, v10);
    result = 0;
    goto LABEL_14;
  }
LABEL_15:
  __break(0x5512u);
  return ce_dispatch_interrupt(result);
}
