__int64 __fastcall coresight_cti_get_platform_data(__int64 a1)
{
  unsigned __int64 v2; // x0
  int v3; // w28
  _DWORD *v4; // x20
  __int64 v5; // x0
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x22
  __int64 next_child_node; // x0
  unsigned __int64 v10; // x21
  unsigned __int64 v11; // x0
  unsigned __int64 v12; // x0
  int v13; // w0
  int v14; // w21
  _QWORD *v15; // x0
  _QWORD *v16; // x22
  unsigned __int64 v17; // x0
  unsigned __int64 v18; // x0
  unsigned __int64 v19; // x21
  _QWORD *v20; // x0
  _QWORD *v21; // x22
  __int64 csdev_by_fwnode; // x0
  const char *v23; // x4
  const char **v24; // x8
  __int64 result; // x0
  __int64 v26; // x3
  int trig_group; // w0
  int u32_array; // w0
  int v29; // w25
  int v30; // w0
  int v31; // w8
  _QWORD *v32; // x0
  _QWORD *v33; // x27
  int v34; // w0
  __int64 v35; // x0
  __int64 v36; // x25
  int v37; // w0
  int v38; // w0
  const char *v39; // x8
  unsigned __int64 reference; // x0
  unsigned __int64 v41; // x26
  __int64 v42; // x0
  const char *v43; // x8
  const char **v44; // x8
  __int64 v45; // x8
  const char *v46; // x9
  void (__fastcall *v47)(_QWORD); // x8
  __int64 v48; // x25
  __int64 v49; // x8
  void (__fastcall *v50)(_QWORD); // x8
  __int64 v51; // x8
  void (__fastcall *v52)(_QWORD); // x8
  unsigned __int64 v59; // x9
  __int64 v60; // [xsp+18h] [xbp-78h]
  const char *v61; // [xsp+20h] [xbp-70h] BYREF
  __int64 v62; // [xsp+28h] [xbp-68h] BYREF
  __int64 v63; // [xsp+30h] [xbp-60h]
  __int64 v64; // [xsp+38h] [xbp-58h] BYREF
  __int64 v65; // [xsp+40h] [xbp-50h]
  __int64 v66; // [xsp+48h] [xbp-48h]
  __int64 v67; // [xsp+50h] [xbp-40h]
  __int64 v68; // [xsp+58h] [xbp-38h]
  __int64 v69; // [xsp+60h] [xbp-30h]
  __int64 v70; // [xsp+68h] [xbp-28h]
  __int64 v71; // [xsp+70h] [xbp-20h]
  __int64 v72; // [xsp+78h] [xbp-18h]
  __int64 v73; // [xsp+80h] [xbp-10h]
  __int64 v74; // [xsp+88h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = _dev_fwnode(a1);
  v3 = -2;
  if ( !v2 || v2 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_33;
  v4 = *(_DWORD **)(a1 + 152);
  v5 = devm_kmalloc(a1, 24, 3520);
  if ( !v5 )
    goto LABEL_32;
  v60 = v5;
  device_property_read_u32_array(a1, "arm,cti-ctm-id", v4 + 5, 1);
  v6 = _dev_fwnode(a1);
  if ( v6
    && v6 <= 0xFFFFFFFFFFFFF000LL
    && *(_UNKNOWN **)(v6 + 8) == &of_fwnode_ops
    && (unsigned int)of_device_is_compatible(v6 - 24, "arm,coresight-cti-v8-arch") )
  {
    v62 = 0;
    v63 = 0;
    v11 = _dev_fwnode(a1);
    if ( !v11 )
      goto LABEL_86;
    if ( v11 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_86;
    if ( *(_UNKNOWN **)(v11 + 8) != &of_fwnode_ops )
      goto LABEL_86;
    v12 = v11 - 24;
    if ( !v12 )
      goto LABEL_86;
    v72 = 0;
    v73 = 0;
    v70 = 0;
    v71 = 0;
    v68 = 0;
    v69 = 0;
    v66 = 0;
    v67 = 0;
    v64 = 0;
    v65 = 0;
    if ( (unsigned int)_of_parse_phandle_with_args(v12, "cpu", 0, 0, 0, &v64) || !v64 )
      goto LABEL_86;
    v13 = of_cpu_node_to_id();
    v14 = v13 < 0 ? -1 : v13;
    if ( v13 < 0 )
    {
LABEL_86:
      dev_warn(a1, "ARM v8 architectural CTI connection: missing cpu\n");
      v3 = -22;
      goto LABEL_33;
    }
    v4[10] = v14;
    v15 = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64))cti_allocate_trig_con)(a1, 2, 3);
    if ( v15 )
    {
      v16 = v15;
      *(_QWORD *)(*v15 + 8LL) |= 3uLL;
      *(_DWORD *)(*v15 + 24LL) = 9;
      *(_DWORD *)(*v15 + 28LL) = 8;
      *(_QWORD *)(v15[1] + 8LL) |= 7uLL;
      *(_DWORD *)(v15[1] + 24LL) = 5;
      *(_DWORD *)(v15[1] + 28LL) = 6;
      *(_DWORD *)(v15[1] + 32LL) = 7;
      scnprintf(&v62, 16, "cpu%d", v14);
      v3 = cti_add_connection_entry(a1, (__int64)v4, v16, 0, (__int64)&v62);
      if ( v3 )
        goto LABEL_33;
      v17 = _dev_fwnode(a1);
      v3 = -22;
      if ( !v17 || v17 > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_33;
      v18 = ((__int64 (*)(void))fwnode_find_reference)();
      if ( v18 > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_101;
      v19 = v18;
      v20 = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64))cti_allocate_trig_con)(a1, 4, 4);
      if ( !v20 )
      {
        v3 = -12;
LABEL_94:
        if ( v19 )
        {
          v51 = *(_QWORD *)(v19 + 8);
          if ( v51 )
          {
            v52 = *(void (__fastcall **)(_QWORD))(v51 + 8);
            if ( v52 )
            {
              if ( *((_DWORD *)v52 - 1) != -643302289 )
                __break(0x8228u);
              v52(v19);
            }
          }
        }
        if ( v3 )
          goto LABEL_33;
LABEL_101:
        _X8 = (unsigned __int64 *)(v4 + 28);
        __asm { PRFM            #0x11, [X8] }
        do
          v59 = __ldxr(_X8);
        while ( __stxr(v59 | 1, _X8) );
        if ( !v4[4] )
        {
LABEL_109:
          v3 = cti_add_default_connection(a1, (__int64)v4);
          result = v60;
          if ( v3 )
            goto LABEL_33;
          goto LABEL_34;
        }
LABEL_103:
        result = v60;
        goto LABEL_34;
      }
      v21 = v20;
      *(_QWORD *)(*v20 + 8LL) |= 0xF0uLL;
      *(_QWORD *)(v20[1] + 8LL) |= 0xF0uLL;
      *(_DWORD *)(*v20 + 24LL) = 10;
      *(_DWORD *)(v20[1] + 24LL) = 11;
      *(_DWORD *)(*v20 + 28LL) = 10;
      *(_DWORD *)(v20[1] + 28LL) = 11;
      *(_DWORD *)(*v20 + 32LL) = 10;
      *(_DWORD *)(v20[1] + 32LL) = 11;
      *(_DWORD *)(*v20 + 36LL) = 10;
      *(_DWORD *)(v20[1] + 36LL) = 11;
      csdev_by_fwnode = coresight_find_csdev_by_fwnode(v19);
      if ( csdev_by_fwnode )
      {
        v23 = *(const char **)(csdev_by_fwnode + 168);
        if ( v23 )
        {
LABEL_93:
          v3 = cti_add_connection_entry(a1, (__int64)v4, v21, csdev_by_fwnode, (__int64)v23);
          goto LABEL_94;
        }
        v24 = (const char **)(csdev_by_fwnode + 56);
      }
      else
      {
        if ( !v19 || *(_UNKNOWN **)(v19 + 8) != &of_fwnode_ops )
        {
          v23 = "unknown";
          goto LABEL_93;
        }
        if ( v19 == 24 )
        {
          v23 = "<no-node>";
          goto LABEL_93;
        }
        v24 = (const char **)(v19 - 8);
      }
      v23 = *v24;
      goto LABEL_93;
    }
LABEL_32:
    v3 = -12;
    goto LABEL_33;
  }
  v7 = _dev_fwnode(a1);
  v3 = -22;
  if ( !v7 )
    goto LABEL_33;
  v8 = v7;
  if ( v7 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_33;
  next_child_node = fwnode_get_next_child_node(v7, 0);
  if ( !next_child_node )
  {
LABEL_102:
    if ( !v4[4] )
      goto LABEL_109;
    goto LABEL_103;
  }
  v10 = next_child_node;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( v10 > 0xFFFFFFFFFFFFF000LL
      || *(_UNKNOWN **)(v10 + 8) != &of_fwnode_ops
      || (of_node_name_eq(v10 - 24, "trig-conns") & 1) == 0 )
    {
      goto LABEL_37;
    }
    v61 = "unknown";
    v62 = 0;
    v63 = 0;
    u32_array = fwnode_property_read_u32_array(v10, "arm,trig-in-sigs", 0, 0);
    v29 = u32_array & ~(u32_array >> 31);
    v30 = fwnode_property_read_u32_array(v10, "arm,trig-out-sigs", 0, 0);
    v31 = v4[17];
    v3 = -22;
    if ( v29 > v31 || (v30 & ~(v30 >> 31)) > v31 )
      goto LABEL_81;
    v32 = (_QWORD *)((__int64 (__fastcall *)(__int64, _QWORD))cti_allocate_trig_con)(a1, (unsigned int)v29);
    if ( !v32 )
    {
LABEL_79:
      v3 = -12;
      goto LABEL_81;
    }
    v33 = v32;
    trig_group = cti_plat_read_trig_group(*v32, v10, "arm,trig-in-sigs");
    if ( trig_group
      || (trig_group = cti_plat_read_trig_types(*v33, v10, "arm,trig-in-types")) != 0
      || (trig_group = cti_plat_read_trig_group(v33[1], v10, "arm,trig-out-sigs")) != 0
      || (trig_group = cti_plat_read_trig_types(v33[1], v10, "arm,trig-out-types")) != 0 )
    {
LABEL_80:
      v3 = trig_group;
      goto LABEL_81;
    }
    v34 = fwnode_property_read_u32_array(v10, "arm,trig-filters", 0, 0);
    if ( v34 >= 1 )
      break;
LABEL_53:
    fwnode_property_read_string(v10, "arm,trig-conn-name", &v61);
    if ( v10 != 24 && *(_UNKNOWN **)(v10 + 8) == &of_fwnode_ops )
    {
      v72 = 0;
      v73 = 0;
      v70 = 0;
      v71 = 0;
      v68 = 0;
      v69 = 0;
      v66 = 0;
      v67 = 0;
      v64 = 0;
      v65 = 0;
      if ( !(unsigned int)_of_parse_phandle_with_args(v10 - 24, "cpu", 0, 0, 0, &v64) )
      {
        if ( v64 )
        {
          v38 = of_cpu_node_to_id();
          if ( (v38 & 0x80000000) == 0 )
          {
            v4[10] = v38;
            scnprintf(&v62, 16, "cpu%d", v38);
            v26 = 0;
            v39 = (const char *)&v62;
LABEL_75:
            v61 = v39;
            goto LABEL_36;
          }
        }
      }
    }
    reference = fwnode_find_reference(v10, "arm,cs-dev-assoc", 0);
    if ( reference > 0xFFFFFFFFFFFFF000LL )
    {
      v26 = 0;
      goto LABEL_36;
    }
    v41 = reference;
    v42 = coresight_find_csdev_by_fwnode(reference);
    v26 = v42;
    if ( v42 )
    {
      v43 = *(const char **)(v42 + 168);
      if ( !v43 )
      {
        v44 = (const char **)(v42 + 56);
        goto LABEL_63;
      }
      goto LABEL_64;
    }
    if ( !v41 )
    {
      v26 = 0;
      v39 = "unknown";
      goto LABEL_75;
    }
    v45 = *(_QWORD *)(v41 + 8);
    v46 = "unknown";
    if ( (_UNKNOWN *)v45 == &of_fwnode_ops )
    {
      if ( v41 != 24 )
      {
        v44 = (const char **)(v41 - 8);
LABEL_63:
        v43 = *v44;
LABEL_64:
        v61 = v43;
        if ( !v41 )
          goto LABEL_36;
        v45 = *(_QWORD *)(v41 + 8);
        goto LABEL_69;
      }
      v46 = "<no-node>";
    }
    v61 = v46;
LABEL_69:
    if ( v45 )
    {
      v47 = *(void (__fastcall **)(_QWORD))(v45 + 8);
      if ( v47 )
      {
        v48 = v42;
        if ( *((_DWORD *)v47 - 1) != -643302289 )
          __break(0x8228u);
        v47(v41);
        v26 = v48;
      }
    }
LABEL_36:
    trig_group = cti_add_connection_entry(a1, (__int64)v4, v33, v26, (__int64)v61);
    if ( trig_group )
      goto LABEL_80;
LABEL_37:
    v10 = fwnode_get_next_child_node(v8, v10);
    if ( !v10 )
      goto LABEL_102;
  }
  if ( v34 > v4[17] )
  {
    v3 = -22;
    goto LABEL_81;
  }
  v35 = _kmalloc_cache_noprof(_kmalloc_noprof, 3520, 24);
  v36 = v35;
  if ( !v35 )
    goto LABEL_79;
  v37 = cti_plat_read_trig_group(v35, v10, "arm,trig-filters");
  if ( !v37 )
  {
    _bitmap_or(v4 + 28, v4 + 28, v36 + 8, (unsigned int)v4[17]);
    kfree(v36);
    goto LABEL_53;
  }
  v3 = v37;
  kfree(v36);
LABEL_81:
  v49 = *(_QWORD *)(v10 + 8);
  if ( v49 )
  {
    v50 = *(void (__fastcall **)(_QWORD))(v49 + 8);
    if ( v50 )
    {
      if ( *((_DWORD *)v50 - 1) != -643302289 )
        __break(0x8228u);
      v50(v10);
    }
  }
LABEL_33:
  result = v3;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
