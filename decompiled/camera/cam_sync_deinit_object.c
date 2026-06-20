__int64 __fastcall cam_sync_deinit_object(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  __int64 v8; // x19
  int v10; // w8
  int v11; // w10
  __int64 v12; // x9
  int v13; // w8
  int v14; // w10
  __int64 v15; // x9
  int v16; // w11
  __int64 v17; // x9
  int v18; // w8
  __int64 v20; // x10
  __int64 v21; // x8
  __int64 v22; // x21
  size_t v23; // x0
  int v24; // w9
  __int64 v25; // x21
  char v26; // w9
  _QWORD **v27; // x10
  _QWORD *v28; // x11
  _QWORD *v29; // x13
  _QWORD *v30; // x10
  _QWORD *v31; // x21
  _QWORD **v32; // x11
  _QWORD *v33; // x9
  int v34; // w8
  _QWORD *v35; // x8
  _QWORD *v36; // x1
  int v37; // w8
  _QWORD *v38; // x9
  _QWORD *v39; // x8
  _QWORD *v40; // x1
  _QWORD *i; // x26
  __int64 v42; // x8
  __int64 v43; // x27
  int v44; // w8
  _QWORD *v45; // x9
  __int64 v46; // x27
  _QWORD *v47; // t1
  __int64 v48; // x8
  _QWORD *v49; // x10
  _QWORD *v50; // x0
  _QWORD *v51; // x8
  __int64 v52; // x9
  __int64 v53; // x8
  _QWORD *v54; // x0
  _QWORD *j; // x26
  __int64 v56; // x8
  __int64 v57; // x27
  int v58; // w8
  _QWORD *v59; // x9
  __int64 v60; // x27
  _QWORD *v61; // t1
  __int64 v62; // x8
  _QWORD *v63; // x10
  _QWORD *v64; // x0
  _QWORD *v65; // x8
  __int64 v66; // x9
  __int64 v67; // x8
  _QWORD *v68; // x0
  __int64 v69; // x27
  _QWORD *v70; // x9
  _QWORD *v71; // x22
  _QWORD *v72; // x8
  _QWORD *v73; // x25
  _QWORD *v74; // x0
  _QWORD *v75; // x9
  _QWORD *v76; // x24
  _QWORD *v77; // x8
  _QWORD *v78; // x26
  _QWORD *v79; // x0
  unsigned __int64 v85; // x10
  _QWORD *v86; // [xsp+18h] [xbp-88h]
  __int64 v87; // [xsp+20h] [xbp-80h]
  __int64 v88; // [xsp+28h] [xbp-78h]
  __int64 v89; // [xsp+30h] [xbp-70h]
  _QWORD *v90; // [xsp+38h] [xbp-68h] BYREF
  _QWORD *v91; // [xsp+40h] [xbp-60h]
  _QWORD *v92; // [xsp+48h] [xbp-58h] BYREF
  _QWORD *v93; // [xsp+50h] [xbp-50h]
  __int64 v94; // [xsp+58h] [xbp-48h] BYREF
  int v95; // [xsp+60h] [xbp-40h]
  int v96; // [xsp+64h] [xbp-3Ch]
  __int64 v97; // [xsp+68h] [xbp-38h]
  __int64 v98; // [xsp+70h] [xbp-30h]
  __int64 v99; // [xsp+78h] [xbp-28h]
  __int64 v100; // [xsp+80h] [xbp-20h]
  __int64 v101; // [xsp+88h] [xbp-18h]
  __int64 v102; // [xsp+90h] [xbp-10h]
  __int64 v103; // [xsp+98h] [xbp-8h]

  result = 4294967274LL;
  v103 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 - 2048 >= 0xFFFFF801 )
  {
    v8 = a1 + 216LL * a2;
    v92 = nullptr;
    v93 = nullptr;
    v90 = nullptr;
    v91 = nullptr;
    if ( (debug_mdl & 0x80) != 0 && !debug_priority )
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        (unsigned __int8)debug_mdl & 0x80,
        4,
        "cam_sync_deinit_object",
        486,
        "row name:%s sync_id:%i [idx:%u] row_state:%u",
        (const char *)v8,
        *(_DWORD *)(v8 + 68),
        a2,
        *(_DWORD *)(v8 + 104));
    raw_spin_lock_bh(sync_dev + 4LL * a2 + 136);
    v10 = *(_DWORD *)(v8 + 104);
    if ( v10 == 1 )
    {
      if ( (debug_mdl & 0x80) != 0 && !debug_priority )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          (unsigned __int8)debug_mdl & 0x80,
          4,
          "cam_sync_deinit_object",
          501,
          "Destroying an active sync object name:%s id:%i",
          (const char *)v8,
          *(_DWORD *)(v8 + 68));
    }
    else if ( !v10 )
    {
      raw_spin_unlock_bh(sync_dev + 4LL * a2 + 136);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        128,
        1,
        "cam_sync_deinit_object",
        494,
        "Error: accessing an uninitialized sync obj: idx = %d name = %s",
        a2,
        (const char *)v8);
      result = 4294967274LL;
      goto LABEL_139;
    }
    if ( (cam_sync_monitor_mask & 2) != 0 )
    {
      cam_generic_fence_update_monitor_array(a2, sync_dev + 8328, *(_QWORD *)(sync_dev + 8672), 7);
      if ( (cam_sync_monitor_mask & 0x20000) != 0 )
      {
        v12 = *(_QWORD *)(sync_dev + 8672);
        if ( v12 )
        {
          if ( (cam_sync_monitor_mask & 2) != 0 )
          {
            v13 = *(_DWORD *)(v8 + 68);
            v14 = v13 - (v11 & 0xFFFFFF80);
            v15 = *(_QWORD *)(v12 + 8LL * (v13 / 128));
            if ( *(_DWORD *)(v15 + 1616LL * v14 + 140) )
            {
              v98 = 0;
              v99 = 0;
              v97 = 0;
              v16 = *(_DWORD *)(v8 + 64);
              v17 = v15 + 1616LL * v14;
              v94 = v8;
              v95 = v16;
              v96 = v13;
              v18 = *(_DWORD *)(v8 + 108);
              HIDWORD(v97) = *(_DWORD *)(v8 + 104);
              LODWORD(v98) = v18;
              _ZF = *(_BYTE *)(v17 + 168) == 0;
              v20 = 896;
              HIDWORD(v98) = *(_DWORD *)(v8 + 176);
              LODWORD(v99) = 1;
              if ( _ZF )
                v21 = 176;
              else
                v21 = 896;
              if ( !_ZF )
                v20 = 176;
              v100 = v17;
              v101 = v17 + v21;
              v102 = v17 + v20;
              cam_generic_fence_dump_monitor_array((__int64)&v94);
            }
          }
        }
      }
      v22 = *(_QWORD *)(sync_dev + 8672);
      if ( v22 )
      {
        v23 = strnlen((const char *)v8, 0x3Fu);
        if ( v23 >= 0x40 )
        {
          _fortify_panic(2, 64, v23 + 1);
          goto LABEL_30;
        }
        v25 = *(_QWORD *)(v22 + 8LL * (*(_DWORD *)(v8 + 68) / 128))
            + 1616LL * (int)(*(_DWORD *)(v8 + 68) - (v24 & 0xFFFFFF80));
        sized_strscpy(v25 + 8, v8);
        *(_DWORD *)(v25 + 136) = *(_DWORD *)(v8 + 64);
        *(_DWORD *)(v25 + 140) = *(_DWORD *)(v8 + 68);
        *(_DWORD *)(v25 + 152) = *(_DWORD *)(v8 + 104);
        *(_DWORD *)(v25 + 148) = *(_DWORD *)(v8 + 108);
        v26 = *(_BYTE *)(v25 + 168);
        *(_QWORD *)(v25 + 160) = *(_QWORD *)v25;
        *(_BYTE *)(v25 + 168) = v26 ^ 1;
      }
    }
    v27 = &v92;
    v29 = (_QWORD *)(v8 + 88);
    v28 = *(_QWORD **)(v8 + 88);
    *(_DWORD *)(v8 + 104) = 0;
    v92 = &v92;
    v93 = &v92;
    v90 = &v90;
    v91 = &v90;
    if ( v28 != (_QWORD *)(v8 + 88) )
    {
      do
      {
        v34 = *((_DWORD *)v28 - 2);
        v33 = v28;
        v28 = (_QWORD *)*v28;
        if ( v34 >= 1 )
        {
          v35 = (_QWORD *)v33[1];
          if ( (_QWORD *)*v35 == v33 && (_QWORD *)v28[1] == v33 )
          {
            v28[1] = v35;
            *v35 = v28;
          }
          else
          {
            _list_del_entry_valid_or_report(v33);
          }
          *v33 = v33;
          v33[1] = v33;
          v36 = v93;
          if ( v33 == v27 || v93 == v33 || (_QWORD **)*v93 != v27 )
          {
LABEL_30:
            _list_add_valid_or_report(v33);
          }
          else
          {
            v93 = v33;
            *v33 = v27;
            v33[1] = v36;
            *v36 = v33;
          }
        }
      }
      while ( v28 != v29 );
    }
    v31 = (_QWORD *)(v8 + 72);
    v30 = *(_QWORD **)(v8 + 72);
    if ( v30 != (_QWORD *)(v8 + 72) )
    {
      v32 = &v90;
      do
      {
        v37 = *((_DWORD *)v30 - 2);
        v38 = v30;
        v30 = (_QWORD *)*v30;
        if ( v37 >= 1 )
        {
          v39 = (_QWORD *)v38[1];
          if ( (_QWORD *)*v39 == v38 && (_QWORD *)v30[1] == v38 )
          {
            v30[1] = v39;
            *v39 = v30;
          }
          else
          {
            _list_del_entry_valid_or_report(v38);
          }
          *v38 = v38;
          v38[1] = v38;
          v40 = v91;
          if ( v38 == v32 || v91 == v38 || (_QWORD **)*v91 != v32 )
          {
            _list_add_valid_or_report(v38);
          }
          else
          {
            v91 = v38;
            *v38 = v32;
            v38[1] = v40;
            *v40 = v38;
          }
        }
      }
      while ( v30 != v31 );
    }
    v86 = v29;
    v87 = a3;
    v88 = a4;
    v89 = a2;
    raw_spin_unlock_bh(sync_dev + 4LL * a2 + 136);
    for ( i = v92; v92 != &v92; i = v92 )
    {
      v42 = *((int *)i - 2);
      if ( (unsigned int)v42 > 0x800 )
LABEL_140:
        __break(0x5512u);
      v43 = *(_QWORD *)(sync_dev + 128) + 216LL * (int)v42;
      raw_spin_lock_bh(sync_dev + 4 * v42 + 136);
      v44 = *(_DWORD *)(v43 + 104);
      if ( v44 == 1 )
      {
        if ( (debug_mdl & 0x80) != 0 && !debug_priority )
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            (unsigned __int8)debug_mdl & 0x80,
            4,
            "cam_sync_deinit_object",
            558,
            "Warning: destroying active child sync obj = %s[%d]",
            (const char *)v43,
            *((_DWORD *)i - 2));
      }
      else if ( !v44 )
      {
        goto LABEL_73;
      }
      v47 = *(_QWORD **)(v43 + 72);
      v46 = v43 + 72;
      v45 = v47;
      if ( v47 != (_QWORD *)v46 )
      {
        while ( 1 )
        {
          v48 = *v45;
          if ( *((_DWORD *)v45 - 2) == a2 )
            break;
          v45 = (_QWORD *)*v45;
          if ( v48 == v46 )
            goto LABEL_73;
        }
        v49 = (_QWORD *)v45[1];
        if ( (_QWORD *)*v49 == v45 && *(_QWORD **)(v48 + 8) == v45 )
        {
          *(_QWORD *)(v48 + 8) = v49;
          *v49 = v48;
        }
        else
        {
          _list_del_entry_valid_or_report(v45);
        }
        *v45 = v45;
        v50 = v45 - 1;
        v45[1] = v45;
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v50, 0);
        else
          kvfree(v50);
      }
