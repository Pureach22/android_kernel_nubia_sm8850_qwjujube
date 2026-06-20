__int64 __fastcall msm_vidc_adjust_fence_info(__int64 a1, __int64 a2)
{
  unsigned __int16 *v2; // x18
  unsigned int *v5; // x22
  __int64 v6; // x4
  unsigned int v7; // w20
  unsigned int v8; // w21
  __int64 buffer; // x0
  __int64 v10; // x4
  __int64 v11; // x20
  __int64 result; // x0
  unsigned int v13; // w8
  size_t v14; // x2
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x19
  __int64 v19; // x0
  __int64 v20; // x1
  _DWORD s[100]; // [xsp+18h] [xbp-198h] BYREF
  __int64 v22; // [xsp+1A8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
    goto LABEL_22;
  memset(s, 0, sizeof(s));
  v5 = *(unsigned int **)(a2 + 232);
  v6 = v5[2];
  if ( (unsigned int)v6 >= 0x20 )
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_7F5E1, "err ", a1 + 340, "msm_vidc_adjust_fence_info", v6);
    }
LABEL_26:
    result = 4294967274LL;
    goto LABEL_27;
  }
  v7 = *v5;
  v8 = v5[1];
  s[2] = v5[2];
  s[0] = v7;
  s[1] = v8;
  memcpy(&s[4], v5 + 4, 4 * v6);
  buffer = msm_vidc_fetch_buffer(a1, v7, v8);
  if ( !buffer )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_7F625, "err ", a1 + 340, "msm_vidc_adjust_fence_info", v10);
    goto LABEL_26;
  }
  v11 = buffer;
  if ( a1 && s[2] && (msm_vidc_debug & 2) != 0 )
  {
    v16 = buf_name(*(unsigned int *)(buffer + 24));
    printk(&unk_83E65, "high", a1 + 340, "msm_vidc_adjust_fence_info", v16);
  }
  result = ((__int64 (__fastcall *)(__int64, __int64, _DWORD *))msm_vidc_populate_fence_info)(a1, v11, s);
  if ( (_DWORD)result )
    goto LABEL_27;
  v13 = s[3];
  if ( a1 && s[3] && (msm_vidc_debug & 2) != 0 )
  {
    v17 = buf_name(*(unsigned int *)(v11 + 24));
    printk(&unk_9420C, "high", a1 + 340, "msm_vidc_adjust_fence_info", v17);
    v13 = s[3];
  }
  v14 = 4LL * v13;
  v5[3] = v13;
  if ( v13 < 0x61 )
  {
    if ( v13 >= 0x21 && (v4l2_fence_info_from_driver___already_done & 1) == 0 )
    {
      v4l2_fence_info_from_driver___already_done = 1;
      v18 = 4LL * v13;
      _warn_printk(
        "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
        v14,
        "field \"&v4l2_finfo->fd\" at ../vendor/qcom/opensource/video-driver/driver/platform/common/src/msm_vidc_platform_ext.c:32",
        0x80u);
      v14 = v18;
      __break(0x800u);
    }
    memcpy(v5 + 4, &s[4], v14);
    v15 = v5[3];
    v14 = 8 * v15;
    if ( (unsigned int)v15 < 0x21 )
    {
      memcpy(v5 + 36, &s[36], v14);
LABEL_22:
      result = 0;
LABEL_27:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v19 = _fortify_panic(16, -1, v14);
  v20 = __ldxr(v2);
  return _write_register(v19, v20);
}
