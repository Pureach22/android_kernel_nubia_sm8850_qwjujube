__int64 __fastcall sde_vdc_parse_dt(__int64 a1, __int64 a2)
{
  int *v4; // x28
  unsigned int dt_entry; // w23
  char *v6; // x1
  unsigned int v7; // w0
  __int64 v8; // x24
  __int64 v9; // x22
  __int64 v10; // x25
  int *v11; // x20
  _DWORD *v12; // x23
  int v13; // w8
  int v14; // w9
  unsigned __int64 v15; // x27
  int v16; // w9
  int v17; // w10
  int v18; // w11
  unsigned __int64 v25; // x9
  unsigned __int64 StatusReg; // x20
  __int64 v27; // x22
  char *s1; // [xsp+10h] [xbp-50h] BYREF
  unsigned int v30; // [xsp+1Ch] [xbp-44h] BYREF
  _BYTE v31[8]; // [xsp+20h] [xbp-40h] BYREF
  _QWORD v32[7]; // [xsp+28h] [xbp-38h] BYREF

  v32[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v32, 0, 48);
  v30 = 0;
  memset(v31, 0, 7);
  s1 = nullptr;
  v4 = (int *)_kvmalloc_node_noprof(5376, 0, 3520, 0xFFFFFFFFLL);
  if ( v4 )
  {
    while ( 1 )
    {
      dt_entry = validate_dt_entry(a1, &vdc_prop, 7, v32, &v30);
      if ( dt_entry )
        break;
      v6 = off_AEC0;
      *(_DWORD *)(a2 + 11168) = v30;
      v7 = of_property_read_string(a1, v6, &s1);
      if ( v7 != -61 )
      {
        dt_entry = v7;
        if ( v7 != -22 && (v7 || strcmp(s1, "vdc_1_2")) )
        {
          printk(&unk_2390D4, "sde_vdc_parse_dt");
          break;
        }
      }
      dt_entry = read_dt_entry(a1, &vdc_prop, 7, v32, v31, v4);
      if ( dt_entry )
        break;
      if ( !v30 )
      {
        dt_entry = 0;
        break;
      }
      v8 = 0;
      v9 = 0;
      v10 = a2 + 11200;
      v11 = v4;
      _ReadStatusReg(SP_EL0);
      while ( v8 != 728 )
      {
        v12 = (_DWORD *)_kvmalloc_node_noprof(56, 0, 3520, 0xFFFFFFFFLL);
        if ( !v12 )
          goto LABEL_22;
        v13 = *v11;
        v14 = v4[192];
        a1 = a2 + v8;
        v15 = v9 + 1;
        *(_QWORD *)(a1 + 11224) = v12;
        *(_DWORD *)(a1 + 11192) = v9 + 1;
        *(_DWORD *)(a1 + 11196) = v13;
        *(_DWORD *)(a1 + 11200) = v14;
        snprintf((char *)(v10 + v8 - 24), 0x10u, "vdc_%u", v9);
        if ( (v31[1] & 1) == 0 )
          *(_DWORD *)(a1 + 11200) = 256;
        v16 = v4[768];
        v17 = v11[960];
        v18 = v4[1152];
        v12[5] = v11[576];
        v12[6] = v16;
        v12[12] = v17;
        v12[13] = v18;
        _X8 = (unsigned __int64 *)(v10 + v8 + 8);
        __asm { PRFM            #0x11, [X8] }
        do
          v25 = __ldxr(_X8);
        while ( __stxr(v25 | 1, _X8) );
        dt_entry = 0;
        v8 += 56;
        ++v11;
        ++v9;
        if ( v15 >= v30 )
          goto LABEL_23;
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v27 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &sde_vdc_parse_dt__alloc_tag;
      v4 = (int *)_kvmalloc_node_noprof(5376, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(StatusReg + 80) = v27;
      if ( !v4 )
        goto LABEL_22;
    }
  }
  else
  {
LABEL_22:
    dt_entry = -12;
  }
LABEL_23:
  kvfree(v4);
  _ReadStatusReg(SP_EL0);
  return dt_entry;
}
