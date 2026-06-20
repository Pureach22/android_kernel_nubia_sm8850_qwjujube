__int64 __fastcall _set_subcaches(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  char v5; // w9
  unsigned int v6; // w9
  unsigned __int64 v7; // x22
  __int64 v8; // x19
  unsigned int v9; // w20
  const char *v10; // x27
  _DWORD *v11; // x8
  char v12; // w10
  __int64 v13; // x20
  __int64 v14; // x8
  _DWORD *v15; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x21
  __int64 v18; // x22
  __int64 v19; // x2
  __int64 v20; // x3
  __int64 v21; // x8
  unsigned __int64 v22; // x9
  unsigned __int64 v23; // x8
  unsigned __int64 StatusReg; // [xsp+8h] [xbp-F8h]
  _QWORD v25[2]; // [xsp+10h] [xbp-F0h] BYREF
  __int64 v26; // [xsp+20h] [xbp-E0h] BYREF
  __int64 v27; // [xsp+28h] [xbp-D8h]
  __int64 v28; // [xsp+30h] [xbp-D0h]
  __int64 v29; // [xsp+38h] [xbp-C8h]
  __int64 v30; // [xsp+40h] [xbp-C0h]
  __int64 v31; // [xsp+48h] [xbp-B8h]
  __int64 v32; // [xsp+50h] [xbp-B0h]
  __int64 v33; // [xsp+58h] [xbp-A8h]
  __int64 v34; // [xsp+60h] [xbp-A0h]
  __int64 v35; // [xsp+68h] [xbp-98h]
  __int64 v36; // [xsp+70h] [xbp-90h]
  __int64 v37; // [xsp+78h] [xbp-88h]
  __int64 v38; // [xsp+80h] [xbp-80h]
  __int64 v39; // [xsp+88h] [xbp-78h]
  __int64 v40; // [xsp+90h] [xbp-70h]
  __int64 v41; // [xsp+98h] [xbp-68h]
  __int64 v42; // [xsp+A0h] [xbp-60h]
  __int64 v43; // [xsp+A8h] [xbp-58h]
  __int64 v44; // [xsp+B0h] [xbp-50h]
  __int64 v45; // [xsp+B8h] [xbp-48h]
  __int64 v46; // [xsp+C0h] [xbp-40h]
  __int64 v47; // [xsp+C8h] [xbp-38h]
  __int64 v48; // [xsp+D0h] [xbp-30h]
  __int64 v49; // [xsp+D8h] [xbp-28h]
  __int64 v50; // [xsp+E0h] [xbp-20h]
  __int64 v51; // [xsp+E8h] [xbp-18h]
  __int64 v52; // [xsp+F0h] [xbp-10h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(result + 2208);
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v5 = *(_BYTE *)(v4 + 193);
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v25[0] = 0;
  if ( (v5 & 1) != 0 || msm_cvp_syscache_disable == 1 )
  {
    if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
      result = printk(&unk_8A697, "core", a3, a4);
    goto LABEL_51;
  }
  v6 = *(_DWORD *)(v4 + 208);
  v50 = 0;
  v51 = 0;
  v7 = *(_QWORD *)(v4 + 200);
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  if ( v7 >= v7 + 24LL * v6 )
    goto LABEL_51;
  v8 = result;
  v9 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( *(_BYTE *)(v7 + 8) != 1 )
      goto LABEL_9;
    v10 = *(const char **)v7;
    result = strcmp("cvp", *(const char **)v7);
    if ( !(_DWORD)result )
      break;
    result = strcmp("cvpfw", v10);
    if ( !(_DWORD)result )
    {
      if ( ((8LL * v9) | 4uLL) > 0xD0 )
        goto LABEL_36;
      v11 = (_DWORD *)&v26 + 2 * v9 + 1;
      *v11 = 0;
      if ( v9 > 0x18 )
        goto LABEL_36;
      goto LABEL_21;
    }
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      result = printk(&unk_90023, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
LABEL_9:
    v7 += 24LL;
    if ( v7 >= *(_QWORD *)(*(_QWORD *)(v8 + 2208) + 200LL)
             + 24 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(v8 + 2208) + 208LL) )
    {
      if ( !v9 )
        goto LABEL_51;
      if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
        printk(&unk_962C0, "core", v9, a4);
      LODWORD(v26) = v9;
      v25[1] = &v26;
      LODWORD(v25[0]) = 1;
      v13 = _kmalloc_noprof((int)(8 * v9 + 20), 3520);
      v14 = *(_QWORD *)(v8 + 2416);
      if ( v14 )
        goto LABEL_29;
      goto LABEL_37;
    }
  }
  if ( ((8LL * v9) | 4uLL) <= 0xD0 )
  {
    v11 = (_DWORD *)&v26 + 2 * v9 + 1;
    *v11 = 1;
    if ( v9 <= 0x18 )
    {
LABEL_21:
      v12 = BYTE1(msm_cvp_debug);
      v11[1] = **(_DWORD **)(v7 + 16);
      if ( (v12 & 1) != 0 && !msm_cvp_debug_out )
        result = printk(&unk_8BB9F, "core", **(unsigned int **)(v7 + 16), *(_QWORD *)(*(_QWORD *)(v7 + 16) + 8LL));
      ++v9;
      goto LABEL_9;
    }
  }
LABEL_36:
  __break(1u);
  v17 = _ReadStatusReg(SP_EL0);
  v18 = *(_QWORD *)(v17 + 80);
  *(_QWORD *)(v17 + 80) = &_core_set_resource__alloc_tag;
  v13 = ((__int64 (*)(void))_kmalloc_noprof)();
  *(_QWORD *)(v17 + 80) = v18;
  v14 = *(_QWORD *)(v8 + 2416);
  if ( !v14 )
    goto LABEL_37;
LABEL_29:
  v15 = *(_DWORD **)(v14 + 24);
  if ( v15 )
  {
    if ( *(v15 - 1) != 292837972 )
      __break(0x8228u);
    if ( ((unsigned int (__fastcall *)(__int64, _QWORD *, __int64 *))v15)(v13, v25, &v26) )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v16 = _ReadStatusReg(SP_EL0);
        printk(&unk_875E7, *(unsigned int *)(v16 + 1800), *(unsigned int *)(v16 + 1804), &unk_8E7CE);
      }
      goto LABEL_38;
    }
  }
LABEL_37:
  if ( (unsigned int)_iface_cmdq_write(v8, v13) )
  {
LABEL_38:
    kfree(v13);
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v23 = _ReadStatusReg(SP_EL0);
      printk(&unk_8DB2C, *(unsigned int *)(v23 + 1800), *(unsigned int *)(v23 + 1804), "warn");
    }
    result = _disable_subcaches(v8);
    goto LABEL_51;
  }
  result = kfree(v13);
  v21 = *(_QWORD *)(v8 + 2208);
  v22 = *(_QWORD *)(v21 + 200);
  if ( v22 < v22 + 24LL * *(unsigned int *)(v21 + 208) )
  {
    do
    {
      if ( *(_BYTE *)(v22 + 8) == 1 )
      {
        *(_BYTE *)(v22 + 9) = 1;
        v21 = *(_QWORD *)(v8 + 2208);
      }
      v22 += 24LL;
    }
    while ( v22 < *(_QWORD *)(v21 + 200) + 24 * (unsigned __int64)*(unsigned int *)(v21 + 208) );
  }
  if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
  {
    result = printk(&unk_84362, "core", v19, v20);
    v21 = *(_QWORD *)(v8 + 2208);
  }
  *(_BYTE *)(v21 + 193) = 1;
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
