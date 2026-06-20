__int64 __fastcall cam_hw_cdm_set_cdm_core_cfg(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v4; // x6
  __int64 v5; // x7
  const char *v6; // x5
  __int64 v7; // x4
  int v8; // w9
  unsigned int v9; // w2
  __int64 v10; // x9
  __int64 result; // x0
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 3680);
  v12 = 0;
  v3 = *(_QWORD *)(a1 + 3392);
  if ( cam_cdm_read_hw_reg(a1, ***(_DWORD ***)(v2 + 232), (int *)&v12) )
  {
    v4 = *(_QWORD *)(a1 + 152);
    v5 = *(unsigned int *)(a1 + 116);
    v6 = "Error reading %s%u register";
    v7 = 694;
  }
  else
  {
    if ( v12 >> 29 )
    {
      v8 = 287;
      if ( *(_DWORD *)(v2 + 132) != 2 )
      {
        if ( *(_BYTE *)(v3 + 2) )
          v8 = 287;
        else
          v8 = 131359;
      }
      if ( *(_DWORD *)(v2 + 4872) == 1 )
        v9 = v8 | 0x10000;
      else
        v9 = v8;
      v10 = *(_QWORD *)(v2 + 232);
      if ( v12 >= 0x20010000 )
        v9 |= *(unsigned __int8 *)(v3 + 3) << *(_DWORD *)(*(_QWORD *)v10 + 276LL);
    }
    else
    {
      v10 = *(_QWORD *)(v2 + 232);
      v9 = 287;
    }
    if ( !cam_cdm_write_hw_reg(a1, *(_DWORD *)(*(_QWORD *)v10 + 24LL), v9) )
    {
      result = 0;
      goto LABEL_18;
    }
    v4 = *(_QWORD *)(a1 + 152);
    v5 = *(unsigned int *)(a1 + 116);
    v6 = "Error writing %s%u core cfg";
    v7 = 719;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
    3,
    1,
    1,
    "cam_hw_cdm_set_cdm_core_cfg",
    v7,
    v6,
    v4,
    v5);
  result = 4294967291LL;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
