__int64 __fastcall cam_isp_add_change_base(__int64 a1, __int64 **a2, int *a3, __int64 a4)
{
  int v4; // w6
  unsigned int v5; // w7
  __int64 *i; // x9
  __int64 v7; // x10
  __int64 v8; // x8
  int v9; // w11
  int v10; // w12
  int v11; // w9
  __int64 v13; // x10
  __int64 v14; // x0
  _DWORD *v16; // x9
  __int64 result; // x0
  __int64 v18; // x6
  int v19; // w10
  __int64 v20; // x8
  int v21; // w11
  int v22; // w11
  char v23; // w9
  __int64 v24; // [xsp+10h] [xbp-40h] BYREF
  int v25; // [xsp+18h] [xbp-38h]
  int v26; // [xsp+1Ch] [xbp-34h]
  __int64 v27; // [xsp+20h] [xbp-30h]
  __int64 v28; // [xsp+28h] [xbp-28h]
  __int64 v29; // [xsp+30h] [xbp-20h]
  __int64 v30; // [xsp+38h] [xbp-18h]
  __int64 v31; // [xsp+40h] [xbp-10h]
  __int64 v32; // [xsp+48h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 + 40);
  v5 = *(_DWORD *)(a1 + 24);
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  if ( v4 + 1 >= v5 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_add_change_base",
      101,
      "Insufficient  HW entries :%d %d",
      v4,
      v5);
  }
  else
  {
    for ( i = *a2; i != (__int64 *)a2; i = (__int64 *)*i )
    {
      if ( *((_DWORD *)i + 4) )
      {
        if ( (v7 = i[4]) != 0 && (v8 = *(_QWORD *)(v7 + 16), *(_DWORD *)(v8 + 4) == a3[1])
          || (v7 = i[5]) != 0 && (v8 = *(_QWORD *)(v7 + 16), *(_DWORD *)(v8 + 4) == a3[1]) )
        {
          v10 = *(_DWORD *)(a4 + 20);
          v9 = *(_DWORD *)(a4 + 24);
          v11 = *a3;
          v24 = v7;
          v13 = *(_QWORD *)(a4 + 8);
          v14 = *(_QWORD *)(v8 + 112);
          v25 = 0;
          v26 = v11;
          v16 = *(_DWORD **)(v8 + 88);
          v27 = v13 + (v9 & 0xFFFFFFFC);
          LODWORD(v28) = v10 - v9;
          if ( *(v16 - 1) != -1055839300 )
            __break(0x8229u);
          result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 *, __int64))v16)(v14, 0, &v24, 56);
          if ( !(_DWORD)result )
          {
            v18 = *(unsigned int *)(a1 + 40);
            v19 = HIDWORD(v28);
            v20 = *(_QWORD *)(a1 + 32) + 32 * v18;
            *(_DWORD *)v20 = *(_DWORD *)a4;
            *(_DWORD *)(v20 + 8) = v19;
            v21 = *(_DWORD *)(a4 + 16);
            *(_DWORD *)(v20 + 12) = 1;
            *(_DWORD *)(v20 + 4) = v21;
            *(_QWORD *)(v20 + 16) = *(_QWORD *)(a4 + 8) + (*(_DWORD *)(a4 + 24) & 0xFFFFFFFC);
            v22 = *(_DWORD *)(a4 + 16);
            *(_DWORD *)(a4 + 24) += v19;
            v23 = debug_mdl;
            *(_DWORD *)(a4 + 16) = v22 + v19;
            *(_DWORD *)(a1 + 40) = v18 + 1;
            if ( (v23 & 8) != 0 && !debug_priority )
            {
              ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v23 & 8,
                4,
                "cam_isp_add_update_entry",
                44,
                "Add new entry: num_ent=%d handle=0x%x, len=%u, offset=%u",
                v18,
                *(_DWORD *)v20,
                *(_DWORD *)(v20 + 8),
                *(_DWORD *)(v20 + 4));
              result = 0;
            }
          }
          goto LABEL_18;
        }
      }
    }
  }
  result = 4294967274LL;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
