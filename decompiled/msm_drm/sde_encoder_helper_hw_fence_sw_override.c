__int64 __fastcall sde_encoder_helper_hw_fence_sw_override(__int64 **a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 result; // x0
  void *v7; // x0
  __int64 v8; // x24
  int v9; // w21
  int v10; // w22
  int v11; // w23
  __int64 (__fastcall *v12)(_QWORD); // x8
  int v13; // w6
  __int64 (__fastcall *v14)(_QWORD); // x8
  char v15; // [xsp+0h] [xbp+0h]

  if ( !*a1 )
  {
    result = 0;
    if ( !a2 )
      return result;
    goto LABEL_12;
  }
  v4 = **a1;
  if ( !v4 )
  {
    v7 = &unk_26FCAB;
LABEL_11:
    printk(v7, "sde_encoder_get_kms");
    result = 0;
    if ( !a2 )
      return result;
    goto LABEL_12;
  }
  v5 = *(_QWORD *)(v4 + 56);
  if ( !v5 || !*(_QWORD *)(v5 + 8) )
  {
    v7 = &unk_234896;
    goto LABEL_11;
  }
  result = sde_kms_get_disp_op();
  if ( !a2 )
    return result;
LABEL_12:
  if ( (unsigned int)result >= 3 )
  {
    __break(0x5512u);
    return sde_encoder_is_primary_display();
  }
  else
  {
    v8 = (unsigned int)result;
    if ( *(_QWORD *)(a2 + 352 + 8LL * (unsigned int)result) )
    {
      v9 = sde_dbg_base_evtlog;
      if ( *a1 )
        v10 = *((_DWORD *)*a1 + 6);
      else
        v10 = -1;
      v11 = *(_DWORD *)(a2 + 64);
      v12 = *(__int64 (__fastcall **)(_QWORD))(a2 + 8LL * (unsigned int)result + 448);
      if ( v12 )
      {
        if ( *((_DWORD *)v12 - 1) != 1800103338 )
          __break(0x8228u);
        v13 = v12(a2);
      }
      else
      {
        v13 = 60333;
      }
      sde_evtlog_log(v9, "sde_encoder_helper_hw_fence_sw_override", 7370, -1, v10, v11, v13, -1059143953, v15);
      ((void (__fastcall *)(__int64 **, _QWORD))sde_encoder_helper_reset_mixers)(a1, 0);
      v14 = *(__int64 (__fastcall **)(_QWORD))(a2 + 352 + 8 * v8);
      if ( *((_DWORD *)v14 - 1) != 729814110 )
        __break(0x8228u);
      return v14(a2);
    }
  }
  return result;
}
