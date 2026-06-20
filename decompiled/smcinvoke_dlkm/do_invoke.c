__int64 __fastcall do_invoke(const char **a1, unsigned int a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  const char *v9; // x2
  int v10; // w3
  int v11; // w4
  __int64 result; // x0
  __int64 v13; // x19
  __int64 v14; // x23
  const char **v15; // x8
  int v16; // w9
  const char *v17; // x2
  unsigned int v18; // w0
  unsigned int v19; // w20
  const char *v20; // x2
  const char *v21; // x8
  int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  if ( (a2 & 0x8000) != 0 )
  {
    if ( (unsigned __int16)a2 == 0xFFFF )
    {
      put_si_object(a1);
      result = 0;
    }
    else if ( (unsigned __int16)a2 == 65534 )
    {
      get_si_object(a1);
      result = 0;
    }
    else
    {
      result = 4294967198LL;
    }
  }
  else
  {
    v8 = _kmalloc_cache_noprof(bpf_trace_run3, 3520, 1696);
    if ( v8 )
    {
      v13 = v8;
      v14 = _kmalloc_noprof(
              24 * (((unsigned __int8)a4 >> 4) + (a4 & 0xF) + ((a4 >> 8) & 0xF) + ((unsigned __int16)a4 >> 12)) + 24,
              print_fmt_cbo_dispatch_wait,
              v9,
              v10,
              v11);
      v15 = a1;
      if ( v14 )
      {
        if ( a1 )
        {
          if ( a1 == &qword_1 )
          {
            v17 = "root";
          }
          else if ( *a1 )
          {
            v17 = *a1;
          }
          else
          {
            v17 = "noname";
          }
        }
        else
        {
          v17 = "null";
        }
        printk(&unk_1022F, "do_invoke", v17);
        marshal_in(v14, a3, a4);
        v18 = si_object_do_invoke(v13, a1, a2, v14, &v22);
        if ( v18 )
        {
          printk(&unk_105E9, "do_invoke", v18);
          v16 = -96;
          v15 = a1;
        }
        else
        {
          v16 = v22;
          v15 = a1;
          if ( !v22 )
          {
            marshal_out(a3, v14, a4);
            v15 = a1;
            v16 = 0;
          }
        }
      }
      else
      {
        v16 = 97;
      }
      v19 = v16;
      if ( v15 )
      {
        if ( v15 == &qword_1 )
        {
          v20 = "root";
        }
        else
        {
          v21 = *v15;
          if ( v21 )
            v20 = v21;
          else
            v20 = "noname";
        }
      }
      else
      {
        v20 = "null";
      }
      printk(&unk_10B64, "do_invoke", v20);
      kfree(v14);
      kfree(v13);
      result = v19;
    }
    else
    {
      result = 97;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
