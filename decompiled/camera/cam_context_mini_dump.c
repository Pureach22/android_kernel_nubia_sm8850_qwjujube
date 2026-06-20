__int64 __fastcall cam_context_mini_dump(unsigned __int64 a1, __int64 *a2)
{
  unsigned __int64 v2; // x6
  const char *v3; // x5
  __int64 v4; // x2
  __int64 v5; // x4
  __int64 v6; // x7
  __int64 result; // x0
  __int64 v8; // x23
  unsigned __int64 v11; // x21
  _QWORD **v12; // x24
  _QWORD *v13; // x0
  _QWORD *v14; // x26
  _QWORD **v15; // x24
  _QWORD *v16; // x0
  _QWORD *v17; // x26
  _QWORD **v18; // x24
  _QWORD *v19; // x0
  _QWORD *v20; // x26

  _ReadStatusReg(SP_EL0);
  if ( a1 && a2 )
  {
    v2 = a2[1];
    if ( v2 > 0x5F )
    {
      v8 = *a2;
      *(_DWORD *)(v8 + 64) = *(_DWORD *)(a1 + 32);
      v11 = v8 + v2;
      *(_DWORD *)(v8 + 56) = *(_DWORD *)(a1 + 464);
      *(_BYTE *)(v8 + 93) = *(_DWORD *)(a1 + 272);
      *(_QWORD *)(v8 + 48) = *(_QWORD *)(a1 + 24);
      *(_DWORD *)(v8 + 84) = *(_DWORD *)(a1 + 64);
      *(_BYTE *)(v8 + 92) = *(_DWORD *)(a1 + 240);
      *(_DWORD *)(v8 + 80) = *(_DWORD *)(a1 + 56);
      *(_DWORD *)(v8 + 88) = *(_DWORD *)(a1 + 60);
      scnprintf(v8 + 24, 20, (const char *)a1);
      v12 = (_QWORD **)(a1 + 128);
      if ( *(_QWORD *)(a1 + 128) == a1 + 128 || (*(_QWORD *)v8 = v8 + 96, v13 = *v12, *v12 == v12) )
      {
LABEL_10:
        v15 = (_QWORD **)(a1 + 160);
        if ( *(_QWORD *)(a1 + 160) == a1 + 160 || (*(_QWORD *)(v8 + 8) = v8 + 96, v16 = *v15, *v15 == v15) )
        {
LABEL_14:
          v18 = (_QWORD **)(a1 + 144);
          if ( *(_QWORD *)(a1 + 144) != a1 + 144 )
          {
            *(_QWORD *)(v8 + 16) = v8 + 96;
            v19 = *v18;
            if ( *v18 != v18 )
            {
              do
              {
                v20 = (_QWORD *)*v19;
                ++*(_DWORD *)(v8 + 72);
                _cam_context_req_mini_dump();
                if ( v8 + 96 >= v11 )
                  break;
                v19 = v20;
              }
              while ( v20 != v18 );
            }
          }
        }
        else
        {
          while ( 1 )
          {
            v17 = (_QWORD *)*v16;
            ++*(_DWORD *)(v8 + 76);
            _cam_context_req_mini_dump();
            if ( v8 + 96 >= v11 )
              break;
            v16 = v17;
            if ( v17 == v15 )
              goto LABEL_14;
          }
        }
      }
      else
      {
        while ( 1 )
        {
          v14 = (_QWORD *)*v13;
          ++*(_DWORD *)(v8 + 68);
          _cam_context_req_mini_dump();
          if ( v8 + 96 >= v11 )
            break;
          v13 = v14;
          if ( v14 == v12 )
            goto LABEL_10;
        }
      }
      v3 = "Ctx %s bytes_written %lu";
      v4 = 3;
      v5 = 2168;
      v2 = a1;
      v6 = 96;
      a2[2] = 96;
    }
    else
    {
      a2[2] = 0;
      v3 = "Insufficient len %lu, bytes_written %lu";
      v4 = 1;
      v5 = 2107;
      v6 = 0;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64, __int64))cam_print_log)(
      3,
      0x80000,
      v4,
      "cam_context_mini_dump",
      v5,
      v3,
      v2,
      v6);
    result = 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_mini_dump",
      2099,
      "invalid params");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
