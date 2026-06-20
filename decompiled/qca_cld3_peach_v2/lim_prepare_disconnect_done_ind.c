__int64 __fastcall lim_prepare_disconnect_done_ind(__int64 a1, __int64 *a2, char a3, unsigned int a4, const void *a5)
{
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x22
  __int64 result; // x0
  unsigned int v20; // w8

  v9 = _qdf_mem_malloc(0x14u, "lim_prepare_disconnect_done_ind", 1299);
  if ( !v9 )
    return 16;
  v18 = v9;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Prepare eWNI_SME_DISCONNECT_DONE_IND withretCode: %d",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "lim_prepare_disconnect_done_ind",
    a4);
  *(_BYTE *)(v18 + 4) = a3;
  *(_DWORD *)v18 = 1315855;
  if ( a5 )
    qdf_mem_copy((void *)(v18 + 12), a5, 6u);
  result = 0;
  if ( a4 == 505 )
    v20 = 0;
  else
    v20 = a4;
  *(_DWORD *)(v18 + 8) = v20;
  *a2 = v18;
  return result;
}
