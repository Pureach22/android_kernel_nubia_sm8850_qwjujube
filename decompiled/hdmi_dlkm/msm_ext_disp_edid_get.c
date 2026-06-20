__int64 __fastcall msm_ext_disp_edid_get(__int64 a1, __int64 a2)
{
  __int64 v4; // x20
  __int64 v5; // x8
  _QWORD *v6; // x21
  __int64 v7; // x19
  void *v9; // x0
  int v10; // w9
  char *v11; // x8
  int v12; // w0
  __int64 (__fastcall *v13)(__int64, void **); // x8
  __int64 v14; // x0
  unsigned int v15; // w19
  __int64 result; // x0
  size_t v17; // x2
  size_t v18; // x21
  __int64 v24; // [xsp+8h] [xbp-38h] BYREF
  int v25; // [xsp+10h] [xbp-30h]
  void *src; // [xsp+18h] [xbp-28h] BYREF
  size_t n; // [xsp+20h] [xbp-20h]
  void *v28; // [xsp+28h] [xbp-18h]
  size_t v29; // [xsp+30h] [xbp-10h]
  __int64 v30; // [xsp+38h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 128);
  v28 = nullptr;
  v29 = 0;
  src = nullptr;
  n = 0;
  v5 = *(_QWORD *)(v4 + 24);
  v25 = 0;
  v24 = 0;
  v6 = *(_QWORD **)(v5 + 152);
  if ( !v6 )
  {
    if ( (unsigned int)__ratelimit(&msm_ext_disp_edid_get__rs, "msm_ext_disp_edid_get") )
      dev_err(*(_QWORD *)(v4 + 24), "%s: codec_data is NULL\n", "msm_ext_disp_edid_get");
    result = 4294967274LL;
    goto LABEL_26;
  }
  v7 = *(unsigned int *)(a1 + 120);
  v9 = (void *)mutex_lock(v6 + 8);
  if ( v7 == 4 )
    v10 = 40;
  else
    v10 = 44;
  LODWORD(v24) = v10;
  if ( (unsigned __int64)(int)v7 < 5 )
  {
    v11 = (char *)v6 + 4 * (int)v7;
    HIDWORD(v24) = *((_DWORD *)v11 + 38);
    v25 = *((_DWORD *)v11 + 33);
    v12 = msm_ext_disp_select_audio_codec(*v6, &v24);
    v13 = (__int64 (__fastcall *)(__int64, void **))v6[2];
    if ( !v13 || v12 )
    {
      if ( (unsigned int)__ratelimit(&msm_ext_disp_edid_get__rs_22, "msm_ext_disp_edid_get") )
        dev_err(*(_QWORD *)(v4 + 24), "%s: codec_data or get_audio_edid_blk() is NULL\n", "msm_ext_disp_edid_get");
      mutex_unlock(v6 + 8);
      result = 4294967274LL;
      goto LABEL_26;
    }
    v14 = *v6;
    if ( *((_DWORD *)v13 - 1) != 1229271850 )
      __break(0x8228u);
    v15 = v13(v14, &src);
    mutex_unlock(v6 + 8);
    result = v15;
    if ( (v15 & 0x80000000) != 0 )
    {
LABEL_26:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    v17 = (unsigned int)n;
    if ( (unsigned int)(v29 + n) >= 0x201 )
    {
      if ( (unsigned int)__ratelimit(&msm_ext_disp_edid_get__rs_24, "msm_ext_disp_edid_get") )
        dev_err(*(_QWORD *)(v4 + 24), "%s: Not enough memory to copy EDID data\n", "msm_ext_disp_edid_get");
      result = 4294967284LL;
      goto LABEL_26;
    }
    if ( (unsigned int)n >= 0x201 && (msm_ext_disp_edid_get___already_done & 1) == 0 )
    {
      msm_ext_disp_edid_get___already_done = 1;
      v18 = (unsigned int)n;
      _warn_printk(
        "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
        (unsigned int)n,
        "field \"ucontrol->value.bytes.data\" at ../vendor/qcom/opensource/audio-kernel/asoc/codecs/msm_hdmi_codec_rx.c:212",
        0x200u);
      v17 = v18;
      __break(0x800u);
    }
    v9 = memcpy((void *)(a2 + 72), src, v17);
    if ( (unsigned int)n <= 0x200 )
    {
      memcpy((void *)(a2 + 72 + (unsigned int)n), v28, (unsigned int)v29);
      result = v15;
      goto LABEL_26;
    }
  }
  __break(0x5512u);
  __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
  return msm_ext_disp_audio_type_get(v9);
}
