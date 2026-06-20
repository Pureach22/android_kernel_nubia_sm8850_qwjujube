unsigned __int64 __fastcall cam_common_util_mul_then_div(unsigned __int64 a1, unsigned __int64 a2, __int64 a3)
{
  unsigned __int64 v3; // x19
  const char *v4; // x5
  __int64 v5; // x4

  v3 = a1;
  if ( !a3 )
  {
    v4 = "Invalid div_factor %llu, node_bw: %llu, mul_factor: %llu";
    v5 = 177;
    goto LABEL_7;
  }
  if ( a1 && !is_mul_ok(a1, a2) )
  {
    v4 = "Multiplication Overflow: div_factor: %llu node_bw: %llu mul_factor: %llu";
    v5 = 184;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, unsigned __int64, unsigned __int64))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_common_util_mul_then_div",
      v5,
      v4,
      a3,
      a1,
      a2);
    return v3;
  }
  return a2 * a1 / (unsigned int)a3;
}
