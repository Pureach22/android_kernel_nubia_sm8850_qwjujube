__int64 __fastcall qcom_sg_unmap_dma_buf(_QWORD *a1, __int64 a2, unsigned int a3)
{
  __int64 v4; // x21
  __int64 v5; // x24
  __int64 (__fastcall *v6)(); // x8
  __int64 v7; // x23
  __int64 v9; // x20
  __int64 v10; // x0
  __int64 v13; // x0

  v5 = a1[8];
  v4 = a1[9];
  v6 = smmu_proxy_callback_ops_1[0];
  v7 = *(_QWORD *)(*a1 + 112LL);
  v9 = *(_QWORD *)(v7 + 120);
  if ( smmu_proxy_callback_ops_1[0] && (v4 & 0x40000) != 0 )
  {
    v10 = a1[1];
    if ( *((_DWORD *)smmu_proxy_callback_ops_1[0] - 1) != 2083810537 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64))v6)(v10);
  }
  else
  {
    mutex_lock(v7 + 24);
    if ( (*(_BYTE *)(v7 + 112) & 1) != 0 || (mem_buf_vmperm_can_cmo(v9) & 1) == 0 )
      v4 |= 0x20uLL;
    *(_BYTE *)(v5 + 32) = 0;
    v13 = a1[1];
    if ( (v4 & 0x20000) != 0 )
      msm_dma_unmap_sg_attrs(v13, *(_QWORD *)a2, *(unsigned int *)(a2 + 8), a3, *a1, v4);
    else
      dma_unmap_sg_attrs(v13, *(_QWORD *)a2, *(unsigned int *)(a2 + 12), a3, v4);
    mem_buf_vmperm_unpin(v9);
    return mutex_unlock(v7 + 24);
  }
}
