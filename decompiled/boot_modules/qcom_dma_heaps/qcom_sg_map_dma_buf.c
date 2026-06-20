__int64 __fastcall qcom_sg_map_dma_buf(_QWORD *a1, unsigned int a2)
{
  __int64 v2; // x21
  __int64 v3; // x25
  __int64 v6; // x24
  __int64 (__fastcall *v7)(); // x8
  __int64 v8; // x19
  __int64 v9; // x20
  __int64 v10; // x0
  __int64 v11; // x1
  int v12; // w0
  __int64 v13; // x0
  int v14; // w0

  v3 = a1[8];
  v2 = a1[9];
  v6 = *(_QWORD *)(*a1 + 112LL);
  v7 = smmu_proxy_callback_ops_0[0];
  v8 = *(_QWORD *)(v3 + 8);
  v9 = *(_QWORD *)(v6 + 120);
  if ( !smmu_proxy_callback_ops_0[0] || (v2 & 0x40000) == 0 )
  {
    mutex_lock(v6 + 24);
    mem_buf_vmperm_pin(v9);
    if ( (*(_BYTE *)(v6 + 112) & 1) != 0 || (mem_buf_vmperm_can_cmo(v9) & 1) == 0 )
      v2 |= 0x20uLL;
    if ( (v2 & 0x20000) != 0 )
    {
      v14 = msm_dma_map_sg_attrs(a1[1], *(_QWORD *)v8, *(unsigned int *)(v8 + 12), a2, *a1, v2);
      if ( (v14 & 0x80000000) == 0 )
      {
        if ( v14 )
        {
          *(_DWORD *)(v8 + 8) = v14;
LABEL_18:
          *(_BYTE *)(v3 + 32) = 1;
LABEL_21:
          mutex_unlock(v6 + 24);
          return v8;
        }
        v14 = -22;
      }
    }
    else
    {
      v13 = a1[1];
      if ( *(_BYTE *)(v3 + 32) == 1 )
      {
        dev_err(v13, "Error: Dma-buf is already mapped!\n");
        v14 = -16;
      }
      else
      {
        v14 = dma_map_sgtable(v13, v8, a2, v2);
        if ( !v14 )
          goto LABEL_18;
      }
    }
    v8 = v14;
    mem_buf_vmperm_unpin(v9);
    goto LABEL_21;
  }
  v10 = a1[1];
  v11 = *(_QWORD *)(v3 + 8);
  if ( *((_DWORD *)smmu_proxy_callback_ops_0[0] - 1) != 1208565790 )
    __break(0x8228u);
  v12 = ((__int64 (__fastcall *)(__int64, __int64))v7)(v10, v11);
  if ( v12 )
    return v12;
  return v8;
}
