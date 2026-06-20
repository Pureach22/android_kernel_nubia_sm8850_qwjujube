__int64 __fastcall send_multiple_vdev_param_cmd_tlv(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  __int64 v21; // x22
  unsigned __int64 v22; // x23
  unsigned int *v23; // x8
  unsigned int v24; // w9
  unsigned int v25; // w21
  _DWORD v26[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (wmi_service_enabled(a1, 0x11Eu, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
  {
    result = send_multi_pdev_vdev_set_param_cmd_tlv(a1, a2);
  }
  else if ( *(_BYTE *)(a2 + 6) )
  {
    v21 = 0;
    v22 = 0;
    while ( 1 )
    {
      v23 = (unsigned int *)(*(_QWORD *)(a2 + 8) + v21);
      v25 = *v23;
      v24 = v23[1];
      LODWORD(v23) = *(unsigned __int8 *)(a2 + 5);
      v26[1] = v25;
      v26[2] = v24;
      v26[0] = (_DWORD)v23;
      if ( (unsigned int)send_vdev_set_param_cmd_tlv(a1, v26, v12, v13, v14, v15, v16, v17, v18, v19) )
        break;
      ++v22;
      v21 += 8;
      if ( v22 >= *(unsigned __int8 *)(a2 + 6) )
        goto LABEL_7;
    }
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: failed to send param:%d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "send_multi_param_cmd_using_vdev_param_tlv",
      v25);
    result = 16;
  }
  else
  {
LABEL_7:
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
