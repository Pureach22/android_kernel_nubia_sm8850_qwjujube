__int64 __fastcall htc_stop(__int64 a1)
{
  __int64 i; // x20
  __int64 v3; // x22
  int v4; // w8
  __int64 v5; // x2
  int v6; // w8
  __int64 v7; // x2
  int v8; // w8
  __int64 v9; // x2
  int v10; // w8
  __int64 v11; // x2
  int v12; // w8
  __int64 v13; // x2
  int v14; // w8
  __int64 v15; // x2
  int v16; // w8
  __int64 v17; // x2
  int v18; // w8
  __int64 v19; // x2
  int v20; // w8
  __int64 v21; // x2
  __int64 result; // x0
  int v23; // w8
  __int64 v24; // x9
  __int64 v25; // x11
  int v26; // w12

  if ( (dword_B804 & 8) != 0 )
    qdf_trace_msg(56, 2, "%s: +htc_stop\n", "htc_stop");
  if ( a1 )
    cancel_work_sync(a1 + 3504);
  qdf_trace_msg(62, 4, "%s: endpoints cleanup\n", "htc_stop");
  for ( i = 0; i != 2952; i += 328 )
  {
    v3 = a1 + i;
    htc_flush_rx_hold_queue(a1, a1 + i + 8);
    htc_flush_endpoint_tx(a1, a1 + i + 8, 0);
    if ( *(_DWORD *)(a1 + i + 148) )
    {
      timer_delete((timer_t)(v3 + 152));
      timer_delete_sync(v3 + 152);
    }
  }
  qdf_trace_msg(62, 4, "%s: stopping hif layer\n", "htc_stop");
  hif_stop(*(_QWORD *)a1);
  qdf_trace_msg(62, 4, "%s: flush endpoints Tx lookup queue\n", "htc_stop");
  v4 = *(unsigned __int16 *)(a1 + 12);
  if ( v4 == 1 )
    goto LABEL_13;
  if ( v4 == 256 )
  {
    v5 = 0;
    goto LABEL_15;
  }
  if ( v4 == 768 && !*(_DWORD *)(a1 + 148) )
  {
LABEL_13:
    v5 = 1;
LABEL_15:
    htc_flush_endpoint_txlookupQ(a1, 0, v5);
  }
  v6 = *(unsigned __int16 *)(a1 + 340);
  if ( v6 != 1 )
  {
    if ( v6 == 256 )
    {
      v7 = 0;
      goto LABEL_22;
    }
    if ( v6 != 768 || *(_DWORD *)(a1 + 476) )
      goto LABEL_23;
  }
  v7 = 1;
LABEL_22:
  htc_flush_endpoint_txlookupQ(a1, 1, v7);
LABEL_23:
  v8 = *(unsigned __int16 *)(a1 + 668);
  if ( v8 == 1 )
    goto LABEL_27;
  if ( v8 == 256 )
  {
    v9 = 0;
    goto LABEL_29;
  }
  if ( v8 == 768 && !*(_DWORD *)(a1 + 804) )
  {
LABEL_27:
    v9 = 1;
LABEL_29:
    htc_flush_endpoint_txlookupQ(a1, 2, v9);
  }
  v10 = *(unsigned __int16 *)(a1 + 996);
  if ( v10 != 1 )
  {
    if ( v10 == 256 )
    {
      v11 = 0;
      goto LABEL_36;
    }
    if ( v10 != 768 || *(_DWORD *)(a1 + 1132) )
      goto LABEL_37;
  }
  v11 = 1;
LABEL_36:
  htc_flush_endpoint_txlookupQ(a1, 3, v11);
LABEL_37:
  v12 = *(unsigned __int16 *)(a1 + 1324);
  if ( v12 == 1 )
    goto LABEL_41;
  if ( v12 == 256 )
  {
    v13 = 0;
    goto LABEL_43;
  }
  if ( v12 == 768 && !*(_DWORD *)(a1 + 1460) )
  {
LABEL_41:
    v13 = 1;
LABEL_43:
    htc_flush_endpoint_txlookupQ(a1, 4, v13);
  }
  v14 = *(unsigned __int16 *)(a1 + 1652);
  if ( v14 != 1 )
  {
    if ( v14 == 256 )
    {
      v15 = 0;
      goto LABEL_50;
    }
    if ( v14 != 768 || *(_DWORD *)(a1 + 1788) )
      goto LABEL_51;
  }
  v15 = 1;
LABEL_50:
  htc_flush_endpoint_txlookupQ(a1, 5, v15);
LABEL_51:
  v16 = *(unsigned __int16 *)(a1 + 1980);
  if ( v16 == 1 )
    goto LABEL_55;
  if ( v16 == 256 )
  {
    v17 = 0;
    goto LABEL_57;
  }
  if ( v16 == 768 && !*(_DWORD *)(a1 + 2116) )
  {
LABEL_55:
    v17 = 1;
LABEL_57:
    htc_flush_endpoint_txlookupQ(a1, 6, v17);
  }
  v18 = *(unsigned __int16 *)(a1 + 2308);
  if ( v18 != 1 )
  {
    if ( v18 == 256 )
    {
      v19 = 0;
      goto LABEL_64;
    }
    if ( v18 != 768 || *(_DWORD *)(a1 + 2444) )
      goto LABEL_65;
  }
  v19 = 1;
LABEL_64:
  htc_flush_endpoint_txlookupQ(a1, 7, v19);
LABEL_65:
  v20 = *(unsigned __int16 *)(a1 + 2636);
  if ( v20 == 1 )
    goto LABEL_69;
  if ( v20 == 256 )
  {
    v21 = 0;
    goto LABEL_71;
  }
  if ( v20 == 768 && !*(_DWORD *)(a1 + 2772) )
  {
LABEL_69:
    v21 = 1;
LABEL_71:
    htc_flush_endpoint_txlookupQ(a1, 8, v21);
  }
  result = qdf_trace_msg(62, 4, "%s: resetting endpoints state\n", "htc_stop");
  v23 = 0;
  v24 = 0;
  do
  {
    v25 = a1 + v24;
    v24 += 328;
    *(_WORD *)(v25 + 12) = 0;
    *(_QWORD *)(v25 + 112) = v25 + 112;
    *(_QWORD *)(v25 + 120) = v25 + 112;
    *(_QWORD *)(v25 + 232) = v25 + 232;
    *(_QWORD *)(v25 + 240) = v25 + 232;
    *(_QWORD *)(v25 + 136) = 0;
    *(_DWORD *)(v25 + 8) = v23++;
    *(_DWORD *)(v25 + 128) = 0;
    *(_DWORD *)(v25 + 248) = 0;
    *(_QWORD *)(v25 + 256) = v25 + 256;
    *(_QWORD *)(v25 + 264) = v25 + 256;
    *(_DWORD *)(v25 + 272) = 0;
    *(_QWORD *)(v25 + 288) = a1;
    v26 = htc_credit_flow;
    *(_QWORD *)(v25 + 328) = 0;
    *(_BYTE *)(v25 + 308) = v26 != 0;
    *(_DWORD *)(v25 + 284) = 0;
  }
  while ( v24 != 2952 );
  if ( (dword_B804 & 8) != 0 )
    return qdf_trace_msg(56, 2, "%s: -htc_stop\n", "htc_stop");
  return result;
}
