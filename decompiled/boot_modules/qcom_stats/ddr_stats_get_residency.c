__int64 __fastcall ddr_stats_get_residency(int a1, __int64 a2)
{
  __int64 result; // x0
  int v4; // w21
  __int64 v6; // x9
  __int64 v7; // x8
  int v8; // w10
  __int64 v9; // x11
  unsigned int v10; // w19
  unsigned int v11; // [xsp+4h] [xbp-28Ch] BYREF
  _BYTE s[640]; // [xsp+8h] [xbp-288h] BYREF
  __int64 v13; // [xsp+288h] [xbp-8h]

  result = 4294967274LL;
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a1 & 0x80000000) == 0 && a2 )
  {
    if ( drv && *(_QWORD *)(drv + 240) && *(_BYTE *)(*(_QWORD *)(drv + 8) + 35LL) == 1 )
    {
      v4 = a1;
      while ( ktime_get_with_offset(1) < *(_QWORD *)(drv + 248) )
        _const_udelay(2147500);
      memset(s, 0, sizeof(s));
      v11 = 0;
      mutex_lock(drv + 192);
      qcom_stats_fill_ddr_stats(*(_QWORD *)drv + *(_QWORD *)(*(_QWORD *)(drv + 8) + 8LL), s, &v11);
      if ( v11 )
      {
        v6 = 32LL * v11;
        v7 = 0;
        v8 = 0;
        while ( 1 )
        {
          if ( v7 == 640 )
            goto LABEL_24;
          if ( (*(_DWORD *)&s[v7] & 0xFF00) == 0x100 )
          {
            if ( (unsigned __int64)(v7 + 4) > 0x280 )
              goto LABEL_23;
            if ( *(_DWORD *)&s[v7 + 4] )
            {
              v9 = a2 + 16LL * v8;
              *(_DWORD *)v9 = HIWORD(*(_DWORD *)&s[v7]);
              if ( (unsigned __int64)(v7 + 24) > 0x280 )
              {
LABEL_23:
                __break(1u);
LABEL_24:
                __break(0x5512u);
              }
              ++v8;
              *(_QWORD *)(v9 + 8) = *(_QWORD *)&s[v7 + 24];
              if ( v8 > v4 )
                goto LABEL_22;
            }
          }
          v7 += 32;
          if ( v6 == v7 )
            goto LABEL_22;
        }
      }
      v8 = 0;
LABEL_22:
      v10 = v8;
      mutex_unlock(drv + 192);
      result = v10;
    }
    else
    {
      result = 4294967277LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
