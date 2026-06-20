__int64 __fastcall _cam_isp_ctx_minidump_cb(__int64 a1, __int64 *a2)
{
  unsigned __int64 v3; // x6
  __int64 v4; // x23
  __int64 v5; // x22
  unsigned __int64 v7; // x21
  _QWORD **v8; // x24
  _QWORD *v9; // x0
  _QWORD *v10; // x26
  _QWORD **v12; // x24
  _QWORD *v13; // x0
  _QWORD *v14; // x26
  _QWORD **v15; // x20
  _QWORD **v16; // t1
  _QWORD *v17; // x0
  _QWORD *v18; // x25

  _ReadStatusReg(SP_EL0);
  if ( a1 && a2 )
  {
    v3 = a2[1];
    if ( v3 > 0xC77 )
    {
      v4 = *(_QWORD *)(a1 + 256);
      v5 = *a2;
      v7 = *a2 + v3;
      *(_QWORD *)(v5 + 3096) = *(_QWORD *)(v4 + 37304);
      *(_QWORD *)(v5 + 3104) = *(_QWORD *)(v4 + 37312);
      *(_QWORD *)(v5 + 3112) = *(_QWORD *)(v4 + 37368);
      *(_QWORD *)(v5 + 3120) = *(unsigned int *)(v4 + 45576);
      *(_QWORD *)(v5 + 3128) = *(_QWORD *)(v4 + 8);
      *(_QWORD *)(v5 + 3136) = *(_QWORD *)(v4 + 37328);
      *(_QWORD *)(v5 + 3144) = *(_QWORD *)(v4 + 37352);
      *(_QWORD *)(v5 + 3152) = *(_QWORD *)(v4 + 45608);
      *(_DWORD *)(v5 + 3160) = *(_DWORD *)(v4 + 16);
      *(_BYTE *)(v5 + 3170) = *(_DWORD *)(v4 + 20);
      *(_BYTE *)(v5 + 3164) = *(_DWORD *)(a1 + 32);
      *(_BYTE *)(v5 + 3165) = *(_DWORD *)(v4 + 37344);
      *(_BYTE *)(v5 + 3166) = *(_DWORD *)(v4 + 37376);
      *(_BYTE *)(v5 + 3167) = *(_DWORD *)(v4 + 45580);
      *(_BYTE *)(v5 + 3168) = *(_DWORD *)(v4 + 37320);
      *(_BYTE *)(v5 + 3169) = *(_DWORD *)(v4 + 45600);
      *(_BYTE *)(v5 + 3177) = *(_BYTE *)(v4 + 45736);
      *(_BYTE *)(v5 + 3178) = *(_BYTE *)(v4 + 45737);
      *(_BYTE *)(v5 + 3179) = *(_BYTE *)(v4 + 45740);
      *(_BYTE *)(v5 + 3180) = *(_BYTE *)(v4 + 45741);
      *(_BYTE *)(v5 + 3181) = *(_BYTE *)(v4 + 45742);
      *(_BYTE *)(v5 + 3183) = *(_BYTE *)(v4 + 45744);
      *(_BYTE *)(v5 + 3184) = *(_BYTE *)(v4 + 45745);
      *(_BYTE *)(v5 + 3185) = *(_BYTE *)(v4 + 45747);
      *(_BYTE *)(v5 + 3176) = *(_DWORD *)(v4 + 45560) != 0;
      *(_BYTE *)(v5 + 3172) = *(_DWORD *)(v4 + 24);
      *(_BYTE *)(v5 + 3171) = *(_DWORD *)(v4 + 45584);
      memcpy((void *)(v5 + 24), (const void *)(v4 + 42160), 0x200u);
      memcpy((void *)(v5 + 536), (const void *)(v4 + 42672), 0x200u);
      memcpy((void *)(v5 + 1048), (const void *)(v4 + 43184), 0x200u);
      memcpy((void *)(v5 + 1560), (const void *)(v4 + 43696), 0x200u);
      memcpy((void *)(v5 + 2072), (const void *)(v4 + 44208), 0x200u);
      memcpy((void *)(v5 + 2584), (const void *)(v4 + 44720), 0x200u);
      if ( v5 + 3192 < v7 )
      {
        v8 = (_QWORD **)(a1 + 128);
        if ( *(_QWORD *)(a1 + 128) != a1 + 128 )
        {
          *(_QWORD *)v5 = v5 + 3192;
          v9 = *v8;
          while ( v9 != v8 )
          {
            v10 = (_QWORD *)*v9;
            ++*(_BYTE *)(v5 + 3173);
            _cam_isp_ctx_req_mini_dump();
            v9 = v10;
            if ( v5 + 3192 >= v7 )
              goto LABEL_11;
          }
        }
        v12 = (_QWORD **)(a1 + 160);
        if ( *(_QWORD *)(a1 + 160) != a1 + 160 )
        {
          *(_QWORD *)(v5 + 16) = v5 + 3192;
          v13 = *v12;
          while ( v13 != v12 )
          {
            v14 = (_QWORD *)*v13;
            ++*(_BYTE *)(v5 + 3175);
            _cam_isp_ctx_req_mini_dump();
            v13 = v14;
            if ( v5 + 3192 >= v7 )
              goto LABEL_11;
          }
        }
        v16 = *(_QWORD ***)(a1 + 144);
        v15 = (_QWORD **)(a1 + 144);
        if ( v16 != v15 )
        {
          *(_QWORD *)(v5 + 8) = v5 + 3192;
          v17 = *v15;
          do
          {
            if ( v17 == v15 )
              break;
            v18 = (_QWORD *)*v17;
            ++*(_BYTE *)(v5 + 3174);
            _cam_isp_ctx_req_mini_dump();
            v17 = v18;
          }
          while ( v5 + 3192 < v7 );
        }
      }
LABEL_11:
      a2[2] = 3192;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_minidump_cb",
        413,
        "In sufficient size received %lu required size: %zu",
        v3,
        0xC78u);
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_minidump_cb",
      405,
      "invalid params");
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
