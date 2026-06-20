unsigned __int64 __fastcall qti_pdt_share_updated_data_cb(__int64 a1)
{
  __int64 v1; // x20
  unsigned __int64 result; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v5; // x8
  char v6; // w9
  __int64 v7; // x0
  __int64 v8; // x0

  v1 = a1 - 24;
  if ( a1 == 24 )
    return 4294967274LL;
  if ( (qcom_smem_is_available() & 1) == 0 )
    return 4294967277LL;
  result = qcom_smem_get(0xFFFFFFFFLL, 624, 0);
  smem_buffer = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    smem_buffer = result + 2048;
    mutex_lock(a1 + 24);
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    v5 = smem_buffer;
    *(_BYTE *)smem_buffer = 1;
    v6 = num_nodes;
    *(_QWORD *)(v5 + 1) = StatusReg;
    *(_BYTE *)(v5 + 9) = v6;
    smem_buffer = v5 + 10;
    v7 = *(_QWORD *)(a1 - 16);
    if ( v7 )
      ipc_log_string(
        v7,
        "[%s] node_id total_energy_uj     power_avg_uw\n",
        (const char *)(_ReadStatusReg(SP_EL0) + 2320));
    qptm_for_each_node(qptm_share_node_data_cb, v1);
    *(_QWORD *)smem_buffer = StatusReg;
    v8 = *(_QWORD *)(a1 - 8);
    if ( v8 )
      ipc_log_string(
        v8,
        "[%s] xo_tick=%lld (0x%llx)\n",
        (const char *)(_ReadStatusReg(SP_EL0) + 2320),
        StatusReg,
        StatusReg);
    mutex_unlock(a1 + 24);
    return 0;
  }
  return result;
}
