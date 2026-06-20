__int64 __fastcall cam_cdm_dump_debug_registers(unsigned int a1)
{
  __int64 result; // x0
  __int64 v3; // x9
  __int64 (__fastcall *v4)(__int64, __int64, unsigned int *, __int64); // x8
  __int64 v5; // x0
  unsigned int v6; // w19
  unsigned int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = a1;
  if ( (unsigned int)get_cdm_mgr_refcount() )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_dump_debug_registers",
      521,
      "CDM intf mgr get refcount failed");
    result = 0xFFFFFFFFLL;
  }
  else
  {
    v3 = *(_QWORD *)&cdm_mgr[72 * (HIWORD(a1) & 0xF) + 72];
    if ( v3 && (v4 = *(__int64 (__fastcall **)(__int64, __int64, unsigned int *, __int64))(v3 + 88)) != nullptr )
    {
      v5 = *(_QWORD *)(v3 + 112);
      if ( *((_DWORD *)v4 - 1) != -1055839300 )
        __break(0x8228u);
      v6 = v4(v5, 7, &v7, 4);
    }
    else
    {
      v6 = -22;
    }
    put_cdm_mgr_refcount();
    result = v6;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
