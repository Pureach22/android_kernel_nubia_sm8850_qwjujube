__int64 __fastcall cam_spi_write(__int64 a1, int a2, unsigned int a3, int a4, int a5)
{
  unsigned int v5; // w8
  __int64 v7; // x8
  char v11; // w9
  char v12; // w10
  int v13; // w25
  unsigned __int8 v14; // w23
  unsigned int v15; // w24
  void *v16; // x23
  int v17; // w0
  unsigned int v18; // w19
  unsigned int v20; // [xsp+10h] [xbp-10h] BYREF
  char v21; // [xsp+14h] [xbp-Ch]
  __int64 v22; // [xsp+18h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = -22;
  if ( (unsigned int)(a4 - 5) >= 0xFFFFFFFC && (unsigned int)(a5 - 5) >= 0xFFFFFFFC )
  {
    v7 = *(_QWORD *)(a1 + 24);
    v11 = *(_BYTE *)(v7 + 24);
    v12 = *(_BYTE *)(v7 + 25);
    v13 = a1;
    v21 = 0;
    v20 = 0;
    v14 = v11 + v12 + 1;
    if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000000000LL,
        4,
        "cam_spi_write",
        464,
        "Data: 0x%x",
        a3);
    v15 = a5 + v14;
    v16 = (void *)_kmalloc_noprof(v15, 3265);
    if ( v16 )
    {
      if ( a5 == 3 )
      {
        BYTE2(v20) = a3;
        v17 = v13;
        LOBYTE(v20) = BYTE2(a3);
        BYTE1(v20) = BYTE1(a3);
      }
      else
      {
        v17 = v13;
        if ( a5 == 2 )
        {
          LOWORD(v20) = bswap32(a3) >> 16;
        }
        else if ( a5 == 1 )
        {
          LOBYTE(v20) = a3;
          if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x4000000000LL,
              4,
              "cam_spi_write",
              472,
              "Byte %d: 0x%x",
              v15,
              (unsigned __int8)a3);
            v17 = v13;
          }
        }
        else
        {
          v20 = bswap32(a3);
        }
      }
      v18 = cam_spi_page_program(v17, a2, (int)&v20, a4, a5, v16);
      if ( (v18 & 0x80000000) != 0 )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x4000000000LL,
          1,
          "cam_spi_write",
          496,
          "error write");
      kfree(v16);
      v5 = v18;
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x4000000000LL,
        1,
        "cam_spi_write",
        493,
        "memory allocation failed");
      v5 = -12;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
