__int64 __fastcall ipa_fltrt_generate_mac_hw_rule_bdy(_BYTE *a1, _DWORD *a2, _BYTE *a3, _BYTE **a4, _QWORD **a5)
{
  _WORD *v9; // x23
  __int64 v10; // x25
  char *v11; // x26
  char *v12; // x28
  char v13; // w24
  __int64 v14; // x8
  __int64 v15; // x9
  _QWORD *v16; // x0
  _WORD *v17; // x0
  _WORD *v18; // x0
  _BYTE *v19; // x0
  _BYTE *v20; // x0
  _BYTE *v21; // x0
  _BYTE *v22; // x0
  _BYTE *v23; // x0
  _WORD *v24; // x0
  _WORD *v25; // x0
  _BYTE *v26; // x0
  _BYTE *v27; // x0
  _BYTE *v28; // x0
  _BYTE *v29; // x0
  _BYTE *v30; // x0
  unsigned int v31; // w8
  unsigned __int64 v32; // x10
  unsigned int v33; // w9
  __int64 v34; // x10
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  v9 = a1;
  v10 = 0;
  v11 = nullptr;
  v12 = nullptr;
  v13 = 0;
  while ( 1 )
  {
    if ( (unsigned int)v10 > 5 )
      return 0xFFFFFFFFLL;
    v31 = *a2 & dword_1E5664[v10];
    if ( v31 )
      break;
LABEL_6:
    if ( (_DWORD)++v10 == 6 )
      return 0;
  }
  v32 = (unsigned __int8)*a3;
  if ( v32 >= 2 )
  {
    printk(&unk_3BFBF4, "ipa_fltrt_generate_mac_hw_rule_bdy");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d ran out of meq128 eq\n", "ipa_fltrt_generate_mac_hw_rule_bdy", 1438);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipahal %s:%d ran out of meq128 eq\n", "ipa_fltrt_generate_mac_hw_rule_bdy", 1438);
    }
    return 0xFFFFFFFFLL;
  }
  v33 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
    goto LABEL_32;
  v34 = *((int *)&ipa3_0_ofst_meq128 + v32);
  if ( v34 + 152 * (unsigned __int64)v33 + 128 <= 0xF6F )
  {
    *v9 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v33 + 16] + v34);
    if ( (v31 & 0x40000) == 0 )
    {
      if ( (v31 & 0x20000) != 0 )
      {
        v13 = -8;
      }
      else
      {
        if ( (v31 & 0x100000) != 0 )
        {
          v13 = -22;
          goto LABEL_3;
        }
        if ( (v31 & 0x80000) == 0 )
        {
          if ( !(v31 >> 30) )
          {
            if ( !(v31 >> 29) )
              goto LABEL_5;
            v13 = -10;
            goto LABEL_20;
          }
          v13 = -18;
LABEL_3:
          v14 = 11;
          v15 = 50;
LABEL_4:
          v12 = (char *)&a2[v14];
          v11 = (char *)a2 + v15;
LABEL_5:
          *a4 = ipa_write_8(v13, *a4);
          v16 = ipa_write_64(0, *a5);
          *a5 = v16;
          v17 = ipa_write_64(0, v16);
          *a5 = v17;
          v18 = ipa_write_16(0, v17);
          *a5 = v18;
          v19 = ipa_write_8(v11[5], v18);
          *a5 = v19;
          v20 = ipa_write_8(v11[4], v19);
          *a5 = v20;
          v21 = ipa_write_8(v11[3], v20);
          *a5 = v21;
          v22 = ipa_write_8(v11[2], v21);
          *a5 = v22;
          v23 = ipa_write_8(v11[1], v22);
          *a5 = v23;
          v24 = ipa_write_8(*v11, v23);
          *a5 = v24;
          v25 = ipa_write_16(0, v24);
          *a5 = v25;
          v26 = ipa_write_8(v12[5], v25);
          *a5 = v26;
          v27 = ipa_write_8(v12[4], v26);
          *a5 = v27;
          v28 = ipa_write_8(v12[3], v27);
          *a5 = v28;
          v29 = ipa_write_8(v12[2], v28);
          *a5 = v29;
          v30 = ipa_write_8(v12[1], v29);
          *a5 = v30;
          a1 = ipa_write_8(*v12, v30);
          *a5 = a1;
          ++*a3;
          goto LABEL_6;
        }
        v13 = -16;
      }
LABEL_20:
      v14 = 8;
      v15 = 38;
      goto LABEL_4;
    }
    v13 = -14;
    goto LABEL_3;
  }
  __break(1u);
LABEL_32:
  __break(0x5512u);
  return ipa_fltrt_generate_vlan_hw_rule_bdy(a1, a2, a3, a4, a5);
}
