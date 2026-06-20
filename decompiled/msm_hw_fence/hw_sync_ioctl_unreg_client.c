__int64 __fastcall hw_sync_ioctl_unreg_client(__int64 a1)
{
  __int64 v1; // x30
  __int64 v2; // x19
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x3
  int client_id; // w5
  __int64 result; // x0
  __int64 v9; // x4
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v2 = v1;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  client_id = get_client_id();
  v10 = client_id;
  if ( (unsigned __int64)&v10 < 0xFFFFFFFFFFFFF001LL )
  {
    v9 = *(unsigned int *)(a1 + 8);
    if ( client_id == (_DWORD)v9 )
    {
      result = (int)msm_hw_fence_deregister(*(unsigned int **)(a1 + 16), v4, v5, v6, v9);
    }
    else
    {
      printk(&unk_24209, "hw_sync_ioctl_unreg_client", 224, v2, v9);
      result = -22;
    }
  }
  else
  {
    result = client_id;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
