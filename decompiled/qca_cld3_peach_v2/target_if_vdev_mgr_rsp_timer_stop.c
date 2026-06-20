__int64 __fastcall target_if_vdev_mgr_rsp_timer_stop(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  __int64 v16; // x9
  unsigned int v17; // w20
  __int64 cmpt_obj; // x0
  void (__fastcall *v20)(__int64, __int64); // x8
  __int64 v21; // x1
  unsigned __int64 v28; // x10

  v6 = ((__int64 (*)(void))wlan_psoc_mlme_get_cmpt_obj)();
  if ( v6 )
    qdf_mutex_acquire(v6 + 688);
  if ( !a1 || (v15 = *(_QWORD *)(a1 + 2128)) == 0 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: tx_ops is NULL", v7, v8, v9, v10, v11, v12, v13, v14, "target_if_vdev_mgr_get_tx_ops");
    goto LABEL_11;
  }
  if ( !*(_QWORD *)(v15 + 1584) )
  {
LABEL_11:
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV %d: Failed to get mlme txrx_ops",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "_target_if_vdev_mgr_rsp_timer_stop",
      *(unsigned __int8 *)(a2 + 84));
LABEL_12:
    v17 = 16;
    goto LABEL_13;
  }
  v16 = 1LL << a3;
  _X11 = (unsigned __int64 *)(a2 + 64 + 8LL * (a3 >> 6));
  __asm { PRFM            #0x11, [X11] }
  do
    v28 = __ldxr(_X11);
  while ( __stlxr(v28 & ~v16, _X11) );
  __dmb(0xBu);
  if ( (v28 & v16) == 0 )
    goto LABEL_12;
  if ( *(_DWORD *)(a2 + 76) == 15 )
  {
    if ( a3 != 3 )
      goto LABEL_21;
LABEL_17:
    v20 = *(void (__fastcall **)(__int64, __int64))(v15 + 1584);
    v21 = *(unsigned __int8 *)(a2 + 84);
    if ( *((_DWORD *)v20 - 1) != -1344763252 )
      __break(0x8228u);
    v20(a1, v21);
    goto LABEL_21;
  }
  if ( a3 == 3 )
    goto LABEL_17;
  timer_delete((timer_t)(a2 + 8));
LABEL_21:
  *(_DWORD *)(a2 + 76) = 0;
  wlan_objmgr_psoc_release_ref(a1, 72);
  v17 = 0;
LABEL_13:
  cmpt_obj = wlan_psoc_mlme_get_cmpt_obj(a1);
  if ( cmpt_obj )
    qdf_mutex_release(cmpt_obj + 688);
  return v17;
}
