__int64 __fastcall osif_twt_check_and_set_wfd_mode(
        __int64 result,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  _BYTE v23[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23[0] = 0;
  if ( !a2 )
  {
    v22 = "%s: vdev is null";
LABEL_11:
    result = qdf_trace_msg(0x48u, 2u, v22, a4, a5, a6, a7, a8, a9, a10, a11, "osif_twt_check_and_set_wfd_mode");
    goto LABEL_12;
  }
  if ( *(_DWORD *)(a2 + 20) != 3 )
    goto LABEL_12;
  v11 = *(_QWORD *)(result + 80);
  if ( !v11 )
  {
    v22 = "%s: psoc is null";
    goto LABEL_11;
  }
  if ( (unsigned int)(*(_DWORD *)(a2 + 16) - 4) >= 0xFFFFFFFE )
  {
    result = ucfg_twt_tgt_caps_get_p2p_go_concurrency_support(
               *(_QWORD *)(result + 80),
               v23,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11);
    if ( !(_DWORD)result && v23[0] == 1 )
    {
      result = wlan_vdev_p2p_is_wfd_r2_mode(v11, *(unsigned __int8 *)(a2 + 168), v14, v15, v16, v17, v18, v19, v20, v21);
      if ( (result & 1) != 0 )
        *(_BYTE *)(a3 + 8) = 1;
    }
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
