__int64 __fastcall msm_ext_disp_edid_ctl_info(__int64 a1, __int64 a2)
{
  __int64 v4; // x20
  _QWORD *v5; // x21
  __int64 v6; // x20
  __int64 v8; // x0
  int v9; // w9
  char *v10; // x8
  int v11; // w0
  __int64 (__fastcall *v12)(__int64, __int64 *); // x8
  __int64 v13; // x0
  unsigned int v14; // w20
  __int64 result; // x0
  int v16; // w8
  int v17; // w9
  _DWORD v23[3]; // [xsp+Ch] [xbp-34h] BYREF
  __int64 v24; // [xsp+18h] [xbp-28h] BYREF
  __int64 v25; // [xsp+20h] [xbp-20h]
  __int64 v26; // [xsp+28h] [xbp-18h]
  __int64 v27; // [xsp+30h] [xbp-10h]
  __int64 v28; // [xsp+38h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 128);
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v5 = *(_QWORD **)(*(_QWORD *)(v4 + 24) + 152LL);
  if ( !v5 )
  {
    if ( (unsigned int)__ratelimit(&msm_ext_disp_edid_ctl_info__rs, "msm_ext_disp_edid_ctl_info") )
      dev_err(*(_QWORD *)(v4 + 24), "%s: codec_data is NULL\n", "msm_ext_disp_edid_ctl_info");
    result = 4294967274LL;
    goto LABEL_16;
  }
  v6 = *(unsigned int *)(a1 + 120);
  v8 = mutex_lock(v5 + 8);
  if ( v6 == 4 )
    v9 = 40;
  else
    v9 = 44;
  v23[0] = v9;
  if ( (unsigned __int64)(int)v6 < 5 )
  {
    v10 = (char *)v5 + 4 * (int)v6;
    v23[1] = *((_DWORD *)v10 + 38);
    v23[2] = *((_DWORD *)v10 + 33);
    v11 = msm_ext_disp_select_audio_codec(*v5, v23);
    v12 = (__int64 (__fastcall *)(__int64, __int64 *))v5[2];
    if ( !v12 || v11 )
    {
      *(_DWORD *)(a2 + 72) = 0;
      *(_DWORD *)(a2 + 64) = 4;
      mutex_unlock(v5 + 8);
      result = 0;
    }
    else
    {
      v13 = *v5;
      if ( *((_DWORD *)v12 - 1) != 1229271850 )
        __break(0x8228u);
      v14 = v12(v13, &v24);
      mutex_unlock(v5 + 8);
      result = v14;
      if ( (v14 & 0x80000000) == 0 )
      {
        v16 = v25;
        v17 = v27;
        *(_DWORD *)(a2 + 64) = 4;
        *(_DWORD *)(a2 + 72) = v17 + v16;
      }
    }
LABEL_16:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
  return msm_ext_disp_edid_get(v8);
}
