__int64 __fastcall cam_jpeg_hw_mgr_mini_dump_cb(_DWORD *a1, unsigned __int64 a2)
{
  _DWORD *v4; // x8
  __int64 v5; // x0
  _DWORD *v6; // x8
  __int64 v7; // x0
  __int64 v8; // x22
  unsigned __int64 v9; // x8
  unsigned int *v10; // x24
  __int64 v11; // x21
  char *v12; // x9
  __int64 v13; // x10
  __int64 v14; // x12
  __int64 v15; // x13
  __int64 v16; // x10
  __int64 v17; // x11
  __int64 v18; // x10
  void (__fastcall *v19)(__int64, char **); // x10
  __int64 v20; // x0
  char *v22; // [xsp+0h] [xbp-20h] BYREF
  unsigned __int64 v23; // [xsp+8h] [xbp-18h]
  __int64 v24; // [xsp+10h] [xbp-10h]
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24 = 0;
  v22 = nullptr;
  if ( a1 && a2 > 0x137 )
  {
    a1[76] = 0;
    v4 = *(_DWORD **)(*(_QWORD *)qword_3AA0E0 + 88LL);
    if ( v4 )
    {
      v5 = *(_QWORD *)(*(_QWORD *)qword_3AA0E0 + 112LL);
      if ( *(v4 - 1) != -1055839300 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _DWORD *, __int64))v4)(v5, 5, a1 + 60, 32);
    }
    v6 = *(_DWORD **)(*(_QWORD *)qword_3AA0E8 + 88LL);
    if ( v6 )
    {
      v7 = *(_QWORD *)(*(_QWORD *)qword_3AA0E8 + 112LL);
      if ( *(v6 - 1) != -1055839300 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _DWORD *, __int64))v6)(v7, 5, a1 + 68, 32);
    }
    v8 = 0;
    v9 = a2 - 312;
    v10 = (unsigned int *)&unk_3A8D08;
    v11 = 312;
    while ( 1 )
    {
      if ( *((_BYTE *)v10 + 48) == 1 )
      {
        if ( v9 < 0x90 )
          goto LABEL_24;
        ++a1[76];
        v12 = (char *)a1 + v11;
        *(_QWORD *)&a1[v8] = (char *)a1 + v11;
        v12[136] = *((_BYTE *)v10 + 48);
        *(_QWORD *)v12 = *(_QWORD *)v10;
        v13 = *((_QWORD *)v10 + 4);
        v14 = *((_QWORD *)v10 + 1);
        v15 = *((_QWORD *)v10 + 2);
        *((_QWORD *)v12 + 3) = *((_QWORD *)v10 + 3);
        *((_QWORD *)v12 + 4) = v13;
        *((_QWORD *)v12 + 1) = v14;
        *((_QWORD *)v12 + 2) = v15;
        v16 = *v10;
        if ( (unsigned int)v16 > 1 )
        {
          __break(0x5512u);
LABEL_26:
          __break(1u);
        }
        if ( ((8 * v16) | 0x1490uLL) > 0x2AB0 )
          goto LABEL_26;
        v17 = *((_QWORD *)&g_jpeg_hw_mgr + v16 + 658);
        if ( v17 )
        {
          v18 = (__int64)&a1[6 * (unsigned int)v16 + 48];
          *(_QWORD *)v18 = *(_QWORD *)(v17 + 96);
          *(_QWORD *)(v18 + 8) = *(_QWORD *)(v17 + 88);
          *(_DWORD *)(v18 + 16) = *(_DWORD *)(v17 + 80);
          *(_DWORD *)(v18 + 20) = *(_DWORD *)(v17 + 104);
        }
        v19 = (void (__fastcall *)(__int64, char **))off_3AB740;
        v20 = *((_QWORD *)v10 - 7);
        v23 = v9;
        v24 = 0;
        v22 = (char *)a1 + v11;
        if ( *((_DWORD *)off_3AB740 - 1) != -72220 )
          __break(0x822Au);
        v19(v20, &v22);
        v9 = a2 - (v24 + v11);
        if ( a2 <= v24 + v11 )
          goto LABEL_24;
        v11 += v24;
      }
      v8 += 2;
      v10 += 52;
      if ( v8 == 48 )
        goto LABEL_24;
    }
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    512,
    1,
    "cam_jpeg_hw_mgr_mini_dump_cb",
    2095,
    "Invalid params dst %pk len %lu",
    a1,
    a2);
  v11 = 0;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return v11;
}
