__int64 __fastcall msm_cvp_print_frpc_bufs(__int64 result, int a2, char a3)
{
  __int64 v3; // x8
  __int64 v4; // x20
  _QWORD **v5; // x24
  _QWORD *i; // x22
  const char *v9; // x8
  unsigned __int64 v10; // x21
  __int64 v11; // x25
  unsigned __int64 v12; // x24
  __int64 v13; // x26
  size_t v14; // x0
  unsigned __int64 v15; // x2
  _BOOL4 v17; // w8
  __int64 v18; // x1
  __int64 v19; // x2
  void *v20; // x0
  const char *v21; // x1
  __int64 v22; // x3
  void *v23; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x8
  const char *v27; // [xsp+38h] [xbp-58h]
  unsigned int v28; // [xsp+44h] [xbp-4Ch]
  _QWORD v29[9]; // [xsp+48h] [xbp-48h] BYREF

  v29[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(cvp_driver + 48);
  strcpy((char *)v29, "Unknown");
  memset(&v29[1], 0, 56);
  if ( v3 )
  {
    v4 = result;
    v5 = (_QWORD **)(result + 360);
    mutex_lock(result + 376);
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_859B8, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
    for ( i = *v5; i != v5; i = (_QWORD *)*i )
      ((void (__fastcall *)(_QWORD *, __int64, _QWORD, _QWORD, _QWORD))msm_cvp_print_dsp_buf_info)(
        i,
        v4,
        *(_QWORD *)(cvp_driver + 48),
        (unsigned int)a2,
        a3 & 1);
    result = mutex_unlock(v4 + 376);
    if ( (a3 & 1) == 0 )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v26 = _ReadStatusReg(SP_EL0);
        result = printk(&unk_903D7, *(unsigned int *)(v26 + 1800), *(unsigned int *)(v26 + 1804), &unk_8E7CE);
        if ( *(_DWORD *)(v4 + 432) )
          goto LABEL_11;
      }
      else if ( *(_DWORD *)(v4 + 432) )
      {
LABEL_11:
        v9 = "warn";
        if ( a2 != 2 )
          v9 = (const char *)&unk_8E085;
        v10 = 0;
        v11 = v4 + 440;
        if ( a2 == 1 )
          v9 = (const char *)&unk_8E7CE;
        v28 = a2 - 1;
        v27 = v9;
        v12 = _ReadStatusReg(SP_EL0);
        do
        {
          if ( v10 == 41 )
          {
            __break(0x5512u);
LABEL_129:
            _fortify_panic(2);
LABEL_130:
            _fortify_panic(7);
          }
          if ( v11 && *(_QWORD *)(v11 + 48) )
          {
            result = get_pkt_index_from_type(*(unsigned int *)(v11 + 92));
            if ( (int)result >= 1 )
            {
              v13 = cvp_hfi_defs + 84LL * (unsigned int)result;
              v14 = strnlen((const char *)(v13 + 16), 0x40u);
              if ( v14 >= 0x41 )
                goto LABEL_129;
              if ( v14 == 64 )
                v15 = 64;
              else
                v15 = v14 + 1;
              if ( v15 >= 0x41 )
                goto LABEL_130;
              result = sized_strscpy(v29, v13 + 16);
            }
            v17 = (msm_cvp_debug & a2) != 0 && msm_cvp_debug_out == 0;
            if ( *(_DWORD *)(v11 + 40) )
            {
              if ( v17 )
              {
                if ( v28 > 1 )
                {
                  if ( a2 > 1023 )
                  {
                    if ( a2 >= 0x4000 )
                    {
                      if ( a2 > 61415 )
                      {
                        if ( a2 == 61416 )
                        {
                          v21 = (const char *)&unk_94624;
                          goto LABEL_111;
                        }
                        if ( a2 == 0x20000 )
                        {
                          v21 = "perf";
                          goto LABEL_111;
                        }
                      }
                      else
                      {
                        if ( a2 == 0x4000 )
                        {
                          v21 = "hfi";
                          goto LABEL_111;
                        }
                        if ( a2 == 0x8000 )
                        {
                          v21 = (const char *)&unk_85102;
                          goto LABEL_111;
                        }
                      }
                    }
                    else if ( a2 > 4095 )
                    {
                      if ( a2 == 4096 )
                      {
                        v21 = "fw";
                        goto LABEL_111;
                      }
                      if ( a2 == 0x2000 )
                      {
                        v21 = "sess";
                        goto LABEL_111;
                      }
                    }
                    else
                    {
                      if ( a2 == 1024 )
                      {
                        v21 = (const char *)&unk_8DA84;
                        goto LABEL_111;
                      }
                      if ( a2 == 2048 )
                      {
                        v21 = "dsp";
                        goto LABEL_111;
                      }
                    }
                  }
                  else if ( a2 > 63 )
                  {
                    if ( a2 > 255 )
                    {
                      if ( a2 == 256 )
                      {
                        v21 = "core";
                        goto LABEL_111;
                      }
                      if ( a2 == 512 )
                      {
                        v21 = (const char *)&unk_8425A;
                        goto LABEL_111;
                      }
                    }
                    else
                    {
                      if ( a2 == 64 )
                      {
                        v21 = (const char *)&unk_84256;
                        goto LABEL_111;
                      }
                      if ( a2 == 128 )
                      {
                        v21 = "synx";
                        goto LABEL_111;
                      }
                    }
                  }
                  else if ( a2 > 15 )
                  {
                    if ( a2 == 16 )
                    {
                      v21 = "prof";
                      goto LABEL_111;
                    }
                    if ( a2 == 32 )
                    {
                      v21 = (const char *)&unk_96215;
                      goto LABEL_111;
                    }
                  }
                  else
                  {
                    v21 = "info";
                    if ( a2 == 4 )
                    {
LABEL_111:
                      v22 = *(_QWORD *)(v11 + 48);
                      v23 = &unk_90BCA;
                      goto LABEL_121;
                    }
                    if ( a2 == 8 )
                    {
                      v21 = "cmd";
                      goto LABEL_111;
                    }
                  }
                  v21 = (const char *)&unk_8E085;
                  goto LABEL_111;
                }
                v18 = *(unsigned int *)(v12 + 1800);
                v19 = *(unsigned int *)(v12 + 1804);
                v20 = &unk_966CC;
                goto LABEL_40;
              }
            }
            else if ( v17 )
            {
              if ( v28 > 1 )
              {
                if ( a2 > 1023 )
                {
                  if ( a2 >= 0x4000 )
                  {
                    if ( a2 > 61415 )
                    {
                      if ( a2 == 61416 )
                      {
                        v21 = (const char *)&unk_94624;
                      }
                      else
                      {
                        if ( a2 != 0x20000 )
                          goto LABEL_119;
                        v21 = "perf";
                      }
                    }
                    else if ( a2 == 0x4000 )
                    {
                      v21 = "hfi";
                    }
                    else
                    {
                      if ( a2 != 0x8000 )
                        goto LABEL_119;
                      v21 = (const char *)&unk_85102;
                    }
                  }
                  else if ( a2 > 4095 )
                  {
                    if ( a2 == 4096 )
                    {
                      v21 = "fw";
                    }
                    else
                    {
                      if ( a2 != 0x2000 )
                        goto LABEL_119;
                      v21 = "sess";
                    }
                  }
                  else if ( a2 == 1024 )
                  {
                    v21 = (const char *)&unk_8DA84;
                  }
                  else
                  {
                    if ( a2 != 2048 )
                      goto LABEL_119;
                    v21 = "dsp";
                  }
                }
                else if ( a2 > 63 )
                {
                  if ( a2 > 255 )
                  {
                    if ( a2 == 256 )
                    {
                      v21 = "core";
                    }
                    else
                    {
                      if ( a2 != 512 )
                        goto LABEL_119;
                      v21 = (const char *)&unk_8425A;
                    }
                  }
                  else if ( a2 == 64 )
                  {
                    v21 = (const char *)&unk_84256;
                  }
                  else
                  {
                    if ( a2 != 128 )
                      goto LABEL_119;
                    v21 = "synx";
                  }
                }
                else if ( a2 > 15 )
                {
                  if ( a2 == 16 )
                  {
                    v21 = "prof";
                  }
                  else
                  {
                    if ( a2 != 32 )
                      goto LABEL_119;
                    v21 = (const char *)&unk_96215;
                  }
                }
                else
                {
                  v21 = "info";
                  if ( a2 == 4 )
                    goto LABEL_120;
                  if ( a2 == 8 )
                  {
                    v21 = "cmd";
                    goto LABEL_120;
                  }
LABEL_119:
                  v21 = (const char *)&unk_8E085;
                }
LABEL_120:
                v22 = *(_QWORD *)(v11 + 48);
                v23 = &unk_92471;
LABEL_121:
                result = printk(v23, v21, "PD mapping", v22);
                goto LABEL_17;
              }
              v18 = *(unsigned int *)(v12 + 1800);
              v19 = *(unsigned int *)(v12 + 1804);
              v20 = &unk_9176C;
LABEL_40:
              result = printk(v20, v18, v19, v27);
            }
          }
LABEL_17:
          ++v10;
          v11 += 152;
        }
        while ( v10 < *(unsigned int *)(v4 + 432) );
      }
    }
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v25 = _ReadStatusReg(SP_EL0);
    result = printk(&unk_8276F, *(unsigned int *)(v25 + 1800), *(unsigned int *)(v25 + 1804), &unk_8E7CE);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
