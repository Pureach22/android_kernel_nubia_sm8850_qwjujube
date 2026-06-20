__int64 __fastcall cam_vfe_bus_ver3_init(__int64 a1, char *a2, __int64 a3, char *a4, _QWORD *a5)
{
  _DWORD *v9; // x19
  __int64 v10; // x25
  _BYTE *v11; // x26
  __int64 v12; // x0
  __int64 result; // x0
  _QWORD *v14; // x28
  __int64 v15; // x0
  __int64 v16; // x22
  __int64 v17; // x27
  int v18; // w8
  __int64 v19; // x9
  char v20; // w9
  char v21; // w8
  int v22; // w8
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  unsigned int v28; // w0
  unsigned int v29; // w24
  _QWORD *v30; // x0
  _DWORD *v31; // x28
  char *v32; // x8
  int v33; // w8
  void *v34; // x19
  __int64 v35; // x0
  char *v36; // x8
  int v37; // w8
  unsigned int v38; // w19
  unsigned int v39; // w0
  __int64 v40; // x19
  __int64 v41; // x8
  __int64 v42; // x19
  __int64 v43; // x22
  bool v44; // cc
  __int64 v45; // x8
  _QWORD *v46; // x0
  __int64 v47; // x9
  __int64 v48; // x10
  _DWORD *v49; // x13
  _QWORD *v50; // x8
  __int64 v51; // x11
  __int64 v52; // x0
  _QWORD *v53; // x1
  _QWORD *v54; // x11
  _QWORD *v55; // x19
  _DWORD *v56; // x27
  unsigned __int64 StatusReg; // x19
  __int64 v58; // x22
  _QWORD *v59; // x0
  _QWORD *v60; // x0
  _QWORD *v61; // [xsp+20h] [xbp-10h]
  _QWORD *v62; // [xsp+28h] [xbp-8h]

  v9 = &unk_393000;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v55 = a5;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_ver3_init",
      5719,
      "Enter");
    a5 = v55;
    v9 = &unk_393000;
    if ( a1 )
      goto LABEL_4;
LABEL_74:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_init",
      5724,
      "Inval_prms soc_info:%pK hw_intf:%pK hw_info%pK",
      (const void *)a1,
      a2,
      (const void *)a3);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_init",
      5725,
      "controller: %pK",
      a4);
    return 4294967274LL;
  }
  if ( !a1 )
    goto LABEL_74;
