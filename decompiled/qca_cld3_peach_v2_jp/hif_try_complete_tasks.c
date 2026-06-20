__int64 __fastcall hif_try_complete_tasks(__int64 a1)
{
  unsigned int v2; // w25
  int v3; // w19
  int v4; // w21
  int v5; // w20
  int v6; // w4
  int v7; // w0
  int v8; // w22

  v2 = 0;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  while ( 1 )
  {
    v6 = *(_DWORD *)(a1 + 672);
    if ( !v6 )
      break;
    if ( v2 > 0x18 )
      goto LABEL_12;
    ++v2;
    qdf_trace_msg(
      61,
      5,
      "%s: waiting for tasklets %d grp tasklets %d work %d oom_work %d",
      "hif_try_complete_tasks",
      v6,
      v3,
      v4,
      v5);
    hif_print_ce(a1, 0);
LABEL_2:
    msleep(10);
  }
  v3 = *(_DWORD *)(a1 + 676);
  if ( !v3 )
  {
    v7 = hal_get_reg_write_pending_work(*(_QWORD *)(a1 + 2560));
    v6 = 0;
    v4 = v7;
    if ( !v7 )
    {
      v5 = *(_DWORD *)(a1 + 680);
      if ( !v5 )
      {
        qdf_trace_msg(61, 5, "%s: CE HP-TP data:", "hif_try_complete_tasks");
        return hif_print_ce(a1, 1);
      }
      v4 = 0;
    }
  }
  if ( ++v2 <= 0x19 )
  {
    qdf_trace_msg(
      61,
      5,
      "%s: waiting for tasklets %d grp tasklets %d work %d oom_work %d",
      "hif_try_complete_tasks",
      0,
      v3,
      v4,
      v5);
    goto LABEL_2;
  }
LABEL_12:
  v8 = v6;
  qdf_trace_msg(
    61,
    2,
    "%s: pending tasklets %d grp tasklets %d work %d oom work %d",
    "hif_try_complete_tasks",
    v6,
    v3,
    v4,
    v5);
  if ( v5 )
    qdf_trace_msg(
      61,
      2,
      "%s: OOM thread is still pending %d tasklets %d grp tasklets %d work %d",
      "hif_try_complete_tasks",
      v5,
      v8,
      v3,
      v4);
  return 5;
}
