__int64 __fastcall hif_open(__int64 a1, __int64 a2, unsigned int a3, int a4, __int64 a5)
{
  int v9; // w23
  int context_size; // w0
  __int64 v11; // x0
  __int64 v12; // x19
  __int64 values; // x0
  __int64 v14; // x9
  int v15; // w0
  int v16; // w4
  char v17; // w9
  int v18; // w8
  unsigned __int64 v19; // x9
  unsigned __int64 v20; // x20
  _QWORD v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v9 = a2;
  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context_size = hif_bus_get_context_size(a3, a2);
  if ( context_size )
  {
    v11 = _qdf_mem_malloc(context_size, "hif_open", 1315);
    v12 = v11;
    if ( v11 )
    {
      *(_QWORD *)(v11 + 576) = a1;
      *(_DWORD *)(v11 + 2552) = v9;
      *(_DWORD *)(v11 + 672) = 0;
      *(_DWORD *)(v11 + 680) = 0;
      *(_DWORD *)(v11 + 676) = 0;
      *(_DWORD *)(v11 + 684) = 0;
      *(_DWORD *)(v11 + 720) = 0;
      *(_DWORD *)(v11 + 4008) = 0;
      qdf_mem_copy(v11 + 2464, a4, 0x58u);
      *(_DWORD *)(v12 + 72) = a3;
      if ( a5 )
      {
        values = cfg_psoc_get_values(a5);
        v14 = *(_QWORD *)(v12 + 576);
        *(_BYTE *)(v12 + 3951) = *(_BYTE *)(values + 800);
        if ( (pld_is_one_msi(*(_QWORD *)(v14 + 40)) & 1) != 0 )
        {
          qdf_trace_msg(61, 8, "%s: Disable wake IRQ once it is one MSI mode", "hif_get_cfg_from_psoc");
          *(_BYTE *)(v12 + 3951) = 1;
        }
        *(_WORD *)(v12 + 3948) = *(_DWORD *)(cfg_psoc_get_values(a5) + 792);
        *(_BYTE *)(v12 + 3950) = *(_DWORD *)(cfg_psoc_get_values(a5) + 796);
      }
      *(_QWORD *)(v12 + 608) = 255;
      v15 = hif_bus_open((_QWORD *)v12, a3);
      if ( v15 )
      {
        qdf_trace_msg(61, 2, "%s: hif_bus_open error = %d, bus_type = %d", "hif_open", v15, a3);
        _qdf_mem_free(v12);
        v12 = 0;
      }
      else
      {
        _qdf_runtime_lock_init(v12 + 4000, "&scn->prevent_linkdown_lock");
        v22[0] = 0;
        v16 = *(unsigned __int8 *)(cfg_psoc_get_values(a5) + 801);
        *(_BYTE *)(v12 + 4196) = v16;
        qdf_trace_msg(61, 5, "%s: Affinity Manager supported: %d", "hif_affinity_mgr_init", v16);
        if ( *(_BYTE *)(v12 + 4196) == 1 )
        {
          v17 = 0;
          *(_QWORD *)(v12 + 4200) = 5000000;
          v18 = _cpu_possible_mask;
          do
          {
            v19 = v18 & (unsigned int)(-1LL << v17);
            if ( !(_DWORD)v19 )
              break;
            v20 = __clz(__rbit64(v19));
            if ( !cpu_topology[12 * (unsigned int)v20 + 2] )
            {
              qdf_cpumask_set_cpu((unsigned int)v20, v22);
              v18 = _cpu_possible_mask;
            }
            v17 = v20 + 1;
          }
          while ( v20 < 0x1F );
          qdf_cpumask_copy(v12 + 26384, v22);
        }
        *(_DWORD *)(v12 + 26432) = -1;
        hif_ce_desc_history_log_register(v12);
        hif_desc_history_log_register();
        ((void (__fastcall *)(const char *, __int64, __int64))qdf_ssr_driver_dump_register_region)("hif", v12, 26440);
      }
    }
  }
  else
  {
    qdf_trace_msg(61, 2, "%s: context size 0 not allowed", "hif_open");
    v12 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v12;
}
