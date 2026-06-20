__int64 __fastcall dsi_hfi_append_panel_timing_caps(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x26
  unsigned int v7; // w22
  __int64 v8; // x25
  __int64 payload_addr; // x0
  unsigned int v10; // w25

  v3 = *(_QWORD *)(a2 + 1688);
  if ( v3 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(a2 + 264) + 1432LL) )
    {
      v7 = 0;
      do
      {
        hfi_util_kv_helper_reset(*(unsigned int **)(v3 + 16));
        v8 = a3 + 300LL * (int)v7;
        hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), 0x1040002u, v8);
        hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), 0x2040003u, v8 + 4);
        hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), 0x1040004u, v8 + 12);
        hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), 0x2040006u, v8 + 16);
        hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), 0xE040005u, v8 + 28);
        hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), 0xC040007u, v8 + 84);
        hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), 0x4040008u, v8 + 132);
        hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), 0x1040009u, v8 + 148);
        hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), 0x15040024u, v8 + 156);
        hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), 0xF040027u, v8 + 240);
        LODWORD(v8) = hfi_util_kv_helper_get_count(*(_QWORD *)(v3 + 16));
        payload_addr = hfi_util_kv_helper_get_payload_addr(*(_QWORD *)(v3 + 16));
        v10 = hfi_adapter_add_prop_array(a1, 0x3000002u, 0, 2u, payload_addr, v8, 4 * (int)v8 + 292);
        if ( v10 )
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: Failed to add caps for timing node:%d, rc = %d",
            v7,
            v10);
        ++v7;
      }
      while ( v7 < *(_DWORD *)(*(_QWORD *)(a2 + 264) + 1432LL) );
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return (unsigned int)-22;
  }
  return v10;
}
