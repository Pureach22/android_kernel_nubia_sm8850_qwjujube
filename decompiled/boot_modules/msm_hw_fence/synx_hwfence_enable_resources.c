__int64 __fastcall synx_hwfence_enable_resources(unsigned int a1, int a2, char a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  __int64 v7; // x20
  unsigned int hw_fence_client_id; // w0
  __int64 v10; // x0
  unsigned int v12; // w19

  if ( hw_fence_driver_enable != 1 )
    return 4294967274LL;
  v6 = hw_fence_drv_data;
  if ( !hw_fence_drv_data
    || (unsigned __int64)hw_fence_drv_data > 0xFFFFFFFFFFFFF000LL
    || (*(_BYTE *)(hw_fence_drv_data + 8) & 1) == 0 )
  {
    printk(&unk_217EB, "synx_hwfence_enable_resources", 725, v5, a5);
    return 4294967274LL;
  }
  if ( a1 - 1024 > 0xBFF || a2 != 1 )
  {
    printk(&unk_21BE2, "synx_hwfence_enable_resources", 731, v5, a1);
    return 4294967274LL;
  }
  if ( *(_BYTE *)(hw_fence_drv_data + 33520) != 1 )
    return 0;
  v7 = v5;
  hw_fence_client_id = get_hw_fence_client_id(a1);
  v10 = hw_fence_utils_set_power_vote(v6, hw_fence_client_id, a3 & 1);
  if ( (_DWORD)v10 )
  {
    v12 = v10;
    printk(&unk_25800, "synx_hwfence_enable_resources", 740, v7, a3 & 1);
    v10 = v12;
  }
  return hw_fence_interop_to_synx_status(v10);
}