LABEL_4:
  if ( !a2 || !a3 || !a4 )
    goto LABEL_74;
  v10 = *(_QWORD *)(a1 + 3296);
  if ( v10 )
  {
    v11 = &unk_2FD000;
    v62 = a5;
    if ( mem_trace_en == 1 )
      v12 = cam_mem_trace_alloc(128, 0xCC0u, 0, "cam_vfe_bus_ver3_init", 0x1669u);
    else
      v12 = _kvmalloc_node_noprof(128, 0, 3520, 0xFFFFFFFFLL);
    v14 = (_QWORD *)v12;
    if ( v12 )
    {
      while ( 1 )
      {
        if ( v11[2904] == 1 )
          v15 = cam_mem_trace_alloc(34992, 0xCC0u, 0, "cam_vfe_bus_ver3_init", 0x1671u);
        else
          v15 = _kvmalloc_node_noprof(34992, 0, 3520, 0xFFFFFFFFLL);
        v16 = v15;
        if ( !v15 )
        {
          v29 = -12;
          if ( (debug_mdl & 8) != 0 && !v9[919] )
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_bus_ver3_init",
              5747,
              "Failed to alloc for vfe_bus_priv");
          goto LABEL_90;
        }
        *v14 = v15;
        v17 = v15 + 0x8000;
        *(_DWORD *)(v15 + 34728) = *(_DWORD *)(a3 + 496);
        *(_DWORD *)(v15 + 34732) = *(_DWORD *)(a3 + 8184);
        *(_DWORD *)(v15 + 34736) = *(_DWORD *)(a3 + 8736);
        *(_DWORD *)(v15 + 34740) = *(_DWORD *)(a3 + 8876);
        v18 = *(_DWORD *)(a3 + 8884);
        *(_QWORD *)(v15 + 34616) = 0;
        *(_DWORD *)(v15 + 34968) = v18;
        *(_DWORD *)(v15 + 8) = *(_DWORD *)(a1 + 20);
        v19 = *(_DWORD *)(a1 + 480) ? *(_QWORD *)(a1 + 288) : 0LL;
        *(_QWORD *)(v15 + 16) = v19;
        *(_QWORD *)(v15 + 24) = a2;
        *(_QWORD *)(v15 + 40) = a4;
        *(_QWORD *)(v15 + 80) = a3;
        *(_BYTE *)(v15 + 34666) = 0;
        *(_BYTE *)(v15 + 34665) = *(_BYTE *)(v10 + 24);
        *(_BYTE *)(v15 + 34667) = *(_BYTE *)(a3 + 8880);
        *(_BYTE *)(v15 + 34673) = *(_BYTE *)(a3 + 8881);
        v20 = *(_BYTE *)(a3 + 8904);
        *(_BYTE *)(v15 + 34669) = 0;
        *(_BYTE *)(v15 + 34668) = v20;
        *(_DWORD *)(v15 + 34628) = *(_DWORD *)(a3 + 8888);
        v21 = *(_BYTE *)(a3 + 8892);
        *(_WORD *)(v15 + 34670) = 0;
        *(_BYTE *)(v15 + 34664) = v21;
        *(_DWORD *)(v15 + 34716) = *(_DWORD *)(a3 + 8896);
        *(_DWORD *)(v15 + 34720) = *(_DWORD *)(a3 + 8900);
        v22 = *(_DWORD *)(a3 + 8200);
        *(_QWORD *)(v15 + 34976) = a3 + 8208;
        *(_QWORD *)(v15 + 72) = a1;
        *(_DWORD *)(v15 + 34972) = v22;
        v23 = *(_QWORD *)(a3 + 8936);
        *(_QWORD *)(v15 + 34984) = a3;
        *(_QWORD *)v15 = v23;
        if ( v11[2904] == 1 )
        {
          v24 = cam_mem_trace_alloc(6688, 0xCC0u, 0, "cam_vfe_bus_ver3_init", 0x16A0u);
          *(_QWORD *)(v16 + 34760) = v24;
          if ( !v24 )
            goto LABEL_82;
        }
        else
        {
          v25 = _kvmalloc_node_noprof(6688, 0, 3520, 0xFFFFFFFFLL);
          *(_QWORD *)(v16 + 34760) = v25;
          if ( !v25 )
          {
LABEL_82:
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_bus_ver3_init",
              5796,
              "VFE:%u Failed to alloc for bus out res",
              *(_DWORD *)(v16 + 8));
            v29 = -12;
            goto LABEL_87;
          }
        }
        *(_QWORD *)(v16 + 34768) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34776) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34784) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34792) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34800) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34808) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34816) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34824) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34832) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34840) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34848) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34856) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34864) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34872) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34880) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34888) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34896) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34904) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34912) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34920) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34928) = 0x2C0000002CLL;
        *(_QWORD *)(v16 + 34936) = 0x2C0000002CLL;
        if ( (v11[2904] & 1) != 0 )
        {
          v26 = cam_mem_trace_alloc(152LL * *(unsigned int *)(v16 + 34736), 0xCC0u, 0, "cam_vfe_bus_ver3_init", 0x16ADu);
          *(_QWORD *)(v16 + 34752) = v26;
          if ( !v26 )
            goto LABEL_83;
        }
        else
        {
          v27 = _kvmalloc_node_noprof(152LL * *(unsigned int *)(v16 + 34736), 0, 3520, 0xFFFFFFFFLL);
          *(_QWORD *)(v16 + 34752) = v27;
          if ( !v27 )
          {
LABEL_83:
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_bus_ver3_init",
              5809,
              "VFE:%u Failed to alloc for bus comp groups",
              *(_DWORD *)(v16 + 8));
            v29 = -12;
            goto LABEL_84;
          }
        }
        *(_DWORD *)(v16 + 34712) = 0;
        *(_QWORD *)(v16 + 34696) = 0;
        *(_QWORD *)(v16 + 34704) = 0;
        *(_QWORD *)(v16 + 34688) = 0;
        _mutex_init(v16 + 34568, "&bus_priv->common_data.bus_mutex", &cam_vfe_bus_ver3_init___key);
        v28 = cam_irq_controller_init(
                "vfe_bus",
                *(_QWORD *)(v16 + 16) + *(_QWORD *)v16,
                (unsigned int *)(a3 + 128),
                (__int64 *)(v16 + 32));
        if ( v28 )
        {
          v29 = v28;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_bus_ver3_init",
            5827,
            "VFE:%u Init bus_irq_controller failed",
            *(_DWORD *)(v16 + 8));
          goto LABEL_30;
        }
        if ( !*(_DWORD *)(v16 + 34736) )
          break;
        v61 = v14;
        a4 = nullptr;
        a2 = (_BYTE *)&unk_70;
        v31 = (_DWORD *)(a3 + 8808);
        _ReadStatusReg(SP_EL0);
        while ( 1 )
        {
          v33 = (unsigned __int8)v11[2904];
          v34 = *(void **)(v16 + 34752);
          v11 = *(_BYTE **)(a1 + 3296);
          if ( v33 == 1 )
            v35 = cam_mem_trace_alloc(64, 0xCC0u, 0, "cam_vfe_bus_ver3_init_comp_grp", 0x798u);
          else
            v35 = _kvmalloc_node_noprof(64, 0, 3520, 0xFFFFFFFFLL);
          v10 = v35;
          if ( !v35 )
          {
            v29 = -12;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_bus_ver3_init",
              5837,
              "VFE:%u init comp_grp:%d failed rc:%d",
              *(_DWORD *)(v16 + 8),
              (_DWORD)a4,
              -12);
            v14 = v61;
            v11 = &unk_2FD000;
            goto LABEL_55;
          }
          v36 = &a2[(_QWORD)v34];
          *((_QWORD *)v36 - 11) = v35;
          *((_DWORD *)v36 - 26) = 1;
          *(_DWORD *)v35 = (_DWORD)a4;
          *(_QWORD *)(v35 + 8) = v16;
          *(_DWORD *)(v35 + 40) = 2;
          if ( a2 == byte_A88 )
            break;
          *(_DWORD *)(v35 + 24) = *(v31 - 17);
          *(_DWORD *)(v35 + 28) = *v31;
          if ( (unsigned __int64)a4 >= 2 )
          {
            *(_DWORD *)(v35 + 60) = 0;
          }
          else
          {
            if ( (cam_get_ddr_type() & 0xFFFFFFFE) == 8 )
              v37 = *((_DWORD *)v11 + 5);
            else
              v37 = *((_DWORD *)v11 + 4);
            *(_DWORD *)(v10 + 60) = v37;
          }
          v32 = &a2[(_QWORD)v34];
          *(_QWORD *)v32 = cam_vfe_bus_ver3_handle_comp_done_top_half;
          ++a4;
          a2 += 152;
          ++v31;
          v11 = &unk_2FD000;
          *((_QWORD *)v32 - 12) = *(_QWORD *)(v16 + 24);
          if ( (unsigned __int64)a4 >= *(unsigned int *)(v16 + 34736) )
          {
            v14 = v61;
            v38 = (_DWORD)a4 - 1;
            goto LABEL_50;
          }
        }
        __break(0x5512u);
        v56 = v34;
        StatusReg = _ReadStatusReg(SP_EL0);
        v58 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &cam_vfe_bus_ver3_init__alloc_tag;
        v14 = (_QWORD *)_kvmalloc_node_noprof(128, 0, 3520, 0xFFFFFFFFLL);
        *(_QWORD *)(StatusReg + 80) = v58;
        v9 = v56;
        if ( !v14 )
          goto LABEL_76;
      }
      v38 = -1;
