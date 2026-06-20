__int64 __fastcall hdd_set_master_channel_list(
        __int64 a1,
        _WORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  int v22; // w10
  __int64 v23; // x8
  unsigned __int16 *v24; // x11
  const char *v25; // x2
  unsigned int v26; // w12
  int v27; // w12
  __int64 v28; // x12
  unsigned int v29; // w20
  unsigned int updated; // w0

  if ( *(_DWORD *)(*(_QWORD *)a1 + 40LL) != 1 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: command not received for sap",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_set_master_channel_list");
    return 4294967274LL;
  }
  v12 = _qdf_mem_malloc(0x198u, "hdd_set_master_channel_list", 14664);
  if ( !v12 )
    return 4294967284LL;
  v21 = v12;
  v22 = (unsigned __int16)(*a2 - 4);
  if ( (unsigned int)v22 < 4 )
  {
LABEL_11:
    v29 = -22;
    v25 = "%s: no valid freq found";
  }
  else
  {
    v23 = 0;
    v24 = a2 + 2;
    v25 = "%s: invalid freq";
    do
    {
      v26 = *v24;
      if ( v26 < 4 || v22 < v26 )
        break;
      v27 = *((_DWORD *)v24 + 1);
      if ( !v27 )
      {
        v29 = -22;
        goto LABEL_18;
      }
      *(_DWORD *)(v12 + 4 * v23) = v27;
      if ( v23 == 101 )
      {
        LODWORD(v23) = 102;
        goto LABEL_16;
      }
      ++v23;
      v28 = (*v24 + 3) & 0x1FFFC;
      v22 -= v28;
      v24 = (unsigned __int16 *)((char *)v24 + v28);
    }
    while ( v22 > 3 );
    if ( !(_WORD)v23 )
      goto LABEL_11;
LABEL_16:
    updated = wlansap_update_sap_chan_list(a1 + 280, v12, (unsigned int)v23);
    if ( !updated )
    {
      v29 = 0;
      goto LABEL_19;
    }
    v29 = updated;
    v25 = "%s: sap chan list update failure";
  }
LABEL_18:
  qdf_trace_msg(0x33u, 2u, v25, v13, v14, v15, v16, v17, v18, v19, v20, "hdd_set_master_channel_list");
LABEL_19:
  _qdf_mem_free(v21);
  return v29;
}
