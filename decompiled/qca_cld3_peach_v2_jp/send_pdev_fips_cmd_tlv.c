__int64 __fastcall send_pdev_fips_cmd_tlv(__int64 a1, __int64 a2)
{
  int v2; // w22
  __int64 result; // x0
  __int64 v6; // x0
  _DWORD *v7; // x23
  __int64 v8; // x20
  __int64 v9; // x1
  __int64 (__fastcall *v10)(__int64, __int64); // x8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w8
  __int64 v20; // x6
  size_t v21; // x2
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  v2 = *(_DWORD *)(a2 + 24);
  result = 4;
  if ( (v2 & 0xF) == 0 && (unsigned int)(v2 - 1) <= 0x676 )
  {
    v6 = wmi_buf_alloc_fl(a1, v2 + 60, "send_pdev_fips_cmd_tlv", 0x2E62u);
    if ( v6 )
    {
      v7 = *(_DWORD **)(v6 + 224);
      v8 = v6;
      *v7 = 29884468;
      v9 = *(unsigned int *)(a2 + 36);
      v10 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3664LL);
      if ( *((_DWORD *)v10 - 1) != -2112860426 )
        __break(0x8228u);
      v7[1] = v10(a1, v9);
      if ( *(_QWORD *)a2 && *(_QWORD *)(a2 + 16) )
      {
        v7[4] = *(_DWORD *)(a2 + 8);
        v7[13] = *(_DWORD *)(a2 + 24);
        v7[2] = *(_DWORD *)(a2 + 32) != 0;
        qdf_mem_copy(v7 + 5, *(const void **)a2, *(unsigned int *)(a2 + 8));
        v19 = *(_DWORD *)(a2 + 28);
        v20 = (unsigned int)v7[4];
        if ( v19 >= 2 )
          v19 = 0;
        v7[3] = v19;
        print_hex_dump(&unk_97927D, "Key: ", 0, 16, 1, v7 + 5, v20, 1);
        v7[14] = *(unsigned __int16 *)(a2 + 24) | 0x110000;
        v21 = *(unsigned int *)(a2 + 24);
        if ( (_DWORD)v21 )
          qdf_mem_copy(v7 + 15, *(const void **)(a2 + 16), v21);
        print_hex_dump(&unk_97927D, "Plain text: ", 0, 16, 1, v7 + 15, (unsigned int)v7[13], 1);
        qdf_mtrace(49, 100, 0x217u, 0xFFu, 0);
        return wmi_unified_cmd_send_fl(
                 a1,
                 v8,
                 v2 + 60,
                 0x4017u,
                 "send_pdev_fips_cmd_tlv",
                 0x2E93u,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29);
      }
      else
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: \n%s:%d Key or Data is NULL",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "send_pdev_fips_cmd_tlv",
          "send_pdev_fips_cmd_tlv",
          11925);
        wmi_buf_free();
        return 4294967289LL;
      }
    }
    else
    {
      return 16;
    }
  }
  return result;
}