LABEL_50:
      v39 = ((__int64 (__fastcall *)(__int64, __int64))cam_vfe_bus_ver3_init_vfe_out_resource)(v16, a3);
      if ( v39 )
      {
        v29 = v39;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_ver3_init",
          5845,
          "VFE:%u Failed to update outport info",
          *(_DWORD *)(v16 + 8));
        if ( (v38 & 0x80000000) == 0 )
        {
          v40 = 152LL * v38;
          do
          {
            ((void (__fastcall *)(__int64))cam_vfe_bus_ver3_deinit_vfe_out_resource)(*(_QWORD *)(v16 + 34760) + v40);
            v40 -= 152;
          }
          while ( v40 != -152 );
        }
        LODWORD(a4) = *(_DWORD *)(v16 + 34736);
LABEL_55:
        v41 = (unsigned int)((_DWORD)a4 - 1);
        if ( (int)a4 - 1 >= 0 )
        {
          v42 = 152LL * (unsigned int)v41;
          v43 = v41 + 1;
          do
          {
            v45 = *(_QWORD *)(v17 + 1984) + v42;
            v46 = *(_QWORD **)(v45 + 24);
            *(_DWORD *)(v45 + 8) = 0;
            *(_QWORD *)(v45 + 16) = 0;
            *(_QWORD *)(v45 + 24) = 0;
            *(_QWORD *)(v45 + 88) = 0;
            *(_QWORD *)(v45 + 96) = 0;
            *(_QWORD *)(v45 + 112) = 0;
            *(_QWORD *)(v45 + 120) = 0;
            if ( v46 )
            {
              if ( v11[2904] == 1 )
                cam_mem_trace_free(v46, 0);
              else
                kvfree(v46);
            }
            else
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                8,
                1,
                "cam_vfe_bus_ver3_deinit_comp_grp",
                1996,
                "comp_grp_priv is NULL");
            }
            v44 = v43-- <= 1;
            v42 -= 152;
          }
          while ( !v44 );
        }