LABEL_73:
      v51 = (_QWORD *)i[1];
      if ( (_QWORD *)*v51 == i && (v52 = *i, *(_QWORD **)(*i + 8LL) == i) )
      {
        *(_QWORD *)(v52 + 8) = v51;
        *v51 = v52;
      }
      else
      {
        _list_del_entry_valid_or_report(i);
      }
      *i = i;
      i[1] = i;
      v53 = *((unsigned int *)i - 2);
      if ( (unsigned int)v53 > 0x800 )
        goto LABEL_140;
      raw_spin_unlock_bh(sync_dev + 4 * v53 + 136);
      v54 = i - 1;
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v54, 0);
      else
        kvfree(v54);
    }
    for ( j = v90; v90 != &v90; j = v90 )
    {
      v56 = *((int *)j - 2);
      if ( (unsigned int)v56 > 0x800 )
        goto LABEL_140;
      v57 = *(_QWORD *)(sync_dev + 128) + 216LL * (int)v56;
      raw_spin_lock_bh(sync_dev + 4 * v56 + 136);
      v58 = *(_DWORD *)(v57 + 104);
      if ( v58 == 1 )
      {
        if ( (debug_mdl & 0x80) != 0 && !debug_priority )
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            (unsigned __int8)debug_mdl & 0x80,
            4,
            "cam_sync_deinit_object",
            588,
            "Warning: destroying active parent sync obj = %s[%d]",
            (const char *)v57,
            *((_DWORD *)j - 2));
      }
      else if ( !v58 )
      {
        goto LABEL_102;
      }
      v61 = *(_QWORD **)(v57 + 88);
      v60 = v57 + 88;
      v59 = v61;
      if ( v61 != (_QWORD *)v60 )
      {
        while ( 1 )
        {
          v62 = *v59;
          if ( *((_DWORD *)v59 - 2) == a2 )
            break;
          v59 = (_QWORD *)*v59;
          if ( v62 == v60 )
            goto LABEL_102;
        }
        v63 = (_QWORD *)v59[1];
        if ( (_QWORD *)*v63 == v59 && *(_QWORD **)(v62 + 8) == v59 )
        {
          *(_QWORD *)(v62 + 8) = v63;
          *v63 = v62;
        }
        else
        {
          _list_del_entry_valid_or_report(v59);
        }
        *v59 = v59;
        v64 = v59 - 1;
        v59[1] = v59;
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v64, 0);
        else
          kvfree(v64);
      }
