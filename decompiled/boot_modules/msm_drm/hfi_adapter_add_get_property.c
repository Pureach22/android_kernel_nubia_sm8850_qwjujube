__int64 __fastcall hfi_adapter_add_get_property(
        __int64 a1,
        int a2,
        int a3,
        unsigned int a4,
        __int64 a5,
        unsigned int a6,
        __int64 a7,
        int a8)
{
  __int64 v8; // x8
  __int64 v10; // x19
  int v17; // w24
  int v18; // w21
  unsigned int v19; // w28
  __int64 v21; // x24
  __int64 v22; // x0
  _QWORD *v23; // x1
  _QWORD *v24; // x0
  __int64 v25; // x2
  __int64 v26; // x8
  __int64 v27; // x9
  __int64 v28; // x8
  __int64 v29; // x8
  __int64 v30; // x25
  int v32; // w19
  unsigned int v33; // w10
  unsigned int v38; // w11
  __int64 v39; // x8
  unsigned int v40; // w0
  __int64 v41; // x19
  __int64 v42; // x0
  _QWORD *v43; // x8
  __int64 v44; // x2
  _QWORD *v45; // x1
  __int64 result; // x0
  unsigned int v47; // w19
  void *v48; // x0
  unsigned int v51; // w8
  unsigned int v53; // [xsp+14h] [xbp-3Ch]
  __int64 v54; // [xsp+18h] [xbp-38h] BYREF
  __int64 v55; // [xsp+20h] [xbp-30h]
  _DWORD v56[2]; // [xsp+28h] [xbp-28h] BYREF
  __int64 v57; // [xsp+30h] [xbp-20h]
  unsigned __int64 v58; // [xsp+38h] [xbp-18h]
  __int64 v59; // [xsp+40h] [xbp-10h]
  __int64 v60; // [xsp+48h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v55 = 0;
  if ( !a1 || (v8 = *(_QWORD *)(a1 + 136)) == 0 )
  {
    v48 = &unk_248BBA;
LABEL_36:
    printk(v48, "hfi_adapter_add_get_property");
    goto LABEL_37;
  }
  v10 = *(_QWORD *)(v8 + 120);
  if ( !v10 )
  {
LABEL_37:
    result = 4294967274LL;
    goto LABEL_38;
  }
  mutex_lock(v10 + 368);
  v17 = *(_DWORD *)(a1 + 80);
  v18 = *(_DWORD *)(a1 + 60);
  mutex_unlock(v10 + 368);
  v53 = a6;
  if ( a4 )
  {
    if ( !a5 )
    {
      v48 = &unk_2204B7;
      goto LABEL_36;
    }
    v19 = a6 + 32;
  }
  else
  {
    v19 = 32;
  }
  mutex_lock(v10 + 368);
  _CF = v17 - v18 >= v19;
  v21 = a1;
  if ( !_CF )
  {
    v22 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))hfi_adapter_get_cmd_buf_helper)(
            *(_QWORD *)(a1 + 136),
            *(unsigned int *)(a1 + 56),
            *(unsigned int *)(a1 + 48));
    v21 = v22;
    if ( v22 )
    {
      v23 = *(_QWORD **)(a1 + 128);
      v24 = (_QWORD *)(v22 + 120);
      v25 = a1 + 120;
      if ( v21 == a1 || v23 == v24 || *v23 != v25 )
      {
        _list_add_valid_or_report(v24, v23);
      }
      else
      {
        *(_QWORD *)(a1 + 128) = v24;
        *(_QWORD *)(v21 + 120) = v25;
        *(_QWORD *)(v21 + 128) = v23;
        *v23 = v24;
      }
    }
    else
    {
      printk(&unk_211CF6, "_chain_new_buffer");
    }
  }
  mutex_unlock(v10 + 368);
  v26 = *(_QWORD *)(v21 + 64);
  v27 = *(_QWORD *)(v21 + 80);
  v57 = 0;
  v58 = 0;
  v59 = 0;
  v54 = v26;
  v28 = *(_QWORD *)(a1 + 136);
  LODWORD(v55) = v27;
  v29 = *(_QWORD *)(v28 + 120);
  v56[0] = a2;
  v56[1] = a3;
  LODWORD(v57) = a8;
  v30 = raw_spin_lock_irqsave(v29 + 360);
  _X9 = &id_counter;
  while ( 1 )
  {
    v32 = id_counter;
    if ( id_counter == -1 )
      break;
    v33 = id_counter + 1;
    __asm { PRFM            #0x11, [X9] }
    while ( 1 )
    {
      v38 = __ldxr((unsigned int *)&id_counter);
      if ( v38 != v32 )
        break;
      if ( !__stlxr(v33, (unsigned int *)&id_counter) )
      {
        __dmb(0xBu);
        break;
      }
    }
    if ( v38 == v32 )
      goto LABEL_23;
  }
  _X11 = &id_counter;
  __asm { PRFM            #0x11, [X11] }
  while ( 1 )
  {
    v51 = __ldxr((unsigned int *)&id_counter);
    if ( v51 != -1 )
      break;
    if ( !__stlxr(0, (unsigned int *)&id_counter) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( v51 == -1 )
    printk(&unk_25A4E1, "_generate_sequential_packet_id");
LABEL_23:
  v39 = *(_QWORD *)(a1 + 136);
  HIDWORD(v57) = v32;
  raw_spin_unlock_irqrestore(*(_QWORD *)(v39 + 120) + 360LL, v30);
  v59 = a5;
  v58 = __PAIR64__(v53, a4);
  if ( a4 )
  {
    v40 = hfi_create_full_packet(&v54, v56);
    if ( !v40 )
      goto LABEL_25;
LABEL_32:
    v47 = v40;
    printk(&unk_24F768, "hfi_adapter_add_get_property");
    result = v47;
    goto LABEL_38;
  }
  v40 = hfi_create_packet_header(&v54, v56);
  if ( v40 )
    goto LABEL_32;
LABEL_25:
  *(_DWORD *)(v21 + 60) += v19;
  v41 = *(_QWORD *)(a1 + 136);
  if ( !v41 )
  {
    v48 = &unk_26FAEC;
    goto LABEL_36;
  }
  v42 = _kmalloc_cache_noprof(wake_up_process, 3264, 32);
  v43 = (_QWORD *)v42;
  if ( v42 )
  {
    v44 = v41 + 80;
    *(_DWORD *)(v42 + 16) = HIDWORD(v57);
    *(_QWORD *)(v42 + 24) = a7;
    v45 = *(_QWORD **)(v41 + 88);
    if ( v42 == v41 + 80 || v45 == (_QWORD *)v42 || *v45 != v44 )
    {
      _list_add_valid_or_report(v42, v45);
      result = 0;
    }
    else
    {
      result = 0;
      *(_QWORD *)(v41 + 88) = v43;
      *v43 = v44;
      v43[1] = v45;
      *v45 = v43;
    }
  }
  else
  {
    printk(&unk_26C111, "hfi_adapter_add_get_property");
    result = 4294967284LL;
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
