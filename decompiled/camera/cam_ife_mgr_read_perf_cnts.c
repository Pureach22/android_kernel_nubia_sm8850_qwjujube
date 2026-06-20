__int64 __fastcall cam_ife_mgr_read_perf_cnts(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  unsigned __int64 v3; // x24
  _DWORD *v4; // x25
  __int64 v5; // x26
  __int64 v6; // x27
  __int64 v7; // x23
  __int64 *v8; // x8
  __int64 v9; // x8
  __int64 (__fastcall *v10)(__int64, __int64, int *, __int64); // x9
  __int64 v11; // x0
  __int64 *v12; // x8
  __int64 v13; // x8
  __int64 (__fastcall *v14)(__int64, __int64, int *, __int64); // x9
  __int64 v15; // x0
  int v16; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(result + 8716) )
  {
    v1 = *(_QWORD *)(result + 72);
    v2 = result;
    v3 = 0;
    v4 = (_DWORD *)(result + 8592);
    v5 = v1 + 224;
    v6 = v1 + 160;
    v16 = 0;
    do
    {
      if ( v3 == 11 )
LABEL_25:
        __break(0x5512u);
      v7 = (unsigned int)*(v4 - 2);
      if ( *v4 == 7 )
      {
        if ( (unsigned int)v7 > 2 )
          goto LABEL_25;
        v12 = *(__int64 **)(v5 + 8 * v7);
        if ( v12 )
        {
          v13 = *v12;
          v14 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v13 + 88);
          v15 = *(_QWORD *)(v13 + 112);
          if ( *((_DWORD *)v14 - 1) != -1055839300 )
            __break(0x8229u);
          result = v14(v15, 84, &v16, 4);
          if ( (_DWORD)result )
          {
            if ( (debug_mdl & 8) != 0 && !debug_priority )
LABEL_3:
              result = ((__int64 (__fastcall *)(__int64))cam_print_log)(3);
          }
        }
      }
      else if ( *v4 == 2 )
      {
        if ( (unsigned int)v7 > 7 )
          goto LABEL_25;
        v8 = *(__int64 **)(v6 + 8 * v7);
        if ( v8 )
        {
          v9 = *v8;
          v10 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v9 + 88);
          v11 = *(_QWORD *)(v9 + 112);
          if ( *((_DWORD *)v10 - 1) != -1055839300 )
            __break(0x8229u);
          result = v10(v11, 84, &v16, 4);
          if ( (_DWORD)result )
          {
            if ( (debug_mdl & 8) != 0 && !debug_priority )
              goto LABEL_3;
          }
        }
      }
      ++v3;
      v4 += 3;
    }
    while ( v3 < *(unsigned int *)(v2 + 8716) );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
