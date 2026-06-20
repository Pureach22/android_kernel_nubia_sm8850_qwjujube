__int64 __fastcall cam_cdm_submit_bls(unsigned int a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // w6
  __int64 v6; // x9
  _DWORD *v7; // x8
  __int64 v8; // x0
  unsigned int v9; // w20
  _QWORD v10[3]; // [xsp+8h] [xbp-18h] BYREF

  v10[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( (unsigned int)get_cdm_mgr_refcount() )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_submit_bls",
        287,
        "CDM intf mgr get refcount failed");
      result = 0xFFFFFFFFLL;
    }
    else
    {
      v5 = HIWORD(a1) & 0xF;
      v10[0] = 0;
      v6 = *(_QWORD *)&cdm_mgr[72 * v5 + 72];
      if ( v6 && (v7 = *(_DWORD **)(v6 + 88)) != nullptr )
      {
        v8 = *(_QWORD *)(v6 + 112);
        v10[1] = a2;
        LODWORD(v10[0]) = a1;
        if ( *(v7 - 1) != -1055839300 )
          __break(0x8228u);
        v9 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v7)(v8, 2, v10, 16);
        if ( (v9 & 0x80000000) != 0 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            1,
            1,
            "cam_cdm_submit_bls",
            306,
            "hw submit bl failed for handle=%x",
            a1);
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          1,
          "cam_cdm_submit_bls",
          309,
          "hw idx %d doesn't have submit ops",
          v5);
        v9 = -22;
      }
      put_cdm_mgr_refcount();
      result = v9;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
