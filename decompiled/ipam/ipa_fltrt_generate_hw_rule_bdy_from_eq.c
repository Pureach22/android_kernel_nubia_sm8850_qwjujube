__int64 __fastcall ipa_fltrt_generate_hw_rule_bdy_from_eq(__int64 a1, char **a2)
{
  int v2; // w25
  int v3; // w23
  int v5; // w24
  int v6; // w26
  __int64 v8; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  char *v12; // x21
  char *v13; // x22
  _QWORD *v14; // x8
  char v15; // w0
  _BYTE *v16; // x0
  _BYTE *v17; // x0
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
  _BYTE *v49; // x0
  _BYTE *v50; // x0
  _BYTE *v51; // x0
  _BYTE *v52; // x0
  _BYTE *v53; // x0
  _BYTE *v54; // x0
  _BYTE *v55; // x0
  _BYTE *v56; // x0
  _BYTE *v57; // x0
  _BYTE *v58; // x0
  _BYTE *v59; // x0
  _BYTE *v60; // x0
  _BYTE *v61; // x0
  _BYTE *v62; // x0
  _BYTE *v63; // x0
  _BYTE *v64; // x0
  _BYTE *v65; // x0
  _BYTE *v66; // x0
  _BYTE *v67; // x0
  _BYTE *v68; // x0
  _BYTE *v69; // x0
  _BYTE *v70; // x0
  _BYTE *v71; // x0
  _BYTE *v72; // x0
  _BYTE *v73; // x0
  _BYTE *v74; // x0
  _BYTE *v75; // x0
  _BYTE *v76; // x0
  _BYTE *v77; // x0
  _DWORD *v78; // x0
  _DWORD *v79; // x0
  _DWORD *v80; // x0
  _DWORD *v81; // x0
  _DWORD *v82; // x0
  _WORD *v83; // x0
  _WORD *v84; // x0
  _WORD *v85; // x0
  char *v86; // x8
  __int64 v87; // x0
  __int64 v88; // x0

  v2 = *(unsigned __int8 *)(a1 + 20);
  v3 = *(unsigned __int8 *)(a1 + 6);
  v5 = *(unsigned __int8 *)(a1 + 72);
  v6 = *(unsigned __int8 *)(a1 + 100);
  v8 = ipa_fltrt_calc_extra_wrd_bytes(a1);
  if ( (int)v8 >= 14 )
  {
    if ( (unsigned int)__ratelimit(
                         &ipa_fltrt_generate_hw_rule_bdy_from_eq__rs,
                         "ipa_fltrt_generate_hw_rule_bdy_from_eq") )
    {
      printk(&unk_3C8B8C, "ipa_fltrt_generate_hw_rule_bdy_from_eq");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_5:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            ipc_logbuf_low,
            "ipahal %s:%d too much extra bytes\n",
            "ipa_fltrt_generate_hw_rule_bdy_from_eq",
            2682);
          return 0xFFFFFFFFLL;
        }
        return 0xFFFFFFFFLL;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_5;
    }
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipahal %s:%d too much extra bytes\n", "ipa_fltrt_generate_hw_rule_bdy_from_eq", 2682);
    goto LABEL_5;
  }
  if ( (int)v8 < 9 )
  {
    v13 = &(*a2)[8 * ((int)v8 > 0)];
    if ( (int)v8 <= 0 )
      v12 = nullptr;
    else
      v12 = *a2;
    if ( !*(_BYTE *)(a1 + 2) )
      goto LABEL_21;
  }
  else
  {
    v12 = *a2;
    v13 = *a2 + 16;
    if ( !*(_BYTE *)(a1 + 2) )
      goto LABEL_21;
  }
  if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
  {
    __break(0x5512u);
    return ipa_fltrt_calc_extra_wrd_bytes(v8);
  }
  v14 = &ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx];
  if ( *((unsigned __int8 *)v14 + 144) == 255 )
  {
    if ( *((unsigned __int8 *)v14 + 128) == 255 )
    {
      printk(&unk_3FA214, "ipa_fltrt_generate_hw_rule_bdy_from_eq");
      if ( ipa3_get_ipc_logbuf() )
      {
        v87 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v87,
          "ipahal %s:%d no support for pure_ack and tos eqs\n",
          "ipa_fltrt_generate_hw_rule_bdy_from_eq",
          2710);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v88 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v88,
          "ipahal %s:%d no support for pure_ack and tos eqs\n",
          "ipa_fltrt_generate_hw_rule_bdy_from_eq",
          2710);
        return 0xFFFFFFFFLL;
      }
      return 0xFFFFFFFFLL;
    }
    v15 = *(_BYTE *)(a1 + 3);
  }
  else
  {
    v15 = 0;
  }
  v12 = ipa_write_8(v15, v12);
