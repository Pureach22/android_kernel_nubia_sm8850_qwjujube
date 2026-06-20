__int64 __fastcall target_if_vdev_mgr_rsp_timer_start(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 cmpt_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x23
  unsigned __int64 v16; // x24
  __int64 v17; // x26
  unsigned int v18; // w21
  __int64 v19; // x23
  unsigned int multiplier; // w22
  __int64 v21; // x0
  unsigned __int64 v25; // x8
  unsigned __int64 v32; // x9

  cmpt_obj = wlan_psoc_mlme_get_cmpt_obj(a1);
  if ( cmpt_obj )
    qdf_mutex_acquire(cmpt_obj + 688);
  v15 = 0;
  v16 = (unsigned __int64)"%s: VDEV %d: %s requested, waiting for %s response";
  v17 = a2 + 64;
  do
  {
    if ( a3 != (_DWORD)v15 && ((*(_QWORD *)(a2 + 64) >> v15) & 1) != 0 )
    {
      if ( a3 >= 8 )
        goto LABEL_15;
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: VDEV %d: %s requested, waiting for %s response",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "_target_if_vdev_mgr_rsp_timer_start",
        *(unsigned __int8 *)(a2 + 84),
        string_from_rsp_bit_strings_0[a3],
        string_from_rsp_bit_strings_0[v15]);
      target_if_vdev_mgr_rsp_timer_stop(a1, a2, v15);
    }
    ++v15;
  }
  while ( v15 != 8 );
  v16 = a3 >> 6;
  v15 = 1LL << a3;
  while ( 1 )
  {
    _X9 = (unsigned __int64 *)(v17 + 8 * v16);
    __asm { PRFM            #0x11, [X9] }
    do
      v25 = __ldxr(_X9);
    while ( __stlxr(v25 | v15, _X9) );
    __dmb(0xBu);
    if ( (v25 & v15) == 0 )
      break;
    if ( a3 < 8 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: VDEV %d: %s requested, waiting for %s response",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "_target_if_vdev_mgr_rsp_timer_start",
        *(unsigned __int8 *)(a2 + 84),
        string_from_rsp_bit_strings_0[a3],
        string_from_rsp_bit_strings_0[a3]);
      target_if_vdev_mgr_rsp_timer_stop(a1, a2, a3);
      _X8 = (unsigned __int64 *)(v17 + 8 * v16);
      __asm { PRFM            #0x11, [X8] }
      do
        v32 = __ldxr(_X8);
      while ( __stxr(v32 | v15, _X8) );
      break;
    }
LABEL_15:
    __break(0x5512u);
  }
  wlan_objmgr_psoc_get_ref(a1, 72);
  v18 = *(_DWORD *)(a2 + 72);
  v19 = jiffies;
  multiplier = qdf_timer_get_multiplier();
  *(_QWORD *)(a2 + 24) = v19 + _msecs_to_jiffies(v18) * multiplier;
  add_timer(a2 + 8);
  v21 = wlan_psoc_mlme_get_cmpt_obj(a1);
  if ( v21 )
    qdf_mutex_release(v21 + 688);
  return 0;
}
