__int64 __fastcall dp_display_convert_to_dp_mode(__int64 a1, __int64 a2, __int64 a3, void *s)
{
  int v8; // w6
  int v9; // w5
  unsigned int v10; // w23
  int dsc_count; // w0
  unsigned int v12; // w9
  unsigned int v13; // w8
  __int64 (__fastcall *v14)(__int64, __int64, void *); // x8
  __int64 result; // x0
  __int64 (__fastcall *v16)(__int64, __int64, void *); // x8
  __int64 v17; // x0
  int v18; // w19
  __int64 v19; // x0
  unsigned int v20; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  if ( a2 && a1 && a3 && s )
  {
    memset(s, 0, 0x320u);
    if ( *(_BYTE *)(a2 + 967) != 1 )
    {
LABEL_15:
      v14 = *(__int64 (__fastcall **)(__int64, __int64, void *))(a2 + 1136);
      if ( *((_DWORD *)v14 - 1) != 27531319 )
        __break(0x8228u);
      result = v14(a2, a3, s);
      if ( (_DWORD)result == -11 )
      {
        v16 = *(__int64 (__fastcall **)(__int64, __int64, void *))(a2 + 1136);
        if ( *((_DWORD *)v16 - 1) != 27531319 )
          __break(0x8228u);
        result = v16(a2, a3, s);
      }
      goto LABEL_21;
    }
    v8 = *(_DWORD *)(a1 + 52);
    v9 = *(_DWORD *)(a1 + 712);
    v10 = v8 - v9 + *(_DWORD *)(a2 + 932);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]Before: in_use:%d, max:%d, free:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        v9,
        v8,
        v10);
    dsc_count = msm_get_dsc_count(*(_QWORD *)(a1 + 344), *(unsigned __int16 *)(a3 + 4), &v20);
    if ( !dsc_count )
    {
      v12 = *(_DWORD *)(a2 + 932);
      v13 = v20;
      *(_DWORD *)(a1 + 712) -= v12;
      *(_DWORD *)(a2 + 932) = 0;
      if ( v10 >= v13 )
      {
        if ( v12 <= v13 )
          v12 = v13;
        *((_DWORD *)s + 192) |= 1u;
        *(_DWORD *)(a2 + 932) = v12;
        *(_DWORD *)(a1 + 712) += v12;
      }
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]After: in_use:%d, max:%d, free:%d, req:%d, caps:0x%x\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          *(_DWORD *)(a1 + 712),
          *(_DWORD *)(a1 + 52),
          v10,
          v13,
          *((_DWORD *)s + 192));
      goto LABEL_15;
    }
    v18 = dsc_count;
    if ( !g_dp_display || (v19 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v19 = 0;
    ipc_log_string(v19, "[e][%-4d]error getting dsc count. rc:%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v18);
    result = printk(&unk_218DA6, "dp_display_convert_to_dp_mode");
  }
  else
  {
    if ( !g_dp_display || (v17 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v17 = 0;
    ipc_log_string(v17, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    result = printk(&unk_275B6D, "dp_display_convert_to_dp_mode");
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
