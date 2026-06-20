__int64 __fastcall cam_soc_util_get_clk_level(_BYTE *a1, __int64 a2, unsigned int a3, int *a4)
{
  __int64 v8; // x0
  __int64 v9; // x7
  _BYTE *v10; // x9
  __int64 v11; // x6
  const char *v12; // x5
  __int64 v13; // x2
  __int64 v14; // x4
  __int64 result; // x0
  int v16; // w20

  if ( !a1 || a3 >= 0x20 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_clk_level",
      1631,
      "Invalid src_clk_idx: %d",
      a3);
LABEL_29:
    result = 4294967274LL;
    v16 = -1;
    goto LABEL_30;
  }
  v8 = cam_wrapper_clk_round_rate(*(_QWORD *)&a1[8 * a3 + 1128], a2, *(_QWORD *)&a1[8 * a3 + 872]);
  v9 = v8;
  if ( v8 < 0 )
  {
    v12 = "round failed rc = %ld";
    v13 = 1;
    v14 = 1640;
    goto LABEL_28;
  }
  if ( (debug_bypass_drivers & 4) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_soc_util_get_clk_level",
      1646,
      "Bypass get clk level");
    result = 0;
    v16 = 7;
    goto LABEL_30;
  }
  v10 = a1 + 1384;
  if ( (a1[2860] & 1) != 0 && (v11 = *(int *)&v10[4 * a3], v8 <= v11) )
  {
    v16 = 0;
  }
  else if ( a1[2861] == 1 && (v11 = *(int *)&v10[4 * a3 + 128], v8 <= v11) )
  {
    v16 = 1;
  }
  else if ( a1[2862] == 1 && (v11 = *(int *)&v10[4 * a3 + 256], v8 <= v11) )
  {
    v16 = 2;
  }
  else if ( a1[2863] == 1 && (v11 = *(int *)&v10[4 * a3 + 384], v8 <= v11) )
  {
    v16 = 3;
  }
  else if ( a1[2864] == 1 && (v11 = *(int *)&v10[4 * a3 + 512], v8 <= v11) )
  {
    v16 = 4;
  }
  else if ( a1[2865] == 1 && (v11 = *(int *)&v10[4 * a3 + 640], v8 <= v11) )
  {
    v16 = 5;
  }
  else if ( a1[2866] == 1 && (v11 = *(int *)&v10[4 * a3 + 768], v8 <= v11) )
  {
    v16 = 6;
  }
  else if ( a1[2867] == 1 && (v11 = *(int *)&v10[4 * a3 + 896], v8 <= v11) )
  {
    v16 = 7;
  }
  else if ( a1[2868] == 1 && (v11 = *(int *)&v10[4 * a3 + 1024], v8 <= v11) )
  {
    v16 = 8;
  }
  else
  {
    if ( a1[2869] != 1 || (v11 = *(int *)&v10[4 * a3 + 1152], v8 > v11) )
    {
      v12 = "Invalid clock rate %ld";
      v13 = 2;
      v14 = 1664;
LABEL_28:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        0x20000,
        v13,
        "cam_soc_util_get_clk_level",
        v14,
        v12,
        v8);
      goto LABEL_29;
    }
    v16 = 9;
  }
  result = 0;
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20000,
      4,
      "cam_soc_util_get_clk_level",
      1658,
      "soc = %d round rate = %ld actual = %lld",
      v11,
      v9,
      a2);
    result = 0;
  }
LABEL_30:
  *a4 = v16;
  return result;
}
