__int64 __fastcall hw_sync_ioctl_reg_client(__int64 a1)
{
  __int64 v1; // x30
  __int64 v2; // x20
  __int64 result; // x0
  __int64 v5; // x2
  __int64 v6; // x3
  unsigned __int64 v7; // x0
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v2 = v1;
  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(result) = get_client_id();
  v9 = result;
  if ( (unsigned __int64)&v9 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( *(_QWORD *)(a1 + 16) )
    {
      printk(&unk_241B9, "hw_sync_ioctl_reg_client", 204, v2, (unsigned int)result);
      result = -22;
    }
    else
    {
      *(_DWORD *)(a1 + 8) = result;
      v7 = msm_hw_fence_register(result, (_QWORD *)(a1 + 24), v5, v6, (unsigned int)result);
      *(_QWORD *)(a1 + 16) = v7;
      if ( v7 > 0xFFFFFFFFFFFFF000LL || v7 == 0 )
        result = -22;
      else
        result = 0;
    }
  }
  else
  {
    result = (int)result;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
