__int64 __fastcall send_twt_enable_cmd_tlv(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _DWORD *v13; // x22
  __int64 v14; // x19
  __int64 v15; // x1
  __int64 (__fastcall *v16)(__int64, __int64); // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w8
  unsigned int v26; // w8
  unsigned int v27; // w8
  unsigned int v28; // w8
  int v29; // w8
  unsigned int v30; // w8
  unsigned int v31; // w8
  __int64 result; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w20

  v4 = wmi_buf_alloc_fl(a1, 0x4Cu, "send_twt_enable_cmd_tlv", 0x22u);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    v14 = v4;
    *v13 = 47513672;
    v15 = *a2;
    v16 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3664LL);
    if ( *((_DWORD *)v16 - 1) != -2112860426 )
      __break(0x8228u);
    v13[1] = v16(a1, v15);
    v25 = v13[18];
    v13[2] = a2[1];
    v13[3] = a2[2];
    v13[4] = a2[3];
    v13[5] = a2[4];
    v13[6] = a2[5];
    v13[7] = a2[6];
    v13[8] = a2[7];
    v13[9] = a2[8];
    v13[10] = a2[9];
    v13[11] = a2[10];
    v13[12] = a2[11];
    v13[13] = a2[12];
    v13[14] = a2[13];
    v13[15] = a2[14];
    v13[16] = a2[15];
    v13[17] = a2[16];
    v13[18] = v25 & 0xFFFFFFFE;
    v26 = v25 & 0xFFFFFFBE | *((_BYTE *)a2 + 77) & 1;
    v13[18] = v26;
    v27 = v26 & 0xFFFFFFFD | (*((unsigned __int8 *)a2 + 78) << 6);
    v13[18] = v27;
    v28 = v27 & 0xFFFFFFF9 | *((_BYTE *)a2 + 77) & 2;
    v13[18] = v28;
    v29 = v28 | *((_BYTE *)a2 + 77) & 4;
    v13[18] = v29;
    if ( *((_BYTE *)a2 + 76) == 1 )
    {
      v30 = v29 & 0xFFFFFFE7 | 8;
      v13[18] = v30;
      v31 = v30 & 0xFFFFFFCF | (16 * (a2[17] & 1));
      v13[18] = v31;
      v13[18] = v31 & 0xFFFFFFDF | (32 * (a2[18] & 1));
    }
    result = wmi_unified_cmd_send_fl(
               a1,
               v14,
               0x4Cu,
               0x3E001u,
               "send_twt_enable_cmd_tlv",
               0x51u,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24);
    if ( (_DWORD)result )
    {
      v41 = result;
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send WMI_TWT_ENABLE_CMDID",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "send_twt_enable_cmd_tlv");
      wmi_buf_free();
      return v41;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to allocate memory",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_twt_enable_cmd_tlv");
    return 16;
  }
  return result;
}
