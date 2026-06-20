__int64 __fastcall cam_ife_set_sfe_cache_debug(__int64 a1, unsigned __int64 a2)
{
  __int64 v3; // x9
  __int64 v4; // x9
  int *v5; // x10
  __int64 result; // x0
  _DWORD *v7; // x8
  __int64 v8; // x0
  unsigned int v9; // w20
  _QWORD v10[11]; // [xsp+8h] [xbp-58h] BYREF

  v3 = a2 & 0xF;
  v10[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[9] = 0x100000000LL;
  memset(v10, 0, 72);
  if ( (a2 & 0xF) != 0 || !qword_3949D8 )
  {
    if ( v3 == 1 && qword_3949E0 )
    {
      v4 = *(_QWORD *)qword_3949E0;
      LODWORD(v10[0]) = a2 >> 4;
      v5 = &dword_3A8524;
    }
    else
    {
      result = 4294967274LL;
      if ( v3 != 2 || !qword_3949E8 )
        goto LABEL_13;
      v4 = *(_QWORD *)qword_3949E8;
      v5 = &dword_3A8528;
      LODWORD(v10[0]) = a2 >> 4;
    }
  }
  else
  {
    v4 = *(_QWORD *)qword_3949D8;
    LODWORD(v10[0]) = a2 >> 4;
    v5 = &dword_3A8520;
  }
  *v5 = a2 >> 4;
  v7 = *(_DWORD **)(v4 + 88);
  v8 = *(_QWORD *)(v4 + 112);
  if ( *(v7 - 1) != -1055839300 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v7)(v8, 43, v10, 80);
LABEL_13:
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v9 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_set_sfe_cache_debug",
      18543,
      "Set SFE cache debug value: 0x%llx",
      a2);
    result = v9;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
