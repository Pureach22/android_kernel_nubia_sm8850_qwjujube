__int64 __fastcall swrm_disable_ports(__int64 result, unsigned __int8 a2)
{
  __int64 v2; // x19
  __int16 v3; // w23
  __int64 v4; // x20
  __int16 v5; // w25
  __int64 v6; // x21
  __int64 *i; // x27
  int v8; // w1
  int v9; // w3
  unsigned __int8 v10; // w2
  char v11; // w8

  if ( result && (v2 = *(_QWORD *)(result + 152)) != 0 )
  {
    v3 = (a2 << 6) + 4132;
    v4 = 0;
    v5 = 16 * a2 + 288;
    do
    {
      v6 = v2 + 9152 + 40 * v4;
      if ( (*(_BYTE *)(v6 + 16) & 1) != 0 )
      {
        for ( i = *(__int64 **)v6; i != (__int64 *)v6; i = (__int64 *)*i )
        {
          v8 = *((unsigned __int8 *)i + 24);
          if ( v8 != *((unsigned __int8 *)i + 23) )
          {
            v9 = *(unsigned __int8 *)(v2 + 9050);
            v10 = *((_BYTE *)i - 8);
            v11 = (v9 + 1) & 0xF;
            if ( v9 == 14 )
              v11 = 0;
            *(_BYTE *)(v2 + 9050) = v11;
            swrm_cmd_fifo_wr_cmd(v2, v8, v10, v9, v5 + (*((unsigned __int8 *)i - 6) << 8));
          }
        }
        result = swr_master_write(
                   v2,
                   v3 + ((_WORD)++v4 << 8),
                   (*(unsigned __int8 *)(v6 + 18) << 24)
                 | (*(unsigned __int8 *)(v6 + 20) << 16)
                 | (*(unsigned __int8 *)(v6 + 19) << 8)
                 | (unsigned int)*(unsigned __int8 *)(v6 + 22));
        if ( !*(_BYTE *)(v6 + 18) )
          result = swrm_pcm_port_config(v2, (unsigned int)v4, v6, 0);
      }
      else
      {
        ++v4;
      }
    }
    while ( v4 != 13 );
  }
  else
  {
    result = __ratelimit(&swrm_disable_ports__rs, "swrm_disable_ports");
    if ( (_DWORD)result )
      return printk(&unk_10D41, "swrm_disable_ports");
  }
  return result;
}
