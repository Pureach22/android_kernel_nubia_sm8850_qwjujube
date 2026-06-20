__int64 __fastcall target_if_vdev_peer_set_param_send(
        __int64 a1,
        __int64 a2,
        int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  __int64 *v13; // x8
  __int64 v14; // x19
  __int64 v19; // x1
  const char *v20; // x2
  const char *v21; // x2
  __int64 result; // x0
  int v23; // w8
  __int64 v24; // [xsp+8h] [xbp-18h] BYREF
  int v25; // [xsp+10h] [xbp-10h]
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v24 = 0;
  if ( !a1 || !a2 )
  {
    v20 = "%s: invalid input";
LABEL_12:
    qdf_trace_msg(0x68u, 2u, v20, a5, a6, a7, a8, a9, a10, a11, a12, "target_if_vdev_peer_set_param_send");
    result = 4;
    goto LABEL_13;
  }
  v12 = *(_QWORD *)(a1 + 216);
  if ( !v12 )
  {
    v21 = "%s: PDEV is NULL";
    goto LABEL_11;
  }
  v13 = *(__int64 **)(v12 + 1240);
  if ( !v13 || (v14 = *v13) == 0 )
  {
    v21 = "%s: wmi_handle is null";
LABEL_11:
    qdf_trace_msg(0x68u, 2u, v21, a5, a6, a7, a8, a9, a10, a11, a12, "target_if_vdev_mgr_wmi_handle_get");
    v20 = "%s: Failed to get WMI handle!";
    goto LABEL_12;
  }
  qdf_mem_set(&v24, 0xCu, 0);
  if ( a3 )
  {
    v19 = a2;
    LODWORD(v24) = a3;
  }
  else
  {
    v19 = a2;
    LODWORD(v24) = 39;
    if ( (unsigned __int8)(a4 - 1) > 6u )
      a4 &= 0xFFFFFF00;
    else
      a4 = dword_AD0790[(unsigned __int8)(a4 - 1)] | a4 & 0xFFFFFF00;
  }
  v23 = *(unsigned __int8 *)(a1 + 168);
  HIDWORD(v24) = a4;
  v25 = v23;
  result = wmi_set_peer_param_send(v14, v19, &v24);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
