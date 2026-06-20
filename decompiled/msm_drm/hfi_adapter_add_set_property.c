__int64 __fastcall hfi_adapter_add_set_property(
        __int64 a1,
        int a2,
        int a3,
        unsigned int a4,
        __int64 a5,
        unsigned int a6,
        int a7)
{
  __int64 v7; // x8
  __int64 v9; // x28
  int v16; // w23
  int v17; // w20
  unsigned int v18; // w27
  __int64 v20; // x23
  __int64 v21; // x0
  _QWORD *v22; // x1
  _QWORD *v24; // x0
  __int64 v25; // x2
  __int64 v26; // x8
  __int64 v27; // x9
  __int64 v28; // x8
  __int64 v29; // x8
  __int64 v30; // x24
  int v32; // w25
  unsigned int v33; // w10
  unsigned int v37; // w11
  __int64 v38; // x8
  __int64 result; // x0
  unsigned int v40; // w19
  void *v41; // x0
  unsigned int v44; // w8
  unsigned int v45; // [xsp+4h] [xbp-3Ch]
  __int64 v46; // [xsp+8h] [xbp-38h] BYREF
  __int64 v47; // [xsp+10h] [xbp-30h]
  _DWORD v48[2]; // [xsp+18h] [xbp-28h] BYREF
  __int64 v49; // [xsp+20h] [xbp-20h]
  unsigned __int64 v50; // [xsp+28h] [xbp-18h]
  __int64 v51; // [xsp+30h] [xbp-10h]
  __int64 v52; // [xsp+38h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  if ( !a1 || (v7 = *(_QWORD *)(a1 + 136)) == 0 )
  {
    v41 = &unk_248BBA;
LABEL_29:
    printk(v41, "hfi_adapter_add_set_property");
    goto LABEL_30;
  }
  v9 = *(_QWORD *)(v7 + 120);
  if ( !v9 )
  {
LABEL_30:
    result = 4294967274LL;
    goto LABEL_31;
  }
  mutex_lock(v9 + 368);
  v16 = *(_DWORD *)(a1 + 80);
  v17 = *(_DWORD *)(a1 + 60);
  mutex_unlock(v9 + 368);
  v45 = a6;
  if ( a4 )
  {
    if ( a5 )
    {
      v18 = a6 + 32;
      goto LABEL_8;
    }
    v41 = &unk_2204B7;
    goto LABEL_29;
  }
  v18 = 32;
LABEL_8:
  mutex_lock(v9 + 368);
  _CF = v16 - v17 >= v18;
  v20 = a1;
  if ( !_CF )
  {
    v21 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))hfi_adapter_get_cmd_buf_helper)(
            *(_QWORD *)(a1 + 136),
            *(unsigned int *)(a1 + 56),
            *(unsigned int *)(a1 + 48));
    if ( !v21 )
    {
      printk(&unk_211CF6, "_chain_new_buffer");
      mutex_unlock(v9 + 368);
      printk(&unk_211CF6, "hfi_adapter_add_set_property");
      result = 0xFFFFFFFFLL;
      goto LABEL_31;
    }
    v22 = *(_QWORD **)(a1 + 128);
    v20 = v21;
    _ZF = v21 == a1;
    v24 = (_QWORD *)(v21 + 120);
    v25 = a1 + 120;
    if ( _ZF || v22 == v24 || *v22 != v25 )
    {
      _list_add_valid_or_report(v24, v22);
    }
    else
    {
      *(_QWORD *)(a1 + 128) = v24;
      *(_QWORD *)(v20 + 120) = v25;
      *(_QWORD *)(v20 + 128) = v22;
      *v22 = v24;
    }
  }
  mutex_unlock(v9 + 368);
  v26 = *(_QWORD *)(v20 + 64);
  v27 = *(_QWORD *)(v20 + 80);
  v49 = 0;
  v50 = 0;
  v51 = 0;
  v46 = v26;
  v28 = *(_QWORD *)(a1 + 136);
  LODWORD(v47) = v27;
  v29 = *(_QWORD *)(v28 + 120);
  v48[0] = a2;
  v48[1] = a3;
  LODWORD(v49) = a7;
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
      v37 = __ldxr((unsigned int *)&id_counter);
      if ( v37 != v32 )
        break;
      if ( !__stlxr(v33, (unsigned int *)&id_counter) )
      {
        __dmb(0xBu);
        break;
      }
    }
    if ( v37 == v32 )
      goto LABEL_23;
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
LABEL_23:
  v38 = *(_QWORD *)(a1 + 136);
  HIDWORD(v49) = v32;
  raw_spin_unlock_irqrestore(*(_QWORD *)(v38 + 120) + 360LL, v30);
  v51 = a5;
  v50 = __PAIR64__(v45, a4);
  if ( !a4 )
  {
    result = hfi_create_packet_header(&v46, v48);
    if ( !(_DWORD)result )
      goto LABEL_25;
LABEL_27:
    v40 = result;
    printk(&unk_24F768, "hfi_adapter_add_set_property");
    result = v40;
    goto LABEL_31;
  }
  result = hfi_create_full_packet(&v46, v48);
  if ( (_DWORD)result )
    goto LABEL_27;
LABEL_25:
  *(_DWORD *)(v20 + 60) += v18;
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
