__int64 __fastcall _osif_psoc_sync_create_and_trans(__int64 **a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v5; // w20
  __int64 *v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = nullptr;
  result = osif_psoc_sync_create(v6);
  if ( !(_DWORD)result )
  {
    result = dsc_psoc_trans_start(*(__int64 **)((char *)v6[0] + (unsigned __int64)&qword_8), a2);
    if ( (_DWORD)result )
    {
      v5 = result;
      osif_psoc_sync_destroy(v6[0]);
      result = qdf_status_to_os_return(v5);
    }
    else
    {
      *a1 = v6[0];
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
