__int64 __fastcall cam_cdm_intf_register_hw_cdm(__int64 a1, __int64 a2, int a3, int *a4)
{
  __int64 result; // x0
  __int64 v7; // x22
  unsigned int v10; // w20
  int v11; // w8
  char *v12; // x9

  result = 4294967274LL;
  if ( a1 && a2 && a4 )
  {
    v7 = a1;
    if ( (unsigned int)get_cdm_mgr_refcount() )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_intf_register_hw_cdm",
        550,
        "CDM intf mgr get refcount failed");
      return 4294967274LL;
    }
    else
    {
      mutex_lock(&cam_cdm_mgr_lock);
      if ( a3 || qword_394278 )
      {
        if ( a3 == 1 && dword_394234 )
        {
          if ( (unsigned int)dword_394234 > 0xF
            || (mutex_lock(&cdm_mgr[72 * dword_394234 + 16]), v11 = dword_394234, (unsigned int)dword_394234 > 0xF)
            || (v12 = &cdm_mgr[72 * dword_394234],
                *((_QWORD *)v12 + 9) = v7,
                *((_QWORD *)v12 + 10) = a2,
                *a4 = v11,
                (unsigned int)dword_394234 > 0xF) )
          {
            __break(0x5512u);
            JUMPOUT(0x16568C);
          }
          mutex_unlock(&cdm_mgr[72 * dword_394234 + 16]);
          v10 = 0;
          ++dword_394234;
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            1,
            1,
            "cam_cdm_intf_register_hw_cdm",
            574,
            "CDM registration failed type=%d count=%d",
            a3,
            dword_394234);
          v10 = -22;
        }
      }
      else
      {
        mutex_lock(&unk_394240);
        qword_394278 = v7;
        qword_394280 = a2;
        *a4 = dword_394234;
        mutex_unlock(&unk_394240);
        v10 = 0;
        ++dword_394234;
      }
      mutex_unlock(&cam_cdm_mgr_lock);
      put_cdm_mgr_refcount();
      return v10;
    }
  }
  return result;
}
