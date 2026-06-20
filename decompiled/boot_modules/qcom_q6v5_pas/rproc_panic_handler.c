__int64 __fastcall rproc_panic_handler(__int64 a1)
{
  _QWORD *v1; // x21
  __int64 v3; // x23
  __int64 v4; // x20
  __int64 v5; // x24
  __int64 v6; // x19
  __int64 v8; // x20
  __int64 v9; // x24

  v1 = (_QWORD *)(a1 - 1224);
  if ( a1 != 1224 )
  {
    v3 = 10100001;
    if ( *(_BYTE *)(a1 + 104) == 1 )
    {
      dev_info(*v1, "waking SOCCP from panic path\n");
      if ( (unsigned int)qcom_smem_state_update_bits(*(_QWORD *)(a1 - 16), 1536, 1LL << *(_DWORD *)(a1 + 72)) )
      {
        dev_err(*v1, "failed to update smem bits for D3 to D0\n");
        return 0;
      }
      v8 = *(_QWORD *)(a1 + 88);
      if ( (unsigned int)readl(v8) != 2 )
      {
        v9 = 10100001;
        while ( 1 )
        {
          v9 -= 100001;
          if ( v9 < 0 )
            break;
          _const_udelay(429500);
          __yield();
          if ( (unsigned int)readl(v8) == 2 )
            goto LABEL_3;
        }
        if ( (unsigned int)readl(v8) != 2 )
          dev_err(*v1, "failed to change to D0\n");
      }
    }
LABEL_3:
    v4 = *(_QWORD *)(a1 + 88);
    if ( (unsigned int)readl(v4) != 2 )
    {
      v5 = 10100001;
      while ( 1 )
      {
        v5 -= 100001;
        if ( v5 < 0 )
          break;
        _const_udelay(429500);
        __yield();
        if ( (unsigned int)readl(v4) == 2 )
          goto LABEL_10;
      }
      if ( (unsigned int)readl(v4) != 2 )
        dev_err(*v1, "failed to change to D0\n");
    }
LABEL_10:
    v6 = *(_QWORD *)(a1 + 96);
    while ( (unsigned int)readl(v6) != 1 )
    {
      v3 -= 100001;
      if ( v3 < 0 )
      {
        if ( (unsigned int)readl(v6) != 1 )
          dev_err(*v1, "failed to change to D0\n");
        return 0;
      }
      _const_udelay(429500);
      __yield();
    }
  }
  return 0;
}
