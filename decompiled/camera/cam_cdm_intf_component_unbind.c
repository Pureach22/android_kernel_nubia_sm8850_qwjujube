__int64 __fastcall cam_cdm_intf_component_unbind(__int64 a1)
{
  const char *v3; // x5
  __int64 v4; // x4
  __int64 v5; // x19
  int *v6; // x21
  _QWORD *v7; // x22
  int *v8; // x0

  if ( (unsigned int)get_cdm_mgr_refcount() )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             1,
             1,
             "cam_cdm_intf_component_unbind",
             750,
             "CDM intf mgr get refcount failed");
  if ( (unsigned int)cam_virtual_cdm_remove(a1 - 16) )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             1,
             1,
             "cam_cdm_intf_component_unbind",
             755,
             "Virtual CDM remove failed");
  put_cdm_mgr_refcount();
  mutex_lock(&cam_cdm_mgr_lock);
  if ( dword_39423C )
  {
    v3 = "cdm manger refcount not zero %d";
    v4 = 763;
  }
  else
  {
    v5 = 0;
    v6 = &dword_394270;
    while ( 1 )
    {
      v7 = v6 + 2;
      if ( *((_QWORD *)v6 + 1) || *((_QWORD *)v6 + 2) || *v6 )
        break;
      mutex_lock(v6 - 12);
      v8 = v6 - 12;
      *v6 = 0;
      v6 += 18;
      *v7 = 0;
      v7[1] = 0;
      mutex_unlock(v8);
      if ( ++v5 == 16 )
      {
        cdm_mgr[0] = 0;
        return mutex_unlock(&cam_cdm_mgr_lock);
      }
    }
    v3 = "Valid node present in index=%d";
    v4 = 770;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    1,
    1,
    "cam_cdm_intf_component_unbind",
    v4,
    v3);
  return mutex_unlock(&cam_cdm_mgr_lock);
}
