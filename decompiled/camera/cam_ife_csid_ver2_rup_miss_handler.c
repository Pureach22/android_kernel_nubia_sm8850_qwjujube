void *__fastcall cam_ife_csid_ver2_rup_miss_handler(__int64 a1, int a2)
{
  _DWORD *v3; // x8
  __int64 v4; // x9
  __int64 v5; // x0
  int v6; // w10
  unsigned int v7; // w10
  int v8; // w9
  void *result; // x0
  __int64 v10; // x0
  int v11; // [xsp+4h] [xbp-3Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-38h]
  __int64 v13; // [xsp+10h] [xbp-30h] BYREF
  __int64 v14; // [xsp+18h] [xbp-28h]
  __int64 v15; // [xsp+20h] [xbp-20h]
  __int64 v16; // [xsp+28h] [xbp-18h]
  int *v17; // [xsp+30h] [xbp-10h]
  __int64 v18; // [xsp+38h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD **)(a1 + 31152);
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v12 = 0;
  if ( v3 )
  {
    v4 = *(_QWORD *)(a1 + 31120);
    v5 = *(_QWORD *)(a1 + 31144);
    v11 = 0x400000;
    v6 = *(_DWORD *)(a1 + 2048);
    LODWORD(v4) = *(_DWORD *)(v4 + 4);
    v17 = &v11;
    v7 = v6 - 2;
    HIDWORD(v14) = v4;
    LODWORD(v15) = a2;
    if ( v7 >= 3 )
      v8 = 0xFFFF;
    else
      v8 = v7;
    HIDWORD(v15) = 0;
    LODWORD(v16) = v8;
    if ( *(v3 - 1) != 414296116 )
      __break(0x8228u);
    result = (void *)((__int64 (__fastcall *)(__int64, _QWORD, __int64 *))v3)(v5, 0, &v13);
    if ( BYTE4(v12) == 1 )
    {
      cam_ife_csid_ver2_print_camif_timestamps(a1, 1);
      result = cam_ife_csid_ver2_read_debug_err_vectors(a1);
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&cam_ife_csid_ver2_rup_miss_handler__rs, "cam_ife_csid_ver2_rup_miss_handler") )
      v10 = 3;
    else
      v10 = 2;
    result = (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       v10,
                       8,
                       1,
                       "cam_ife_csid_ver2_rup_miss_handler",
                       3323,
                       "CSID[%u] event cb not registered",
                       *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
