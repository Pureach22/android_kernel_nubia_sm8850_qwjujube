__int64 __fastcall syna_cdev_process_reports(__int64 a1, _QWORD *a2, __int64 a3, __int64 *a4)
{
  unsigned int v4; // w19
  _QWORD *v5; // x26
  __int64 v6; // x22
  signed int v7; // w20
  __int64 v9; // x25
  size_t v10; // x24
  __int64 v11; // x0
  __int64 v12; // x2
  __int64 v13; // x0
  unsigned __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x27
  _BYTE *v17; // x21
  __int64 v18; // x0
  __int64 v19; // x2
  __int64 v20; // x0
  __int64 v21; // x2
  __int16 v22; // w8
  __int64 v23; // x2
  unsigned int v24; // w8
  _QWORD *v25; // x25
  _QWORD *v26; // x8
  __int64 v27; // x9
  __int64 v28; // x0
  __int64 v29; // x2
  void *v30; // x0
  __int64 *v31; // x2
  __int64 *v32; // x1
  unsigned int v33; // w9
  unsigned int v34; // w8
  _DWORD *v35; // x8
  __int64 v36; // x0
  int v37; // w20
  unsigned int v38; // w23
  __int64 v39; // x0
  __int64 v40; // x2
  __int64 v41; // x0
  __int64 v42; // x2
  void *v43; // x0
  __int64 v44; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x2
  _BYTE *src; // [xsp+0h] [xbp-10h]
  unsigned __int8 v50; // [xsp+Ch] [xbp-4h]

  v50 = a1;
  if ( !a4 )
  {
    printk(&unk_38D56, "syna_cdev_process_reports", a3);
    return (unsigned int)-22;
  }
  v4 = a3;
  v5 = a2;
  if ( !a2 )
  {
    printk(&unk_35B39, "syna_cdev_update_fifo", a3);
    v38 = -22;
    goto LABEL_70;
  }
  v6 = *a4;
  v7 = a3 + 3;
  v9 = HIDWORD(qword_31700) & (unsigned int)~(SHIDWORD(qword_31700) >> 31);
  v10 = (unsigned int)(v9 + a3 + 3);
  v11 = syna_request_managed_device(a1);
  if ( !v11 )
  {
    v43 = &unk_3BE43;
LABEL_64:
    printk(v43, "syna_pal_mem_alloc", v12);
    goto LABEL_65;
  }
  if ( (int)v10 < 1 )
  {
    v43 = &unk_38286;
    goto LABEL_64;
  }
  v13 = devm_kmalloc(v11, (unsigned int)(v9 + v7), 3520);
  if ( !v13 )
  {
LABEL_65:
    printk(&unk_35592, "syna_cdev_update_fifo", (unsigned int)v10);
LABEL_69:
    v38 = -12;
    goto LABEL_70;
  }
  v16 = HIDWORD(qword_31700);
  v17 = (_BYTE *)v13;
  if ( SHIDWORD(qword_31700) < 1 )
  {
    v16 = 0;
    src = nullptr;
  }
  else
  {
    v18 = syna_request_managed_device(v13);
    if ( !v18 )
    {
      v44 = printk(&unk_3BE43, "syna_pal_mem_alloc", v19);
      v20 = syna_request_managed_device(v44);
      if ( !v20 )
        goto LABEL_10;
      goto LABEL_67;
    }
    src = (_BYTE *)devm_kmalloc(v18, v16, 3520);
    if ( !src )
    {
      v20 = syna_request_managed_device(0);
      if ( !v20 )
      {
LABEL_10:
        printk(&unk_3BE43, "syna_pal_mem_free", v21);
LABEL_68:
        printk(&unk_3CBD2, "syna_cdev_update_fifo", HIDWORD(qword_31700));
        goto LABEL_69;
      }
LABEL_67:
      devm_kfree(v20, v17);
      goto LABEL_68;
    }
  }
  *v17 = v50;
  if ( (_DWORD)v10 == 1 )
    goto LABEL_80;
  v17[1] = v4;
  if ( (_DWORD)v10 == 2 )
    goto LABEL_80;
  v17[2] = BYTE1(v4);
  if ( !v4 )
    goto LABEL_19;
  if ( v17 == (_BYTE *)-3LL )
  {
LABEL_73:
    v36 = printk(&unk_33CFA, "syna_cdev_update_fifo", v4);
    v38 = -22;
    v37 = 1;
    goto LABEL_54;
  }
  if ( (unsigned int)v9 + v4 < v4 )
  {
    printk(&unk_3944E, "syna_pal_mem_cpy", v4);
    goto LABEL_73;
  }
  v15 = v4;
  v14 = v10 - 3;
  if ( v10 - 3 < v4 )
    goto LABEL_81;
  memcpy(v17 + 3, v5, v4);
LABEL_19:
  if ( SHIDWORD(qword_31700) < 2 )
    goto LABEL_33;
  if ( !v16 )
    goto LABEL_80;
  v22 = *(_WORD *)(v6 + 898);
  v5 = src;
  *src = v22;
  if ( v16 == 1 )
    goto LABEL_80;
  src[1] = HIBYTE(v22);
  v15 = HIDWORD(qword_31700);
  if ( WORD2(qword_31700) != 2 )
  {
    if ( v16 != 2 )
    {
      src[2] = *(_BYTE *)(v6 + 901);
      v15 = HIDWORD(qword_31700);
      goto LABEL_25;
    }
LABEL_80:
    __break(1u);
    goto LABEL_81;
  }
LABEL_25:
  if ( &v17[v7] && src )
  {
    if ( (unsigned int)v15 <= (unsigned int)v9 )
    {
      v15 = (unsigned int)v15;
      if ( v7 <= (unsigned int)v10 )
        v14 = v10 - v7;
      else
        v14 = 0;
      if ( v14 >= (unsigned int)v15 )
      {
        memcpy(&v17[v7], src, (unsigned int)v15);
LABEL_33:
        v5 = (_QWORD *)a4[78];
        mutex_lock(&qword_316D0);
        v24 = *((_DWORD *)a4 + 316);
        if ( v24 < 0x4B0 )
        {
          if ( syna_cdev_push_data_to_fifo_pre_remaining_frames >= 1200 )
          {
            printk(&unk_37E9C, "syna_cdev_push_data_to_fifo", v23);
            syna_cdev_push_data_to_fifo_pre_remaining_frames = *((_DWORD *)a4 + 316);
          }
        }
        else
        {
          if ( v24 != syna_cdev_push_data_to_fifo_pre_remaining_frames )
            printk(&unk_341DE, "syna_cdev_push_data_to_fifo", v23);
          v25 = (_QWORD *)a4[159];
          v26 = (_QWORD *)v25[1];
          if ( (_QWORD *)*v26 == v25 && (v27 = *v25, *(_QWORD **)(*v25 + 8LL) == v25) )
          {
            *(_QWORD *)(v27 + 8) = v26;
            *v26 = v27;
          }
          else
          {
            _list_del_entry_valid_or_report(a4[159]);
          }
          v28 = v25[2];
          *v25 = 0xDEAD000000000100LL;
          v25[1] = 0xDEAD000000000122LL;
          kfree(v28);
          kfree(v25);
          syna_cdev_push_data_to_fifo_pre_remaining_frames = *((_DWORD *)a4 + 316);
          *((_DWORD *)a4 + 316) = syna_cdev_push_data_to_fifo_pre_remaining_frames - 1;
        }
        v9 = _kmalloc_cache_noprof(platform_device_alloc, 3264, 48);
        if ( v9 )
        {
          v30 = (void *)_kmalloc_noprof(v10, 3264);
          *(_QWORD *)(v9 + 16) = v30;
          if ( v30 )
          {
            *(_DWORD *)(v9 + 24) = v10;
            memcpy(v30, v17, v10);
            ktime_get_real_ts64(v9 + 32);
            v31 = a4 + 159;
            v32 = (__int64 *)a4[160];
            if ( (__int64 *)v9 != a4 + 159 && v32 != (__int64 *)v9 && (__int64 *)*v32 == v31 )
            {
              a4[160] = v9;
              *(_QWORD *)v9 = v31;
              *(_QWORD *)(v9 + 8) = v32;
              *v32 = v9;
              goto LABEL_48;
            }
LABEL_82:
            _list_add_valid_or_report(v9, v32);
LABEL_48:
            v33 = *((_DWORD *)a4 + 316) + 1;
            v34 = qword_31708 - 1;
            *((_DWORD *)a4 + 316) = v33;
            if ( v34 < v33 )
            {
              v35 = (_DWORD *)v5[8];
              if ( v35 )
              {
                if ( *(v35 - 1) != 875454897 )
                  __break(0x8228u);
                ((void (__fastcall *)(_QWORD *, _QWORD))v35)(v5 + 1, 0);
              }
            }
            mutex_unlock(&qword_316D0);
            v36 = _wake_up(a4 + 161, 1, 1, 0);
            v37 = 0;
            v38 = 0;
LABEL_54:
            v5 = src;
            v39 = syna_request_managed_device(v36);
            if ( v39 )
              goto LABEL_55;
LABEL_77:
            v47 = printk(&unk_3BE43, "syna_pal_mem_free", v40);
            v41 = syna_request_managed_device(v47);
            if ( v41 )
              goto LABEL_58;
LABEL_78:
            printk(&unk_3BE43, "syna_pal_mem_free", v42);
            if ( v37 )
              goto LABEL_70;
            return 0;
          }
          printk(&unk_31F9D, "syna_cdev_push_data_to_fifo", (unsigned int)v10);
        }
        else
        {
          printk(&unk_35B63, "syna_cdev_push_data_to_fifo", v29);
          printk(&unk_3B1BE, "syna_cdev_push_data_to_fifo", 48);
        }
        mutex_unlock(&qword_316D0);
        v36 = printk(&unk_34D82, "syna_cdev_update_fifo", v48);
        v38 = -12;
        v37 = 1;
        goto LABEL_54;
      }
LABEL_81:
      _fortify_panic(17, v14, v15);
      goto LABEL_82;
    }
    printk(&unk_3944E, "syna_pal_mem_cpy", v15);
  }
  v46 = printk(&unk_377AA, "syna_cdev_update_fifo", v15);
  v38 = -22;
  v37 = 1;
  v39 = syna_request_managed_device(v46);
  if ( !v39 )
    goto LABEL_77;
LABEL_55:
  if ( v5 )
    v39 = devm_kfree(v39, v5);
  v41 = syna_request_managed_device(v39);
  if ( !v41 )
    goto LABEL_78;
LABEL_58:
  devm_kfree(v41, v17);
  if ( v37 )
  {
LABEL_70:
    printk(&unk_39968, "syna_cdev_process_reports", v50);
    return v38;
  }
  return 0;
}
