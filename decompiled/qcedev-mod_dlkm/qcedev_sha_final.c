__int64 __fastcall qcedev_sha_final(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  char v4; // w8
  size_t v5; // x23
  size_t v8; // x21
  void *v9; // x22
  unsigned int v10; // w0
  unsigned int v11; // w23
  __int64 result; // x0
  _QWORD v13[5]; // [xsp+8h] [xbp-28h] BYREF

  v13[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_BYTE *)(a2 + 194);
  memset(v13, 0, 32);
  if ( (v4 & 1) != 0 )
  {
    v5 = *(unsigned int *)(a2 + 124);
    v8 = (unsigned int)(v5 + 128);
    *(_BYTE *)(a2 + 129) = 1;
    v9 = (void *)_kmalloc_noprof(v8, 3264);
    if ( v9 )
    {
      memcpy((void *)(((unsigned __int64)v9 + 63) & 0xFFFFFFFFFFFFFFC0LL), (const void *)(a2 + 60), v5);
      *(_QWORD *)(a1 + 872) = v13;
      sg_init_one(v13, ((unsigned __int64)v9 + 63) & 0xFFFFFFFFFFFFFFC0LL, (unsigned int)v5);
      *(_DWORD *)(a1 + 864) = v5;
      v10 = submit_req((__int64 *)a1, (__int64 *)a2);
      *(_WORD *)(a2 + 128) = 0;
      *(_QWORD *)(a2 + 8) = 0;
      *(_DWORD *)(a2 + 124) = 0;
      *(_BYTE *)(a2 + 194) = 0;
      *(_QWORD *)(a2 + 60) = 0;
      *(_QWORD *)(a2 + 68) = 0;
      *(_QWORD *)(a2 + 76) = 0;
      *(_QWORD *)(a2 + 84) = 0;
      *(_QWORD *)(a2 + 92) = 0;
      *(_QWORD *)(a2 + 100) = 0;
      *(_QWORD *)(a2 + 108) = 0;
      *(_QWORD *)(a2 + 116) = 0;
      v11 = v10;
      memset(v9, 0, v8);
      kfree(v9);
      result = v11;
      *(_QWORD *)(a1 + 872) = 0;
    }
    else
    {
      result = 4294967284LL;
    }
  }
  else
  {
    printk(&unk_1260A, "qcedev_sha_final", a3, a4);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
