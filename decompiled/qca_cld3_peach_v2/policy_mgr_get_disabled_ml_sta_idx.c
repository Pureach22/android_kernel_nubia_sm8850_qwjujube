__int64 __fastcall policy_mgr_get_disabled_ml_sta_idx(
        __int64 a1,
        _BYTE *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        unsigned __int8 a6)
{
  __int64 context; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  unsigned int v21; // w20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x5
  __int64 v31; // x8
  __int64 v32; // x8

  context = policy_mgr_get_context(a1);
  if ( !context )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid Context",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "policy_mgr_get_disabled_ml_sta_idx");
  v20 = context;
  v21 = a6;
  qdf_mutex_acquire(context + 56);
  if ( pm_disabled_ml_links[0] == 1 && !dword_8D4FC4 )
  {
    v30 = (unsigned __int8)*a2;
    if ( a6 > 4u || (unsigned int)v30 >= 5 )
    {
LABEL_13:
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid fill_index: %d or ml_sta: %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "policy_mgr_get_disabled_ml_sta_idx",
        v21,
        v30);
      return qdf_mutex_release(v20 + 56);
    }
    *(_BYTE *)(a5 + a6) = byte_8D4FCC;
    *(_DWORD *)(a4 + 4LL * a6) = dword_8D4FC8;
    v31 = (unsigned __int8)*a2;
    *a2 = v31 + 1;
    *(_BYTE *)(a3 + v31) = a6;
    v21 = a6 + 1;
  }
  if ( byte_8D4FD0 != 1 || dword_8D4FD4 )
    return qdf_mutex_release(v20 + 56);
  v30 = (unsigned __int8)*a2;
  if ( v21 > 4 || (unsigned int)v30 > 4 )
    goto LABEL_13;
  *(_BYTE *)(a5 + v21) = byte_8D4FDC;
  *(_DWORD *)(a4 + 4LL * v21) = dword_8D4FD8;
  v32 = (unsigned __int8)*a2;
  *a2 = v32 + 1;
  *(_BYTE *)(a3 + v32) = v21;
  return qdf_mutex_release(v20 + 56);
}
