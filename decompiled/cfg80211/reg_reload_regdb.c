__int64 reg_reload_regdb()
{
  __int64 result; // x0
  __int64 v1; // x0
  __int64 v2; // x19
  __int64 v3; // x19
  __int64 v4; // x0
  char v5; // w8
  unsigned int v6; // w19
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = 0;
  result = request_firmware(v7, "regulatory.db", reg_pdev + 16);
  if ( !(_DWORD)result )
  {
    if ( (valid_regdb(*(_QWORD *)((char *)&unk_8 + v7[0]), *(unsigned int *)v7[0]) & 1) != 0 )
    {
      v1 = kmemdup_noprof(*(_QWORD *)(v7[0] + 8LL), *(_QWORD *)v7[0], 3264);
      v2 = v1;
      if ( v1 )
      {
        rtnl_lock(v1);
        if ( regdb && (unsigned __int64)regdb <= 0xFFFFFFFFFFFFF000LL )
          kfree(regdb);
        regdb = v2;
        v3 = cfg80211_regdomain;
        v4 = _kmalloc_cache_noprof(timer_delete, 3520, 64);
        if ( v4 )
        {
          *(_DWORD *)(v4 + 16) = -1;
          *(_BYTE *)(v4 + 28) = *(_BYTE *)(v3 + 20);
          v5 = *(_BYTE *)(v3 + 21);
          *(_QWORD *)(v4 + 20) = 0;
          *(_BYTE *)(v4 + 29) = v5;
          v4 = reg_process_hint();
          v6 = 0;
        }
        else
        {
          v6 = -12;
        }
        rtnl_unlock(v4);
      }
      else
      {
        v6 = -12;
      }
    }
    else
    {
      v6 = -61;
    }
    release_firmware(v7[0]);
    result = v6;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
