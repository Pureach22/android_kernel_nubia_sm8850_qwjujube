__int64 __fastcall lim_mlm_add_bss(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v11; // x21
  unsigned int v12; // w19
  _QWORD *context; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _QWORD *v24; // x20
  __int64 cmpt_obj; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x21
  _BYTE *v35; // x25
  __int16 v36; // w2
  __int64 v38; // x0
  __int64 v39; // x24
  int started; // w22
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7

  v11 = *(_QWORD *)(a11 + 16);
  v12 = *(unsigned __int8 *)(a11 + 10);
  context = _cds_get_context(54, (__int64)"lim_mlm_add_bss", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v24 = context;
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v11, v16, v17, v18, v19, v20, v21, v22, v23);
    if ( cmpt_obj )
    {
      v34 = cmpt_obj;
      v35 = (_BYTE *)(a11 + 7022);
      qdf_mem_copy((void *)(cmpt_obj + 184), (const void *)(a11 + 24), 6u);
      if ( *(_BYTE *)(a11 + 8676) == 1 )
      {
        lim_decide_he_op(a1, v34 + 68, a11);
        lim_update_usr_he_cap(a1, a11);
      }
      if ( a11 && *(_BYTE *)(a11 + 10071) == 1 )
      {
        lim_decide_eht_op(a1, v34 + 84, a11);
        lim_update_usr_eht_cap(a1, a11);
      }
      v36 = *(_WORD *)(a11 + 8);
      *(_DWORD *)(a11 + 72) = 16;
      qdf_trace(53, 0, v36, 16);
      if ( !(unsigned int)lim_pre_vdev_start(a1, v34, a11) )
      {
        v38 = _qdf_mem_malloc(0x368u, "lim_mlm_add_bss", 361);
        if ( v38 )
        {
          v39 = v38;
          *(_BYTE *)(v38 + 850) = *(_BYTE *)(a11 + 7170);
          *(_BYTE *)(v38 + 17) = *(_BYTE *)(a11 + 155);
          *(_DWORD *)(v38 + 852) = *(_DWORD *)(a11 + 7176);
          *(_BYTE *)(v38 + 18) = (*(_BYTE *)(a11 + 7024) & 0x10) != 0;
          *(_BYTE *)(v38 + 59) = lim_get_ht_capability(a1, 9, a11);
          *(_BYTE *)(v39 + 58) = lim_get_ht_capability(a1, 8, a11);
          started = wma_pre_vdev_start_setup(v12, v39);
          _qdf_mem_free(v39);
          if ( !started )
          {
            if ( !*v35 )
              ucfg_pmo_disable_wakeup_event(v24[3], v12, 11);
            if ( !(unsigned int)wma_vdev_pre_start(v12, 0)
              && !(unsigned int)vdev_mgr_start_send(v34, 0, v41, v42, v43, v44, v45, v46, v47, v48) )
            {
              wma_post_vdev_start_setup(v12);
              return 0;
            }
            wma_remove_bss_peer_on_failure(v24, v12);
          }
        }
      }
      wma_send_add_bss_resp(v24, v12, 16);
      return 0;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: vdev component object is NULL",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "lim_mlm_add_bss");
  }
  return 500;
}
