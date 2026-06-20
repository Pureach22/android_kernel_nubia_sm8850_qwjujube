const char *__fastcall sde_evtlog_dump_all(const char *result)
{
  const char *v1; // x19
  char *v2; // x23
  const char *v3; // x20
  int v4; // w22
  _BOOL4 v5; // w21
  unsigned int v6; // w26
  int v7; // w25
  unsigned int v8; // w26
  unsigned int v9; // w22
  _BYTE s[512]; // [xsp+8h] [xbp-208h] BYREF
  __int64 v11; // [xsp+208h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
    goto LABEL_25;
  v1 = result;
  v2 = (char *)(result + 786432);
  result = (const char *)memset(s, 0, sizeof(s));
  v3 = *((const char **)v2 + 4);
  v4 = *((_DWORD *)v2 + 6);
  if ( !v3 )
  {
    result = (const char *)_kvmalloc_node_noprof(0x400000, 0, 3520, 0xFFFFFFFFLL);
    v3 = result;
    *((_QWORD *)v2 + 4) = result;
    if ( !result )
      goto LABEL_25;
    *((_DWORD *)v2 + 10) = 0x2000;
  }
  if ( (v4 & 0xA) != 0
    && (word_294380 & 0x100) == 0
    && *((_DWORD *)v2 + 10)
    && (result = (const char *)sde_evtlog_dump_to_buffer(v1, v3, 512, 1, 1), v5 = result == nullptr, result) )
  {
    v3 += 512;
    if ( *((_DWORD *)v2 + 10) < 2u )
    {
      v5 = 0;
      v7 = v4 & 5;
      if ( (v4 & 8) != 0 )
        goto LABEL_16;
      goto LABEL_22;
    }
    v6 = 1;
    do
    {
      result = (const char *)sde_evtlog_dump_to_buffer(v1, v3, 512, 0, 1);
      if ( !result )
        break;
      ++v6;
      v3 += 512;
    }
    while ( v6 < *((_DWORD *)v2 + 10) );
  }
  else
  {
    v5 = 1;
  }
  v7 = v4 & 5;
  if ( (v4 & 8) != 0 )
  {
LABEL_16:
    if ( v3 && HIBYTE(word_294380) == 1 )
    {
      drm_printf(qword_2945A8, "===================evtlog================\n");
      if ( *((_DWORD *)v2 + 10) )
      {
        v8 = 0;
        do
        {
          drm_printf(qword_2945A8, "%s", v3);
          ++v8;
          v3 += 512;
        }
        while ( v8 < *((_DWORD *)v2 + 10) );
      }
      result = (const char *)drm_printf(qword_2945A8, "\n");
    }
  }
LABEL_22:
  if ( v7 )
  {
    if ( *((_DWORD *)v2 + 10) )
    {
      result = (const char *)sde_evtlog_dump_to_buffer(v1, s, 512, v5, 0);
      if ( result )
      {
        result = (const char *)printk(&unk_276989, "sde_evtlog_dump_all");
        if ( *((_DWORD *)v2 + 10) >= 2u )
        {
          v9 = 1;
          do
          {
            result = (const char *)sde_evtlog_dump_to_buffer(v1, s, 512, 0, 0);
            if ( !result )
              break;
            result = (const char *)printk(&unk_276989, "sde_evtlog_dump_all");
            ++v9;
          }
          while ( v9 < *((_DWORD *)v2 + 10) );
        }
      }
    }
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
