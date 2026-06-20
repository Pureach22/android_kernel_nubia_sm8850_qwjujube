__int64 __fastcall send_pdev_param_cmd_tlv(
        __int64 a1,
        unsigned int *a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w21
  __int64 v15; // x0
  _DWORD *v16; // x24
  __int64 v17; // x19
  __int64 v18; // x8
  _DWORD *v19; // x8
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 result; // x0
  unsigned int v38; // w20

  v11 = *a2;
  if ( *a2 )
  {
    v15 = wmi_buf_alloc_fl(a1, 0x10u, "send_pdev_param_cmd_tlv", 0xAC2u);
    if ( v15 )
    {
      v16 = *(_DWORD **)(v15 + 224);
      v17 = v15;
      *v16 = 5373964;
      v18 = 3680;
      if ( *((_BYTE *)a2 + 8) )
        v18 = 3720;
      v19 = *(_DWORD **)(*(_QWORD *)(a1 + 728) + v18);
      if ( *(v19 - 1) != -2112860426 )
        __break(0x8228u);
      v20 = ((__int64 (__fastcall *)(__int64, _QWORD))v19)(a1, a3);
      v16[1] = v20;
      v16[2] = v11;
      v16[3] = a2[1];
      qdf_trace_msg(0x31u, 8u, "Set pdev %d param 0x%x to %u", v21, v22, v23, v24, v25, v26, v27, v28, v20, v11);
      qdf_mtrace(49, 100, 0x203u, 0xFFu, 0);
      result = wmi_unified_cmd_send_fl(
                 a1,
                 v17,
                 0x10u,
                 0x4003u,
                 "send_pdev_param_cmd_tlv",
                 0xAD9u,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 v35,
                 v36);
      if ( (_DWORD)result )
      {
        v38 = result;
        wmi_buf_free();
        return v38;
      }
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(0x31u, 2u, "%s: Unavailable param %d", a4, a5, a6, a7, a8, a9, a10, a11, "send_pdev_param_cmd_tlv", 0);
    return 4;
  }
  return result;
}
