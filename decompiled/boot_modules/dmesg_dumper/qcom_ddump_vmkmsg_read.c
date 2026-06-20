__int64 __fastcall qcom_ddump_vmkmsg_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  _QWORD *v3; // x25
  __int64 v5; // x20
  __int64 v6; // x0
  int v7; // w0
  unsigned __int64 v8; // x19
  __int64 result; // x0
  unsigned __int64 v10; // x8
  unsigned __int64 *v11; // x26
  unsigned __int64 v12; // x27
  unsigned __int64 v13; // x22
  __int64 v14; // x24
  unsigned __int64 v15; // x8
  __int64 v16; // x28
  int v17; // w20
  unsigned int v18; // w23
  const char *v19; // x24
  unsigned __int64 v20; // x19
  unsigned __int64 v21; // x11
  unsigned __int64 *v22; // x10
  __int64 v23; // x11
  bool v24; // cc
  unsigned __int64 v25; // x10
  unsigned __int64 v26; // x9
  unsigned __int64 v27; // x1
  __int64 v28; // x11
  size_t v29; // x2
  _QWORD *v30; // x8
  size_t v31; // x1
  __int64 v32; // x9
  unsigned __int64 v33; // x9
  unsigned __int64 v34; // x10
  __int64 v35; // x0
  unsigned __int64 v36; // x10
  unsigned __int64 v42; // x9
  unsigned __int64 v43; // x8
  unsigned __int64 v45; // x9
  int v46; // w19
  __int64 v47; // x19
  unsigned __int64 StatusReg; // x19
  __int64 v49; // x20
  __int64 v51; // [xsp+10h] [xbp-30h]
  __int64 v52; // [xsp+18h] [xbp-28h] BYREF
  __int64 v53; // [xsp+20h] [xbp-20h] BYREF
  __int128 s; // [xsp+28h] [xbp-18h] BYREF
  __int64 v55; // [xsp+38h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD **)(*(_QWORD *)(a1 + 40) + 696LL);
  if ( *((_BYTE *)v3 + 337) != 1 )
  {
    result = -19;
    goto LABEL_77;
  }
  if ( a3 <= 0x3FF )
  {
    dev_err(*v3, "user buffer size should greater than %d\n", 1024);
    result = -22;
    goto LABEL_77;
  }
  v5 = v3[19];
  if ( *(_BYTE *)(v5 + 145) == 1 && *(_QWORD *)(v5 + 8) < 0x400u )
  {
LABEL_14:
    result = 0;
    goto LABEL_77;
  }
  *(_QWORD *)v5 = a3 >> (*(_BYTE *)(v5 + 144) ^ 1u);
  v6 = v3[26];
  *(_QWORD *)&s = 1;
  v7 = gh_dbl_send(v6, &s, 0);
  if ( v7 )
  {
    v46 = v7;
    dev_err(*v3, "failed to raise virq to the sender %d\n", v7);
    result = v46;
    goto LABEL_77;
  }
  if ( !(unsigned int)wait_for_completion_timeout(v3 + 28, 250) )
  {
    dev_err(*v3, "wait for completion timeout\n");
    result = -110;
    goto LABEL_77;
  }
  v8 = *(_QWORD *)(v5 + 8);
  if ( v8 > a3 )
  {
    dev_err(*v3, "can not read the correct length of svm kmsg\n");
    result = -22;
    goto LABEL_77;
  }
  if ( (*(_BYTE *)(v5 + 144) & 1) == 0 )
  {
    pvm_update_record_time(v3[43], v5 + 16);
    v11 = (unsigned __int64 *)v3[19];
    v10 = v3[20];
    v52 = 0;
    v53 = 0;
    if ( v10 >= *v11 )
      v12 = *v11;
    else
      v12 = v10;
    v13 = 2 * v12;
    v14 = vmalloc_noprof(2 * v12);
    if ( !v14 )
      goto LABEL_76;
LABEL_19:
    v15 = v11[1];
    if ( !v15 )
    {
      v32 = 0;
      goto LABEL_68;
    }
    v51 = v14;
    v16 = 0;
    v17 = 0;
    v18 = 0;
    v19 = (const char *)(v11 + 19);
    s = 0u;
    do
    {
      if ( *((_BYTE *)v11 + v16 + 152) == 10 )
      {
        if ( sscanf(v19, "[%5lu.%06lu]", &v53, &v52) != 2 || (v20 = v17 + v18 + 15, v12 < v20) )
        {
          v14 = v51;
          v32 = -22;
          goto LABEL_68;
        }
        v21 = 1000000000 * v53 + 1000 * v52;
        v22 = (unsigned __int64 *)v3[43];
        if ( v21 >= *v22 )
        {
          if ( v22[2] <= v21 )
          {
            if ( v22[4] <= v21 )
            {
              if ( v22[6] <= v21 )
              {
                if ( v22[8] <= v21 )
                {
                  if ( v22[10] <= v21 )
                  {
                    if ( v22[12] <= v21 )
                    {
                      v24 = v22[14] > v21;
                      v23 = 7;
                      if ( !v24 )
                        v23 = 8;
                    }
                    else
                    {
                      v23 = 6;
                    }
                  }
                  else
                  {
                    v23 = 5;
                  }
                }
                else
                {
                  v23 = 4;
                }
              }
              else
              {
                v23 = 3;
              }
            }
            else
            {
              v23 = 2;
            }
          }
          else
          {
            v23 = 1;
          }
          v25 = v22[2 * v23 - 1];
          v26 = v52 + v25 % 0x3B9ACA00 / 0x3E8;
          snprintf((char *)&s, 0xFu, "[%5lu.%06lu]", v25 / 0x3B9ACA00 + v53 + v26 / 0xF4240, v26 % 0xF4240);
        }
        else
        {
          qmemcpy(&s, "[Invalid Time]", 14);
        }
        if ( v13 >= v18 )
          v27 = v13 - v18;
        else
          v27 = 0;
        if ( v27 <= 0xD )
        {
          _fortify_panic(17);
LABEL_75:
          _fortify_panic(17);
          v13 = 2 * v12;
          StatusReg = _ReadStatusReg(SP_EL0);
          v49 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &vmkmsg_with_pvm_ktime_prefix__alloc_tag;
          v14 = vmalloc_noprof(2 * v12);
          *(_QWORD *)(StatusReg + 80) = v49;
          if ( !v14 )
          {
LABEL_76:
            result = -12;
            goto LABEL_77;
          }
          goto LABEL_19;
        }
        v28 = *(_QWORD *)((char *)&s + 6);
        v29 = (unsigned int)(v17 + 1);
        v30 = (_QWORD *)(v51 + v18);
        if ( v13 >= (unsigned __int64)v18 + 14 )
          v31 = v13 - (v18 + 14LL);
        else
          v31 = 0;
        *v30 = s;
        *(_QWORD *)((char *)v30 + 6) = v28;
        if ( v31 < v29 )
          goto LABEL_75;
        memcpy((char *)v30 + 14, v19, v29);
        v15 = v11[1];
        v17 = 0;
        v19 = (char *)v11 + v16 + 153;
        v18 = v20;
      }
      else
      {
        ++v17;
      }
      ++v16;
    }
    while ( v15 > (int)v16 );
    v32 = -22;
    v14 = v51;
    if ( v18 <= a3 )
      v32 = v18;
    if ( v15 && v18 <= a3 )
    {
      if ( (v18 & 0x80000000) != 0 )
      {
        __break(0x800u);
LABEL_63:
        printk(&unk_7DA6);
        v32 = -14;
        goto LABEL_68;
      }
      _check_object_size(v51, v18, 1);
      v33 = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(v33 + 70) & 0x20) != 0 || (v34 = a2, (*(_QWORD *)v33 & 0x4000000) != 0) )
        v34 = a2 & ((__int64)(a2 << 8) >> 8);
      v35 = v18;
      if ( 0x8000000000LL - (unsigned __int64)v18 >= v34 )
      {
        v36 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v42 = *(_QWORD *)(v33 + 8);
        _WriteStatusReg(TTBR1_EL1, v42 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v42);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v36);
        v35 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v51, v18);
        v43 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v45 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v45 - 4096);
        _WriteStatusReg(TTBR1_EL1, v45);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v43);
      }
      v32 = v18;
      if ( v35 )
        goto LABEL_63;
    }
LABEL_68:
    v47 = v32;
    vfree(v14);
    result = v47;
    goto LABEL_77;
  }
  if ( !v8 )
    goto LABEL_14;
  if ( v8 >> 31 )
  {
    __break(0x800u);
    goto LABEL_72;
  }
  _check_object_size(v5 + 152, *(_QWORD *)(v5 + 8), 1);
  if ( inline_copy_to_user(a2, v5 + 152, v8) )
  {
LABEL_72:
    dev_err(*v3, "copy_to_user fail\n");
    result = -14;
    goto LABEL_77;
  }
  result = *(_QWORD *)(v5 + 8);
LABEL_77:
  _ReadStatusReg(SP_EL0);
  return result;
}
