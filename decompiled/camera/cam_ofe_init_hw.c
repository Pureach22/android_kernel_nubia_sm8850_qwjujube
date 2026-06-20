__int64 __fastcall cam_ofe_init_hw(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x1
  __int64 result; // x0
  unsigned int v5; // w0
  int v6; // w0
  unsigned int v7; // w19
  unsigned int v8; // w20
  __int64 v9; // x0
  _QWORD v10[80]; // [xsp+0h] [xbp-280h] BYREF

  v10[79] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v10, 0, 0x278u);
  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 3680);
    if ( v2 )
    {
      v3 = raw_spin_lock_irqsave(a1 + 48);
      if ( *(_DWORD *)(a1 + 92) == 1 )
      {
        ++*(_DWORD *)(v2 + 12);
        raw_spin_unlock_irqrestore(a1 + 48, v3);
        result = 0;
      }
      else
      {
        raw_spin_unlock_irqrestore(a1 + 48, v3);
        LODWORD(v10[1]) = 2;
        LODWORD(v10[2]) = 1;
        *(_QWORD *)((char *)&v10[3] + 4) = 0xA300000001LL;
        v10[5] = 1024;
        v10[6] = 1024;
        v10[7] = 1024;
        v5 = *(_DWORD *)(v2 + 8);
        LODWORD(v10[0]) = 0;
        v6 = cam_cpas_start(v5, (__int64)v10, (__int64)&v10[2]);
        if ( v6 )
        {
          v7 = v6;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_ofe_init_hw",
            106,
            "cpas start failed: %d",
            v6);
          result = v7;
        }
        else
        {
          *(_BYTE *)(v2 + 16) = 1;
          v8 = cam_ofe_enable_soc_resources(a1 + 96);
          if ( v8 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              256,
              1,
              "cam_ofe_init_hw",
              113,
              "soc enable failed rc:%d",
              v8);
            if ( (unsigned int)cam_cpas_stop(*(_DWORD *)(v2 + 8)) )
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                256,
                1,
                "cam_ofe_init_hw",
                115,
                "cpas stop failed");
            else
              *(_BYTE *)(v2 + 16) = 0;
          }
          else
          {
            *(_BYTE *)(v2 + 17) = 1;
          }
          v9 = raw_spin_lock_irqsave(a1 + 48);
          *(_DWORD *)(a1 + 92) = 1;
          ++*(_DWORD *)(v2 + 12);
          raw_spin_unlock_irqrestore(a1 + 48, v9);
          if ( (debug_mdl & 0x100) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x100,
              4,
              "cam_ofe_init_hw",
              127,
              "OFE%u powered on",
              *(_DWORD *)(a1 + 116));
          result = v8;
        }
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_ofe_init_hw",
        70,
        "soc_info = %pK core_info = %pK",
        (const void *)(a1 + 96),
        nullptr);
      result = 4294967274LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_ofe_init_hw",
      61,
      "Invalid cam_dev_info");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
