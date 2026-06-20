__int64 __fastcall qcom_ddump_remove(__int64 a1)
{
  __int64 *v1; // x19
  __int64 result; // x0
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 v6; // x0
  _WORD v7[2]; // [xsp+0h] [xbp-10h] BYREF
  unsigned __int16 v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(__int64 **)(a1 + 168);
  v8 = 0;
  v7[0] = 0;
  gh_dbl_tx_unregister(v1[26]);
  gh_dbl_rx_unregister(v1[27]);
  if ( *((_BYTE *)v1 + 180) == 1 )
  {
    remove_proc_entry("vmkmsg", 0);
  }
  else
  {
    gh_panic_notifier_unregister(v1 + 33);
    wakeup_source_unregister(v1[32]);
  }
  if ( *((_BYTE *)v1 + 180) == 1 )
  {
    gunyah_qtvm_unregister_notifier(v1 + 23);
    result = ghd_rm_get_vmid(*((unsigned int *)v1 + 43), &v8);
    if ( !(_DWORD)result )
    {
      result = ghd_rm_get_vmid(1, v7);
      if ( !(_DWORD)result )
      {
        result = qcom_ddump_unshare_mem(v1, v7[0], v8);
        if ( !(_DWORD)result && (v1[42] & 1) == 0 )
        {
          v3 = *v1;
          v5 = v1[19];
          v4 = v1[20];
          v6 = phys_to_dma(*v1, v1[7]);
          result = dma_free_attrs(v3, v4, v5, v6, 0);
        }
      }
    }
  }
  else
  {
    result = kmsg_dump_unregister(v1 + 1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
