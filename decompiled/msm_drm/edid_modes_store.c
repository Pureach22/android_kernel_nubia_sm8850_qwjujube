__int64 __fastcall edid_modes_store(int a1, int a2, char *s, __int64 a4)
{
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v7; // x0
  int v8; // w3
  int v9; // w4
  unsigned __int64 v10; // x24
  __int64 v11; // x8
  __int16 v12; // w9
  __int64 v13; // x11
  __int16 v14; // w25
  char v15; // w26
  const char *v16; // x21
  __int16 v17; // w28
  _QWORD *v18; // x22
  __int64 v19; // x27
  __int64 v20; // x0
  void *v21; // x0
  __int64 v22; // x19
  __int64 v23; // x0
  void *v24; // x0
  __int64 v25; // x1
  __int64 v26; // x20
  size_t v27; // x0
  size_t v28; // x2
  size_t v29; // x0
  size_t v30; // x8
  __int64 v31; // x0
  __int64 v32; // x2
  __int64 *v33; // x1
  __int64 v34; // x0
  __int16 v35; // [xsp+Ch] [xbp-24h]
  int v37; // [xsp+18h] [xbp-18h] BYREF
  int v38; // [xsp+1Ch] [xbp-14h] BYREF
  __int64 v39; // [xsp+20h] [xbp-10h] BYREF
  __int64 v40; // [xsp+28h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0;
  v38 = 0;
  v37 = 0;
  if ( !dp_debug_p )
  {
    result = -19;
    goto LABEL_3;
  }
  if ( sscanf(s, "%d %d %d %d", (char *)&v39 + 4, &v39, &v38, &v37) != 4 )
  {
    ipc_log_context = get_ipc_log_context();
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(ipc_log_context, "[i][%-4d]: clearing debug modes\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_226C95, *(unsigned int *)(StatusReg + 1800));
    else
      printk(&unk_226CC8, "edid_modes_store");
    *(_BYTE *)(*(_QWORD *)(dp_debug_p + 120) + 981LL) = 0;
  }
  v7 = get_ipc_log_context();
  v9 = v39;
  v8 = HIDWORD(v39);
  v10 = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    v7,
    "[d][%-4d]: hdisplay = %d, vdisplay = %d, vrefresh = %d, aspect_ratio = %d\n",
    *(_DWORD *)(v10 + 1800),
    v8,
    v9,
    v38,
    v37);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]: hdisplay = %d, vdisplay = %d, vrefresh = %d, aspect_ratio = %d\n",
      *(_DWORD *)(v10 + 1800),
      HIDWORD(v39),
      v39,
      v38,
      v37);
  v11 = dp_debug_p;
  *(_BYTE *)(*(_QWORD *)(dp_debug_p + 120) + 981LL) = 1;
  v12 = WORD2(v39);
  *(_DWORD *)(*(_QWORD *)(v11 + 120) + 984LL) = HIDWORD(v39);
  *(_DWORD *)(*(_QWORD *)(v11 + 120) + 988LL) = v39;
  *(_DWORD *)(*(_QWORD *)(v11 + 120) + 992LL) = v38;
  v13 = edid_ctl;
  *(_DWORD *)(*(_QWORD *)(v11 + 120) + 996LL) = v37;
  **(_WORD **)(v13 + 48) = v12;
  *(_WORD *)(*(_QWORD *)(edid_ctl + 48) + 2LL) = v39;
  v14 = v38;
  v15 = v37;
  *(_WORD *)(*(_QWORD *)(edid_ctl + 48) + 4LL) = v38;
  *(_BYTE *)(*(_QWORD *)(edid_ctl + 48) + 6LL) = v15;
  v16 = (const char *)edid_ctl;
  v17 = WORD2(v39);
  v19 = edid_ctl + 56;
  v18 = *(_QWORD **)(edid_ctl + 56);
  v35 = v39;
  while ( v18 != (_QWORD *)v19 )
  {
    if ( !strcmp((const char *)v18 - 40, v16) && !strcmp((const char *)v18 - 20, v16 + 20) )
    {
      *((_WORD *)v18 - 4) = v17;
      *((_WORD *)v18 - 2) = v14;
      *((_WORD *)v18 - 3) = v35;
      *((_BYTE *)v18 - 2) = v15;
      v20 = get_ipc_log_context();
      ipc_log_string(
        v20,
        "[i][%-4d]: %s %s %dx%d %d %d replaced\n",
        *(_DWORD *)(v10 + 1800),
        (const char *)v18 - 40,
        (const char *)v18 - 20,
        *((unsigned __int16 *)v18 - 4),
        *((unsigned __int16 *)v18 - 3),
        *((unsigned __int16 *)v18 - 2),
        *((unsigned __int8 *)v18 - 2));
      if ( (_drm_debug & 4) == 0 )
      {
        v21 = &unk_25686C;
LABEL_31:
        printk(v21, "store_user_edid_modes");
        goto LABEL_34;
      }
      v24 = &unk_27CCFE;
      v25 = *(unsigned int *)(v10 + 1800);
      goto LABEL_33;
    }
    v18 = (_QWORD *)*v18;
  }
  v22 = _kmalloc_cache_noprof(_drm_debug, 3520, 56);
  if ( !v22 )
  {
    v23 = get_ipc_log_context();
    ipc_log_string(v23, "[e][%-4d]kzalloc mode fail\n", *(_DWORD *)(v10 + 1800));
    printk(&unk_26F9EE, "store_user_edid_modes");
    goto LABEL_34;
  }
  v26 = edid_ctl;
  v27 = strnlen((const char *)edid_ctl, 0x14u);
  if ( v27 >= 0x15 )
  {
    _fortify_panic(2, 20, v27 + 1);
    goto LABEL_36;
  }
  v28 = v27 + 1;
  if ( v27 == 20 )
  {
LABEL_36:
    _fortify_panic(4, 20, v28);
    goto LABEL_37;
  }
  memcpy((void *)v22, (const void *)v26, v28);
  v29 = strnlen((const char *)(v26 + 20), 0xCu);
  v30 = v29;
  if ( v29 >= 0xD )
  {
LABEL_37:
    _fortify_panic(2, 12, v30 + 1);
    goto LABEL_38;
  }
  if ( v29 == 12 )
  {
LABEL_38:
    v31 = _fortify_panic(4, 12, v30 + 1);
    goto LABEL_39;
  }
  memcpy((void *)(v22 + 20), (const void *)(v26 + 20), v29 + 1);
  *(_WORD *)(v22 + 32) = v17;
  v31 = v22 + 40;
  *(_WORD *)(v22 + 36) = v14;
  v32 = v26 + 56;
  *(_WORD *)(v22 + 34) = v35;
  *(_BYTE *)(v22 + 38) = v15;
  v33 = *(__int64 **)(v26 + 64);
  if ( v22 + 40 != v26 + 56 && v33 != (__int64 *)v31 && *v33 == v32 )
  {
    *(_QWORD *)(v26 + 64) = v31;
    *(_QWORD *)(v22 + 40) = v32;
    *(_QWORD *)(v22 + 48) = v33;
    *v33 = v31;
    goto LABEL_29;
  }
LABEL_39:
  _list_add_valid_or_report(v31, v33);
LABEL_29:
  v34 = get_ipc_log_context();
  ipc_log_string(
    v34,
    "[i][%-4d]: %s %s %dx%d %d %d stored\n",
    *(_DWORD *)(v10 + 1800),
    (const char *)v22,
    (const char *)(v22 + 20),
    *(unsigned __int16 *)(v22 + 32),
    *(unsigned __int16 *)(v22 + 34),
    *(unsigned __int16 *)(v22 + 36),
    *(unsigned __int8 *)(v22 + 38));
  if ( (_drm_debug & 4) == 0 )
  {
    v21 = &unk_242469;
    goto LABEL_31;
  }
  v24 = &unk_242432;
  v25 = *(unsigned int *)(v10 + 1800);
LABEL_33:
  printk(v24, v25);
LABEL_34:
  result = a4;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
