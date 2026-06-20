__int64 __fastcall tpg_hw_v_1_4_handle_irq(__int64 a1)
{
  __int64 v1; // x8
  int *v2; // x21
  __int64 v3; // x22
  unsigned int v5; // w19
  int v6; // w8
  int v7; // w23
  __int64 v8; // x0

  if ( !a1
    || (v1 = *(_QWORD *)(a1 + 32)) == 0
    || (v2 = *(int **)(v1 + 24)) == nullptr
    || (v3 = *(_QWORD *)(a1 + 40)) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_v_1_4_handle_irq",
      775,
      "Invalid Params");
    return 0;
  }
  v5 = cam_io_r_mb(*(_QWORD *)(v3 + 288) + v2[120]);
  v6 = 1 << v2[243];
  if ( (((1 << v2[242]) | v6) & v5) != 0 )
  {
    if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x200000000LL,
        4,
        "tpg_hw_v_1_4_handle_irq",
        787,
        "Got TPG Interrupt val = 0x%x",
        v5);
      v7 = (1 << v2[243]) & v5;
      if ( !v7 )
      {
LABEL_10:
        cam_io_w_mb(v5, *(_QWORD *)(v3 + 288) + v2[122]);
        cam_io_w_mb((unsigned int)(1 << v2[251]), *(_QWORD *)(v3 + 288) + v2[124]);
        if ( v7 )
          complete(a1 + 104);
        return 1;
      }
    }
    else
    {
      v7 = v6 & v5;
      if ( (v6 & v5) == 0 )
        goto LABEL_10;
    }
    v8 = raw_spin_lock_irqsave(a1 + 96);
    *(_DWORD *)(a1 + 8) = 2;
    raw_spin_unlock_irqrestore(a1 + 96, v8);
    goto LABEL_10;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x200000000LL,
    1,
    "tpg_hw_v_1_4_handle_irq",
    803,
    "Not a valid event 0x%x",
    v5);
  return 1;
}
