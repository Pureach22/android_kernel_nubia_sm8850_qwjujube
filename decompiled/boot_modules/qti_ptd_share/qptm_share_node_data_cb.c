__int64 __fastcall qptm_share_node_data_cb(__int64 a1, __int64 a2)
{
  unsigned int node_id; // w19
  unsigned int energy_in_uj; // w0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x5
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  const char *v12; // x1
  unsigned __int64 StatusReg; // x9
  __int64 v14; // x3
  __int64 v16; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v17[2]; // [xsp+10h] [xbp-10h] BYREF

  node_id = -22;
  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
    goto LABEL_19;
  v16 = 0;
  v17[0] = 0;
  node_id = qptm_get_node_id();
  if ( (node_id & 0x80000000) == 0 )
  {
    energy_in_uj = qptm_get_energy_in_uj(a1, v17);
    if ( (energy_in_uj & 0x80000000) != 0 )
    {
      v11 = *(_QWORD *)(a2 + 16);
      if ( v11 )
      {
        v12 = "[%s] unable to read total_energy_uj for node_id %d: %d\n";
        StatusReg = _ReadStatusReg(SP_EL0);
LABEL_17:
        v14 = (unsigned __int16)node_id;
        node_id = energy_in_uj;
        ipc_log_string(v11, v12, StatusReg + 2320, v14, energy_in_uj);
        goto LABEL_19;
      }
    }
    else
    {
      energy_in_uj = qptm_get_power_in_uw(a1, &v16);
      if ( (energy_in_uj & 0x80000000) == 0 )
      {
        v6 = smem_buffer;
        *(_WORD *)smem_buffer = node_id;
        v7 = *(_QWORD *)(a2 + 16);
        if ( v7 )
        {
          ipc_log_string(
            v7,
            "[%s] node_id=0x%x\n",
            (const char *)(_ReadStatusReg(SP_EL0) + 2320),
            (unsigned __int16)node_id);
          v6 = smem_buffer;
        }
        *(_QWORD *)(v6 + 2) = v17[0];
        v8 = v16;
        *(_QWORD *)(v6 + 10) = v16;
        v9 = *(_QWORD *)(a2 + 8);
        smem_buffer = v6 + 18;
        if ( v9 )
          ipc_log_string(
            v9,
            "[%s] 0x%04x, 0x%016llx, 0x%016llx\n",
            (const char *)(_ReadStatusReg(SP_EL0) + 2320),
            (unsigned __int16)node_id,
            v17[0],
            v8);
        node_id = 0;
        goto LABEL_19;
      }
      v11 = *(_QWORD *)(a2 + 16);
      if ( v11 )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        v12 = "[%s] unable to read power_avg_uw for node_id %d: %d\n";
        goto LABEL_17;
      }
    }
    node_id = energy_in_uj;
    goto LABEL_19;
  }
  v10 = *(_QWORD *)(a2 + 16);
  if ( v10 )
    ipc_log_string(v10, "[%s] unable to read node_id: %d\n", (const char *)(_ReadStatusReg(SP_EL0) + 2320), node_id);
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return node_id;
}
