__int64 __fastcall dp_display_validate_topology(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4, _DWORD *a5)
{
  __int64 v10; // x26
  int v11; // w27
  unsigned int v12; // w20
  unsigned int mixer_count; // w0
  unsigned int dsc_count; // w0
  unsigned int v15; // w7
  unsigned int v16; // w5
  __int64 v17; // x0
  unsigned __int64 StatusReg; // x24
  unsigned int v19; // w24
  unsigned int v20; // w8
  _BOOL4 v21; // w9
  unsigned int v22; // w24
  __int64 v23; // x0
  unsigned __int64 v24; // x22
  bool v25; // zf
  char v26; // w10
  __int64 v27; // x0
  unsigned __int64 v28; // x22
  __int64 v29; // x4
  __int64 v30; // x7
  const char *v31; // x3
  unsigned int v32; // w8
  __int64 v33; // x5
  __int64 v34; // x6
  __int64 v35; // x0
  unsigned __int64 v36; // x22
  __int64 v37; // x0
  void *v38; // x0
  __int64 v39; // x0
  unsigned int v41; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v42; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v43; // [xsp+18h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 1512);
  v11 = a4[192];
  v12 = a4[11];
  v42 = 0;
  v41 = 0;
  mutex_lock(a1 + 1776);
  mixer_count = msm_get_mixer_count(v10, a3, a5, &v42);
  if ( mixer_count )
  {
    v19 = mixer_count;
    if ( !g_dp_display || (v37 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v37 = 0;
    ipc_log_string(v37, "[e][%-4d]error getting mixer count. rc:%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v19);
    v38 = &unk_23799E;
    goto LABEL_60;
  }
  if ( *(_BYTE *)(a2 + 967) != 1 || (v11 & 1) == 0 )
  {
    v16 = v42;
    v20 = 0;
    v21 = 0;
LABEL_17:
    if ( v16 == 2 )
      v21 = a5[5] != 0;
    goto LABEL_19;
  }
  dsc_count = msm_get_dsc_count(v10, *(unsigned __int16 *)(a3 + 4), &v41);
  if ( dsc_count )
  {
    v19 = dsc_count;
    if ( !g_dp_display || (v39 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v39 = 0;
    ipc_log_string(v39, "[e][%-4d]error getting dsc count. rc:%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v19);
    v38 = &unk_218DA6;
LABEL_60:
    printk(v38, "dp_display_validate_topology");
    goto LABEL_61;
  }
  v15 = a5[1];
  if ( v42 <= v41 )
    v16 = v41;
  else
    v16 = v42;
  v41 = v16;
  if ( v16 > v15 || v16 > a5[2] )
  {
    if ( !g_dp_display || (v17 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v17 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      v17,
      "[d][%-4d]mode %sx%d: not enough resources for dsc %d dsc_a:%d lm_a:%d\n",
      *(_DWORD *)(StatusReg + 1800),
      (const char *)(a3 + 80),
      v12,
      v16,
      a5[2],
      v15);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]mode %sx%d: not enough resources for dsc %d dsc_a:%d lm_a:%d\n",
        *(_DWORD *)(StatusReg + 1800),
        (const char *)(a3 + 80),
        v12,
        v41,
        a5[2],
        a5[1]);
    v19 = -11;
    a4[192] &= ~1u;
    goto LABEL_61;
  }
  v20 = v16;
  v42 = v16;
  v21 = 0;
  if ( !v16 )
    goto LABEL_17;
LABEL_19:
  v22 = *a5 + a5[1] - *(_DWORD *)(a1 + 1884) + *(_DWORD *)(a2 + 936);
  if ( v16 > v22 )
  {
    if ( !g_dp_display || (v23 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v23 = 0;
    v24 = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      v23,
      "[d][%-4d]mode %sx%d is invalid, not enough lm req:%d avail:%d\n",
      *(_DWORD *)(v24 + 1800),
      (const char *)(a3 + 80),
      v12,
      v16,
      v22);
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]mode %sx%d is invalid, not enough lm req:%d avail:%d\n",
        *(unsigned int *)(v24 + 1800),
        a3 + 80,
        v12,
        v42,
        v22);
LABEL_51:
      v19 = -1;
      goto LABEL_61;
    }
LABEL_43:
    v19 = -1;
    goto LABEL_61;
  }
  if ( v20 )
    v25 = 0;
  else
    v25 = v16 == 2;
  v26 = !v25 || v21;
  if ( (v26 & 1) == 0 )
  {
    if ( !g_dp_display || (v35 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v35 = 0;
    v36 = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      v35,
      "[d][%-4d]mode %sx%d is invalid, not enough 3dmux %d %d\n",
      *(_DWORD *)(v36 + 1800),
      (const char *)(a3 + 80),
      v12,
      0,
      a5[5]);
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_43;
    v29 = *(unsigned int *)(v36 + 1800);
    v32 = a5[5];
    v31 = "[msm-dp-debug][%-4d]mode %sx%d is invalid, not enough 3dmux %d %d\n";
    v33 = a3 + 80;
    v34 = v12;
    v30 = 0;
    goto LABEL_50;
  }
  if ( v20 != 4 && v16 == 4 )
  {
    if ( !g_dp_display || (v27 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v27 = 0;
    v28 = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      v27,
      "[d][%-4d]mode %sx%d is invalid, unsupported DP topology lm:%d dsc:%d\n",
      *(_DWORD *)(v28 + 1800),
      (const char *)(a3 + 80),
      v12,
      4,
      v20);
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_43;
    v29 = *(unsigned int *)(v28 + 1800);
    v30 = v42;
    v31 = "[msm-dp-debug][%-4d]mode %sx%d is invalid, unsupported DP topology lm:%d dsc:%d\n";
    v32 = v41;
    v33 = a3 + 80;
    v34 = v12;
LABEL_50:
    _drm_dev_dbg(0, 0, 0, v31, v29, v33, v34, v30, v32);
    goto LABEL_51;
  }
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]mode %sx%d is valid, supported DP topology lm:%d dsc:%d 3dmux:%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      (const char *)(a3 + 80),
      v12,
      v16,
      v20,
      v21);
    v16 = v42;
  }
  v19 = 0;
  a4[199] = v16;
LABEL_61:
  mutex_unlock(a1 + 1776);
  _ReadStatusReg(SP_EL0);
  return v19;
}
