__int64 __fastcall msm_pcie_handle_drv_pc_ctrl(__int64 a1, char a2)
{
  _BYTE *v4; // x9

  mutex_lock(a1 + 1904);
  v4 = *(_BYTE **)(a1 + 1792);
  *(_DWORD *)(a1 + 1896) = a2 & 8;
  if ( v4 && *v4 == 1 )
  {
    if ( (a2 & 8) != 0 )
    {
      queue_work_on(32, mpcie_wq, a1 + 1832);
    }
    else
    {
      queue_work_on(32, mpcie_wq, a1 + 1800);
      flush_work(a1 + 1800);
    }
  }
  return mutex_unlock(a1 + 1904);
}
