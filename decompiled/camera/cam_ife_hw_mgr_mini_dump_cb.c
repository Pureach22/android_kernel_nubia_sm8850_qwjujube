__int64 __fastcall cam_ife_hw_mgr_mini_dump_cb(_DWORD *a1, unsigned __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x25
  __int64 v6; // x22
  unsigned __int64 v7; // x8
  char *v8; // x27
  __int64 v9; // x11
  __int64 v10; // x12
  __int64 v11; // x13
  unsigned __int64 v12; // x24
  unsigned int *v13; // x28
  char *v14; // x23
  __int64 v15; // x10
  void (__fastcall *v16)(_QWORD); // x9
  __int64 v17; // x0
  __int64 v18; // x10
  unsigned int v19; // w10
  __int64 v20; // x9
  __int64 v21; // x9
  __int64 v22; // x10
  __int64 v23; // x9
  char *v24; // x12
  char *v25; // x11
  __int64 *v26; // x10
  unsigned int (__fastcall *v27)(__int64, char **); // x9
  __int64 v28; // x0
  _DWORD *v30; // [xsp+0h] [xbp-40h]
  __int64 *v31; // [xsp+8h] [xbp-38h]
  char *v32; // [xsp+20h] [xbp-20h] BYREF
  unsigned __int64 v33; // [xsp+28h] [xbp-18h]
  __int64 v34; // [xsp+30h] [xbp-10h]
  __int64 v35; // [xsp+38h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v34 = 0;
  v32 = nullptr;
  if ( a2 > 0x47 )
  {
    *a1 = 0;
    v4 = qword_394A78;
    if ( (__int64 *)qword_394A78 == &qword_394A78 )
    {
      LODWORD(v6) = 0;
      v3 = 72;
    }
    else
    {
      v6 = 0;
      v7 = a2 - 72;
      v3 = 72;
      v30 = a1 + 2;
      while ( v7 > 0x177 )
      {
        if ( v6 == 8 )
        {
LABEL_38:
          __break(0x5512u);
LABEL_39:
          __break(1u);
        }
        v8 = (char *)a1 + v3;
        v3 += 376;
        v31 = *(__int64 **)v4;
        *(_QWORD *)&v30[2 * v6] = v8;
        v8[356] = *(_DWORD *)(v4 + 56);
        v8[357] = *(_DWORD *)(v4 + 60);
        v8[358] = *(_DWORD *)(v4 + 64);
        *((_DWORD *)v8 + 88) = *(_DWORD *)(v4 + 8720);
        v8[359] = *(_DWORD *)(v4 + 8716);
        *((_DWORD *)v8 + 90) = *(_DWORD *)(v4 + 8744);
        *((_QWORD *)v8 + 42) = *(_QWORD *)(v4 + 8856);
        *((_QWORD *)v8 + 43) = *(_QWORD *)(v4 + 9304);
        *((_DWORD *)v8 + 91) = *(_DWORD *)(v4 + 9312);
        v8[368] = *(_DWORD *)(v4 + 8844) != 0;
        v8[369] = *(_DWORD *)(v4 + 8848) != 0;
        *(_QWORD *)(v8 + 132) = *(_QWORD *)(v4 + 9404);
        v9 = *(_QWORD *)(v4 + 9392);
        v10 = *(_QWORD *)(v4 + 9376);
        v11 = *(_QWORD *)(v4 + 9384);
        *(_DWORD *)(v8 + 319) = *(_DWORD *)(v4 + 9399);
        *((_QWORD *)v8 + 38) = v11;
        *((_QWORD *)v8 + 39) = v9;
        *((_QWORD *)v8 + 37) = v10;
        if ( *(_DWORD *)(v4 + 8716) )
        {
          v12 = 0;
          v13 = (unsigned int *)(v4 + 8584);
          v14 = v8;
          while ( 1 )
          {
            v18 = *(_QWORD *)v13;
            *((_DWORD *)v14 + 2) = v13[2];
            *(_QWORD *)v14 = v18;
            if ( v12 == 11 )
              goto LABEL_38;
            v19 = v13[2];
            v20 = *v13;
            if ( v19 == 7 )
              break;
            if ( v19 == 2 )
            {
              if ( (unsigned int)v20 > 7 )
                goto LABEL_38;
              v23 = v20;
              v24 = v8 + 208;
              v25 = (char *)a1 + v3;
              v26 = (__int64 *)g_ife_hw_mgr[v23 + 20];
LABEL_9:
              v15 = *v26;
              *(_QWORD *)&v24[v23 * 8] = v25;
              v33 = v7;
              v34 = 0;
              v16 = *(void (__fastcall **)(_QWORD))(v15 + 88);
              v17 = *(_QWORD *)(v15 + 112);
              v32 = v25;
              goto LABEL_10;
            }
            if ( v19 )
              goto LABEL_14;
            if ( (unsigned int)v20 > 7 )
              goto LABEL_38;
            v21 = v20;
            v33 = v7;
            v34 = 0;
            v32 = (char *)a1 + v3;
            v22 = g_ife_hw_mgr[v21 + 12];
            *(_QWORD *)&v8[v21 * 8 + 144] = (char *)a1 + v3;
            v16 = *(void (__fastcall **)(_QWORD))(v22 + 88);
            v17 = *(_QWORD *)(v22 + 112);
LABEL_10:
            if ( *((_DWORD *)v16 - 1) != -1055839300 )
              __break(0x8229u);
            v16(v17);
            if ( !v34 )
              goto LABEL_35;
            v3 += v34;
            v7 = a2 - v3;
LABEL_14:
            ++v12;
            v13 += 3;
            v14 += 12;
            if ( v12 >= *(unsigned int *)(v4 + 8716) )
              goto LABEL_26;
          }
          if ( (unsigned int)v20 > 2 )
            goto LABEL_38;
          v23 = v20;
          if ( ((v23 * 8) | 0xE0uLL) > 0x13FE0 )
            goto LABEL_39;
          v24 = v8 + 272;
          v25 = (char *)a1 + v3;
          v26 = (__int64 *)g_ife_hw_mgr[v23 + 28];
          goto LABEL_9;
        }
LABEL_26:
        v27 = *(unsigned int (__fastcall **)(__int64, char **))(v4 + 40);
        if ( v27 )
        {
          v28 = *(_QWORD *)(v4 + 32);
          v32 = (char *)a1 + v3;
          v33 = v7;
          v34 = 0;
          if ( *((_DWORD *)v27 - 1) != 1863972096 )
            __break(0x8229u);
          if ( v27(v28, &v32) )
            goto LABEL_35;
          v7 = a2 - (v34 + v3);
          if ( a2 < v34 + v3 )
            goto LABEL_35;
          v3 += v34;
          *((_QWORD *)v8 + 41) = v32;
        }
        v4 = (__int64)v31;
        ++v6;
        if ( v31 == &qword_394A78 )
          goto LABEL_35;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_mini_dump_cb",
        19827,
        "Insufficent received length: %u, dumped_len %u",
        a2,
        v3);
    }
LABEL_35:
    *a1 = v6;
    goto LABEL_36;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_hw_mgr_mini_dump_cb",
    19811,
    "Insufficent received length: %u",
    a2);
  v3 = 0;
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return v3;
}
