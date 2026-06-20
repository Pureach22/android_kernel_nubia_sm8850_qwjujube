__int64 __fastcall qrtr_gunyah_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  __int64 v3; // x0
  _WORD v4[2]; // [xsp+0h] [xbp-60h] BYREF
  unsigned __int16 v5; // [xsp+4h] [xbp-5Ch] BYREF
  _QWORD v6[11]; // [xsp+8h] [xbp-58h] BYREF

  v6[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 168);
  v5 = 0;
  v4[0] = 0;
  cancel_work_sync(v1 + 280);
  gh_dbl_tx_unregister(*(_QWORD *)(v1 + 264));
  result = gh_dbl_rx_unregister(*(_QWORD *)(v1 + 272));
  if ( *(_BYTE *)(v1 + 176) == 1 )
  {
    gunyah_qtvm_unregister_notifier(v1 + 184);
    result = ghd_rm_get_vmid(*(unsigned int *)(v1 + 180), &v5);
    if ( !(_DWORD)result )
    {
      result = ghd_rm_get_vmid(1, v4);
      if ( !(_DWORD)result )
      {
        qrtr_gunyah_unshare_mem(v1, v4[0], v5);
        v3 = *(_QWORD *)(*(_QWORD *)(v1 + 24) + 744LL);
        memset(v6, 0, 80);
        result = _of_parse_phandle_with_args(v3, "shared-buffer", 0, 0, 0, v6);
        if ( (_DWORD)result || !v6[0] )
          result = dma_free_attrs(
                     *(_QWORD *)(v1 + 24),
                     *(_QWORD *)(v1 + 168),
                     *(_QWORD *)(v1 + 160),
                     *(_QWORD *)(v1 + 56),
                     64);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
