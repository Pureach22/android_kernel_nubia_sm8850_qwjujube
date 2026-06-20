__int64 __fastcall _cam_isp_ctx_trigger_reg_dump(unsigned int a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x8
  __int64 *v6; // x9
  __int64 (__fastcall *v7)(__int64, __int64 *); // x8
  __int64 v8; // x0
  unsigned int v9; // w19
  __int64 v11; // [xsp+10h] [xbp-20h] BYREF
  __int64 v12; // [xsp+18h] [xbp-18h]
  __int64 v13; // [xsp+20h] [xbp-10h]
  __int64 v14; // [xsp+28h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a2 + 264);
  v6 = *(__int64 **)(a2 + 208);
  v13 = a3;
  v11 = v5;
  v12 = 0;
  v7 = (__int64 (__fastcall *)(__int64, __int64 *))v6[12];
  LODWORD(v12) = a1;
  v8 = *v6;
  if ( *((_DWORD *)v7 - 1) != 1863972096 )
    __break(0x8228u);
  v9 = v7(v8, &v11);
  if ( v9 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_trigger_reg_dump",
      955,
      "Reg dump on error failed ctx: %u link: 0x%x rc: %d",
      *(unsigned int *)(a2 + 32),
      *(unsigned int *)(a2 + 64),
      v9);
  }
  else if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_trigger_reg_dump",
      961,
      "Reg dump type: %u successful in ctx: %u on link: 0x%x",
      a1,
      *(unsigned int *)(a2 + 32),
      *(_DWORD *)(a2 + 64));
  }
  _ReadStatusReg(SP_EL0);
  return v9;
}
