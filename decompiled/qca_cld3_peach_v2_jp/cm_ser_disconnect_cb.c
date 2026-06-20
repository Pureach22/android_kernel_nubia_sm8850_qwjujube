__int64 __fastcall cm_ser_disconnect_cb(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x21
  __int64 cm_ctx_fl; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  _QWORD *v23; // x20
  unsigned int v24; // w21
  _QWORD *v25; // x20
  double v26; // d0
  unsigned int *v27; // x8
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w21
  unsigned int v36; // w19
  __int64 v37; // [xsp+0h] [xbp-30h] BYREF
  __int64 v38; // [xsp+8h] [xbp-28h]
  __int64 v39; // [xsp+10h] [xbp-20h]
  __int64 v40; // [xsp+18h] [xbp-18h]
  __int64 v41; // [xsp+20h] [xbp-10h]
  __int64 v42; // [xsp+28h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: cmd is NULL, reason: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "cm_ser_disconnect_cb",
      (unsigned int)a2);
    goto LABEL_8;
  }
  v11 = *(_QWORD *)(a1 + 32);
  cm_ctx_fl = cm_get_cm_ctx_fl(v11, "cm_ser_disconnect_cb", 171);
  if ( !cm_ctx_fl )
  {
LABEL_8:
    result = 29;
    goto LABEL_23;
  }
  if ( a2 > 1 )
  {
    if ( a2 == 2 )
    {
      v26 = cm_reset_active_cm_id(v11, *(unsigned int *)(a1 + 4));
      wlan_objmgr_vdev_release_ref(v11, 0x4Du, v27, v26, v28, v29, v30, v31, v32, v33, v34);
      result = 0;
      goto LABEL_23;
    }
    if ( a2 != 3 )
      goto LABEL_14;
    v23 = (_QWORD *)cm_ctx_fl;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: Active command timeout",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "cm_ser_disconnect_cb",
      *(unsigned __int8 *)(v11 + 104),
      *(unsigned int *)(a1 + 4));
    cm_trigger_panic_on_cmd_timeout(*v23, 39);
    v24 = *(_DWORD *)(a1 + 4);
    v40 = 0;
    v41 = 0;
    v38 = 0;
    v39 = 0;
    v37 = 0;
    qdf_mem_set(&v37, 0x28u, 0);
    if ( !(unsigned int)cm_fill_disconnect_resp_from_cm_id(v23, v24, &v37) )
      cm_disconnect_complete(v23, (unsigned int *)&v37);
LABEL_13:
    result = 0;
    goto LABEL_23;
  }
  if ( a2 )
  {
    if ( a2 != 1 )
    {
LABEL_14:
      result = 4;
      goto LABEL_23;
    }
    goto LABEL_13;
  }
  v25 = (_QWORD *)cm_ctx_fl;
  if ( (*(_BYTE *)(a1 + 20) & 0x38) == 0x28 )
    result = cm_sm_deliver_event(*(_QWORD *)(a1 + 32), 15, 4, a1 + 4);
  else
    result = wlan_sm_dispatch(*(_QWORD *)(cm_ctx_fl + 72), 0xFu, 4u, a1 + 4, v14, v15, v16, v17, v18, v19, v20, v21);
  if ( (_DWORD)result )
  {
    v35 = result;
    v36 = *(_DWORD *)(a1 + 4);
    v40 = 0;
    v41 = 0;
    v38 = 0;
    v39 = 0;
    v37 = 0;
    qdf_mem_set(&v37, 0x28u, 0);
    if ( !(unsigned int)cm_fill_disconnect_resp_from_cm_id(v25, v36, &v37) )
      cm_disconnect_complete(v25, (unsigned int *)&v37);
    result = v35;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
