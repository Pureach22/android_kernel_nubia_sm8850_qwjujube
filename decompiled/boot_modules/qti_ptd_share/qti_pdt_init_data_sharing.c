__int64 __fastcall qti_pdt_init_data_sharing(__int64 a1)
{
  unsigned __int64 v2; // x20
  __int64 v3; // x0
  unsigned __int64 StatusReg; // x22
  __int64 v5; // x0
  __int64 v6; // x8
  char v7; // w9
  __int64 v9; // x0

  if ( a1 )
  {
    if ( (qcom_smem_is_available() & 1) != 0 )
    {
      LODWORD(v2) = qcom_smem_alloc(0xFFFFFFFFLL, 624, 4096);
      if ( !(_DWORD)v2 )
      {
        v2 = qcom_smem_get(0xFFFFFFFFLL, 624, 0);
        smem_buffer = v2;
        if ( v2 < 0xFFFFFFFFFFFFF001LL )
        {
          v3 = *(_QWORD *)(a1 + 16);
          if ( v3 )
          {
            StatusReg = _ReadStatusReg(SP_EL0);
            ipc_log_string(v3, "[%s] smem_buffer legend address=0x%lx\n", (const char *)(StatusReg + 2320), v2);
            v3 = *(_QWORD *)(a1 + 16);
            if ( v3 )
              v3 = ipc_log_string(
                     v3,
                     "[%s] smem_buffer data   address=0x%lx\n",
                     (const char *)(StatusReg + 2320),
                     smem_buffer + 2048);
          }
          LODWORD(v2) = qptm_available_node_count(v3);
          if ( (v2 & 0x80000000) != 0 )
          {
            v9 = *(_QWORD *)(a1 + 16);
            if ( v9 )
              ipc_log_string(
                v9,
                "[%s] unable to read number of voltage nodes: %d\n",
                (const char *)(_ReadStatusReg(SP_EL0) + 2320),
                v2);
          }
          else
          {
            v5 = *(_QWORD *)(a1 + 16);
            num_nodes = v2;
            if ( v5 )
              ipc_log_string(
                v5,
                "[%s] number of enabled voltage nodes=%d\n",
                (const char *)(_ReadStatusReg(SP_EL0) + 2320),
                (unsigned __int8)v2);
            mutex_lock(a1 + 48);
            __isb(0xFu);
            v2 = _ReadStatusReg(CNTVCT_EL0);
            v6 = smem_buffer;
            *(_BYTE *)smem_buffer = 1;
            v7 = num_nodes;
            *(_QWORD *)(v6 + 1) = v2;
            *(_BYTE *)(v6 + 9) = v7;
            smem_buffer = v6 + 10;
            qptm_for_each_node(qptm_share_node_info_cb, a1);
            *(_QWORD *)smem_buffer = v2;
            mutex_unlock(a1 + 48);
            LODWORD(v2) = 0;
          }
        }
      }
    }
    else
    {
      LODWORD(v2) = -19;
    }
  }
  else
  {
    LODWORD(v2) = -22;
  }
  return (unsigned int)v2;
}
