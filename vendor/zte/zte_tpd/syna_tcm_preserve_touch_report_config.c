__int64 __fastcall syna_tcm_preserve_touch_report_config(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x2
  unsigned int v5; // w20
  _DWORD *v6; // x8
  unsigned int v7; // w0
  __int64 v8; // x2
  __int64 v9; // x2
  size_t v10; // x20
  size_t v11; // x2
  void *v12; // x0
  __int64 v13; // x21
  __int64 v14; // x0
  __int64 v15; // x2
  __int64 v16; // x0
  __int64 v17; // x2
  const void *v18; // x1
  void *v19; // x0
  __int64 v20; // x2
  char v21; // w8
  __int64 v22; // x2
  char v23; // w8
  __int64 v24; // x10
  unsigned int v25; // w15
  unsigned int v26; // w8
  unsigned int v27; // w11
  int v28; // w9
  char v29; // w13
  char v30; // w12
  unsigned int v31; // w16
  __int64 v32; // x14
  int v33; // w17
  unsigned int v34; // w15
  __int64 result; // x0
  void *v36; // x0
  unsigned int v37; // w20
  __int64 v38; // x2
  char v39; // w8
  __int64 v40; // x2
  char v41; // w8
  void *v42; // x0
  __int64 v43; // x2
  __int64 v44; // x2
  char v45; // w8

  if ( !a1 )
  {
    printk(unk_3365A, "syna_tcm_preserve_touch_report_config", a3);
    return 4294967055LL;
  }
  v3 = *(unsigned __int8 *)(a1 + 9);
  if ( (_DWORD)v3 == 1 )
  {
    v5 = a2;
    if ( !a2 )
    {
      if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) != 0 )
      {
        v5 = 0;
      }
      else
      {
        v5 = *(_DWORD *)(a1 + 524);
        printk(unk_3BA3F, "syna_tcm_preserve_touch_report_config", v3);
      }
    }
    v6 = *(_DWORD **)(a1 + 920);
    if ( *(v6 - 1) != 606091918 )
      __break(0x8228u);
    v7 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD))v6)(a1, 37, 0, 0, 0, v5);
    if ( (v7 & 0x80000000) != 0 )
    {
      v37 = v7;
      printk(unk_339F8, "syna_tcm_preserve_touch_report_config", v8);
      result = v37;
      goto LABEL_58;
    }
    v3 = *(unsigned int *)(a1 + 336);
    if ( *(_QWORD *)(a1 + 328) )
    {
      if ( (_DWORD)v3 )
      {
        if ( *(_BYTE *)(a1 + 392) )
          printk(unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 392));
        mutex_lock(a1 + 344);
        v9 = *(unsigned __int8 *)(a1 + 464);
        ++*(_BYTE *)(a1 + 392);
        if ( (_DWORD)v9 )
          printk(unk_38244, "syna_tcm_buf_lock", v9);
        mutex_lock(a1 + 416);
        ++*(_BYTE *)(a1 + 464);
        *(_DWORD *)(a1 + 908) = 1;
        v10 = *(unsigned int *)(a1 + 340);
        v11 = *(unsigned int *)(a1 + 408);
        v12 = *(void **)(a1 + 400);
        if ( (unsigned int)v11 >= (unsigned int)v10 )
        {
LABEL_23:
          memset(v12, 0, v11);
          v18 = *(const void **)(a1 + 328);
          v3 = *(unsigned int *)(a1 + 336);
          *(_DWORD *)(a1 + 412) = 0;
          if ( v18 )
          {
            if ( (_DWORD)v3 )
            {
              v19 = *(void **)(a1 + 400);
              if ( v19 )
              {
                if ( (unsigned int)v10 <= (unsigned int)v3 && (unsigned int)v10 <= *(_DWORD *)(a1 + 408) )
                {
                  memcpy(v19, v18, v10);
                  v20 = *(unsigned __int8 *)(a1 + 464);
                  *(_DWORD *)(a1 + 412) = v10;
                  if ( (_DWORD)v20 == 1 )
                  {
                    v21 = 0;
                  }
                  else
                  {
                    printk(unk_38244, "syna_tcm_buf_unlock", v20);
                    v21 = *(_BYTE *)(a1 + 464) - 1;
                  }
                  *(_BYTE *)(a1 + 464) = v21;
                  mutex_unlock(a1 + 416);
                  v22 = *(unsigned __int8 *)(a1 + 392);
                  if ( (_DWORD)v22 == 1 )
                  {
                    v23 = 0;
                  }
                  else
                  {
                    printk(unk_38244, "syna_tcm_buf_unlock", v22);
                    v23 = *(_BYTE *)(a1 + 392) - 1;
                  }
                  *(_BYTE *)(a1 + 392) = v23;
                  mutex_unlock(a1 + 344);
                  if ( (_DWORD)v10 )
                  {
                    v24 = *(_QWORD *)(a1 + 400);
                    v25 = 0;
                    v26 = 0;
                    v27 = 0;
                    v28 = 0;
                    v29 = 0;
                    v30 = 0;
                    while ( 1 )
                    {
                      v31 = *(unsigned __int8 *)(v24 + v25);
                      v32 = v25 + 1LL;
                      if ( v31 > 2 )
                      {
                        if ( v31 != 3 )
                        {
                          if ( v31 == 4 )
                          {
                            if ( (v30 & 1) != 0 )
                              v27 = (v27 + 7) & 0xFFFFFFF8;
                            if ( (v29 & 1) != 0 )
                            {
                              v29 = 1;
                              v26 = (v26 + 7) & 0xFFFFFFF8;
                            }
                            else
                            {
                              v29 = 0;
                            }
                            goto LABEL_35;
                          }
LABEL_47:
                          v33 = *(unsigned __int8 *)(v24 + v32);
                          LODWORD(v32) = v25 + 2;
                          if ( (v30 & 1) != 0 )
                            v34 = v27 + v33;
                          else
                            v34 = v27;
                          if ( (v29 & 1) != 0 )
                          {
                            v26 += v33;
                            v29 = 1;
                            v27 = v34;
                          }
                          else if ( (v30 & 1) != 0 )
                          {
                            v29 = 0;
                            v30 = 1;
                            v27 += v33;
                          }
                          else
                          {
                            v30 = 0;
                            v29 = 0;
                            v28 += v33;
                          }
                          goto LABEL_35;
                        }
                        v30 = 0;
                        *(_DWORD *)(a1 + 472) = v32;
                        v29 = 1;
                      }
                      else if ( v31 - 1 < 2 )
                      {
                        v30 = 1;
                      }
                      else
                      {
                        if ( *(_BYTE *)(v24 + v25) )
                          goto LABEL_47;
                        v30 = 0;
                        v29 = 0;
                      }
LABEL_35:
                      v25 = v32;
                      if ( (unsigned int)v32 >= (unsigned int)v10 )
                        goto LABEL_57;
                    }
                  }
                  v28 = 0;
                  v27 = 0;
                  v26 = 0;
LABEL_57:
                  result = 0;
                  *(_DWORD *)(a1 + 480) = v28;
                  *(_DWORD *)(a1 + 476) = v27;
                  *(_DWORD *)(a1 + 484) = v26;
                  goto LABEL_58;
                }
                printk(unk_3944E, "syna_pal_mem_cpy", v3);
              }
              printk(unk_35DBE, "syna_tcm_preserve_touch_report_config", v3);
              v38 = *(unsigned __int8 *)(a1 + 464);
              if ( (_DWORD)v38 == 1 )
              {
                v39 = 0;
              }
              else
              {
                printk(unk_38244, "syna_tcm_buf_unlock", v38);
                v39 = *(_BYTE *)(a1 + 464) - 1;
              }
              *(_BYTE *)(a1 + 464) = v39;
              mutex_unlock(a1 + 416);
              v40 = *(unsigned __int8 *)(a1 + 392);
              if ( (_DWORD)v40 == 1 )
              {
                v41 = 0;
              }
              else
              {
                printk(unk_38244, "syna_tcm_buf_unlock", v40);
                v41 = *(_BYTE *)(a1 + 392) - 1;
              }
              *(_BYTE *)(a1 + 392) = v41;
              mutex_unlock(a1 + 344);
              result = 4294967274LL;
LABEL_58:
              *(_DWORD *)(a1 + 908) = 0;
              return result;
            }
            v3 = *(unsigned int *)(a1 + 340);
            v36 = unk_3AE77;
          }
          else
          {
            v36 = unk_3C2AD;
          }
          goto LABEL_65;
        }
        if ( v12 )
        {
          v13 = *(_QWORD *)(a1 + 400);
          v14 = syna_request_managed_device();
          if ( !v14 )
          {
            printk(unk_3BE43, "syna_pal_mem_free", v15);
            v16 = syna_request_managed_device();
            if ( v16 )
              goto LABEL_20;
            goto LABEL_78;
          }
          devm_kfree(v14, v13);
        }
        v16 = syna_request_managed_device();
        if ( v16 )
        {
LABEL_20:
          if ( (int)v10 > 0 )
          {
            v12 = (void *)devm_kmalloc(v16, v10, 3520);
            *(_QWORD *)(a1 + 400) = v12;
            if ( v12 )
            {
              v11 = v10;
              *(_DWORD *)(a1 + 408) = v10;
              goto LABEL_23;
            }
LABEL_80:
            printk(unk_3703C, "syna_tcm_buf_alloc", (unsigned int)v10);
            *(_QWORD *)(a1 + 408) = 0;
            printk(unk_357BB, "syna_tcm_preserve_touch_report_config", v43);
            v44 = *(unsigned __int8 *)(a1 + 392);
            if ( (_DWORD)v44 == 1 )
            {
              v45 = 0;
            }
            else
            {
              printk(unk_38244, "syna_tcm_buf_unlock", v44);
              v45 = *(_BYTE *)(a1 + 392) - 1;
            }
            *(_BYTE *)(a1 + 392) = v45;
            mutex_unlock(a1 + 344);
            result = 4294967053LL;
            goto LABEL_58;
          }
          v42 = unk_38286;
LABEL_79:
          printk(v42, "syna_pal_mem_alloc", v17);
          *(_QWORD *)(a1 + 400) = 0;
          goto LABEL_80;
        }
LABEL_78:
        v42 = unk_3BE43;
        goto LABEL_79;
      }
      v3 = *(unsigned int *)(a1 + 340);
      v36 = unk_34B7A;
    }
    else
    {
      v36 = unk_3BC27;
    }
  }
  else
  {
    v36 = unk_36DD4;
  }
LABEL_65:
  printk(v36, "syna_tcm_preserve_touch_report_config", v3);
  return 4294967055LL;
}
