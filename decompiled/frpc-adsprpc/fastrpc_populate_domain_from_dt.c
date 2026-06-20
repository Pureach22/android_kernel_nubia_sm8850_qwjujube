__int64 __fastcall fastrpc_populate_domain_from_dt(__int64 a1, __int64 *a2)
{
  __int64 v4; // x0
  int string; // w0
  const char *v6; // x21
  unsigned int v7; // w0
  unsigned int v8; // w0
  __int64 v9; // x25
  int v10; // w27
  const char *v11; // x23
  int v12; // w24
  unsigned int v13; // w21
  __int64 v14; // x8
  __int64 v15; // x22
  __int64 result; // x0
  unsigned int v17; // w20
  __int64 v18; // x5
  unsigned int v19; // w0
  __int64 v20; // x4
  __int64 v21; // x5
  int *v22; // x8
  int v23; // w9
  int *v24; // x8
  __int64 *v25; // x8
  __int64 v26; // x9
  __int64 v27; // t1
  unsigned int v28; // w20
  unsigned __int64 StatusReg; // x28
  __int64 (__fastcall *v30)(_QWORD); // x0
  __int64 v31; // [xsp+0h] [xbp-20h]
  int v32; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v33; // [xsp+Ch] [xbp-14h] BYREF
  char *s1[2]; // [xsp+10h] [xbp-10h] BYREF

  s1[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 744);
  s1[0] = nullptr;
  v32 = -1;
  v33 = 0;
  string = of_property_read_string(v4, "label", s1);
  if ( (string & 0x80000000) == 0 )
  {
    v6 = s1[0];
    if ( !strcmp(s1[0], "nsp") || !strcmp(v6, "lpass") || !strcmp(v6, "sdsp") )
    {
      v7 = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "dsp-type", &v33, 1, 0);
      if ( (v7 & 0x80000000) != 0 )
      {
        dev_err(a1, "Error %d : %s: dsp-type not specified for %s", v7, "fastrpc_populate_domain_from_dt", s1[0]);
      }
      else
      {
        if ( v33 - 4 <= 0xFFFFFFFC )
        {
          dev_err(
            a1,
            "Error %d: %s: DSP type %u specified in DT is invalid\n",
            -22,
            "fastrpc_populate_domain_from_dt",
            v33);
          result = 4294967274LL;
          goto LABEL_16;
        }
        v8 = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "instance-id", &v32, 1, 0);
        if ( (v8 & 0x80000000) == 0 )
        {
          v10 = v32;
          v9 = v33;
          v11 = s1[0];
          v12 = 1000 * v33;
          v13 = v32 + 1000 * v33;
          mutex_lock(&unk_26CD8);
          v14 = 0;
          while ( 1 )
          {
            v15 = *(_QWORD *)&g_frpc[2 * v14 + 26];
            if ( v15 )
              break;
LABEL_9:
            if ( ++v14 == 256 )
            {
              mutex_unlock(&unk_26CD8);
              v15 = _kmalloc_cache_noprof(_usecs_to_jiffies, 3520, 232);
              if ( v15 )
              {
                while ( 1 )
                {
                  *(_DWORD *)(v15 + 52) = v10;
                  *(_DWORD *)(v15 + 56) = v13;
                  *(_DWORD *)(v15 + 60) = v9;
                  if ( (unsigned int)snprintf((char *)(v15 + 20), 0x1Eu, "%s%d", v11, v13) >= 0x1E )
                  {
                    printk(&unk_24B21, 4294967282LL, "fastrpc_add_domain_to_table", v11, v13, v18);
                    LODWORD(result) = -14;
                    goto LABEL_42;
                  }
                  if ( !v10 || (_DWORD)v9 == 1 && v10 == 1 )
                    *(_BYTE *)(v15 + 51) = 1;
                  v19 = fastrpc_sysfs_domain_create(v15);
                  if ( v19 )
                    break;
                  mutex_lock(&unk_26CD8);
                  if ( (unsigned int)v9 < 5 )
                  {
                    v22 = &g_frpc[v9];
                    v23 = v22[538] + 1;
                    v22[538] = v23;
                    if ( (_DWORD)v9 != 4 )
                    {
                      *(_DWORD *)(v15 + 16) = v23 + v12;
                      v24 = &g_frpc[2 * ((1640531527 * v13) >> 24)];
                      v27 = *((_QWORD *)v24 + 13);
                      v25 = (__int64 *)(v24 + 26);
                      v26 = v27;
                      *(_QWORD *)v15 = v27;
                      if ( v27 )
                        *(_QWORD *)(v26 + 8) = v15;
                      *v25 = v15;
                      *(_QWORD *)(v15 + 8) = v25;
                      mutex_unlock(&unk_26CD8);
                      goto LABEL_15;
                    }
                  }
                  __break(0x5512u);
                  StatusReg = _ReadStatusReg(SP_EL0);
                  v30 = _usecs_to_jiffies;
                  v31 = *(_QWORD *)(StatusReg + 80);
                  *(_QWORD *)(StatusReg + 80) = &fastrpc_add_domain_to_table__alloc_tag;
                  v15 = _kmalloc_cache_noprof(v30, 3520, 232);
                  *(_QWORD *)(StatusReg + 80) = v31;
                  if ( !v15 )
                    goto LABEL_41;
                }
                v28 = v19;
                printk(&unk_2510C, v19, "fastrpc_add_domain_to_table", v15 + 20, v20, v21);
                result = v28;
                if ( (v28 & 0x80000000) == 0 )
                  goto LABEL_16;
              }
              else
              {
LABEL_41:
                LODWORD(result) = -12;
              }
LABEL_42:
              v17 = result;
              dev_err(
                a1,
                "Error %d: %s: failed to add domain %s to table (type %u, instance id %u)",
                result,
                "fastrpc_populate_domain_from_dt",
                s1[0],
                v33,
                v32);
              goto LABEL_18;
            }
          }
          while ( *(_DWORD *)(v15 + 56) != v13 )
          {
            v15 = *(_QWORD *)v15;
            if ( !v15 )
              goto LABEL_9;
          }
          mutex_unlock(&unk_26CD8);
          if ( *(_BYTE *)(v15 + 50) == 1 )
          {
            printk(&unk_24CFE, 22, "fastrpc_add_domain_to_table", v15 + 20, *(unsigned int *)(v15 + 56), 1);
            result = 22;
          }
          else
          {
LABEL_15:
            result = 0;
            *a2 = v15;
          }
          goto LABEL_16;
        }
        dev_err(a1, "Error %d: %s: instance-id not specified for %s\n", v8, "fastrpc_populate_domain_from_dt", s1[0]);
      }
    }
    else
    {
      dev_err(
        a1,
        "Error %d: %s: DSP label %s specified in DT is invalid\n",
        4294967274LL,
        "fastrpc_populate_domain_from_dt",
        v6);
    }
    result = 4294967274LL;
    goto LABEL_16;
  }
  v17 = string;
  dev_err(a1, "Error %d: %s: FastRPC DSP label not specified in DT\n", string, "fastrpc_populate_domain_from_dt");
LABEL_18:
  result = v17;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
