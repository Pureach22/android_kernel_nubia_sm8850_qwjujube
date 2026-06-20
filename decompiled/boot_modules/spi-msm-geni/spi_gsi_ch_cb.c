void __fastcall spi_gsi_ch_cb(__int64 a1, int *a2, __int64 a3)
{
  int v3; // w3
  __int64 v4; // x20
  __int64 v6; // x0
  __int64 v7; // x0

  if ( !a2 || !a3 )
  {
    printk(&unk_E0B3);
    return;
  }
  v3 = *a2;
  v4 = *(_QWORD *)(a3 + 152);
  if ( *a2 && v3 != 8 )
  {
    if ( (unsigned int)(v3 - 1) >= 6 )
    {
      ipc_log_string(*(_QWORD *)(v4 + 472), "%s: Unsupported event: %d\n", "spi_gsi_ch_cb", v3);
      if ( !*(_QWORD *)(v4 + 200) )
        return;
      goto LABEL_7;
    }
    ipc_log_string(
      *(_QWORD *)(v4 + 472),
      "%s: cb_ev %d status %llu ts %llu count %llu\n",
      "spi_gsi_ch_cb",
      v3,
      *((_QWORD *)a2 + 1),
      *((_QWORD *)a2 + 2),
      *((_QWORD *)a2 + 3));
    v6 = *(_QWORD *)(v4 + 200);
    if ( v6 )
    {
      dev_err(
        v6,
        "%s: cb_ev %d status %llu ts %llu count %llu\n",
        "spi_gsi_ch_cb",
        *a2,
        *((_QWORD *)a2 + 1),
        *((_QWORD *)a2 + 2),
        *((_QWORD *)a2 + 3));
      if ( !*(_QWORD *)(v4 + 200) )
      {
LABEL_16:
        ipc_log_string(*(_QWORD *)(v4 + 472), "err.routine %u, err.type %u, err.code %u\n", a2[8], a2[9], a2[10]);
        v7 = *(_QWORD *)(v4 + 200);
        if ( v7 )
          dev_err(v7, "err.routine %u, err.type %u, err.code %u\n", a2[8], a2[9], a2[10]);
        else
          printk(&unk_EA3D);
        if ( *(_QWORD *)(v4 + 200) )
          spi_trace_log();
        *(_BYTE *)(v4 + 448) = 1;
        complete_all(v4 + 384);
        complete_all(v4 + 416);
        return;
      }
    }
    else
    {
      printk(&unk_E544);
      if ( !*(_QWORD *)(v4 + 200) )
        goto LABEL_16;
    }
    spi_trace_log();
    goto LABEL_16;
  }
  ipc_log_string(
    *(_QWORD *)(v4 + 472),
    "%s:cb_ev%d status%llu ts%llu count%llu\n",
    "spi_gsi_ch_cb",
    v3,
    *((_QWORD *)a2 + 1),
    *((_QWORD *)a2 + 2),
    *((_QWORD *)a2 + 3));
  if ( *(_QWORD *)(v4 + 200) )
LABEL_7:
    spi_trace_log();
}
