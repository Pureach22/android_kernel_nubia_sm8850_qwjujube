__int64 __fastcall ipa_flt_generate_mac_eq(_DWORD *a1, _WORD *a2, _BYTE *a3, __int64 a4)
{
  __int64 v4; // x8
  _BYTE *v5; // x4
  _BYTE *v6; // x17
  char v7; // w11
  __int64 v8; // x9
  __int64 v9; // x17
  __int64 v10; // x3
  unsigned __int64 v11; // x3
  __int64 v12; // x3
  char v13; // w5
  unsigned int v14; // w3
  unsigned __int64 v15; // x6
  unsigned int v16; // w5
  __int64 v17; // x6
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  v4 = 0;
  v5 = nullptr;
  v6 = nullptr;
  v7 = 0;
  v8 = a4 + 101;
  while ( 1 )
  {
    if ( (unsigned int)v4 > 5 )
      return 0xFFFFFFFFLL;
    v14 = *a1 & dword_1E5664[v4];
    if ( v14 )
      break;
LABEL_7:
    if ( (_DWORD)++v4 == 6 )
      return 0;
  }
  v15 = (unsigned __int8)*a3;
  if ( v15 >= 2 )
  {
    printk(&unk_3BFBF4, "ipa_flt_generate_mac_eq");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d ran out of meq128 eq\n", "ipa_flt_generate_mac_eq", 3075);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipahal %s:%d ran out of meq128 eq\n", "ipa_flt_generate_mac_eq", 3075);
    }
    return 0xFFFFFFFFLL;
  }
  v16 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx < 0x1Au )
  {
    v17 = *((int *)&ipa3_0_ofst_meq128 + v15);
    if ( v17 + 152 * (unsigned __int64)v16 + 128 > 0xF6F )
      goto LABEL_33;
    *a2 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v16 + 16] + v17);
    if ( (v14 & 0x40000) == 0 )
    {
      if ( (v14 & 0x20000) != 0 )
      {
        v7 = -8;
      }
      else
      {
        if ( (v14 & 0x100000) != 0 )
        {
          v7 = -22;
          goto LABEL_3;
        }
        if ( (v14 & 0x80000) == 0 )
        {
          if ( !(v14 >> 30) )
          {
            if ( !(v14 >> 29) )
              goto LABEL_5;
            v7 = -10;
            goto LABEL_21;
          }
          v7 = -18;
LABEL_3:
          v9 = 11;
          v10 = 50;
LABEL_4:
          v6 = &a1[v9];
          v5 = (char *)a1 + v10;
LABEL_5:
          v11 = (unsigned __int8)*a3;
          if ( v11 >= 2 )
            goto LABEL_32;
          v12 = v8 + 33 * v11;
          *(_BYTE *)v12 = v7;
          *(_QWORD *)(v12 + 1) = 0;
          *(_QWORD *)(v12 + 17) = 0;
          *(_WORD *)(v12 + 9) = 0;
          *(_BYTE *)(v12 + 16) = *v5;
          *(_BYTE *)(v12 + 15) = v5[1];
          *(_BYTE *)(v12 + 14) = v5[2];
          *(_BYTE *)(v12 + 13) = v5[3];
          *(_BYTE *)(v12 + 12) = v5[4];
          v13 = v5[5];
          *(_WORD *)(v12 + 25) = 0;
          *(_BYTE *)(v12 + 11) = v13;
          *(_BYTE *)(v12 + 32) = *v6;
          *(_BYTE *)(v12 + 31) = v6[1];
          *(_BYTE *)(v12 + 30) = v6[2];
          *(_BYTE *)(v12 + 29) = v6[3];
          *(_BYTE *)(v12 + 28) = v6[4];
          *(_BYTE *)(v12 + 27) = v6[5];
          ++*a3;
          goto LABEL_7;
        }
        v7 = -16;
      }
LABEL_21:
      v9 = 8;
      v10 = 38;
      goto LABEL_4;
    }
    v7 = -14;
    goto LABEL_3;
  }
LABEL_32:
  __break(0x5512u);
LABEL_33:
  __break(1u);
  return ipa_flt_generat_vlan_eq();
}
