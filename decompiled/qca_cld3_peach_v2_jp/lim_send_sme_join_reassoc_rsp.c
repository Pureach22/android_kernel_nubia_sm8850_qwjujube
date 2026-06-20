__int64 __fastcall lim_send_sme_join_reassoc_rsp(__int64 a1, char a2, unsigned int a3, unsigned __int16 a4, __int64 a5)
{
  int v6; // w23
  bool v7; // zf
  __int64 v10; // x1
  const char *v12; // x24
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  char v22; // w8
  int v23; // w3

  v6 = a3;
  v7 = (a2 & 1) == 0;
  if ( (a2 & 1) != 0 )
    v10 = 8;
  else
    v10 = 4;
  if ( v7 )
    v12 = "Join";
  else
    v12 = "Reassoc";
  lim_diag_event_report(a1, v10, a5, a3);
  v13 = lim_result_code_str((unsigned int)v6);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Sending %s resp, with %s (%d)",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "lim_send_sme_join_reassoc_rsp",
    v12,
    v13,
    (unsigned int)v6);
  if ( v6 > 508 )
  {
    v22 = v6 + 2;
    if ( (unsigned int)(v6 - 510) > 0x1B )
    {
LABEL_19:
      if ( v6 == 509 )
      {
        v23 = 8;
        goto LABEL_23;
      }
      goto LABEL_22;
    }
    if ( ((1 << v22) & 0x80020C0) == 0 )
    {
      if ( ((1 << v22) & 0x4000003) != 0 )
      {
        v23 = 10;
LABEL_23:
        v6 = 16;
        return lim_cm_send_connect_rsp(a1, a5, 0, v23, v6, a4, a2 & 1);
      }
      if ( ((1 << v22) & 0x18) != 0 )
      {
        v23 = 7;
        goto LABEL_23;
      }
      goto LABEL_19;
    }
LABEL_16:
    v23 = 9;
    goto LABEL_23;
  }
  if ( v6 )
  {
    if ( v6 != 507 )
    {
      if ( v6 == 508 )
      {
        v23 = 6;
        goto LABEL_23;
      }
LABEL_22:
      v23 = 5;
      goto LABEL_23;
    }
    goto LABEL_16;
  }
  v23 = 0;
  return lim_cm_send_connect_rsp(a1, a5, 0, v23, v6, a4, a2 & 1);
}
