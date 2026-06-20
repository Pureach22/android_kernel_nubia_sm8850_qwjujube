__int64 __fastcall send_multiple_pdev_param_cmd_tlv(
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
  __int64 v21; // x8
  __int64 v22; // x22
  __int64 v23; // x23
  unsigned __int8 v24; // w2
  unsigned int *v25; // x8
  unsigned int v26; // w21
  unsigned int v27[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v28; // [xsp+18h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (wmi_service_enabled(a1, 0x11Au, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
  {
    result = send_multi_pdev_vdev_set_param_cmd_tlv(a1, a2);
  }
  else
  {
    v21 = *(unsigned __int8 *)(a2 + 6);
    v27[2] = *(unsigned __int8 *)(a2 + 4) != 0;
    if ( v21 )
    {
      v22 = 8 * v21;
      v23 = 0;
      while ( 1 )
      {
        v24 = *(_BYTE *)(a2 + 5);
        v25 = (unsigned int *)(*(_QWORD *)(a2 + 8) + v23);
        v26 = *v25;
        LODWORD(v25) = v25[1];
        v27[0] = v26;
        v27[1] = (unsigned int)v25;
        if ( (unsigned int)send_pdev_param_cmd_tlv(a1, v27, v24, v12, v13, v14, v15, v16, v17, v18, v19) )
          break;
        v23 += 8;
        if ( v22 == v23 )
          goto LABEL_7;
      }
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: failed to send pdev setparam:%d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "send_multi_param_cmd_using_pdev_set_param_tlv",
        v26);
      result = 16;
    }
    else
    {
LABEL_7:
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
