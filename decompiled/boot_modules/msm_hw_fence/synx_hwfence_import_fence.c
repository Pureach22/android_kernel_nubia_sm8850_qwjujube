__int64 __fastcall synx_hwfence_import_fence(unsigned __int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v8; // x22
  __int64 updated; // x0
  _QWORD *v10; // x20
  __int64 v11; // x24
  int v12; // w0
  __int64 result; // x0
  unsigned int v14; // w8
  unsigned int v15; // w23
  __int64 v16; // x5
  int fence_from_import; // w0
  unsigned int v18; // w19
  unsigned int v19; // w19
  int v20; // w25
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v8 = v5;
  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  updated = hw_fence_check_valid_fctl(hw_fence_drv_data, a1, a3, a4, a5);
  if ( !(_DWORD)updated )
  {
    v10 = (_QWORD *)(a2 + 16);
    v11 = *(_QWORD *)(a2 + 16);
    if ( v11 && *(_UNKNOWN **)(v11 + 8) == &dma_fence_array_ops )
    {
      if ( *(_DWORD *)(v11 + 68) )
      {
        v14 = 0;
        while ( 1 )
        {
          v15 = v14;
          v16 = *(_QWORD *)(*(_QWORD *)(v11 + 80) + 8LL * (int)v14);
          if ( *(_UNKNOWN **)(v16 + 8) == &dma_fence_array_ops )
          {
            printk(&unk_27DA1, "synx_hwfence_import_fence", 544, v8, v14);
            v12 = -22;
            goto LABEL_16;
          }
          *(_QWORD *)(a2 + 16) = v16;
          fence_from_import = hw_fence_interop_create_fence_from_import(a2);
          if ( fence_from_import )
            break;
          v14 = v15 + 1;
          if ( v15 + 1 >= *(_DWORD *)(v11 + 68) )
            goto LABEL_15;
        }
        v20 = fence_from_import;
        printk(&unk_27DF4, "synx_hwfence_import_fence", 553, v8, v15);
        v12 = v20;
      }
      else
      {
LABEL_15:
        v12 = 0;
      }
LABEL_16:
      *v10 = v11;
      if ( !v12 )
      {
LABEL_5:
        updated = msm_hw_fence_wait_update_v2(a1, (_QWORD *)(a2 + 16), (__int64)v21, 0, 1);
        if ( (_DWORD)updated )
        {
          v19 = updated;
          printk(&unk_206D5, "synx_hwfence_import_fence", 573, v8, *(_QWORD *)(a2 + 16));
          updated = v19;
        }
        else
        {
          if ( HIDWORD(v21[0]) )
          {
            printk(&unk_22379, "synx_hwfence_import_fence", 577, v8, v21[0]);
            msm_hw_fence_wait_update_v2(a1, (_QWORD *)(a2 + 16), (__int64)v21, 0, 1);
            result = 4294967274LL;
            goto LABEL_9;
          }
          **(_DWORD **)a2 = LODWORD(v21[0]) | 0x80000000;
        }
        goto LABEL_8;
      }
    }
    else
    {
      v12 = hw_fence_interop_create_fence_from_import(a2);
      if ( !v12 )
        goto LABEL_5;
    }
    v18 = v12;
    printk(&unk_22324, "synx_hwfence_import_fence", 565, v8, *v10);
    result = v18;
    goto LABEL_9;
  }
LABEL_8:
  result = hw_fence_interop_to_synx_status(updated);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