LABEL_30:
        v30 = *(_QWORD **)(v17 + 1984);
        if ( v11[2904] == 1 )
          cam_mem_trace_free(v30, 0);
        else
          kvfree(v30);
LABEL_84:
        v59 = *(_QWORD **)(v17 + 1992);
        if ( v11[2904] == 1 )
          cam_mem_trace_free(v59, 0);
        else
          kvfree(v59);
LABEL_87:
        v60 = (_QWORD *)*v14;
        if ( v11[2904] == 1 )
          cam_mem_trace_free(v60, 0);
        else
          kvfree(v60);
LABEL_90:
        if ( v11[2904] == 1 )
          cam_mem_trace_free(v14, 0);
        else
          kvfree(v14);
        return v29;
      }
      v47 = v16 + 34544;
      *(_DWORD *)(v16 + 34560) = 0;
      v48 = 0;
      *(_QWORD *)(v16 + 34544) = v16 + 34544;
      v49 = &unk_393000;
      *(_QWORD *)(v16 + 34552) = v16 + 34544;
      v50 = v62;
      do
      {
        v51 = v16 + v48;
        v52 = v51 + 1776;
        *(_QWORD *)(v51 + 1776) = v51 + 1776;
        *(_QWORD *)(v51 + 1784) = v51 + 1776;
        v53 = *(_QWORD **)(v16 + 34552);
        if ( (_QWORD *)(v16 + v48 + 1776) == v53 || *v53 != v47 )
        {
          _list_add_valid_or_report(v52);
          v50 = v54;
        }
        else
        {
          *(_QWORD *)(v16 + 34552) = v52;
          *(_QWORD *)(v51 + 1776) = v47;
          *(_QWORD *)(v51 + 1784) = v53;
          *v53 = v52;
        }
        v48 += 128;
      }
      while ( v48 != 0x8000 );
      v14[14] = 0;
      v14[15] = 0;
      result = 0;
      v14[5] = &cam_vfe_bus_ver3_acquire_vfe_out;
      v14[6] = &cam_vfe_bus_ver3_release_vfe_out;
      v14[7] = cam_vfe_bus_ver3_start_hw;
      v14[8] = cam_vfe_bus_ver3_stop_hw;
      v14[2] = cam_vfe_bus_ver3_init_hw;
      v14[3] = cam_vfe_bus_ver3_deinit_hw;
      v14[11] = _cam_vfe_bus_ver3_process_cmd;
      *v50 = v14;
      if ( (debug_mdl & 8) != 0 && !v49[919] )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_ver3_init",
          5869,
          "Exit, VFE:%u",
          *(_DWORD *)(v16 + 8));
        return 0;
      }
    }
    else
    {
LABEL_76:
      result = 4294967284LL;
      if ( (debug_mdl & 8) != 0 && !v9[919] )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_ver3_init",
          5739,
          "Failed to alloc for vfe_bus");
        return 4294967284LL;
      }
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_init",
      5732,
      "Invalid soc_private");
    return 4294967277LL;
  }
  return result;
}
