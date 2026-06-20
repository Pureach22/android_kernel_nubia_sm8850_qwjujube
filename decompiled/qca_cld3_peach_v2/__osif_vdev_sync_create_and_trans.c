__int64 __fastcall _osif_vdev_sync_create_and_trans(__int64 a1, __int64 **a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v6; // w20
  __int64 *v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = nullptr;
  result = osif_vdev_sync_create(a1, v7);
  if ( !(_DWORD)result )
  {
    result = dsc_vdev_trans_start(*(__int64 *)((char *)v7[0] + (unsigned __int64)&qword_8), a3);
    if ( (_DWORD)result )
    {
      v6 = result;
      osif_vdev_sync_destroy(v7[0]);
      result = qdf_status_to_os_return(v6);
    }
    else
    {
      *a2 = v7[0];
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
