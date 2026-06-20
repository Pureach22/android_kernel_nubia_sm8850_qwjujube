__int64 __fastcall send_set_rap_ps_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  __int64 v2; // x23
  __int64 v5; // x0
  _DWORD *v6; // x24
  __int64 v7; // x19
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x8
  _DWORD *v18; // x10
  unsigned __int8 *v19; // x11
  _DWORD *v20; // x13
  int v21; // w14
  __int64 result; // x0

  v2 = *((unsigned int *)a2 + 1);
  v5 = wmi_buf_alloc_fl(a1, 12 * (int)v2 + 20, "send_set_rap_ps_cmd_tlv", 0x54u);
  if ( !v5 )
    return 16;
  v6 = *(_DWORD **)(v5 + 224);
  v7 = v5;
  *v6 = 51970060;
  v8 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3664LL);
  if ( *((_DWORD *)v8 - 1) != -2112860426 )
    __break(0x8228u);
  v6[1] = v8(a1, 255);
  v6[2] = 1;
  v6[3] = *a2;
  v6[4] = (unsigned __int16)(12 * v2) | 0x120000;
  if ( !(_DWORD)v2 )
  {
LABEL_8:
    result = wmi_unified_cmd_send_fl(
               a1,
               v7,
               12 * (int)v2 + 20,
               0x4037u,
               "send_set_rap_ps_cmd_tlv",
               0x7Bu,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16);
    if ( !(_DWORD)result )
      return result;
    wmi_buf_free();
    return 16;
  }
  v17 = 0;
  v18 = v6 + 5;
  v19 = a2 + 13;
  while ( 1 )
  {
    v20 = &v18[v17];
    v18[v17] = 52035592;
    if ( v17 == 60 )
      break;
    v17 += 3;
    v20[1] = *(_DWORD *)(v19 - 5);
    v21 = *(unsigned __int16 *)(v19 - 1);
    v19 += 6;
    v20[2] = v21;
    if ( 3 * v2 == v17 )
      goto LABEL_8;
  }
  __break(0x5512u);
  return wlan_interop_issues_ap_psoc_enable();
}