LABEL_21:
  if ( *(_BYTE *)(a1 + 4) )
    v12 = ipa_write_8(*(_BYTE *)(a1 + 5), v12);
  if ( *(_BYTE *)(a1 + 48) )
    v12 = ipa_write_8(*(_BYTE *)(a1 + 49), v12);
  if ( v6 )
  {
    v12 = ipa_write_8(*(_BYTE *)(a1 + 101), v12);
    v16 = ipa_write_8(*(_BYTE *)(a1 + 102), v13);
    v17 = ipa_write_8(*(_BYTE *)(a1 + 103), v16);
    v18 = ipa_write_8(*(_BYTE *)(a1 + 104), v17);
    v19 = ipa_write_8(*(_BYTE *)(a1 + 105), v18);
    v20 = ipa_write_8(*(_BYTE *)(a1 + 106), v19);
    v21 = ipa_write_8(*(_BYTE *)(a1 + 107), v20);
    v22 = ipa_write_8(*(_BYTE *)(a1 + 108), v21);
    v23 = ipa_write_8(*(_BYTE *)(a1 + 109), v22);
    v24 = ipa_write_8(*(_BYTE *)(a1 + 118), v23);
    v25 = ipa_write_8(*(_BYTE *)(a1 + 119), v24);
    v26 = ipa_write_8(*(_BYTE *)(a1 + 120), v25);
    v27 = ipa_write_8(*(_BYTE *)(a1 + 121), v26);
    v28 = ipa_write_8(*(_BYTE *)(a1 + 122), v27);
    v29 = ipa_write_8(*(_BYTE *)(a1 + 123), v28);
    v30 = ipa_write_8(*(_BYTE *)(a1 + 124), v29);
    v31 = ipa_write_8(*(_BYTE *)(a1 + 125), v30);
    v32 = ipa_write_8(*(_BYTE *)(a1 + 110), v31);
    v33 = ipa_write_8(*(_BYTE *)(a1 + 111), v32);
    v34 = ipa_write_8(*(_BYTE *)(a1 + 112), v33);
    v35 = ipa_write_8(*(_BYTE *)(a1 + 113), v34);
    v36 = ipa_write_8(*(_BYTE *)(a1 + 114), v35);
    v37 = ipa_write_8(*(_BYTE *)(a1 + 115), v36);
    v38 = ipa_write_8(*(_BYTE *)(a1 + 116), v37);
    v39 = ipa_write_8(*(_BYTE *)(a1 + 117), v38);
    v40 = ipa_write_8(*(_BYTE *)(a1 + 126), v39);
    v41 = ipa_write_8(*(_BYTE *)(a1 + 127), v40);
    v42 = ipa_write_8(*(_BYTE *)(a1 + 128), v41);
    v43 = ipa_write_8(*(_BYTE *)(a1 + 129), v42);
    v44 = ipa_write_8(*(_BYTE *)(a1 + 130), v43);
    v45 = ipa_write_8(*(_BYTE *)(a1 + 131), v44);
    v46 = ipa_write_8(*(_BYTE *)(a1 + 132), v45);
    v13 = ipa_write_8(*(_BYTE *)(a1 + 133), v46);
    if ( v6 != 1 )
    {
      v12 = ipa_write_8(*(_BYTE *)(a1 + 134), v12);
      v47 = ipa_write_8(*(_BYTE *)(a1 + 135), v13);
      v48 = ipa_write_8(*(_BYTE *)(a1 + 136), v47);
      v49 = ipa_write_8(*(_BYTE *)(a1 + 137), v48);
      v50 = ipa_write_8(*(_BYTE *)(a1 + 138), v49);
      v51 = ipa_write_8(*(_BYTE *)(a1 + 139), v50);
      v52 = ipa_write_8(*(_BYTE *)(a1 + 140), v51);
      v53 = ipa_write_8(*(_BYTE *)(a1 + 141), v52);
      v54 = ipa_write_8(*(_BYTE *)(a1 + 142), v53);
      v55 = ipa_write_8(*(_BYTE *)(a1 + 151), v54);
      v56 = ipa_write_8(*(_BYTE *)(a1 + 152), v55);
      v57 = ipa_write_8(*(_BYTE *)(a1 + 153), v56);
      v58 = ipa_write_8(*(_BYTE *)(a1 + 154), v57);
      v59 = ipa_write_8(*(_BYTE *)(a1 + 155), v58);
      v60 = ipa_write_8(*(_BYTE *)(a1 + 156), v59);
      v61 = ipa_write_8(*(_BYTE *)(a1 + 157), v60);
      v62 = ipa_write_8(*(_BYTE *)(a1 + 158), v61);
      v63 = ipa_write_8(*(_BYTE *)(a1 + 143), v62);
      v64 = ipa_write_8(*(_BYTE *)(a1 + 144), v63);
      v65 = ipa_write_8(*(_BYTE *)(a1 + 145), v64);
      v66 = ipa_write_8(*(_BYTE *)(a1 + 146), v65);
      v67 = ipa_write_8(*(_BYTE *)(a1 + 147), v66);
      v68 = ipa_write_8(*(_BYTE *)(a1 + 148), v67);
      v69 = ipa_write_8(*(_BYTE *)(a1 + 149), v68);
      v70 = ipa_write_8(*(_BYTE *)(a1 + 150), v69);
      v71 = ipa_write_8(*(_BYTE *)(a1 + 159), v70);
      v72 = ipa_write_8(*(_BYTE *)(a1 + 160), v71);
      v73 = ipa_write_8(*(_BYTE *)(a1 + 161), v72);
      v74 = ipa_write_8(*(_BYTE *)(a1 + 162), v73);
      v75 = ipa_write_8(*(_BYTE *)(a1 + 163), v74);
      v76 = ipa_write_8(*(_BYTE *)(a1 + 164), v75);
      v77 = ipa_write_8(*(_BYTE *)(a1 + 165), v76);
      v13 = ipa_write_8(*(_BYTE *)(a1 + 166), v77);
    }
  }
  if ( v2 )
  {
    v12 = ipa_write_8(*(_BYTE *)(a1 + 24), v12);
    v78 = ipa_write_32(*(_DWORD *)(a1 + 28), v13);
    v13 = (char *)ipa_write_32(*(_DWORD *)(a1 + 32), v78);
    if ( v2 != 1 )
    {
      v12 = ipa_write_8(*(_BYTE *)(a1 + 36), v12);
      v79 = ipa_write_32(*(_DWORD *)(a1 + 40), v13);
      v13 = (char *)ipa_write_32(*(_DWORD *)(a1 + 44), v79);
    }
  }
  if ( v5 )
  {
    v12 = ipa_write_8(*(_BYTE *)(a1 + 76), v12);
    v80 = ipa_write_32(*(_DWORD *)(a1 + 80), v13);
    v13 = (char *)ipa_write_32(*(_DWORD *)(a1 + 84), v80);
    if ( v5 != 1 )
    {
      v12 = ipa_write_8(*(_BYTE *)(a1 + 88), v12);
      v81 = ipa_write_32(*(_DWORD *)(a1 + 92), v13);
      v13 = (char *)ipa_write_32(*(_DWORD *)(a1 + 96), v81);
    }
  }
  if ( *(_BYTE *)(a1 + 167) )
  {
    v82 = ipa_write_32(*(_DWORD *)(a1 + 172), v13);
    v13 = (char *)ipa_write_32(*(_DWORD *)(a1 + 176), v82);
  }
  if ( v3 )
  {
    v12 = ipa_write_8(*(_BYTE *)(a1 + 8), v12);
    v83 = ipa_write_16(*(_WORD *)(a1 + 12), v13);
    v13 = (char *)ipa_write_16(*(_WORD *)(a1 + 10), v83);
    if ( v3 != 1 )
    {
      v12 = ipa_write_8(*(_BYTE *)(a1 + 14), v12);
      v84 = ipa_write_16(*(_WORD *)(a1 + 18), v13);
      v13 = (char *)ipa_write_16(*(_WORD *)(a1 + 16), v84);
    }
  }
  if ( *(_BYTE *)(a1 + 62) )
  {
    v12 = ipa_write_8(*(_BYTE *)(a1 + 64), v12);
    v13 = (char *)ipa_write_32(*(_DWORD *)(a1 + 68), v13);
  }
  if ( *(_BYTE *)(a1 + 56) )
  {
    v12 = ipa_write_8(*(_BYTE *)(a1 + 58), v12);
    v85 = ipa_write_16(*(_WORD *)(a1 + 60), v13);
    v13 = (char *)ipa_write_16(0, v85);
  }
  if ( *(_BYTE *)(a1 + 50) )
    v13 = (char *)ipa_write_32(*(_DWORD *)(a1 + 52) & 0xFFFFF, v13);
  if ( v12 )
    ipa_pad_to_64(v12);
  v86 = ipa_pad_to_64(v13);
  *a2 = v86;
  return 0;
}
