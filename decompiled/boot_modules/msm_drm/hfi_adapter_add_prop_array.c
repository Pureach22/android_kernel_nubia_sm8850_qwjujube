__int64 __fastcall hfi_adapter_add_prop_array(
        __int64 a1,
        unsigned int a2,
        int a3,
        unsigned int a4,
        __int64 a5,
        unsigned int a6,
        unsigned int a7)
{
  __int64 v7; // x8
  __int64 v9; // x28
  unsigned int v16; // w25
  __int64 v18; // x25
  __int64 v19; // x0
  _QWORD *v20; // x1
  _QWORD *v21; // x0
  __int64 v22; // x2
  __int64 v23; // x8
  __int64 v24; // x9
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x26
  int v29; // w28
  unsigned int v30; // w10
  unsigned int v35; // w11
  __int64 result; // x0
  __int64 v37; // x8
  unsigned int v38; // w0
  void *v39; // x0
  unsigned int v40; // w19
  void *v41; // x0
  unsigned int v44; // w8
  __int64 v45; // [xsp+8h] [xbp-38h] BYREF
  __int64 v46; // [xsp+10h] [xbp-30h]
  _DWORD v47[2]; // [xsp+18h] [xbp-28h] BYREF
  __int64 v48; // [xsp+20h] [xbp-20h]
  __int64 v49; // [xsp+28h] [xbp-18h]
  __int64 v50; // [xsp+30h] [xbp-10h]
  __int64 v51; // [xsp+38h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49 = 0;
  v50 = 0;
  v48 = 0;
  v46 = 0;
  if ( !a1 || !a5 || (v7 = *(_QWORD *)(a1 + 136)) == 0 )
  {
    v39 = &unk_22A65E;
    goto LABEL_29;
  }
  v9 = *(_QWORD *)(v7 + 120);
  if ( v9 )
  {
    if ( a6 && a4 && a7 )
    {
      mutex_lock(v9 + 368);
      v16 = *(_DWORD *)(a1 + 80) - *(_DWORD *)(a1 + 60);
      mutex_unlock(v9 + 368);
      mutex_lock(v9 + 368);
      _CF = v16 >= a7 + 32;
      v18 = a1;
      if ( !_CF )
      {
        v19 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))hfi_adapter_get_cmd_buf_helper)(
                *(_QWORD *)(a1 + 136),
                *(unsigned int *)(a1 + 56),
                *(unsigned int *)(a1 + 48));
        v18 = v19;
        if ( v19 )
        {
          v20 = *(_QWORD **)(a1 + 128);
          v21 = (_QWORD *)(v19 + 120);
          v22 = a1 + 120;
          if ( v18 == a1 || v20 == v21 || *v20 != v22 )
          {
            _list_add_valid_or_report(v21, v20);
          }
          else
          {
            *(_QWORD *)(a1 + 128) = v21;
            *(_QWORD *)(v18 + 120) = v22;
            *(_QWORD *)(v18 + 128) = v20;
            *v20 = v21;
          }
        }
        else
        {
          printk(&unk_211CF6, "_chain_new_buffer");
        }
      }
      mutex_unlock(v9 + 368);
      v23 = *(_QWORD *)(v18 + 64);
      v24 = *(_QWORD *)(v18 + 80);
      v47[0] = a2;
      v47[1] = a3;
      v45 = v23;
      v25 = *(_QWORD *)(a1 + 136);
      LODWORD(v46) = v24;
      v26 = *(_QWORD *)(v25 + 120);
      LODWORD(v48) = 4;
      v27 = raw_spin_lock_irqsave(v26 + 360);
      _X9 = &id_counter;
      while ( 1 )
      {
        v29 = id_counter;
        if ( id_counter == -1 )
          break;
        v30 = id_counter + 1;
        __asm { PRFM            #0x11, [X9] }
        while ( 1 )
        {
          v35 = __ldxr((unsigned int *)&id_counter);
          if ( v35 != v29 )
            break;
          if ( !__stlxr(v30, (unsigned int *)&id_counter) )
          {
            __dmb(0xBu);
            break;
          }
        }
        if ( v35 == v29 )
          goto LABEL_24;
      }
      _X11 = &id_counter;
      __asm { PRFM            #0x11, [X11] }
      while ( 1 )
      {
        v44 = __ldxr((unsigned int *)&id_counter);
        if ( v44 != -1 )
          break;
        if ( !__stlxr(0, (unsigned int *)&id_counter) )
        {
          __dmb(0xBu);
          break;
        }
      }
      if ( v44 == -1 )
        printk(&unk_25A4E1, "_generate_sequential_packet_id");
LABEL_24:
      v37 = *(_QWORD *)(a1 + 136);
      HIDWORD(v48) = v29;
      raw_spin_unlock_irqrestore(*(_QWORD *)(v37 + 120) + 360LL, v27);
      LODWORD(v49) = a4;
      v38 = hfi_create_packet_header(&v45, v47);
      if ( v38 )
      {
        v40 = v38;
        v41 = &unk_26FB38;
      }
      else
      {
        result = hfi_append_packet_with_kv_pairs(&v45, a2, a4, 0, a5, a6, a7);
        if ( !(_DWORD)result )
        {
          *(_DWORD *)(v18 + 60) += a7 + 32;
          goto LABEL_33;
        }
        v40 = result;
        v41 = &unk_27CF97;
      }
      printk(v41, "hfi_adapter_add_prop_array");
      result = v40;
      goto LABEL_33;
    }
    v39 = &unk_25A45E;
LABEL_29:
    printk(v39, "hfi_adapter_add_prop_array");
    result = 4294967274LL;
    goto LABEL_33;
  }
  result = 4294967274LL;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
