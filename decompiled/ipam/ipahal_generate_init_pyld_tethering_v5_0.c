_WORD *__fastcall ipahal_generate_init_pyld_tethering_v5_0(_DWORD *a1, char a2)
{
  _WORD *v3; // x21
  unsigned int v4; // w8
  unsigned int v5; // w9
  unsigned int v6; // w25
  __int64 ipc_logbuf_low; // x0
  __int64 v8; // x20
  _DWORD *v9; // x23
  int v10; // w24
  unsigned int *v11; // x26
  int v13; // w27
  unsigned int v14; // w8
  unsigned int v15; // w9
  __int64 ipc_logbuf; // x0
  _WORD *result; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x1
  unsigned __int64 v21; // x20
  __int16 v22; // w8
  __int64 v23; // x22
  int v24; // w28
  unsigned __int64 v25; // x27
  unsigned int v26; // w8
  unsigned int v27; // w9
  int v29; // w24
  __int64 v30; // x8
  unsigned __int64 v31; // x24
  unsigned __int64 v32; // x26
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  unsigned __int64 StatusReg; // x22
  __int64 v38; // x24
  __int64 v39; // x1
  _WORD *v40; // [xsp+8h] [xbp-8h]

  LOBYTE(v3) = a2;
  v4 = a1[1] - ((a1[1] >> 1) & 0x55555555);
  v5 = *a1 - ((*a1 >> 1) & 0x55555555);
  v6 = ((16843009
       * (((v4 & 0x33333333) + ((v4 >> 2) & 0x33333333) + (((v4 & 0x33333333) + ((v4 >> 2) & 0x33333333)) >> 4))
        & 0xF0F0F0F)) >> 24)
     + ((16843009
       * (((v5 & 0x33333333) + ((v5 >> 2) & 0x33333333) + (((v5 & 0x33333333) + ((v5 >> 2) & 0x33333333)) >> 4))
        & 0xF0F0F0F)) >> 24);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipahal %s:%d prod entries = %d\n",
      "ipahal_generate_init_pyld_tethering_v5_0",
      244,
      v6);
  }
  v8 = 0;
  LODWORD(v9) = 0;
  v10 = 0;
  v11 = a1 + 3;
  do
  {
    if ( (v8 & 0x1F) == 0 && v8 != 0 )
      ++v10;
    if ( v10 <= 1 )
    {
      if ( (unsigned int)v10 > 1 )
        goto LABEL_67;
      v13 = a1[v10];
      if ( ((unsigned int)ipahal_get_ep_bit((unsigned int)v8) & v13) != 0 )
      {
        v14 = *(v11 - 1);
        if ( v14 )
          LODWORD(v9) = (_DWORD)v9
                      + ((16843009
                        * ((((v14 - ((v14 >> 1) & 0x55555555)) & 0x33333333)
                          + (((v14 - ((v14 >> 1) & 0x55555555)) >> 2) & 0x33333333)
                          + ((((v14 - ((v14 >> 1) & 0x55555555)) & 0x33333333)
                            + (((v14 - ((v14 >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4))
                         & 0xF0F0F0F)) >> 24);
        if ( *v11 )
        {
          v15 = *v11;
          LODWORD(v9) = (_DWORD)v9
                      + ((16843009
                        * ((((v15 - ((v15 >> 1) & 0x55555555)) & 0x33333333)
                          + (((v15 - ((v15 >> 1) & 0x55555555)) >> 2) & 0x33333333)
                          + ((((v15 - ((v15 >> 1) & 0x55555555)) & 0x33333333)
                            + (((v15 - ((v15 >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4))
                         & 0xF0F0F0F)) >> 24);
        }
        else if ( !v14 )
        {
          printk(&unk_3E877F, "ipahal_generate_init_pyld_tethering_v5_0");
          if ( ipa3_get_ipc_logbuf() )
          {
            ipc_logbuf = ipa3_get_ipc_logbuf();
            ipc_log_string(
              ipc_logbuf,
              "ipahal %s:%d no cons bitmask for prod %d\n",
              "ipahal_generate_init_pyld_tethering_v5_0",
              262,
              v8);
          }
          result = (_WORD *)ipa3_get_ipc_logbuf_low();
          if ( result )
          {
            v18 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v18,
              "ipahal %s:%d no cons bitmask for prod %d\n",
              "ipahal_generate_init_pyld_tethering_v5_0",
              262,
              v8);
            return nullptr;
          }
          return result;
        }
      }
    }
    ++v8;
    v11 += 2;
  }
  while ( v8 != 36 );
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v19 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v19,
      "ipahal %s:%d sum all entries = %d\n",
      "ipahal_generate_init_pyld_tethering_v5_0",
      267,
      (_DWORD)v9);
  }
  if ( ((unsigned __int8)v3 & 1) != 0 )
    v20 = 2336;
  else
    v20 = 3520;
  v21 = (24 * ((int)v9 + (unsigned __int64)v6)) | 4;
  for ( result = (_WORD *)_kmalloc_noprof(v21, v20); result; *(_QWORD *)(StatusReg + 80) = v38 )
  {
    v22 = (_WORD)v9 + v6;
    v6 *= 3;
    v23 = 0;
    v24 = 0;
    v9 = a1 + 3;
    v25 = 4;
    v40 = result;
    *result = 24 * v22;
    v3 = result + 2;
    while ( 1 )
    {
      if ( (v23 & 0x1F) == 0 && v23 != 0 )
        ++v24;
      if ( v24 > 1 )
        goto LABEL_30;
      if ( (unsigned int)v24 > 1 )
        goto LABEL_67;
      v29 = a1[v24];
      if ( ((unsigned int)ipahal_get_ep_bit((unsigned int)v23) & v29) == 0 )
        goto LABEL_30;
      if ( (v25 & 0x8000000000000000LL) != 0 )
        break;
      if ( v21 < v25 )
        break;
      if ( v21 - v25 < 8 )
        break;
      v30 = *(unsigned int *)((char *)v9 - 2);
      *(_DWORD *)v3 = v30;
      if ( v21 < v25 )
        break;
      if ( v21 - v25 < 8 )
        break;
      v31 = v25 + 8;
      *(_QWORD *)v3 = v30 & 0xFFFF0000FFFFFFFFLL | ((unsigned __int64)(unsigned __int16)HIWORD(*v9) << 32);
      if ( ((v25 + 8) & 0x8000000000000000LL) != 0 )
        break;
      if ( v21 < v25 + 8 )
        break;
      if ( v21 - (v25 + 8) < 8 )
        break;
      v32 = v25 + 16;
      *((_QWORD *)v3 + 1) = 0;
      if ( ((v25 + 16) & 0x8000000000000000LL) != 0 || v21 < v25 + 16 || v21 - (v25 + 16) < 8 )
        break;
      *((_DWORD *)v3 + 4) = v6;
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v33 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v33, "ipahal %s:%d Pipe: %d\n", "ipahal_generate_init_pyld_tethering_v5_0", 315, v23);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v34 = ipa3_get_ipc_logbuf_low();
        if ( v21 < v25 || v21 - v25 < 8 )
          break;
        ipc_log_string(
          v34,
          "ipahal %s:%d hdr->dst_mask_31_0=[0x%x], hdr->dst_mask_63_32=[0x%x]\n",
          "ipahal_generate_init_pyld_tethering_v5_0",
          317,
          *(_DWORD *)v3,
          *((_DWORD *)v3 + 1));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v35 = ipa3_get_ipc_logbuf_low();
        if ( v21 < v31 || v21 - v31 < 8 )
          break;
        ipc_log_string(
          v35,
          "ipahal %s:%d hdr->dst_mask_95_64=[0x%x], hdr->dst_mask_127_96=[0x%x]\n",
          "ipahal_generate_init_pyld_tethering_v5_0",
          319,
          *((_DWORD *)v3 + 2),
          *((_DWORD *)v3 + 3));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v36 = ipa3_get_ipc_logbuf_low();
        if ( v21 < v32 || v21 - v32 < 8 )
          break;
        ipc_log_string(
          v36,
          "ipahal %s:%d hdr->offset=0x%x\n",
          "ipahal_generate_init_pyld_tethering_v5_0",
          320,
          *((_DWORD *)v3 + 4));
      }
      v25 += 24LL;
      v3 += 12;
      v26 = *v9 - ((*v9 >> 1) & 0x55555555);
      v27 = *(v9 - 1) - ((*(v9 - 1) >> 1) & 0x55555555);
      v6 += 3
          * (((16843009
             * (((v26 & 0x33333333) + ((v26 >> 2) & 0x33333333) + (((v26 & 0x33333333) + ((v26 >> 2) & 0x33333333)) >> 4))
              & 0xF0F0F0F)) >> 24)
           + ((16843009
             * (((v27 & 0x33333333) + ((v27 >> 2) & 0x33333333) + (((v27 & 0x33333333) + ((v27 >> 2) & 0x33333333)) >> 4))
              & 0xF0F0F0F)) >> 24));
LABEL_30:
      ++v23;
      v9 += 2;
      if ( v23 == 36 )
        return v40;
    }
    __break(1u);
LABEL_67:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v38 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &ipahal_generate_init_pyld_tethering_v5_0__alloc_tag;
    v21 = (24 * ((int)v9 + (unsigned __int64)v6)) | 4;
    if ( ((unsigned __int8)v3 & 1) != 0 )
      v39 = 2336;
    else
      v39 = 3520;
    result = (_WORD *)_kmalloc_noprof((24 * ((int)v9 + (unsigned __int64)v6)) | 4, v39);
  }
  return result;
}
