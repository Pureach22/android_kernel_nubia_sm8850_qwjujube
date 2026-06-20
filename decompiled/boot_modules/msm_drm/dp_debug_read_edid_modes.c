__int64 __fastcall dp_debug_read_edid_modes(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x8
  _QWORD *v5; // x25
  unsigned __int64 v6; // x20
  unsigned __int64 v7; // x19
  __int64 v8; // x0
  __int64 v9; // x0
  const char *v10; // x23
  unsigned int v11; // w27
  int v12; // w26
  int v13; // w0
  __int64 v14; // x0
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v16; // x10
  __int64 v17; // x0
  _QWORD *v19; // x10
  unsigned __int64 v20; // x10
  unsigned __int64 v25; // x9
  unsigned __int64 v26; // x8
  unsigned __int64 v28; // x9
  __int64 ipc_log_context; // x0

  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 )
  {
    v5 = **(_QWORD ***)(v4 + 144);
    if ( v5 )
    {
      if ( *a4 )
      {
        return 0;
      }
      else
      {
        v7 = _kmalloc_cache_noprof(kthread_park, 3520, 4096);
        if ( v7 >= 0x11 )
        {
          mutex_lock(*v5 + 432LL);
          v10 = (const char *)v5[22];
          if ( v10 == (const char *)(v5 + 22) )
          {
            v11 = 0;
          }
          else
          {
            v11 = 0;
            v12 = 4096;
            while ( 1 )
            {
              v13 = drm_mode_vrefresh(v10 - 64);
              v14 = snprintf(
                      (char *)(v7 + v11),
                      (unsigned int)v12,
                      "%s %d %d %d %d %d 0x%x\n",
                      v10 + 16,
                      v13,
                      *((_DWORD *)v10 + 13),
                      *((unsigned __int16 *)v10 - 27),
                      *((unsigned __int16 *)v10 - 22),
                      *((_DWORD *)v10 - 16),
                      *((_DWORD *)v10 - 10));
              if ( v12 <= (int)v14 )
                break;
              v10 = *(const char **)v10;
              v11 += v14;
              v12 = 4096 - v11;
              if ( v10 == (const char *)(v5 + 22) )
                goto LABEL_15;
            }
            ipc_log_context = get_ipc_log_context(v14);
            ipc_log_string(ipc_log_context, "[e][%-4d]buffer overflow\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
            printk(&unk_27296B, "dp_debug_check_buffer_overflow");
          }
LABEL_15:
          mutex_unlock(*v5 + 432LL);
          if ( v11 >= a3 )
            v6 = a3;
          else
            v6 = v11;
          if ( v6 > 0x1000 )
          {
            _copy_overflow(4096, v6);
          }
          else
          {
            _check_object_size(v7, v6, 1);
            StatusReg = _ReadStatusReg(SP_EL0);
            if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v16 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
              v16 = a2 & ((__int64)(a2 << 8) >> 8);
            v17 = v6;
            _CF = 0x8000000000LL - v6 >= v16;
            v19 = a4;
            if ( _CF )
            {
              v20 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v25 = *(_QWORD *)(StatusReg + 8);
              _WriteStatusReg(TTBR1_EL1, v25 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v25);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v20);
              v17 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
              v19 = a4;
              v26 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v28 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v28 - 4096);
              _WriteStatusReg(TTBR1_EL1, v28);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v26);
            }
            if ( !v17 )
            {
              *v19 += v6;
              kfree(v7);
              return v6;
            }
          }
          kfree(v7);
          return -14;
        }
        else
        {
          return -12;
        }
      }
    }
    else
    {
      v9 = get_ipc_log_context(a1);
      ipc_log_string(v9, "[e][%-4d]connector is NULL\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_272998, "dp_debug_read_edid_modes");
      return -22;
    }
  }
  else
  {
    v8 = get_ipc_log_context(a1);
    ipc_log_string(v8, "[e][%-4d]invalid data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_245274, "dp_debug_read_edid_modes");
    return -19;
  }
}
