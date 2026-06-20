__int64 cam_req_mgr_handle_core_shutdown()
{
  _QWORD *v0; // x8
  _QWORD *v1; // x20
  __int64 result; // x0
  _QWORD v3[2]; // [xsp+0h] [xbp-10h] BYREF

  v3[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = 0;
  v0 = *(_QWORD **)g_crm_core_dev;
  if ( *(_QWORD *)g_crm_core_dev != g_crm_core_dev )
  {
    do
    {
      v1 = (_QWORD *)*v0;
      LODWORD(v3[0]) = *((_DWORD *)v0 - 10);
      result = cam_req_mgr_destroy_session(v3, 1);
      v0 = v1;
    }
    while ( v1 != (_QWORD *)g_crm_core_dev );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
