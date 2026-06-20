_QWORD *__fastcall target_if_spectral_get_current_channel(
        __int64 *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v20; // x19
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 (*v23)(void); // x8
  __int16 v24; // w0
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w20
  const char *v35; // x2

  if ( !a1 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Null argument.",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_spectral_get_current_channel");
    return nullptr;
  }
  if ( a2 < 2 )
  {
    result = target_if_spectral_get_vdev(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( !result )
      return result;
    v19 = result[27];
    v20 = (__int64)result;
    if ( v19 && (v21 = *(_QWORD *)(v19 + 80)) != 0 )
    {
      v22 = *(_QWORD *)(v21 + 2136);
      if ( v22 )
      {
        v23 = *(__int64 (**)(void))(v22 + 272);
        if ( *((_DWORD *)v23 - 1) != -810236724 )
          __break(0x8228u);
        v24 = v23();
        if ( (v24 & 0x8000) == 0 )
        {
          v34 = v24;
          wlan_objmgr_vdev_release_ref(v20, 0x1Bu, v25, v26, v27, v28, v29, v30, v31, v32, v33);
          return (_QWORD *)v34;
        }
        goto LABEL_15;
      }
      v35 = "%s: rx_ops is null";
    }
    else
    {
      v35 = "%s: psoc is NULL";
    }
    qdf_trace_msg(0x56u, 2u, v35, v11, v12, v13, v14, v15, v16, v17, v18, "target_if_vdev_get_chan_freq");
LABEL_15:
    wlan_objmgr_vdev_release_ref(v20, 0x1Bu, v25, v26, v27, v28, v29, v30, v31, v32, v33);
    return nullptr;
  }
  qdf_trace_msg(
    0x56u,
    2u,
    "%s: Invalid Spectral mode %u",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "target_if_spectral_get_current_channel",
    a2);
  return nullptr;
}
