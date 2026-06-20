__int64 __fastcall iommu_debug_atos_write(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v5; // x21
  unsigned __int64 v6; // x0
  __int64 v7; // x8
  _QWORD *v8; // x9
  unsigned __int64 StatusReg; // x8
  __int64 v10; // x9
  __int64 v12; // x9
  __int64 v13; // x20
  __int64 v14; // x9
  unsigned __int64 v15; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v16[2]; // [xsp+10h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD **)(a1 + 32);
  v16[0] = 0;
  mutex_lock(v5 + 7);
  if ( v5[5] )
  {
    if ( (unsigned int)kstrtoull_from_user(a2, a3, 0, v16) )
    {
      dev_err(v5[4], "Invalid format for iova\n");
      v5[17] = 0;
      goto LABEL_15;
    }
    v6 = iommu_iova_to_phys(v5[5], v16[0]);
    v15 = v6;
    if ( HIWORD(v6) )
      goto LABEL_14;
    if ( mem_section && (v7 = *(_QWORD *)(mem_section + ((v6 >> 31) & 0x1FFFFFFF8LL))) != 0 )
      v8 = (_QWORD *)(v7 + 32 * ((v6 >> 27) & 0x7F));
    else
      v8 = nullptr;
    StatusReg = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(StatusReg + 16);
    if ( v8 && (*v8 & 2) != 0 )
    {
      if ( (*v8 & 8) != 0 )
      {
        LODWORD(v13) = 1;
      }
      else
      {
        v12 = v8[1];
        if ( v12 )
          v13 = (*(_QWORD *)(v12 + 16) >> (v6 >> 21)) & 1LL;
        else
          LODWORD(v13) = 0;
      }
      v14 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v14;
      if ( v14 && *(_QWORD *)(StatusReg + 16) )
      {
        if ( (_DWORD)v13 )
        {
LABEL_25:
          v5[17] = v16[0];
          mutex_unlock(v5 + 7);
          printk(&unk_CBEE, v16);
          goto LABEL_16;
        }
LABEL_14:
        dev_err(v5[4], "Invalid ATOS operation page %pa\n", &v15);
        goto LABEL_15;
      }
    }
    else
    {
      v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v10;
      if ( v10 && *(_QWORD *)(StatusReg + 16) )
        goto LABEL_14;
      LODWORD(v13) = 0;
    }
    preempt_schedule();
    if ( (_DWORD)v13 )
      goto LABEL_25;
    goto LABEL_14;
  }
  printk(&unk_CE32, "iommu_debug_atos_write");
LABEL_15:
  mutex_unlock(v5 + 7);
  a3 = -22;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return a3;
}
