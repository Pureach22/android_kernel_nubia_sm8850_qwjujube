__int64 __fastcall qrtr_gunyah_vm_cb(__int64 a1, __int64 a2, unsigned __int16 *a3)
{
  __int64 v4; // x0
  int v6; // w20
  _WORD v8[2]; // [xsp+0h] [xbp-10h] BYREF
  unsigned __int16 v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
  {
    v4 = *(unsigned int *)(a1 - 4);
    v6 = *a3;
    v9 = 0;
    v8[0] = 0;
    if ( !(unsigned int)ghd_rm_get_vmid(v4, &v9) && !(unsigned int)ghd_rm_get_vmid(1, v8) && v9 == v6 )
    {
      mutex_lock(a1 + 24);
      if ( (unsigned __int64)(a2 - 2) >= 2 )
      {
        if ( a2 == 1 && (*(_BYTE *)(a1 + 72) & 1) == 0 )
        {
          qrtr_gunyah_fifo_init(a1 - 184);
          if ( (unsigned int)qrtr_endpoint_register(a1 - 184, 1, 0, 0) )
          {
            dev_err(*(_QWORD *)(a1 - 160), "endpoint register failed\n");
          }
          else if ( (unsigned int)qrtr_gunyah_share_mem(a1 - 184, v8[0], v9) )
          {
            dev_err(*(_QWORD *)(a1 - 160), "failed to share memory\n");
            qrtr_endpoint_unregister(a1 - 184);
          }
          else
          {
            *(_BYTE *)(a1 + 72) = 1;
          }
        }
      }
      else if ( *(_BYTE *)(a1 + 72) == 1 )
      {
        qrtr_endpoint_unregister(a1 - 184);
        qrtr_gunyah_unshare_mem(a1 - 184, v8[0], v9);
        *(_BYTE *)(a1 + 72) = 0;
      }
      mutex_unlock(a1 + 24);
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
