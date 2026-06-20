__int64 __fastcall ccid_bulk_write(__int64 a1, unsigned __int64 a2, size_t a3)
{
  __int64 v3; // x24
  __int64 *v6; // x19
  __int64 v7; // x0
  _QWORD *v8; // x10
  __int64 v9; // x9
  _QWORD *v10; // x8
  __int64 *v11; // x22
  __int64 v12; // x11
  __int64 v13; // x2
  __int64 result; // x0
  __int64 v15; // x23
  __int64 v16; // x0
  _QWORD *v17; // x10
  __int64 v18; // x9
  _QWORD *v19; // x8
  __int64 v20; // x11
  __int64 v21; // x0
  __int64 v22; // x23
  __int64 v23; // x0
  __int64 **v24; // x8
  __int64 **v25; // x1
  __int64 v26; // x9
  __int64 v27; // x0
  __int64 **v28; // x8
  __int64 **v29; // x1
  __int64 v30; // x9
  __int64 v31; // x20
  __int64 v32; // x19
  __int64 v33; // x0
  __int64 *i; // x10
  __int64 v35; // x9
  __int64 **v36; // x8
  __int64 *v37; // x11
  __int64 *v38; // x21
  __int64 v39; // x22
  _QWORD v40[6]; // [xsp+0h] [xbp-30h] BYREF

  v40[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 32);
  if ( !*(_DWORD *)(v3 + 232) )
  {
    result = -19;
    goto LABEL_61;
  }
  if ( !a3 )
  {
    printk(&unk_81A1, "ccid_bulk_write", 0);
    result = -19;
    goto LABEL_61;
  }
  if ( a3 >= 0x20C )
  {
    printk(&unk_8256, "ccid_bulk_write", 523);
    result = -12;
    goto LABEL_61;
  }
  v6 = (__int64 *)(v3 + 544);
  v7 = raw_spin_lock_irqsave(v3 + 228);
  v8 = *(_QWORD **)(v3 + 544);
  v9 = v7;
  if ( v8 == (_QWORD *)(v3 + 544) )
  {
    raw_spin_unlock_irqrestore(v3 + 228, v7);
  }
  else
  {
    v10 = (_QWORD *)v8[1];
    v11 = v8 - 8;
    if ( (_QWORD *)*v10 == v8 && (v12 = *v8, *(_QWORD **)(*v8 + 8LL) == v8) )
    {
      *(_QWORD *)(v12 + 8) = v10;
      *v10 = v12;
    }
    else
    {
      _list_del_entry_valid_or_report(*(_QWORD *)(v3 + 544));
    }
    *v8 = 0xDEAD000000000100LL;
    v8[1] = 0xDEAD000000000122LL;
    raw_spin_unlock_irqrestore(v3 + 228, v9);
    if ( v11 )
    {
      if ( !*(_DWORD *)(v3 + 464) )
        goto LABEL_29;
      goto LABEL_56;
    }
  }
  if ( *(_DWORD *)(v3 + 464) )
  {
LABEL_56:
    printk(&unk_82FB, "ccid_bulk_write", v13);
    LODWORD(v15) = -5;
    goto LABEL_60;
  }
  memset(v40, 0, 40);
  init_wait_entry(v40, 0);
  while ( 1 )
  {
    v15 = prepare_to_wait_event(v3 + 504, v40, 1);
    v16 = raw_spin_lock_irqsave(v3 + 228);
    v17 = (_QWORD *)*v6;
    v18 = v16;
    if ( (__int64 *)*v6 != v6 )
      break;
    v21 = raw_spin_unlock_irqrestore(v3 + 228, v16);
    if ( *(_DWORD *)(v3 + 464) )
    {
LABEL_55:
      finish_wait(v3 + 504, v40);
      goto LABEL_56;
    }
LABEL_23:
    if ( v15 )
    {
      if ( (v15 & 0x80000000) != 0 )
        goto LABEL_60;
      goto LABEL_56;
    }
    schedule(v21);
  }
  v19 = (_QWORD *)v17[1];
  if ( (_QWORD *)*v19 == v17 && (v20 = *v17, *(_QWORD **)(*v17 + 8LL) == v17) )
  {
    *(_QWORD *)(v20 + 8) = v19;
    *v19 = v20;
  }
  else
  {
    _list_del_entry_valid_or_report(*v6);
  }
  *v17 = 0xDEAD000000000100LL;
  v17[1] = 0xDEAD000000000122LL;
  v11 = v17 - 8;
  v21 = raw_spin_unlock_irqrestore(v3 + 228, v18);
  if ( !v11 )
  {
    if ( *(_DWORD *)(v3 + 464) )
      goto LABEL_55;
    goto LABEL_23;
  }
  finish_wait(v3 + 504, v40);
  if ( *(_DWORD *)(v3 + 464) )
    goto LABEL_56;
LABEL_29:
  v22 = *v11;
  _check_object_size(*v11, a3, 0);
  if ( inline_copy_from_user(v22, a2, a3) )
  {
    if ( *(_DWORD *)(v3 + 232) )
    {
      v23 = raw_spin_lock_irqsave(v3 + 228);
      v24 = (__int64 **)(v11 + 8);
      v25 = *(__int64 ***)(v3 + 552);
      v26 = v23;
      if ( v11 + 8 == v6 || v25 == v24 || *v25 != v6 )
      {
        _list_add_valid_or_report(v11 + 8, v25, v3 + 544);
      }
      else
      {
        *(_QWORD *)(v3 + 552) = v24;
        v11[8] = (__int64)v6;
        v11[9] = (__int64)v25;
        *v25 = (__int64 *)v24;
      }
      raw_spin_unlock_irqrestore(v3 + 228, v26);
      LODWORD(v15) = -14;
    }
    else
    {
      v32 = *(_QWORD *)(v3 + 248);
      kfree(*v11);
      usb_ep_free_request(v32, v11);
      LODWORD(v15) = -19;
    }
  }
  else
  {
    *((_DWORD *)v11 + 2) = a3;
    LODWORD(v15) = a3;
    if ( (usb_ep_queue(*(_QWORD *)(v3 + 248), v11, 3264) & 0x80000000) != 0 )
    {
      *(_DWORD *)(v3 + 464) = 1;
      v27 = raw_spin_lock_irqsave(v3 + 228);
      v28 = (__int64 **)(v11 + 8);
      v29 = *(__int64 ***)(v3 + 552);
      v30 = v27;
      if ( v11 + 8 == v6 || v29 == v28 || *v29 != v6 )
      {
        _list_add_valid_or_report(v11 + 8, v29, v3 + 544);
      }
      else
      {
        *(_QWORD *)(v3 + 552) = v28;
        v11[8] = (__int64)v6;
        v11[9] = (__int64)v29;
        *v29 = (__int64 *)v28;
      }
      raw_spin_unlock_irqrestore(v3 + 228, v30);
      v31 = raw_spin_lock_irqsave(v3 + 228);
      if ( *(_DWORD *)(v3 + 232) )
      {
        LODWORD(v15) = -5;
      }
      else
      {
        raw_spin_unlock_irqrestore(v3 + 228, v31);
        v33 = raw_spin_lock_irqsave(v3 + 228);
        for ( i = (__int64 *)*v6; ; i = *(__int64 **)(v3 + 544) )
        {
          v35 = v33;
          if ( i == v6 )
            break;
          v36 = (__int64 **)i[1];
          if ( *v36 == i && (v37 = (__int64 *)*i, *(__int64 **)(*i + 8) == i) )
          {
            v37[1] = (__int64)v36;
            *v36 = v37;
          }
          else
          {
            _list_del_entry_valid_or_report(i);
          }
          *i = 0xDEAD000000000100LL;
          i[1] = 0xDEAD000000000122LL;
          v38 = i - 8;
          raw_spin_unlock_irqrestore(v3 + 228, v35);
          if ( !v38 )
            goto LABEL_58;
          v39 = *(_QWORD *)(v3 + 248);
          kfree(*v38);
          usb_ep_free_request(v39, v38);
          v33 = raw_spin_lock_irqsave(v3 + 228);
        }
        raw_spin_unlock_irqrestore(v3 + 228, v33);
LABEL_58:
        LODWORD(v15) = -19;
      }
      raw_spin_unlock_irqrestore(v3 + 228, v31);
    }
  }
LABEL_60:
  result = (int)v15;
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return result;
}
