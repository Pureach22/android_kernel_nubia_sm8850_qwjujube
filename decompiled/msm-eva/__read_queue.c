__int64 __fastcall _read_queue(__int64 a1, unsigned int *a2, _DWORD *a3)
{
  _DWORD *v3; // x21
  unsigned int v7; // w4
  unsigned int v8; // w20
  _DWORD *v9; // x8
  int v10; // w23
  __int64 result; // x0
  const char *v12; // x2
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x1
  __int64 v15; // x2
  void *v16; // x0
  const char *v17; // x3
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x10
  __int64 v21; // x9
  __int64 v22; // x0
  unsigned int *v23; // x1
  __int64 v24; // x9
  unsigned int v25; // w26
  unsigned __int64 v26; // x8
  __int64 v27; // x1
  __int64 v28; // x2
  void *v29; // x0
  unsigned int v30; // w9
  int v31; // w9
  unsigned int v32; // w25
  unsigned __int64 v33; // x8
  unsigned int v34; // w25
  size_t v35; // x20
  int v36; // w9
  int v37; // w9
  char v38; // w9
  unsigned int *v39; // x8
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x8

  if ( !a1 || !a3 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    StatusReg = _ReadStatusReg(SP_EL0);
    v14 = *(unsigned int *)(StatusReg + 1800);
    v15 = *(unsigned int *)(StatusReg + 1804);
    v16 = &unk_920BB;
    v17 = (const char *)&unk_8E7CE;
LABEL_19:
    printk(v16, v14, v15, v17);
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(a1 + 24) )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
      return result;
    v18 = _ReadStatusReg(SP_EL0);
    v14 = *(unsigned int *)(v18 + 1800);
    v15 = *(unsigned int *)(v18 + 1804);
    v16 = &unk_88A12;
    v17 = "warn";
    goto LABEL_19;
  }
  __dsb(0xFu);
  v3 = *(_DWORD **)(a1 + 8);
  if ( v3 )
  {
    raw_spin_lock();
    v7 = v3[12];
    v8 = v3[13];
    v9 = a3;
    v10 = v3[2] & 1;
    if ( v7 == v8 )
    {
      v3[8] = v10;
      __dsb(0xFu);
      *a3 = 0;
      if ( v7 == v3[13] )
      {
        raw_spin_unlock(a1);
        result = 4294967235LL;
        if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
        {
          if ( v10 )
            v12 = "message";
          else
            v12 = "debug";
          printk(&unk_8CF3B, "hfi", v12, (unsigned int)v3[8]);
          return 4294967235LL;
        }
        return result;
      }
      v3[8] = 0;
    }
    v20 = *(_QWORD *)(a1 + 24);
    v21 = 4 * v7;
    v22 = a1;
    v23 = (unsigned int *)(v20 + v21);
    if ( v20 + v21 < v20 || (v24 = *(unsigned int *)(a1 + 32), (unsigned __int64)v23 > v20 + v24 - 4) )
    {
      raw_spin_unlock(a1);
      result = 4294967235LL;
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        return result;
      v33 = _ReadStatusReg(SP_EL0);
      v27 = *(unsigned int *)(v33 + 1800);
      v28 = *(unsigned int *)(v33 + 1804);
      v29 = &unk_941BD;
      goto LABEL_42;
    }
    v25 = *v23;
    if ( *v23 <= 3 )
    {
      raw_spin_unlock(a1);
      result = 4294967235LL;
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        return result;
      v26 = _ReadStatusReg(SP_EL0);
      v27 = *(unsigned int *)(v26 + 1800);
      v28 = *(unsigned int *)(v26 + 1804);
      v29 = &unk_838AF;
LABEL_42:
      printk(v29, v27, v28, &unk_8E7CE);
      return 4294967235LL;
    }
    if ( (v25 & 0xFFFFFFFC) <= 0x3000 )
    {
      v30 = (unsigned int)v24 >> 2;
      if ( v7 <= v30 )
      {
        v8 = (v25 >> 2) + v7;
        v34 = v8 - v30;
        if ( v8 >= v30 )
        {
          v35 = (v25 >> 2) - v34;
          memcpy(a2, v23, v35 * 4);
          memcpy(&a2[v35], *(const void **)(a1 + 24), 4 * v34);
          v8 = v34;
        }
        else
        {
          memcpy(a2, v23, v25 & 0xFFFFFFFC);
        }
        v32 = 0;
        *a2 = v25;
        v22 = a1;
        v9 = a3;
        goto LABEL_47;
      }
    }
    v31 = msm_cvp_debug_out;
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v40 = _ReadStatusReg(SP_EL0);
      printk(&unk_88195, *(unsigned int *)(v40 + 1800), *(unsigned int *)(v40 + 1804), "warn");
      v31 = msm_cvp_debug_out;
      v9 = a3;
      v22 = a1;
      if ( (msm_cvp_debug & 2) != 0 )
      {
LABEL_38:
        if ( !v31 )
        {
          v41 = _ReadStatusReg(SP_EL0);
          printk(&unk_838D9, *(unsigned int *)(v41 + 1800), *(unsigned int *)(v41 + 1804), "warn");
          v9 = a3;
          v22 = a1;
        }
      }
    }
    else if ( (msm_cvp_debug & 2) != 0 )
    {
      goto LABEL_38;
    }
    v32 = -61;
LABEL_47:
    v36 = v3[13];
    v3[12] = v8;
    if ( v8 == v36 )
      v37 = v10;
    else
      v37 = 0;
    v3[8] = v37;
    __dsb(0xFu);
    *v9 = v3[9] == 1;
    raw_spin_unlock(v22);
    v38 = msm_cvp_debug;
    if ( (v3[2] & 2) != 0 || (msm_cvp_debug & 8) == 0 )
    {
      v39 = a2;
      result = v32;
    }
    else
    {
      result = v32;
      v39 = a2;
      if ( !msm_cvp_debug_out )
      {
        printk(&unk_89C98, "cmd", "__read_queue", a2[1]);
        v38 = msm_cvp_debug;
        result = v32;
        v39 = a2;
      }
    }
    if ( (v38 & 0x20) != 0 && (v3[2] & 2) == 0 )
    {
      if ( !msm_cvp_debug_out )
      {
        printk(&unk_912A4, &unk_96215, "__read_queue", a1);
        v39 = a2;
      }
      _dump_packet(v39);
      return v32;
    }
    return result;
  }
  result = 4294967284LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v19 = _ReadStatusReg(SP_EL0);
    printk(&unk_82D2B, *(unsigned int *)(v19 + 1800), *(unsigned int *)(v19 + 1804), &unk_8E7CE);
    return 4294967284LL;
  }
  return result;
}
