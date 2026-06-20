__int64 __fastcall cam_req_mgr_core_mini_dump_cb(__int64 a1, unsigned __int64 a2)
{
  int v4; // w22
  _BYTE *v5; // x23
  __int64 v6; // x24
  unsigned __int64 v7; // x8
  char *v8; // x26
  __int64 v9; // x21
  __int64 v10; // x28
  char *v11; // x25
  __int64 v12; // x8
  __int64 v13; // x10
  __int64 v14; // x11
  __int64 v15; // x8
  __int64 v16; // x10
  __int64 v17; // x11
  __int64 v18; // x8
  __int64 v19; // x10
  __int64 v20; // x11
  __int64 v21; // x8
  __int64 v22; // x10
  __int64 v23; // x11
  int *v24; // x26
  int v25; // w8
  int *v26; // x26
  int v27; // w8
  int *v28; // x26
  int v29; // w8
  int *v30; // x26
  int v31; // w8

  if ( a1 && a2 > 0x27 )
  {
    v4 = 0;
    v5 = (_BYTE *)(a1 + 12288);
    v6 = a1 + 40;
    v7 = a2 - 40;
    v8 = (char *)&g_links;
    v9 = 40;
    v10 = 8;
    *(_DWORD *)(a1 + 32) = 0;
    while ( v7 >> 3 > 0x65E )
    {
      v11 = v8 + 0x8000;
      if ( *((_DWORD *)v8 + 8318) )
      {
        *(_QWORD *)a1 = v6;
        v5[794] = v8[33252];
        *(_DWORD *)(a1 + 13052) = *((_DWORD *)v8 + 8312);
        *(_QWORD *)(a1 + 13024) = *((_QWORD *)v8 + 4160);
        *(_DWORD *)(a1 + 13032) = *((_QWORD *)v8 + 4158);
        *(_DWORD *)(a1 + 13036) = *((_DWORD *)v8 + 8318);
        *(_DWORD *)(a1 + 13040) = *((_DWORD *)v8 + 8322);
        *(_DWORD *)(a1 + 13044) = *((_DWORD *)v8 + 8335);
        *(_DWORD *)(a1 + 13048) = *((_DWORD *)v8 + 8);
        *(_DWORD *)(a1 + 13060) = *(_DWORD *)v8;
        *(_DWORD *)(a1 + 13064) = *((_DWORD *)v8 + 1);
        *(_DWORD *)(a1 + 13068) = *((_DWORD *)v8 + 2);
        v5[788] = v8[33312];
        *(_DWORD *)(a1 + 13072) = *((_DWORD *)v8 + 8288);
        v5[789] = v8[33292];
        v5[790] = v8[33344];
        v5[791] = v8[33276];
        v5[792] = v8[33277];
        v5[793] = v8[33278];
        v5[795] = v8[33360];
        *(_QWORD *)(a1 + 64) = *((_QWORD *)v8 + 9);
        v12 = *((_QWORD *)v8 + 13);
        v13 = *((_QWORD *)v8 + 10);
        v14 = *((_QWORD *)v8 + 11);
        *(_QWORD *)(a1 + 88) = *((_QWORD *)v8 + 12);
        *(_QWORD *)(a1 + 96) = v12;
        *(_QWORD *)(a1 + 72) = v13;
        *(_QWORD *)(a1 + 80) = v14;
        v15 = *((_QWORD *)v8 + 17);
        v16 = *((_QWORD *)v8 + 14);
        v17 = *((_QWORD *)v8 + 15);
        *(_QWORD *)(a1 + 120) = *((_QWORD *)v8 + 16);
        *(_QWORD *)(a1 + 128) = v15;
        *(_QWORD *)(a1 + 104) = v16;
        *(_QWORD *)(a1 + 112) = v17;
        *(_QWORD *)(a1 + 136) = *((_QWORD *)v8 + 18);
        v18 = *((_QWORD *)v8 + 22);
        v19 = *((_QWORD *)v8 + 19);
        v20 = *((_QWORD *)v8 + 20);
        *(_QWORD *)(a1 + 160) = *((_QWORD *)v8 + 21);
        *(_QWORD *)(a1 + 168) = v18;
        *(_QWORD *)(a1 + 144) = v19;
        *(_QWORD *)(a1 + 152) = v20;
        v21 = *((_QWORD *)v8 + 26);
        v22 = *((_QWORD *)v8 + 23);
        v23 = *((_QWORD *)v8 + 24);
        *(_QWORD *)(a1 + 192) = *((_QWORD *)v8 + 25);
        *(_QWORD *)(a1 + 200) = v21;
        *(_QWORD *)(a1 + 176) = v22;
        *(_QWORD *)(a1 + 184) = v23;
        memcpy((void *)(a1 + 208), *((const void **)v8 + 6), 0xD98u);
        *(_DWORD *)(a1 + 13016) = *((_DWORD *)v8 + 16);
        *(_QWORD *)(a1 + 40) = *(_QWORD *)(*((_QWORD *)v8 + 3) + 48LL);
        *(_DWORD *)(a1 + 48) = *(_DWORD *)(*((_QWORD *)v8 + 3) + 240LL);
        *(_DWORD *)(a1 + 52) = *(_DWORD *)(*((_QWORD *)v8 + 3) + 244LL);
        *(_DWORD *)(a1 + 56) = *(_DWORD *)(*((_QWORD *)v8 + 3) + 304LL);
        v24 = *((int **)v8 + 7);
        if ( v24 )
        {
          v25 = *v24;
          *(_DWORD *)(a1 + 3688) = *v24;
          *(_DWORD *)(a1 + 3692) = v25;
          *(_DWORD *)(a1 + 3696) = v24[2];
          *(_DWORD *)(a1 + 3700) = v24[3];
          *(_DWORD *)(a1 + 3704) = v24[4];
          *(_DWORD *)(a1 + 3708) = v24[8];
          *(_DWORD *)(a1 + 3712) = v24[9];
          memcpy((void *)(a1 + 3716), v24 + 10, 0x900u);
          v26 = *((int **)v24 + 3);
          if ( v26 )
          {
            v27 = *v26;
            *(_DWORD *)(a1 + 6020) = *v26;
            *(_DWORD *)(a1 + 6024) = v27;
            *(_DWORD *)(a1 + 6028) = v26[2];
            *(_DWORD *)(a1 + 6032) = v26[3];
            *(_DWORD *)(a1 + 6036) = v26[4];
            *(_DWORD *)(a1 + 6040) = v26[8];
            *(_DWORD *)(a1 + 6044) = v26[9];
            memcpy((void *)(a1 + 6048), v26 + 10, 0x900u);
            v28 = *((int **)v26 + 3);
            if ( v28 )
            {
              v29 = *v28;
              *(_DWORD *)(a1 + 8352) = *v28;
              *(_DWORD *)(a1 + 8356) = v29;
              *(_DWORD *)(a1 + 8360) = v28[2];
              *(_DWORD *)(a1 + 8364) = v28[3];
              *(_DWORD *)(a1 + 8368) = v28[4];
              *(_DWORD *)(a1 + 8372) = v28[8];
              *(_DWORD *)(a1 + 8376) = v28[9];
              memcpy((void *)(a1 + 8380), v28 + 10, 0x900u);
              v30 = *((int **)v28 + 3);
              if ( v30 )
              {
                v31 = *v30;
                *(_DWORD *)(a1 + 10684) = *v30;
                *(_DWORD *)(a1 + 10688) = v31;
                *(_DWORD *)(a1 + 10692) = v30[2];
                *(_DWORD *)(a1 + 10696) = v30[3];
                *(_DWORD *)(a1 + 10700) = v30[4];
                *(_DWORD *)(a1 + 10704) = v30[8];
                *(_DWORD *)(a1 + 10708) = v30[9];
                memcpy((void *)(a1 + 10712), v30 + 10, 0x900u);
                if ( *((_QWORD *)v30 + 3) )
                {
                  __break(0x5512u);
                  goto LABEL_14;
                }
              }
            }
          }
        }
        ++v4;
        v9 += 13048;
        *(_DWORD *)(a1 + 32) = v4;
        v7 = a2 - v9;
      }
      --v10;
      v8 = v11 + 632;
      if ( !v10 )
        return v9;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_core_mini_dump_cb",
      6171,
      "Insufficent received length: %lu, dumped_len %lu",
      a2,
      v9);
  }
  else
  {
LABEL_14:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_core_mini_dump_cb",
      6157,
      "Insufficient received length %lu dumped len: %u",
      a2,
      0);
    return 0;
  }
  return v9;
}
