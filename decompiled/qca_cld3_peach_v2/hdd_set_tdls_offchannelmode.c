__int64 __fastcall hdd_set_tdls_offchannelmode(
        __int64 a1,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  unsigned int v24; // w1
  __int64 vdev_by_user; // x0
  __int64 v26; // x20
  unsigned int v27; // w19
  unsigned int *v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w0
  __int64 result; // x0
  _BYTE v39[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v40; // [xsp+8h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)a1;
  v39[0] = 0;
  if ( (unsigned int)cfg_tdls_get_off_channel_enable(v14, v39, a4, a5, a6, a7, a8, a9, a10, a11) )
  {
    v23 = "%s: cfg get tdls off ch failed";
    v24 = 2;
LABEL_8:
    qdf_trace_msg(0x33u, v24, v23, v15, v16, v17, v18, v19, v20, v21, v22, "hdd_set_tdls_offchannelmode");
LABEL_9:
    v37 = 16;
    goto LABEL_10;
  }
  if ( (v39[0] & 1) == 0 )
  {
    v23 = "%s: tdls off ch is false, do nothing";
    v24 = 8;
    goto LABEL_8;
  }
  if ( *(_BYTE *)(a1 + 1800) != 1 )
    goto LABEL_9;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a2 + 52832), 0x57u, (__int64)"hdd_set_tdls_offchannelmode");
  if ( !vdev_by_user )
    goto LABEL_9;
  v26 = vdev_by_user;
  v27 = ucfg_set_tdls_offchan_mode(vdev_by_user, a3);
  _hdd_objmgr_put_vdev_by_user(
    v26,
    0x57u,
    (__int64)"hdd_set_tdls_offchannelmode",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36);
  v37 = v27;
LABEL_10:
  result = qdf_status_to_os_return(v37);
  _ReadStatusReg(SP_EL0);
  return result;
}
