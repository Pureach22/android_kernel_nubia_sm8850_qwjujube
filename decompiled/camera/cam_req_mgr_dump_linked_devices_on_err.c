__int64 __fastcall cam_req_mgr_dump_linked_devices_on_err(__int64 a1, __int64 a2)
{
  int v2; // w19
  __int64 result; // x0
  __int64 v4; // x20
  _DWORD *v5; // x21
  __int64 v6; // x22
  unsigned int v7; // w23
  __int64 v8; // x24
  _QWORD v9[26]; // [xsp+10h] [xbp-D0h] BYREF

  v2 = a1;
  v9[25] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v9, 0, 200);
  result = cam_get_link_priv(a1, a2);
  if ( result && (v4 = result, *(_DWORD *)result == v2) )
  {
    v5 = *(_DWORD **)(result + 33160);
    if ( *(int *)(result + 4) >= 1 )
    {
      v6 = 0;
      v7 = 0;
      v8 = 28;
      do
      {
        if ( v7 >= 0xC9 )
          __break(0x5512u);
        ++v6;
        v7 += snprintf((char *)v9 + v7, 200 - v7, " %s", (const char *)(*(_QWORD *)(v4 + 40) + v8));
        v8 += 320;
      }
      while ( v6 < *(int *)(v4 + 4) );
      v2 = *(_DWORD *)v4;
    }
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               16,
               3,
               "cam_req_mgr_dump_linked_devices_on_err",
               6265,
               "Connected devices on the link 0x%x in session 0x%x:%s",
               v2,
               *v5,
               (const char *)v9);
  }
  else if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 0x10,
               4,
               "cam_req_mgr_dump_linked_devices_on_err",
               6251,
               "Invalid link hdl 0x%x",
               v2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
