__int64 __fastcall cm_csr_handle_diconnect_req(
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
  unsigned int v11; // w19
  _QWORD *context; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  __int64 v23; // x21
  _QWORD *v24; // x23
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w8
  int v35; // w8

  v11 = *(unsigned __int8 *)(a1 + 104);
  context = _cds_get_context(52, (__int64)"cm_csr_handle_diconnect_req", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
    return 4;
  if ( v11 > 5
    || (v22 = context[2153], (v23 = v22 + 96LL * v11) == 0)
    || !v22
    || (*(_BYTE *)(v22 + 96LL * v11 + 1) & 1) == 0 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: session not found for vdev_id %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "cm_csr_handle_diconnect_req",
      v11);
    return 4;
  }
  v24 = context;
  ((void (__fastcall *)(_QWORD))cm_csr_set_joining)(v11);
  ++*(_DWORD *)(v23 + 64);
  v33 = *(_DWORD *)(a2 + 8);
  if ( v33 != 18 )
  {
    if ( v33 == 7 )
    {
      v35 = *(_DWORD *)(a2 + 12);
      if ( v35 == 65533 )
      {
        ++*(_DWORD *)(v23 + 80);
      }
      else if ( v35 == 4 )
      {
        ++*(_DWORD *)(v23 + 84);
      }
    }
    else if ( v33 == 6 )
    {
      ++*(_DWORD *)(v23 + 72);
    }
    else
    {
      ++*(_DWORD *)(v23 + 68);
    }
  }
  csr_update_prev_ap_info((unsigned __int8 *)v23, a1, v25, v26, v27, v28, v29, v30, v31, v32);
  sme_qos_csr_event_ind(v24, v11, 6, 0);
  return 0;
}
