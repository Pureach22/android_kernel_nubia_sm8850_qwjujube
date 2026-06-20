__int64 __fastcall qcom_ddump_vm_cb(__int64 a1, __int64 a2, unsigned __int16 *a3)
{
  __int64 v4; // x0
  int v6; // w20
  _QWORD *v8; // x8
  __int64 v9; // x20
  __int64 v10; // x21
  __int64 v11; // x22
  __int64 v12; // x0
  __int64 v13; // x9
  __int64 v14; // x21
  __int64 v15; // x0
  __int64 v16; // x0
  int v17; // w0
  _WORD v18[2]; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int16 v19; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
  {
    v4 = *(unsigned int *)(a1 - 12);
    v6 = *a3;
    v20[0] = 0;
    v19 = 0;
    v18[0] = 0;
    if ( !(unsigned int)ghd_rm_get_vmid(v4, &v19) && !(unsigned int)ghd_rm_get_vmid(1, v18) && v19 == v6 )
    {
      if ( (unsigned __int64)(a2 - 2) >= 2 )
      {
        if ( a2 == 1 && (*(_BYTE *)(a1 + 153) & 1) == 0 )
        {
          if ( *(_BYTE *)(a1 + 152) == 1 )
          {
            v14 = *(_QWORD *)(a1 - 32);
            v13 = *(_QWORD *)(a1 - 24);
            v15 = *(_QWORD *)(a1 - 128);
          }
          else
          {
            v16 = dma_alloc_attrs(*(_QWORD *)(a1 - 184), *(_QWORD *)(a1 - 24), v20, 3264, 0);
            *(_QWORD *)(a1 - 32) = v16;
            if ( !v16 )
              goto LABEL_3;
            v14 = v16;
            v15 = dma_to_phys(*(_QWORD *)(a1 - 184), v20[0]);
            v13 = *(_QWORD *)(a1 - 24);
            *(_QWORD *)(a1 - 128) = v15;
            *(_QWORD *)(a1 - 120) = v15 + v13 - 1;
          }
          strcpy((char *)(a1 + 104), "VM_LOG");
          *(_QWORD *)(a1 + 128) = v14;
          *(_QWORD *)(a1 + 136) = v15;
          *(_QWORD *)(a1 + 144) = v13;
          v17 = msm_minidump_add_region(a1 + 104);
          if ( v17 < 0 )
            dev_err(*(_QWORD *)(a1 - 184), "Failed to add vm log entry in minidump table %d\n", v17);
          if ( !(unsigned int)qcom_ddump_share_mem(a1 - 184, v18[0], v19) )
          {
            *(_BYTE *)(a1 + 153) = 1;
            goto LABEL_3;
          }
          dev_err(*(_QWORD *)(a1 - 184), "Failed to share memory\n");
          if ( (*(_BYTE *)(a1 + 152) & 1) != 0 )
            goto LABEL_3;
          goto LABEL_10;
        }
      }
      else if ( *(_BYTE *)(a1 + 153) == 1 )
      {
        v8 = *(_QWORD **)(a1 + 160);
        *(_BYTE *)(a1 + 153) = 0;
        v8[14] = 0;
        v8[15] = 0;
        v8[12] = 0;
        v8[13] = 0;
        v8[10] = 0;
        v8[11] = 0;
        v8[8] = 0;
        v8[9] = 0;
        v8[6] = 0;
        v8[7] = 0;
        v8[4] = 0;
        v8[5] = 0;
        v8[2] = 0;
        v8[3] = 0;
        *v8 = 0;
        v8[1] = 0;
        msm_minidump_remove_region(a1 + 104);
        if ( !(unsigned int)qcom_ddump_unshare_mem(a1 - 184, v18[0], v19) && (*(_BYTE *)(a1 + 152) & 1) == 0 )
        {
LABEL_10:
          v9 = *(_QWORD *)(a1 - 184);
          v11 = *(_QWORD *)(a1 - 32);
          v10 = *(_QWORD *)(a1 - 24);
          v12 = phys_to_dma(v9, *(_QWORD *)(a1 - 128));
          dma_free_attrs(v9, v10, v11, v12, 0);
        }
      }
    }
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return 0;
}
