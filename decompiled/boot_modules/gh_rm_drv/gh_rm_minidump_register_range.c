__int64 __fastcall gh_rm_minidump_register_range(__int64 a1, __int64 a2, const void *a3, size_t a4)
{
  unsigned __int64 v8; // x20
  __int64 v9; // x19
  unsigned int v10; // w0
  unsigned int v11; // w20
  __int64 result; // x0
  unsigned __int64 StatusReg; // x25
  __int64 v14; // x26
  __int64 v15; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v16[2]; // [xsp+10h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
  {
    v8 = a4 + 20;
    v15 = 0;
    v16[0] = 0;
    v9 = _kmalloc_noprof(a4 + 20, 3264);
    if ( v9 )
    {
      while ( 1 )
      {
        if ( v8 >= 8 )
        {
          *(_QWORD *)v9 = a1;
          if ( a4 + 12 >= 8 )
          {
            *(_QWORD *)(v9 + 8) = a2;
            if ( a4 <= 0xFFFFFFFFFFFFFFEBLL && v8 >= 0x10 )
              break;
          }
        }
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v14 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &gh_rm_minidump_register_range__alloc_tag;
        v9 = _kmalloc_noprof(v8, 3264);
        *(_QWORD *)(StatusReg + 80) = v14;
        if ( !v9 )
          goto LABEL_17;
      }
      *(_DWORD *)(v9 + 16) = (unsigned __int8)a4 | (*(unsigned __int16 *)(v9 + 18) << 16) | 0x1C00;
      memcpy((void *)(v9 + 20), a3, a4);
      v10 = gunyah_rm_call(rm, 1442840641, v9, v8, v16, &v15);
      if ( v10 )
      {
        v11 = v10;
        printk(&unk_132B2, "gh_rm_minidump_register_range");
      }
      else if ( v15 == 4 )
      {
        v11 = *(unsigned __int16 *)v16[0];
      }
      else
      {
        printk(&unk_1372E, "gh_rm_minidump_register_range");
        if ( v15 )
          kfree(v16[0]);
        v11 = -22;
      }
      kfree(v9);
      result = v11;
    }
    else
    {
LABEL_17:
      result = 4294967284LL;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
