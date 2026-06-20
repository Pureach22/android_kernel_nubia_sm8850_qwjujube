__int64 __fastcall dp_debug_read_edid_modes_mst(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x19
  unsigned __int64 v6; // x22
  __int64 v7; // x0
  _QWORD *v8; // x24
  __int64 v10; // x23
  __int64 v11; // x21
  const char *v12; // x26
  unsigned int v13; // w28
  int v14; // w25
  int v15; // w0
  __int64 v16; // x0
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v18; // x10
  __int64 v19; // x0
  unsigned __int64 v20; // x10
  unsigned __int64 v25; // x9
  unsigned __int64 v26; // x8
  unsigned __int64 v28; // x9
  __int64 v29; // x0
  __int64 ipc_log_context; // x0
  __int64 v31; // x0

  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 )
  {
    if ( *a4 )
    {
      return 0;
    }
    else
    {
      v7 = drm_mode_object_find(***(_QWORD ***)(v4 + 144), 0, *(unsigned int *)(v4 + 16), 3233857728LL);
      v8 = (_QWORD *)(v7 - 64);
      if ( v7 )
        _ZF = v7 == 64;
      else
        _ZF = 1;
      if ( _ZF )
      {
        ipc_log_context = get_ipc_log_context(v7);
        ipc_log_string(
          ipc_log_context,
          "[e][%-4d]connector %u not in mst list\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          *(_DWORD *)(v4 + 16));
        printk(&unk_26BA2F, "dp_debug_read_edid_modes_mst");
        return 0;
      }
      else
      {
        v10 = v7;
        v11 = _kmalloc_cache_noprof(kthread_park, 3520, 4096);
        if ( v11 )
        {
          mutex_lock(*(_QWORD *)(v10 - 64) + 432LL);
          v12 = *(const char **)(v10 + 112);
          if ( v12 == (const char *)(v10 + 112) )
          {
            v13 = 0;
          }
          else
          {
            v13 = 0;
            v14 = 4096;
            while ( 1 )
            {
              v15 = drm_mode_vrefresh(v12 - 64);
              v16 = snprintf(
                      (char *)(v11 + v13),
                      (unsigned int)v14,
                      "%s %d %d %d %d %d 0x%x\n",
                      v12 + 16,
                      v15,
                      *((_DWORD *)v12 + 13),
                      *((unsigned __int16 *)v12 - 27),
                      *((unsigned __int16 *)v12 - 22),
                      *((_DWORD *)v12 - 16),
                      *((_DWORD *)v12 - 10));
              if ( v14 <= (int)v16 )
                break;
              v12 = *(const char **)v12;
              v13 += v16;
              v14 = 4096 - v13;
              if ( v12 == (const char *)(v10 + 112) )
                goto LABEL_15;
            }
            v31 = get_ipc_log_context(v16);
            ipc_log_string(v31, "[e][%-4d]buffer overflow\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
            printk(&unk_27296B, "dp_debug_check_buffer_overflow");
          }
LABEL_15:
          mutex_unlock(*v8 + 432LL);
          if ( v13 >= a3 )
            v6 = a3;
          else
            v6 = v13;
          if ( v6 > 0x1000 )
          {
            _copy_overflow(4096, v6);
            v6 = 4294967282LL;
          }
          else
          {
            _check_object_size(v11, v6, 1);
            StatusReg = _ReadStatusReg(SP_EL0);
            if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v18 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
              v18 = a2 & ((__int64)(a2 << 8) >> 8);
            v19 = v6;
            if ( 0x8000000000LL - v6 >= v18 )
            {
              v20 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v25 = *(_QWORD *)(StatusReg + 8);
              _WriteStatusReg(TTBR1_EL1, v25 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v25);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v20);
              v19 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
              v26 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v28 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v28 - 4096);
              _WriteStatusReg(TTBR1_EL1, v28);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v26);
            }
            if ( v19 )
              v6 = 4294967282LL;
            else
              *a4 += v6;
          }
        }
        else
        {
          v6 = 0;
        }
        kfree(v11);
        drm_mode_object_put(v10);
      }
    }
  }
  else
  {
    v29 = get_ipc_log_context(a1);
    ipc_log_string(v29, "[e][%-4d]invalid data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_245274, "dp_debug_read_edid_modes_mst");
    return -19;
  }
  return v6;
}
