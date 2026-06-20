__int64 __fastcall gh_rm_mem_append(int a1, unsigned __int8 a2, const void *a3, unsigned int a4)
{
  __int64 result; // x0
  __int64 v7; // x24
  __int64 v10; // x0
  __int64 v11; // x19
  unsigned int v12; // w0
  unsigned int v13; // w20
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v15[2]; // [xsp+10h] [xbp-10h] BYREF

  result = 4294967274LL;
  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 <= 1u && a4 <= 0x200 )
  {
    v7 = 16 * a4;
    v14 = 0;
    v15[0] = 0;
    v10 = _kmalloc_noprof(v7 | 0xC, 3264);
    v11 = v10;
    if ( v10 )
    {
      *(_DWORD *)v10 = a1;
      *(_BYTE *)(v10 + 4) = a2;
      *(_WORD *)(v10 + 8) = a4;
      memcpy((void *)(v10 + 12), a3, 16 * a4);
      v12 = gunyah_rm_call(rm, 1358954520, v11, v7 | 0xC, &v14, v15);
      if ( v12 )
      {
        v13 = v12;
        printk(&unk_12082, "gh_rm_mem_append");
      }
      else if ( v15[0] )
      {
        printk(&unk_1372E, "gh_rm_mem_append");
        kfree(v14);
        v13 = -22;
      }
      else
      {
        v13 = 0;
      }
      kfree(v11);
      result = v13;
    }
    else
    {
      result = 4294967284LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