LABEL_102:
      v65 = (_QWORD *)j[1];
      if ( (_QWORD *)*v65 == j && (v66 = *j, *(_QWORD **)(*j + 8LL) == j) )
      {
        *(_QWORD *)(v66 + 8) = v65;
        *v65 = v66;
      }
      else
      {
        _list_del_entry_valid_or_report(j);
      }
      *j = j;
      j[1] = j;
      v67 = *((unsigned int *)j - 2);
      if ( (unsigned int)v67 > 0x800 )
        goto LABEL_140;
      raw_spin_unlock_bh(sync_dev + 4 * v67 + 136);
      v68 = j - 1;
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v68, 0);
      else
        kvfree(v68);
    }
    v69 = v89;
    raw_spin_lock_bh(sync_dev + 4 * v89 + 136);
    v71 = (_QWORD *)(v8 + 160);
    v70 = *(_QWORD **)(v8 + 160);
    if ( v70 != (_QWORD *)(v8 + 160) )
    {
      do
      {
        v73 = (_QWORD *)*v70;
        v72 = (_QWORD *)v70[1];
        if ( (_QWORD *)*v72 == v70 && (_QWORD *)v73[1] == v70 )
        {
          v73[1] = v72;
          *v72 = v73;
        }
        else
        {
          _list_del_entry_valid_or_report(v70);
        }
        *v70 = v70;
        v74 = v70 - 2;
        v70[1] = v70;
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v74, 0);
        else
          kvfree(v74);
        v70 = v73;
      }
      while ( v73 != v71 );
    }
    v76 = (_QWORD *)(v8 + 144);
    v75 = *(_QWORD **)(v8 + 144);
    if ( v75 != (_QWORD *)(v8 + 144) )
    {
      do
      {
        v78 = (_QWORD *)*v75;
        v77 = (_QWORD *)v75[1];
        if ( (_QWORD *)*v77 == v75 && (_QWORD *)v78[1] == v75 )
        {
          v78[1] = v77;
          *v77 = v78;
        }
        else
        {
          _list_del_entry_valid_or_report(v75);
        }
        *v75 = v75;
        v79 = v75 - 8;
        v75[1] = v75;
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v79, 0);
        else
          kvfree(v79);
        v75 = v78;
      }
      while ( v78 != v76 );
    }
    if ( (*(_QWORD *)(v8 + 184) & 4) != 0 )
    {
      cam_dma_fence_get_put_ref(0, *(unsigned int *)(v8 + 196));
      if ( v87 )
      {
        if ( *(_DWORD *)(v8 + 192) == *(_DWORD *)(v87 + 4) )
        {
          *(_BYTE *)(v87 + 8) = *(_BYTE *)(v8 + 200);
          *(_DWORD *)v87 = *(_DWORD *)(v8 + 196);
        }
      }
    }
    if ( v88 && (*(_QWORD *)(v8 + 184) & 8) != 0 && *(_DWORD *)(v8 + 204) == *(_DWORD *)v88 )
    {
      *(_DWORD *)(v88 + 4) = *(_DWORD *)(v8 + 208);
      *(_BYTE *)(v88 + 8) = *(_BYTE *)(v8 + 212);
    }
    *(_QWORD *)(v8 + 56) = 0;
    *(_QWORD *)(v8 + 64) = 0;
    *(_QWORD *)(v8 + 104) = 0;
    *(_QWORD *)(v8 + 184) = 0;
    *(_QWORD *)(v8 + 192) = 0;
    *(_DWORD *)(v8 + 176) = 0;
    *(_QWORD *)v8 = 0;
    *(_QWORD *)(v8 + 8) = 0;
    *(_QWORD *)(v8 + 16) = 0;
    *(_QWORD *)(v8 + 24) = 0;
    *(_QWORD *)(v8 + 32) = 0;
    *(_QWORD *)(v8 + 40) = 0;
    *(_QWORD *)(v8 + 48) = 0;
    *v31 = 0;
    *(_QWORD *)(v8 + 80) = 0;
    *v86 = 0;
    v86[1] = 0;
    *v76 = 0;
    *(_QWORD *)(v8 + 152) = 0;
    *v71 = 0;
    *(_QWORD *)(v8 + 168) = 0;
    *(_DWORD *)(v8 + 200) = 0;
    *(_DWORD *)(v8 + 212) = 0;
    *(_QWORD *)(v8 + 204) = 0;
    complete_all(v8 + 112);
    _X9 = (unsigned __int64 *)(sync_dev + 8416 + 8LL * (a2 >> 6));
    __asm { PRFM            #0x11, [X9] }
    do
      v85 = __ldxr(_X9);
    while ( __stxr(v85 & ~(1LL << a2), _X9) );
    *(_QWORD *)(v8 + 144) = v8 + 144;
    *(_QWORD *)(v8 + 152) = v76;
    *(_QWORD *)(v8 + 72) = v8 + 72;
    *(_QWORD *)(v8 + 80) = v31;
    *(_QWORD *)(v8 + 88) = v8 + 88;
    *(_QWORD *)(v8 + 96) = v86;
    *(_QWORD *)(v8 + 160) = v8 + 160;
    *(_QWORD *)(v8 + 168) = v71;
    raw_spin_unlock_bh(sync_dev + 4 * v69 + 136);
    result = 0;
  }
LABEL_139:
  _ReadStatusReg(SP_EL0);
  return result;
}
