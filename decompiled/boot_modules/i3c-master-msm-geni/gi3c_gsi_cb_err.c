void __fastcall gi3c_gsi_cb_err(__int64 a1, const char *a2)
{
  int v2; // w3
  __int64 v4; // x19
  int v5; // w8

  v2 = *(_DWORD *)(a1 + 8);
  if ( (v2 & 0x7E0) != 0 )
  {
    v4 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL);
    ipc_log_string(*(_QWORD *)(v4 + 2528), "%s TCE Unexpected Err, stat:0x%x\n", a2, v2);
    if ( *(_QWORD *)(v4 + 8) )
      i3c_trace_log();
    v5 = *(_DWORD *)(a1 + 8);
    if ( (v5 & 0x20) != 0 )
    {
      geni_i3c_err(v4, 0);
      *(_DWORD *)(v4 + 21260) = *(_DWORD *)a1;
      v5 = *(_DWORD *)(a1 + 8);
      if ( (v5 & 0x40) == 0 )
      {
LABEL_6:
        if ( (v5 & 0x80) == 0 )
          goto LABEL_7;
        goto LABEL_14;
      }
    }
    else if ( (v5 & 0x40) == 0 )
    {
      goto LABEL_6;
    }
    geni_i3c_err(v4, 1u);
    v5 = *(_DWORD *)(a1 + 8);
    if ( (v5 & 0x80) == 0 )
    {
LABEL_7:
      if ( (v5 & 0x100) == 0 )
        goto LABEL_8;
      goto LABEL_15;
    }
LABEL_14:
    geni_i3c_err(v4, 2u);
    v5 = *(_DWORD *)(a1 + 8);
    if ( (v5 & 0x100) == 0 )
    {
LABEL_8:
      if ( (v5 & 0x200) == 0 )
        goto LABEL_9;
      goto LABEL_16;
    }
LABEL_15:
    geni_i3c_err(v4, 3u);
    v5 = *(_DWORD *)(a1 + 8);
    if ( (v5 & 0x200) == 0 )
    {
LABEL_9:
      if ( (v5 & 0x400) == 0 )
        return;
      goto LABEL_10;
    }
LABEL_16:
    geni_i3c_err(v4, 4u);
    if ( (*(_DWORD *)(a1 + 8) & 0x400) == 0 )
      return;
LABEL_10:
    geni_i3c_err(v4, 5u);
  }
}
