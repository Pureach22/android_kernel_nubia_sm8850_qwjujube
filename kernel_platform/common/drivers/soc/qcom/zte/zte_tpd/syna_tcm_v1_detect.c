__int64 __fastcall syna_tcm_v1_detect(__int64 a1, char a2, __int64 a3)
{
  __int64 result; // x0
  char v5; // w22
  _QWORD *v6; // x20
  unsigned int v7; // w21
  void *v8; // x0
  void *v9; // x21
  __int64 v10; // x0
  __int64 v11; // x2
  __int64 v12; // x0
  __int64 v13; // x2
  __int64 v14; // x2
  __int64 v15; // x0
  __int64 (*v16)(void); // x8
  unsigned __int8 *v17; // x21
  unsigned int v18; // w0
  __int64 v19; // x2
  __int64 v20; // x2
  char v21; // w8
  unsigned int v22; // w20
  void *v23; // x0
  __int64 v24; // x2
  char v25; // w8
  int v26; // w8
  unsigned int v27; // w9
  __int64 v28; // x10
  int v29; // w12
  unsigned int v30; // w8
  __int64 v31; // x1
  __int64 v32; // x2
  void *v33; // x0
  int v34; // w21
  __int64 v35; // x2
  __int64 v36; // x2
  char v37; // w8
  const char *v38; // x2
  _BYTE v39[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v40; // [xsp+8h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39[0] = 0;
  if ( !a1 )
  {
    printk(unk_3365A, "syna_tcm_v1_detect", a3);
    result = 4294967055LL;
    goto LABEL_22;
  }
  if ( (a2 & 1) != 0 )
    goto LABEL_3;
  v5 = a3;
  mutex_lock(a1 + 840);
  if ( *(_BYTE *)(a1 + 640) )
    printk(unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 640));
  v6 = (_QWORD *)(a1 + 576);
  mutex_lock(a1 + 592);
  v7 = *(_DWORD *)(a1 + 584);
  v8 = *(void **)(a1 + 576);
  ++*(_BYTE *)(a1 + 640);
  if ( v7 > 0x35 )
  {
LABEL_13:
    memset(v8, 0, v7);
    v15 = *(_QWORD *)(a1 + 72);
    *(_DWORD *)(a1 + 588) = 0;
    if ( v15 )
    {
      v16 = *(__int64 (**)(void))(v15 + 32);
      if ( v16 )
      {
        v17 = *(unsigned __int8 **)(a1 + 576);
        /* CFI check removed */
        v18 = v16();
        if ( (v18 & 0x80000000) == 0 )
        {
          v20 = *(unsigned __int8 *)(a1 + 640);
          if ( (_DWORD)v20 == 1 )
          {
            v21 = 0;
          }
          else
          {
            printk(unk_38244, "syna_tcm_buf_unlock", v20);
            v21 = *(_BYTE *)(a1 + 640) - 1;
          }
          *(_BYTE *)(a1 + 640) = v21;
          mutex_unlock(a1 + 592);
          mutex_unlock(a1 + 840);
          if ( *v17 != 165 )
          {
            result = 4294967051LL;
            goto LABEL_22;
          }
          if ( *(_BYTE *)(a1 + 896) == 1 )
          {
            if ( *(_DWORD *)(a1 + 512) )
            {
              syna_tcm_buf_lock(a1 + 576);
              v26 = *(_DWORD *)(a1 + 512);
              v27 = *(_DWORD *)(a1 + 584);
              if ( v27 > v26 + 5 )
              {
                v28 = *(_QWORD *)(a1 + 576);
                v29 = *(unsigned __int8 *)(a1 + 900);
                *(_WORD *)(a1 + 898) = *(_WORD *)(v28 + (unsigned int)(v26 + 5));
                if ( v29 == 1 )
                {
                  v30 = v26 + 7;
                  if ( v27 >= v30 )
                    *(_BYTE *)(a1 + 901) = *(_BYTE *)(v28 + v30);
                }
                syna_tcm_buf_unlock(a1 + 576);
              }
            }
          }
          if ( *(_WORD *)(a1 + 898) == 23130 )
            *(_BYTE *)(a1 + 896) = 0;
          if ( *(_BYTE *)(a1 + 901) == 90 )
            *(_BYTE *)(a1 + 900) = 0;
          if ( v17[1] == 16
            || ((v5 & 1) == 0 ? (v31 = 2) : (v31 = 4),
                (syna_tcm_v1_write_message(a1, v31, 0, 0, v39, *(unsigned int *)(a1 + 492)) & 0x80000000) == 0) )
          {
            if ( *(_BYTE *)(a1 + 9)
              || (syna_tcm_buf_lock(a1 + 576),
                  v34 = syna_tcm_v1_parse_idinfo(a1, v17 + 4, 52, 48),
                  syna_tcm_buf_unlock(a1 + 576),
                  (v34 & 0x80000000) == 0) )
            {
              if ( (syna_tcm_v1_check_max_rw_size(a1) & 0x80000000) == 0 )
              {
                printk(unk_31A47, "syna_tcm_v1_detect", v32);
                if ( (*(_BYTE *)(a1 + 896) & 1) != 0 || (*(_BYTE *)(a1 + 900) & 1) != 0 )
                {
                  if ( *(_BYTE *)(a1 + 896) )
                    v38 = "yes";
                  else
                    v38 = (const char *)unk_398C0;
                  printk(unk_33DAE, "syna_tcm_v1_detect", v38);
                }
LABEL_3:
                result = 0;
                *(_QWORD *)(a1 + 912) = syna_tcm_v1_read_message;
                *(_QWORD *)(a1 + 920) = syna_tcm_v1_write_message;
                *(_QWORD *)(a1 + 936) = syna_tcm_v1_set_up_max_rw_size;
                *(_QWORD *)(a1 + 944) = syna_tcm_v1_check_max_rw_size;
                *(_QWORD *)(a1 + 928) = syna_tcm_v1_terminate;
                *(_DWORD *)(a1 + 892) = 0;
                *(_BYTE *)(a1 + 8) = 1;
                goto LABEL_22;
              }
              v33 = unk_3C68A;
            }
            else
            {
              v33 = unk_3842E;
            }
          }
          else
          {
            v33 = unk_37F35;
          }
          printk(v33, "syna_tcm_v1_detect", v32);
          result = 4294967054LL;
          goto LABEL_22;
        }
        v22 = v18;
        goto LABEL_28;
      }
      v22 = -245;
      v23 = unk_3617E;
    }
    else
    {
      v22 = -241;
      v23 = unk_37DFA;
    }
    printk(v23, "syna_tcm_read", v14);
LABEL_28:
    printk(unk_38F27, "syna_tcm_v1_detect", v19);
    v24 = *(unsigned __int8 *)(a1 + 640);
    if ( (_DWORD)v24 == 1 )
    {
      v25 = 0;
    }
    else
    {
      printk(unk_38244, "syna_tcm_buf_unlock", v24);
      v25 = *(_BYTE *)(a1 + 640) - 1;
    }
    *(_BYTE *)(a1 + 640) = v25;
    mutex_unlock(a1 + 592);
    mutex_unlock(a1 + 840);
    result = v22;
    goto LABEL_22;
  }
  if ( !v8 )
  {
LABEL_10:
    v12 = syna_request_managed_device();
    if ( v12 )
      goto LABEL_11;
LABEL_56:
    printk(unk_3BE43, "syna_pal_mem_alloc", v13);
    *v6 = 0;
    goto LABEL_57;
  }
  v9 = v8;
  v10 = syna_request_managed_device();
  if ( v10 )
  {
    devm_kfree(v10, v9);
    goto LABEL_10;
  }
  printk(unk_3BE43, "syna_pal_mem_free", v11);
  v12 = syna_request_managed_device();
  if ( !v12 )
    goto LABEL_56;
LABEL_11:
  v7 = 54;
  v8 = (void *)devm_kmalloc(v12, 54, 3520);
  *v6 = v8;
  if ( v8 )
  {
    *(_DWORD *)(a1 + 584) = 54;
    goto LABEL_13;
  }
LABEL_57:
  printk(unk_3703C, "syna_tcm_buf_alloc", 54);
  *(_QWORD *)(a1 + 584) = 0;
  printk(unk_343B9, "syna_tcm_v1_detect", v35);
  v36 = *(unsigned __int8 *)(a1 + 640);
  if ( (_DWORD)v36 == 1 )
  {
    v37 = 0;
  }
  else
  {
    printk(unk_38244, "syna_tcm_buf_unlock", v36);
    v37 = *(_BYTE *)(a1 + 640) - 1;
  }
  *(_BYTE *)(a1 + 640) = v37;
  mutex_unlock(a1 + 592);
  mutex_unlock(a1 + 840);
  result = 4294967053LL;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
