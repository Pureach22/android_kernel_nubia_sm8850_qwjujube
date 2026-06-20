__int64 __fastcall aw22xxx_para_show(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v4; // x24
  __int64 v5; // x22
  int v6; // w0
  unsigned __int64 v7; // x23
  int v8; // w0
  __int64 v10; // x0

  if ( write_idx )
  {
    v4 = 0;
    v5 = 0;
    while ( 1 )
    {
      v7 = v4 >> 3;
      if ( -1030792151 * (unsigned int)(unsigned __int16)v4 > 0xA3D70A3 )
      {
        if ( v7 > 0xC34 )
          goto LABEL_11;
      }
      else
      {
        v8 = snprintf((char *)(a3 + v5), 4096 - v5, "\r\n");
        if ( v7 >= 0xC35 )
        {
LABEL_11:
          __break(0x5512u);
          v10 = MEMORY[0x71110C8]();
          return aw22xxx_para_store(v10);
        }
        v5 += v8;
      }
      v6 = snprintf((char *)(a3 + v5), 4096 - v5, "%d  ", (unsigned __int8)user_para_data[v4++]);
      v5 += v6;
      if ( v4 >= (unsigned int)(25 * write_idx) )
        return v5 + snprintf((char *)(a3 + v5), 4096 - v5, "\r\n");
    }
  }
  return 0;
}
