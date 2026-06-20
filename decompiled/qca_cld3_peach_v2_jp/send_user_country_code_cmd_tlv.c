__int64 __fastcall send_user_country_code_cmd_tlv(__int64 a1, unsigned __int8 a2, unsigned __int8 *a3)
{
  __int64 v6; // x0
  __int64 v7; // x23
  __int64 v8; // x19
  _DWORD *v9; // x8
  int v10; // w8
  int v11; // w8
  __int64 result; // x0
  int v13; // w8
  int v14; // w8
  int v15; // w8
  unsigned int v16; // w9
  unsigned int v17; // w10
  int v18; // w9
  int v19; // w9
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  v6 = wmi_buf_alloc_fl(a1, 0x10u, "send_user_country_code_cmd_tlv", 0x4AFBu);
  if ( !v6 )
    return 2;
  v7 = *(_QWORD *)(v6 + 224);
  v8 = v6;
  *(_DWORD *)v7 = 42401804;
  v9 = *(_DWORD **)(*(_QWORD *)(a1 + 728) + 3664LL);
  if ( *(v9 - 1) != -2112860426 )
    __break(0x8228u);
  *(_DWORD *)(v7 + 4) = ((__int64 (__fastcall *)(__int64, _QWORD))v9)(a1, a2);
  v10 = a3[4];
  switch ( v10 )
  {
    case 3:
      v15 = *(_DWORD *)(v7 + 12);
      v16 = v15 & 0xFFFFFF00;
      v17 = v15 & 0xFFFF0000;
      v15 &= 0xFF000000;
      *(_DWORD *)(v7 + 8) = 0;
      *(_DWORD *)(v7 + 12) = v16;
      v18 = *a3;
      *(_DWORD *)(v7 + 12) = v17 | v18;
      v19 = v18 | (a3[1] << 8);
      *(_DWORD *)(v7 + 12) = v19 | v15;
      v11 = v15 | (a3[2] << 16) | v19;
      break;
    case 2:
      v13 = *(unsigned __int16 *)(v7 + 14) << 16;
      *(_DWORD *)(v7 + 8) = 2;
      *(_DWORD *)(v7 + 12) = v13;
      v14 = *(unsigned __int16 *)a3;
      *(_DWORD *)(v7 + 12) = v14;
      v11 = v14 | (*((unsigned __int16 *)a3 + 1) << 16);
      break;
    case 1:
      *(_DWORD *)(v7 + 8) = 1;
      v11 = *(unsigned __int16 *)a3;
      break;
    default:
      goto LABEL_12;
  }
  *(_DWORD *)(v7 + 12) = v11;
LABEL_12:
  qdf_mtrace(49, 100, 0x1D04u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v8,
             0x10u,
             0x3A004u,
             "send_user_country_code_cmd_tlv",
             0x4B1Cu,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to config wow wakeup event",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "send_user_country_code_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
