__int64 __fastcall gh_panic_notifier_vm_cb(__int64 a1, __int64 a2, _WORD *a3)
{
  __int64 v6; // x0
  _QWORD *v8; // x20
  __int64 v9; // x0
  int v10; // w0
  int v11; // w2
  __int64 v12; // x0
  __int64 v13; // x8
  unsigned __int64 v14; // x3
  unsigned __int64 v15; // x9
  __int64 v16; // x8
  unsigned __int64 v17; // x10
  bool v18; // cf
  unsigned __int64 v19; // x10
  __int64 v20; // x0
  _BYTE *v21; // x21
  __int64 v22; // x0
  __int64 v23; // x8
  _WORD v24[2]; // [xsp+8h] [xbp-28h] BYREF
  unsigned __int16 v25; // [xsp+Ch] [xbp-24h] BYREF
  _QWORD v26[2]; // [xsp+10h] [xbp-20h] BYREF
  int v27; // [xsp+20h] [xbp-10h]
  int v28; // [xsp+24h] [xbp-Ch]
  __int64 v29; // [xsp+28h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned int *)(a1 - 36);
  v26[0] = 0;
  v25 = 0;
  v24[0] = 0;
  if ( !(unsigned int)ghd_rm_get_vmid(v6, &v25) && !(unsigned int)ghd_rm_get_vmid(1, v24) )
  {
    v8 = (_QWORD *)(a1 - 160);
    if ( (unsigned __int64)(a2 - 2) >= 2 )
    {
      if ( a2 == 1 && v25 == (unsigned __int16)*a3 )
      {
        v20 = dma_alloc_attrs(*(_QWORD *)(a1 - 160), *(_QWORD *)(a1 - 48), v26, 3264, 0);
        *(_QWORD *)(a1 - 56) = v20;
        if ( v20 )
        {
          v21 = (_BYTE *)v20;
          v22 = dma_to_phys(*(_QWORD *)(a1 - 160), v26[0]);
          v23 = v22 + *(_QWORD *)(a1 - 48) - 1;
          *(_QWORD *)(a1 - 152) = v22;
          *(_QWORD *)(a1 - 144) = v23;
          *v21 = 0;
          if ( (unsigned int)gh_panic_notifier_share_mem(a1 - 160, v24[0], v25) )
          {
            dev_err(*v8, "Failed to share memory\n");
          }
          else
          {
            *(_QWORD *)(a1 + 48) = gh_panic_notifier_notify;
            *(_DWORD *)(a1 + 64) = 0;
            atomic_notifier_chain_register(&panic_notifier_list, a1 + 48);
          }
        }
      }
    }
    else if ( v25 == (unsigned __int16)*a3 && *(_QWORD *)(a1 - 56) )
    {
      atomic_notifier_chain_unregister(&panic_notifier_list, a1 + 48);
      v9 = *(unsigned int *)(a1 - 32);
      v27 = v24[0];
      v28 = 7;
      v26[1] = (1LL << v25) | (1LL << SLOBYTE(v24[0]));
      v10 = ghd_rm_mem_reclaim(v9, 0);
      if ( v10 )
        dev_err(*v8, "Gunyah mem reclaim failed: %d\n", v10);
      v11 = qcom_scm_assign_mem();
      v12 = *(_QWORD *)(a1 - 160);
      if ( v11 )
      {
        dev_err(v12, "unshare mem assign call failed with %d\n", v11);
      }
      else
      {
        v13 = *(_QWORD *)(v12 + 664);
        v14 = *(_QWORD *)(a1 - 152);
        if ( v13 )
        {
          v15 = *(_QWORD *)(v13 + 16);
          if ( v15 )
          {
            v16 = v13 + 8;
            do
            {
              v17 = *(_QWORD *)(v16 - 8);
              v18 = v14 >= v17;
              v19 = v14 - v17;
              if ( v18 && v19 < v15 )
                break;
              v15 = *(_QWORD *)(v16 + 32);
              v16 += 24;
            }
            while ( v15 );
          }
        }
        dma_free_attrs();
        *(_QWORD *)(a1 - 56) = 0;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
