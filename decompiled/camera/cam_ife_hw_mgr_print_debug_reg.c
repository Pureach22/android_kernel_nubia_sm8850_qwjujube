__int64 __fastcall cam_ife_hw_mgr_print_debug_reg(__int64 result, __int64 a2, unsigned int a3, unsigned int a4)
{
  __int64 v5; // x20
  int *v6; // x25
  _QWORD *v7; // x24
  __int64 v8; // x28
  const char *v9; // x22
  __int64 v10; // x23
  __int64 v11; // x27
  unsigned int v12; // w26
  const char *v13; // x19
  _QWORD *v14; // x22
  int *v15; // x24
  unsigned int v16; // w25
  unsigned __int64 v17; // x9
  int v18; // w7
  _QWORD *v19; // x10
  const char *v20; // x8
  char v21; // w26
  _QWORD *v23; // [xsp+28h] [xbp-38h]
  unsigned int v24; // [xsp+34h] [xbp-2Ch]
  __int64 v25; // [xsp+38h] [xbp-28h] BYREF
  const char *v26; // [xsp+40h] [xbp-20h]
  unsigned __int64 v27; // [xsp+48h] [xbp-18h]
  __int64 v28; // [xsp+50h] [xbp-10h]
  __int64 v29; // [xsp+58h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(result + 9377) == 1 )
  {
    v5 = result;
    v27 = 0;
    v28 = 0;
    v25 = 0;
    v26 = nullptr;
    if ( a3 == -1 )
    {
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 8,
                 1,
                 "cam_ife_hw_mgr_print_debug_reg",
                 237,
                 "Ctx %u, invalid reg dump event",
                 *(_DWORD *)(result + 56));
    }
    else
    {
      v6 = (int *)&unk_3A8000;
      if ( dword_3A88C8 >= 1 )
      {
        v7 = g_ife_hw_mgr;
        v8 = 0;
        v9 = "Invalid";
        v10 = (1LL << a3) & 0xFFF;
        v23 = &g_ife_hw_mgr[a4];
        v24 = a4;
        do
        {
          if ( v8 == 20 )
LABEL_28:
            __break(0x5512u);
          v17 = v7[v8 + 10214];
          if ( v17 && (v10 & (v17 >> 4)) != 0 )
          {
            v18 = v17 & 0xF;
            if ( (v17 & 0xFFFF0000000000LL) == 0 )
            {
              if ( v18 == 1 )
              {
LABEL_19:
                if ( a4 >= 8 )
                  goto LABEL_28;
                v19 = (_QWORD *)v23[20];
              }
              else
              {
                if ( (v17 & 0xF) != 0 )
                {
                  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                             3,
                             8,
                             1,
                             "cam_ife_hw_mgr_print_debug_reg",
                             273,
                             "Ctx %u, invalid hardware type %d",
                             *(unsigned int *)(v5 + 56));
                  break;
                }
                v19 = v23 + 12;
                if ( a4 >= 8 )
                  goto LABEL_28;
              }
              v20 = v9;
              if ( a3 <= 8 )
                v20 = off_451450[a3];
              if ( v18 == 2 )
              {
                v21 = (v17 & 0xF0000) != 0;
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, const char *))cam_print_log)(
                  3,
                  8,
                  3,
                  "cam_ife_hw_mgr_print_debug_reg",
                  286,
                  "Reg_Read ctx:%d, CPAS %s",
                  *(unsigned int *)(v5 + 56),
                  v20);
                result = cam_cpas_log_votes(v21);
              }
              else
              {
                v11 = *(_QWORD *)(*v19 + 112LL);
                v12 = WORD1(v17);
                v13 = v9;
                v14 = v7;
                v15 = v6;
                v16 = BYTE4(v17);
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  3,
                  "cam_ife_hw_mgr_print_debug_reg",
                  302,
                  "Reg_Read: ctx:%d, Req: %llu %s[%u] %s",
                  *(_DWORD *)(v5 + 56),
                  *(_QWORD *)(v5 + 9304),
                  "CSID",
                  a4,
                  v20);
                v25 = v11 + 96;
                v26 = "ISP_Reg_read";
                v27 = __PAIR64__(v16, v12);
                v6 = v15;
                v7 = v14;
                v9 = v13;
                v28 = 8;
                result = cam_io_print_info(&v25);
              }
              a4 = v24;
              goto LABEL_7;
            }
            if ( a3 != 4
              || (((unsigned __int64)(unsigned __int16)(HIDWORD(v17) >> 8) >> *(_DWORD *)(*(_QWORD *)(a2 + 32) + 4LL))
                & 1) != 0 )
            {
              goto LABEL_19;
            }
          }
LABEL_7:
          ++v8;
        }
        while ( v8 < v6[562] );
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
