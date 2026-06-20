__int64 __fastcall hdd_set_btm_support_config(unsigned __int8 *a1, __int64 a2)
{
  __int64 *v4; // x23
  unsigned int v5; // w22
  char is_vdev_in_conn_state; // w0
  unsigned int v7; // w20
  char v8; // w21
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  unsigned __int8 v18; // w2

  v4 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  v5 = *(_DWORD *)(*(_QWORD *)a1 + 40LL);
  is_vdev_in_conn_state = hdd_is_vdev_in_conn_state(a1);
  v7 = *(unsigned __int8 *)(a2 + 4);
  v8 = is_vdev_in_conn_state;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev: %d, cfg_val: %d for op_mode: %d, conn_state:%d",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "hdd_set_btm_support_config",
    a1[8],
    v7,
    v5,
    is_vdev_in_conn_state & 1);
  result = 4294967274LL;
  if ( !v5 && (v8 & 1) == 0 )
  {
    if ( v7 == 1 )
    {
      v18 = 1;
    }
    else
    {
      if ( v7 )
        return result;
      v18 = 0;
    }
    wlan_cm_set_btm_config(*v4, a1[8], v18);
    return 0;
  }
  return result;
}
