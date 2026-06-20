__int64 __fastcall hdd_update_dp_vdev_flags(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _QWORD *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _QWORD *v25; // x22
  _QWORD *v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x8
  _DWORD *v36; // x8
  __int64 result; // x0
  __int64 v38; // [xsp+0h] [xbp-20h] BYREF
  char v39; // [xsp+8h] [xbp-18h]
  _BYTE v40[23]; // [xsp+9h] [xbp-17h]

  *(_QWORD *)&v40[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, (__int64)"hdd_update_dp_vdev_flags", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !a1 )
    goto LABEL_16;
  v25 = context;
  v26 = _cds_get_context(51, (__int64)"hdd_update_dp_vdev_flags", v17, v18, v19, v20, v21, v22, v23, v24);
  if ( !v26 )
  {
    result = 4;
    goto LABEL_17;
  }
  if ( *((_BYTE *)v26 + 1801) != 1 )
  {
LABEL_16:
    result = 0;
    goto LABEL_17;
  }
  if ( (_BYTE)a2 != 0xFF )
  {
    if ( v25 && *v25 )
    {
      v35 = *(_QWORD *)(*v25 + 8LL);
      if ( v35 && (v36 = *(_DWORD **)(v35 + 40)) != nullptr )
      {
        v39 = 0;
        v38 = a4 & 1;
        *(_QWORD *)v40 = 0;
        *(_QWORD *)&v40[7] = 0;
        if ( *(v36 - 1) != -96731432 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, _QWORD, _QWORD, __int64 *))v36)(v25, a2, a3, &v38);
      }
      else
      {
        qdf_trace_msg(0x89u, 8u, "NULL vdev params callback", v27, v28, v29, v30, v31, v32, v33, v34);
      }
    }
    else
    {
      qdf_trace_msg(
        0x89u,
        8u,
        "%s: Invalid Instance:",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "cdp_txrx_set_vdev_param");
    }
    goto LABEL_16;
  }
  result = 16;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
