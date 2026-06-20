__int64 __fastcall cam_isp_update_hw_entry(__int64 result, __int64 a2, __int64 a3, int a4, char a5)
{
  __int64 v5; // x6
  __int64 v6; // x8
  __int64 v7; // x6
  _DWORD *v8; // x8
  int v9; // w9
  int v10; // w9
  __int64 v11; // x8
  int v12; // w9
  char v13; // w9
  int v14; // w10
  int v15; // [xsp+14h] [xbp-Ch]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v5 = *(unsigned int *)(a2 + 40);
  v6 = *(_QWORD *)(a2 + 32);
  if ( (a5 & 1) != 0 )
  {
    v7 = (unsigned int)(v5 - 1);
    v8 = (_DWORD *)(v6 + 32 * v7);
    v9 = v8[2] + a4;
    v8[2] = v9;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v16 = a3;
      v15 = a4;
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 debug_mdl & 8,
                 4,
                 "cam_isp_combine_update_entry",
                 63,
                 "Combined with prev entry: num_ent=%d handle=0x%x, len=%u, offset=%u",
                 v7,
                 *v8,
                 v9,
                 v8[1]);
      a4 = v15;
      a3 = v16;
    }
    v10 = *(_DWORD *)(a3 + 16) + a4;
    *(_DWORD *)(a3 + 24) += a4;
    *(_DWORD *)(a3 + 16) = v10;
  }
  else
  {
    v11 = v6 + 32 * v5;
    *(_DWORD *)v11 = *(_DWORD *)a3;
    *(_DWORD *)(v11 + 8) = a4;
    v12 = *(_DWORD *)(a3 + 16);
    *(_DWORD *)(v11 + 12) = result;
    *(_DWORD *)(v11 + 4) = v12;
    *(_QWORD *)(v11 + 16) = *(_QWORD *)(a3 + 8) + (*(_DWORD *)(a3 + 24) & 0xFFFFFFFC);
    v13 = debug_mdl;
    v14 = *(_DWORD *)(a3 + 16) + a4;
    *(_DWORD *)(a3 + 24) += a4;
    *(_DWORD *)(a3 + 16) = v14;
    *(_DWORD *)(a2 + 40) = v5 + 1;
    if ( (v13 & 8) != 0 && !debug_priority )
      return ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               v13 & 8,
               4,
               "cam_isp_add_update_entry",
               44,
               "Add new entry: num_ent=%d handle=0x%x, len=%u, offset=%u",
               v5,
               *(_DWORD *)v11,
               *(_DWORD *)(v11 + 8),
               *(_DWORD *)(v11 + 4));
  }
  return result;
}
