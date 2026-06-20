__int64 __fastcall hdd_find_adapter_for_nan_oui_frames(_QWORD *a1, unsigned int a2, unsigned __int8 *a3, char a4)
{
  __int64 result; // x0
  const void *v6; // x19
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  const void *fw_addr; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x19
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7

  result = 0;
  if ( a2 < 0x20 || a4 != 13 )
    return result;
  if ( a3[26] != 80 || a3[27] != 111 || a3[28] != 154 || a3[29] != 19 )
    return 0;
  v6 = a3 + 4;
  if ( !(unsigned int)qdf_mem_cmp(a3 + 4, &unk_ABA91A, 4u) )
  {
    if ( a1[1061] )
    {
      if ( v6 )
      {
        v25 = a1[1061];
        goto LABEL_16;
      }
      v25 = a1[1061];
LABEL_22:
      v28 = 0;
      v26 = 0;
      v27 = 0;
      v29 = 0;
      goto LABEL_23;
    }
    return 0;
  }
  fw_addr = (const void *)ucfg_nan_get_fw_addr(*a1);
  if ( !fw_addr )
  {
    qdf_trace_msg(0x33u, 2u, "%s: NAN addr is null", v17, v18, v19, v20, v21, v22, v23, v24, "hdd_compare_nan_address");
    return 0;
  }
  if ( (unsigned int)qdf_mem_cmp(v6, fw_addr, 6u) )
    return 0;
  result = hdd_get_adapter((__int64)a1, 16);
  if ( result )
  {
    if ( v6 )
    {
      v25 = result;
LABEL_16:
      v26 = a3[4];
      v27 = a3[5];
      v28 = a3[6];
      v29 = a3[9];
LABEL_23:
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: USD adapter found for dest_addr:%02x:%02x:%02x:**:**:%02x",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "hdd_find_adapter_for_nan_oui_frames",
        v26,
        v27,
        v28,
        v29);
      return v25;
    }
    v25 = result;
    goto LABEL_22;
  }
  return result;
}
