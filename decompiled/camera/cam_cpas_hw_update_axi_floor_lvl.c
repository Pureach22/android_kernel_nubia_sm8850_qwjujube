__int64 __usercall cam_cpas_hw_update_axi_floor_lvl@<X0>(
        __int64 a1@<X0>,
        unsigned int a2@<W1>,
        unsigned int a3@<W2>,
        char a4@<W3>,
        __int64 a5@<X8>)
{
  __int64 v5; // x19
  char v6; // w20
  __int64 v7; // x21
  unsigned int v8; // w22
  unsigned int v9; // w24
  __int64 v10; // x25
  _DWORD *v11; // x26
  _QWORD *v12; // x27
  __int64 v13; // x23
  unsigned int v14; // w23

  if ( a2 >= 0x2B )
    goto LABEL_11;
  v7 = *(_QWORD *)(a1 + 3680);
  v9 = a2;
  v6 = a4;
  v8 = a3;
  v5 = a1;
  v10 = v7 + 320;
  v13 = *(_QWORD *)(v7 + 320 + 8LL * a2);
  if ( (a4 & 1) == 0 )
  {
    mutex_lock(a1);
    mutex_lock(v7 + 48LL * v9 + 664);
  }
  if ( *(_DWORD *)(v13 + 176) == v8 )
  {
    v14 = 0;
    goto LABEL_21;
  }
  v12 = &unk_393000;
  v11 = &unk_393000;
  if ( (debug_mdl & 4) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpas_hw_update_axi_floor_lvl",
      2569,
      "CPAS client: %s curr lvl: %d required lvl: %d",
      v13);
  *(_DWORD *)(v13 + 176) = v8;
  a5 = *(unsigned int *)(v7 + 2776);
  if ( (_DWORD)a5 )
  {
    if ( (unsigned int)(a5 - 44) >= 0xFFFFFFD5 )
      goto LABEL_13;
LABEL_11:
    __break(0x5512u);
    while ( 1 )
    {
      --a5;
      v10 += 8;
      if ( !a5 )
        break;
LABEL_13:
      if ( *(_QWORD *)v10 && v8 <= *(_DWORD *)(*(_QWORD *)v10 + 176LL) )
        v8 = *(_DWORD *)(*(_QWORD *)v10 + 176LL);
    }
  }
  if ( (v12[458] & 4) != 0 && !v11[919] )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v12[458] & 4LL,
      4,
      "cam_cpas_hw_update_axi_floor_lvl",
      2580,
      "Required highest_level[%d]",
      v8);
  *(_DWORD *)(v7 + 159436) = v8;
  v14 = cam_cpas_util_set_max_camnoc_axi_clk_rate(v7, v5 + 96);
  if ( v14 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_update_axi_floor_lvl",
      2587,
      "Failed in scaling clock rate level %d for AXI",
      v8);
LABEL_21:
  if ( (v6 & 1) == 0 )
  {
    mutex_unlock(v7 + 48LL * v9 + 664);
    mutex_unlock(v5);
  }
  return v14;
}
