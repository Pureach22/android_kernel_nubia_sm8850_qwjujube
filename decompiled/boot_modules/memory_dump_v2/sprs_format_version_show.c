__int64 __fastcall sprs_format_version_show(__int64 a1, __int64 a2, const char *a3)
{
  __int64 v3; // x19
  __int64 v5; // x21
  int v6; // w25
  __int64 v7; // x8
  int v8; // w23
  size_t v9; // x24
  size_t v10; // x0
  size_t v11; // x2
  __int64 v12; // x27
  __int64 result; // x0
  char string[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v15; // [xsp+10h] [xbp-40h]
  __int64 v16; // [xsp+18h] [xbp-38h]
  __int64 v17; // [xsp+20h] [xbp-30h]
  __int64 v18; // [xsp+28h] [xbp-28h]
  __int64 v19; // [xsp+30h] [xbp-20h]
  __int64 v20; // [xsp+38h] [xbp-18h]
  __int64 v21; // [xsp+40h] [xbp-10h]
  __int64 v22; // [xsp+48h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 152);
  *a3 = 0;
  if ( v3 )
  {
    v20 = 0;
    v21 = 0;
    v18 = 0;
    v19 = 0;
    v16 = 0;
    v17 = 0;
    *(_QWORD *)string = 0;
    v15 = 0;
    mutex_lock(v3);
    v5 = 0;
    v6 = 0;
    do
    {
      v7 = *(_QWORD *)(v3 + 8 * v5 + 64);
      if ( v7 )
      {
        v8 = scnprintf(string, 64, "SPR data format version for cpu%d is %d\n", v5, *(_DWORD *)(*(_QWORD *)v7 + 4LL));
        v9 = strnlen(a3, 0x1000u);
        if ( v9 == -1 )
          goto LABEL_22;
        v10 = strnlen(string, 0x40u);
        if ( v10 >= 0x41 )
          goto LABEL_21;
        if ( v10 == 64 )
        {
          v10 = _fortify_panic(4, 64, 65);
LABEL_21:
          _fortify_panic(2, 64, v10 + 1);
LABEL_22:
          _fortify_panic(2, -1, v9 + 1);
        }
        if ( v9 <= 0xFFF )
        {
          if ( v10 + v9 >= 0x1000 )
            v11 = 4095 - v9;
          else
            v11 = v10;
          if ( v10 + v9 >= 0x1000 )
            v12 = 4095;
          else
            v12 = v10 + v9;
          memcpy((void *)&a3[v9], string, v11);
          a3[v12] = 0;
        }
        v6 += v8;
      }
      ++v5;
    }
    while ( v5 != 8 );
    mutex_unlock(v3);
    result = v6;
  }
  else
  {
    result = -14;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
