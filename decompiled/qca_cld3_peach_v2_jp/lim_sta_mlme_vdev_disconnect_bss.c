__int64 __fastcall lim_sta_mlme_vdev_disconnect_bss(
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
        unsigned __int16 *a11)
{
  _QWORD *context; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD *v22; // x20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w5

  context = _cds_get_context(53, (__int64)"lim_sta_mlme_vdev_disconnect_bss", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v22 = context;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Vdev %d: disconnect bss callback type:(%d)",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "lim_sta_mlme_vdev_disconnect_bss",
      *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL),
      *a11);
    v31 = *a11;
    if ( v31 > 0x140B )
    {
      if ( v31 != 5146 )
      {
        if ( v31 != 5132 )
        {
LABEL_14:
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Vdev %d Wrong message type received %d",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "lim_sta_mlme_vdev_disconnect_bss",
            *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL));
          return 0;
        }
        _lim_process_sme_deauth_req(v22, *((_QWORD *)a11 + 1));
        return 0;
      }
    }
    else
    {
      if ( v31 == 5128 )
      {
        _lim_process_sme_disassoc_req(v22, *((_QWORD *)a11 + 1));
        return 0;
      }
      if ( v31 != 5131 )
        goto LABEL_14;
    }
    _lim_process_sme_disassoc_cnf(v22, *((_QWORD *)a11 + 1));
    return 0;
  }
  if ( a11 )
    _qdf_mem_free((__int64)a11);
  return 4;
}
