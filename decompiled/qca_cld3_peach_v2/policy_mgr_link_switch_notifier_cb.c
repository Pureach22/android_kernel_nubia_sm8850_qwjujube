__int64 __fastcall policy_mgr_link_switch_notifier_cb(__int64 a1, unsigned __int8 *a2, unsigned int a3)
{
  __int64 v5; // x8
  __int64 v6; // x19
  unsigned int v7; // w25
  unsigned int v8; // w26
  __int64 result; // x0
  unsigned int v10; // w22
  unsigned int v11; // w23
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v21; // x2
  unsigned int v22; // w1
  __int64 context; // x0
  __int64 v24; // x21
  int v25; // w8
  unsigned __int8 active_vdev_id; // w0
  unsigned int v27; // w24
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w20
  __int64 assoc_link_vdev; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  _WORD v46[2]; // [xsp+18h] [xbp-E8h] BYREF
  unsigned __int16 v47; // [xsp+1Ch] [xbp-E4h] BYREF
  __int64 v48; // [xsp+20h] [xbp-E0h] BYREF
  __int64 v49; // [xsp+28h] [xbp-D8h]
  __int64 v50; // [xsp+30h] [xbp-D0h]
  unsigned __int8 v51[4]; // [xsp+3Ch] [xbp-C4h] BYREF
  _QWORD v52[22]; // [xsp+40h] [xbp-C0h] BYREF
  int v53; // [xsp+F0h] [xbp-10h]
  __int64 v54; // [xsp+F8h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 216);
  if ( v5 )
    v6 = *(_QWORD *)(v5 + 80);
  else
    v6 = 0;
  v7 = *a2;
  v8 = a2[1];
  result = 0;
  v10 = a2[2];
  v11 = *((_DWORD *)a2 + 3);
  v53 = 0;
  memset(v52, 0, sizeof(v52));
  v51[0] = 0;
  v49 = 0;
  v50 = 0;
  v48 = 0;
  v47 = 0;
  v46[0] = 0;
  if ( a3 <= 1 )
  {
    if ( (policy_mgr_is_chan_switch_in_progress(v6) & 1) != 0 )
    {
      v21 = "%s: CSA is in progress for SAP/GO, reject the link switch";
      v22 = 8;
LABEL_18:
      qdf_trace_msg(0x4Fu, v22, v21, v13, v14, v15, v16, v17, v18, v19, v20, "policy_mgr_link_switch_notifier_cb");
      result = 4;
      goto LABEL_19;
    }
    context = policy_mgr_get_context(v6);
    if ( !context )
    {
      v21 = "%s: Invalid Context";
      v22 = 2;
      goto LABEL_18;
    }
    v24 = context;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: target link %d freq %d curr link %d notify reason %d link switch reason %d vdev %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "policy_mgr_link_switch_notifier_cb",
      v10,
      v11,
      v8,
      a3,
      *((_DWORD *)a2 + 6),
      v7);
    qdf_mem_set(&v48, 0x18u, 0);
    v25 = *((_DWORD *)a2 + 6);
    LOBYTE(v48) = v8;
    BYTE1(v48) = v10;
    HIDWORD(v48) = v11;
    LODWORD(v49) = v25;
    result = ml_nlink_conn_change_notify(v6, v7, 0, &v48);
    if ( !(_DWORD)result )
    {
      qdf_mutex_acquire(v24 + 56);
      ((void (__fastcall *)(__int64, _QWORD, _QWORD *, unsigned __int8 *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
        v6,
        v7,
        v52,
        v51);
      if ( !v51[0] && (policy_mgr_is_hw_dbs_capable(v6) & 1) == 0 )
      {
        active_vdev_id = ucfg_mlo_get_active_vdev_id(a1);
        ((void (__fastcall *)(__int64, _QWORD, _QWORD *, unsigned __int8 *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
          v6,
          active_vdev_id,
          v52,
          v51);
      }
      if ( a1 && !*(_DWORD *)(a1 + 16) )
      {
        if ( (*(_BYTE *)(a1 + 60) & 2) != 0 && (assoc_link_vdev = ucfg_mlo_get_assoc_link_vdev(a1)) != 0 )
        {
          if ( ucfg_cm_is_vdev_active(assoc_link_vdev, v38, v39, v40, v41, v42, v43, v44, v45) )
            v27 = 3;
          else
            v27 = 1;
        }
        else
        {
          v27 = 1;
        }
      }
      else
      {
        v27 = 0;
      }
      ml_nlink_get_dynamic_inactive_links(v6, a1, &v47, v46);
      if ( (((unsigned __int64)v47 >> v10) & 1) != 0 )
      {
        v36 = 0;
      }
      else
      {
        v36 = 0;
        if ( (policy_mgr_is_concurrency_allowed(v6, 0, v11, 3, v27, 0) & 1) == 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: target link %d freq %d not allowed by conc rule",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "policy_mgr_link_switch_notifier_cb",
            v10,
            v11);
          v36 = 4;
        }
      }
      if ( v51[0] )
        policy_mgr_restore_deleted_conn_info(v6, (unsigned int *)v52, v51[0], v28, v29, v30, v31, v32, v33, v34, v35);
      qdf_mutex_release(v24 + 56);
      result = v36;
    }
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
