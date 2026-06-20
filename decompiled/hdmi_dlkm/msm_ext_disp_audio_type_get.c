__int64 __fastcall msm_ext_disp_audio_type_get(__int64 a1, __int64 a2)
{
  __int64 v4; // x22
  _QWORD *v5; // x21
  __int64 v7; // x20
  int v8; // w8
  _DWORD *v9; // x20
  int v10; // w0
  __int64 (__fastcall *v11)(__int64, __int64); // x8
  __int64 v12; // x0
  int v13; // w0
  __int64 (__fastcall *v14)(_QWORD); // x8
  __int64 v15; // x0
  int v16; // w20
  __int64 v17; // x8
  unsigned int v18; // w20
  _DWORD v25[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 128);
  v5 = *(_QWORD **)(*(_QWORD *)(v4 + 24) + 152LL);
  if ( !v5 )
  {
    if ( (unsigned int)__ratelimit(&msm_ext_disp_audio_type_get__rs, "msm_ext_disp_audio_type_get") )
      dev_err(*(_QWORD *)(v4 + 24), "%s: codec_data is NULL\n", "msm_ext_disp_audio_type_get");
LABEL_23:
    v18 = -22;
    goto LABEL_24;
  }
  v7 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 120) + 4LL);
  mutex_lock(v5 + 8);
  if ( (_DWORD)v7 == 4 )
    v8 = 40;
  else
    v8 = 44;
  v25[0] = v8;
  if ( (unsigned int)v7 >= 5 )
  {
    __break(0x5512u);
    __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
    JUMPOUT(0x6804);
  }
  v9 = (_DWORD *)v5 + v7;
  v25[1] = v9[38];
  v25[2] = v9[33];
  v10 = msm_ext_disp_select_audio_codec(*v5, v25);
  if ( v5[2] && v5[4] && !v10 )
  {
    v11 = (__int64 (__fastcall *)(__int64, __int64))v5[3];
    v12 = *v5;
    if ( *((_DWORD *)v11 - 1) != 1323373652 )
      __break(0x8228u);
    v13 = v11(v12, 1);
    v9[28] = v13;
    if ( v13 )
    {
      v14 = (__int64 (__fastcall *)(_QWORD))v5[4];
      v15 = *v5;
      if ( *((_DWORD *)v14 - 1) != -939997060 )
        __break(0x8228u);
      v16 = v14(v15);
      mutex_unlock(v5 + 8);
      if ( v16 == 40 )
      {
        v17 = 1;
        goto LABEL_29;
      }
      if ( v16 == 44 )
      {
        v17 = 2;
LABEL_29:
        v18 = 0;
        *(_QWORD *)(a2 + 72) = v17;
        goto LABEL_24;
      }
      if ( (unsigned int)__ratelimit(&msm_ext_disp_audio_type_get__rs_36, "msm_ext_disp_audio_type_get") )
        dev_err(*(_QWORD *)(v4 + 24), "%s: Invalid disp_type:%d\n", "msm_ext_disp_audio_type_get", v16);
      goto LABEL_23;
    }
    if ( (unsigned int)__ratelimit(&msm_ext_disp_audio_type_get__rs_34, "msm_ext_disp_audio_type_get") )
      dev_err(*(_QWORD *)(v4 + 24), "%s: Display cable disconnected\n", "msm_ext_disp_audio_type_get");
    v18 = 0;
    *(_QWORD *)(a2 + 72) = 0;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&msm_ext_disp_audio_type_get__rs_30, "msm_ext_disp_audio_type_get") )
      dev_err(*(_QWORD *)(v4 + 24), "%s: get_audio_edid_blk() or get_intf_id is NULL\n", "msm_ext_disp_audio_type_get");
    v18 = -22;
  }
  mutex_unlock(v5 + 8);
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return v18;
}
