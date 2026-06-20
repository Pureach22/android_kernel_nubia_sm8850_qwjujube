__int64 __fastcall cam_csiphy_update_secure_info(__int64 a1, unsigned int a2)
{
  __int64 is_mink_api_available; // x0
  __int64 v5; // x1
  __int64 result; // x0
  __int64 v7; // x21
  __int64 v8; // x9
  int v9; // w8
  unsigned __int16 *v10; // x20
  unsigned __int16 v11; // w9
  char v12; // w11
  unsigned int cpas_hw_version; // w0
  unsigned int v14; // w19
  unsigned int v15; // w9
  char v16; // w8
  char v17; // w8
  char v18; // w9
  int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  is_mink_api_available = cam_is_mink_api_available();
  if ( (is_mink_api_available & 1) != 0 )
  {
    result = 0;
    if ( (debug_mdl & 0x8000) == 0 || debug_priority )
      goto LABEL_27;
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      (unsigned __int16)debug_mdl & 0x8000,
      4,
      "cam_csiphy_update_secure_info",
      809,
      "Using MINK API for CSIPHY [%u], skipping legacy update",
      *(_DWORD *)(a1 + 932));
    goto LABEL_29;
  }
  if ( a2 < 3 )
  {
    v7 = 0;
    v8 = a1 + 104LL * a2;
    v9 = *(unsigned __int8 *)(v8 + 602);
    v10 = (unsigned __int16 *)(v8 + 600);
    if ( *(_BYTE *)(v8 + 602) )
    {
      v11 = *v10;
      do
      {
        v12 = v11 & 0xF;
        --v9;
        v11 >>= 4;
        v7 |= (unsigned int)(1 << v12);
      }
      while ( (_BYTE)v9 );
    }
    cpas_hw_version = cam_cpas_get_cpas_hw_version(&v19);
    if ( cpas_hw_version )
    {
      v14 = cpas_hw_version;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_csiphy_update_secure_info",
        824,
        "Failed while getting CPAS Version");
      result = v14;
LABEL_27:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    if ( v19 == 5767424 || v19 == 6816000 || v19 == 7864576 )
    {
      v15 = *(_DWORD *)(a1 + 932);
      if ( v15 < 4 )
        v16 = 7;
      else
        v16 = 8;
      if ( v15 <= 3 )
        goto LABEL_18;
    }
    else
    {
      v15 = *(_DWORD *)(a1 + 932);
      v16 = 7;
      if ( v15 <= 3 )
      {
LABEL_18:
        v17 = v15 * v16;
        if ( *((_DWORD *)v10 + 6) )
          v18 = 0;
        else
          v18 = 3;
LABEL_25:
        result = 0;
        *((_QWORD *)v10 + 4) = v7 << (v18 + v17);
        if ( (debug_mdl & 0x8000) == 0 || debug_priority )
          goto LABEL_27;
        ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          (unsigned __int16)debug_mdl & 0x8000,
          4,
          "cam_csiphy_update_secure_info",
          860,
          "CSIPHY_idx:%d, cp_reg_mask:0x%llx",
          *(unsigned int *)(a1 + 932));
LABEL_29:
        result = 0;
        goto LABEL_27;
      }
    }
    v18 = (v15 - 4) * v16 + 32;
    if ( *((_DWORD *)v10 + 6) )
      v17 = 0;
    else
      v17 = 3;
    goto LABEL_25;
  }
  __break(0x5512u);
  return _csiphy_prgm_common_data(is_mink_api_available, v5);
}
