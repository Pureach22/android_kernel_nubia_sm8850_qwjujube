__int64 __fastcall policy_mgr_set_link_in_progress(__int64 a1, char a2)
{
  __int64 v4; // x1
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v16; // w9
  unsigned int v23; // w10

  qdf_mutex_acquire(a1 + 56);
  if ( (a2 & 1) != 0 )
  {
    _X8 = (unsigned int *)(a1 + 2664);
    __asm { PRFM            #0x11, [X8] }
    do
      v16 = __ldxr(_X8);
    while ( __stxr(v16 + 1, _X8) );
  }
  else if ( *(int *)(a1 + 2664) >= 1 )
  {
    _X8 = (unsigned int *)(a1 + 2664);
    __asm { PRFM            #0x11, [X8] }
    do
      v23 = __ldxr(_X8);
    while ( __stxr(v23 - 1, _X8) );
  }
  if ( *(_DWORD *)(a1 + 2664) )
    qdf_event_reset(a1 + 2672);
  else
    qdf_event_set(a1 + 2672, v4);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: link_in_progress %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "policy_mgr_set_link_in_progress",
    *(unsigned int *)(a1 + 2664));
  return qdf_mutex_release(a1 + 56);
}
