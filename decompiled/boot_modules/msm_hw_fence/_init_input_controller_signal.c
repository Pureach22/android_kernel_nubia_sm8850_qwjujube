__int64 __fastcall init_input_controller_signal(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4)
{
  __int64 v4; // x30
  __int64 result; // x0
  unsigned int v8; // w20
  __int64 v9; // x22
  __int64 v10; // x22
  unsigned int v11; // w23
  unsigned int client_id_priv; // w0
  unsigned int v13; // w20
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4
  int client_virt_id; // w23
  __int64 v18; // x30
  void *v19; // x0
  __int64 v20; // x2

  if ( (~msm_hw_fence_debug_level & 0x10001) != 0 )
  {
    if ( (*a3 & 1) != 0 )
      return 0;
  }
  else
  {
    v8 = a4;
    v9 = v4;
    printk(&unk_29CCE, "_init_input_controller_signal", 909, *(unsigned int *)(a2 + 4), (unsigned __int8)*a3);
    a4 = v8;
    v4 = v9;
    if ( (*a3 & 1) != 0 )
      return 0;
  }
  v10 = v4;
  v11 = a4;
  client_id_priv = hw_fence_utils_get_client_id_priv(a1, a4);
  if ( client_id_priv >= 0x681 )
  {
    printk(&unk_24471, "_init_input_controller_signal", 914, v10, v11);
    return 4294967274LL;
  }
  v13 = client_id_priv;
  client_virt_id = hw_fence_ipcc_get_client_virt_id(a1, client_id_priv);
  if ( client_virt_id != *(_DWORD *)(a1 + 628) && (unsigned int)hw_fence_ipcc_enable_protocol(a1, v13) )
  {
    v18 = v10;
    v19 = &unk_2B318;
    v20 = 925;
LABEL_15:
    printk(v19, "_init_input_controller_signal", v20, v18, v13);
    return 4294967274LL;
  }
  if ( client_virt_id != *(_DWORD *)(a1 + 636)
    && (unsigned int)hw_fence_ipcc_enable_client_signal_pairs(a1, v13, v14, v15, v16) )
  {
    v18 = v10;
    v19 = &unk_2AE66;
    v20 = 938;
    goto LABEL_15;
  }
  result = 0;
  *a3 = 1;
  return result;
}
