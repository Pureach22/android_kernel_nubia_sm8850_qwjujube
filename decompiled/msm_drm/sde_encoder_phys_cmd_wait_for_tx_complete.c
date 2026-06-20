__int64 __fastcall sde_encoder_phys_cmd_wait_for_tx_complete(_DWORD *a1)
{
  __int64 v1; // x8
  int v2; // w4
  __int64 result; // x0
  int v5; // w7
  unsigned int v6; // w20
  int v7; // w4
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return 4294967274LL;
  v1 = *(_QWORD *)a1;
  if ( *(_QWORD *)a1 )
  {
    if ( *(_BYTE *)(v1 + 4922) == 1 && a1[166] == 3 )
      return 0;
    if ( !a1[219] )
    {
      v2 = *(_DWORD *)(v1 + 24);
LABEL_13:
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_encoder_phys_cmd_wait_for_tx_complete",
        2156,
        -1,
        v2,
        a1[168] - 1,
        a1[208],
        -1059143953,
        vars0);
      return 0;
    }
  }
  else if ( !a1[219] )
  {
    v2 = -1;
    goto LABEL_13;
  }
  result = sde_encoder_phys_cmd_wait_for_idle();
  if ( (_DWORD)result )
  {
    v6 = result;
    if ( *(_QWORD *)a1 )
      v7 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
    else
      v7 = -1;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_phys_cmd_wait_for_tx_complete",
      2163,
      -1,
      v7,
      a1[168] - 1,
      -1059143953,
      v5,
      vars0);
    printk(&unk_25AE80, "sde_encoder_phys_cmd_wait_for_tx_complete");
    return v6;
  }
  return result;
}
