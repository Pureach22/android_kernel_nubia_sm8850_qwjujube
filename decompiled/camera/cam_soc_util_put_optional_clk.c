__int64 __fastcall cam_soc_util_put_optional_clk(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19
  __int64 v3; // x21
  __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 result; // x0
  __int64 v8; // x19

  v2 = a2;
  if ( (a2 & 0x80000000) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_put_optional_clk",
      2355,
      "Invalid params clk %d",
      a2);
    return 4294967274LL;
  }
  v3 = a1 + 4LL * (unsigned int)a2;
  v4 = a1;
  if ( (*(_DWORD *)(a1 + 3184) & (1 << a2)) != 0 )
  {
    if ( (unsigned int)a2 >= 7 )
      goto LABEL_13;
    a1 = cam_soc_util_clk_wrapper_unregister_entry(*(unsigned int *)(v3 + 3156), a1);
  }
  if ( (*(_DWORD *)(v4 + 3568) & (1 << v2)) == 0 )
  {
    if ( v2 <= 6 )
    {
      v6 = v2;
      goto LABEL_11;
    }
LABEL_13:
    __break(0x5512u);
    return cam_soc_util_clk_wrapper_unregister_entry(a1, a2);
  }
  if ( v2 > 6 )
    goto LABEL_13;
  v5 = *(unsigned int *)(v3 + 3156);
  v6 = v2;
  cam_soc_util_clk_aggregate_unregister_entry(v5, v4, v2);
LABEL_11:
  v8 = v4 + 8 * v6;
  cam_wrapper_clk_put(*(_QWORD *)(v8 + 3072), *(_QWORD *)(v8 + 3016));
  result = 0;
  *(_QWORD *)(v8 + 3072) = 0;
  return result;
}
