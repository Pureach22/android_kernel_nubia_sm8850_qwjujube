_WORD *__fastcall ipahal_generate_init_pyld_flt_rt(__int64 a1, char a2)
{
  __int64 v4; // x9
  int v5; // w8
  int v6; // w10
  unsigned int *v7; // x12
  unsigned int v8; // w13
  unsigned int v9; // w13
  int v10; // w22
  __int64 v11; // x0
  __int64 v12; // x23
  __int64 v13; // x20
  unsigned int v14; // w9
  __int64 v16; // x0
  __int64 v17; // x1
  unsigned __int64 v18; // x21
  _WORD *result; // x0
  unsigned int *v20; // x8
  unsigned __int64 v21; // x10
  unsigned __int64 v22; // x9
  unsigned __int64 v23; // x11
  bool v24; // cf
  unsigned int v25; // t1
  unsigned int v26; // w14
  _WORD *v27; // x15
  unsigned __int64 v28; // x13
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned __int64 StatusReg; // x24
  __int64 v32; // x25
  __int64 v33; // x8
  __int64 v34; // x1
  __int64 v35; // x0
  __int64 v36; // x0

  v4 = 0;
  v5 = 0;
  v6 = 0;
  do
  {
    v7 = (unsigned int *)(a1 + v4);
    v4 += 8;
    v8 = *v7;
    LODWORD(v7) = v7[1] - ((v7[1] >> 1) & 0x55555555);
    v9 = ((v8 - ((v8 >> 1) & 0x55555555)) & 0x33333333) + (((v8 - ((v8 >> 1) & 0x55555555)) >> 2) & 0x33333333);
    v5 += (16843009 * ((v9 + (v9 >> 4)) & 0xF0F0F0F)) >> 24;
    v6 += (16843009
         * ((((unsigned int)v7 & 0x33333333)
           + (((unsigned int)v7 >> 2) & 0x33333333)
           + ((((unsigned int)v7 & 0x33333333) + (((unsigned int)v7 >> 2) & 0x33333333)) >> 4))
          & 0xF0F0F0F)) >> 24;
  }
  while ( v4 != 128 );
  v10 = v6 + v5;
  if ( !(v6 + v5) )
  {
    printk(&unk_3B6F58, "ipahal_generate_init_pyld_flt_rt");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d no rule ids provided\n", "ipahal_generate_init_pyld_flt_rt", 676);
    }
    result = (_WORD *)ipa3_get_ipc_logbuf_low();
    if ( !result )
      return result;
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d no rule ids provided\n", "ipahal_generate_init_pyld_flt_rt", 676);
    return nullptr;
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v11 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v11, "ipahal %s:%d num_rules = %d\n", "ipahal_generate_init_pyld_flt_rt", 679, v10);
  }
  v12 = 0;
  v13 = 32;
  while ( !*(_DWORD *)(a1 + 4 * v12) )
  {
    ++v12;
    v13 = (unsigned int)(v13 - 1);
    if ( v12 == 32 )
    {
      v13 = 0;
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_18;
      goto LABEL_17;
    }
  }
  if ( (int)v12 > 31 )
  {
LABEL_16:
    if ( !ipa3_get_ipc_logbuf_low() )
      goto LABEL_18;
    goto LABEL_17;
  }
  v14 = 31;
  while ( !*(_DWORD *)(a1 + 4LL * v14) )
  {
    if ( v14-- <= (unsigned int)v12 )
    {
      v13 = (unsigned int)(v13 + v12 - 32);
      goto LABEL_16;
    }
  }
  v13 = (unsigned int)v13 + v14 - 31;
  if ( ipa3_get_ipc_logbuf_low() )
  {
LABEL_17:
    v16 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v16, "ipahal %s:%d hdr_entries = %d\n", "ipahal_generate_init_pyld_flt_rt", 694, v13);
  }
LABEL_18:
  if ( (a2 & 1) != 0 )
    v17 = 2336;
  else
    v17 = 3520;
  v18 = (8LL * (int)v13 + 8LL * v10) | 4;
  result = (_WORD *)_kmalloc_noprof(v18, v17);
  if ( !result )
  {
LABEL_40:
    printk(&unk_3B3E69, "ipahal_generate_init_pyld_flt_rt");
    if ( ipa3_get_ipc_logbuf() )
    {
      v35 = ipa3_get_ipc_logbuf();
      ipc_log_string(v35, "ipahal %s:%d no mem\n", "ipahal_generate_init_pyld_flt_rt", 701);
    }
    result = (_WORD *)ipa3_get_ipc_logbuf_low();
    if ( !result )
      return result;
    v36 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v36, "ipahal %s:%d no mem\n", "ipahal_generate_init_pyld_flt_rt", 701);
    return nullptr;
  }
  while ( 1 )
  {
    *result = 8 * (v13 + v10);
    if ( (int)v12 >= (int)v13 )
      return result;
    v20 = (unsigned int *)(a1 + 4LL * (unsigned int)v12);
    v21 = v18 - 4;
    v22 = (unsigned int)v13 - (unsigned __int64)(unsigned int)v12;
    v23 = 4;
    while ( (v23 & 0x8000000000000000LL) == 0 )
    {
      if ( v18 < v23 )
        break;
      v24 = v21 >= 8;
      v21 -= 8LL;
      if ( !v24 )
        break;
      v25 = *v20++;
      --v22;
      v26 = ((v25 - ((v25 >> 1) & 0x55555555)) & 0x33333333) + (((v25 - ((v25 >> 1) & 0x55555555)) >> 2) & 0x33333333);
      v27 = &result[v23 / 2];
      v23 += 8LL;
      v28 = v25 | ((unsigned __int64)(unsigned __int16)v27[2] << 32) | (v13 << 48);
      v13 = (unsigned int)v13 + ((16843009 * ((v26 + (v26 >> 4)) & 0xF0F0F0F)) >> 24);
      *(_QWORD *)v27 = v28;
      if ( !v22 )
        return result;
    }
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v32 = *(_QWORD *)(StatusReg + 80);
    v33 = 8LL * (int)v13 + 8LL * v10;
    if ( (v18 & 1) != 0 )
      v34 = 2336;
    else
      v34 = 3520;
    *(_QWORD *)(StatusReg + 80) = &ipahal_generate_init_pyld_flt_rt__alloc_tag;
    v18 = v33 | 4;
    result = (_WORD *)_kmalloc_noprof(v33 | 4, v34);
    *(_QWORD *)(StatusReg + 80) = v32;
    if ( !result )
      goto LABEL_40;
  }
}
