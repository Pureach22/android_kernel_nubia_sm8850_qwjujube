// positive sp value has been detected, the output may be wrong!
__int64 __fastcall ipahal_nat_entry_size(unsigned int a1, _QWORD *a2)
{
  _BYTE *v2; // x0
  _BYTE *v3; // x0
  _BYTE *v4; // x0
  _BYTE *v5; // x0
  _BYTE *v6; // x0
  _BYTE *v7; // x0
  _BYTE *v8; // x0
  _BYTE *v9; // x0
  _BYTE *v10; // x0
  _BYTE *v11; // x0
  _BYTE *v12; // x0
  _BYTE *v13; // x0
  _BYTE *v14; // x0
  _BYTE *v15; // x0
  _BYTE *v16; // x0
  char *v17; // x21
  _BYTE *v18; // x0
  _BYTE *v19; // x0
  _BYTE *v20; // x0
  _BYTE *v21; // x0
  _BYTE *v22; // x0
  _BYTE *v23; // x0
  _BYTE *v24; // x0
  _BYTE *v25; // x0
  _BYTE *v26; // x0
  _BYTE *v27; // x0
  _BYTE *v28; // x0
  _BYTE *v29; // x0
  _BYTE *v30; // x0
  _BYTE *v31; // x0
  _BYTE *v32; // x0
  _BYTE *v33; // x0
  _BYTE *v34; // x0
  _BYTE *v35; // x0
  _BYTE *v36; // x0
  _BYTE *v37; // x0
  _BYTE *v38; // x0
  _BYTE *v39; // x0
  _BYTE *v40; // x0
  _BYTE *v41; // x0
  _BYTE *v42; // x0
  _BYTE *v43; // x0
  _BYTE *v44; // x0
  _BYTE *v45; // x0
  _BYTE *v46; // x0
  _BYTE *v47; // x0
  _BYTE *v48; // x0
  _DWORD *v49; // x0
  _DWORD *v50; // x0
  _DWORD *v51; // x0
  _DWORD *v52; // x0
  _DWORD *v53; // x0
  _WORD *v54; // x0
  _WORD *v55; // x0
  _WORD *v56; // x0
  int v57; // w19
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x3
  signed __int64 v61; // x19
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 *v64; // x23
  __int64 v65; // x24
  int v66; // w25
  int v67; // w26
  int v68; // w27
  int v69; // w28
  char *v70; // x20
  __int64 ipc_logbuf; // x21
  const char *v73; // x0
  _BYTE *ipc_logbuf_low; // x0
  __int64 v75; // x1
  __int64 v76; // x2
  int v77; // w12
  long double v78; // q0
  __int64 v79; // x21
  const char *v80; // x0
  unsigned int v81; // w8
  __int64 (__fastcall *v82)(long double); // x8
  __int64 v83; // x0
  __int64 result; // x0
  __int64 v85; // x0
  unsigned int *v86; // [xsp-48h] [xbp-50h]
  char *v87; // [xsp-38h] [xbp-40h]

  if ( !a2 )
  {
    _warn_printk("entry_size is NULL\n");
    __break(0x800u);
    return 4294967274LL;
  }
  v70 = (char *)a1;
  if ( a1 >= 4 )
  {
    _warn_printk("requested NAT type %d is invalid\n", a1);
    __break(0x800u);
    return 4294967274LL;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    v73 = ipahal_nat_type_str((unsigned int)v70);
    ipc_log_string(ipc_logbuf, "ipahal %s:%d Get the entry size for NAT type=%s\n", "ipahal_nat_entry_size", 436, v73);
  }
  ipc_logbuf_low = (_BYTE *)ipa3_get_ipc_logbuf_low();
  if ( ipc_logbuf_low )
  {
    v79 = ipa3_get_ipc_logbuf_low();
    v80 = ipahal_nat_type_str((unsigned int)v70);
    v78 = ipc_log_string(v79, "ipahal %s:%d Get the entry size for NAT type=%s\n", "ipahal_nat_entry_size", 436, v80);
  }
  v81 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
  {
    __break(0x5512u);
  }
  else if ( (192LL * v81 + 48 * (unsigned __int64)(unsigned int)v70) >> 7 <= 0x26 )
  {
    v82 = (__int64 (__fastcall *)(long double))ipahal_nat_objs[24 * v81 + 6 * (unsigned int)v70];
    if ( *((_DWORD *)v82 - 1) != -1073338243 )
      __break(0x8228u);
    *a2 = v82(v78);
    if ( ipa3_get_ipc_logbuf() )
    {
      v83 = ipa3_get_ipc_logbuf();
      ipc_log_string(v83, "ipahal %s:%d The entry size is %zu\n", "ipahal_nat_entry_size", 441, *a2);
    }
    result = ipa3_get_ipc_logbuf_low();
    if ( result )
    {
      v85 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v85, "ipahal %s:%d The entry size is %zu\n", "ipahal_nat_entry_size", 441, *a2);
      return 0;
    }
    return result;
  }
  __break(1u);
  if ( v77 )
    return ipahal_nat_is_entry_zeroed(ipc_logbuf_low, v75, v76);
  v2 = ipa_write_8(v81, ipc_logbuf_low);
  v3 = ipa_write_8(*(_BYTE *)(v65 + 275), v2);
  v4 = ipa_write_8(*(_BYTE *)(v65 + 276), v3);
  v5 = ipa_write_8(*(_BYTE *)(v65 + 277), v4);
  v6 = ipa_write_8(*(_BYTE *)(v65 + 278), v5);
  v7 = ipa_write_8(*(_BYTE *)(v65 + 279), v6);
  v8 = ipa_write_8(*(_BYTE *)(v65 + 280), v7);
  v9 = ipa_write_8(*(_BYTE *)(v65 + 281), v8);
  v10 = ipa_write_8(*(_BYTE *)(v65 + 290), v9);
  v11 = ipa_write_8(*(_BYTE *)(v65 + 291), v10);
  v12 = ipa_write_8(*(_BYTE *)(v65 + 292), v11);
  v13 = ipa_write_8(*(_BYTE *)(v65 + 293), v12);
  v14 = ipa_write_8(*(_BYTE *)(v65 + 294), v13);
  v15 = ipa_write_8(*(_BYTE *)(v65 + 295), v14);
  v16 = ipa_write_8(*(_BYTE *)(v65 + 296), v15);
  v17 = ipa_write_8(*(_BYTE *)(v65 + 297), v16);
  if ( v69 != 1 )
  {
    v70 = ipa_write_8(*(_BYTE *)(v65 + 298), v70);
    v18 = ipa_write_8(*(_BYTE *)(v65 + 299), v17);
    v19 = ipa_write_8(*(_BYTE *)(v65 + 300), v18);
    v20 = ipa_write_8(*(_BYTE *)(v65 + 301), v19);
    v21 = ipa_write_8(*(_BYTE *)(v65 + 302), v20);
    v22 = ipa_write_8(*(_BYTE *)(v65 + 303), v21);
    v23 = ipa_write_8(*(_BYTE *)(v65 + 304), v22);
    v24 = ipa_write_8(*(_BYTE *)(v65 + 305), v23);
    v25 = ipa_write_8(*(_BYTE *)(v65 + 306), v24);
    v26 = ipa_write_8(*(_BYTE *)(v65 + 315), v25);
    v27 = ipa_write_8(*(_BYTE *)(v65 + 316), v26);
    v28 = ipa_write_8(*(_BYTE *)(v65 + 317), v27);
    v29 = ipa_write_8(*(_BYTE *)(v65 + 318), v28);
    v30 = ipa_write_8(*(_BYTE *)(v65 + 319), v29);
    v31 = ipa_write_8(*(_BYTE *)(v65 + 320), v30);
    v32 = ipa_write_8(*(_BYTE *)(v65 + 321), v31);
    v33 = ipa_write_8(*(_BYTE *)(v65 + 322), v32);
    v34 = ipa_write_8(*(_BYTE *)(v65 + 307), v33);
    v35 = ipa_write_8(*(_BYTE *)(v65 + 308), v34);
    v36 = ipa_write_8(*(_BYTE *)(v65 + 309), v35);
    v37 = ipa_write_8(*(_BYTE *)(v65 + 310), v36);
    v38 = ipa_write_8(*(_BYTE *)(v65 + 311), v37);
    v39 = ipa_write_8(*(_BYTE *)(v65 + 312), v38);
    v40 = ipa_write_8(*(_BYTE *)(v65 + 313), v39);
    v41 = ipa_write_8(*(_BYTE *)(v65 + 314), v40);
    v42 = ipa_write_8(*(_BYTE *)(v65 + 323), v41);
    v43 = ipa_write_8(*(_BYTE *)(v65 + 324), v42);
    v44 = ipa_write_8(*(_BYTE *)(v65 + 325), v43);
    v45 = ipa_write_8(*(_BYTE *)(v65 + 326), v44);
    v46 = ipa_write_8(*(_BYTE *)(v65 + 327), v45);
    v47 = ipa_write_8(*(_BYTE *)(v65 + 328), v46);
    v48 = ipa_write_8(*(_BYTE *)(v65 + 329), v47);
    v17 = ipa_write_8(*(_BYTE *)(v65 + 330), v48);
  }
  if ( v68 )
  {
    v70 = ipa_write_8(*(_BYTE *)(v65 + 188), v70);
    v49 = ipa_write_32(*(_DWORD *)(v65 + 192), v17);
    v17 = (char *)ipa_write_32(*(_DWORD *)(v65 + 196), v49);
    if ( v68 != 1 )
    {
      v70 = ipa_write_8(*(_BYTE *)(v65 + 200), v70);
      v50 = ipa_write_32(*(_DWORD *)(v65 + 204), v17);
      v17 = (char *)ipa_write_32(*(_DWORD *)(v65 + 208), v50);
    }
  }
  if ( v67 )
  {
    v70 = ipa_write_8(*(_BYTE *)(v65 + 240), v70);
    v51 = ipa_write_32(*(_DWORD *)(v65 + 244), v17);
    v17 = (char *)ipa_write_32(*(_DWORD *)(v65 + 248), v51);
    if ( v67 != 1 )
    {
      v70 = ipa_write_8(*(_BYTE *)(v65 + 252), v70);
      v52 = ipa_write_32(*(_DWORD *)(v65 + 256), v17);
      v17 = (char *)ipa_write_32(*(_DWORD *)(v65 + 260), v52);
    }
  }
  if ( *(_BYTE *)(v65 + 331) )
  {
    v53 = ipa_write_32(*(_DWORD *)(v65 + 336), v17);
    v17 = (char *)ipa_write_32(*(_DWORD *)(v65 + 340), v53);
  }
  if ( v66 )
  {
    v70 = ipa_write_8(*(_BYTE *)(v65 + 172), v70);
    v54 = ipa_write_16(*(_WORD *)(v65 + 176), v17);
    v17 = (char *)ipa_write_16(*(_WORD *)(v65 + 174), v54);
    if ( v66 != 1 )
    {
      v70 = ipa_write_8(*(_BYTE *)(v65 + 178), v70);
      v55 = ipa_write_16(*(_WORD *)(v65 + 182), v17);
      v17 = (char *)ipa_write_16(*(_WORD *)(v65 + 180), v55);
    }
  }
  if ( *(_BYTE *)(v65 + 226) )
  {
    v70 = ipa_write_8(*(_BYTE *)(v65 + 228), v70);
    v17 = (char *)ipa_write_32(*(_DWORD *)(v65 + 232), v17);
  }
  if ( *(_BYTE *)(v65 + 220) )
  {
    v70 = ipa_write_8(*(_BYTE *)(v65 + 222), v70);
    v56 = ipa_write_16(*(_WORD *)(v65 + 224), v17);
    v17 = (char *)ipa_write_16(0, v56);
  }
  if ( *(_BYTE *)(v65 + 214) )
    v17 = (char *)ipa_write_32(*(_DWORD *)(v65 + 216) & 0xFFFFF, v17);
  if ( v70 )
    ipa_pad_to_64(v70);
  v87 = ipa_pad_to_64(v17);
  v57 = *(unsigned __int16 *)(a2[3] + 164LL);
  *(_WORD *)v64 = v57;
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v58 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v58,
      "ipahal %s:%d en_rule=0x%x, action=%d, rt_idx=%d, retain_hdr=%d\n",
      "ipa_flt_gen_hw_rule_ipav5_5",
      925,
      v57,
      ((unsigned __int64)*v64 >> 52) & 0x1F,
      (unsigned __int8)BYTE2(*v64),
      (*v64 & 0x4000000000000000LL) != 0);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v59 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v59,
      "ipahal %s:%d priority=%d, rule_id=%d, pdn=%d, set_metadata=%d\n",
      "ipa_flt_gen_hw_rule_ipav5_5",
      930,
      (unsigned __int8)BYTE4(*v64),
      ((unsigned __int64)*v64 >> 42) & 0x3FF,
      ((unsigned __int64)*v64 >> 57) & 0xF,
      (*v64 & 0x2000000000000000LL) != 0);
  }
  ipa_write_64(*v64, v64);
  v60 = *v86;
  if ( (_DWORD)v60 )
  {
    v61 = v87 - (char *)v64;
    if ( v87 - (char *)v64 == v60 )
    {
      result = 0;
    }
    else
    {
      printk(&unk_3B3D90, "ipa_flt_gen_hw_rule_ipav5_5");
      if ( ipa3_get_ipc_logbuf() )
      {
        v62 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v62,
          "ipahal %s:%d hw_len differs b/w passed=0x%x calc=%td\n",
          "ipa_flt_gen_hw_rule_ipav5_5",
          938,
          *v86,
          v61);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v63 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v63,
          "ipahal %s:%d hw_len differs b/w passed=0x%x calc=%td\n",
          "ipa_flt_gen_hw_rule_ipav5_5",
          938,
          *v86,
          v61);
      }
      result = 0xFFFFFFFFLL;
    }
  }
  else
  {
    result = 0;
    *v86 = (_DWORD)v87 - (_DWORD)v64;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
