__int64 __fastcall synx_hwfence_recover(unsigned int a1)
{
  __int64 v1; // x30
  __int64 v3; // x20
  unsigned int hw_fence_client_id; // w0
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 v7; // x4
  __int64 v8; // x0
  __int64 v10; // x30
  unsigned int v11; // w20

  v3 = v1;
  if ( a1 - 1024 >= 0xC00 )
  {
    printk(&unk_2B11D, "synx_hwfence_recover", 479, v1, a1);
    return 4294967274LL;
  }
  else
  {
    hw_fence_client_id = get_hw_fence_client_id(a1);
    v8 = msm_hw_fence_reset_client_by_id(hw_fence_client_id, 2, v5, v6, v7);
    if ( (_DWORD)v8 )
    {
      v10 = v3;
      v11 = v8;
      printk(&unk_29AAD, "synx_hwfence_recover", 486, v10, a1);
      v8 = v11;
    }
    return hw_fence_interop_to_synx_status(v8);
  }
}
