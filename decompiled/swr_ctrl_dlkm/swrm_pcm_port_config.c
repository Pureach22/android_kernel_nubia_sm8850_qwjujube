__int64 __fastcall swrm_pcm_port_config(__int64 result, unsigned __int8 a2, __int64 **a3, char a4)
{
  int v4; // w20
  __int64 v5; // x19
  int v6; // w21
  __int16 v7; // w20
  unsigned int v8; // w8
  __int64 **v11; // x10
  unsigned int v12; // w11
  int v13; // w17
  int v14; // w0
  int v15; // w0
  __int64 v16; // x0
  unsigned int v17; // w2

  v4 = a2;
  v5 = result;
  if ( *((_BYTE *)a3 + 30) )
    v6 = 16;
  else
    v6 = 8;
  if ( (unsigned int)a2 - 14 <= 0xFFFFFFF2 )
  {
    result = __ratelimit(&swrm_pcm_port_config__rs, "swrm_pcm_port_config");
    if ( (_DWORD)result )
      return dev_err(*(_QWORD *)(v5 + 8512), "%s: invalid port: %d\n", "swrm_pcm_port_config", v4);
    return result;
  }
  if ( !*((_BYTE *)a3 + 31) )
    return result;
  v7 = a2 << 8;
  if ( (a4 & 1) != 0 )
    v8 = 3;
  else
    v8 = 0;
  result = swr_master_write(result, v7 | 0x1054u, v8);
  v11 = (__int64 **)*a3;
  if ( *a3 == (__int64 *)a3 )
  {
LABEL_22:
    if ( (a4 & 1) == 0 )
      goto LABEL_26;
    return result;
  }
  v12 = *(_DWORD *)(v5 + 9136);
  while ( 1 )
  {
    v13 = *((_DWORD *)v11 + 8);
    if ( v13 > 176399 )
    {
      if ( v13 != 352800 && v13 != 176400 )
        goto LABEL_14;
    }
    else if ( v13 != 44100 && v13 != 88200 )
    {
      goto LABEL_14;
    }
    result = v12 / v13;
    if ( v12 % v13 )
      break;
LABEL_14:
    v11 = (__int64 **)*v11;
    if ( v11 == a3 )
      goto LABEL_22;
  }
  if ( (a4 & 1) != 0 )
  {
    v14 = swr_master_read(v5, v7 | 0x1020u);
    swr_master_write(v5, v7 | 0x1020, v14 | v6);
    v15 = swr_master_read(v5, v7 | 0x1054u);
    swr_master_write(v5, v7 | 0x1054, v15 | 4);
    swr_master_write(v5, v7 | 0x1080, 0x93u);
    v16 = v5;
    v17 = 160;
    return swr_master_write(v16, v7 | 0x1084u, v17);
  }
LABEL_26:
  swr_master_write(v5, v7 | 0x1020, 0);
  swr_master_write(v5, v7 | 0x1080, 1u);
  v16 = v5;
  v17 = 1;
  return swr_master_write(v16, v7 | 0x1084u, v17);
}
