__int64 __fastcall csr_roam_substate_change(
        __int64 result,
        int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x21
  __int64 v13; // x22
  const char *v15; // x20
  const char *v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  if ( a3 >= 6 )
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: Invalid no of concurrent sessions %d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "csr_roam_substate_change",
             a3);
  v12 = result + 17268;
  if ( *(_DWORD *)(result + 17268 + 4LL * a3) != a2 )
  {
    v13 = result;
    v15 = mac_trace_getcsr_roam_sub_state(a2);
    v16 = mac_trace_getcsr_roam_sub_state(*(_DWORD *)(v12 + 4LL * a3));
    qdf_trace_msg(0x34u, 8u, "CSR RoamSubstate: [ %s <== %s ]", v17, v18, v19, v20, v21, v22, v23, v24, v15, v16);
    raw_spin_lock(v13 + 17472);
    *(_DWORD *)(v12 + 4LL * a3) = a2;
    return raw_spin_unlock(v13 + 17472);
  }
  return result;
}
