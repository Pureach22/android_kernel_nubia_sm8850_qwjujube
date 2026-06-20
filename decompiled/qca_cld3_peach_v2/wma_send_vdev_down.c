__int64 __fastcall wma_send_vdev_down(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  unsigned int v11; // w20
  __int64 *v14; // x22
  unsigned int vdev_stop_type; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w20
  __int64 result; // x0
  unsigned int v26; // w0
  unsigned int v27; // w21
  int v28; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 520);
  v11 = *(unsigned __int8 *)(a2 + 4);
  v28 = 0;
  if ( a2 )
  {
    v14 = (__int64 *)(v10 + 488LL * v11);
    vdev_stop_type = mlme_get_vdev_stop_type(*v14, &v28, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( vdev_stop_type )
    {
      v24 = vdev_stop_type;
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to get vdev stop type",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wma_send_vdev_down");
      _qdf_mem_free(a2);
      result = v24;
    }
    else
    {
      if ( v28 == 4174 || (v26 = wma_send_vdev_down_to_fw(a1, v11)) == 0 )
      {
        v27 = 0;
      }
      else
      {
        v27 = v26;
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Failed to send vdev down cmd: vdev %d",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "wma_send_vdev_down",
          v11);
      }
      wlan_vdev_mlme_sm_deliver_evt(*v14, 0x1Bu, 8u, a2, v16, v17, v18, v19, v20, v21, v22, v23);
      result = v27;
    }
  }
  else
  {
    qdf_trace_msg(0x36u, 2u, "%s: resp is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wma_send_vdev_down");
    result = 29;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
