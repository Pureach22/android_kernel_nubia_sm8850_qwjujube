__int64 __fastcall wma_oem_event_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10)
{
  _QWORD *context; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  const char *v29; // x2
  unsigned int v30; // w8
  __int64 v32; // x10
  int v33; // w9
  __int64 v34; // x10
  int v35; // w9
  void (__fastcall *v36)(__int64 *, __int64); // x8
  __int64 v37; // x1
  void (__fastcall *v38)(_QWORD); // x8
  __int64 v39; // [xsp+8h] [xbp-38h] BYREF
  __int64 v40; // [xsp+10h] [xbp-30h]
  __int64 v41; // [xsp+18h] [xbp-28h]
  __int64 v42; // [xsp+20h] [xbp-20h]
  __int64 v43; // [xsp+28h] [xbp-18h]
  __int64 v44; // [xsp+30h] [xbp-10h]
  __int64 v45; // [xsp+38h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(53, (__int64)"wma_oem_event_handler", a1, a2, a3, a4, a5, a6, a7, a8);
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  if ( !_cds_get_context(54, (__int64)"wma_oem_event_handler", v12, v13, v14, v15, v16, v17, v18, v19) )
  {
    v29 = "%s: NULL wma handle";
LABEL_11:
    qdf_trace_msg(0x36u, 2u, v29, v20, v21, v22, v23, v24, v25, v26, v27, "wma_oem_event_handler");
    goto LABEL_12;
  }
  if ( !context )
  {
    v29 = "%s: NULL mac handle";
    goto LABEL_11;
  }
  if ( !a10 )
  {
    v29 = "%s: Invalid oem data Event";
    goto LABEL_11;
  }
  v28 = *a10;
  if ( !*a10 )
  {
    v29 = "%s: Invalid fixed param in oem data Event";
    goto LABEL_11;
  }
  if ( *(_DWORD *)(v28 + 4) <= *((_DWORD *)a10 + 6) )
  {
    v32 = a10[2];
    v33 = *((_DWORD *)a10 + 10);
    v40 = *(unsigned int *)(v28 + 4);
    v42 = v32;
    if ( v33 )
    {
      v34 = a10[4];
      LODWORD(v43) = v33;
      v44 = v34;
    }
    v35 = *(_DWORD *)(v28 + 8);
    v30 = 16;
    if ( v35 > 1 )
    {
      if ( v35 != 2 )
      {
        if ( v35 != 3 )
          goto LABEL_13;
        if ( (unsigned int)wma_oem_smem_event_handler() )
        {
          v30 = 16;
          goto LABEL_13;
        }
        goto LABEL_33;
      }
    }
    else
    {
      if ( v35 )
      {
        if ( v35 != 1 )
          goto LABEL_13;
        v36 = (void (__fastcall *)(__int64 *, __int64))context[1819];
        if ( !v36 )
        {
LABEL_33:
          v30 = 0;
          goto LABEL_13;
        }
LABEL_26:
        v37 = *((unsigned __int8 *)context + 14560);
        if ( *((_DWORD *)v36 - 1) != -1528054483 )
          __break(0x8228u);
        v36(&v39, v37);
        goto LABEL_33;
      }
      v36 = (void (__fastcall *)(__int64 *, __int64))context[1819];
      if ( v36 )
        goto LABEL_26;
    }
    v38 = (void (__fastcall *)(_QWORD))context[1821];
    if ( v38 )
    {
      if ( *((_DWORD *)v38 - 1) != 1641065772 )
        __break(0x8228u);
      v38(&v39);
    }
    goto LABEL_33;
  }
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: Invalid data len %d num_data %d",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "wma_oem_event_handler");
LABEL_12:
  v30 = -22;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v30;
}
