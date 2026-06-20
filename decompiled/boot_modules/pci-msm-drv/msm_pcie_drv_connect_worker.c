__int64 __fastcall msm_pcie_drv_connect_worker(__int64 result)
{
  _BYTE *v1; // x20
  __int64 v2; // x19

  if ( qword_30CB0 )
  {
    v1 = *(_BYTE **)(result - 72);
    v2 = result;
    if ( v1 )
    {
      if ( (*v1 & 1) == 0 )
      {
        result = msm_pcie_notify_client(result - 1864, 16);
        if ( (result & 1) != 0 )
        {
          mutex_lock(v2 + 40);
          *v1 = 1;
          if ( *(_DWORD *)(v2 + 32) )
            queue_work_on(32, mpcie_wq, v2 - 32);
          return mutex_unlock(v2 + 40);
        }
      }
    }
  }
  return result;
}
