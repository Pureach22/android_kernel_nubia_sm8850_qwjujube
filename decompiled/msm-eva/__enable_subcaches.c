__int64 __fastcall _enable_subcaches(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v5; // x19
  unsigned __int64 v6; // x24
  unsigned int v7; // w20
  char v8; // w8
  __int64 v9; // x8
  unsigned __int64 v10; // x11
  unsigned __int64 v11; // x23
  unsigned int v12; // w20
  const char *v13; // x25
  _DWORD *v14; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // [xsp+8h] [xbp-F8h]
  _QWORD v19[2]; // [xsp+10h] [xbp-F0h] BYREF
  _QWORD v20[28]; // [xsp+20h] [xbp-E0h] BYREF

  v20[26] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (msm_cvp_syscache_disable & 1) != 0 )
    goto LABEL_50;
  v4 = *(_QWORD *)(result + 2208);
  v5 = result;
  if ( *(_BYTE *)(v4 + 192) != 1 )
    goto LABEL_50;
  v6 = *(_QWORD *)(v4 + 200);
  v7 = 0;
  if ( v6 >= v6 + 24LL * *(unsigned int *)(v4 + 208) )
  {
LABEL_10:
    if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
      result = printk(&unk_875B8, "core", v7, a4);
    goto LABEL_50;
  }
  while ( 1 )
  {
    result = llcc_slice_activate(*(_QWORD *)(v6 + 16));
    if ( (_DWORD)result )
      break;
    v8 = BYTE1(msm_cvp_debug);
    *(_BYTE *)(v6 + 8) = 1;
    if ( (v8 & 1) != 0 && !msm_cvp_debug_out )
      result = printk(&unk_88AD7, "core", *(_QWORD *)v6, a4);
    v6 += 24LL;
    ++v7;
    if ( v6 >= *(_QWORD *)(*(_QWORD *)(v5 + 2208) + 200LL)
             + 24 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(v5 + 2208) + 208LL) )
      goto LABEL_10;
  }
  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_92EEC, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
  }
  if ( *(_BYTE *)(*(_QWORD *)(v5 + 2208) + 376LL) )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v16 = _ReadStatusReg(SP_EL0);
      printk(&unk_8E7D2, *(unsigned int *)(v16 + 1800), *(unsigned int *)(v16 + 1804), &unk_8E7CE);
    }
    __break(0x800u);
  }
  v19[0] = 0;
  if ( (msm_cvp_syscache_disable & 1) != 0 )
    goto LABEL_49;
  v9 = *(_QWORD *)(v5 + 2208);
  if ( *(_BYTE *)(v9 + 192) != 1 )
    goto LABEL_49;
  v10 = *(_QWORD *)(v9 + 200);
  v11 = v10 + 24LL * (unsigned int)(*(_DWORD *)(v9 + 208) - 1);
  memset(v20, 0, 208);
  if ( v11 < v10 )
    goto LABEL_48;
  v12 = 0;
  v18 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( *(_BYTE *)(v11 + 9) != 1 )
      goto LABEL_27;
    v13 = *(const char **)v11;
    if ( !strcmp("cvp", *(const char **)v11) )
      break;
    if ( strcmp("cvpfw", v13) )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        printk(&unk_90023, *(unsigned int *)(v18 + 1800), *(unsigned int *)(v18 + 1804), &unk_8E7CE);
      goto LABEL_26;
    }
    if ( ((8LL * v12) | 4uLL) > 0xD0 )
      goto LABEL_39;
    v14 = (_DWORD *)&v20[v12] + 1;
    *v14 = 0;
    if ( v12 > 0x18 )
      goto LABEL_39;
LABEL_25:
    ++v12;
    v14[1] = **(_DWORD **)(v11 + 16);
LABEL_26:
    *(_BYTE *)(v11 + 9) = 0;
    v9 = *(_QWORD *)(v5 + 2208);
LABEL_27:
    v11 -= 24LL;
    if ( v11 < *(_QWORD *)(v9 + 200) )
      goto LABEL_40;
  }
  if ( ((8LL * v12) | 4uLL) <= 0xD0 )
  {
    v14 = (_DWORD *)&v20[v12] + 1;
    *v14 = 1;
    if ( v12 <= 0x18 )
      goto LABEL_25;
  }
LABEL_39:
  __break(1u);
LABEL_40:
  if ( v12 )
  {
    if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
      printk(&unk_84E06, "core", v12, a4);
    v19[1] = v20;
    LODWORD(v19[0]) = 1;
    if ( (unsigned int)_core_release_resource(v5, v19) && (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v17 = _ReadStatusReg(SP_EL0);
      printk(&unk_90050, *(unsigned int *)(v17 + 1800), *(unsigned int *)(v17 + 1804), "warn");
    }
  }
LABEL_48:
  *(_BYTE *)(*(_QWORD *)(v5 + 2208) + 193LL) = 0;
LABEL_49:
  result = _disable_subcaches(v5);
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
