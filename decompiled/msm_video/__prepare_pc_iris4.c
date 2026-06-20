__int64 __fastcall _prepare_pc_iris4(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x4
  int v4; // w20
  __int64 v5; // x4
  int v6; // w8
  unsigned int v7; // w0
  __int64 v8; // x4
  void *v9; // x0
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  result = _read_register(a1, 0xA004Cu, v10);
  if ( (_DWORD)result )
    goto LABEL_12;
  v4 = v10[0];
  if ( (v10[0] & 0x100) == 0 )
  {
    result = _read_register(a1, 0xC0010u, (_DWORD *)v10 + 1);
    if ( (_DWORD)result )
      goto LABEL_12;
    v6 = BYTE4(v10[0]) & 1;
    HIDWORD(v10[0]) = v6;
    if ( (v4 & 0x40000000) == 0 || !v6 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_95F3F, "err ", 0xFFFFFFFFLL, "codec", v5);
      goto LABEL_15;
    }
    v7 = _prepare_pc(a1);
    if ( v7 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_83F26, "err ", 0xFFFFFFFFLL, "codec", v7);
      goto LABEL_15;
    }
    if ( (unsigned int)_read_register_with_poll_timeout(a1, 0xA004Cu, 256, 256, 0xFAu, 0x9C4u) )
    {
      if ( (msm_vidc_debug & 1) == 0 )
      {
LABEL_15:
        result = _read_register(a1, 0xA004Cu, v10);
        if ( !(_DWORD)result )
        {
          result = _read_register(a1, 0xC0010u, (_DWORD *)v10 + 1);
          if ( !(_DWORD)result )
          {
            v8 = BYTE4(v10[0]) & 1;
            HIDWORD(v10[0]) = BYTE4(v10[0]) & 1;
            if ( (msm_vidc_debug & 1) != 0 )
              printk(&unk_8ECDF, "err ", 0xFFFFFFFFLL, "codec", v8);
            result = 4294967285LL;
          }
        }
        goto LABEL_12;
      }
      v9 = &unk_969E0;
    }
    else
    {
      result = _read_register_with_poll_timeout(a1, 0xC0010u, 1, 1, 0xFAu, 0x9C4u);
      if ( !(_DWORD)result )
        goto LABEL_12;
      if ( (msm_vidc_debug & 1) == 0 )
        goto LABEL_15;
      v9 = &unk_8B002;
    }
    printk(v9, "err ", 0xFFFFFFFFLL, "codec", "__prepare_pc_iris4");
    goto LABEL_15;
  }
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_82971, "high", 0xFFFFFFFFLL, "codec", v3);
  result = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
