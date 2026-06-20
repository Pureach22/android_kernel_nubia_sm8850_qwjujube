_WORD *__fastcall reg_call_chan_change_cbks(__int64 a1, __int64 a2, char a3, __int64 a4)
{
  __int64 psoc_obj; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x21
  _WORD *result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x22
  const char *v28; // x2
  __int64 v29; // x8
  __int64 *v30; // x26
  __int64 v31; // x27
  unsigned __int64 StatusReg; // x28
  __int64 v33; // x8
  void (__fastcall *v34)(__int64, __int64, __int64, __int64, __int64); // x23
  __int64 v35; // x4
  __int64 v36; // [xsp+8h] [xbp-8h]

  psoc_obj = reg_get_psoc_obj(a1);
  if ( !psoc_obj )
  {
    v28 = "%s: psoc reg component is NULL";
    return (_WORD *)qdf_trace_msg(0x51u, 1u, v28, v9, v10, v11, v12, v13, v14, v15, v16, "reg_call_chan_change_cbks");
  }
  v17 = psoc_obj;
  if ( !reg_get_pdev_obj(a2) )
  {
    v28 = "%s: pdev reg component is NULL";
    return (_WORD *)qdf_trace_msg(0x51u, 1u, v28, v9, v10, v11, v12, v13, v14, v15, v16, "reg_call_chan_change_cbks");
  }
  result = (_WORD *)_qdf_mem_malloc(0xE58u, "reg_call_chan_change_cbks", 70);
  if ( result )
  {
    v27 = (__int64)result;
    if ( (unsigned int)reg_get_pwrmode_chan_list(a2, result, 0, v19, v20, v21, v22, v23, v24, v25, v26) )
      return (_WORD *)_qdf_mem_free(v27);
    if ( (a3 & 1) != 0 )
      v29 = a4;
    else
      v29 = 0;
    v30 = (__int64 *)(v17 + 91176);
    v31 = 30;
    v36 = v29;
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v17 + 93240);
        v33 = *(_QWORD *)(v17 + 93248);
        v34 = (void (__fastcall *)(__int64, __int64, __int64, __int64, __int64))*(v30 - 1);
        if ( (v33 & 1) == 0 )
          goto LABEL_19;
      }
      else
      {
        raw_spin_lock_bh(v17 + 93240);
        v33 = *(_QWORD *)(v17 + 93248) | 1LL;
        *(_QWORD *)(v17 + 93248) = v33;
        v34 = (void (__fastcall *)(__int64, __int64, __int64, __int64, __int64))*(v30 - 1);
        if ( (v33 & 1) == 0 )
        {
LABEL_19:
          raw_spin_unlock(v17 + 93240);
          if ( v34 )
            goto LABEL_20;
          goto LABEL_14;
        }
      }
      *(_QWORD *)(v17 + 93248) = v33 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v17 + 93240);
      if ( v34 )
      {
LABEL_20:
        v35 = *v30;
        if ( *((_DWORD *)v34 - 1) != 614064543 )
          __break(0x8237u);
        v34(a1, a2, v27, v36, v35);
      }
LABEL_14:
      --v31;
      v30 += 2;
      if ( !v31 )
        return (_WORD *)_qdf_mem_free(v27);
    }
  }
  return result;
}
