__int64 __fastcall target_if_send_vdev_spectral_enable_cmd(
        __int64 *a1,
        unsigned int a2,
        char a3,
        char a4,
        char a5,
        char a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v14; // x22
  __int64 v15; // x8
  __int64 v16; // x9
  __int64 (__fastcall *v17)(_QWORD); // x9
  __int64 v19; // x0
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x20
  _QWORD *vdev; // x0
  __int64 v36; // x21
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 *v45; // x9
  __int64 (__fastcall *v46)(__int64, __int64 *); // x8
  __int64 v47; // x0
  const char *v48; // x2
  unsigned int v49; // w0
  __int64 result; // x0
  __int64 v51; // [xsp+0h] [xbp-10h] BYREF
  __int64 v52; // [xsp+8h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v51) = 0;
  LODWORD(v51) = 0;
  if ( !a1 )
  {
    v48 = "%s: spectral is null";
LABEL_13:
    qdf_trace_msg(
      0x56u,
      2u,
      v48,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "target_if_send_vdev_spectral_enable_cmd",
      v51,
      v52);
    v49 = 29;
LABEL_14:
    result = qdf_status_to_os_return(v49);
    goto LABEL_15;
  }
  v14 = *a1;
  if ( !*a1 )
  {
    v48 = "%s: pdev is null";
    goto LABEL_13;
  }
  v15 = *(_QWORD *)(v14 + 80);
  if ( !v15 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: psoc is null",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "target_if_send_vdev_spectral_enable_cmd",
      v51,
      v52);
    v49 = 4;
    goto LABEL_14;
  }
  v16 = *(_QWORD *)(v15 + 2136);
  if ( !v16 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: rx_ops is null",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "get_target_if_spectral_handle_from_psoc",
      v51,
      v52);
LABEL_18:
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: psoc spectral object is null",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "target_if_send_vdev_spectral_enable_cmd",
      v51);
    v49 = 16;
    goto LABEL_14;
  }
  v17 = *(__int64 (__fastcall **)(_QWORD))(v16 + 264);
  v19 = *(_QWORD *)(v14 + 80);
  if ( *((_DWORD *)v17 - 1) != -373219892 )
    __break(0x8229u);
  v25 = v17(v19);
  if ( !v25 )
    goto LABEL_18;
  v34 = v25;
  vdev = target_if_spectral_get_vdev(a1, a2, v26, v27, v28, v29, v30, v31, v32, v33);
  if ( vdev )
  {
    v36 = (__int64)vdev;
    qdf_mem_set(&v51, 6u, 0);
    LOBYTE(v51) = *(_BYTE *)(v36 + 168);
    wlan_objmgr_vdev_release_ref(
      v36,
      0x1Bu,
      (unsigned int *)(unsigned __int8)v51,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44);
    v45 = *(__int64 **)(v14 + 1240);
    v46 = *(__int64 (__fastcall **)(__int64, __int64 *))(v34 + 16);
    BYTE1(v51) = a3;
    BYTE3(v51) = a5;
    BYTE2(v51) = a4;
    BYTE4(v51) = a6;
    BYTE5(v51) = a2;
    if ( v45 )
      v47 = *v45;
    else
      v47 = 0;
    if ( *((_DWORD *)v46 - 1) != 1732079038 )
      __break(0x8228u);
    result = v46(v47, &v51);
  }
  else
  {
    result = 17;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
