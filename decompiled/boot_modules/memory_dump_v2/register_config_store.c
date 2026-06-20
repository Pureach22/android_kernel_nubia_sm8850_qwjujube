__int64 __fastcall register_config_store(__int64 a1, int a2, char *s, int a4)
{
  __int64 v6; // x19
  int v7; // w0
  __int64 result; // x0
  unsigned int v9; // w23
  __int64 *v10; // x8
  __int64 v11; // x22
  unsigned int v12; // w0
  int v13; // w9
  _DWORD *v14; // x8
  unsigned int v15; // w10
  unsigned int v16; // w23
  int v17; // w21
  int v19; // w9
  unsigned int v20; // w9
  unsigned int v22; // w10
  unsigned int v23; // w24
  unsigned int v24; // w23
  __int64 v25; // x8
  _BOOL4 v26; // w10
  _BOOL4 v27; // w11
  int v28; // w9
  int v29; // w9
  int v30; // w10
  unsigned __int8 v31; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v32; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v33; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v34; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+18h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v34 = 0;
  v32 = 0;
  v33 = 0;
  v31 = 0;
  v7 = sscanf(s, "%x %x %c %u", &v34, &v33, &v31, &v32);
  if ( v7 >= 2 )
  {
    if ( v7 == 2 )
      v31 = 114;
    if ( v32 <= 1 )
    {
      if ( (v34 & 3) != 0 )
      {
        dev_err(a1, "Invalid address, must be 4 byte aligned\n");
      }
      else
      {
        if ( (v31 | 0x20) != 0x72 )
        {
          v9 = 4;
          goto LABEL_15;
        }
        if ( v33 )
        {
          if ( v31 != 114 || (v33 & 3) == 0 )
          {
            if ( v31 == 82 )
              v9 = 4 * v33;
            else
              v9 = v33;
LABEL_15:
            mutex_lock(v6);
            v10 = *(__int64 **)(v6 + 56);
            v11 = *v10;
            if ( v32 )
            {
              if ( *((_DWORD *)v10 + 4) == *((_DWORD *)v10 + 3) )
              {
                dev_err(a1, "Couldn't add per-core config, out of range\n");
                v17 = -22;
                goto LABEL_53;
              }
              v12 = _sw_hweight64(_cpu_possible_mask);
              v13 = v9 * v12;
              if ( v9 * v12 / v12 >= v9 )
              {
                v14 = *(_DWORD **)(v6 + 56);
                v15 = v14[7];
                v16 = v15 + v13;
                if ( v15 + v13 >= v15 && v16 <= v14[2] )
                {
                  v17 = config_cpuss_register(a1, v11, (unsigned int)v14[5], v31, v34, v33);
                  if ( !v17 )
                  {
                    if ( v33 == 4 && v31 == 114 )
                      v19 = 1;
                    else
                      v19 = 2;
                    *(_DWORD *)(*(_QWORD *)(v6 + 56) + 20LL) += v19;
                    ++*(_DWORD *)(*(_QWORD *)(v6 + 56) + 16LL);
                    *(_DWORD *)(*(_QWORD *)(v6 + 56) + 28LL) = v16;
LABEL_44:
                    v17 = a4;
                    goto LABEL_53;
                  }
                  goto LABEL_53;
                }
              }
              dev_err(a1, "Couldn't add per-core reg config, no enough memory\n");
            }
            else
            {
              v20 = v9 + 8;
              if ( v31 == 114 && v9 == 4 )
                v20 = 8;
              if ( v20 >= v9 )
              {
                v22 = *((_DWORD *)v10 + 7);
                v23 = v20 + v22;
                if ( v20 + v22 >= v22 && v23 <= *((_DWORD *)v10 + 2) )
                {
                  v24 = *(_DWORD *)(v11 + 8) + (*((_DWORD *)v10 + 6) >> 2);
                  v17 = config_cpuss_register(a1, v11, v24, v31, v34, v33);
                  if ( !v17 )
                  {
                    v25 = *(_QWORD *)(v6 + 56);
                    v26 = v31 == 114;
                    v27 = v33 == 4;
                    if ( v26 && v27 )
                      v28 = 4;
                    else
                      v28 = 8;
                    v29 = *(_DWORD *)(v25 + 24) + v28;
                    if ( v26 && v27 )
                      v30 = 1;
                    else
                      v30 = 2;
                    *(_DWORD *)(v25 + 24) = v29;
                    *(_DWORD *)(*(_QWORD *)(v6 + 56) + 28LL) = v23;
                    *(_DWORD *)(v11 + 4LL * (v24 + v30)) = 0;
                    *(_DWORD *)(v11 + 12) = 4 * (v24 + v30) + 4;
                    goto LABEL_44;
                  }
LABEL_53:
                  mutex_unlock(v6);
                  result = v17;
                  goto LABEL_54;
                }
              }
              dev_err(a1, "Couldn't add system reg config, no enough memory\n");
            }
            v17 = -12;
            goto LABEL_53;
          }
          dev_err(a1, "Invalid length, must be 4 byte aligned\n");
        }
        else
        {
          dev_err(a1, "Invalid length of 0\n");
        }
      }
      result = -22;
      goto LABEL_54;
    }
  }
  result = -22;
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
