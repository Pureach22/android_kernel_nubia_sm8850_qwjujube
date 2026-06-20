__int64 __fastcall wsa884x_variant_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x9
  int v7; // w9
  const char *v8; // x9
  __int64 result; // x0
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // [xsp+0h] [xbp-30h] BYREF
  __int128 v14; // [xsp+8h] [xbp-28h] BYREF
  __int64 v15; // [xsp+18h] [xbp-18h]
  __int64 v16; // [xsp+20h] [xbp-10h]
  __int64 v17; // [xsp+28h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 64);
  v13 = a6;
  v14 = 0u;
  v15 = 0;
  v16 = 0;
  if ( v6 )
  {
    v7 = *(_DWORD *)(v6 + 216);
    switch ( v7 )
    {
      case 12:
        v12 = *(_QWORD *)"WSA8845H\n";
        WORD4(v14) = 10;
        v11 = 9;
        break;
      case 5:
        v8 = "WSA8845\n";
        goto LABEL_10;
      case 0:
        v8 = "WSA8840\n";
LABEL_10:
        v10 = *(_QWORD *)v8;
        BYTE8(v14) = 0;
        *(_QWORD *)&v14 = v10;
        v11 = 8;
LABEL_14:
        result = simple_read_from_buffer(a4, a5, &v13, &v14, v11);
        goto LABEL_15;
      default:
        v12 = *(_QWORD *)"UNDEFINED\n";
        *(_DWORD *)((char *)&v14 + 7) = 672837;
        v11 = 10;
        break;
    }
    *(_QWORD *)&v14 = v12;
    goto LABEL_14;
  }
  if ( (unsigned int)__ratelimit(&wsa884x_variant_read__rs, "wsa884x_variant_read") )
    printk(&unk_D94C, "wsa884x_variant_read");
  result = -22;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
