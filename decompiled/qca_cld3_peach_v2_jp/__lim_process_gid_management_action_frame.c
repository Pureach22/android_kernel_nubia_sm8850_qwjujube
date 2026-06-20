__int64 __fastcall _lim_process_gid_management_action_frame(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x23
  unsigned __int8 *v14; // x24
  unsigned int v15; // w22
  __int64 result; // x0
  __int64 v17; // x19
  unsigned int v18; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w8
  unsigned int *v36; // x9
  const char *v37; // x2
  char v38; // w10
  __int16 v39; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v40; // [xsp+18h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(unsigned __int8 **)(a2 + 16);
  v13 = *(_QWORD *)(a2 + 24);
  v15 = *(_DWORD *)(a2 + 40);
  v39 = 0;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Received GID Management action frame",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "__lim_process_gid_management_action_frame");
  result = _qdf_mem_malloc(0x1Au, "__lim_process_gid_management_action_frame", 399);
  if ( result )
  {
    v17 = result;
    v18 = dot11f_unpack_vht_gid_management_action_frame(a1, v13, v15, result, 0);
    if ( (v18 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Fail to parse an Grp id frame (0x%08x, %d bytes):",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "__lim_process_gid_management_action_frame",
        v18,
        v15);
LABEL_17:
      result = _qdf_mem_free(v17);
      goto LABEL_18;
    }
    if ( v18 )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: warnings while unpacking Grp id frm (0x%08x, %d bytes):",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "__lim_process_gid_management_action_frame",
        v18,
        v15);
    if ( !dph_lookup_hash_entry(v19, v20, v21, v22, v23, v24, v25, v26, a1, v14 + 10, &v39, a3 + 360) )
    {
      v37 = "%s: Failed to get STA entry from hash table";
LABEL_16:
      qdf_trace_msg(0x35u, 2u, v37, v27, v28, v29, v30, v31, v32, v33, v34, "__lim_process_gid_management_action_frame");
      goto LABEL_17;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s:  MAC: %0x:%0x:%0x:%0x:%0x:%0x",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "__lim_process_gid_management_action_frame",
      v14[10],
      v14[11],
      v14[12],
      v14[13],
      v14[14],
      v14[15]);
    v36 = (unsigned int *)(v17 + 6);
    v35 = *(_DWORD *)(v17 + 6);
    if ( *(_DWORD *)(v17 + 2) )
    {
      if ( v35 )
      {
LABEL_15:
        v37 = "%s: rcved frame with mult group ID set";
        goto LABEL_16;
      }
      v35 = *(_DWORD *)(v17 + 2);
      v36 = (unsigned int *)(v17 + 2);
    }
    else if ( !v35 )
    {
      v37 = "%s: rcved Gid frame with no group ID set";
      goto LABEL_16;
    }
    if ( (v35 & 1) == 0 )
    {
      do
      {
        v38 = v35;
        v35 >>= 1;
      }
      while ( (v38 & 2) == 0 );
      *v36 = v35;
    }
    goto LABEL_15;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
