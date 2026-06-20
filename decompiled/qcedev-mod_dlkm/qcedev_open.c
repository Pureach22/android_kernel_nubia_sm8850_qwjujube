__int64 __fastcall qcedev_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  int *v5; // x20
  int v6; // w9
  __int64 v7; // x2
  int **v8; // x0
  int **v9; // x19
  unsigned __int64 StatusReg; // x21
  __int64 v12; // x22
  void *(*v13)(void *, const void *, size_t); // x0

  v6 = *(_DWORD *)(a1 + 76);
  v7 = *(_QWORD *)&v6 & 0xFFFFFLL;
  if ( dword_F28 != (v6 & 0xFFFFF) )
    goto LABEL_6;
  if ( (unsigned int)v7 <= 1 )
  {
    v5 = &qce_dev[86 * (unsigned int)v7];
    if ( v5 )
    {
      v4 = a2;
      v8 = (int **)_kmalloc_cache_noprof(memmove, 3520, 264);
      if ( v8 )
      {
LABEL_5:
        *v8 = v5;
        *(_QWORD *)(v4 + 32) = v8;
        v9 = v8;
        qcedev_ce_high_bw_req(v5, 1);
        _mutex_init(v9 + 27, "&handle->registeredbufs.lock", &qcedev_open___key);
        v9[25] = (int *)(v9 + 25);
        v9[26] = (int *)(v9 + 25);
        return 0;
      }
      return 4294967284LL;
    }
LABEL_6:
    printk(&unk_12CB8, "qcedev_open", v7, a4);
    return 4294967294LL;
  }
  __break(0x5512u);
  StatusReg = _ReadStatusReg(SP_EL0);
  v12 = *(_QWORD *)(StatusReg + 80);
  v13 = memmove;
  *(_QWORD *)(StatusReg + 80) = &qcedev_open__alloc_tag;
  v8 = (int **)_kmalloc_cache_noprof(v13, 3520, 264);
  *(_QWORD *)(StatusReg + 80) = v12;
  if ( v8 )
    goto LABEL_5;
  return 4294967284LL;
}
