__int64 __fastcall dummy_source_enable(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned __int8 *v3; // x23
  __int64 result; // x0
  unsigned __int64 v11; // x9
  unsigned int v13; // w0
  unsigned int v14; // w19
  __int64 *v15; // x8
  __int64 v16; // x9
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 v19; // x20
  unsigned int v20; // w24
  __int64 v21; // x21
  char *v22; // x22
  size_t v23; // x0
  unsigned __int64 v24; // x2
  unsigned __int8 v25; // w8
  unsigned int v26; // w20
  unsigned __int64 StatusReg; // x22
  __int64 v28; // x25
  __int64 (__fastcall *v29)(_QWORD, _QWORD, _QWORD); // x0
  char *string[2]; // [xsp+0h] [xbp-10h] BYREF

  string[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned __int8 **)(*(_QWORD *)(a1 + 152) + 152LL);
  _X11 = (unsigned __int64 *)(a1 + 968);
  __asm { PRFM            #0x11, [X11] }
  while ( 1 )
  {
    v11 = __ldxr(_X11);
    if ( v11 )
      break;
    if ( !__stlxr(a3, _X11) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( v11 )
  {
    result = 4294967280LL;
  }
  else
  {
    if ( (v3[17] & 1) == 0 )
    {
      result = coresight_trace_id_get_system_id();
      if ( (result & 0x80000000) != 0 )
      {
        *(_QWORD *)(a1 + 968) = 0;
        goto LABEL_29;
      }
      v15 = *((__int64 **)v3 + 1);
      v3[16] = result;
      v16 = *v15;
      v17 = *(unsigned int *)(*v15 + 4);
      if ( (int)v17 < 1 )
      {
LABEL_17:
        v19 = 0;
      }
      else
      {
        v18 = *(_QWORD *)(v16 + 8);
        while ( 1 )
        {
          v19 = *(_QWORD *)(*(_QWORD *)v18 + 16LL);
          if ( v19 )
          {
            if ( *(_DWORD *)(v19 + 8) == 4 )
              break;
          }
          --v17;
          v18 += 8;
          if ( !v17 )
            goto LABEL_17;
        }
      }
      string[0] = nullptr;
      v20 = result;
      if ( !(unsigned int)of_property_read_string(*(_QWORD *)(*(_QWORD *)v3 + 744LL), "trace-name", string) )
      {
        v21 = _kmalloc_cache_noprof(_fortify_panic, 3520, 34);
        if ( !v21 )
        {
LABEL_33:
          v26 = -12;
          goto LABEL_34;
        }
        while ( 1 )
        {
          v22 = string[0];
          v23 = strnlen(string[0], 0x19u);
          if ( v23 == -1 )
          {
            _fortify_panic(2, -1, 0);
          }
          else
          {
            if ( v23 == 25 )
              v24 = 25;
            else
              v24 = v23 + 1;
            if ( v24 < 0x1A )
            {
              sized_strscpy(v21, v22);
              v25 = v3[16];
              *(_BYTE *)(v21 + 33) = 1;
              *(_BYTE *)(v21 + 25) = v25;
              if ( !v19 || (v26 = coresight_qmi_assign_atid(v19, v21)) == 0 )
              {
LABEL_27:
                coresight_csr_set_etr_atid(a1, v3[16], 1, 0);
                result = 0;
                goto LABEL_29;
              }
LABEL_34:
              coresight_trace_id_put_system_id(v20);
              *(_QWORD *)(a1 + 968) = 0;
              dev_err(*(_QWORD *)v3, "Assign dummy source atid fail\n");
              result = v26;
              goto LABEL_29;
            }
          }
          _fortify_panic(7, 25, v24);
          StatusReg = _ReadStatusReg(SP_EL0);
          v28 = *(_QWORD *)(StatusReg + 80);
          v29 = _fortify_panic;
          *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
          v21 = _kmalloc_cache_noprof(v29, 3520, 34);
          *(_QWORD *)(StatusReg + 80) = v28;
          if ( !v21 )
            goto LABEL_33;
        }
      }
      v26 = -22;
      goto LABEL_34;
    }
    v13 = coresight_trace_id_reserve_id(v3[16]);
    if ( !v13 )
      goto LABEL_27;
    *(_QWORD *)(a1 + 968) = 0;
    v14 = v13;
    dev_err(*(_QWORD *)v3, "Reserve atid: %d fail\n", v3[16]);
    result = v14;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
