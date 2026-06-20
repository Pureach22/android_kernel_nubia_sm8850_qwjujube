__int64 __fastcall sde_encoder_helper_collect_misr(__int64 **a1, __int64 a2, __int64 a3)
{
  char v4; // w19
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x21
  __int64 v8; // x0
  __int64 disp_op; // x0
  __int64 *v10; // x8
  __int64 v12; // x21
  _DWORD *v13; // x9

  if ( !a1 )
    return 4294967274LL;
  v4 = a2;
  if ( *a1 )
  {
    v5 = **a1;
    if ( v5 )
    {
      v6 = *(_QWORD *)(v5 + 56);
      v7 = a3;
      if ( v6 && (v8 = *(_QWORD *)(v6 + 8)) != 0 )
      {
        disp_op = sde_kms_get_disp_op(v8, a2);
      }
      else
      {
        printk(&unk_234896, "sde_encoder_get_kms");
        disp_op = 0;
      }
      a3 = v7;
      v10 = a1[53];
      if ( !v10 )
        return 4294966772LL;
      goto LABEL_13;
    }
    v12 = a3;
    printk(&unk_26FCAB, "sde_encoder_get_kms");
    a3 = v12;
  }
  disp_op = 0;
  v10 = a1[53];
  if ( !v10 )
    return 4294966772LL;
LABEL_13:
  if ( (unsigned int)disp_op >= 3 )
  {
    __break(0x5512u);
    return sde_encoder_helper_inc_pending(disp_op);
  }
  v13 = (_DWORD *)v10[(unsigned int)disp_op + 31];
  if ( !v13 )
    return 4294966772LL;
  if ( *(v13 - 1) != -1383520583 )
    __break(0x8229u);
  return ((__int64 (__fastcall *)(__int64 *, _QWORD, __int64))v13)(v10, v4 & 1, a3);
}
