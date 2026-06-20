__int64 __fastcall debug_dump_bytes(__int64 a1, unsigned __int16 a2, const char *a3)
{
  int v3; // w21
  __int64 v6; // x25
  unsigned __int16 v7; // w24
  int v8; // w22
  unsigned int v9; // w23
  bool v10; // zf
  __int64 result; // x0
  char s[8]; // [xsp+8h] [xbp-58h] BYREF
  __int16 v13; // [xsp+10h] [xbp-50h]
  _QWORD v14[7]; // [xsp+18h] [xbp-48h] BYREF
  int v15; // [xsp+50h] [xbp-10h]
  __int64 v16; // [xsp+58h] [xbp-8h]

  v3 = a2;
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  memset(v14, 0, sizeof(v14));
  v13 = 0;
  *(_QWORD *)s = 0;
  qdf_trace_msg(56, 2, "%s: <---------Dumping %d Bytes : %s ------>\n", "debug_dump_bytes", a2, a3);
  if ( v3 )
  {
    v6 = 0;
    v7 = 0;
    do
    {
      v8 = 0;
      v9 = 0;
      while ( 1 )
      {
        if ( v9 >= 0x3D )
          __break(0x5512u);
        snprintf((char *)v14 + v9, 60LL - v9, "%02X ", *(unsigned __int8 *)(a1 + v6));
        if ( (unsigned __int16)++v8 == 16 )
          break;
        ++v6;
        v9 += 3;
        if ( a2 == v6 )
        {
          snprintf(s, 0xAu, "%4.4X", v7);
          qdf_trace_msg(56, 2, "%s: [%s]: %s\n", "debug_dump_bytes", s, (const char *)v14);
          goto LABEL_10;
        }
      }
      snprintf(s, 0xAu, "%4.4X", v7);
      qdf_trace_msg(56, 2, "%s: [%s]: %s\n", "debug_dump_bytes", s, (const char *)v14);
      qdf_mem_set((int)v14, 0x3Cu, 0);
      v10 = a2 - 1LL == v6++;
      v7 += 16;
    }
    while ( !v10 );
  }
LABEL_10:
  result = qdf_trace_msg(56, 2, "%s: <------------------------------------------------->\n", "debug_dump_bytes");
  _ReadStatusReg(SP_EL0);
  return result;
}
