__int64 __fastcall print_client_buffer(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  const char *v4; // x9
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x1
  unsigned int v7; // w8
  const char *v8; // x3
  __int64 v9; // x8
  const char *v10; // x1

  if ( !a4 || !a3 || !a2 || (msm_cvp_debug & (unsigned int)result) == 0 || msm_cvp_debug_out )
    return result;
  if ( (unsigned int)(result - 1) > 1 )
  {
    if ( (int)result > 1023 )
    {
      if ( (int)result >= 0x4000 )
      {
        if ( (int)result > 61415 )
        {
          if ( (_DWORD)result == 61416 )
          {
            v9 = a2;
            v10 = (const char *)&unk_94624;
            return printk(&unk_8957C, v10, v9, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
          }
          v9 = a2;
          if ( (_DWORD)result == 0x20000 )
          {
            v10 = "perf";
            return printk(&unk_8957C, v10, v9, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
          }
        }
        else
        {
          v9 = a2;
          if ( (_DWORD)result == 0x4000 )
          {
            v10 = "hfi";
            return printk(&unk_8957C, v10, v9, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
          }
          if ( (_DWORD)result == 0x8000 )
          {
            v10 = (const char *)&unk_85102;
            return printk(&unk_8957C, v10, v9, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
          }
        }
      }
      else
      {
        v9 = a2;
        if ( (int)result > 4095 )
        {
          if ( (_DWORD)result == 4096 )
          {
            v10 = "fw";
            return printk(&unk_8957C, v10, v9, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
          }
          if ( (_DWORD)result == 0x2000 )
          {
            v10 = "sess";
            return printk(&unk_8957C, v10, v9, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
          }
        }
        else
        {
          if ( (_DWORD)result == 1024 )
          {
            v10 = (const char *)&unk_8DA84;
            return printk(&unk_8957C, v10, v9, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
          }
          if ( (_DWORD)result == 2048 )
          {
            v10 = "dsp";
            return printk(&unk_8957C, v10, v9, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
          }
        }
      }
    }
    else
    {
      v9 = a2;
      if ( (int)result > 63 )
      {
        if ( (int)result > 255 )
        {
          if ( (_DWORD)result == 256 )
          {
            v10 = "core";
            return printk(&unk_8957C, v10, v9, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
          }
          if ( (_DWORD)result == 512 )
          {
            v10 = (const char *)&unk_8425A;
            return printk(&unk_8957C, v10, v9, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
          }
        }
        else
        {
          if ( (_DWORD)result == 64 )
          {
            v10 = (const char *)&unk_84256;
            return printk(&unk_8957C, v10, v9, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
          }
          if ( (_DWORD)result == 128 )
          {
            v10 = "synx";
            return printk(&unk_8957C, v10, v9, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
          }
        }
      }
      else if ( (int)result > 15 )
      {
        if ( (_DWORD)result == 16 )
        {
          v10 = "prof";
          return printk(&unk_8957C, v10, v9, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
        }
        if ( (_DWORD)result == 32 )
        {
          v10 = (const char *)&unk_96215;
          return printk(&unk_8957C, v10, v9, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
        }
      }
      else
      {
        if ( (_DWORD)result == 4 )
        {
          v10 = "info";
          return printk(&unk_8957C, v10, v9, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
        }
        if ( (_DWORD)result == 8 )
        {
          v10 = "cmd";
          return printk(&unk_8957C, v10, v9, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
        }
      }
    }
    v10 = (const char *)&unk_8E085;
    return printk(&unk_8957C, v10, v9, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
  }
  v4 = (const char *)&unk_8E085;
  StatusReg = _ReadStatusReg(SP_EL0);
  v6 = *(unsigned int *)(StatusReg + 1800);
  v7 = *(_DWORD *)(StatusReg + 1804);
  if ( (_DWORD)result == 2 )
    v4 = "warn";
  if ( (_DWORD)result == 1 )
    v8 = (const char *)&unk_8E7CE;
  else
    v8 = v4;
  return printk(&unk_89FCB, v6, v7, v8);
}
