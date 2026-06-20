_WORD *__fastcall ipahal_generate_init_pyld_tethering(_DWORD *a1, char a2)
{
  __int64 v3; // x22
  unsigned int v4; // w8
  __int64 v5; // x20
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x21
  int v8; // w23
  __int64 v9; // x9
  unsigned int v10; // w10
  __int64 v11; // x0
  unsigned __int64 v12; // x21
  __int64 v13; // x1
  _WORD *result; // x0
  __int64 v15; // x26
  __int16 v16; // w8
  unsigned __int64 v17; // x28
  _DWORD *v18; // x27
  unsigned int v19; // w8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 ipc_logbuf; // x0
  __int64 v23; // x0
  unsigned __int64 StatusReg; // x24
  __int64 v25; // x25
  __int64 v26; // x1
  _WORD *v27; // [xsp+8h] [xbp-8h]

  LOBYTE(v3) = a2;
  v4 = *a1 - ((*a1 >> 1) & 0x55555555);
  v5 = (16843009
      * (((v4 & 0x33333333) + ((v4 >> 2) & 0x33333333) + (((v4 & 0x33333333) + ((v4 >> 2) & 0x33333333)) >> 4))
       & 0xF0F0F0F)) >> 24;
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d prod entries = %d\n", "ipahal_generate_init_pyld_tethering", 184, v5);
  }
  v7 = 0;
  v8 = 0;
  v9 = 2;
  do
  {
    if ( ((*a1 >> v7) & 1) != 0 )
    {
      v10 = a1[v9];
      if ( !v10 )
      {
        printk(&unk_3E877F, "ipahal_generate_init_pyld_tethering");
        if ( ipa3_get_ipc_logbuf() )
        {
          ipc_logbuf = ipa3_get_ipc_logbuf();
          ipc_log_string(
            ipc_logbuf,
            "ipahal %s:%d no cons bitmask for prod %d\n",
            "ipahal_generate_init_pyld_tethering",
            188,
            v7);
        }
        result = (_WORD *)ipa3_get_ipc_logbuf_low();
        if ( result )
        {
          v23 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v23,
            "ipahal %s:%d no cons bitmask for prod %d\n",
            "ipahal_generate_init_pyld_tethering",
            188,
            v7);
          return nullptr;
        }
        return result;
      }
      v8 += (16843009
           * ((((v10 - ((v10 >> 1) & 0x55555555)) & 0x33333333)
             + (((v10 - ((v10 >> 1) & 0x55555555)) >> 2) & 0x33333333)
             + ((((v10 - ((v10 >> 1) & 0x55555555)) & 0x33333333)
               + (((v10 - ((v10 >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4))
            & 0xF0F0F0F)) >> 24;
    }
    ++v7;
    v9 += 2;
  }
  while ( v7 != 32 );
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v11 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v11, "ipahal %s:%d sum all entries = %d\n", "ipahal_generate_init_pyld_tethering", 194, v8);
  }
  v12 = ((8 * (_DWORD)v5) | 4u) + 24LL * v8;
  if ( (v3 & 1) != 0 )
    v13 = 2336;
  else
    v13 = 3520;
  result = (_WORD *)_kmalloc_noprof(((8 * (_DWORD)v5) | 4u) + 24LL * v8, v13);
  if ( result )
  {
    while ( v12 < 2 )
    {
LABEL_36:
      __break(1u);
      v12 = ((8 * (_DWORD)v5) | 4u) + 24LL * v8;
      StatusReg = _ReadStatusReg(SP_EL0);
      v25 = *(_QWORD *)(StatusReg + 80);
      if ( (v3 & 1) != 0 )
        v26 = 2336;
      else
        v26 = 3520;
      *(_QWORD *)(StatusReg + 80) = &ipahal_generate_init_pyld_tethering__alloc_tag;
      result = (_WORD *)_kmalloc_noprof(((8 * (_DWORD)v5) | 4u) + 24LL * v8, v26);
      *(_QWORD *)(StatusReg + 80) = v25;
      if ( !result )
        return result;
    }
    v15 = 0;
    v16 = 24 * v8;
    v17 = 4;
    v3 = 8;
    v8 = 16843009;
    v27 = result;
    *result = v16 + 8 * v5;
    v18 = result + 2;
    do
    {
      if ( ((*a1 >> v15) & 1) != 0 )
      {
        if ( (v17 & 0x8000000000000000LL) != 0 || v12 < v17 || v12 - v17 < 8 )
          goto LABEL_36;
        *(_QWORD *)v18 = (unsigned int)a1[(unsigned __int64)v3 / 4] | (unsigned __int64)(v5 << 32);
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v20 = ipa3_get_ipc_logbuf_low();
          if ( v12 < v17 || v12 - v17 < 8 )
            goto LABEL_36;
          ipc_log_string(v20, "ipahal %s:%d hdr->dst_mask=0x%x\n", "ipahal_generate_init_pyld_tethering", 216, *v18);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v21 = ipa3_get_ipc_logbuf_low();
          if ( v12 < v17 || v12 - v17 < 8 )
            goto LABEL_36;
          ipc_log_string(v21, "ipahal %s:%d hdr->offset=0x%x\n", "ipahal_generate_init_pyld_tethering", 217, v18[1]);
        }
        v17 += 8LL;
        v18 += 2;
        v19 = a1[(unsigned __int64)v3 / 4] - ((a1[(unsigned __int64)v3 / 4] >> 1) & 0x55555555);
        v5 = 3
           * ((16843009
             * (((v19 & 0x33333333) + ((v19 >> 2) & 0x33333333) + (((v19 & 0x33333333) + ((v19 >> 2) & 0x33333333)) >> 4))
              & 0xF0F0F0F)) >> 24)
           + (unsigned int)v5;
      }
      ++v15;
      v3 += 8;
    }
    while ( v15 != 32 );
    return v27;
  }
  return result;
}
