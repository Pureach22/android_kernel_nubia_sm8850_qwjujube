__int64 __fastcall synx_hwfence_signal_n_indv(unsigned int *a1, unsigned __int16 *a2)
{
  __int64 v2; // x30
  unsigned int v5; // w0
  __int64 v6; // x23
  unsigned int v7; // w0
  unsigned __int64 v8; // x21
  unsigned int v9; // w22
  char v10; // w23
  __int64 v11; // x0
  unsigned int updated; // w0
  __int64 v13; // x22
  unsigned int txq_tw_wm_value; // w0
  __int64 v16; // x4
  unsigned int v17; // w19
  __int64 v18; // x4
  unsigned int v19; // w19

  if ( a1
    && (unsigned __int64)a1 <= 0xFFFFFFFFFFFFF000LL
    && *a1 - 1024 <= 0xBFF
    && *((_QWORD *)a1 + 1)
    && (*(_DWORD *)a2 & 0x80000000) != 0
    && ((v5 = *((_DWORD *)a2 + 2), v5 == 2) || v5 == 4 || v5 > 0x40) )
  {
    v6 = v2;
    v7 = hw_fence_interop_to_hw_fence_error();
    v8 = *a2;
    v9 = v7;
    if ( (*a1 & 0xFFFFFFC0) == 0x940 || *a1 - 2944 < 0x100 || (*((_DWORD *)a2 + 1) & 1) != 0 )
    {
      updated = hw_fence_update_txq_with_client_data(*((_QWORD *)a1 + 1), *a2, 0, v7, *((_QWORD *)a2 + 2));
      if ( updated )
      {
        v16 = *a1;
        v17 = updated;
        printk(&unk_21C46, "synx_hwfence_signal_n_indv", 310, v6, v16);
        v11 = v17;
      }
      else
      {
        v13 = *((_QWORD *)a1 + 1);
        txq_tw_wm_value = hw_fence_get_txq_tw_wm_value(hw_fence_drv_data, v13, *((_DWORD **)a2 + 3));
        if ( txq_tw_wm_value )
        {
          v18 = *a1;
          v19 = txq_tw_wm_value;
          printk(&unk_2648C, "synx_hwfence_signal_n_indv", 318, v6, v18);
          v11 = v19;
        }
        else
        {
          if ( (a2[2] & 1) == 0 )
            hw_fence_ipcc_trigger_signal(
              hw_fence_drv_data,
              *(_DWORD *)(v13 + 172),
              *(_DWORD *)(hw_fence_drv_data + 636),
              *(_DWORD *)(v13 + 164));
          v11 = 0;
        }
      }
    }
    else
    {
      v10 = hw_fence_get_txq_skip_wr_idx(hw_fence_drv_data, *((_QWORD *)a1 + 1)) ^ 1;
      if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
        printk(&unk_2944B, "synx_hwfence_signal_n_indv", 301, *a1, (unsigned int)v8);
      v11 = hw_fence_signal_fence(hw_fence_drv_data, 0, v8, v9, v10 & 1);
    }
    return hw_fence_interop_to_synx_status(v11);
  }
  else
  {
    printk(&unk_27D41, "synx_hwfence_signal_n_indv", 284, v2, a1);
    return 4294967274LL;
  }
}
